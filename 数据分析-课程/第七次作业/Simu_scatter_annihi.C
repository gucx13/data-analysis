#include "TMath.h" 
using namespace std;
double l_annihi = 5 , l_scatter = 0.1;
double P_scatter,P_annihi;
double Decay_lens;

void Decay_len(){
      P_scatter = gRandom->Rndm();
      P_annihi = gRandom->Rndm();
      if (-log(P_scatter)*l_scatter<-log(P_annihi)*l_annihi)
            Decay_lens = -log(P_scatter)*l_scatter;
      else
            Decay_lens = 0;

}

void Simu_scatter_annihi(){
   	TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,20,1000,600);
	TMultiGraph *mg = new TMultiGraph();
	for(int j = 0 ; j < 100 ; j++){
 		Decay_lens = -log(gRandom->Rndm())*l_scatter;
		double posi_x[1000] = {0}, posi_y[1000] = {0};
		int i = 1;
		double angle = 0;
		while(Decay_lens>0){
			angle += gRandom->Uniform(-30,30);
			posi_x[i] = posi_x[i-1]+Decay_lens*cos(angle*3.1415926/180);
			posi_y[i] = posi_y[i-1]+Decay_lens*sin(angle*3.1415926/180);
			P_scatter = gRandom->Rndm();
      		P_annihi = gRandom->Rndm();
      			if (-log(P_scatter)*l_scatter<-log(P_annihi)*l_annihi)
            			Decay_lens = -log(P_scatter)*l_scatter;
      			else
            			Decay_lens = 0;
			i += 1;
}
		TGraph* gr = new TGraph(i,posi_x,posi_y);
		mg->Add(gr);
}
mg->Draw("AC");
}
