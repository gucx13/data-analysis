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

double h[5]={300,600,800,828,1000},d[5]={800,1172,1328,1340,1500};
vector<double> hVecPtr(h,h+5);
vector<double> dVecPtr(d,d+5);

double Chi_square(double* hPtr,double* dPtr, double par[]){
    double h = *hPtr;
	double d = *dPtr;
    double alpha = par[0];  // parameter alpha

   	double sigma = 15.0;
    double f = (d-alpha*pow(h,0.5))*(d-alpha*pow(h,0.5))/(sigma*sigma);
    return f;
}
void fcn(int& npar , double* deriv, double& f ,double par[] ,int flag){
    vector<double> hVec = hVecPtr;
    vector<double> dVec = dVecPtr;
   	int n = dVec.size();

    double chi_square = 0.0;
    for(int i = 0 ; i < n ; i++ ){
        double h = hVec[i];
		double d = dVec[i];
        double pdf = Chi_square(&h,&d,par);
            if (pdf>0)
                chi_square += pdf;
    }
    f= chi_square;    
}

void pro7_1a(){
    const int npar = 1;
    TMinuit minuit(npar);
    minuit.SetFCN(fcn);

    double par[npar];               // the start values
    double stepSize[npar];          // step sizes
    double minVal[npar];            // minimum bound on parameter
    double maxVal[npar];            // maximum bound on parameter
    string parName[npar];

    par[0] = 2.0;            // a guess
    stepSize[0] = 0.002;       // take e.g. 0.1 of start value
    minVal[0] = -5;    // if min and max values = 0, parameter is unbounded.
    maxVal[0] = 100;
    parName[0] = "alpha";
	
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
	
cout<<"alpha ="<<outpar[0]<<endl<<"chi = "<<amin<<endl;

















	
}

