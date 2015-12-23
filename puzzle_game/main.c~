#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int tablo[4][4];
void tabloCiz();
void tabloYaz();
void kontrolYap(int sayi);
int oyunBitis();
int koseKontrol(int sayi);
int tasKontrol(int index);
int main()
{
    int secim=1;
    while(secim==1){
        tabloCiz();
        tabloYaz();
        int kontrol=1;
        int rakam;
        while(kontrol==1)
        {
            printf("\nLutfen hareket ettirmek istediginiz rakami seciniz...:");
            scanf("%d",&rakam);
            system("clear");
            int index=koseKontrol(rakam);
            if(tasKontrol(index)==1){
                kontrolYap(rakam);

                tabloYaz();
                if(oyunBitis()==1)
                {
                    tabloYaz();
                    printf("Tebrikler oyunu bitirdiniz.Tekrar oynamak ister misiniz(1/0)?");
                    scanf("%d",&secim);
                    break;
                }
            }
            else
            {
                printf("\n\n%d hareket edemez!\n\n",rakam);
            }
        }

    }
    system("PAUSE");
    return 0;
}
void tabloCiz()
{

    srand(time(NULL));
    int indis;
    int dizi[16]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int i,j,y_dizi[16],x=0;

    for(i=0;i<16;i++)
    {
            indis=rand()%16;
            if(dizi[indis]==0)
            {
               i--;
            }
            else
            {
                y_dizi[i]=dizi[indis];
                dizi[indis]=0;
            }
    }
    int temp;
    for(i=0;i<16;i++)
    {
        if(y_dizi[i]==16)
            {
                temp=y_dizi[i];
                y_dizi[i]=y_dizi[15];
                y_dizi[15]=temp;
            }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            tablo[i][j]=y_dizi[x];
            x++;
        }

    }
    tablo[3][3]=0;
}
void tabloYaz()
{
    int i,j;
    printf("\n<<Kayan Puzzle Oyunu>>\n\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(tablo[i][j]!=0)
                printf("%d\t",tablo[i][j]);
            else
                printf("muslım \t");
        }
        printf("\n");
    }
}
void kontrolYap(int sayi)
{
    int i, j;
    int temp1,temp2,tut1,tut2;
    for( i = 0; i < 4; i++ ) {
        for( j = 0; j < 4; j++ ) {
             if(tablo[i][j]==sayi)
             {
                     tut1=i;
                     tut2=j;
             }
             if(tablo[i][j]==0){
                    temp1=i;
                    temp2=j;
             }

        }

    }
   tablo[temp1][temp2]=sayi;
   tablo[tut1][tut2]=0;
}
int oyunBitis()
{

    if(tablo[0][0]==1&&tablo[0][1]==2&&tablo[0][2]==3&&tablo[0][3]==4
        &&tablo[1][0]==5&&tablo[1][1]==6&&tablo[1][2]==7&&tablo[1][3]==8
        &&tablo[2][0]==9&&tablo[2][1]==10&&tablo[2][2]==11&&tablo[2][3]==12
        &&tablo[3][0]==13&&tablo[3][1]==14&&tablo[3][2]==15&&tablo[3][3]==0 )
        {
            return 1;
        }
        return 0;
}
int koseKontrol(int sayi)
{
    int i, j;
    int sayac=0;
    for( i = 0; i < 4; i++ ) {
        for( j = 0; j < 4; j++ ) {
           if(tablo[i][j]!=sayi)
           {
              sayac++;
           }

           if(tablo[i][j]==sayi)
           {
              return sayac;
           }
        }

    }
}
int tasKontrol(int index)
{
    int i, j;
    int sayac=0;
    for( i = 0; i < 4; i++ ) {
        for( j = 0; j < 4; j++ )
        {
            	if(index==0)
            	{
                	if( tablo[0][1]==0||tablo[1][0]==0)
                    	{
                        	return 1;
                    	}
                	else
                    	{
                        	return 0;
                    	}
            	}
            	else  if(index==1)
            	{
                	if( tablo[0][0]==0|| tablo[0][2]==0|| tablo[1][1]==0)
                    	{
                        	return 1;
                    	}
                	else
                    	{
                        	return 0;
                    	}
            	}
            	else  if(index==2)
            	{
                	if( tablo[0][1]==0|| tablo[0][3]==0|| tablo[1][2]==0)
                    	{
                        	return 1;
                    	}
                	else
                    	{
                        	return 0;
                    	}
            	}
            	else  if(index==3)
            	{
                	if( tablo[0][2]==0|| tablo[1][3]==0)
                    	{
                        	return 1;
                    	}
                	else
                    	{
                       	 	return 0;
                    	}
            	}
            	else  if(index==4)
            	{
                	if(tablo[0][0]==0|| tablo[1][1]==0|| tablo[2][0]==0)
                    	{
                        	return 1;
                    	}
                	else
                    	{
                        	return 0;
                    	}
            	}
            	else  if(index==5)
            	{
                	if( tablo[1][0]==0|| tablo[0][1]==0|| tablo[1][2]==0|| tablo[2][1]==0)
                    	{
                        	return 1;
                    	}
                	else
                    	{
                        	return 0;
                    	}
            	}
            	else  if(index==6)
            	{
                	if( tablo[1][1]==0|| tablo[0][2]==0|| tablo[1][3]==0|| tablo[2][2]==0)
                    	{
                        	return 1;
                    	}
                	else
                    	{
                        	return 0;
                    	}
            	}
            	else  if(index==7)
            	{
                	if( tablo[0][3]==0|| tablo[1][2]==0|| tablo[2][3]==0)
                    	{
                        	return 1;
                    	}
                	else
                    	{
                        	return 0;
                   	 	}
            	}
            	else  if(index==8)
            	{
                	if( tablo[1][0]==0|| tablo[3][0]==0|| tablo[2][1]==0)
                    	{
                        	return 1;
                    	}
                	else
                    	{
                        	return 0;
                   	 	}
            	}
            	else  if(index==9)
            	{
                	if( tablo[2][0]==0|| tablo[2][2]==0|| tablo[1][1]==0 || tablo[3][1]==0)
                    	{
                        	return 1;
                    	}
                	else
                   	 	{
                    	    return 0;
                 	   	}
            	}
            	else  if(index==10)
            	{
                	if( tablo[2][1]==0|| tablo[2][3]==0|| tablo[1][2]==0 || tablo[3][2]==0)
                    	{
                        	return 1;
                    	}
                	else
                    	{
                        	return 0;
                 	   	}
            	}
            	else  if(index==11)
            	{
                	if( tablo[2][2]==0|| tablo[1][3]==0|| tablo[3][3]==0)
                    	{
                        	return 1;
                    	}
                	else
                    	{
                        	return 0;
                    	}
            	}
            	else  if(index==12)
            	{
                	if( tablo[2][0]==0|| tablo[3][1]==0)
                    	{
                        	return 1;
                    	}
                	else
                    	{
                        	return 0;
                    	}
           	 	}
            	else  if(index==13)
            	{
                	if( tablo[3][0]==0|| tablo[3][2]==0|| tablo[2][1]==0)
                	{
                    	return 1;
                	}
                	else
                	{
                    	return 0;
                	}
            	}
           	 	else  if(index==14)
            	{
                	if( tablo[3][1]==0|| tablo[2][2]==0|| tablo[3][3]==0)
                	{
                    	return 1;
                	}
                	else
                	{
                    	return 0;
                	}
           		}    
            	else if (index==15)
            	{
            		if (tablo[3][2]==0||tablo[2][3]==0)
            		{
            			return 1;
            		}
            		else
            		{
            			return 0;
            		}
            	
            	}    
            
        }
    }
    return 0;
}
