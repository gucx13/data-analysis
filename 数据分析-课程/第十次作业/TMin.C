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
vector<double> xVecPtr;
void getData(vector<double>* xVecPtr){
	double mean = 0,sigma = 1;
	TRandom r;
		for (int i=0; i < 100 ; i++){
			double x = gRandom->Gaus(mean,sigma);
			xVecPtr->push_back(x);

		}	
}

double gausPdf(double* xPtr, double par[]){
	double x = *xPtr;
	double mean = par[0];  // mean of x
	double sigma = par[1];
	double f = (0.3989/sigma) * exp(-(x-mean)*(x-mean)/(2*sigma*sigma));
    return f;
}

double gausPdf1(double* xPtr, double par[]){
    double x = *xPtr;
    double mean = 0.05;  // mean of x
    double sigma = par[0];
    double f = (0.3989/sigma) * exp(-(x-mean)*(x-mean)/(2*sigma*sigma));
    return f;
}
double gausPdf2(double* xPtr, double par[]){
    double x = *xPtr;
    double mean = 0.2;  // mean of x
    double sigma = par[0];
    double f = (0.3989/sigma) * exp(-(x-mean)*(x-mean)/(2*sigma*sigma));
    return f;
}

double gausPdf3(double* xPtr, double par[]){
    double x = *xPtr;
    double mean = 0.5;  // mean of x
    double sigma = par[0];
    double f = (0.3989/sigma) * exp(-(x-mean)*(x-mean)/(2*sigma*sigma));
    return f;
}


void fcn(int& npar , double* deriv, double& f ,double par[] ,int flag){
	vector<double> xVec = xVecPtr;
	int n = xVec.size();

	double lnL = 0.0;
	for(int i = 0 ; i < n ; i++ ){
		double x = xVec[i];
		double pdf = gausPdf(&x,par);
			if (pdf>0)
				lnL += log(pdf);
	}
	f= -2.0*lnL;	
}


void fcn1(int& npar , double* deriv, double& f ,double par[] ,int flag){
    vector<double> xVec = xVecPtr;
    int n = xVec.size();

    double lnL = 0.0;
    for(int i = 0 ; i < n ; i++ ){
        double x = xVec[i];
        double pdf = gausPdf1(&x,par);
            if (pdf>0)
                lnL += log(pdf);
    }
    f= -2.0*lnL;
}


void fcn2(int& npar , double* deriv, double& f ,double par[] ,int flag){
    vector<double> xVec = xVecPtr;
    int n = xVec.size();

    double lnL = 0.0;
    for(int i = 0 ; i < n ; i++ ){
        double x = xVec[i];
        double pdf = gausPdf2(&x,par);
            if (pdf>0)
                lnL += log(pdf);
    }
    f= -2.0*lnL;
}


void fcn3(int& npar , double* deriv, double& f ,double par[] ,int flag){
    vector<double> xVec = xVecPtr;
    int n = xVec.size();

    double lnL = 0.0;
    for(int i = 0 ; i < n ; i++ ){
        double x = xVec[i];
        double pdf = gausPdf3(&x,par);
            if (pdf>0)
                lnL += log(pdf);
    }
    f= -2.0*lnL;
}



void TMin(){
	TH1F* mean = new TH1F("mean","mean",30,-0.3,0.3);
	TH1F* variant = new TH1F("variant","variant",30,0.5,1.6);
	TH1F* likelihood = new TH1F("likelihood","likelihood",30,200,370);
	
	TH1F* variant1 = new TH1F("variant1","variant1",30,0.5,1.6);
	TH1F* likelihood1 = new TH1F("likelihood1","likelihood1",30,200,370);

	TH1F* variant2 = new TH1F("variant2","variant2",30,0.5,1.6);
	TH1F* likelihood2 = new TH1F("likelihood2","likelihood2",30,200,370);

	TH1F* variant3 = new TH1F("variant3","variant3",30,0.5,1.6);
	TH1F* likelihood3 = new TH1F("likelihood3","likelihood3",30,200,370);
	for (int j = 0; j < 1000; j++){	
	gStyle->SetOptStat(kFALSE);
	getData(&xVecPtr);
	
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

	likelihood->Fill(amin);
	mean->Fill(outpar[0]); 
	variant->Fill(outpar[1]);

	const int npar1 = 1;
    TMinuit minuit1(npar1);
    minuit1.SetFCN(fcn1);
	
	double par1[npar1];               // the start values
    double stepSize1[npar1];          // step sizes
    double minVal1[npar1];            // minimum bound on parameter
    double maxVal1[npar1];            // maximum bound on parameter
    string parName1[npar1];
	
	par1[0] = 1.0;            // a guess
    stepSize1[0] = 0.002;       // take e.g. 0.1 of start value
    minVal1[0] = -10;    // if min and max values = 0, parameter is unbounded.
    maxVal1[0] = 10;
    parName1[0] = "sigma";

	for (int i=0; i<npar1; i++){
        minuit1.DefineParameter(i, parName1[i].c_str(),
        par1[i], stepSize1[i], minVal1[i], maxVal1[i]);
  }

	minuit1.Migrad();       // Minuit's best minimization algorithm
    double outpar1[npar1], err1[npar1];
    for (int i=0; i<npar1; i++){
        minuit1.GetParameter(i,outpar1[i],err1[i]);
  }

	Double_t amin1 , edm1 , errdef1;
    Int_t nvpar1,nparx1,icstat1;
    minuit1.mnstat(amin1,edm1,errdef1,nvpar1,nparx1,icstat1);

	likelihood1->Fill(amin1);
    variant1->Fill(outpar1[0]);
	
	minuit1.SetFCN(fcn2);	
	
	minuit1.Migrad();       // Minuit's best minimization algorithm
	for (int i=0; i<npar1; i++){
        minuit1.GetParameter(i,outpar1[i],err1[i]);
  }

	minuit1.mnstat(amin1,edm1,errdef1,nvpar1,nparx1,icstat1);
	
	likelihood2->Fill(amin1);
    variant2->Fill(outpar1[0]);

	minuit1.SetFCN(fcn3);   
    
    minuit1.Migrad();       // Minuit's best minimization algorithm
    for (int i=0; i<npar1; i++){
        minuit1.GetParameter(i,outpar1[i],err1[i]);
  }

    minuit1.mnstat(amin1,edm1,errdef1,nvpar1,nparx1,icstat1);
    
    likelihood3->Fill(amin1);
    variant3->Fill(outpar1[0]);


	xVecPtr.erase(xVecPtr.begin(),xVecPtr.begin()+100); 
}


	TCanvas * c1 = new TCanvas("c", "c", 1000, 1000);
    
    TLegend lege(0.7,0.7,0.9,0.9);
    lege.AddEntry(variant,"all free","l");
    lege.AddEntry(variant1,"mu=0.05","l");
    lege.AddEntry(variant2,"mu=0.2","l");
    lege.AddEntry(variant3,"mu=0.5","l");
    variant->SetTitle("sigma");
    variant1->SetLineColor(kRed);
    variant2->SetLineColor(kBlue);
    variant3->SetLineColor(kGreen);
    variant->Draw();
    variant1->Draw("same");
    variant2->Draw("same");
    variant3->Draw("same");
    lege.Draw();
    c1->SaveAs("sigma.eps");

    TCanvas * c2 = new TCanvas("c2", "c2", 1000, 1000);

    TLegend lege1(0.7,0.7,0.9,0.9);
    lege1.AddEntry(likelihood,"all free","l");
    lege1.AddEntry(likelihood1,"mu=0.05","l");
    lege1.AddEntry(likelihood2,"mu=0.2","l");
    lege1.AddEntry(likelihood3,"mu=0.5","l");
    likelihood->SetTitle("likelihood");
    likelihood1->SetLineColor(kRed);
    likelihood2->SetLineColor(kBlue);
    likelihood3->SetLineColor(kGreen);
    likelihood->Draw();
    likelihood1->Draw("same");
    likelihood2->Draw("same");
    likelihood3->Draw("same");
    lege1.Draw();
    c2->SaveAs("likelihood.eps");

}
