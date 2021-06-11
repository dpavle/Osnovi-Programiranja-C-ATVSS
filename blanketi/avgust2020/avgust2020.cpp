
#include <iostream>

void z1() {
	/* u program unosimo tekst do pojavljivanja znaka '.', pri cemu tekst
	unosimo slovo po slovo. prikazuje broj pojavljivanja svih samoglasnika i 
	izrazava tu vrednost procentualno u odnosu na sve unete znake. */

	char in; 
	int a_ct, e_ct, i_ct, o_ct, u_ct, ostalo, ukupno; 
	a_ct = e_ct = i_ct = o_ct = u_ct = ostalo = ukupno = 0;

	printf("Unesi tekst: ");
	while ((in = getchar()) != '.') { // tekst se unosi dok se ne unese znak '.'
		switch (in) { // AEIOU/aeiou - samoglasnici 
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
			default: ostalo++; break; // ako nema samoglasnika, inkrementira se vrednost ostalo, tj. broj suglasnika 
			}  // kraj switch 
		ukupno++;
	}

	printf("A: %d E: %d I: %d O: %d U: %d", a_ct, e_ct, i_ct, o_ct, u_ct);
	printf("\n%2d%% unesenih karaktera su samoglasnici.\n", ((a_ct + e_ct + i_ct + o_ct + u_ct) * 100) / ukupno); 
}

bool palindrom(int num) { // zadatak 2.1
	/* funkcija koja za uneti proizvoljan broj proverava da li je on palindrom. */

	int c, obrnut = 0; 
	int original = num;

	if (num < 0) { // brojevi manji od 0 ne mogu biti palindomi
		return false; 
	}
	
	while (num > 0) { 
		c = num % 10; // izvlacenje cifara 
		obrnut = obrnut * 10 + c; // 'okretanje' broja
		num /= 10; 
	}

	return (original == obrnut); // broj je palindrom ako se moze procitati na isti nacin sa leva na desno i sa desna na levo
}

void z3() {
	/* program koji racuna broj elemenata vecih od 10 i deljivih sa 3. 
	svi takvi elementi se smestaju u novi niz i racuna se njihov zbir.*/

	int b = 0, rez[3 * 4], z = 0; // rez - skup svih elemenata vecih od 10 i deljivih sa 3, z - zbir, b - brojac

	const int matrica[3][4] = 
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (matrica[i][j] > 10 && matrica[i][j] % 3 == 0) { // uslov zadatka
				z += matrica[i][j]; // zbir svih clanova koji ispunjavanju uslov
				rez[b] = matrica[i][j]; // skup svih elemenata koji ispunjavaju uslov
				b++; // brojac elemenata
			}
		}
	}

	printf("\nElemenata matrice koji su >10 i deljivi sa 3 ima %d, oni su: ", b);

	for (int i = 0; i < b; i++) {
		printf("%d ", rez[i]);
	}

	printf("\nNjihov zbir je: %d\n", z);
}


void z4() {
	/* u ulaznoj datoteci ulaz.txt se nalaze imena gradova u srbiji.
	u izlaznu datoteku izlaz.txt se prepisuju imena svih gradova koja pocinju na B 
	ili ona cija je duzina veca od 11 slova.*/

	FILE* ulaz, *izlaz; 
	char buffer[255];

	ulaz = fopen("ulaz.txt", "r"); izlaz = fopen("izlaz.txt", "w"); // otvaranje fajlova

	while (fgets(buffer, 255, ulaz) != NULL) { // citanje stringova ulaznog fajla red-po-red
		if ((strlen(buffer) > 11) || buffer[0] == 'B') { // strlen() funkcija vraca duzinu stringa
			// printf("%s", &buffer[0]); 
			fputs(buffer, izlaz); // upis stringova koji ispunjavaju uslov iz bafera u izlazni fajl
		}
	}
	fclose(ulaz); fclose(izlaz); // zatvaranje fajlova 
}

int povrsina_obim_pravougaonika(int a, int b, int c) {
	/* funkcija koja racuna povrsinu i obim pravougaonika 
	integer c sluzi za odabir return vrednosti f-je (obim/povrsina) */
	
	int obim, povrsina;

	obim = 2 * (a + b); 
	povrsina = a * b;

	if (c == 1) {
		return (obim);
	}
	else if (c == 2) {
		return (povrsina);
	}
	else {
		return 0;
	}
}


int main() {
	int num[50], n, p = 0, a, b, obim, povrsina, zp = 0;


	 z1(); // zadatak 1

	printf("Unesi N: "); scanf_s("%d", &n); // zadatak 2.2

	for (int i = 0; i < n; i++) { // unos brojeva i ispit palindroma
		scanf_s("%d", &num[i]);
		if (palindrom(num[i])) {
			p++; 
		}
	}
	printf("Ima %d palindroma! \n", p);
	
	z3(); // zadatak 3

	z4(); // zadatak 4


	printf("Unesi N: "); scanf_s("%d", &n); // zadatak 5 

	for (int i = 0; i < n; i++) {
		printf("Unesi a i b pravouganika: "); scanf_s("%d %d", &a, &b);

		obim = povrsina_obim_pravougaonika(a, b, 1); povrsina = povrsina_obim_pravougaonika(a, b, 2);

		printf("Obim %d. pravougaonika: %d\n", i+1, obim); 
		
		zp += povrsina;
	}

	printf("Zbir povrsina svih pravougaonika je: %d", zp);
}


