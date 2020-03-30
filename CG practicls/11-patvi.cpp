#include<graphics.h>
#include<iostream>
#include<cmath>
using namespace std;
class pixel
{

public :
void DDA(float x1,float y1,float x2,float y2)
{
    float len,X,Y,dx,dy;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    (dx>dy)?len=dx:len=dy;
    dx=(x2-x1)/len;
    dy=(y2-y1)/len;
    X=x1+0.5;
    Y=y1+0.5;
    for(int i=0;i<len;i++)
    {

    putpixel(X,Y,GREEN);	
    		X+=dx;
		Y+=dy;
         delay(20);
         
    }
 
}


};
int main() 
{
    pixel p;
    int ch;
    int gd = DETECT,gm; 
   initgraph(&gd, &gm,NULL);
 cout<<"PATTERN DRAWING";
  p.DDA(50,50,250,50); //A to B;
  p.DDA(250,50,250,150);//B to C;
 
  p.DDA(250,150,50,150);//C to D;
  p.DDA(50,150,50,50);  //D to A;   
 p.DDA(50,100,150,50);  //E to F;
 p.DDA(150,50,250,100); //F to G;
 p.DDA(250,100,150,150);//G to H;
 
 p.DDA(150,150,50,100); //H to E;
 p.DDA(100,75,200,75); //I to J;
 p.DDA(200,75,200,125);//J to k;
 p.DDA(200,125,100,125);//K to L;
 
 p.DDA(100,125,100,75);//L to I;
 
 circle(150,100,25);
 
	return 0;
  }


 



