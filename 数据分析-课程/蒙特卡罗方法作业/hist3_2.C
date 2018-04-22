void hist3_2()
{ 
   TFile *file = new TFile("hist1.root","RECREATE");
   TH1F *hist3 = new TH1F("hist_name","3.2a",100,0,100);
   TH2F *hist34 = new TH2F("hist_name","3.2b",20,0,50,20,0,50);
   for (int i=0;i<100;i++) {
	TH1F *hist_name = new TH1F(Form("hist_name_%d",i),Form("hist_name_%d",i),5,0,1);
      for (int i=0;i<100;i++)
	{
	hist_name->Fill( gRandom->Rndm() );
	}
	hist3->Fill(hist_name->GetBinContent(3));
	hist34->Fill(hist_name->GetBinContent(3),hist_name->GetBinContent(4));
   }
   TCanvas *c1 = new TCanvas("c1","c1");
   hist3->Draw();
   TCanvas *c2 = new TCanvas("c2","c2");
   hist34->Draw();
      file->Write();
}
