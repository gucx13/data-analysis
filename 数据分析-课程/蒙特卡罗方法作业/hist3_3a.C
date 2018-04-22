void hist3_3a()
{
TH1F *hist_name = new TH1F("hist_name","3.3a",100,0,2);

for (int i=0;i<10000;i++)
      {
      double r = gRandom->Rndm();
	double x =sqrt(r);
	hist_name->Fill( x );
      }
hist_name->Draw();
}
