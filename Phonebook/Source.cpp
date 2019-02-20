#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<iostream>

using namespace std;

void Meniu() {
	printf("\t\t\t ______   _                                ____                     _              \n");
	printf("\t\t\t|  __  \\ | |                              |  _  \\                  | |  _        \n");
	printf("\t\t\t| |__>  || |__      ___    ______    ____ | |_> /  _____    _____  | | / /         \n");
	printf("\t\t\t|  ___ / |  __ \\  /  _  \\ | '__  \\  /  _ \\|  _ |  /  _  \\  /  _  \\ | |/ /    \n");
	printf("\t\t\t| |      | |  | ||  |_|  || |   \\ ||   __/| |_> \\|  |_|  ||  |_|  ||    \\       \n");
	printf("\t\t\t|_|      |_|  |_| \\ ___ / |_|   |_| \\___| |_____/ \\ ___ /  \\ ___ / |_| \\_\\   \n\n");
	printf("________________________________________________________________________________________________________________________\n");
}

void Meniu2() {
	printf("   || MAIN MENU ||\n\n");


	printf("1. LOAD(Initializare Automata)\n");
	printf("2. LOAD(Initializare Manuala)\n");
	printf("------------------------------------\n");
	printf("3. ADD CONTACT\n");
	printf("4. SEARCH FOR CONTACT\n");
	printf("5. DELETE CONTACT\n");
	printf("6. EDIT CONTACT\n");
	printf("7. LIST ALL CONTACTS\n\n");
}


typedef struct nod {
	char *nume;
	char *prenume;
	char *varsta;
	char *numar;
	nod *urm;
}nod;
nod*first; nod*last;

void InitializareM() {


	char *a = (char *)malloc(50 * sizeof(char));
	char *b = (char *)malloc(50 * sizeof(char));
	char *c = (char *)malloc(50 * sizeof(char));
	char *d = (char *)malloc(50 * sizeof(char));

	Meniu();
	system("cls");

	printf("Introduceti numele: ");
	scanf("%s", b);
	printf("Introduceti prenumele: ");
	scanf("%s", d);
	printf("Introduceti varsta: ");
	scanf("%s", c);
	printf("Introduceti numarul de telefon: ");
	scanf("%s", a);

	_getch();
	system("cls");
	Meniu();
	printf("\n");
	Meniu2();
	printf("\t\t\tLista a fost initializata.\n");


	first = (nod*)malloc(sizeof(nod));

	first->numar = a;
	first->urm = NULL;
	last = first;

	first->nume = b;

	first->prenume = d;

	first->varsta = c;
}
//inainte de adaugare, lista trebuie initializata LOAD
void InitializareA() {


	char *a = (char *)malloc(50 * sizeof(char));
	char *b = (char *)malloc(50 * sizeof(char));
	char *c = (char *)malloc(50 * sizeof(char));
	char *d = (char *)malloc(50 * sizeof(char));

	strcpy(b, "Georgescu");
	strcpy(d, "Eduard");
	strcpy(c, "18");
	strcpy(a, "0758475672");

	system("cls");
	Meniu();
	printf("\n");
	Meniu2();
	printf("\t\t\tLista a fost initializata.\n");


	first = (nod*)malloc(sizeof(nod));

	first->numar = a;
	first->urm = NULL;
	last = first;

	first->nume = b;

	first->prenume = d;

	first->varsta = c;
}
void Adaugare_Adresa() {
	nod *newnod;
	system("cls");
	Meniu();
	char *a = (char *)malloc(50 * sizeof(char));
	char *b = (char *)malloc(50 * sizeof(char));
	char *c = (char *)malloc(50 * sizeof(char));
	char *d = (char *)malloc(50 * sizeof(char));

	printf("Introduceti numele: ");
	scanf("%s", b);
	printf("Introduceti prenumele: ");
	scanf("%s", d);
	printf("Introduceti varsta: ");
	scanf("%s", c);
	printf("Introduceti numarul de telefon: ");
	scanf("%s", a);

	printf("\t\t\tContactul a fost adaugat.\n");

	newnod = (nod*)malloc(sizeof(nod));

	newnod->numar = a;
	newnod->urm = NULL;
	last->urm = newnod;
	last = newnod;

	newnod->nume = b;

	newnod->prenume = d;

	newnod->varsta = c;

	_getch();
	system("cls");
	Meniu();
	printf("\n");
	Meniu2();

}



//Search cautare dupa nume ###strcmp###
void Search() {
	nod *find;
	char w[20], gasit = 0;
	system("cls");
	Meniu();
	if (first == NULL) {
		printf("\n\t\t\tLista este goala....\n");
		_getch();
		system("cls");
		Meniu();
		printf("\n");
		Meniu2();
		return;
	}
	printf("Introduceti numele contactului pe care vreti sa il cautati in agenda: ");
	scanf("%s", w);
	printf("\n");
	find = first;
	for (; find;) {
		if (strstr(find->nume, w) != NULL) {
			printf("---------------------------------------\n");
			printf("Nume: %s\n", find->nume);
			printf("Prenume: %s\n", find->prenume);
			printf("Varsta: %s\n", find->varsta);
			printf("Nr. Telefon: %s\n\n", find->numar);
			gasit = 1;
			find = find->urm;

		}
		else
			find = find->urm;
	}
	if (gasit == 0) {
		printf("Nu exista contacte .......\n");
	}
	_getch();
	system("cls");
	Meniu();
	printf("\n");
	Meniu2();
}
void Afisare2() {
	int i = 1;
	nod*parcurg;
	parcurg = first;
	system("cls");
	Meniu();
	if (first == NULL) {
		printf("\n\t\t\tLista este goala....\n");
		_getch();
		system("cls");
		Meniu();
		printf("\n");
		Meniu2();
		return;
	}

	while (parcurg) {
		printf("#%d", i);
		printf("---------------------------------------\n");
		printf("\n Nume: %s\n Prenume: %s\n Varsta: %s\n Numarul de telefon: %s\n  \n", parcurg->nume, parcurg->prenume, parcurg->varsta, parcurg->numar);
		parcurg = parcurg->urm;
		i++;
	}
}

void Afisare() {
	int i = 1;
	nod*parcurg;
	parcurg = first;
	system("cls");
	Meniu();
	if (first == NULL) {
		printf("\n\t\t\tLista este goala....\n");
		_getch();
		system("cls");
		Meniu();
		printf("\n");
		Meniu2();
		return;

	}

	while (parcurg) {
		printf("#%d", i);
		printf("---------------------------------------\n");
		printf("\n Nume: %s\n Prenume: %s\n Varsta: %s\n Numarul de telefon: %s\n  \n", parcurg->nume, parcurg->prenume, parcurg->varsta, parcurg->numar);
		parcurg = parcurg->urm;
		i++;
	}
	_getch();
	system("cls");
	Meniu();
	printf("\n");
	Meniu2();
}
//cautare si stergere dupa nume ###strcmp###
void Delete()
{
	nod *del, *dfirst, *dtemp;
	char w[20], confirm = 'n';
	system("cls");
	Meniu();
	if (first == NULL) {
		printf("\n\t\t\tLista este goala....\n");
		_getch();
		system("cls");
		Meniu();
		printf("\n");
		Meniu2();
		return;
	}
	Afisare2();
	printf("Introduceti numele contactului pe care vreti sa il stergeti: : ");
	scanf("%s", w);
	printf("\n");
	dfirst = del = first;
	while (strcmp(del->nume, w) != 0) {
		dtemp = del;
		del = del->urm;
		if (del == NULL) break;
	}
	if (del != NULL) {
		printf("\n\n---------------------------------------------------------");
		printf("\nNume: %s\n", del->nume);
		printf("Prenume: %s\n", del->prenume);
		printf("Varsta: %s\n", del->varsta);
		printf("Nr. Telefon.: %s\n", del->numar);
		printf("---------------------------------------------------------");
		printf("\nStergeti contactul?.....Confirm [y/n]: ");
		confirm = getch();

		if (confirm == 'y') {
			if (del == first) {
				dtemp = first->urm;
				free(first);
				first = dtemp;
			}
			else {
				dtemp = del->urm;
				free(del);
				dfirst->urm = dtemp;
			}
			printf("\n\nContact a fost sters....");
		}
		else
			printf("\n\nContactul nu a fost sters....");
	}
	else {
		printf("\nNu exista contacte.......");
	}
	_getch();
	system("cls");
	Meniu();
	printf("\n");
	Meniu2();
}
//cautare si editare dupa nume ###strcmp###
void Editare()
{
	nod *edit;
	char w[20];
	system("cls");
	Meniu();
	if (first == NULL) {
		printf("\n\t\t\tLista este goala....\n");
		_getch();
		system("cls");
		Meniu();
		printf("\n");
		Meniu2();
		return;
	}
	system("cls");
	Meniu();
	Afisare2();
	printf("Introduceti numele contactului pe care vreti sa il editati: ");
	scanf("%s", w);
	printf("\n");
	edit = first;
	while (strcmp(edit->nume, w) != 0) {
		edit = edit->urm;
		if (edit == NULL) break;
	}
	if (edit != NULL) {
		printf("Nume:");
		scanf("%s", edit->nume);
		printf("Prenume: ");
		scanf("%s", edit->prenume);
		printf("Varsta: ");
		scanf("%s", edit->varsta);
		printf("Nr. Telefon: ");
		scanf("%s", edit->numar);

		printf("---------------------------------------\n");
		printf("Contactul a fost editat.");
	}
	else {
		printf("Nu exista contacte.......\n");
	}
	_getch();
	system("cls");
	Meniu();
	printf("\n");
	Meniu2();
}
void main() {
	char c = ' ';

	Meniu();

	Meniu2();


	do {
		printf(">> ");
		while (c < '1' || c > '7') {
			c = getch();
			//printf("%c", c);
		}
		printf("%c", c);
		_getch();
		switch (c) {
		case '1':
			InitializareA();
			break;
		case '2':
			InitializareM();
			break;
		case '3':
			Adaugare_Adresa();
			break;
		case '4':
			Search();
			break;
		case '5':
			Delete();
			break;
		case '6':
			Editare();
			break;
		case '7':
			Afisare();
			break;

		}
		c = ' ';
	} while (c > '0' || c < '8');
	_getch();
}
