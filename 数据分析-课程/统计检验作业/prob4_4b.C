using namespace std;
void prob4_4b() {

      TFile *f = new TFile("prob4_4.root","RECREATE");
      TTree *T = new TTree("T","data from ascii file");
      TTree *T1 = new TTree("T1","theory1 from ascii file");
      TTree *T2 = new TTree("T2","theory2 from ascii file");


      T->ReadFile("data_1.dat","min:max:number");
      T1->ReadFile("theory_1.dat","min:max:number");
      T2->ReadFile("theory_2.dat","min:max:number");

      Float_t data_num,theory1_num,theory2_num;

      T->SetBranchAddress("number",&data_num);
      T1->SetBranchAddress("number",&theory1_num);
      T2->SetBranchAddress("number",&theory2_num);

      Int_t nentries = (Int_t)T->GetEntries();
      TH1F *Chi1 = new TH1F("Chi1","Chi1 distribution",100,0,100);
	TH1F *Chi2 = new TH1F("Chi2","Chi2 distribution",100,0,100);

	for(int k = 0;k<100000;k++){
		Float_t CHI_sq1 = 0,CHI_sq2 = 0;
			for (Int_t i=0;i<nentries;i++) {
                  	T->GetEntry(i);
                  	T1->GetEntry(i);
                  	T2->GetEntry(i);
                  	Float_t theory_1_gen = gRandom->Poisson(theory1_num);
				Float_t theory_2_gen = gRandom->Poisson(theory2_num);
				CHI_sq1 += (theory_1_gen-theory1_num)*(theory_1_gen-theory1_num)/theory1_num;
                  	CHI_sq2 += (theory_2_gen-theory2_num)*(theory_2_gen-theory2_num)/theory2_num;
            	}
            	Chi1->Fill(CHI_sq1);
			Chi2->Fill(CHI_sq2);
	}
	TCanvas* c1 = new TCanvas("c1","c1",500,500);
	Chi1->Draw();
	TCanvas* c2 = new TCanvas("c2","c2",500,500);
	Chi2->Draw();

	Int_t Prob1=0,Prob2=0;
	for(int i = 0;i<100000;i++)
	{
	if(Chi1->GetRandom()>15.8193)
	   Prob1+=1;
	if(Chi2->GetRandom()>35.9653)
         Prob2+=1;
	}
	cout<<Prob1/100000.0<<"  "<<Prob2/100000.0<<endl;

      T->Write();
      T1->Write();
      T2->Write();
}
                                                                                       
