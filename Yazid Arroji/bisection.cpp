#include<stdio.h>
#include<conio.h>
#include<math.h>
// yazid Arroji
// 1908896
// code bisection

// fungsi perhitungan bisection
float bisection(float x){
    float d;
    d=pow(x,2)-(2*pow(x,1))-2;
    return d;
}
main(){
    float x1,x2,xr,error,tol;
    int i=1;
    printf(“ntttt” METODE BISECTIONn”);
    printf(” t t t t  METODE BAGI DUA ” n”);
    printf(“t=========================================================================nn”);

    printf(“tttt x^2-2x-2=0nn”);
    printf(“tMasukkan batas atas persamaan(x1)  : “);scanf(“%f”,&x1);
    printf(“tMasukkan batas bawah persamaan (x2): “);scanf(“%f”,&x2);
    printf(“tMasukkan nilai toleransi: “);scanf(“%f”,&tol);
    printf(“tTidak ada akar di antara kedua batas persamaann”);
    {
        printf(“n titx1 tx2 txr tf(x1) tf(x2) tf(xr) terror n”);
        do{
            xr=(x1+x2)/2;
            error=fabs(x2-x1)/fabs(x2);
            printf(“nt%dt%.3ft%.3ft%.3ft%.3ft%.3ft%.3ft%.3fn”,i,x1,x2,xr,bisection(x1),bisection(x2),bisection(xr),error);
            if(bisection(x1)*bisection(x2)<0)
                x2=xr;
            else
                x1=xr;
                i++;
        }
        while(tol<error);
        printf(“n tnilai xr terakhir : %.3fn”,xr);
        printf(“tBanyaknya iterasi : %d n”,i-1);
        printf(“ntttttttBy :”);
        printf(“nttttttt————“);
        printf(“ntttttttKelompok 1”);
    }
    getch();
    return 0;
}
