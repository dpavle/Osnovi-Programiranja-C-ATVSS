#include <iostream>
#include <stdio.h>

void z1() {
    /* program koji stampa sadrzaj kvadratne matrice 5x5 vrstu po vrstu,
    a potom sporednu dijagonalu, sleva-udesno. matrica se formira
    generatorom slucajnih (nasumicnih) brojeva rand() */

    srand(time(NULL)); // rng 
    
    int a[5][5], n, i, j; // i - broj vrste, j - broj kolone 

    for (i = 0; i < 5; i++) { // alocira memoriju za n elemenata vrste koji su tipa int
        for (j = 0; j < 5; j++) {
            a[i][j] = rand() % 10; // popunjavanje matrice nasumicnim brojevima do 10 koriscenjem rand() f-je
        }
    }

    for (i = 0; i < 5; printf("\n"), i++) { // stampanje sadrzaja matrice 5*5
        for (j = 0; j < 5; j++) {
            printf(" %d", a[i][j]); 
        }
    }
    printf("\n"); 

    for (i = 4; i >= 0; i--) { // stampanje sporedne dijagonale, sleva-udesno
        printf(" %d", *(*(a + i) + 5 - 1 - i)); // ? 
        printf("\n"); 
    }
}


void z2() {
    /* program koji stampa datu matricu i novu matricu u istom obliku 
    ali sada unazad, od clana a44, a43, a42, a41, ... a11 */

    int m[4][4] = { 
        /* deklaracija i inicijalizacija ulazne matrice*/
                    { 1, 2, 3, 4 },
                    { 5, 6, 7, 8 },
                    { 9, 10, 11, 12 },
                    { 13, 14, 15, 16 }
    }; 
    int n = 4, i, j;
    printf("Ulazni niz: \n");
    for (i = 0; i < n; i++) { // stampanje matrice 
        for (j = 0; j < n; j++) {
            printf("%2d ", m[i][j]);
        }
        printf("\n"); 
    }

    printf("\nObrnuti izlazni niz: \n" ); 

    for (i = 3; i >= 0; i--) { // stampanje matrice unazad 
        for (j = 3; j >= 0; j--) {
            printf("%2d ", m[i][j]); 
        }
        printf("\n"); 
    }
}

void z3() {
    /* program koji izracunava sumu svih elemenata u svakom 
    redu pojedinacno, pravougaone matrice [4x4] */

    int mat[4][4] = {
        /* deklaracija i inicijalizacija polazne matrice */
        { 1, 2, 3, 4},
        { 5, 6, 7, 8},
        { 9, 10, 11, 12},
        { 13, 14, 15, 16} 
    };

    int i, j, s = 0; 
    
    printf("\nPolazna matrica je: \n"); 

    for (i = 0; i < 4; i++) { // stampanje matrice 
        for (j = 0; j < 4; j++) {
            printf("%2d ", mat[i][j]);
        }
        printf("\n"); 
    }

    printf("\n");

    for (i = 0; i < 4; i++) { 
        s = 0; 
        for (j = 0; j < 4; j++) {
            s = s + mat[i][j]; // suma elemenata u redu
            }
        printf("Suma elemenata u %d redu: %d \n", i+1, s); 
    }
}

void z4() {
    /* program koji racuna sumu elemenata na glavnoj dijagonali
    matrica dimenzija 5x5 */

    int m[5][5], i, j, s;  

    srand(time(NULL)); // rng

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            m[i][j] = rand() % 10; // popunjavanje 5x5 matrice nasumicnim brojevima do 10
        }
    }

    s = 0; 
    for (i = 0; i < 5; i++) {

        s += m[i][i]; // suma elemenata na glavnoj dijagonali 

        for (j = 0; j < 5; j++) {
            printf("%2d ", m[i][j]); // stampanje matrice 
        }
        printf("\n"); 
    }
    printf("Suma elemenata na glavnoj dijagonali: %d", s); 
}

void z5() {
    /* program koji racuna broj elemenata matrice vecih od 10 
    svi elementi matrice se smestaju u novi niz i racuna se njihov zbir */
    
    int matrica[3][3], i, j, k, s; // k - brojac, s - zbir 
    int veci_od_10[9];

    srand(time(NULL)); // rng 

    for (i = 0; i < 3; i++) { 
        for (j = 0; j < 3; j++) {
            matrica[i][j] = rand() % 20; // popunjavanje matrice nasumicnim brojevima do 20 
        }
    }
    k = 0; s = 0; 
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%2d ", matrica[i][j]); // stampanje matrice 
            
            if (matrica[i][j] > 10) { 
                veci_od_10[k] = matrica[i][j]; // elementi matrice veci od 10 se smestaju u novi niz
                k++; 
            }
        }
        printf("\n"); 
    }

    printf("Elementi matrice veci od 10: \n");
    for (i = 0; i < k; i++) {
        printf("%d ", veci_od_10[i]); // stampanje niza elemenata vecih od 10 
        s += veci_od_10[i]; // zbir elemenata u nizu elemanata matrice vecih od 10 
    }
    printf("\nZbir elemenata matrice vecih od 10: %d", s); 
}


void z6() {

    int m1[3][3], m2[3][3], i, j; 

    srand(time(NULL)); // rng 

    for (i = 0; i < 3; i++) { // popunjavanje obe matrice nasumicnim brojevima do 10
        for (j = 0; j < 3; j++) { 
            m1[i][j] = rand() % 10; 
            m2[i][j] = rand() % 10;
        }
    }

    printf("Matrica 1:\n"); 
    for (i = 0; i < 3; i++) { // stampanje druge matrice 
        for (j = 0; j < 3; j++) {
            printf("%2d ", m1[i][j]);
        }
        printf("\n"); 
    }

    printf("Matrica 2:\n"); 
    for (i = 0; i < 3; i++) { // stampanje prve matrice 
        for (j = 0; j < 3; j++) {
            printf("%2d ", m2[i][j]); 
        }
        printf("\n");
    }

    printf("Matrica 1+2:\n"); 
    for (i = 0; i < 3; i++) { // stampanje zbira prve i druge matrice 
        for (j = 0; j < 3; j++) {
            printf("%2d ", (m2[i][j] + m1[i][j])); 
        }
        printf("\n");
    }
}

void print_matrix(int n, int m[5][5]) {
    /* funkcija za stampanje kvadratne matrice */
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%2d ", m[i][j]);
        }
        printf("\n");
    }
}

void z7() {
    int matrica[5][5], i, j, n, p;

    srand(time(NULL)); // rng
    
    printf("Unesite dimenziju matrice (max 5): "); scanf_s("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrica[i][j] = rand() % 50; // popunjavanje matrice nasumicnim brojevima do 50 
        }
    }

    print_matrix(n, matrica); printf("\n"); 

    for (i = 0; i < n; i++) {
        for (j = n-1; j >= 0; j--) {
            if (i + j == n-1) { // uslov za sporednu dijagonalu
                for (int k = i; k >= 0; k--) { // zamena mesta clanovima na spor. dijagonali, rastuci redosled
                    if (matrica[i][j] > matrica[k][n - k - 1]) {
                        p = matrica[i][j];
                        matrica[i][j] = matrica[k][n - k - 1];
                        matrica[k][n - k - 1] = p;
                    }
                }
            }
            else {
                matrica[i][j] = 1; // svi ostali clanovi matrice se zamenjuju jedinicom 
            }
        }
    }
    print_matrix(n, matrica);
}

int main()
{
    z1(); z2(); z3(); z4(); z5(); z6(); z7();
}
