#include <iostream>
#define VELIC 10
#define VELICINA 5 

void swap(int* a, int* b); 
long sump(int* pok, int vel); 
void prikaz_niza(double niz[], int n);
void uvecaj_niz(double broj, double* pok); 

void z1() {
	/* program za unos i izracunavanje zbira clanova niza sa 5 elemenata */

	float broj[5]; // deklaracija niza
	double rez = 0; int i; // pomocne promenljive

	for (i = 0; i < 5; i++) { // unos podataka i smestanje istih u broj[]
		printf("Unesite broj %d: ", i + 1); scanf("%f", &broj[i]); 
	}
	for (i = 4; i + 1; i--) { // sabiranje svih clanove niza 
		rez += broj[i]; 
	}
	printf("Zbir unesenih brojeva je %.2lf \n", rez); // prikaz rezultata sabiranja
}

void z2() {
	/* program koji odredjuje redni broj maksimalnog elementa u 
	celobrojnom nizu X od N elemenata */

	const int n = 5; int x[n]; int i; int max; int max_broj;
	for (i = 0; i < n; i++) { // unos niza 
		printf("Unesi %d. clan niza: ", i + 1); scanf("%d", &x[i]); 
	}

	max = x[0];
	for (i = 1; i < n; i++) {
		if (x[i] > max) {
			max = x[i]; // vrednost max. elementa
			max_broj = i + 1; // redni broj max. elementa 
		}
	}
printf("Redni broj max. elementa u nizu je %d. ", max_broj); 
}

void z4() {
	/* program za stampanje niza i ~~mnozenje~~ sabiranje elemenata niza
	konstantnom vrednoscu */

	double dip[VELICINA] = { 20.0, 17.66, 8.2, 15.3, 22.22 }; 
	int i; // const int mnozi = 5; 
	int sabirak; scanf("%d", &sabirak); 

	for (i = 0; i < VELICINA; i++) {
		// dip[i] *= mnozi;  // svaki element se mnozi vrednoscu 'mnozi' 
		dip[i] += sabirak;  // na svaki element se dodaje vrednost 'sabirak' 
	}
	printf("\n dip * 5 = "); 
	for (i = 0; i < VELICINA; i++) { // stampanje (prikaz) niza 
		printf("%8.3f", dip[i]);
	} 
	printf("\n"); 
}


void z6() {
	int niz0[1000]; int niz1[1000]; // niz1 skladisti elemente koji se ne ponavljaju u nizu0 
	int i, j, n, b, br = 0; 
	printf("Unesi n: "); scanf("%d", &n); // broj clanova niza 

	for (i = 0; i < n; i++) {
		printf("Unesi %d clan niza: ", i + 1); scanf_s("%d", &niz0[i]); // unos niza
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) { 
			/* (primer za niz sa 3 elementa)
				 i = 0, j = 1
				 i = 0, j = 2
				 i = 1, j = 0
				 i = 1, j = 1
				 i = 1, j = 2
				 i = 2, j = 0
				 i = 2, j = 1
				 i = 2, j = 2	
			  sve kombinacije elemenata niza se uporedjuju 
			*/ 
			if (i != j && niz0[i] == niz0[j]) {
				b = 1; } // ako su dva elementa na razlicitim pozicijama ista, vrednost b postaje 1, sto ponistava sledeci uslov 
		} 
		if (b == 0) {
			niz1[br] = niz0[i]; br++; } // ako je vrednost b ostala 0, element se pojavljuje samo jednom u nizu, isti se dodaje se u novi niz niz1  
		b = 0;
	} 
	printf("Ima %d elemenata koji se pojavljuju samo jednom, i to su: ", br); 
	for (i = 0; i < br; i++) {
		printf("%d, ", niz1[i]);
	}
}

void z7() {
	int A[5]; int B[5]; int C[5];  int i; int br = 0; 
	printf("Unos niza A[5]\n"); 
	for (i = 0; i < 5; i++) {
		printf("Unesi %d clan niza: ", i + 1); scanf("%d", &A[i]); 
	}
	printf("Unos niza B[5]\n");
	for (i = 0; i < 5; i++) {
		printf("Unesi %d clan niza: ", i + 1); scanf("%d", &B[i]);
	}
	for (i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) { // sve kombinacije elemenata A i B se uporedjuju 
			if (A[i] == B[j]) {
				C[br] = A[i]; br++; } // ako su dva elementa iz skupova A i B ista, njihova vrednost se dodaje u novi skup C 
		} 
	}
	printf("Zajednicki elementi A i B su: ");
	for (i = 0; i < br; i++) {
		printf("%d, ", C[i]); 
	}
}


void swap(int* a, int* b) { // zadatak 5 1/2
	/* funkcija vrsi zamenu vrednosti dve promenljive 
	i smesta ih u dve memorijske lokacije */
	int temp; 
	temp = *a; 
	*a = *b; 
	*b = temp; 
}


long sump(int* ar, int n) { // zadatak 3 1/2
	/* funkcija za sabiranje clanova niza, koristi pokazivacku aritmetiku */ 

	int i;
	long ukupno = 0;
	for (i = 0; i < n; i++) {
		ukupno += *ar; // dodaje vrednost elementa niza na koji trenutno ukazuje pokazivac na ukupno 
		ar++; // pomera pokazivac na sledeci element 
	}
	return ukupno;
}

void uvecaj_niz(double broj, double* pok) { // zadatak 4.2 1/3
	/* funkcija za mnozenje svakog elementa niza nekim brojem, 
	koristi pokazivacku aritmetiku */

	int i; 
	for (i = 0; i < VELICINA; i++) {
		*pok = *pok * broj; // element niza na koji ukazuje pokazivac se mnozi vrednoscu 'broj' 
		pok++; // pomera pokazivac na sledeci element
	}
}

void prikaz_niza(double niz[], int n) { // zadatak 4.2 2/3 
	/* funkcija za prikaz (stampanje) niza */

	int i;
	for (i = 0; i < n; i++) {
		printf("%8.3f", niz[i]);
	}
}

void main() {

	int i, j, n;
	static int niz[VELIC] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
	double niz2[VELICINA] = { 20.0, 17.66, 8.2, 15.3, 22.22 };
	int ar[10] = { 7, 3, 9, 2 , 11, 20, 17, 19, 6, 4 };
	long odgovor;

	// z1();

	z7(); 
	// z6(); 

	/* zadatak 1.2 */
	char niz0[4] = { 'a', 'a', 'a', 'a' };

	niz0[0] = 'a';
	niz0[1] = 'a';
	niz0[2] = 'a';
	niz0[3] = 'a';

	printf("\n");

	for (i = 0; i < 4; i++) {
		printf("%c, ", niz0[i]);
	}

	printf("\n");

	// z2(); 

	/* zadatak 3 2/2 */

	printf("Niz = ");
	for (i = 0; i < VELIC; i++) {
		printf("%4d", niz[i]);
	}
	odgovor = sump(niz, VELIC);
	printf("\nSuma niza je: %ld.\n", odgovor);

	// z4(); 

	/* zadatak 4.2 3/3*/

	printf("Niz2 = "); prikaz_niza(niz2, VELICINA);
	uvecaj_niz(5, niz2); printf("\n");
	printf("Niz2 * 5 = "); prikaz_niza(niz2, VELICINA);

	/* zadatak 5 2/2*/ printf("\n"); 

	printf("\nVektor pre sortiranja:\n");
	for (i = 0; i < 10; i++) {
		printf("ar[%d]=%d\n", i, ar[i]);
	}

	n = 10;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1; j++) {
			if (ar[j] > ar[j + 1]) { // bubble sort
				swap(&ar[j], &ar[j + 1]); 
			}
		}
	}
	printf("Vektor posle sortiranja:\n");
	for (i = 0; i < 10; i++) {
		printf("ar[%d] = %d\n", i, ar[i]);
	}
} 