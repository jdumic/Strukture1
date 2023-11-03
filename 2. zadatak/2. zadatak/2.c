/*2. Definirati strukturu osoba (ime, prezime, godina rođenja) i napisati program koji:
A. dinamički dodaje novi element na početak liste,
B. ispisuje listu,
C. dinamički dodaje novi element na kraj liste,
D. pronalazi element u listi (po prezimenu),
E. briše određeni element iz liste,
U zadatku se ne smiju koristiti globalne varijable.*/

#define CTR_SECURE_NO_WARNINGS_
#include <stdio.h>
#define MAXDUZINA 80



typedef struct Osoba osoba;
typedef osoba* pozicija;

struct Osoba {
	char ime[MAXDUZINA];
	char prezime[MAXDUZINA];
	int god;
	pozicija next;
};

int upisnapocetak(pozicija, char[MAXDUZINA], char[MAXDUZINA], int);
int ispis(pozicija);
int upisnakraj(pozicija, char[MAXDUZINA], char[MAXDUZINA], int);
int trazi(pozicija, char[MAXDUZINA]);
int brisi(pozicija);

int main() {

	osoba head;
	head.next = NULL;

	upisnapocetak(&head, "ime1", "prezime1", 0001);
	upisnapocetak(&head, "ime2", "prezime2", 0002);
	upisnakraj(&head, "ime3", "prezime3", 0003);
	upisnakraj(&head, "ime4", "prezime4", 0004);
	ispis(head.next);
	trazi(head.next, "prezime3");

	return 0;
}

int upisnapocetak(pozicija p, char imef[MAXDUZINA], char prezimef[MAXDUZINA], int x) {
	pozicija new;
	new = (pozicija)malloc(sizeof(osoba));
	if (new == NULL) {
		printf("greška pri alociranju memorije");
		return -1;
	}

	//newPerson=createPerson(); if(newPerson){  newperson->next=head->next; head->next=newPerson;}

	new->next = p->next;
	p->next = new;

	strcpy(new->ime, imef);
	strcpy(new->prezime, prezimef);
	new->god = x;

	return 1;
}

int ispis(pozicija p) {

	printf("\nime:\tprezime:\tgod:\n");

	while (p != NULL) {
		printf("%s\t%s\t%d\n", p->ime, p->prezime, p->god);
		p = p->next;
	}
	return 1;
}

int upisnakraj(pozicija p, char imef[MAXDUZINA], char prezimef[MAXDUZINA], int x) {
	pozicija new;
	new = (pozicija)malloc(sizeof(osoba));
	if (new == NULL) {
		printf("greška pri alociranju memorije");
		return -1;
	}

	while (p->next != NULL) {
		p = p->next;
	}
	//  newPerson=createPerson(); if(newPerson){ last=findlast(head); newPerson->next=last->next; last->next=newPerosn;}

	new->next = p->next;
	p->next = new;

	strcpy(new->ime, imef);
	strcpy(new->prezime, prezimef);
	new->god = x;

	return 1;
}



int trazi(pozicija p, char prez[MAXDUZINA]) {

	int n = 1;

	while (p != NULL) {
		if (prez == p->prezime) {
			printf("clan se nalazi na poziciji broj:%d ", n);
			return 1;
		}
		n++;
		p = p->next;
	}
	printf("clan ne postoji");

	return 1;
}

<<<<<<< HEAD
int trazi(pozicija p, char prez[MAXDUZINA]) {

	int n = 1;

	while (p != NULL) {
		if (!strcmp(p->prezime, prez)) {
			printf("clan se nalazi na poziciji broj:%d ", n);
			return 1;
		}
		n++;
		p = p->next;
	}
	printf("clan ne postoji");

	return -1;
}

int brisi(pozicija p, char imef[MAXDUZINA]) {



	while (p->next->next != NULL) {
		pozicija temp = NULL;
		if (p->next != NULL && !strcmp(p->next->ime, imef)) {
			temp = p->next;
			p->next = p->next->next;
			free(temp);
			return 1;
		}

		p = p->next;

	}
	printf("clan ne postoji");
	return -1;
}

int upisiza(pozicija p, char ime[MAXDUZINA], char prez[MAXDUZINA], int god, char imef[MAXDUZINA]) {

	pozicija novi = NULL;


	while (p != NULL) {
		if (!strcmp(p->ime, imef)) {
			novi = (pozicija)malloc(sizeof(osoba));
			if (novi == NULL) {
				printf("greška pri alociranju memorije");
				return -1;
			}

			novi->next = p->next;
			p->next = novi;
			strcpy(novi->ime, ime);
			strcpy(novi->prezime, prez);
			novi->god = god;
			return 1;

		}

		p = p->next;
	}
	if (p == NULL) {
		printf("clan ne postoji");
		return -1;
	}





}

int upisispred(pozicija p, char ime[MAXDUZINA], char prez[MAXDUZINA], int god, char imef[MAXDUZINA]) {

	pozicija novi = NULL;
	pozicija prosli = NULL;


	while (p != NULL) {
		if (!strcmp(p->ime, imef)) {
			novi = (pozicija)malloc(sizeof(osoba));
			if (novi == NULL) {
				printf("greška pri alociranju memorije");
				return -1;
			}


			novi->next = prosli->next;
			prosli->next = novi;



			strcpy(novi->ime, ime);
			strcpy(novi->prezime, prez);
			novi->god = god;
			return 1;

		}
		prosli = p;
		p = p->next;

	}
	if (p == NULL) {
		printf("clan ne postoji");
		return -1;
	}

}

int sort(pozicija p) {

	for (int i = 0; (p + i) != NULL; i++) {

	}
=======
int brisi(pozicija p)
{
	pozicija new;
	new = (pozicija)malloc(sizeof(osoba));
	if (new == NULL) {
		printf("greška pri alociranju memorije");
		return -1;
	}

	new->next = p->next;
	p->next = new;
	free(new);

>>>>>>> 1295c46e3a78875a78a56fabe5208f4eaa509874
}