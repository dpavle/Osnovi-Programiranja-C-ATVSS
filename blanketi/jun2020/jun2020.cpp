#include <iostream>

int sadrzi_cifru(int X, int d) { // X - ulazni broj, d - cifra
	/* funkcija proverava da li uneti broj X sadrzi unetu cifru d */
	int cifra;

	while (X > 0) {
		cifra = X % 10;

		if (cifra == d) { 
			return d; // u slucaju da broj sadrzi datu cifru, funkcija vraca tu cifru na izlazu
		}
		X = X / 10;
	}
	return -1; // ukoliko broj ne sadrzi datu cifru program vraca -1

}

int broj_samoglasnika(char rec[255]) {
	/* funkcija vraca broj samoglasnika u datom stringu (reci) */

	int brojSamoglasnika = 0, i = 0;

	while(rec[i] != '\0') { 
		if (tolower(rec[i]) == 'a' || tolower(rec[i]) == 'e' || tolower(rec[i]) == 'i' || tolower(rec[i]) == 'o' || tolower(rec[i]) == 'u') {
			brojSamoglasnika++;
		}
		i++;
		
	}
	return brojSamoglasnika;

}
	
void z1() {
	/* papir-kamen-makaze 
	papir je jaci od kamena, kamen od makaza, a makaze od papira
	igraci u program unose odgovarajuci znakovni niz nakon cega kompjuter
	treba da proglasi pobednika. moguci rezultati su: 
	"Pobednik je prvi igrac." 
	"Pobednik je drugi igrac."
	"Nereseno."  
	*/
	char p1[10], p2[10]; 

	printf("Igrac 1: "); scanf("%s", p1);
	printf("Igrac 2: "); scanf("%s", p2);

	while (strcmp(p1, p2) == 0) { // strcmp() vraca 0 ako su dva stringa data u argumentu ista (p1 =/= p2)
		printf("Nereseno. \n");
		printf("Igrac 1: "); scanf("%s", p1);
		printf("Igrac 2: "); scanf("%s", p2);
	}

	if ((strcmp(p1, "Kamen") == 0) && (strcmp(p2, "Makaze") == 0)) { 
		// p1 = "Kamen" =/= "Kamen", ali strcmp(p1, "Kamen") == 0) 
		printf("Pobednik je prvi igrac."); 
	}
	else if((strcmp(p1, "Makaze") == 0) && (strcmp(p2, "Papir") == 0)) { 
		printf("Pobednik je prvi igrac.");
	}
	else if ((strcmp(p1, "Papir") == 0) && (strcmp(p2, "Kamen") == 0)) {
		printf("Pobednik je prvi igrac.");
	}
	else {
		printf("Pobednik je drugi igrac.");
	}
}

void z2() {
	int N, Nt, cifra, obr = 0;

	printf("\nUnesi broj: "); scanf("%d", &N);
	Nt = N; // duplikat originalne unete vrednosti

	while (N > 0) { // na kraju petlje N = 0, zato se dalje u programu koristi Nt
		cifra = N % 10;
		obr = (obr * 10) + cifra;
		/* primer: 123 
		1. obr = 0*10 + 3 = 3
		2. obr = 3*10 + 2 = 30 + 2 = 32 
		3. obr = 32*10 + 1 = 320 = 1 = 321
		*/
		N /= 10;	
	}

	if (Nt == obr) {
		printf("Broj je palindrom.");
	}
	else {
		printf("Broj nije palindrom.");
	}
}

void z3() {
	/* funkcija sadrzi_cifru() proverava da li se cifra d pojavljuje u zapisu broja x.
	u glavnom programu se unosi niz A[] od n elemenata i proverava se koliko el. niza sadrze
	koju cifru. na izlazu se stampa broj el. niza koji sadrzi svaku od cifara. */

	int A[6] = { 1,5,10,20,30,40 };
	int nula, jedan, dva, tri, cetiri, pet, sest, sedam, osam, devet;
	nula = jedan = dva = tri = cetiri = pet = sest = sedam = osam = devet = 0; 

	for (int i = 0; i < 6; i++) { // za svaki element A 
		for (int j = 0; j <= 9; j++) { // za svaku cifru 0-9
			switch (sadrzi_cifru(A[i], j)) { // sadrzi_cifru(X,d) vraca cifru d ukoliko broj sadrzi tu cifru
			case 0: nula++; break;
			case 1: jedan++; break;
			case 2: dva++; break;
			case 3: tri++; break;
			case 4: cetiri++; break;
			case 5: pet++; break;
			case 6: sest++; break;
			case 7: sedam++; break;
			case 8: osam++; break;
			case 9: devet++; break;
			}
		}
	}

	printf("\ncifru 0 sadrze %d elemenata", nula);
	printf("\ncifru 1 sadrze %d elemenata", jedan);
	printf("\ncifru 2 sadrze %d elemenata", dva);
	printf("\ncifru 3 sadrze %d elemenata", tri);
	printf("\ncifru 4 sadrze %d elemenata", cetiri);
	printf("\ncifru 5 sadrze %d elemenata", pet);
	printf("\ncifru 6 sadrze %d elemenata", sest);
	printf("\ncifru 7 sadrze %d elemenata", sedam);
	printf("\ncifru 8 sadrze %d elemenata", osam);
	printf("\ncifru 9 sadrze %d elemenata", devet);
}

void z5() {
	/* ulazni fajl (ulaz.txt) sadrzi spisak studenata (imena, prezimena, i godiste rodjenja)
	za svakog studenta se kreira i u izlazni fajl upisuje sifra 
	sifra se sastoji od prva tri slova imena studenta, njegove god. rodjenja, zadnja dva slova prezimena
	i broja samoglasnika u njegovom imenu i prezimenu 
	
	
	Primer: 
	Milos Kosanovic 1986 --> Mil1986ic6 */

	FILE* ulaz, * izlaz; 
	char ime[16], prezime[16];
	int godina;
	 
	ulaz = fopen("ulaz.txt", "r"); izlaz = fopen("izlaz.txt", "w");


	while (!feof(ulaz)) {
		fscanf(ulaz, "%s %s %d", ime, prezime, &godina);

		for (int i = 0; i < 3; i++) { 
			fputc(ime[i], izlaz); // prva tri karaktera (slova) imena
		}

		fprintf(izlaz, "%d", godina); // godina rodjenja (kao string!)

		fputc(prezime[strlen(prezime) - 2], izlaz); fputc(prezime[strlen(prezime) - 1], izlaz);
		// zadnja dva slova prezimena 

		fprintf(izlaz, "%d\n", broj_samoglasnika(ime) + broj_samoglasnika(prezime)); 
		// zbir broja samoglasnika u imenu 
	}
}



int main() {
	// printf("%d", sadrzi_cifru(34, 3));

	// printf("Papir-Kamen-Makaze:\n"); z1();

	// z2(); z3(); 
	
	z5();

}

