#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <unistd.h>
int main(){
  srand(time(NULL));
  // karakterler 0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f,g,h
  char karakterler[36]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h',
                        '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h'};
  char hafiza[6][6];
  char hafiza1[6][6];
  int i,j;
  int sayi;
  int satirhold,sutunhold;
  int skor=0;
  printf("\nSadece 1x1 den 6x6 ya kadar olan koordinatlari kullaniniz!\n");
  printf("Tablonun guncel hali icin veri girdikten sonra 1 saniye bekleyiniz.\n");
  for(i=0;i<6;i++){
      for(j=0;j<6;j++){
      hafiza[i][j]='*';
      }
  }
    for(i=0;i<6;i++){
      for(j=0;j<6;j++){
          printf("%c ",hafiza[i][j]);
      }
      printf("\n");
  } 
  for(i=0;i<6;i++){
      for(j=0;j<6;j++){
      sayi=rand()%36;
      while(karakterler[sayi]=='x'){
          sayi=rand()%36;
      }     
      hafiza1[i][j]=karakterler[sayi];
      karakterler[sayi]='x';
    }
  } 
  
    int satir,sutun;
    satir=2;
    while(satir>=1 && satir<=6){
  printf("Enter a coordinate: ");
    scanf("%d%d",&satir,&sutun);
    while(hafiza[satir-1][sutun-1]==' '){
      printf("Gecersiz Hamle Tekrar Seçiniz.");
        scanf("%d%d",&satir,&sutun);
    }
    printf("  1 2 3 4 5 6\n");
    hafiza[satir-1][sutun-1]=hafiza1[satir-1][sutun-1];
    for(i=0;i<6;i++){
      printf("%d ",i+1);
      for(j=0;j<6;j++){
          printf("%c ",hafiza[i][j]);
      }
      printf("\n");
    } 
    satirhold=satir;
    sutunhold=sutun;
    printf("Enter a coordinate: ");
    scanf("%d%d",&satir,&sutun);

  while(hafiza[satir-1][sutun-1]==' ' || hafiza[satir-1][sutun-1]==hafiza[satirhold-1][sutunhold-1]){
      printf("Gecersiz Hamle Tekrar Seçiniz.\n");
        scanf("%d%d",&satir,&sutun);
    }
    printf("  1 2 3 4 5 6\n");
      hafiza[satir-1][sutun-1]=hafiza1[satir-1][sutun-1];
    for(i=0;i<6;i++){
          printf("%d ",i+1);
      for(j=0;j<6;j++){
          printf("%c ",hafiza[i][j]);
      }
      printf("\n");
    } 
    printf("-------------\n");
    printf("  1 2 3 4 5 6\n");


    if(hafiza[satir-1][sutun-1]==hafiza[satirhold-1][sutunhold-1]){
    hafiza[satir-1][sutun-1]=' ';
    hafiza[satirhold-1][sutunhold-1]=' ';
    sleep(1);
    for(i=0;i<6;i++){
          printf("%d ",i+1);
      for(j=0;j<6;j++){
          printf("%c ",hafiza[i][j]);
      }
      printf("\n");
    } 
    printf("-------------\n");
    skor+=3;
    printf("Skor-->%d\n",skor);
    }
    else{
    hafiza[satir-1][sutun-1]='*';
    hafiza[satirhold-1][sutunhold-1]='*';
    sleep(1);
    for(i=0;i<6;i++){
      printf("%d ",i+1);
      for(j=0;j<6;j++){
          printf("%c ",hafiza[i][j]);
      }
      printf("\n");
    } 
    printf("-------------\n");
    skor-=1;
    printf("Skor-->%d\n",skor);
    }
  }
}