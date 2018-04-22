void tree1w() {
TFile *f = new TFile("tree1.root","recreate"); TTree *t1 = new TTree("t1","test tree"); gRandom->SetSeed(0);
Float_t px,py,pz;
Double_t random;
Int_t i;
//Set the Branches of tree 
t1->Branch("px",&px,"px/F"); 
t1->Branch("py",&py,"py/F"); 
t1->Branch("pz",&pz,"pz/F"); 
t1->Branch("random",&random,"random/D"); 
t1->Branch("i",&i,"i/I");
for (i=0;i<5000;i++)
{
gRandom->Rannor(px,py);
pz = px*px + py*py;
random = gRandom->Rndm(); t1->Fill();//Fill tree
}
t1->Write();
}
