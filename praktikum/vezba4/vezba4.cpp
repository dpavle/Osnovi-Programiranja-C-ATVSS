
#include <stdio.h>
#include <math.h>

void z1() {
    /* program za prikaz neparnih brojeva manjih ili jednakih 20 */

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
    /* program za izracunavanje zbira celih brojeva upotrebom while petlje
    izracunavanje se prekida kada se unese '0' */

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
    /* program za permutovanje cifara celog broja koriscenjem while naredba
    (npr. 54321 u 12345) */

    int x; 
    printf("Unesite ulazni broj: "); 
    scanf("%d", &x); // Unos broja 
    
    while (x != 0) { // Petlja se prekida kada broj dostigne 0
        printf("%d", x % 10);
        x = x / 10;
    }
}

void z4() {
    /* program za odredjivanje srednje vrednosti n realnih pozitivnih brojeva
    pomocu while petlje */

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


void z7() {
    /* program koji cifre nekog proizvoljno unetog broja rotira za k pozicija u desno */

    int k, broj, brojac = 0, brojTemp, c;

    printf("Unesite 'k': "); scanf("%d", &k);
    printf("Unesite broj: "); scanf("%d", &broj);

    brojTemp = broj;

    while (brojTemp > 0) // izvlacenje ukupnog broja cifara broja 
    {
        brojac++;
        brojTemp = brojTemp / 10;
    }
    for (int i = 0; i < k % brojac; i++) // rotiranje cifara 
    {
        c = broj % 10;
        broj = broj / 10;
        broj = broj + c * pow(10, brojac - 1);
    }
    printf("%d", broj);
}


void z8() {
    int n, c, zk = 0; // zk - zbir kvadrata, c - cifra
    printf("Unesite broj 'n': "); scanf("%d", &n);

    while (n > 0) {
        c = n % 10; // izvlacenje cifara broja 
        zk = zk + (pow(c, 2)); // zbir kvadrata 
        n = n / 10;
    }
    printf("%d", zk);
}

int main() {
   z1(); z2(); z3(); z4(); z7(); z8();
}