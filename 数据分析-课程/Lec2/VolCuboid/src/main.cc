//#########main.cc##################

#include <iostream>
//#include <math>

#include "VolCuboid.h"
//#include "TH1F.h"

using namespace std;

int main ()
{
   cout << "Class VolCuboid " << endl;
   float length, width, height;
   
   length = 2.0 ; //cm
   width  = 3.0 ; //cm
   height = 4.0 ; //cm

   VolCuboid myVolCuboid( length, width, height );
   //VolCuboid *myVolCuboid = new VolCuboid( length, width, height );

   float volume = myVolCuboid.Vol() ;
   //float volume = myVolCuboid->Vol() ;
   cout << "Volume is " << volume << " cm^3" << endl;
   cout << "Area   is " << myVolCuboid.Area() << " cm^2" << endl;


   // use pointer
   VolCuboid * pVolCuboid = new VolCuboid( length, width, height );
   
   volume = pVolCuboid->Vol();
   cout << endl;
   cout << "Operation with pointer" << endl;
   cout << "Volume is " << volume << " cm^3" << endl;
   cout << "Area   is " << pVolCuboid->Area() << " cm^2" << endl;

}
