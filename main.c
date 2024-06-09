#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

extern int brojRezervacija;  

int main() {

    Rezervacija* rezervacija = NULL;
    unesiRezervaciju(&rezervacija);
                                         
    if (getchar() == EOF) {                           
        perror("Greska pri citanju.");
        return 1;
    }

    FILE* racun = fopen("racun.txt", "w");
    if (racun == NULL) {
        perror("Greska pri otvaranju datoteke");
        return 1;
    }
    fprintf(racun, "          ISPIS RACUNA - Koktel Bar\n\n"); 
    long int pocetak = ftell(racun); 
    
   
    qsort(rezervacija, brojRezervacija, sizeof(Rezervacija), comparePrezimena);   // 21.


    char trazenoIme[MAX_LENGTH];                                          
    printf("----------------------------\n");
    printf("Mozete li ponoviti prezime: ");
    if (fgets(trazenoIme, sizeof(trazenoIme), stdin) == NULL) {
        printf("Nemamo rezervaciju na to prezime. Izabreite drugi termin.");
        return 1;
    }
    trazenoIme[strcspn(trazenoIme, "\n")] = '\0';


    Rezervacija kljuc = { "",0 };
    strcpy(kljuc.prezime, trazenoIme);
    Rezervacija* rezultat = bsearch(&kljuc, rezervacija, brojRezervacija, sizeof(Rezervacija), comparePrezimena);             // 22.
    if (rezultat != NULL) {
        printf("Rezervacija | %s | za |%d| je pronadena.\n\n", trazenoIme, rezervacija->brojOsoba);
    }
    else {
        printf("Rezervacija za prezime %s nije pronadena. Zao mi je.\n", trazenoIme);
        printf("Rezervirajte drugi termin.");
        return 1;
    }
    fprintf(racun, "Rezervacija na prezime: %s\nBroj osoba: %d\n\n", rezervacija->prezime, rezervacija->brojOsoba);



    int izbor;
    char* fileIme = NULL;
    float ukupnaCijena = 0.0f;

    prikaziGlavniIzbornik();
    printf("\nOdaberite stranicu: ");
    if (scanf("%d", &izbor) != 1) {
        printf("Molimo odaberite jednu od stranica.\n");
        return 1;
    }

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    prviMenu(izbor, &fileIme);
    switch (izbor) {
    case 1: ukupnaCijena += racunanjeCijenaGin(fileIme, 4.99f, 4.49f, 5.39f, racun); break;
    case 2: ukupnaCijena += racunanjeCijenaTequilla(fileIme, 4.99f, 3.99f, 4.99f, 4.39f, racun); break;
    case 3: ukupnaCijena += racunanjeCijenaRum(fileIme, 4.99f, 4.59f, 4.99f, 4.79f, racun); break;
    case 4: ukupnaCijena += racunanjeCijenaVodka(fileIme, 5.99f, 4.90f, 5.30f, racun); break;
    case 5: { float novaCijenaPica = racunanjePica(fileIme, 2.20f, 2.20f, 1.80f, 2.00f, 2.10f, 1.90f, racun);
            ukupnaCijena += novaCijenaPica; break; }
    default: printf("Pogresan odabir.\n"); break;
    }
 
    dodatniOdabir(&ukupnaCijena, racun);
    ispisUkupneCijene(ukupnaCijena, racun);
    free(fileIme);
    fclose(racun);


    if (rename("racun.txt", "gotovRacun.txt") != 0) {
        perror("Greska pri preimenovanju datoteke.");
        return 1;
    }

    free(rezervacija);

    return 0;
}
