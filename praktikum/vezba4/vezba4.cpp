
#include <stdio.h>

void z1()
{
    int i, n, a; // Deklaracija promenljivih, i - brojac, n - broj brojeva, a - vrednosti brojeva
    printf("Unesite broj brojeva: "); // Unos broja brojeva za ispitivanje
    scanf("%d", &n); 

    for (i = 1; i <= n; i++) { // for petlja, ide od 1 do n sa korakom 1 
        printf("Unesite broj a: "); 
        scanf("%d", &a); // Broj za ispitivanje
        if (a % 2 == 1 && a <= 20) { // neparni brojevi u opsegu do 20 
            printf("Iteracija %d; Broj %d PRIPADA datom kriterijumu! \n", i, a); // stampanje broja iteracije i brojeve koji ispunjavaju uslove
        }
        else {
            printf("Iteracija %d; Broj %d NE PRIPADA datom kriterijumu \n", i, a); // stampanje broja iteracija i brojeva koji ne ispunjavaju uslove
        }
    }
}

void z2() {
    long sum = 0L; 
    int num; 
    printf("Unesite broj za sumiranje ili 0 za izlaz!\n");
    scanf("%d", &num); 
    while (num != 0) {
        sum = sum + num;
        printf("Unesite naredni broj za sabiranje ili 0 za izlaz! %d\n", num); 
        scanf("%d", &num); 
    }
    printf("Zbir unetih brojeva je %ld \n", sum); 

}


void z3() {
    int x; 
    printf("Unesite ulazni broj: "); 
    scanf("%d", &x); // Unos broja 
    
    while (x != 0) { // Petlja se prekida kada broj dostigne 0
        printf("%d", x % 10);
        x = x / 10;
    }
}

void z4() {
    int n, brojac=0;
    float suma = 0, x; 
    printf("Unesite broj brojeva: "); 
    scanf("%d", &n); 

    while (brojac < n) {
        printf("Unesite broj %d: ", brojac + 1); 
        scanf("%f", &x);
        suma += x; brojac += 1; 
    }
    printf("Srednja vrednost ovih brojeva je %.2f\n", suma / n); 
}

int main() {
    z1(); z2(); z3(); z4();
}