using namespace std;
void pro6_7(){
TH1F *exp = new TH1F("exp","exp",90,-2,4);
int tau = 1 , n=100;
for (int j=0; j<1000;j++){
double sum=0;
	for (int i = 0;i<n;i++){
		sum += gRandom->Exp(tau);
	}
sum = n/sum;
exp->Fill(sum);
}
exp->Draw();
}
