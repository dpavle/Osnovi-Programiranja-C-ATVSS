#include <iostream>
#include <math.h> 

#define PI 3.14159265358979323846

// I kolokvijum

long float faktorijel(int x) {
	/* funkcija za izracunavanje faktorijela broja (X!) */

	int f = 1, i; 

	for (i = 1; i <= x; i++) {
		f = f * i;
	}
	return f; 
}

float povrsina_lopte(int r) {
	/* funkcija za izracunavanje povrsine lopte (P = 4 * pi * r^2) */
	float A; 

	A = 4 * PI * pow(r, 2);

	return A;
}


float zapremina_lopte(int r) {
	/* funkcija za izracunavanje zapremine lopte (V = 4/3 * pi * r^3) */
	float V; 

	V = (4 / 3.0) * PI * pow(r,3);

	return V;
}

int z1() {
	/* program za izracunavanje sume 
	S = SUM k -> N : X^K+1 / K!+N-N^2 */

	int N, s = 0, x;

	printf("N: "); scanf("%d", &N);
	printf("X: "); scanf("%d", &x);

	for (int K=10; K <= N; K++) {
		s += (pow(x, K+1)) / (faktorijel(K) + N - pow(N, 2));
	}
	return s;
}

void z2(int a, int b) {
	/* program koji izracunava vrednost f-je 
	
		{ e^2a+sin(b), a<b
	y = { cos^3(a*b), a=b
		{ sqrt(a-b^3), a>b

	*/

}

void z3() {
	/* program koji unetu cifru ispisuje morzeovom azbukom.*/

	char ch = getchar();
	switch (ch) {
		case '0': printf("-----"); break;
		case '1': printf(".----"); break;
		case '2': printf("..---"); break; 
		case '3': printf("...--"); break;
		case '4': printf("....-"); break; 
		case '5': printf("....."); break; 
		case '6': printf("-...."); break;
		case '7': printf("--..."); break;
		case '8': printf("---.."); break;
		case '9': printf("----."); break;
	}
}

void z4() {

}

int z5() {
	/* program koji racuna zbir n proizvoljno unetih celih brojeva 
	koriscenjem while petlje */
	
	int x, n, z = 0, br = 1;

	printf("Broj brojeva za unos: "); scanf("%d", &n);
	
	while (br<=n) {
		scanf("%d", &x);
		z += x;
		br++;
	}
	return z; 
}

// II kolokvijum 

void z6() {
	/* data je kvadratna matrica, kao izlaz iz programa 
	je predvidjeno stampanje ove matrice u pokaznom formatu kao i 
	stampanje nove matrice u istom obliku ali sada unazad od clana a44, a43, a42, a41, ... a11 */
	const int matrica[4][4]{ 
		{ 1, 2, 3, 4},
		{ 5, 6, 7, 8}, 
		{9, 10, 11, 12}, 
		{13, 14, 15, 16} 
	};

	printf("\nUlazni niz: \n");

	for (int i = 0; i < 4; i++) { // stampanje ulaznog niza 
		for (int j = 0; j < 4; j++) {
			printf("%d ", matrica[i][j]);
		}
		printf("\n");
	}
	
	printf("\nObrnuti izlazni niz: \n");

	for (int i = 3; i >= 0; i--) { // stampanje ulaznog niza u obrnutom obliku
		for (int j = 3; j >= 0; j--) {
			printf("%d ", matrica[i][j]);
		}
		printf("\n");
	}
}

void z7() {
/* program za izracunavanje sume S = SUM k -> N : X^(2*k) * cos(k*2) / k! + N! * 2 */ 
} 

void z8(const char *ulaz, const char *izlaz) {

	FILE* fp, *fpr;
	int br;

	fp = fopen(ulaz, "r"); fpr = fopen(izlaz, "w"); 

	while (!feof(fp)) { // program radi dok ne stigne do kraja ulaznog fajla
		fscanf(fp, "%d", &br);
		if (br % 3 == 0 && br % 7 == 0) { // ako je uneti broj deljiv sa 3 i 7, upisuje se u izlazni fajl
			printf("\n%d ", br);
			fprintf(fpr, "    %d\n", br); // upis u izlazni fajl
		}	
	}
}

void z9() {
	/* unosi se niz karaktera u vektor Niz 1.
	sadrzaj vektora Niz1 se kopira u vektor Niz2 i utvrdjuje da li je to isti niz. 
	broji koliko praznina (blanko karaktera) ima u nizu Niz1 */

	char Niz1[255], Niz2[255]; 
	int c = 0, b = 0; 

	char ch = getchar(); // unos prvog karaktera

	while (ch != '!') { // program radi dok se ne unese karakter '!'
		Niz1[c] = ch; c++; // rezultantni niz
		ch = getchar(); // unos sledeceg karaktera 
	}
	Niz1[c++] = '!'; // prepisivanje karaktera ! kojim je zavrsio unos  

	printf("Niz1: ");
	for (int i = 0; i < c; i++) { // stampanje prvog niza
		printf("%c", Niz1[i]);

		Niz2[i] = Niz1[i]; // kopiranje vrednosti Niza1 u Niz2 na istoj poziciji

		if (Niz1[i] == ' ') { // brojanje blanko karaktera
			b++;
		}
	}

	printf(" Niz2: ");
	for (int i = 0; i < c; i++) { // stampanje drugog niza
		printf("%c", Niz2[i]);
	}


	printf("\nDuzina niza 1 je: %d, blanko karaktera ima: %d", c, b);

	if (Niz1 == Niz2) { 
		printf("\nNizovi su isti.");
	}
	else {
		printf("\nNizovi nisu isti.");
	}
}

void z10() {
	/* u programu se unose podaci za N lopti i stampaju se vrednosti njihovih 
	povrsina i zapremina. povrsina i zapremina se racunaju pomocu zasebnih funkcija. */

	int n, r;
	float p, z;
	printf("Unesi N: "); scanf("%d", &n); // broj lopti 

	for (int i = 0; i < n; i++) {
		printf("Unesi r: "); scanf("%d", &r); // unos poluprecnika lopte
		printf("Povrsina: %f, Zapremina: %f", povrsina_lopte(r), zapremina_lopte(r));
	}
}


int main() {

	// printf("S = %d", z1());

	// printf("Unesi cifru (0-9): ");  z3();
	
	// printf("Zbir unetih brojeva: %d", z5());

	// printf("\n"); z6();

	//z8("ulaz.txt", "izlaz.txt");

	// z9();

	z10();

}
