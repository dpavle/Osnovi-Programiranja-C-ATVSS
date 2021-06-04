
#include <iostream>
#include <stdio.h>
#include "vezba8.h"

#define MSG1 "Ja sam student prve godine" 

void z1() {
	/* program za ispisivanje tablice ASCII kodova za sve znakove od 32 do 126 
	u jednoj koloni se prikazuje po 19 znakova, a u jednom redu po 5 (5x19=95) */

	char c = ' '; int i; 
	printf("Tablica ASCII kodova \n \n"); 
	for (i = 0; i < 95; i++) { // prikazuju se ASCII kodovi od 32 do 126, od 32 do 126 ima 94 karaktera (for loop krece od nule) 
		printf("%3d %c	", c + i, c + i); // c u int obliku (kako ga vidi formatter %d) je 32 
		if (i % 19 == 0) // prelazak na novu liniju kada 'i' stigne do 19 ; stampanje 19 karaktera po liniji ; 19%19=0 
			printf("\n"); 
	}
}

void z3() {
	/* program za unos i stampanje karaktera
	program ucitava i broji karaktere sa ulaza sve dok
	se ne otkuca znak za kraj unosa EOF (CTRL-Z) */

	char ch; int br = 0; // br - broj unetih karaktera
	while ((ch = getchar()) != EOF) { // getchar() - unos karaktera, EOF = CTRL-Z
		br++;
		printf("\n %c", ch);
	}
	printf("Uneto je %d karaktera", br-1);
}

void z4() {
	/* program koji iz skupa unetih karaktera izracunava broj 
	unetih slova, brojeva i ostalih karaktera.
	tekst se unosi sa tastature a program se prekida pritiskom na ctrl+z, a zatim enter.*/

	char rec; int slova = 0; int brojevi = 0; int ostalo = 0;
	while ((rec = getchar()) != EOF) { // getchar() - unos karaktera, EOF = CTRL-Z
		if (rec >= 65 && rec <= 122) { // A-z po ASCII tablici 
			slova++; }
		else if (rec >= 48 && rec <= 57) { // 0-9 po ASCII tablici 
			brojevi++; }
		else { // ostali karakteri 
			ostalo++; }
	}
	printf("Slova ima - %d, Brojeva ima - %d, ostalih karaktera ima - %d", slova, brojevi, ostalo-1);
}

void z5() {
	/* program koji konvertuje velika u mala slova u recenici 
	recenica se unosi sa tastature a program se prekida unosenjem
	karaktera '%' */

	char s, brojac = 0; char recenica[255];
	printf("Unesi recenicu: "); s = getchar(); // unos 

	while ((s != '%')) { // program radi dok se ne unese karakter '%'
		if ((s >= 'A') && (s <= 'Z')) {
			s = s + 32; // 65 (A) + 32 = 97 (a)
		}
		recenica[brojac++] = s; // rezultat
		s = getchar(); // unos sledeceg karaktera
	}

	for (int i = 0; i < brojac; i++) {
		printf("%c", recenica[i]); // ispis rezultata
	}
}


void z6() {
	/* program koji ucitava dva znakovna niza, cije se duzine unose kao podatak
	sa tastature, izvrsi nadovezivanje drugog na prvi, okrene 'naopako' dobijeni niz
	i ispise ga na standardnom izlaznom uredjaju */

	char niz1[200], niz2[200], Rniz[200];
	int n1, n2, Rn, brojac = 0, i;

	printf("Unesi duzinu prvog niza: "); scanf("%d", &n1);
	printf("Unesi duzinu drugog niza: "); scanf("%d", &n2);

	Rn = n1 + n2;

	printf("Unesi prvi niz: ");
	for (i = 0; i < n1; i++) {
		scanf("%s", &niz1[i]);
	}

	printf("Unesi drugi niz: ");
	for (i = 0; i < n1; i++) {
		scanf("%s", &niz2[i]);
	}

	for (int i = 0; i < n1; i++) { // dodavanje prvog niza na novi zajednicki niz
		Rniz[brojac++] = niz1[i];
	}

	for (int i = 0; i < n2; i++) { // dodavanje drugog niza na novi zajednicki niz 
		Rniz[brojac++] = niz2[i];
	}
	

	for (int i = 0; i < brojac; i++) { // ispis 'naopakog' niza
		printf("%c", Rniz[brojac - 1 - i]);
	}
}


int main() { 
	const char msg[] = MSG1; 
	char x = ' ';
	printf("%c", x); 

	z1(); printf("\n"); 

	puts(msg); printf("\n"); // zadatak 2
	
	z3(); printf("\n"); z4(); printf("\n"); z5(); printf("\n");

	z6();
}
