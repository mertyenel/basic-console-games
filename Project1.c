#include<stdio.h>
int main()
{
  // 1=Mavi 2=Kırmızı 3=Sarı
  int tup[5][4]={{1,2,3,3},
                 {1,2,1,2},
                 {3,1,2,3},
                 {0,0,0,0},
                 {0,0,0,0}};
 int i,j;  
 int hold; 
 int sayachold;  
 int hamle=0;
  for(i=0;i<5;i++){
    for(j=0;j<4;j++){
      printf("%d",tup[i][j]);
    }
    printf("\n");
  }
  printf("1 ile 5 numaralı tüplerden herhangi ikisini seçerek oyuna başlayabilirsiniz.Örneğin 1 4\nOyunu sonlandırmak için ilk tüp için -1 girin.\n");
  int sayi1,sayi2;
  sayi1=2;
  while(sayi1 != -1){
  int sayac1=0, sayac2=0;

  printf("Enter a move: ");
  scanf("%d%d",&sayi1, &sayi2);
for(i=0;i<4;i++){
  if(tup[sayi1-1][i]!=0){
    sayac1++;
  }
  }
for(i=0;i<4;i++){
  if(tup[sayi2-1][i]!=0){
    sayac2++;
  }
  }

  //printf("sayac1=%d sayac2=%d\n",sayac1,sayac2);
  if(sayac1 != 0 && sayac2<4){
    sayachold=sayac1;
   if(tup[sayi1-1][sayac1-1]==tup[sayi2-1][sayac2-1] || sayac2 == 0 ){
   hold=tup[sayi1-1][sayac1-1];
   for(i=0;i<sayac1;i++){
    if(tup[sayi1-1][sayac1-2-i]==hold){
      sayachold--;
    }
    else
    break;
   }
   if(sayachold==sayac1){
  tup[sayi2-1][sayac2] = tup[sayi1-1][sayac1-1];
  tup[sayi1-1][sayac1-1]=0;
  hamle++;
   } 
   else{
   
 // 3-2 1  2
  if(sayac1-sayachold+1<=4-sayac2){

    for(i=0;i<sayac1-sayachold+1;i++){
      tup[sayi2-1][sayac2+i] = tup[sayi1-1][sayac1-1-i];
     tup[sayi1-1][sayac1-1-i]=0;
    }
    hamle++;
  }
  else{
       printf("TEKRAR DENEYİNİZ\nGECERSİZ HAMLE\n");

  }
  
   }
   }
  else
   printf("TEKRAR DENEYİNİZ\nGECERSİZ HAMLE\n");
  printf("(1-Mavi,2-Kırmızı,3-Sarı)\n");
  printf("-----\n");
  }
  else
    printf("TEKRAR DENEYİNİZ\nGECERSİZ HAMLE\n");

 for(i=0;i<5;i++){
    for(j=0;j<4;j++){
      printf("%d",tup[i][j]);
    }
    printf("----->%d.Tüp",i+1);
    printf("\n");
    printf("-----\n");
  }

  printf("Hamle sayısı=%d\n",hamle);


  } 
}
