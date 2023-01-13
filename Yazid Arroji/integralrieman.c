#include<stdio.h>
#include<conio.h>
#include<math.h>
// yazid Arroji
// 1908896
// code integral rieman
// Definisi Fungsi
#define f(x) 2*x + 3


int main()
{
 float bawah, atas, integrasi=0.0, langkah, k;
 int i, subInterval,x;

 printf("Masukan batasan bawah integrasi: ");
 scanf("%f", &bawah);
 printf("Masukan batasan atas integrasi: ");
 scanf("%f", &atas);
 printf("Masukan angka nilai sub interval: ");
 scanf("%d", &subInterval);

//rumus
 langkah = (atas - bawah)/subInterval;
 x =  bawah + langkah / 2;

//rumus
 integrasi = f(x);
 for(i=1; i<= subInterval-1; i++)
 {
 	x += langkah;
 	integrasi += ((i-1)*f(x));
 }
 integrasi = integrasi * langkah;
 //print hasil
 printf("\nNilai dari integrasi adalah: %.3f", integrasi);
 getch();
 return 0;
}