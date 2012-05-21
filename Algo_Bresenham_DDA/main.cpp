#include <cstdlib>
#include <iostream>
//#include <conio2.h>
#include<math.h>
//#include <cmath>
#include <graphics.h>
#include <iomanip>

//#define i 24

using namespace std;

int main(int argc, char *argv[])
{
    //textbackground(CYAN);
       
    int i,pil,bar,kol;
    int xa,ya,xb,yb; //titik
    int dx,dy;//delta
    int stp;//step
    float xt,yt;//tambah
    float adx,ady;//rata2
    double a1,a2,Po;//temp
    float m,adx2,ady2;    
    
    system("cls");
    
    do
    {
        cout<<" ================================ "<<endl;
        cout<<"|             Menu               |"<<endl;
        cout<<" ================================ "<<endl;
        cout<<"| 1. Bresenham                   |"<<endl;
        cout<<"| 2. DDA                         |"<<endl;
        cout<<"| 3. About                       |"<<endl;
        cout<<"| 4. Keluar                      |"<<endl;
        cout<<" ================================ "<<endl;
        cout<<"| Masukkan pilihan [1..4] :  ";cin>>pil;//<<endl;
        
        system("cls"); 
                                
        if(pil==1)
        {
            cout<<" = Algoritma Bresenham ="<<endl;
            cout<<" ======================="<<endl<<endl;
                    
            cout<<"Diperlukan 2 titik untuk membuat sebuah garis :"<<endl<<endl;
                    
            cout<<"Titik A :"<<endl;
            cout<<"x => ";cin>>xa;
            cout<<"y => ";cin>>ya;
            cout<<endl<<endl;
                    
            cout<<"Titik B :"<<endl;
            cout<<"x => ";cin>>xb;
            cout<<"y => ";cin>>yb;
                    
            dx=xa-xb; dy=ya-yb;
            adx=abs(dx); ady=abs(dy);
            adx2=2*adx; ady2=2*ady;
            
            m=ady2-adx2;
            
            if(adx>ady)
                (stp=adx);
            else
                (stp=ady);
            
            float Dx[stp],Dy[stp],Dx2[stp],Dy2[stp],Pk[stp];//array
            Dx[0]=xa; Dy[0]=ya; 
            
            initwindow(400,300); //open a 400x300 graphics window
            
            cout<<endl<<endl;
            cout<<"m = "<<m<<endl;
            
            cout<<endl<<endl;
            cout<<"Pk, Xk , Yk"<<endl;
            cout<<"==========="<<endl<<endl;
            
            if(m<1)
            {
                Pk[1]=Po=ady2-adx;
                
                for(i=1;i<=stp;i++)
                {
                    Dx[i]=Dx[i-1]+1;                    
                    
                    if(Pk[i]<0)
                        {
                            Dy[i]=Dy[i-1];
                            Pk[i+1]=Pk[i]+ady2;
                        }
                    else
                        {
                            Dy[i]=Dy[i-1]+1;
                            Pk[i+1]=Pk[i]+m;
                        }
                                    
                    putpixel(Dx[i],Dy[i],3);
                    cout<<Pk[i]<<" , "<<Dx[i]<<" , "<<Dy[i]<<endl;                    
                    
                }
                
            }         
            else
            if(m>1)
            {
                Pk[1]=Po=ady2-ady;
                for(i=1;i<=stp;i++)
                {
                    Dy[i]=Dy[i-1]+1;                    
                    
                    if(Pk[i]<0)
                        {
                            Dx[i]=Dx[i-1];
                            Pk[i+1]=Pk[i]+ady2;
                        }
                    else
                        {
                            Dx[i]=Dx[i-1]+1;
                            Pk[i+1]=Pk[i]+m;
                        }
                                    
                    putpixel(Dx[i],Dy[i],3);
                    cout<<Dx[i]<<" , "<<Dy[i]<<endl;
                    
                }
                
            } 
            
            cout<<endl;
        }
        else
        if(pil==2)
        {
            cout<<" = Algoritma DDA ="<<endl;
            cout<<" ================="<<endl<<endl;
                    
            cout<<"Diperlukan 2 titik untuk membuat sebuah garis :"<<endl<<endl;
                    
            cout<<"Titik A :"<<endl;
            cout<<"x => ";cin>>xa;
            cout<<"y => ";cin>>ya;
            cout<<endl<<endl;
                    
            cout<<"Titik B :"<<endl;
            cout<<"x => ";cin>>xb;
            cout<<"y => ";cin>>yb;
                    
            dx=xa-xb; dy=ya-yb;
            adx=abs(dx); ady=abs(dy);
                    
            if(adx>ady)
                (stp=adx);
            else
                (stp=ady);
            
            
            float Dx[stp],Dy[stp],Dx2[stp],Dy2[stp];//array
            Dx[0]=xa; Dy[0]=ya;
                    
            xt=adx/stp; yt=ady/stp;   
            
            initwindow(400,300); //open a 400x300 graphics window
            
            cout<<endl<<endl;
            cout<<"Xk , Yk"<<endl;
            cout<<"======="<<endl<<endl;
                    
            for(i=1;i<=stp;i++)
            {
                Dx[i]=Dx[i-1]+xt;
                Dy[i]=Dy[i-1]+yt;                
                
                //pembulatan Dx
                a1 = modf (Dx[i],&a2);                
                if(a1>=0.5)
                    Dx2[i]=(int)Dx[i]+1;
                else
                    Dx2[i]=(int)Dx[i];
                
                //pembulatan Dy
                a1 = modf (Dy[i],&a2);                
                if(a1>=0.5)
                    Dy2[i]=(int)Dy[i]+1;
                else
                    Dy2[i]=(int)Dy[i];          
                                
                putpixel(Dx2[i],Dy2[i],3);
                cout<<Dx2[i]<<" , "<<Dy2[i]<<endl;
            }
            cout<<endl;            
            
        }
        else
        if(pil==3)
        {
            cout<<" ================================ "<<endl;
            cout<<"|       Anggota Kelompok         |"<<endl;
            cout<<" ================================ "<<endl;
            cout<<"| 1. Zumara   10108397           |"<<endl;
            cout<<"| 2. Ridzkin  10108394           |"<<endl;
            cout<<"| 3. Rifqi    10108402           |"<<endl;
            cout<<"| 4. Tri      10108403           |"<<endl;
            cout<<" ================================ "<<endl<<endl;
        }
        else
        if(pil==4)
        {
            cout<<endl<<endl;
            cout<<" ===== by zuma ====="<<endl<<endl;
        }
        else
        {
            cout<<endl<<endl;
            cout<<" Pilihan anda salah.. "<<endl;
            cout<<" Tekan Enter ! "<<endl<<endl;
            cout<<endl<<endl;
        }
        
        system("PAUSE");
        system("cls");
        closegraph();
    }
    while(pil!=4);
    
    return EXIT_SUCCESS;
}
