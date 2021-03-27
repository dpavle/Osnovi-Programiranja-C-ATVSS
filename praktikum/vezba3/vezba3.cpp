#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void z1() {
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
		printf("Beli Znak\n");
	}
}


void main() {
	z1(); 

	int slucajan, dvostruki, x, y; 
	srand(time(NULL)); 

	slucajan = rand(); 
	dvostruki = slucajan * 2;
	x = rand() % 10; 
	y = rand() % 10 + 10; 
	printf("Slucajan broj je %d\n", slucajan); 
	printf("Dvostruki slucajan broj je %d\n", dvostruki); 
	printf("Jos neki slucajni brojevi %d,\t%d,\n", x, y); 
}