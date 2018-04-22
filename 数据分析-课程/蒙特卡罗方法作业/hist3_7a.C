using namespace std;

int GenFunc(int num,int mean)
{
int z = 0;
      for(int i=0;i<num;i++)
      {
      z += gRandom->Poisson(mean);
      }
      return z;
}
                       


void hist3_7a()
{
TH1F *hist_name = new TH1F("hist_name","3.7a",100,0,3000);
for(int j=0;j<1000;j++)
{
	int photon=1,dananum=6;
		for(int i=0;i<dananum;i++)
		{
		photon = GenFunc(photon,3);
		
		}
	hist_name->Fill(photon);
}
hist_name->Draw();
}










