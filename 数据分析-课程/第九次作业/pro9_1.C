using namespace std;
int pro9_1(){
   gStyle->SetOptStat(kFALSE);
TH1F* mean = new TH1F("mean","mean",30,-0.5,0.5);
TH1F* variant = new TH1F("variant","variant",30,0.5,2); 
TH1F* likelihood = new TH1F("likelihood","likelihood",30,0,30); 

TH1F* variant1 = new TH1F("variant1","variant1",30,0.5,2);
TH1F* likelihood1 = new TH1F("likelihood1","likelihood1",30,0,30);

TH1F* variant2 = new TH1F("variant2","variant2",30,0.5,2);
TH1F* likelihood2 = new TH1F("likelihood2","likelihood2",30,0,30);

TH1F* variant3 = new TH1F("variant3","variant3",30,0.5,2);
TH1F* likelihood3 = new TH1F("likelihood3","likelihood3",30,0,30);

TF1* fcn = new TF1("fcn","gaus",-5,5);
TF1* fcn1 = new TF1("fcn1","[0] * TMath::Gaus(x,0.05,[1])",-5,5);
TF1* fcn2 = new TF1("fcn2","[0] * TMath::Gaus(x,0.2,[1])",-5,5);
TF1* fcn3 = new TF1("fcn3","[0] * TMath::Gaus(x,0.5,[1])",-5,5);

double par[2]={1,1};


	for(int j = 0 ; j < 1000 ; j++){
		TH1F* gsd = new TH1F("gsd","gsd_0",30,-5,5);
			for(int i = 0 ; i < 100 ; i++){
				gsd->Fill(gRandom->Gaus(0,1));
			}
		fcn->SetParameters(10,0,1);
		gsd->Fit(fcn,"RLS");
		TFitResultPtr r = gsd->Fit(fcn, "RLS");
		likelihood->Fill(r->MinFcnValue());
		Double_t mypara[3];
		fcn->GetParameters(&mypara[0]);
		mean->Fill(mypara[1]);
		variant->Fill(mypara[2]);

		fcn1->SetParameters(1,1);
		gsd->Fit(fcn1,"RLS");
		TFitResultPtr r1 = gsd->Fit(fcn1, "RLS");
        likelihood1->Fill(r1->MinFcnValue());
		Double_t mypara1[2];
		fcn1->GetParameters(&mypara1[0]);
		variant1->Fill(mypara1[1]);

		fcn2->SetParameters(1,1);
        gsd->Fit(fcn2,"RLS");
        TFitResultPtr r2 = gsd->Fit(fcn2, "RLS");
        likelihood2->Fill(r2->MinFcnValue());
        Double_t mypara2[2];
        fcn2->GetParameters(&mypara2[0]);
        variant2->Fill(mypara2[1]);

		fcn3->SetParameters(1,1);
        gsd->Fit(fcn3,"R");
		TFitResultPtr r3 = gsd->Fit(fcn3, "RLS");
        likelihood3->Fill(r3->MinFcnValue());
        Double_t mypara3[2];
        fcn3->GetParameters(&mypara3[0]);
        variant3->Fill(mypara3[1]);
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
	c1->SaveAs("sigma.pdf");

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
    c2->SaveAs("likelihood.pdf");



return 0;
}


	
		
