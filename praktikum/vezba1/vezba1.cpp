#include <iostream>

void razlika_brojeva() {
	int razlika = 100 - 90;
	printf("\nRazlika 100 - 90 = %d\n\n", razlika); // Naredba 'printf' je definisana u 'stdio.h' biblioteci. Njena funkcija je štampanje podataka (rezultata) na standardnom izlazu.
}

void kolicnik_brojeva() {
	int a = 3, b = 2, c = a / b;
	printf("\nkolicnik (c) = %d\n", c); // Rezultat deljenja (3 / 2) je 1 zato što su promenljive a,b i c celobrojnog tipa (integer), tako da se ostatak pri deljenju ne prikazuje. 
}

void kolicnik_brojeva_2() { 
	int a = 3, b = 0;
	// a = a / b; // Deljenje nulom (b = 0) nije moguće, greška.
	printf("%d\n", a);
}

void zbir_brojeva() {
	int zbir = 0, i; 
	for (i = 0; i < 10; i++) { // Vrednost promenljive 'zbir' pre ulaska u petlju: 0.  
		zbir = zbir + i; 
		printf("i=%d, zbir=%d\n", i, zbir); 
	}
	printf("\nzbir = %d\n", zbir); // Vrednost promenljive 'zbir' nakon izlaska iz petlje: 45. 
}

int	main() {
	printf("Moj prvi program u C jeziku.\n");

	razlika_brojeva();
	zbir_brojeva();
	kolicnik_brojeva();
	// kolicnik_brojeva_2();
}