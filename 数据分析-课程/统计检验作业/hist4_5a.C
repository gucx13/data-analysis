void hist4_5a()
{
TH1F *hist_name = new TH1F("hist_name","4.5",16,0,16);
for(int i=0;i<57;i++)
	{
	hist_name->Fill(0);
	}
for(int i=0;i<203;i++)
      {
      hist_name->Fill(1);
      }
for(int i=0;i<383;i++)
      {
      hist_name->Fill(2);
      }
for(int i=0;i<525;i++)
      {
      hist_name->Fill(3);
      }
for(int i=0;i<532;i++)
      {
      hist_name->Fill(4);
      }
for(int i=0;i<408;i++)
      {
      hist_name->Fill(5);
      }
for(int i=0;i<273;i++)
      {
      hist_name->Fill(6);
      }
for(int i=0;i<139;i++)
      {
      hist_name->Fill(7);
      }
for(int i=0;i<45;i++)
      {
      hist_name->Fill(8);
      }
for(int i=0;i<27;i++)
      {
      hist_name->Fill(9);
      }
for(int i=0;i<10;i++)
      {
      hist_name->Fill(10);
      }
for(int i=0;i<4;i++)
      {
      hist_name->Fill(11);
      }
for(int i=0;i<0;i++)
      {
      hist_name->Fill(12);
      }
for(int i=0;i<1;i++)
      {
      hist_name->Fill(13);
      }
for(int i=0;i<1;i++)
      {
      hist_name->Fill(14);
      }
for(int i=0;i<0;i++)
      {
      hist_name->Fill(15);
      }
hist_name->Draw();
}
