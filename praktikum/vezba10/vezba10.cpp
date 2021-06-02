
#include <iostream>
#include <stdio.h> 

void z1() {
    /* primer upisa u fajl */

    FILE* fp;

    fp = fopen("test.txt", "w+"); // otvaranje fajla (ukoliko fajl ne postoji, bice kreiran novi fajl) 
    fprintf(fp, "This is testing for fprintf...\n"); // upis u fajl
    fputs("This is testing for fputs...\n", fp); 
    fclose(fp); // zatvaranje fajla

}

void z2() {
    /* primer citanja iz fajla */

    FILE* fp; 
    char buff[255];
    
    fp = fopen("test.txt", "r"); // otvaranje fajla 
    fscanf(fp, "%s", buff); // citanje stringa (citanje se prekida nakon prvog blanko znaka) 
    printf("1: %s\n", buff);   // stampanje prethodno ucitanog stringa 

    fgets(buff, 255, (FILE*)fp); // f-ja fgets() cita do n-1 (n=255) karaktera sa fp
    printf("2: %s\n", buff); 

    fgets(buff, 255, (FILE*)fp);
    printf("3: %s\n", buff);
    fclose(fp); // zatvaranje fajla
}

void z3() {
    /* fajl zad3.txt sadrzi podatke o poenima koje su studenti osvojili
    na ispitu iz predmeta programski jezici I. za svakog studenta je zapamcen 
    broj poena koje je dobio na ispitu 
    
    program stampa imena svih studenata koji su polozili ispit.
    ispit su polozili svi studenti koji imaju vise od 50 poena. 
    lista se stampa na standardni izlaz i u fajl rez.txt */

    FILE* fp, * fpr; 

    char ime[20], prezime[20]; 
    int poeni = 0;

    fp = fopen("zad3.txt", "r"); // otvaranje fajla zad3.txt u modu za citanje
    fpr = fopen("rez.txt", "w"); // otvaranje fajla rez.txt u modu za pisanje

    while (!feof(fp)) { // f-ja feof() vraca broj razlicit od nule ako smo došli do kraja datoteke, a nulu u suprotnom.
        fscanf(fp, "%s %s %d", ime, prezime, &poeni); // citanje stringova rec po rec 
        if (poeni > 50) { 
            printf("%s %s %d", ime, prezime, poeni); // stampanje rezultata na standardni izlaz 
            printf("\n");
            fprintf(fpr, "%s %s %d \n", ime, prezime, poeni); // upisivanje rezultata u izlazni fajl (fpr - rez.txt)
        }
    }
    fclose(fp); fclose(fpr); // zatvaranje oba fajla
}

void z4() {
    /* program koji iz zad3.txt racuna prosecan broj poena za ispit
    koji su studenti polagali */


    FILE* fp; 
    char ime[20], prezime[20]; int poeni, brS, brP;
    poeni = brS = brP = 0; // brS - ukupan broj studenata, brP - ukupan broj poena

    fp = fopen("zad3.txt", "r"); // otvaranje fajla zad3.txt u modu za citanje

    while (!feof(fp)) { // f-ja feof() vraca broj razlicit od nule ako smo došli do kraja datoteke, a nulu u suprotnom.
        fscanf(fp, "%s %s %d", ime, prezime, &poeni); // citanje stringova rec po rec 
        brP += poeni; brS++; // broj poena trenutnog studenta se dodaje na brP i iterira se vrednost brS
    }
    printf("Ukupan broj poena: %d\nUkupan broj studenata: %d\n", brP, brS);
    printf("Prosek poena: %d", brP / brS);
}

void z5() {
    /* fajl zad4.txt sadrzi odlomak jednog naseg poznatog romana
    tokom kucanja odlomka greskom je umesto slova 'lj' kucano slowo 'q' i 
    umesto slova 'nj' slovo 'w' 
    
    program izvrsava ispravku gresaka i unete ispravke unosi u fajl rez4.txt 
    i broji koliko je bilo ukupno izmena */

    FILE* fp, * fpr; 

    int c, i = 0;  // i - broj promena 

    fp = fopen("zad4.txt", "r");
    fpr = fopen("rez5.txt", "w");

    while ((c = fgetc(fp)) != EOF) { // citanje karakter po karakter do kraja fajla (EOF)

        switch (c) {
        case 'q': i++; putc('l', fpr); putc('j', fpr); break; // karakteri 'l' i 'j' se ubacuju u izlazni fajl umesto karaktera 'q'
        case 'w': i++; putc('n', fpr); putc('j', fpr); break; // karakteri 'l' i 'j' se ubacuju u izlazni fajl umesto karaktera 'w' 
        default: putc(c, fpr); break; // svi ostali karakteri se prepisuju
        }

    } fclose(fp); fclose(fpr); // zatvaranje fajlova

    printf("Bilo je ukupno %d promena", i);
}


void z6() {
    /* u ulaznoj datoteci se nalaze celi brojevi. 
    u izlaznu datoteku prepisati brojeve iz ulazne 
    datoteke koji su deljivi sa 3 i 7 */

    FILE* fp, * fpr; 
    int br;

    fp = fopen("ulaz.txt", "r"); fpr = fopen("izlaz.txt", "w"); // otvaranje fajlova

    while (!feof(fp)) { // f-ja feof() vraca broj razlicit od nule ako smo došli do kraja datoteke, a nulu u suprotnom.
        fscanf(fp, "%d", &br); // citanje brojeva iz ulaznog fajla
        
        if (br % 3 == 0 && br % 7 == 0) { // ako je broj deljiv sa 3 i 7 
            fprintf(fpr, "%d\n", br); // broj se upisuje u izlazni fajl
        }
    }
    fclose(fpr); fclose(fp); // zatvaranje fajlova 
    
}

void z7() {
    /* program koji brise specifican red txt fajla */

    FILE* fp, *fpr;
    char buff[255], temp;
    int c = 1, red; 

    printf("Broj reda koji se brise: "); scanf("%d", &red);

    fp = fopen("primer.txt", "r+"); fpr = fopen("temp.txt", "w");

    while ((fgets(buff, 255, fp)) != NULL) {
        if (red != c) { // ako trenutni red nije izabran 
            fputs(buff, fpr); // red se prepisuje u novi fajl
            c++; printf("%s", buff);
        } 
        else {
            c++;
        }
    }
}

int main()
{
    z7();
}

