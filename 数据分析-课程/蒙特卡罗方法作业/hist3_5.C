void hist3_5()
{
	double x,t,y;
	TH1F *hist_name = new TH1F("hist_name","3.5",100,0,5);
		for (int i=0;i<10000;i++){
			x = gRandom->Gaus(0,0.5);
			t = gRandom->Exp(1);
			y = x + t;
			hist_name->Fill(y);
		}
		hist_name->Draw();
}
