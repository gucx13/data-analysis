using namespace std;
int hw6_1(){
   gStyle->SetOptStat(kFALSE);
TH1F* mean = new TH1F("mean","mean",30,-0.5,0.5);
TH1F* variant = new TH1F("variant","variant",30,0.5,1.5); 
TH1F* chindf = new TH1F("chindf","chindf",30,0,0.5); 

TH1F* variant1 = new TH1F("variant1","variant1",30,0.5,1.5);
TH1F* chindf1 = new TH1F("chindf1","chindf1",30,0,0.5);

TF1* fcn = new TF1("fcn","gaus",-5,5);
TF1* fcn1 = new TF1("fcn1","[0] * TMath::Gaus(x,0.05,[1])",-5,5);
double par[2]={1,1};


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
		
		fcn1->SetParameters(1,1);
		gsd->Fit(fcn1,"R");
		chindf1->Fill(fcn1->GetChisquare()/99);
		Double_t mypara0[2];
		fcn1->GetParameters(&mypara0[0]);
		variant1->Fill(mypara0[1]);
	}
	TCanvas * c1 = new TCanvas("c", "c", 1000, 1000);
	TLegend lege(0.7,0.7,0.9,0.9);
      lege.AddEntry(variant,"all free","l");
      lege.AddEntry(variant1,"constrain","l");
	variant->SetTitle("sigma");
	variant1->SetLineColor(kRed);
	variant->Draw();
	variant1->Draw("same");
      lege.Draw();
	c1->SaveAs("sigma.pdf");

      TCanvas * c2 = new TCanvas("c2", "c2", 1000, 1000);

      TLegend lege1(0.7,0.7,0.9,0.9);
      lege1.AddEntry(chindf,"all free","l");
      lege1.AddEntry(chindf1,"constrain","l");
      chindf->SetTitle("chi2/ndf");
      chindf1->SetLineColor(kRed);
      chindf->Draw();
      chindf1->Draw("same");
      lege1.Draw();
      c2->SaveAs("chi2ndf.pdf");



return 0;
}
