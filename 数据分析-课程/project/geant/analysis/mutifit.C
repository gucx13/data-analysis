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
const Int_t n = 20 ;
Double_t pdf_sample[n],pdf_sig[n],pdf_bkg[n];

//define pdf
double poissonPdf(double* xPtr, double* yPtr, double* zPtr, double par[]){
    double     s = *xPtr;
    double     b = *yPtr;
    double   sam = *zPtr;
    double    mu = par[0];  //
    double theta = par[1];  //
    double nui = mu*s+theta*b;
    double   f = sam*log(nui)-nui;
//    double     f = (sam-nui)*(sam-nui);
    return f;
}


//define likelihood function
void fcn(int& npar , double* deriv, double& f ,double par[] ,int flag){
//  vector<double> S(pdf_sig, pdf_sig + n);
//  vector<double> B(pdf_bkg, pdf_bkg + n);
//  vector<double> SAM(pdf_sample, pdf_sample + n);

    double lnL = 0.0;
    for(int i = 0 ; i < n ; i++ ){
        double pdf = poissonPdf(&pdf_sig[i],&pdf_bkg[i],&pdf_sample[i],par);

            if (pdf>0)
                lnL += pdf;
    }
    f= -2*lnL;

}




void mutifit(){


TFile *f_bkg = new TFile("bkg_real.root");
TFile *f_sig = new TFile("sig_t0.root");
TFile *f_sample = new TFile("bkg_367.root");
//TFile *f        = new TFile("save.root","RECREATE");

TTree *bkg = (TTree*)f_bkg->Get("bkg");
TTree *sig = (TTree*)f_sig->Get("sig");
TTree *sample = (TTree*)f_sample->Get("bkg");

Double_t energy_bkg, energy_sig, energy_sample;

sample->SetBranchAddress("energy",&energy_sample);
sig->SetBranchAddress("energy",&energy_sig);
bkg->SetBranchAddress("energy",&energy_bkg);


TH1D *hist_sample = new TH1D("sample","sample",n,0,100);
TH1D *hist_sig = new TH1D("sig","sig",n,0,100);
TH1D *hist_bkg = new TH1D("bkg","bkg",n,0,100);

Int_t nentries_sample = (Int_t)sample->GetEntries();
Int_t nentries_sig = (Int_t)sig->GetEntries();
Int_t nentries_bkg = (Int_t)bkg->GetEntries();


for (int i=0;i<nentries_sample;i++) {
    sample->GetEntry(i);
        if (energy_sample>0 && energy_sample<100){
            hist_sample->Fill(energy_sample);
        }
    }

for (int i=0;i<nentries_sig;i++) {
    sig->GetEntry(i);
        if (energy_sig>0 && energy_sig<100){
            hist_sig->Fill(energy_sig);
        }
    } 
for (int i=0;i<nentries_bkg;i++) {
    bkg->GetEntry(i);
        if (energy_bkg>0.01 && energy_bkg<100){
            hist_bkg->Fill(energy_bkg);
        }
    } 

//hist_sig->Draw();



    for(Int_t i=0;i<n;i++){
        pdf_sample[i]=hist_sample->GetBinContent(i+1);
        cout<<pdf_sample[i]<<endl;
}

    for(Int_t i=0;i<n;i++){
        pdf_sig[i]=hist_sig->GetBinContent(i+1)/(Double_t)hist_sig->GetEntries();
        cout<<pdf_sig[i]<<endl;
}

    for(Int_t i=0;i<n;i++){
        pdf_bkg[i]=hist_bkg->GetBinContent(i+1)/(Double_t)hist_bkg->GetEntries();
        cout<<pdf_bkg[i]<<endl;
}


    const int npar = 2;
    TMinuit minuit(npar);
    minuit.SetFCN(fcn);

    double par[npar];    
    double stepSize[npar];
    double minVal[npar];  
    double maxVal[npar];  
    string parName[npar];

    par[0] = 1;   
    stepSize[0] = 0.1;
    minVal[0] = -100;    
    maxVal[0] = 100;
    parName[0] = "sig_num(mu)";

    par[1] = 311;     
    stepSize[1] = 0.1;
    minVal[1] = 0;  
    maxVal[1] = 1000;
    parName[1] = "bkg_num(theta)";

    for (int i=0; i<npar; i++){
        minuit.DefineParameter(i, parName[i].c_str(),
        par[i], stepSize[i], minVal[i], maxVal[i]);
  }

    minuit.Migrad();       // Minuit's best minimization algorithm

    double outpar[npar], err[npar];
    for (int i=0; i<npar; i++){
        minuit.GetParameter(i,outpar[i],err[i]);
		cout<<outpar[i]<<endl;
  	}


	
}
