#include <stdio.h>
#define size 6

// yazid Arroji
// 1908896
// code eliminasi gaus jordan

// DEKLARASI VARIABEL
int i, j, k;

// FUNGSI ELIMINASI GAUSS JORDAN
void gaussJordan(double array[size][size], int ordo){
    double pembagi, v[size];

    printf("\t[Matriks A | B]\n");
    printMatrix(array, ordo);

    // perulangan seluruh matriks BERDASARKAN PARAMETER ordo
    for(i = 0; i < ordo; i++){
        pembagi = array[i][i];
        // perulangan tiap-tiap baris pada matriks BERDASARKAN PARAMETER ordo
        for(k = i; k < ordo + 1; k++){
            array[i][k] /= pembagi;
        }
        // cek secara vertikal selain x[i][i] bernilai 0
        for(j = i + 1; j < ordo + 1; j++){
            v[i] = array[j][i];
            for(k = i; k < ordo + 1; k++){
                array[j][k] = array[j][k] - v[i] * array[i][k];
            }
        }
    }
    for(i = 1; i < ordo; i++){
        for(j = 1; j < i + 1; j++){
            v[j] = array[j - 1][i];
            for(k = i; k < ordo + 1; k++){
                array[j - 1][k] -= v[j] * array[i][k];
            }
        }
    }
    printf("\n\t[Matriks Identitas]\n");
    printMatrix(array, ordo);
}

void printMatrix(double array[size][size], int ordo){
    for (i = 0; i < ordo; i++){
        printf("|");
        for (j = 0; j < ordo; j++){
            printf("%.3f   ", array[i][j]);
            if (j == ordo - 1){
                printf("\t|   %.3lf", array[i][j + 1]);
            }
        }
        printf("|\n");
    }
}


int main(){
    // deklarasi variable bersama tipe data
    double array[size][size];
    int ordo;
    printf("\n\nSOLUSI PERSAMAAN SISTEM LINEAR METODE GAUSS JORDAN\n");
    printf("\nPress any key to continue.\n");
    getchar();
    printf("\nMasukkan Ordo Matriks : ");
    scanf("%d", &ordo);
    // syarat inputan
    if(ordo < 2){
        printf("\nBentuk Matriks Minimal 2x2!");
        return 0; // program akan terhenti
    }
    printf("\n[ Terkonfirmasi Matriks Ordo %dx%d ]\n\n", ordo, ordo);
    for(i = 0; i < ordo; i++) {
        printf("Input Matriks Baris ke-%d\n", (i + 1));

        printf("Matriks A\n");
        for(j = 0; j < ordo; j++){
            printf("[%d][%d] = ", (i+1), (j+1));
            scanf("%lf", &array[i][j]);
            // kondisi (ordo - 1), maka input vektor B ke arrayay array[i][j+1]
            if(j == ordo - 1){
                printf("Matriks B\n");
                printf("[%d][%d] = ", (i+1), (j+1));
                scanf("%lf", &array[i][j + 1]);
            }
        }
        printf("\n");
    }

    // Panggil fungsi operasi Gauss Jordan
    gaussJordan(array, ordo);
    // menampilkan hasil
    for(i = 0; i < ordo; i++){
        printf("\nX%d = %.3lf", (i + 1), array[i][ordo]);
    }
    return 0;
}