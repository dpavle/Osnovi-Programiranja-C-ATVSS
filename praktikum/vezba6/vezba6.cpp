#include <stdio.h>
#include <cmath>
#define IME "***REMOVED***" // "Visa tehnicka skola" 
#define ADRESA "***REMOVED***" // "Beogradska 20"
#define MESTO "18000 Nis"
// #define LIMIT 65

// void zvezde(); // deklaracija funkcije bez argumenata

void zvezde(int LIMIT); // deklaracija funkcije sa argumentom
int imin(int n, int m); 
int funkcija_y(int x1, int x2); 
float hipotenuza(); 
void promeni(int *xp, int *yp); 

int main() { 

	int broj1, broj2, vrati, rez; 
	float kat1, kat2, hip; 
	int x = 5; int y = 10; 

	zvezde(12); // poziv korisnicke funkcije 
	printf("%s \n", IME); // poziv funkcije iz st. biblioteke
	zvezde(8);
	printf("%s \n", ADRESA);
	printf("%s \n", MESTO);
	zvezde(20); 

	printf("\nUnesite 2 proizvoljna broja: \n"); vrati = scanf("%d %d", &broj1, &broj2); 
	rez = imin(broj1, broj2); 
	if (vrati == 2)
	{
		printf("Manji od %d i %d je %d \n", broj1, broj2, imin(broj1, broj2));
		printf("Manji od %d i %d je %d \n", broj1, broj2, rez);
	} 

	printf("y = %d \n", funkcija_y(broj1, broj2)); 

	printf("Unesi vrednost prve i druge katete: "); // scanf("%f %f", &kat1, &kat2); 
	hip = hipotenuza();
	printf("Hipotenuza je %4.2f\n", hip); 

	printf("U programu originalne vrednosti: x = %d, y = %d \n", x, y);
	promeni(&x, &y); 
	printf("U programu vrednosti nakon poziva funkcije: x = %d, y = %d \n", x, y); 
}

/* definicija korisnickih funkcija */

void zvezde(int LIMIT) { 
	/* funkcija za stampanje karaktera zvezde u jednoj liniji sve dok se ne dostigne LIMIT */
	int brojac;
	for (brojac = 1; brojac <= LIMIT; brojac++) 
		printf("%c", '*');  
	printf("\n");
} 

int imin(int n, int m) {
	/* funkcija trazi manji i vraca od dva broja */
	int min;
	if (n < m)
		min = n;
	else
		min = m;
	return min; 
}

int funkcija_y(int x1, int x2) {
	/* vraca vrednost funkcije y: 
	
	      x1+x2, x1 < x2
	y = { x1*x2, x1 = x2
		  x1-x2, x1 > x2  

	*/
	if (x1 < x2) {
		return x1 + x2;
	}
	else if (x1 == x2) {
		return x1 * x2;
	}
	else if (x1 > x2) {
		return x1 - x2;
	}
	else return 0; 
}

float hipotenuza() {
	/* funkcija za izracunavanje hipotenuze pravouglog trougla */

	float n, m; 
	scanf("%f %f", &n, &m);
	float rez = sqrt(n * n + m * m); 
	return rez; 
}

void promeni(int *xp, int *yp) {
	int temp;
	printf("U funk. originalne vrednosti su: u = %d, v = %d \n", *xp, *yp);
	temp = *xp; *xp = *yp; *yp = temp;
	printf("U funk. nakon promene vrednosti su: u = %d, v = %d \n", *xp, *yp);
} 