/*1. Napisati program koji prvo pročita koliko redaka ima datoteka, tj. koliko ima studenata
zapisanih u datoteci. Nakon toga potrebno je dinamički alocirati prostor za niz struktura
studenata (ime, prezime, bodovi) i učitati iz datoteke sve zapise. Na ekran ispisati ime,
prezime, apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadrži ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova/max_br_bodova*100*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE (50)
#define MAX_LINE (1024)
#define FILE_ERROR_OPEN (-1)

typedef struct _student {
	char ime[MAX_SIZE];
	char prezime[MAX_SIZE];
	double bodovi;
} student;


int citajRetke()
{
	int brojac = 0;
	FILE* f = NULL;
	char buffer[MAX_LINE] = { 0 };

	f = fopen("Text.txt", "r");
	if (!f) {
		printf("file is not open");
		return FILE_ERROR_OPEN;
	}

	while (!feof(f))
	{
		fgets(buffer, sizeof(buffer), f);
		brojac++;
	}
	fclose(f);
	return brojac;
}

student* alokacija(int n)
{

	student* s = NULL;
	s = (student*)malloc(n * sizeof(student));

	return s;

}

int upis(int n, student* s)
{

	FILE* f = NULL;
	f = fopen("Text.txt", "r");
	if (f == NULL) {
		printf("greska");
		return -1;
	}
	for (int i = 0; i < n; i++) {
		fscanf(f, " % s % s % d", s[i].ime, s[i].prezime, &s[i].bodovi);
	}
	fclose(f);
	return 1;
}

int ispis(int n, student* s)
{

	printf("\nime:\tprezime:\tRB:\tAB\t\n");

	for (int i = 0; i < n; i++) {
		printf("%s\t%s\t%d\t%lf\n", (s + i)->ime, (s + i)->prezime, (s + i)->bodovi, (double)(s + i)->bodovi / 50);
	}
	return 1;
}

int main()
{

	int n;
	student* s = NULL;
	n = citajRetke();
	printf("broj redaka je %d", n);
	s = alokacija(n);
	upis(n, s);
	ispis(n, s);

	return 0;
}

