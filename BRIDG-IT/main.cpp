#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include<time.h>
#include<windows.h>
#include<MMSystem.h>
#include<stdlib.h>
#include<queue>
#include<cmath>
#include<stdlib.h>
#include<time.h>
using namespace std;
struct matrice
{
    int X,Y,culoare,graf;
}tabla[9][9];
int n;int copie[9][9],dist;int viz1[40][40],viz2[40][40];
int muzica,culoare,culoare1,culoare2,limba,castigator,dificultatejoc;
int scor1,scor2,scor3,scor4;
void initializari_principale(int &muzica,int &culoare,int &culoare1,int &culoare2,int &limba)
{
    muzica=2;
    limba=1;
    culoare=1;
    culoare1=BLUE;
    culoare2=GREEN;
    n=9;
    scor1=scor2=scor3=scor4=0;
}
void startjoc();
void startjoceasy(bool ok);
void startjochard(bool ok);
void meniu(int &muzica);
void scor()
{
    setcolor(WHITE);
    if(scor1==10)scor1=0;
    if(scor2==10)scor2=0;
    if(scor3==10)scor3=0;
    if(scor4==10)scor4=0;
    if(dificultatejoc==0)
    {
        if(n==9){
        if(scor1==0)outtextxy(80,480,"0 ");
        else if(scor1==1)outtextxy(80,480,"1 ");
        else if(scor1==2)outtextxy(80,480,"2 ");
        else if(scor1==3)outtextxy(80,480,"3 ");
        else if(scor1==4)outtextxy(80,480,"4 ");
        else if(scor1==5)outtextxy(80,480,"5 ");
        else if(scor1==6)outtextxy(80,480,"6 ");
        else if(scor1==7)outtextxy(80,480,"7 ");
        else if(scor1==8)outtextxy(80,480,"8 ");
        else if(scor1==9)outtextxy(80,480,"9 ");
        if(scor2==0)outtextxy(80,600,"0 ");
        else if(scor2==1)outtextxy(80,600,"1 ");
        else if(scor2==2)outtextxy(80,600,"2 ");
        else if(scor2==3)outtextxy(80,600,"3 ");
        else if(scor2==4)outtextxy(80,600,"4 ");
        else if(scor2==5)outtextxy(80,600,"5 ");
        else if(scor2==6)outtextxy(80,600,"6 ");
        else if(scor2==7)outtextxy(80,600,"7 ");
        else if(scor2==8)outtextxy(80,600,"8 ");
        else if(scor2==9)outtextxy(80,600,"9 ");}
        else if(n==7)
        {
        if(scor1==0)outtextxy(80,480,"0 ");
        else if(scor1==1)outtextxy(80,480,"1 ");
        else if(scor1==2)outtextxy(80,480,"2 ");
        else if(scor1==3)outtextxy(80,480,"3 ");
        else if(scor1==4)outtextxy(80,480,"4 ");
        else if(scor1==5)outtextxy(80,480,"5 ");
        else if(scor1==6)outtextxy(80,480,"6 ");
        else if(scor1==7)outtextxy(80,480,"7 ");
        else if(scor1==8)outtextxy(80,480,"8 ");
        else if(scor1==9)outtextxy(80,480,"9 ");
        if(scor2==0)outtextxy(80,640,"0 ");
        else if(scor2==1)outtextxy(80,640,"1 ");
        else if(scor2==2)outtextxy(80,640,"2 ");
        else if(scor2==3)outtextxy(80,640,"3 ");
        else if(scor2==4)outtextxy(80,640,"4 ");
        else if(scor2==5)outtextxy(80,640,"5 ");
        else if(scor2==6)outtextxy(80,640,"6 ");
        else if(scor2==7)outtextxy(80,640,"7 ");
        else if(scor2==8)outtextxy(80,640,"8 ");
        else if(scor2==9)outtextxy(80,640,"9 ");
        }
    }
    else{
        if(n==9){
        if(scor3==0)outtextxy(80,480,"0 ");
        else if(scor3==1)outtextxy(80,480,"1 ");
        else if(scor3==2)outtextxy(80,480,"2 ");
        else if(scor3==3)outtextxy(80,480,"3 ");
        else if(scor3==4)outtextxy(80,480,"4 ");
        else if(scor3==5)outtextxy(80,480,"5 ");
        else if(scor3==6)outtextxy(80,480,"6 ");
        else if(scor3==7)outtextxy(80,480,"7 ");
        else if(scor3==8)outtextxy(80,480,"8 ");
        else if(scor3==9)outtextxy(80,480,"9 ");
        if(scor4==0)outtextxy(80,600,"0 ");
        else if(scor4==1)outtextxy(80,600,"1 ");
        else if(scor4==2)outtextxy(80,600,"2 ");
        else if(scor4==3)outtextxy(80,600,"3 ");
        else if(scor4==4)outtextxy(80,600,"4 ");
        else if(scor4==5)outtextxy(80,600,"5 ");
        else if(scor4==6)outtextxy(80,600,"6 ");
        else if(scor4==7)outtextxy(80,600,"7 ");
        else if(scor4==8)outtextxy(80,600,"8 ");
        else if(scor4==9)outtextxy(80,600,"9 ");
        }
        else if(n==7)
        {
        if(scor3==0)outtextxy(80,480,"0 ");
        else if(scor3==1)outtextxy(80,480,"1 ");
        else if(scor3==2)outtextxy(80,480,"2 ");
        else if(scor3==3)outtextxy(80,480,"3 ");
        else if(scor3==4)outtextxy(80,480,"4 ");
        else if(scor3==5)outtextxy(80,480,"5 ");
        else if(scor3==6)outtextxy(80,480,"6 ");
        else if(scor3==7)outtextxy(80,480,"7 ");
        else if(scor3==8)outtextxy(80,480,"8 ");
        else if(scor3==9)outtextxy(80,480,"9 ");
        if(scor4==0)outtextxy(80,640,"0 ");
        else if(scor4==1)outtextxy(80,640,"1 ");
        else if(scor4==2)outtextxy(80,640,"2 ");
        else if(scor4==3)outtextxy(80,640,"3 ");
        else if(scor4==4)outtextxy(80,640,"4 ");
        else if(scor4==5)outtextxy(80,640,"5 ");
        else if(scor4==6)outtextxy(80,640,"6 ");
        else if(scor4==7)outtextxy(80,640,"7 ");
        else if(scor4==8)outtextxy(80,640,"8 ");
        else if(scor4==9)outtextxy(80,640,"9 ");
        }
    }
}
/*in structura se saleaza coordonarele cenrului unui cerc si culoarea sa*/
//urmatoare functie construieste bulinele si matricea initiala care sta la baza jocului
void cercuri(int Xcentru/*coordonata x a primului element din matrice*/,int Ycentru/*coordonata y a primului element din matrice*/,int raza,int distanta/*distanta dintre 2 cercuri*/,matrice tabla[ ][9],int culoare1,int culoare2)
{//aceasta functie este gata si nu trebuie modificata
    int D=distanta,XC1=Xcentru,YC1=Ycentru,XC2=XC1-distanta/2,YC2=YC1+distanta/2;int k,c,XCP=XC2,YCP=YC2;/*variabile care ajuta la creearea cercurilor*/
    dist=D;int k1,k2;
    k1=k2=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(i%2==0 && j%2==1)
            {tabla[i][j].culoare=culoare1;/*se pun culorile bulinelor primului jucator*/
            tabla[i][j].graf=k1;
            k1++;
            }
            else if(i%2==1 && j%2==0){
                    tabla[i][j].culoare=culoare2;/*se pun culorile bulinelor celui de-al doilea jucator*/
                    tabla[i][j].graf=k2;
                    k2++;}
            else if(i%2==0 && j%2==0 || i%2==1 && j%2==1)tabla[i][j].culoare=0;/*spatiile goale vor avea valoarea 0 in matrice.culoare*/
            if(j==n-1)//de la linia 20 pana la linia linia 31 se creeaza cercurile jocului
            {
                tabla[i][j].X=XCP;
                tabla[i][j].Y=YCP;
                XCP=XC1;
                YCP+=D/2;
            }
            else{
            tabla[i][j].Y=YCP;
            tabla[i][j].X=XCP;
            XCP+=D/2;}
        }
    }
    for(int i=0;i<n;i+=2)
    {
        k=0;
        for(int j=0;j<n;++j)
        {
            if(tabla[i][j].culoare!=0){k++;c=tabla[i][j].culoare;}
        }
        while(k)
        {
            setcolor(c);circle(XC1,YC1,raza);setfillstyle(SOLID_FILL,c);floodfill(XC1,YC1,c);
            XC1+=D;
            k--;
        }
        XC1=Xcentru;YC1+=D;
    }
    XC1=XC2;
    tabla[0][0].X=Xcentru-distanta/2;tabla[0][0].Y=Ycentru;
    for(int i=1;i<n;++i)
        {
            tabla[0][i].X=tabla[0][i-1].X+distanta/2;
            tabla[0][i].Y=tabla[0][i-1].Y;}
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            tabla[i][j].X=tabla[i-1][j].X;
        }
    }
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            tabla[i][j].Y=tabla[i-1][j].Y+distanta/2;
        }
    }
     for(int i=1;i<n;i+=2)
    {
        k=0;
        for(int j=0;j<n;++j)
        {
        if(tabla[i][j].culoare!=0){k++;c=tabla[i][j].culoare;}

        }
        while(k)
        {
            setcolor(c);circle(XC2,YC2,raza);setfillstyle(SOLID_FILL,c);floodfill(XC2,YC2,c);
            XC2+=D;
            k--;
        }
        XC2=Xcentru-distanta/2;YC2+=D;
    }
    setcolor(WHITE);
    /*se creeaza marginile tabloului in urmatorul for*/
    for(int i=0;i<n;++i)
    {
        line(tabla[i][0].X-raza,tabla[i][0].Y-raza,tabla[i][n-1].X+raza,tabla[i][n-1].Y-raza);
        line(tabla[0][i].X-raza,tabla[0][i].Y-raza,tabla[n-1][i].X-raza,tabla[n-1][i].Y+raza);
    }
    line(tabla[n-1][0].X-raza,tabla[n-1][0].Y+raza,tabla[n-1][n-1].X+raza,tabla[n-1][n-1].Y+raza);
    line(tabla[0][n-1].X+raza,tabla[0][n-1].Y-raza,tabla[n-1][n-1].X+raza,tabla[n-1][n-1].Y+raza);
    char*text1,*text2;
    if(dificultatejoc==0)
    {
            if(limba==1)
            {
                text1="PLAYER 1";
                text2="PLAYER 2";
            }
            else if(limba==2)
                {
                    text1="JUCATOR 1";
                    text2="JUCATOR 2";
                }
    }
    else if(dificultatejoc)
    {
        if(limba==1)
        {
            text1="CPU";
            text2="PLAYER";
        }
        else if(limba==2)
        {
            text1="BOT";
            text2="JUCATOR";
        }
    }
    settextstyle(2,0,10);
    setcolor(culoare1);outtextxy(30,400,text1);circle(100,500,raza);setfillstyle(SOLID_FILL,culoare1);floodfill(100,500,culoare1);//creeaza cercul in care apare scorul jucatorului 1
    setcolor(culoare2);outtextxy(30,500+D/3,text2);circle(100,500+D,raza);setfillstyle(SOLID_FILL,culoare2);floodfill(100,500+D,culoare2);//creeaza cercul in care apare scorul jucatorului 2
    for(int i=0;i<n;++i)//cu acest for evităm mutările de pe marginea matricii deoarece nu ar avea sens să fie
    {
        for(int j=0;j<n;++j)
        {
            if(i==0 && j%2==0 || i==n-1 && j%2==0 || j==0 && i%2==0 || j==n-1 && i%2==0)
            {
                tabla[i][j].culoare=-20;
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<'['<<tabla[i][j].X<<','<<tabla[i][j].Y<<','<<tabla[i][j].culoare<<" "<<tabla[i][j].graf<<']';
        }
        cout<<'\n';
    }
}
int b[40][40][40][40],a[40][40];
int dx[4]={0,2,0,-2}, dy[4]={-2,0,2,0};
void butonwinner(int gata)
{
    int x,y;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
    clearmouseclick(WM_LBUTTONDOWN);
    x=mousex();
    y=mousey();
    if(x<=0 && x>=1200 && y<=0 && y>=700)
    {
        gata=1;
    }
    else if(x>=850 && x<=1150 && y>=550 && y<=7000)
    {
        cleardevice();
        meniu(muzica);
    }
    }
}
void winner()
{
    cleardevice();
    readimagefile("tower.jpg",0,0,1200,700);
    int gata=0;
    if(castigator==1)
    {
        if(limba==1)
        {
        if(dificultatejoc==0){readimagefile("PLAYER1WON.jpg",150,150,1050,500);scor1++;}
        else {readimagefile("CPUWON.jpg",150,150,1050,500);scor3++;}
        readimagefile("backbuton.jpg",850,550,1150,700);
        do
        {
            butonwinner(gata);
        }
        while(!gata);
        }
        else if(limba==2)
        {
        if(dificultatejoc==0){readimagefile("JUC1WON.jpg",150,150,1050,500);scor1++;}
        else {readimagefile("CPURWON.jpg",150,150,1050,500);scor3++;}
        readimagefile("INAPOI.jpg",850,600,1150,700);
        do
        {
            butonwinner(gata);
        }
        while(!gata);
        }
    }
    else if(castigator==2)
    {
        if(limba==1)
        {
        if(dificultatejoc==0){readimagefile("PLAYER2WON.jpg",150,150,1050,500);scor2++;}
        else {readimagefile("PLYWON.jpg",150,150,1050,500);scor4++;}
        readimagefile("backbuton.jpg",850,600,1150,700);
        do
        {
            butonwinner(gata);
        }
        while(!gata);
        }
        else if(limba==2)
        {
        if(dificultatejoc==0){readimagefile("JUC2WON.jpg",150,150,1050,500);scor2++;}
        else {readimagefile("JUCWON.jpg",150,150,1050,500);scor4++;}
        readimagefile("INAPOI.jpg",850,600,1150,700);
        do
        {
            butonwinner(gata);
        }
        while(!gata);
        }
    }

}
void parcurgere(int cul, int viz[40][40],int i,int j,int n)
{int k;
 if (i<n && i>=0 && j<n && j>=0)
   {if (!viz[i][j] && tabla[i][j].culoare==cul)
       {viz[i][j]=1;
        for (k=0;k<=3;k++)
        {if (i+dx[k]<n && i+dx[k]>=0 && j+dy[k]<n && j+dy[k]>=0)


          if (b[i][j][i+dx[k]][j+dy[k]]==1)
            parcurgere(cul,viz,i+dx[k],j+dy[k],n);
       }
   }

}
}
void verif(int n,int viz1[40][40], int viz2[40][40])
{int i,j,p;
for (j=0;j<=n-1;j++)
{if (tabla[0][j].culoare==culoare1)
  parcurgere(culoare1,viz1,0,j,n);
}
for (j=0;j<=n-1;j++)
    if(tabla[n-1][j].culoare==culoare1 && viz1[n-1][j]==1)
        {cout<<"PLAYER 1 WON"<<'\n';;
        castigator=1;
        break;
        }
for (i=0;i<=n-1;i++)
  if (tabla[i][0].culoare==culoare2)
      parcurgere(culoare2,viz2,i,0,n);
for (i=0;i<=n-1;i++)
    if(tabla[i][n-1].culoare==culoare2 && viz2[i][n-1]==1)
        {cout<<"PLAYER 2 WON"<<'\n';
        castigator=2;
        break;
        }
for (i=0;i<=n-1;i++){
    for (j=0;j<=n-1;j++){
      viz1[i][j]=viz2[i][j]=0;}}
if(castigator!=0){delay(700);winner();castigator=0;}
}
void nrlinii(int nr)
{
    setcolor(YELLOW);
    if(nr==1)outtextxy(1125,480,"1 ");
    else if(nr==2)outtextxy(1125,480,"2 ");
    else if(nr==3)outtextxy(1125,480,"3 ");
    else if(nr==4)outtextxy(1125,480,"4 ");
    else if(nr==5)outtextxy(1125,480,"5 ");
    else if(nr==6)outtextxy(1125,480,"6 ");
    else if(nr==7)outtextxy(1125,480,"7 ");
    else if(nr==8)outtextxy(1125,480,"8 ");
    else if(nr==9)outtextxy(1125,480,"9 ");
    else if(nr==10)outtextxy(1125,480,"10 ");
    else if(nr==11)outtextxy(1125,480,"11 ");
    else if(nr==12)outtextxy(1125,480,"12 ");
    else if(nr==13)outtextxy(1125,480,"13 ");
    else if(nr==14)outtextxy(1125,480,"14 ");
    else if(nr==15)outtextxy(1125,480,"15 ");
    else if(nr==16)outtextxy(1125,480,"16 ");
    else if(nr==17)outtextxy(1125,480,"17 ");
    else if(nr==18)outtextxy(1125,480,"18 ");
    else if(nr==19)outtextxy(1125,480,"19 ");
    else if(nr==20)outtextxy(1125,480,"20 ");
    else if(nr==21)outtextxy(1125,480,"21 ");
    else if(nr==22)outtextxy(1125,480,"22 ");
    else if(nr==23)outtextxy(1125,480,"23 ");
    else if(nr==24)outtextxy(1125,480,"24 ");
    else if(nr==25)outtextxy(1125,480,"25 ");
}
void startjoc();
void startjoceasy();
void startjochard();
void trasare_linii_player(matrice tabla[ ][9],int n,int raza,bool &gata,bool &ok,int &nr)
{
    int k1,k2;
    k1=k2=0;
    setcolor(YELLOW);
    if(limba==1)outtextxy(1050,420,"LINES");
    else outtextxy(1050,420,"LINII");
    nrlinii(nr);
    int x,y;
    if(ok==false)
    {
     if(limba==1)outtextxy(400,5,"PLAYER1'S turn ");
     else if(limba==2)outtextxy(400,5,"RANDUL JUCATORULUI1");
    }
    if(ok==false)//folosim ok-ul pentru a putea pune pe rand liniile pentru jucători
    {
    if(ismouseclick(WM_LBUTTONDOWN))
    {
    clearmouseclick(WM_LBUTTONDOWN);
    x=mousex();
    y=mousey();//salvam coordonatele click-ului pentru a vede in ce zona a ecranului a avut loc click-ul
    if(!(x>=0 && x<=1200 && y>=0 && y<=700))//verificam daca click-ul a avut loc pe ecran sau nu
       {gata=true;}
    else{
    for(int i=0;i<n && ok==false;i++)
    {
        for(int j=0;j<n && ok==false;j++)
        {
            if(tabla[i][j].culoare==0)
            {
                if(i%2==1 && j%2==1)
                {
                    if(x>=tabla[i][j].X-raza && x<=tabla[i][j].X+raza && y>=tabla[i][j].Y-raza && y<=tabla[i][j].Y+raza)
                    {
                    PlaySound(TEXT("ding.wav"),NULL,SND_ASYNC);
                    setcolor(tabla[i-1][j].culoare);
                    rectangle(tabla[i-1][j].X-5,tabla[i-1][j].Y,tabla[i+1][j].X+5,tabla[i+1][j].Y);
                    b[i-1][j][i+1][j]=b[i+1][j][i-1][j]=1;
                    setfillstyle(SOLID_FILL,tabla[i-1][j].culoare);floodfill(tabla[i][j].X,tabla[i][j].Y,tabla[i-1][j].culoare);
                    tabla[i][j].culoare=-culoare1;
                    nr++;
                    nrlinii(nr);
                    for (int i=0;i<=2*n;i++)
                     for (int j=0;j<=2*n;j++)
                      viz1[i][j]=viz2[i][j]=0;
                    verif (n,viz1,viz2);
                    cout<<endl<<endl;
                    for(int l=0;l<n;++l)
                    {
                        for(int r=0;r<n;++r)
                        {
                            cout<<tabla[l][r].culoare<<" ";
                        }
                        cout<<endl;
                    }
                    /*aducerelanull();
                    for(int r=0;r<4;++r)
                    {1
                    DF(graf1,viz1,r,ok);}*/
                    k1++;
                    setcolor(YELLOW);

                    ok=true;
                    if(limba==1)outtextxy(400,5,"PLAYER2'S turn");
                    else if(limba==2)outtextxy(400,5,"RANDUL JUCATORULUI2");
                    /*se traseaza linia pentru primul jucator si se foloseste de coordonatele salvate in matrice
                    si traseaza linia intre cele doua buline in acest caz trage linia verticala pentru jucatorul 1*/
                    }
                    else if(x>=1099 && x<=1199 && y>=1 && y<=60)
                    {
                        cleardevice();
                        meniu(muzica);
                    }
                    else if(x>=1050 && x<=1200 && y>=550 && y<=700)
                    {
                        startjoc();
                    }

                }
                else if(i%2==0 && j%2==0)
                {
                    if(x>=tabla[i][j].X-raza && x<=tabla[i][j].X+raza && y>=tabla[i][j].Y-raza && y<=tabla[i][j].Y+raza)
                    {
                    PlaySound(TEXT("ding.wav"),NULL,SND_ASYNC);
                    setcolor(tabla[i][j-1].culoare);
                    rectangle(tabla[i][j-1].X,tabla[i][j-1].Y-5,tabla[i][j+1].X,tabla[i][j+1].Y+5);
                    b[i][j-1][i][j+1]=b[i][j+1][i][j-1]=1;
                    setfillstyle(SOLID_FILL,tabla[i][j-1].culoare);floodfill(tabla[i][j].X,tabla[i][j].Y,tabla[i][j-1].culoare);
                    tabla[i][j].culoare=-culoare1;
                    nr++;
                    nrlinii(nr);
                    cout<<endl<<endl;
                    for(int l=0;l<n;++l)
                    {
                        for(int r=0;r<n;++r)
                        {
                            cout<<tabla[l][r].culoare<<" ";
                        }
                        cout<<endl;
                    }
                    for (int i=0;i<=2*n;i++)
                     for (int j=0;j<=2*n;j++)
                      viz1[i][j]=viz2[i][j]=0;
                    verif (n,viz1,viz2);
                    k1++;
                    setcolor(YELLOW);

                    ok=true;
                    if(limba==1)outtextxy(400,5,"PLAYER2'S turn");
                    else if(limba==2)outtextxy(400,5,"RANDUL JUCATORULUI2");
                    /*se traseaza linia pentru primul jucator si se foloseste de coordonatele salvate in matrice
                    si traseaza linia intre cele doua buline in acest caz trage linia orizontala pentru jucatorul 1*/
                    }
                    else if(x>=1099 && x<=1199 && y>=1 && y<=60)
                    {
                        cleardevice();
                        meniu(muzica);
                    }
                    else if(x>=1050 && x<=1200 && y>=550 && y<=700)
                    {
                        startjoc();
                    }

                    }

            }
        }
    }
    }
    }
    }
    else
    {
    if(ismouseclick(WM_LBUTTONDOWN))
    {
    clearmouseclick(WM_LBUTTONDOWN);
    x=mousex();
    y=mousey();
    if(!(x>=0 && x<=1200 && y>=0 && y<=700))
       {gata=true;}
    else{
    for(int i=0;i<n && ok==true;++i)
    {
        for(int j=0;j<n && ok==true;++j)
        {
            if(tabla[i][j].culoare==0)
            {
                if(i%2==1 && j%2==1)
                {
                    if(x>=tabla[i][j].X-raza && x<=tabla[i][j].X+raza && y>=tabla[i][j].Y-raza && y<=tabla[i][j].Y+raza)
                    {
                    PlaySound(TEXT("ding.wav"),NULL,SND_ASYNC);
                    setcolor(tabla[i][j-1].culoare);
                    rectangle(tabla[i][j-1].X,tabla[i][j-1].Y-5,tabla[i][j+1].X,tabla[i][j+1].Y+5);
                    b[i][j-1][i][j+1]=b[i][j+1][i][j-1]=1;
                    setfillstyle(SOLID_FILL,tabla[i][j-1].culoare);floodfill(tabla[i][j].X,tabla[i][j].Y,tabla[i][j-1].culoare);
                    tabla[i][j].culoare=-culoare2;
                    nr++;
                    nrlinii(nr);
                    for (int i=0;i<=2*n;i++)
                     for (int j=0;j<=2*n;j++)
                      viz1[i][j]=viz2[i][j]=0;
                    verif (n,viz1,viz2);
                    cout<<endl<<endl;
                    for(int l=0;l<n;++l)
                    {
                        for(int r=0;r<n;++r)
                        {
                            cout<<tabla[l][r].culoare<<" ";
                        }
                        cout<<endl;
                    }
                    k2++;
                    setcolor(YELLOW);

                    ok=false;
                    if(limba==1)outtextxy(400,5,"PLAYER1'S  turn ");
                    else if(limba==2)outtextxy(400,5,"RANDUL  JUCATORULUI1");
                    /*se traseaza linia pentru al doilea jucator si se foloseste de coordonatele salvate in matrice
                    si traseaza linia intre cele doua buline in acest caz trage linia orizontala pentru jucatorul 2*/
                    }
                    else if(x>=1099 && x<=1199 && y>=1 && y<=60)
                    {
                        cleardevice();
                        meniu(muzica);
                    }
                    else if(x>=1050 && x<=1200 && y>=550 && y<=700)
                    {
                        startjoc();
                    }
                }
                else if(i%2==0 && j%2==0)
                {
                    if(x>=tabla[i][j].X-raza && x<=tabla[i][j].X+raza && y>=tabla[i][j].Y-raza && y<=tabla[i][j].Y+raza)
                    {
                    PlaySound(TEXT("ding.wav"),NULL,SND_ASYNC);
                    setcolor(tabla[i-1][j].culoare);
                    rectangle(tabla[i-1][j].X-5,tabla[i-1][j].Y,tabla[i+1][j].X+5,tabla[i+1][j].Y);
                    b[i-1][j][i+1][j]=b[i+1][j][i-1][j]=1;
                    setfillstyle(SOLID_FILL,tabla[i-1][j].culoare);floodfill(tabla[i][j].X,tabla[i][j].Y,tabla[i-1][j].culoare);
                    tabla[i][j].culoare=-culoare2;
                    nr++;
                    nrlinii(nr);
                    cout<<endl<<endl;
                    for(int l=0;l<n;++l)
                    {
                        for(int r=0;r<n;++r)
                        {
                            cout<<tabla[l][r].culoare<<" ";
                        }
                        cout<<endl;
                    }
                    for (int i=0;i<=2*n;i++)
                     for (int j=0;j<=2*n;j++)
                      viz1[i][j]=viz2[i][j]=0;
                    verif (n,viz1,viz2);
                    /*aducerelanull();
                    for(int r=0;r<4;++r)
                    {
                    DF(graf2,viz2,r,ok);}*/
                    k2++;
                    setcolor(YELLOW);

                    ok=false;
                    if(limba==1)outtextxy(400,5,"PLAYER1'S  turn ");
                    else if(limba==2)outtextxy(400,5,"RANDUL  JUCATORULUI1");
                    /*se traseaza linia pentru al doilea jucator si se foloseste de coordonatele salvate in matrice
                    si traseaza linia intre cele doua buline in acest caz trage linia verticala pentru jucatorul 2*/
                    }
                    else if(x>=1099 && x<=1199 && y>=1 && y<=60)
                    {
                        cleardevice();
                        meniu(muzica);
                    }
                    else if(x>=1050 && x<=1200 && y>=550 && y<=700)
                    {
                        startjoc();
                    }

                }
            }
        }
    }
    }
    }
    //logical(0);
    }
}
void startjoc()
{   //functia pentru joc
    dificultatejoc=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int l=0;l<n;++l)
            {
                for(int r=0;r<n;++r)
                {
                    b[i][j][l][r]=0;
                }
            }
        }
    }
    PlaySound(NULL,NULL,SND_ASYNC);
    if(muzica!=0)muzica=2;
    readimagefile("tower.jpg",0,0,1200,700);
    if(limba==1)readimagefile("backbuton.jpg",1099,1,1199,60);
    else readimagefile("INAPOI.jpg",1099,1,1199,60);
    if(n==9)cercuri(400,100,30,120,tabla,culoare1,culoare2);//apeleaza functia cercuri ce creeaza tabla jocului propriuzis
    else cercuri(500,100,40,160,tabla,culoare1,culoare2);
    readimagefile("restart.jpg",1050,550,1200,700);

    scor();
    bool gata=false,ok=false;
    int k=0;
    do
    {
    trasare_linii_player(tabla,n,30,gata,ok,k);//functia care trage liniile pentru cei doi playeri in timpul jocului
    }
    while(!gata);
    getch();
    closegraph();
}
void trasare_linii_player_easy(matrice tabla[ ][9],int n,int raza,bool &gata,bool &ok,int &nr1,bool ok1)
{
    srand(time(NULL));
    matrice liber[81];
    int k1,k2;
    k1=k2=0;
    int nr=0;
    setcolor(YELLOW);
    if(limba==1)outtextxy(1050,420,"LINES");
    else outtextxy(1050,420,"LINII");
    int x,y;
    if(ok==false)
    {
     if(limba==1)outtextxy(400,5,"CPU'S turn   ");
     else if(limba==2)outtextxy(400,5,"RANDUL CALCULATORULUI   ");
    }
    if(ok==false)//folosim ok-ul pentru a putea pune pe rand liniile pentru jucători
    {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(tabla[i][j].culoare==0)
            {
                liber[nr].X=i;
                liber[nr++].Y=j;
            }
        }
    }
    int l=rand()%nr;
    int i=liber[l].X,j=liber[l].Y;
                if(i%2==1 && j%2==1)
                {
                    delay(700);
                    PlaySound(TEXT("ding.wav"),NULL,SND_ASYNC);
                    setcolor(tabla[i-1][j].culoare);
                    rectangle(tabla[i-1][j].X-5,tabla[i-1][j].Y,tabla[i+1][j].X+5,tabla[i+1][j].Y);
                    b[i-1][j][i+1][j]=b[i+1][j][i-1][j]=1;
                    setfillstyle(SOLID_FILL,tabla[i-1][j].culoare);floodfill(tabla[i][j].X,tabla[i][j].Y,tabla[i-1][j].culoare);
                    tabla[i][j].culoare=-culoare1;
                    nr1++;
                    nrlinii(nr1);
                    for (int i=0;i<=2*n;i++)
                     for (int j=0;j<=2*n;j++)
                      viz1[i][j]=viz2[i][j]=0;
                    verif (n,viz1,viz2);
                    cout<<endl<<endl;
                    for(int l=0;l<n;++l)
                    {
                        for(int r=0;r<n;++r)
                        {
                            cout<<tabla[l][r].culoare<<" ";
                        }
                        cout<<endl;
                    }
                    /*aducerelanull();
                    for(int r=0;r<4;++r)
                    {1
                    DF(graf1,viz1,r,ok);}*/
                    k1++;
                    setcolor(YELLOW);

                    ok=true;
                    if(limba==1)outtextxy(400,5,"PLAYER'S turn   ");
                    else if(limba==2)outtextxy(400,5,"RANDUL JUCATORULUI   ");
                    /*se traseaza linia pentru primul jucator si se foloseste de coordonatele salvate in matrice
                    si traseaza linia intre cele doua buline in acest caz trage linia verticala pentru jucatorul 1*/

                }
                else if(i%2==0 && j%2==0)
                {
                    delay(700);
                    PlaySound(TEXT("ding.wav"),NULL,SND_ASYNC);
                    setcolor(tabla[i][j-1].culoare);
                    rectangle(tabla[i][j-1].X,tabla[i][j-1].Y-5,tabla[i][j+1].X,tabla[i][j+1].Y+5);
                    b[i][j-1][i][j+1]=b[i][j+1][i][j-1]=1;
                    setfillstyle(SOLID_FILL,tabla[i][j-1].culoare);floodfill(tabla[i][j].X,tabla[i][j].Y,tabla[i][j-1].culoare);
                    tabla[i][j].culoare=-culoare1;
                    nr1++;
                    nrlinii(nr1);
                    cout<<endl<<endl;
                    for(int l=0;l<n;++l)
                    {
                        for(int r=0;r<n;++r)
                        {
                            cout<<tabla[l][r].culoare<<" ";
                        }
                        cout<<endl;
                    }
                    for (int i=0;i<=2*n;i++)
                     for (int j=0;j<=2*n;j++)
                      viz1[i][j]=viz2[i][j]=0;
                    verif (n,viz1,viz2);
                    k1++;
                    setcolor(YELLOW);

                    ok=true;
                    if(limba==1)outtextxy(400,5,"PLAYER'S turn");
                    else if(limba==2)outtextxy(400,5,"RANDUL JUCATORULUI");
                    /*se traseaza linia pentru primul jucator si se foloseste de coordonatele salvate in matrice
                    si traseaza linia intre cele doua buline in acest caz trage linia orizontala pentru jucatorul 1*/
                    }

            }
    else
    {
    if(ismouseclick(WM_LBUTTONDOWN))
    {
    clearmouseclick(WM_LBUTTONDOWN);
    x=mousex();
    y=mousey();
    if(!(x>=0 && x<=1200 && y>=0 && y<=700))
       {gata=true;}
    else{
    for(int i=0;i<n && ok==true;++i)
    {
        for(int j=0;j<n && ok==true;++j)
        {
            if(tabla[i][j].culoare==0)
            {
                if(i%2==1 && j%2==1)
                {
                    if(x>=tabla[i][j].X-raza && x<=tabla[i][j].X+raza && y>=tabla[i][j].Y-raza && y<=tabla[i][j].Y+raza)
                    {

                    PlaySound(TEXT("ding.wav"),NULL,SND_ASYNC);
                    setcolor(tabla[i][j-1].culoare);
                    rectangle(tabla[i][j-1].X,tabla[i][j-1].Y-5,tabla[i][j+1].X,tabla[i][j+1].Y+5);
                    b[i][j-1][i][j+1]=b[i][j+1][i][j-1]=1;
                    setfillstyle(SOLID_FILL,tabla[i][j-1].culoare);floodfill(tabla[i][j].X,tabla[i][j].Y,tabla[i][j-1].culoare);
                    tabla[i][j].culoare=-culoare2;
                    nr1++;
                    nrlinii(nr1);
                    for (int i=0;i<=2*n;i++)
                     for (int j=0;j<=2*n;j++)
                      viz1[i][j]=viz2[i][j]=0;
                    verif (n,viz1,viz2);
                    cout<<endl<<endl;
                    for(int l=0;l<n;++l)
                    {
                        for(int r=0;r<n;++r)
                        {
                            cout<<tabla[l][r].culoare<<" ";
                        }
                        cout<<endl;
                    }
                    k2++;
                    setcolor(YELLOW);

                    ok=false;
                    if(limba==1)outtextxy(400,5,"CPU'S  turn         ");
                    else if(limba==2)outtextxy(400,5,"RANDUL  CALCULATORULUI");
                    /*se traseaza linia pentru al doilea jucator si se foloseste de coordonatele salvate in matrice
                    si traseaza linia intre cele doua buline in acest caz trage linia orizontala pentru jucatorul 2*/
                    }
                    else if(x>=1099 && x<=1199 && y>=1 && y<=60)
                    {
                        cleardevice();
                        meniu(muzica);
                    }
                    else if(x>=1050 && x<=1200 && y>=550 && y<=700)
                    {
                        startjoceasy(ok1);
                    }
                }
                else if(i%2==0 && j%2==0)
                {
                    if(x>=tabla[i][j].X-raza && x<=tabla[i][j].X+raza && y>=tabla[i][j].Y-raza && y<=tabla[i][j].Y+raza)
                    {

                    PlaySound(TEXT("ding.wav"),NULL,SND_ASYNC);
                    setcolor(tabla[i-1][j].culoare);
                    rectangle(tabla[i-1][j].X-5,tabla[i-1][j].Y,tabla[i+1][j].X+5,tabla[i+1][j].Y);
                    b[i-1][j][i+1][j]=b[i+1][j][i-1][j]=1;
                    setfillstyle(SOLID_FILL,tabla[i-1][j].culoare);floodfill(tabla[i][j].X,tabla[i][j].Y,tabla[i-1][j].culoare);
                    tabla[i][j].culoare=-culoare2;
                    nr1++;
                    nrlinii(nr1);
                    cout<<endl<<endl;
                    for(int l=0;l<n;++l)
                    {
                        for(int r=0;r<n;++r)
                        {
                            cout<<tabla[l][r].culoare<<" ";
                        }
                        cout<<endl;
                    }
                    for (int i=0;i<=2*n;i++)
                     for (int j=0;j<=2*n;j++)
                      viz1[i][j]=viz2[i][j]=0;
                    verif (n,viz1,viz2);
                    /*aducerelanull();
                    for(int r=0;r<4;++r)
                    {
                    DF(graf2,viz2,r,ok);}*/
                    k2++;
                    setcolor(YELLOW);

                    ok=false;
                    if(limba==1)outtextxy(400,5,"CPU'S  turn         ");
                    else if(limba==2)outtextxy(400,5,"RANDUL  CALCULATORULUI");
                    /*se traseaza linia pentru al doilea jucator si se foloseste de coordonatele salvate in matrice
                    si traseaza linia intre cele doua buline in acest caz trage linia verticala pentru jucatorul 2*/
                    }
                    else if(x>=1099 && x<=1199 && y>=1 && y<=60)
                    {
                        cleardevice();
                        meniu(muzica);
                    }
                    else if(x>=1050 && x<=1200 && y>=550 && y<=700)
                    {
                        startjoceasy(ok1);
                    }
                }
            }
        }
    }
    }
    }
    //logical(0);
    }
}
void startjoceasy(bool ok)
{   //functia pentru joc
    dificultatejoc=1;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int l=0;l<n;++l)
            {
                for(int r=0;r<n;++r)
                {
                    b[i][j][l][r]=0;
                }
            }
        }
    }
    PlaySound(NULL,NULL,SND_ASYNC);
    if(muzica!=0)muzica=2;
    readimagefile("tower.jpg",0,0,1200,700);
    if(limba==1)readimagefile("backbuton.jpg",1099,1,1199,60);
    else readimagefile("INAPOI.jpg",1099,1,1199,60);
    if(n==9)cercuri(400,100,30,120,tabla,culoare1,culoare2);//apeleaza functia cercuri ce creeaza tabla jocului propriuzis
    else cercuri(500,100,40,160,tabla,culoare1,culoare2);
    readimagefile("restart.jpg",1050,550,1200,700);

    scor();bool ok1=ok;
    bool gata=false;
    int k=0;
    do
    {
    trasare_linii_player_easy(tabla,n,30,gata,ok,k,ok1);//functia care trage liniile pentru cei doi playeri in timpul jocului
    }
    while(!gata);
    getch();
    closegraph();
}
void trasare_linii_player_hard(matrice tabla[ ][9],int n,int raza,bool &gata,bool &ok,int &nr1,bool ok1)
{ int l1,c1,ifinal,jfinal;
    srand(time(NULL));
    matrice liber[81];
    int k1,k2;
    k1=k2=0;
    int nr=0;
    setcolor(YELLOW);
    if(limba==1)outtextxy(1050,420,"LINES");
    else outtextxy(1050,420,"LINII");
    int x,y;
    if(ok==false)
    {
     if(limba==1)outtextxy(400,5,"CPU'S turn ");
     else if(limba==2)outtextxy(400,5,"RANDUL CALCULATORULUI");
    }
    if(ok==false)//folosim ok-ul pentru a putea pune pe rand liniile pentru jucători
    {
    int primamut=1;

    for (int i=0; i<n;++i)
        for (int j=0;j<n;j++)
          for (int k=0;k<n;++k)
            for (int p=0;p<n;++p)
                 if (b[i][j][k][p]==1)
                    primamut=0;

    if (primamut==1)
     {{for (int i1=1;i1<=n-2;i1+=2)
            {liber[nr].X=i1;
            liber[nr++].Y=1;
            liber[nr].X=i1;
            liber[nr++].Y=n-2;}
     }
        int l=rand()%nr;
    ifinal=liber[l].X;
    jfinal=liber[l].Y;}
    else{int vizitat[40][40],final=0,da=0;
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
          vizitat[i][j]=0;
     for (int coord1=0;coord1<n;++coord1)
        for (int coord2=0;coord2<n;++coord2)
            {int x1,x2,x3,x4;
                if (tabla[coord1][coord2].culoare==0)
                {if (coord2-1>=0 && coord2+1<n)
                 if (tabla[coord1][coord2+1].culoare==culoare1)
                    {b[coord1][coord2-1][coord1][coord2+1]=b[coord1][coord2+1][coord1][coord2-1]=1;
                    x1=coord1;
                    x2=coord2-1;
                    x3=coord1;
                    x4=coord2+1;
                    da=1;}
                 if (coord1-1>=0 && coord1+1<n)
                    if (tabla[coord1-1][coord2].culoare==culoare1)
                    {b[coord1-1][coord2][coord1+1][coord2]=b[coord1+1][coord2][coord1-1][coord2]=1;
                    x1=coord1-1;
                    x2=coord2;
                    x3=coord1+1;
                    x4=coord2;
                    da=1;}
            if (da==1){
            for (int j0=0;j0<n;++j0)
             if (tabla[0][j0].culoare==culoare1)
               parcurgere(culoare1, vizitat,0,j0,n);
          for (int j0=0;j0<n;++j0)
            {
                if (vizitat[n-1][j0] && tabla[n-1][j0].culoare==culoare1 )
                   {final=1;
                   ifinal=coord1;
                   jfinal=coord2;}}

            for (int i=0;i<n;++i)
              for (int j=0;j<n;++j)
                 vizitat[i][j]=0;
                 da=0;
                 b[x1][x2][x3][x4]=b[x3][x4][x1][x2]=0;}}
            }
    if (!final )
    {int d[100][100],p,u;
     matrice c[100],prec[100][100];
     for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            d[i][j]=n*n;
     for (int i=1;i<n;i+=2)
     {c[(i+1)/2].X=i;
      c[(i+1)/2].Y=0;
      d[i][0]=0;
      prec[i][0].X=-1;
     }
     p=1;
     u=n/2;
     int x0,y0,xn,yn;
     while (p<=u)
     {if (c[p].Y==n-1)
        p++;
      else
      {x0=c[p].X;
       y0=c[p++].Y;
       for (int i=0;i<4;++i)
       {xn=x0+dx[i];
        yn=y0+dy[i];
            if (b[x0][y0][xn][yn]==1 && xn>=0 && xn<n && yn>=0 && yn<n)
               {if (d[xn][yn]>d[x0][y0])
                {d[xn][yn]=d[x0][y0];
                 prec[xn][yn].X=x0;
                 prec[xn][yn].Y=y0;
                 c[++u].X=xn;
                 c[u].Y=yn;
                }}
                else
                 if (xn>=0 && xn<n && yn>=0 && yn<n)
                 if (tabla[(x0+xn)/2][(y0+yn)/2].culoare==0)
                  {if (d[xn][yn]>1+d[x0][y0])
                    {d[xn][yn]=1+d[x0][y0];
                    prec[xn][yn].X=x0;
                    prec[xn][yn].Y=y0;
                    c[++u].X=xn;
                    c[u].Y=yn;}
                    }

                  }
       }

      }
    int minim=n*n;
    for (int i=1;i<=n-1;i+=2)
    if (d[i][n-1]<minim)
      {minim=d[i][n-1];
       p=i;

      }
    for (int a1=0;a1<=n-1;a1++)
        {{for (int a2=0;a2<=n-1;a2++)
    cout<<d[a1][a2]<<' ';}
    cout<<endl;}
    cout<<endl;
    int lin=p, col=n-1, okay=0;
    while (prec[lin][col].X!=-1)
    {l1=prec[lin][col].X;
    c1=prec[lin][col].Y;
    if (tabla[(lin+l1)/2][(col+c1)/2].culoare==0 && okay==0)
        {ifinal=(lin+l1)/2;
        jfinal=(col+c1)/2;
        okay=1;
        break;}
    lin=l1;
    col=c1;
    }
    if (okay==0)
    {lin=p, col=n-1;
        while (prec[lin][col].X!=-1)
    {l1=prec[lin][col].X;
    c1=prec[lin][col].Y;
    if (tabla[(lin+l1)/2][(col+c1)/2].culoare==0 )
        {ifinal=(lin+l1)/2;
        jfinal=(col+c1)/2;
        break;}
    lin=l1;
    col=c1;
    }
    }
if (minim==n*n)
{for (int param1=0;param1<n;param1++)
    for (int param2=0;param2<n;param2++)
        if (tabla[param1][param2].culoare==0)
    {ifinal=param1;
    jfinal=param2;}
}

    }
    }



     int i=ifinal, j=jfinal;
     cout<<ifinal<<' '<<jfinal;



                if(i%2==1 && j%2==1)
                {
                    delay(700);
                    PlaySound(TEXT("ding.wav"),NULL,SND_ASYNC);
                    setcolor(tabla[i-1][j].culoare);
                    rectangle(tabla[i-1][j].X-5,tabla[i-1][j].Y,tabla[i+1][j].X+5,tabla[i+1][j].Y);
                    b[i-1][j][i+1][j]=b[i+1][j][i-1][j]=1;
                    setfillstyle(SOLID_FILL,tabla[i-1][j].culoare);floodfill(tabla[i][j].X,tabla[i][j].Y,tabla[i-1][j].culoare);
                    tabla[i][j].culoare=-culoare1;
                    nr1++;
                    nrlinii(nr1);
                    for (int i=0;i<=2*n;i++)
                     for (int j=0;j<=2*n;j++)
                      viz1[i][j]=viz2[i][j]=0;
                    verif (n,viz1,viz2);
                    cout<<endl<<endl;
                    for(int l=0;l<n;++l)
                    {
                        for(int r=0;r<n;++r)
                        {
                            cout<<tabla[l][r].culoare<<" ";
                        }
                        cout<<endl;
                    }
                    /*aducerelanull();
                    for(int r=0;r<4;++r)
                    {1
                    DF(graf1,viz1,r,ok);}*/
                    k1++;
                    setcolor(YELLOW);

                    ok=true;
                    if(limba==1)outtextxy(400,5,"PLAYER'S turn");
                    else if(limba==2)outtextxy(400,5,"RANDUL JUCATORULUI");
                    /*se traseaza linia pentru primul jucator si se foloseste de coordonatele salvate in matrice
                    si traseaza linia intre cele doua buline in acest caz trage linia verticala pentru jucatorul 1*/

                }
                else if(i%2==0 && j%2==0)
                {
                    delay(700);
                    PlaySound(TEXT("ding.wav"),NULL,SND_ASYNC);
                    setcolor(tabla[i][j-1].culoare);
                    rectangle(tabla[i][j-1].X,tabla[i][j-1].Y-5,tabla[i][j+1].X,tabla[i][j+1].Y+5);
                    b[i][j-1][i][j+1]=b[i][j+1][i][j-1]=1;
                    setfillstyle(SOLID_FILL,tabla[i][j-1].culoare);floodfill(tabla[i][j].X,tabla[i][j].Y,tabla[i][j-1].culoare);
                    tabla[i][j].culoare=-culoare1;
                    nr1++;
                    nrlinii(nr1);
                    cout<<endl<<endl;
                    for(int l=0;l<n;++l)
                    {
                        for(int r=0;r<n;++r)
                        {
                            cout<<tabla[l][r].culoare<<" ";
                        }
                        cout<<endl;
                    }
                    for (int i=0;i<=2*n;i++)
                     for (int j=0;j<=2*n;j++)
                      viz1[i][j]=viz2[i][j]=0;
                    verif (n,viz1,viz2);
                    k1++;
                    setcolor(YELLOW);

                    ok=true;
                    if(limba==1)outtextxy(400,5,"PLAYER'S turn");
                    else if(limba==2)outtextxy(400,5,"RANDUL JUCATORULUI");
                    /*se traseaza linia pentru primul jucator si se foloseste de coordonatele salvate in matrice
                    si traseaza linia intre cele doua buline in acest caz trage linia orizontala pentru jucatorul 1*/
                    }

            }
    else
    {
    if(ismouseclick(WM_LBUTTONDOWN))
    {
    clearmouseclick(WM_LBUTTONDOWN);
    x=mousex();
    y=mousey();
    if(!(x>=0 && x<=1200 && y>=0 && y<=700))
       {gata=true;}
    else{
    for(int i=0;i<n && ok==true;++i)
    {
        for(int j=0;j<n && ok==true;++j)
        {
            if(tabla[i][j].culoare==0)
            {
                if(i%2==1 && j%2==1)
                {
                    if(x>=tabla[i][j].X-raza && x<=tabla[i][j].X+raza && y>=tabla[i][j].Y-raza && y<=tabla[i][j].Y+raza)
                    {
                    PlaySound(TEXT("ding.wav"),NULL,SND_ASYNC);
                    setcolor(tabla[i][j-1].culoare);
                    rectangle(tabla[i][j-1].X,tabla[i][j-1].Y-5,tabla[i][j+1].X,tabla[i][j+1].Y+5);
                    b[i][j-1][i][j+1]=b[i][j+1][i][j-1]=1;
                    setfillstyle(SOLID_FILL,tabla[i][j-1].culoare);floodfill(tabla[i][j].X,tabla[i][j].Y,tabla[i][j-1].culoare);
                    tabla[i][j].culoare=-culoare2;
                    nr1++;
                    nrlinii(nr1);
                    for (int i=0;i<=2*n;i++)
                     for (int j=0;j<=2*n;j++)
                      viz1[i][j]=viz2[i][j]=0;
                    verif (n,viz1,viz2);
                    cout<<endl<<endl;
                    for(int l=0;l<n;++l)
                    {
                        for(int r=0;r<n;++r)
                        {
                            cout<<tabla[l][r].culoare<<" ";
                        }
                        cout<<endl;
                    }
                    k2++;
                    setcolor(YELLOW);

                    ok=false;
                    if(limba==1)outtextxy(400,5,"CPU'S  turn          ");
                    else if(limba==2)outtextxy(400,5,"RANDUL  CALCULATORULUI");
                    /*se traseaza linia pentru al doilea jucator si se foloseste de coordonatele salvate in matrice
                    si traseaza linia intre cele doua buline in acest caz trage linia orizontala pentru jucatorul 2*/
                    }
                    else if(x>=1099 && x<=1199 && y>=1 && y<=60)
                    {
                        cleardevice();
                        meniu(muzica);
                    }
                    else if(x>=1050 && x<=1200 && y>=550 && y<=700)
                    {
                        startjochard(ok1);
                    }
                }
                else if(i%2==0 && j%2==0)
                {
                    if(x>=tabla[i][j].X-raza && x<=tabla[i][j].X+raza && y>=tabla[i][j].Y-raza && y<=tabla[i][j].Y+raza)
                    {
                    PlaySound(TEXT("ding.wav"),NULL,SND_ASYNC);
                    setcolor(tabla[i-1][j].culoare);
                    rectangle(tabla[i-1][j].X-5,tabla[i-1][j].Y,tabla[i+1][j].X+5,tabla[i+1][j].Y);
                    b[i-1][j][i+1][j]=b[i+1][j][i-1][j]=1;
                    setfillstyle(SOLID_FILL,tabla[i-1][j].culoare);floodfill(tabla[i][j].X,tabla[i][j].Y,tabla[i-1][j].culoare);
                    tabla[i][j].culoare=-culoare2;
                    nr1++;
                    nrlinii(nr1);
                    cout<<endl<<endl;
                    for(int l=0;l<n;++l)
                    {
                        for(int r=0;r<n;++r)
                        {
                            cout<<tabla[l][r].culoare<<" ";
                        }
                        cout<<endl;
                    }
                    for (int i=0;i<=2*n;i++)
                     for (int j=0;j<=2*n;j++)
                      viz1[i][j]=viz2[i][j]=0;
                    verif (n,viz1,viz2);
                    /*aducerelanull();
                    for(int r=0;r<4;++r)
                    {
                    DF(graf2,viz2,r,ok);}*/
                    k2++;
                    setcolor(YELLOW);

                    ok=false;
                    if(limba==1)outtextxy(400,5,"CPU'S  turn          ");
                    else if(limba==2)outtextxy(400,5,"RANDUL  CALCULATORULUI");
                    /*se traseaza linia pentru al doilea jucator si se foloseste de coordonatele salvate in matrice
                    si traseaza linia intre cele doua buline in acest caz trage linia verticala pentru jucatorul 2*/
                    }
                    else if(x>=1099 && x<=1199 && y>=1 && y<=60)
                    {
                        cleardevice();
                        meniu(muzica);
                    }
                    else if(x>=1050 && x<=1200 && y>=550 && y<=700)
                    {
                        startjochard(ok1);
                    }

                }
            }
        }
    }
    }
    }
    //logical(0);
    }
}
void startjochard(bool ok)
{   //functia pentru joc
    dificultatejoc=2;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int l=0;l<n;++l)
            {
                for(int r=0;r<n;++r)
                {
                    b[i][j][l][r]=0;
                }
            }
        }
    }
    PlaySound(NULL,NULL,SND_ASYNC);
    if(muzica!=0)muzica=2;
    readimagefile("tower.jpg",0,0,1200,700);
    if(limba==1)readimagefile("backbuton.jpg",1099,1,1199,60);
    else readimagefile("INAPOI.jpg",1099,1,1199,60);
    if(n==9)cercuri(400,100,30,120,tabla,culoare1,culoare2);//apeleaza functia cercuri ce creeaza tabla jocului propriuzis
    else cercuri(500,100,40,160,tabla,culoare1,culoare2);
    readimagefile("restart.jpg",1050,550,1200,700);

    scor();
    bool gata=false,ok1=ok;
    int k=0;
    do
    {
    trasare_linii_player_hard(tabla,n,30,gata,ok,k,ok1);//functia care trage liniile pentru cei doi playeri in timpul jocului
    }
    while(!gata);
    getch();
    closegraph();
}
void dificultate();
void butonincepe(int &gata)
{
    int x,y;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
    clearmouseclick(WM_LBUTTONDOWN);
    x=mousex();
    y=mousey();
    if(!(x>=0 && x<=1200 && y>=0 && y<=700))
       {gata=1;}
    else if(x>=300 && x<=900 && y>=150 && y<=300)
    {
        cleardevice();
        if(dificultatejoc==1)startjoceasy(false);
        else if(dificultatejoc==2)startjochard(false);
    }
    else if(x>=300 && x<=900 && y>=400 && y<=550)
    {
        cleardevice();
        if(dificultatejoc==1)startjoceasy(true);
        else if(dificultatejoc==2)startjochard(true);
    }
    else if(x>=1099 && x<=1199 && y>=1 && y<=60)
    {
        cleardevice();
        dificultate();
    }
    }
}
void incepe()
{
    int gata=0;
    readimagefile("podalg.jpg",0,0,1200,700);
    if(limba==1)
    {
        readimagefile("backbuton.jpg",1099,1,1199,60);
        readimagefile("CPUSTR.jpg",300,150,900,300);
        readimagefile("PLYSTR.jpg",300,400,900,550);
    do
    {
        butonincepe(gata);

    }
    while(!gata);
    }
    else if(limba==2)
    {
        readimagefile("INAPOI.jpg",1099,1,1199,60);
        readimagefile("CLCINC.jpg",300,150,900,300);
        readimagefile("JUCINC.jpg",300,400,900,550);
    do
    {
        butonincepe(gata);

    }
    while(!gata);
    }
}
void alegeri();
int butondificultate(int gata)
{
    int x,y;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
    clearmouseclick(WM_LBUTTONDOWN);
    x=mousex();
    y=mousey();
    if(!(x>=0 && x<=1200 && y>=0 && y<=700))
       {gata=1;}
    else if(x>=300 && x<=900 && y>=150 && y<=300)
    {
        cleardevice();
        dificultatejoc=1;
        incepe();
    }
    else if(x>=300 && x<=900 && y>=400 && y<=550)
    {
        cleardevice();
        dificultatejoc=2;
        incepe();

    }
    else if(x>=1099 && x<=1199 && y>=1 && y<=60)
    {
        cleardevice();
        alegeri();
    }
    }
}
void dificultate()
{
    int gata=0;
    readimagefile("podalg.jpg",0,0,1200,700);
    if(limba==1)
    {
        readimagefile("backbuton.jpg",1099,1,1199,60);
        readimagefile("EASY.jpg",300,150,900,300);
        readimagefile("HARD.jpg",300,400,900,550);
    do
    {
        butondificultate(gata);

    }
    while(!gata);
    }
    else if(limba==2)
    {
        readimagefile("INAPOI.jpg",1099,1,1199,60);
        readimagefile("USOR.jpg",300,150,900,300);
        readimagefile("GREU.jpg",300,400,900,550);
    do
    {
        butondificultate(gata);

    }
    while(!gata);
    }
}
void butonalegeri(int gata)
{
    int x,y;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
    clearmouseclick(WM_LBUTTONDOWN);
    x=mousex();
    y=mousey();
    if(!(x>=0 && x<=1200 && y>=0 && y<=700))
       {gata=1;}
    else if(x>=300 && x<=900 && y>=150 && y<=300)
    {
        cleardevice();
        startjoc();
    }
    else if(x>=300 && x<=900 && y>=400 && y<=550)
    {
        cleardevice();
        dificultate();
    }
    else if(x>=1099 && x<=1199 && y>=1 && y<=60)
    {
        cleardevice();
        meniu(muzica);
    }
    }
}
void alegeri()
{
    int gata=0;
    readimagefile("podalg.jpg",0,0,1200,700);
    if(limba==1)
    {
        readimagefile("backbuton.jpg",1099,1,1199,60);
        readimagefile("PVP.jpg",300,150,900,300);
        readimagefile("PVC.jpg",300,400,900,550);
        do
        {
            butonalegeri(gata);
        }
        while(!gata);
    }
    else if(limba==2)
    {
        readimagefile("INAPOI.jpg",1099,1,1199,60);
        readimagefile("JVJ.jpg",300,150,900,300);
        readimagefile("JVC.jpg",300,400,900,550);
        do
        {
            butonalegeri(!gata);
        }
        while(!gata);
    }
}
void music(int &ok)
{   //functia pentru muzica
    if(ok==1)//se oprestee muzica cand ok este 1
    {
        readimagefile("notmusicbutton.jpg",1,1,60,60);
        PlaySound(NULL,NULL,SND_ASYNC);
        ok=0;
        muzica=0;
    }
    else if(ok==0)//se porneste muzica cand ok este 0
    {
        readimagefile("musicbutton.jpg",1,1,60,60);
        PlaySound(TEXT("music4.wav"),NULL,SND_ASYNC);
        ok=1;
        muzica=1;
    }
}
int buton_setari(int &culoare,int &culoare1,int &culoare2,int &limba,int &gata)
{
    int x,y;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
    clearmouseclick(WM_LBUTTONDOWN);
    x=mousex();
    y=mousey();
    if(!(x>=0 && x<=1200 && y>=0 && y<=700))
       {gata=1;}
    else{
            if(x>=1099 && x<=1199 && y>=1 && y<=60)
            {
                cleardevice();
                meniu(muzica);
            }
            else if(x>=300 && x<=900 && y>=50 && y<=200)
            {
                if(limba==1)
                {
                    limba=2;
                    readimagefile("butonlimbaromana.jpg",300,50,900,200);
                    readimagefile("INAPOI.jpg",1099,1,1199,60);
                    if(culoare==1)
                    {
                        readimagefile("culoributon_albastruverde.jpg",300,250,900,400);
                    }
                    else if(culoare==2)
                    {
                        readimagefile("culoributon_albrosu.jpg",300,250,900,400);
                    }
                    if(n==9)
                    {
                        readimagefile("DIMENSIUNE9.jpg",300,450,900,600);
                    }
                    else if(n==7)
                    {
                        readimagefile("DIMENSIUNE7.jpg",300,450,900,600);
                    }
                }
                else if(limba==2)
                {
                    limba=1;
                    readimagefile("butonlimbaengleza.jpg",300,50,900,200);
                    readimagefile("backbuton.jpg",1099,1,1199,60);
                    if(culoare==1)
                    {
                        readimagefile("colorsbuton_bluegreen.jpg",300,250,900,400);
                    }
                    else if(culoare==2)
                    {
                        readimagefile("colorsbuton_whitered.jpg",300,250,900,400);

                    }
                    if(n==9)
                    {
                        readimagefile("DIMENSION9.jpg",300,450,900,600);
                    }
                    else if(n==7)
                    {
                        readimagefile("DIMENSION7.jpg",300,450,900,600);

                    }
                }
            }
                else if(x>=300 && x<=900 && y>=250 && y<=400)
                {
                    if(culoare==1)
                    {
                        culoare=2;
                        culoare1=WHITE;
                        culoare2=RED;
                        if(limba==1)readimagefile("colorsbuton_whitered.jpg",300,250,900,400);
                        else if(limba==2)readimagefile("culoributon_albrosu.jpg",300,250,900,400);
                    }
                    else if(culoare==2)
                    {
                        culoare=1;
                        culoare1=BLUE;
                        culoare2=GREEN;
                        if(limba==1)readimagefile("colorsbuton_bluegreen.jpg",300,250,900,400);
                        else if(limba==2)readimagefile("culoributon_albastruverde.jpg",300,250,900,400);
                    }
                }
                else if(x>=300 && x<=900 && y>=450 && y<=600)
                {
                    if(n==9)
                    {
                        n=7;
                        if(limba==1)readimagefile("DIMENSION7.jpg",300,450,900,600);
                        else if(limba==2)readimagefile("DIMENSIUNE7.jpg",300,450,900,600);
                    }
                    else if(n==7)
                    {
                        n=9;
                        if(limba==1)readimagefile("DIMENSION9.jpg",300,450,900,600);
                        else if(limba==2)readimagefile("DIMENSIUNE9.jpg",300,450,900,600);
                    }
                }
            }
        }
    }


void butonreguli(int &gata)//functie pentru butonul de back de la reguli (functia nu e gata)
{
    int x,y;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
    clearmouseclick(WM_LBUTTONDOWN);
    x=mousex();
    y=mousey();
    if(!(x>=0 && x<=1200 && y>=0 && y<=700))
       {gata=1;}
    else{
            if(x>=1099 && x<=1199 && y>=1 && y<=60)
            {
                cleardevice();
                //PlaySound(NULL,NULL,SND_ASYNC);
                meniu(muzica);
            }

         }
    }
}
void reguli(int &ok)
{
    //funtia pentru reguli ce afiseaza regulile jocului
    //nu prea e de lucru la ea
    //trebuie facut doar sa mearga butonul back
    int gata=0;
    if(limba==1)
    {
    readimagefile("pod2.jpg",0,0,1200,700);
    readimagefile("backbuton.jpg",1099,1,1199,60);
    settextstyle(0,0,0);setcolor(WHITE);
    delay(500);
    outtextxy(65,100,"On the surface, Bridg-It appears to be a simple game of connecting dots to form lines across");
    delay(500);
    outtextxy(65,130,"the board.Playing Bridg-It is simple.");
    setcolor(RED);settextstyle(2,0,10);
    delay(500);
    outtextxy(65,180,"RULES");
    setcolor(YELLOW);settextstyle(0,0,0);
    delay(500);
    outtextxy(65,230,"1 Players take turns connecting two adjacent dots of their own color with a bridge.");
    delay(500);
    outtextxy(65,280,"2 Adjacent dots are considered to be dots directly above, below, to the right, or to the left");
    delay(500);
    outtextxy(65,330,"of another dot with the same color.");
    delay(500);
    outtextxy(65,380,"3 A newly formed bridge cannot cross a bridge already played and whoever connects their");
    delay(500);
    outtextxy(65,430,"opposite edges of the board first wins. ");
    delay(500);
    readimagefile("BG.jpg",400,500,800,700);
    do
    {
        butonreguli(gata);
    } while(!gata);
    }
    else if(limba==2)
    {
    readimagefile("pod2.jpg",0,0,1200,700);
    readimagefile("INAPOI.jpg",1099,1,1199,60);
    settextstyle(0,0,0);setcolor(WHITE);
    delay(500);
    outtextxy(65,100,"La suprafata, Bridg-It pare a fi un simplu joc de conectare a punctelor pentru a forma ");
    delay(500);
    outtextxy(65,130,"de linii de-a lungul tablei de joc.Este usor sa joci Bridg-It.");
    setcolor(RED);settextstyle(2,0,10);
    delay(500);
    outtextxy(65,180,"REGULI");
    setcolor(YELLOW);settextstyle(0,0,0);
    delay(500);
    outtextxy(65,230,"1 Jucatorii fac ture conectand doua puncte adiacente de propria culoare cu un pod.");
    delay(500);
    outtextxy(65,280,"2 Punctele adiacente sunt considerate a fi puncte direct deasupra, dedesubt, la dreapta sau la stanga");
    delay(500);
    outtextxy(65,330,"de un alt punct cu aceeasi culoare.");
    delay(500);
    outtextxy(65,380,"3 Un nou pod format nu poate traversa un pod deja existent si jucatorul care leaga");
    delay(500);
    outtextxy(65,430,"margini opuse ale tablei de joc castiga");
    delay(500);
    readimagefile("BG.jpg",400,500,800,700);
    do
    {
        butonreguli(gata);
    } while(!gata);
    }
}
void setari()
{
    if(limba==1)
    {
    readimagefile("podsetari.jpg",0,0,1200,700);
    readimagefile("backbuton.jpg",1099,1,1199,60);
    readimagefile("butonlimbaengleza.jpg",300,50,900,200);
    if(culoare==1)readimagefile("colorsbuton_bluegreen.jpg",300,250,900,400);
    else if(culoare==2)readimagefile("colorsbuton_whitered.jpg",300,250,900,400);
    if(n==9)readimagefile("DIMENSION9.jpg",300,450,900,600);
    else if(n==7)readimagefile("DIMENSION7.jpg",300,450,900,600);
    int gata=0;
   do
   {
       buton_setari(culoare,culoare1,culoare2,limba,gata);
   }
   while(!gata);
    }
    else if(limba==2)
    {
    readimagefile("podsetari.jpg",0,0,1200,700);
    readimagefile("INAPOI.jpg",1099,1,1199,60);
    readimagefile("butonlimbaromana.jpg",300,50,900,200);
    if(culoare==1)readimagefile("culoributon_albastruverde.jpg",300,250,900,400);
    else if(culoare==2)readimagefile("culoributon_albrosu.jpg",300,250,900,400);
    if(n==9)readimagefile("DIMENSIUNE9.jpg",300,450,900,600);
    else if(n==7)readimagefile("DIMENSIUNE7.jpg",300,450,900,600);
    int gata=0;
   do
   {
       buton_setari(culoare,culoare1,culoare2,limba,gata);
   }
   while(!gata);
    }
}
void clickmeniu(bool &gata,int &ok)
{
    //funtie care face comenzi pentru meniu
    int x,y;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
    clearmouseclick(WM_LBUTTONDOWN);
    x=mousex();
    y=mousey();
    if(!(x>=0 && x<=1200 && y>=0 && y<=700))
       {gata=true;}
       else
       {
         if(x>=1 && x<=60 && y>=1 && y<=60)
          {music(ok);}//in caz ca click-ul e pe butonul de muzica
          else if(x>=350 && x<=850 && y>=100 && y<=200)//in caz ca click-ul e pe butonul de start
           {
           cleardevice();
           alegeri();
           }
           else if(x>=350 && x<=850 && y>=400 && y<=500)//in caz ca click-ul e pe butonul de reguli
           {
               cleardevice();
               reguli(ok);
           }
           else if(x>=350 && x<=850 && y>=250 && y<=350)//in caz ca click-ul e pe butonul de setari
           {   cleardevice();
               setari();
           }
       }
    }
}
void meniu(int &muzica)//functie care creeaza meniul
{
    castigator=0;
    readimagefile("firstimage.jpg",0,0,1200,700);
    //urmatoarele 4 instructiuni afiseaza butoanele meniului pe ecran
    if(muzica==2)
    {
        PlaySound(TEXT("music4.wav"),NULL,SND_ASYNC);//muzica incepe mereu cand se deschide jocul
        readimagefile("musicbutton.jpg",1,1,60,60);
        muzica=1;
    }
    else if(muzica==0)readimagefile("notmusicbutton.jpg",1,1,60,60);
    else if(muzica==1)readimagefile("musicbutton.jpg",1,1,60,60);
    if(limba==1)
    {
    readimagefile("startbutton.jpg",350,100,850,200);
    readimagefile("settingsbutton.jpg",350,250,850,350);
    readimagefile("rulesbutton.jpg",350,400,850,500);
    int ok=1;
    bool gata1=false;
    do
    {
        clickmeniu(gata1,ok);//se foloseste functia pentru a putea efectua comenzi pe ecran
    }
    while(!gata1);
    }
    else if(limba==2)
    {
    readimagefile("INCEPEJOCUL.jpg",350,100,850,200);
    readimagefile("setaributton.jpg",350,250,850,350);
    readimagefile("regulibutton.jpg",350,400,850,500);
    int ok=1;
    bool gata1=false;
    do
    {
        clickmeniu(gata1,ok);//se foloseste functia pentru a putea efectua comenzi pe ecran
    }
    while(!gata1);
    }
    getch();
    closegraph();
}
int main()
{
    initwindow(1200,700);
    initializari_principale(muzica,culoare,culoare1,culoare2,limba);
    meniu(muzica);
    return 0;
}
