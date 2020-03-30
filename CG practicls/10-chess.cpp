    
    #include<iostream>
    #include<graphics.h>
    #include<math.h>
    using namespace std;
    void bres(int x1, int y1, int x2, int y2) 
    {
    int p,s, dx, dy,x,y;
    float error,m;
    
    dx = x2 - x1;
    dy = y2 - y1;
    p=2*dx-dy;
    x=x1;
    y=y1;

    
     if(x1==x2)
{
   while(y!=y2)
   {
      if(y2-y1>0)
         ++y;
      else
         --y;
      putpixel(x,y,7);
   }
}
else
{
   m=(float)(y2-y1)/(x2-x1);
   error=0;
   putpixel(x,y,7);
   while(x!=x2)
   {
      error+=m;
      if(error>.5)
      {
         if(x2-x1>0)
            y+=1;
         else
            y-=1;
         --error;
      }
      if(x2-x1>0)
         ++x;
      else
         --x;
     putpixel(x,y,7);
   }
    
    }
   } 

    void ddaline(int x1, int y1, int x2, int y2) {
    int s, m, dx, dy;
    float xi, yi, x, y;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy))
    s = abs(dx); else
    s = abs(dy);
    xi = dx / (float) s;
    yi = dy / (float) s;
    x = x1;
    y = y1;
    putpixel(x1 + 0.5, y1 + 0.5, 15);
    for (m = 0; m < s; m++) {
    x += xi;
    y += yi;
    putpixel(x + 0.5, y + 0.5, 15);
    }
    }
    
    
    void fill(int x, int y) {
    int i, j;
    for (i = x; i < (x + 50); i++)
    bres(i, y, i, y + 50);
    //drawline(i,y,i,y+50);
    }
    int main()
     {
    int i, j, c = 0,ch;
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm,NULL);
    cleardevice();
    cout<<"1.Bresnham Algorithm"<<endl;
    
    cout<<"2.DDA Algorithm"<<endl;
     cout<<"3.Exit"<<endl;
    cin>>ch;
    do
    switch(ch)
    {
    case 1:
    bres(100, 50, 100, 450);
    bres(100, 50, 500, 50);
    bres(500, 50, 500, 450);
    bres(100, 450, 500, 450);
    break;
    case 2:
    ddaline(100, 50, 100, 450);
    ddaline(100, 50, 500, 50);
    ddaline(500, 50, 500, 450);
    ddaline(100, 450, 500, 450);
    break;
    case 3:exit(0);
    break;
    default:
    cout<<"Exit From Program"<<endl;
    }
    while(ch>=3);
    for (i = 100; i < 500; i += 50) 
    {
    for (j = 50; j < 450; j += 50) 
    {
    delay(100);
    if (c % 2 == 0)
    fill(i, j);
    c++;
    }
    c++;
    }
   
    closegraph();
    return 0;
    }
