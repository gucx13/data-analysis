using namespace std;
double pro8_1(){
   gStyle->SetOptStat(kFALSE);
TH1F* mean = new TH1F("mean","mean",30,-0.5,0.5);
TH1F* variant = new TH1F("variant","variant",30,0.5,1.5); 
TH1F* chindf = new TH1F("chindf","chindf",30,0,0.5); 

TF1* fcn = new TF1("fcn","gaus",-5,5);
for(int j = 0 ; j < 1000 ; j++){
		TH1F* gsd = new TH1F("gsd","gsd_0",30,-5,5);
			for(int i = 0 ; i < 100 ; i++){
				gsd->Fill(gRandom->Gaus(0,1));
			}
		fcn->SetParameters(10,0,1);
		gsd->Fit(fcn,"R");
		chindf->Fill(fcn->GetChisquare()/99);
		Double_t mypara[3];
		fcn->GetParameters(&mypara[0]);
		mean->Fill(mypara[1]);
		variant->Fill(mypara[2]);
}
TCanvas * c1 = new TCanvas("c", "c", 1000, 1000);

chindf->Draw();

c1->SaveAs("prob1_chindf.pdf");
return 0;
}
