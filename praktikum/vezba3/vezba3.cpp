#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void z1() { 
	/* logicki izraz kojim se proverava da li je uneti karakter 'c': 
	Malo slovo (Answer:  c >= ’a’ && c <= ’z’ )
	Veliko slovo(Answer:  c >= ’A’ && c <= ’Z’ )
	cifra (Answer:  c >= ’0’ && c <= ’9’ )
	beli znak (ukljucujuci blanko, tab i novi red) 
	(Answer:  c == ’\n’ || c== ’\t’ || c == ’’ ) */

	char c;
	scanf("%c", &c);

	if (c >= 'a' && c <= 'z') {
		printf("Malo slovo\n");
	}
	else if (c >= 'A' && c <= 'Z') {
		printf("Veliko slovo\n");
	}
	else if (c >= '0' && c <= '9') {
		printf("Cifra\n");
	}
	else if (c == '\n' || c == '\t' || c == ' ') {
		printf("Beli znak\n");
	}
}

void z2() { 
	/* generator slucajnog broja, 
	stampa jedan celobrojni slucajni broj i njegovu dvostruku vrednost. 
	takodje i jedan slucajan broj izmedju 0 i 9 i jedan izmedju 10 i 19. */

	int slucajan, dvostruki, x, y;
	srand(time(NULL)); // inicijalizacija generatora nasumicnih brojeva  

	slucajan = rand();
	dvostruki = slucajan * 2;
	x = rand() % 10; // slucajan izmedju 0 i 9
	y = rand() % 10 + 10; // slucajan izmedju 10 i 19

	printf("Slucajan broj je: %d\n", slucajan);
	printf("Dvostruki slucajan broj je: %d\n", dvostruki);
	printf("Jos neki slucajni brojevi: %d, %d \n", x, y); // slucajan 0-9 i 10-19 
}

void z3() { 
	int x, y, z; x = 10; y = 3; z = (x / y) * y;
	if (x == z) {
		printf("Vrednosti x i z su jednake. \n");
	}
	if (x <= z) {
		printf("Vrednost x je < ili = vrednosti z. \n");
	}
	if (x >= z) {
		printf("Vrednost x je > ili = vrednosti z. \n");
	}
	printf("Vrednost x je %d\n", x); 
	printf("Vrednost z je %d\n", z);
}


void z4() { 
	/* program za resavanje kvadratne jednacine x^2 + x -2 = 0,
	po jednacini x1,2 = -b + sqrt(b^2 - 4ac) / 2a */

	double a, b, c;
	double x1, x2, pom; 
	a = 1; b = 1; c = -2;
	pom = sqrt(b * b - 4 * a * c); // diskriminanta 

	if (pom < 0) { // resenja jednacine su kompleksna ako je diskriminanta (pom, b^2-4ac) < 0. 
		printf("Resenja kvadratne jednacine su kompleskna."); 
	}

	x1 = ((-b) + pom ) / 2 * a; 
	x2 = ((-b) - pom ) / 2 * a;

	printf("Vrednost prvog korena x1: %.2f \n", x1); 
	printf("Vrednost drugog korena x2: %.2f \n", x2); 
}

void z5() {
	/* program za resavanje proizvoljne kvadratne jednacine, 
	po jednacini x1,2 = -b + sqrt(b^2 - 4ac) / 2a */

	double a, b, c;
	double x1, x2, pom;
	printf("A = ");  scanf("%lf", &a); 
	printf("B = ");  scanf("%lf", &b); 
	printf("C = ");  scanf("%lf", &c);
	pom = sqrt(b * b - 4 * a * c); // diskriminanta 

	if (pom < 0) { // resenja jednacine su kompleksna ako je diskriminanta (pom, b^2-4ac) < 0. 
		printf("Resenja kvadratne jednacine su kompleskna.");
	}

	x1 = ((-b) + pom) / 2 * a;
	x2 = ((-b) - pom) / 2 * a;

	printf("Vrednost prvog korena x1: %f \n", x1);
	printf("Vrednost drugog korena x2: %f \n", x2);
}

void z6() {
	/* program za izracunavanje ukamacene vrednosti ako je 
	poznata kamatna stopa, period orocavanja u mesecima i iznos glavnice
	kamata se racuna kao glavnica * (1 + kamata/100)^period */ 

	double stopa, period, glavnica; 
	printf("Unesite mesecnu kamatnu stopu: "); scanf("%lf", &stopa); // ulaz u pokretnom zarezu 
	stopa = stopa / 100.0; // konverzija u procente 
	printf("Unesite glavnicu: "); scanf("%lf", &glavnica); 
	printf("Unesive vreme orocavanja u mesecima: "); scanf("%lf", &period); 
	
	printf("Ukamacena vrednost je %.2f\n", glavnica * pow( (1.0 + stopa), period) );
}

void z7() {
	/* program kojim se izracunava vrednost funkcije: 
		  x, x < 2
	y = { 2, 2 <= x < 3 
		  x-1, x>= 3	  */

	int x, y; 
	scanf("%d", &x); 

	if (x < 2) {
		y = x; }
	else if (x>= 2 && x < 3) {
		y = 2; }
	else if (x >= 3) {
		y = x - 1; }

	printf("Vrednost funkcije y = %d", y); 
}

void main() {
	z7();  
}