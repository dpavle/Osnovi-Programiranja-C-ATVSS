// vezba5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

void z1() { 
	// izracunavanje n! (faktorijel) primenom do while strukture 

	int i, fak; 
	long n; 
	i = 1; n = 1;
	printf("Izracunavanje n! \n Unesite broj: "); scanf("%d", &fak); 

	do { 
		// prva iteracija se izvrsava bez provere uslova 
		n *= i; 
		i++; 
	} while (i <= fak); 
	printf("%d! = %ld \n", fak, n); 
}

void z2() {
	char ch; 
	int a_ct, e_ct, i_ct, o_ct, u_ct, ostalo; 
	a_ct = e_ct = i_ct = o_ct = u_ct = ostalo = 0;
	printf("Unesi tvoje ime i prezime, # za izlaz. \n"); 
	while ((ch = getchar()) != '#') 
	{ 
		switch (ch) {
			case 'a': a_ct++; break;
			case 'A': a_ct++; break;
			case 'e': e_ct++; break;
			case 'E': e_ct++; break;
			case 'i': i_ct++; break;
			case 'I': i_ct++; break;
			case 'o': o_ct++; break;
			case 'O': o_ct++; break;
			case 'u': u_ct++; break;
			case 'U': u_ct++; break;
			default: ostalo++; break;
		}  // kraj switch
	}
	printf("Broj samoglasnika: A E I O U \n"); 
	printf("\t %4d %4d %4d %4d \n", a_ct, e_ct, i_ct, o_ct, u_ct); 
	printf("Broj suglasnika: %d \n ", ostalo); 
}

void z3() {
	int x1, x2, x3; 
	int a1, a2, a3; int b1, b2, b3; 
	int c1, c2, c3; int r1, r2, r3; 

	scanf("%d %d %d %d", &a1, &b1, &c1, &r1); 
	scanf("%d %d %d %d", &a2, &b2, &c2, &r2);
	scanf("%d %d %d %d", &a3, &b3, &c3, &r3);

	int d = a1 * b2 * c3 + a2 * b3 * c1 + a3 * b1 * c2 - c1 * b2 * a3 - c2 * b3 * a1 - c3 * b1 * a2; 
	int d1 = r1 * b2 * c3 + r2 * b3 * c1 + r3 * b1 * c2 - c1 * b2 * r3 - c2 * b3 * r1 - c3 * b1 * r2; 
	int d2 = a1 * r2 * c3 + a2 * r3 * c1 + a3 * r1 * c2 - c1 * r2 * a3 - c2 * r3 * a1 - c3 * r1 * a2; 
	int d3 = a1 * b2 * r3 + a2 * b3 * r1 + a3 * b1 * r2 - r1 * b2 * a3 - r2 * b3 * a1 - r3 * b1 * a2;


	x1 = d1 / d; x2 = d2 / d; x3 = d3 / d;

	printf("Determinante: %d %d %d %d", d, d1, d2, d3);
	printf("\n promenljive: %d %d %d \n", x1, x2, x3); 
}

void z4() { 
	// for petlja i do while petlja se mogu transformisati u while petlju

	int i = 1; int z = 0; 
	do { 
		z = z + i; 
		i++; 
	} 
	while (i <= 10);
	printf("%d \n", z);

	z = 0;
	for (i = 0; i <= 10; i++) { // isti izraz koristeci for petlju 
		z = z + i; 
	}
	printf("%d \n", z); 
}

void z5() {
	printf("\n 1 - Program matematika \n 2 - Program finansija \n 3 - Program zabave \n 4 - Exit \n");
	int sel;
	while ((sel = getchar()) != '4') {
		
		switch (sel) {
		case '1': printf("Program matematika");  continue;
		case '2': printf("Program finansija");  continue;
		case '3': printf("Program zabave");  continue;
		}
	printf("\n 1 - Program matematika \n 2 - Program finansija \n 3 - Program zabave \n 4 - Exit \n");
	}
}

void z6() {
	int n = 10; int i; int broj;
	for (i = 2; i < broj; i++); 
		if (broj % i == 0); 

}

int main() { 
	z5(); 
}
