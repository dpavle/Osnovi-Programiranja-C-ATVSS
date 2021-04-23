#include <stdio.h>

void z1() {
	unsigned neoznacen = -39000;
	printf("Neoznacen = %u i nije %d\n", neoznacen, neoznacen);
	printf("Characters: %c %c\n", 'a', 65); // Broj '65' predstavlja karakter 'A' u ASCII tabeli karaktera. 
	printf("Decimals: %d %ld\n", 1977, 650000L);
	printf("Preceding with blanks: %10d\n", 1977);
	printf("Preceding with zeroes: %010d\n", 1977);
	printf("Some different: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	printf("floats: %4.2f %+.0e %E\n", 3.1416, 3.1416, 3.1416);
	printf("Width trick: %*d\n", 5, 10);
	printf("%s \n", "A string");
}

void z2() {
	/* deklaracija podataka */
	float f_pro;
	double d_pro;
	/* dodela vrednosti */
	f_pro = 106.11;
	d_pro = -0.0000654;
	/* štampanje vrednosti promenljivih */
	printf("Promenljiva f_pro = %2f\n", f_pro);
	printf("Promenljiva d_pro = %.11f\n", d_pro);
	printf("Promenljiva f_pro = %e\n", f_pro);
	printf("Promenljiva d_pro = %G\n", d_pro);
}

void z3() {
	char ch;
	printf("Unesite proizvoljan karakter: ");
	scanf("%c", &ch); // Naredba za unos podataka 
	printf("ASCII kod unetog karaktera je %c je %d.\n", ch, ch);
}

void z4() {
	int x, y;
	x = 10; y = 10;
	printf("Vrednost izraza ++x je %d\n", ++x);
	printf("Vrednost izraza y++ je %d\n", y++);
	printf("Nakon inkrementriranja vrednost x je %d\n", x);
	printf("Nakon inkrementiranja vrednost y je %d\n", y);
	printf("Vrednost izraza --x je %d\n", --x);
	printf("Vrednost izraza y-- je %d\n", y--);
	printf("Nakon dekrementiranja vrednost x je %d\n", x);
	printf("Nakon dekrementiranja vrednost y je %d\n", y);

	/* Kada koristimo prefiks inkrement/dekrement operator (++x, --y, ...)
	vrednost promenljive se najpre povećava/smanjuje za 1, pa se štampa njena nova vrednost.

	   A kada koristimo postfiks inkrement/dekrement operator (x++, y--, ...)
	prvo se "vraća" tj. u našem slučaju štampa originalna nepromenjena vrednost promenljive,
	pa se tek nakon toga vrednost povećava/smanjuje za 1. */
}

int main() {
	z1(); z2(); z3(); z4();
}