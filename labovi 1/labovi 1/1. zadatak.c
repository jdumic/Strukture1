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
	char porezime[MAX_SIZE];
	double bodovi;
} student;

int citajRetke()
{
	int brojac = 0;
	FILE* filepointer = NULL;
	char buffer[MAX_LINE] = { 0 };

	filepointer = fopen("Text.txt", "r");
	if (!filepointer) {
		printf("file is not open");
		return FILE_ERROR_OPEN;
	}

	while (!feof(filepointer))
	{
		fgets(buffer, MAX_LINE, filepointer);
		brojac++;
	}
	fclose(filepointer);
	return brojac;
}


int main()
{

	int brojRedaka = 0;

	brojRedaka = citajRetke();


	int i = 0;
	FILE* filepointer = NULL;

	filepointer = fopen("Text.txt", "r");
	if (!filepointer) {
		printf("file is not open");
		return FILE_ERROR_OPEN;
	}

	student* studenti = (student*)malloc(brojRedaka * sizeof(student));

	if (studenti == NULL) {
		printf("greska,nije se alocirala memorija");
		return -1;
	}

	for (i = 0; i < brojRedaka; i++) {
		fscanf(filepointer, "%s %s %d", studenti[i].ime, studenti[i].porezime, &studenti[i].bodovi);
	}

	printf("%d", brojRedaka);

	for (i = 0; i < brojRedaka; i++) {
		float relativniBodovi = (float)studenti[i].bodovi / 100;
		printf("%s %s %d %f/n", studenti[i].ime, studenti[i].porezime, studenti[i].bodovi, relativniBodovi);
	}

	return 0;
}

