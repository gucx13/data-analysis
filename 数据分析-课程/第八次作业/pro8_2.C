using namespace std;
int pro8_2(){
   gStyle->SetOptStat(kFALSE);
   TH1F* variant1 = new TH1F("variant1","variant1",30,0.5,1.5);
TH1F* chindf1 = new TH1F("chindf1","chindf1",30,0,0.5);
TF1* fcn1 = new TF1("fcn1","[0] * TMath::Gaus(x,0.05,[1])",-5,5);
for(int j = 0 ; j < 1000 ; j++){
		TH1F* gsd = new TH1F("gsd","gsd_0",30,-5,5);
			for(int i = 0 ; i < 100 ; i++){
				gsd->Fill(gRandom->Gaus(0,1));
			}
		fcn1->SetParameters(1,1);
		gsd->Fit(fcn1,"R");
		chindf1->Fill(fcn1->GetChisquare()/99);
		Double_t mypara0[2];
		fcn1->GetParameters(&mypara0[0]);
		variant1->Fill(mypara0[1]);
	}
	TCanvas * c1 = new TCanvas("c", "c", 1000, 1000);
}
