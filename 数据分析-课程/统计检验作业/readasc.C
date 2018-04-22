using namespace std;
void readasc() {
	
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
	Float_t CHI_sq1 = 0,CHI_sq2 = 0;
		for (Int_t i=0;i<nentries;i++) {
			T->GetEntry(i);
			T1->GetEntry(i);
			T2->GetEntry(i);
			CHI_sq1 += (data_num-theory1_num)*(data_num-theory1_num)/theory1_num;
			CHI_sq2 += (data_num-theory2_num)*(data_num-theory2_num)/theory2_num;
			cout<<data_num<<"  "<<theory1_num<<"  "<<theory2_num<<endl;
		}
			cout<<CHI_sq1<< "  "<<CHI_sq2<<endl;

	T->Write();
	T1->Write();
	T2->Write();
}
