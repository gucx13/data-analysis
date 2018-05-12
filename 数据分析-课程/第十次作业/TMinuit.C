vector <double> xVecPtr;
void getData(vector <double>* xVecPtr){
	double TauTruth = 0.5;
	TRandom r;
		for (int i=0; i < 30 ; i++){
			double x = r.Exp(TauTruth);
			xVecPtr->push_back(x)
		}	
}
void fcn(int& npar , double* deriv, double& f ,double par[] ,int flag){
	vector<double> xVec = *xVecPtr;
	int n = xVec.size();

	double lnL = 0.0;
	for(int i = 0 ; i < n ; i++ ){
		double x = xVec[i];
		double pdf = expPdf(&x,par);
			if (pdf>0)
				lnL += log(pdf);
	}
	f= -2.0*lnL;	
}
void TMinuit(){

}
