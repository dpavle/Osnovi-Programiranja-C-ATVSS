#include <iostream>
#include <stdlib.h>

#define PI 3.14

int povrsina_zapremina_valjak(double r, int H, int pz) {
	/* funkcija koja racuna povrsinu i zapreminu valjka 
	selekcija se vrsi pomocu promenljive pz:
	pz = 1 --> funkcija vraca povrsinu 
	pz = 2 --> funkcija vraca zapreminu */

	int A, V;

	A = 2 * PI * (r * r) + 2 * PI * r * H;

	V = H * PI * (r * r);

	if (pz == 1) {
		return A; 
	}
	else if (pz == 2) {
		return V;
	}
}


void z2() {
	/* program koji slucajno bira cele brojeve iz intervala 0-2000,
	prikazuje izabran broj i prekida biranje kada je
	izabran broj 500, kada je birano vise od 20 puta ili je
	odabran broj cija je cifra stotina 3.
	prikazuje se i broj odabranih jednocifrenih brojeva. */

	bool izabran = false;
	int broj, BB = 1, csb; // BB - broj biranih brojeva, csb = cifra stotina broja

	srand(time(NULL)); // rng 

	while (izabran == false) {

		broj = rand() % 2000; // rand() bira ceo broj iz intervala 0-2000
		BB++; csb = (broj / 100) % 10;

		if (broj == 500 || BB > 20 || csb == 3) {
			printf("Izabran broj: %d\n", broj);
			izabran = true;
		}
	}
	printf("Broj biranih brojeva = %d\n", BB);
}

void z3() {
	/* program koji za razlicito uneto n stampa na standardni izlaz celu piramidu */
	int n;

	printf("Unesite N: "); scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) { 
			printf(" "); 
		}
		for (int k = 1; k <= (2 * i - 1); k++) {
			printf("*");
		}
		printf("\n");
	}
}

void z4() {
	/* program stampa zapremine N valjka kao realni broj sa dve decimale */

	int N, r, H;

	printf("Unesi N: "); scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		printf("Unesi r i H: "); scanf("%d %d", &r, &H);

		printf("V = %.2d\n", povrsina_zapremina_valjak(r, H, 2));
	}
}

int main() {

	z2();

	z3(); 

	z4();
}