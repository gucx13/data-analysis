#include <math.h>
using namespace std;
double func(double k , double nu){
	double L;
	L=1880*(log(nu)-7.06*0.0/k)-nu*exp(-7.06*0.0/k)+940*(log(nu)-7.06*6.0/k)-nu*exp(-7.06*6.0/k)+530*(log(nu)-7.06*12.0/k)-nu*exp(-7.06*12.0/k)+305*(log(nu)-7.06*18.0/k)-nu*exp(-7.06*18.0/k);
return L;
}

void prob6_11(){
double k_max=1,nu_max=1,L_max = -10000000;
	for (int i = 50;i<2000;i++){
		for (int j = 50;j<4000;j++){
			if (func(0.001*i,1*j)>func(0.001*(i-1),1*j) ){
                L_max=func(0.001*i,1*j);
                k_max=0.001*i;
				nu_max=1*j;
				cout<<L_max<<"  "<<k_max<<"  "<<nu_max<<endl;
            }

		}
	}
//cout<<L_max<<"  "<<k_max<<"  "<<nu_max<<endl;
}
