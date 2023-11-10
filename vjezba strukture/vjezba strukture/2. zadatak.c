/*2. Definirati strukturu osoba(ime, prezime, godina rođenja) i napisati program koji :
A.dinamički dodaje novi element na početak liste,
B.ispisuje listu,
C.dinamički dodaje novi element na kraj liste,
D.pronalazi element u listi(po prezimenu),
E.briše određeni element iz liste,
U zadatku se ne smiju koristiti globalne varijable.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX (80)

typedef struct osoba
{
	char ime[MAX];
	char prezime[MAX];
	int god;
	pozicija next;
} osoba;

typedef osoba* pozicija;

int upisNaPocetak(pozicija, char[MAX], char[MAX], int);
int ispis(pozicija);
int upisNaKraj(pozicija, char[MAX], char[MAX], int);
int trazi(pozicija, char[MAX]);
int brisi(pozicija);


int upisNaPocetak(pozicija p, char imef[MAX], char prezimef[MAX], int x)
{

	pozicija new;
	new = (pozicija)malloc(sizeof(osoba));
	if (new == NULL)
	{
		printf("greska");
		return -1;
	}

	new->next = p->next;
	p->next = new;

	strcpy(new->ime, imef);
	strcpy(new->prezime, prezimef);
	new->god = x;

	return 1;

}

int ispis(pozicija p)
{

	printf("\nime\tprezime\tgod\n");

	while (p != NULL)
	{
		printf("%s\t%s\t%d\n", p->ime, p->prezime, p->god);
		p = p->next;
	}
	return 1;

}

int upisNaKraj(pozicija p, char imef[MAX], char prezimef[MAX], int x)
{

	pozicija new;
	new = (pozicija)malloc(sizeof(osoba));

	if (new == NULL)
	{
		printf("greska");
		return -1;
	}

	while (p->next != NULL)
	{
		p = p->next;
	}

	new->next = p->next;
	p->next = new;

	strcpy(new->ime, imef);
	strcpy(new->prezime, prezimef);
	new->god = x;

	return 1;

}