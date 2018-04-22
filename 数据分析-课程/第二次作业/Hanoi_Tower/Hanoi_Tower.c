#include <iostream>

using namespace std;

void TowersofHanoi(int n,char x,char y,char z)
{

        if(n)
        {
            TowersofHanoi(n-1,x,z,y);
            cout << " From " << x << " To " << y << endl;
            TowersofHanoi(n-1,z,y,x);
        }
}

int Hanoi_Tower()
{
    TowersofHanoi(1000,'A','B','C');
    return 0;
}
