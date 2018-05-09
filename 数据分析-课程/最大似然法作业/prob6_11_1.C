

double func(double* k , double* nu){
	double L;
    L=1880*(log(nu)-7.06*0.0/k)-nu*exp(-7.06*0.0/k)+940*(log(nu)-7.06*6.0/k)-nu*exp(-7.06*6.0/k)+530*(log(nu)-7.06*12.0/k)-nu*exp(-7.06*12.0/k)+305*(log(nu)-7.06*18.0/k)-nu*exp(-7.06*18.0/k);
return L;
}
void prob6_11_1()
{
   TF2 *f = new TF2("f",func,0.1,3,0,4000);
   f->Draw("surf1");
}
