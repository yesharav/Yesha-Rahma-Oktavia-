#include <stdio.h>
// yazid Arroji
// 1908896
// code interpolasi

int main() {
    // deklarasi variable
    int inputan; 
    float x[inputan];
    float y[inputan];
    int i, j; 

    printf("Jumlah titik : "); 
    scanf("%d", &inputan); 
    // proses perulangan berdasarkan inputan
    for ( i = 0; i < inputan; i++) {
        printf("\nx[%d] y[%d] : ", i, i);
        scanf("%f", &x[i]);
        scanf("%f", &y[i]);
    }
    
    // save Data ke array
    float L[inputan];
    float Ly = 0;
    float Lx = 0;

    printf("\nTitik interpolasi : ");
    scanf("%f", &Lx);

    // rumus
    for ( i = 0; i < Lx; i++) {
        L[i] = 1;
        for ( j = 0; j < Lx; j++) {
            if(i != j) { L[i] *= (Lx - x[j])/(x[i] - x[j]); }
        }
        Ly += L[i] * y[i];
    }
    
    //Cetak Hasil
    printf("\np2(%.5f) : %.5f", Lx, Ly);
    return 0;
}