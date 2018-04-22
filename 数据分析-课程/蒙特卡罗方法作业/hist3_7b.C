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



void hist3_7b()
{
TH1F *hist_name = new TH1F("hist_name","3.7b",200,0,5000);
for(int j=0;j<1000;j++)
{     
      int photon=1,dananum=6;
		photon = GenFunc(photon,6);
            for(int i=1;i<dananum;i++)
            {
            photon = GenFunc(photon,3);

            }
      hist_name->Fill(photon);
}
hist_name->Draw();
}



