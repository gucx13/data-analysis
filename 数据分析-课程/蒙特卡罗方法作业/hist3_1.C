void hist3_1()
{

   TFile *file = new TFile("hist0.root","RECREATE");
   TH1F *hist_name = new TH1F("hist_name","3.1",100,-1,2);

   for (int i=0;i<10000;i++) {
	hist_name->Fill( gRandom->Rndm() ); 
   }
	hist_name->Draw();
	file->Write();
}
