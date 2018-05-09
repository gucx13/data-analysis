Double_t func(Double_t *val, Double_t *par)
{
   Float_t x = val[0];
   Float_t y = val[1];
   Double_t f = x*x-y*y;
   return f;
}
void test()
{
   TF2 *f = new TF2("f",func,-1,1,-1,1);
   f->Draw("surf1");
}
