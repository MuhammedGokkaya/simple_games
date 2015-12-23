#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <termios.h>
#include <unistd.h>
int getch(void);
int getche(void);
char *dizi;
char *gemi;
int *hile;
int sorgu=0;
void haritaCiz(int n);
void haritaYaz(int n);
int gemiYap(int n);
void gemiKontrol(int n);
int main()
{
    int g_dik,dik,g_yatay,yatay,sayac=0,x,y,boyut;
    char ch2,ch;
    printf("\n>>>>>>>>AMIRAL BATTI<<<<<<<<<\n\n");
    while(1){
        printf("_____________________________\n\nHARITA GENISLIGI GIRINIZ:");
        scanf("%d",&boyut);
        if(boyut<4||boyut>15)
        {
            printf("Bu boyutta HARITA çizilmez!!!\n");
        }
        else
            break;
    }
    haritaCiz(boyut);
    gemiYap(boyut);
    haritaYaz(boyut);
   // gemiKontrol(boyut);

    printf("\n© MUHAMMED GOKKAYA v.1.1\n");
    printf("\n__________________________\n");
    for(;;)
    {
       getch();
        printf("dikey...:\t");
        g_dik=getch();
        ch = (char)g_dik;
        dik = ch -'0';
        printf("yatay...:\t");
        g_yatay=getch();
        ch2 =(char)g_yatay;
        yatay =ch2-'0';
        sorgu++;
       // gemiKontrol(boyut);
        /*char kordinat1;
        kordinat1 = getch();
        int dik = kordinat1+'0';
        char kordinat2;
        kordinat2 = getch();
        int dik= kordinat2+'0';*/
        /*printf("SATIR KOORDINATI GIR(0-14):");
        scanf("%d",&dik);
        printf("SUTUN KOORDINATI GIR(0-14):");
        scanf("%d",&yatay);*/
       /* g_dik=getch();
        ch = (char)g_dik;
        dik = ch -'0';
        g_yatay=getch();
        ch2 =(char)g_yatay;
        yatay =ch2-'0';*/
        if(yatay==2015&&dik==2015)
        {
            for(x=0;x<boyut;x++)
            {
                for(y=0;y<boyut;y++)
                    {
                        if(*(gemi+(boyut*x)+y)=='x')
                            *(dizi+(boyut*x)+y)='x';
                    }
            }
            for(x=0;x<boyut;x++)
            {
                for(y=0;y<boyut;y++)
                    {
                        printf("%c ",*(dizi+(boyut*x)+y));
                    }
                    printf("\n");
            }
            sorgu--;
            break;
            }
        else if(*(gemi+(boyut*dik)+yatay)=='x')
        {
            printf("DOGRU SECIM\n");
            *(dizi+(boyut*dik)+yatay)='x';
            gemiYap(boyut);
            haritaYaz(boyut);
            sayac++;
            if(sayac==10)
            {
                break;
            }
        }    
        else if(*(dizi+(boyut*dik)+yatay)=='*')
        {
            printf("AYNI YER VURULMAZ REIZZ\n");
        }    
        
        else
           {
            printf("YANLIS SECIM!!\n");
            *(dizi+(boyut*dik)+yatay)='*';
            gemiYap(boyut);
            haritaYaz(boyut);                        
           }
        }
}
void haritaCiz(int n)
{
    int i,j;
    gemi=(char *)malloc(sizeof(char)*n*n);
    hile=(int *)malloc(sizeof(int)*n*n);
    dizi=(char *)malloc(sizeof(char)*n*n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            *(dizi+(n*i)+j) = '_';
        }
    }
}
void haritaYaz(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%c ",*(dizi+(n*i)+j));
    printf("\n");
    }
}
int gemiYap(int n)
{
    srand(time(NULL));
    int i,j,g_sayi,x,y,koordinat;
    for(g_sayi=0;g_sayi<4;g_sayi++)
    {
        x=rand()%n,y=rand()%n,koordinat=rand()%2;
        if(koordinat==0){
            if(x>n-3){
                x-=g_sayi;
                for(i=x;i<=x+g_sayi;i++)
                    {
                        for(j=y;j<=y;j++)
                        {
                            if(*(dizi + (n*i)+j) == 'x'){
                             }
                            else
                            {
                                *(gemi + (n*i)+j) = 'x';
                            
                            }
                        }
                    }
            }
            else{
                for(i=x;i<=x+g_sayi;i++)
                    {
                        for(j=y;j<=y;j++)
                        {
                            if(*(dizi + (n*i)+j) =='x'){
                                
                            }
                            else
                            {
                                *(gemi + (n*i)+j) = 'x';
                                
                            }
                        }
                    }
            }
        }
        else{
            if(y>n-3){
                y-=g_sayi;
                for(i=x;i<=x;i++)
                    {
                        for(j=y;j<=y+g_sayi;j++)
                        {
                            if(*(dizi + (n*i)+j) =='x'){
                                
                            }
                            else
                            {
                                *(gemi + (n*i)+j) = 'x';
                                
                            }
                        }
                    }
            }
            else{
                for(i=x;i<=x;i++)
                    {
                        for(j=y;j<=y+g_sayi;j++)
                        {
                            if(*(dizi + (n*i)+j) =='x'){
                                
                            }
                            else
                            {
                                *(gemi + (n*i)+j) = 'x';
                            }
                        }
                    }
        }
    }
    
}}
void gemiKontrol(int n){
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%c",*(gemi+(n*i)+j));
        }
        printf("\n");
    }
}
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
int getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}






