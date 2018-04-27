using namespace std;
double l_annihi = 5 , l_scatter = 0.1;
double P_scatter,P_annihi;


double Decay_len(){
      P_scatter = gRandom->Rndm();
      P_annihi = gRandom->Rndm();
      if (-log(P_scatter)*l_scatter<-log(P_annihi)*l_annihi)
            return -log(P_scatter)*l_scatter;
      else
            return 0;

}

void Simu_scatter_annihi(){
double posi_x = 0, posi_y = 0;
double angel = gRandom->Uniform(-30,30);
double Decay_len = sin(30);
//while(Decay_len>0){
cout<<Decay_len<<endl;
//}


}
