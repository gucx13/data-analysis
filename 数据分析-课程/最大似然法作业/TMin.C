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
double height[4]={0,6,12,18};
double number[4]={1880,940,530,305};

void getData(vector<double>* xVecPtr){
	double mean = 0,sigma = 1;
	TRandom r;
		for (int i=0; i < 100 ; i++){
			double x = gRandom->Gaus(mean,sigma);
			xVecPtr->push_back(x);

		}	
}

double gausPdf(double* xPtr, double* yPtr, double par[]){
	double x = *xPtr;
	double y = *yPtr;
	double mean = par[0];  // mean of x
	double sigma = par[1];
	double f = (0.3989/sigma) * exp(-(x-mean)*(x-mean)*(y-mean)/(2*sigma*sigma));
    return f;
}



void fcn(int& npar , double* deriv, double& f ,double par[] ,int flag){
	vector<double> xVec(height, height+4);
	vector<double> yVec(number, number+4);
	int n = xVec.size();

	double lnL = 0.0;
	for(int i = 0 ; i < n ; i++ ){
		double x = xVec[i];
		double y = yVec[i];
		double pdf = gausPdf(&x,&y,par);
			if (pdf>0)
				lnL += log(pdf);
	}
	f= -2.0*lnL;	
}




void TMin(){

	gStyle->SetOptStat(kFALSE);

	const int npar = 2;
	TMinuit minuit(npar);
	minuit.SetFCN(fcn);

	double par[npar];               // the start values
	double stepSize[npar];          // step sizes 
	double minVal[npar];            // minimum bound on parameter 
	double maxVal[npar];            // maximum bound on parameter
	string parName[npar];

	par[0] = 2.0;            // a guess
	stepSize[0] = 0.002;       // take e.g. 0.1 of start value
	minVal[0] = -10;    // if min and max values = 0, parameter is unbounded.
	maxVal[0] = 10;
	parName[0] = "mean";

	par[1] = 1.23;            // a guess
	stepSize[1] = 0.002;       // take e.g. 0.1 of start value
	minVal[1] = 0;    // if min and max values = 0, parameter is unbounded.
	maxVal[1] = 10;
	parName[1] = "sigma";

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

}
