#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
map<char,string>mymap;
	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];
cout<<mymap['a']<<endl;


cout<<mymap.size()<<endl;
return 0;
}
