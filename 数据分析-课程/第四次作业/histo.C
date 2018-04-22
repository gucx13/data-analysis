void histo()
{
   	TFile *file = new TFile("Gauss.root","RECREATE");
	TH2F *hist_name = new TH2F("test","title",1000,0,100,1000,0,100);
	for(int i=0;i<1000;i++)
	hist_name->Fill(gRandom->Gaus(50,10),gRandom->Gaus(50,10));
	hist_name->Draw();
	file->Write();
}
