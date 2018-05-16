#include <iostream>                                                                                                                                                                                         
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>

#include <TROOT.h>
#include <TMinuit.h>
#include <TApplication.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TF1.h>
#include <TAxis.h>
#include <TLine.h>

using namespace std;

//get data
double height[4]={0,6,12,18};
double number[4]={1880,940,530,305};

//define pdf
double poissonPdf(double* xPtr, double* yPtr, double par[]){
    double   h = *xPtr;
    double   n = *yPtr;
    double  nu = par[0];  // 
    double   k = par[1];  //Boltzmann constant
    double nui = nu * exp(-0.1241 * h / k);
    cout << "nui = "<<nui<<endl;
    double   f = n*log(nui/n)-nui+n;

    return f;
}

//define likelihood function
void fcn(int& npar , double* deriv, double& f ,double par[] ,int flag){
    vector<double> H(height, height+4);
    vector<double> N(number, number+4); 
    int n = 4;

    double lnL = 0.0;
    for(int i = 0 ; i < n ; i++ ){
        double x = H[i];
        double y = N[i];
        //cout << "x: " << x << " y: " << y << " par: " << par << endl;
        
        double pdf = poissonPdf(&x,&y,par);
            

                lnL += pdf;

    f= -2.0*lnL;
	}
}

void prob11_chi2(){
    
    const int npar = 2;
    TMinuit minuit(npar);
    minuit.SetFCN(fcn);

    double par[npar];    
    double stepSize[npar];
    double minVal[npar];  
    double maxVal[npar];  
    string parName[npar];

    par[0] = 2000.0;   
    stepSize[0] = 1;
    minVal[0] = 0;    
    maxVal[0] = 4000;
    parName[0] = "nu_0";

    par[1] = 1.;     
    stepSize[1] = 0.1;
    minVal[1] = 0;  
    maxVal[1] = 10;
    parName[1] = "Boltzmann constant";

    for (int i=0; i<npar; i++){
        minuit.DefineParameter(i, parName[i].c_str(),
        par[i], stepSize[i], minVal[i], maxVal[i]);
  }

    minuit.Migrad();       // Minuit's best minimization algorithm
    double outpar[npar], err[npar];
    for (int i=0; i<npar; i++){
        minuit.GetParameter(i,outpar[i],err[i]);
  }

    Double_t amin, edm , errdef;
    Int_t nvpar,nparx,icstat;
    minuit.mnstat(amin,edm,errdef,nvpar,nparx,icstat);
    
    cout<<parName[0]<<"="<<outpar[0]<<"+"<<err[0]<<endl;
    cout<<parName[1]<<"="<<outpar[1]<<"+"<<err[1]<<endl;
	cout<<"chi-square = "<<amin<<endl;
}                     
