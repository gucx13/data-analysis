#include<iostream>
#include<map>
using namespace std;
int main()
{
map<char,int> mymap;
mymap['x']=100;
mymap['y']=200;
mymap['z']=300;
map<char,int>::reverse_iterator rit;
for (rit=mymap.rbegin();rit!=mymap.rend();++rit)
   cout<<rit->first<<"=>"<<rit->second<<endl;
return 0;
}
