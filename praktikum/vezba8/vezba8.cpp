
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


int main() { 
	const char msg[] = MSG1; 
	char x = ' ';
	printf("%c", x); 

	z1(); printf("\n"); 

	puts(msg); // zadatak 2

	z3(); printf("\n");

	z4(); printf("\n");
}
