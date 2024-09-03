#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"


int brojRezervacija = 1;

void unesiRezervaciju(Rezervacija** rez) {

    *rez = (Rezervacija*)malloc(sizeof(Rezervacija));
    if (*rez == NULL) {
        printf("Greska pri alokaciji memorije.\n");
        exit(1);
    }

    printf("====================================\n");
    printf("         Dobrodosli u koktel bar!         \n");
    printf("====================================\n");
    printf("Unesite prezime: ");
    if (fgets((*rez)->prezime, MAX_LENGTH, stdin) == NULL) {
        perror("Greska pri unosu prezimena");
        exit(1);
    }
    (*rez)->prezime[strcspn((*rez)->prezime, "\n")] = '\0'; //uklanajnje reda

    printf("Unesite broj osoba: ");
    if (scanf("%d", &(*rez)->brojOsoba) != 1) {
        printf("Krivi unos.\n");
        (*rez)->brojOsoba = 0;  // 0 ako je krivi unos
    }
    ocistiUlazniTok(); 
}
 

void prikaziIzbornik() {

    printf("\n");
    printf("//////////////////////////////////\n\n");
    printf("1. Uzmi narudzbu\n");
    printf("2. Pregled narudzbi\n");
    printf("3. Izbrisi narudzbu\n");
    printf("4. Promjenite broj osoba\n");
    printf("5. Provjerite narudzbu\n");
    printf("6. Kraj radnog vremena\n\n");
    printf("///////////////////////////////////\n\n");
}

void prikaziGlavniIzbornik() {

    printf("\n                                  =============================\n");
    printf("                                           KOKTEL MENI\n");
    printf("                                  =============================\n");
    printf("                                        1. GIN KOKTELI\n");
    printf("                                       2. TEQUILLA KOKTELI\n");
    printf("                                         3. RUM KOKTELI\n");
    printf("                                        4. VODKA KOKTELI\n");
    printf("                                      5. BEZALKOHOLNA PICA\n");
    printf("                                  ==============================\n\n");
}

void ocistiUlazniTok() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void prviMenu(int* izbor, char** fileIme) {

    const char* imeDatoteke = NULL;

    switch (*izbor) {
    case 1: imeDatoteke = "GIN.txt"; break;
    case 2: imeDatoteke = "TEQUILLA.txt"; break;
    case 3: imeDatoteke = "RUM.txt"; break;
    case 4: imeDatoteke = "VODKA.txt"; break;
    case 5: imeDatoteke = "BEZALKOHOLNAPICA.txt"; break;
    default:
        do {
            printf("Izaberite jednu od stranica: ");
            while (scanf("%d", izbor) != 1 || *izbor < 1 || *izbor > 5) {
                printf("Ne postoji ta stranica.");
                ocistiUlazniTok();
            }
        } while (*izbor < 1 || *izbor>5);

        switch (*izbor) {
        case 1: imeDatoteke = "GIN.txt"; break;
        case 2: imeDatoteke = "TEQUILLA.txt"; break;
        case 3: imeDatoteke = "RUM.txt"; break;
        case 4: imeDatoteke = "VODKA.txt"; break;
        case 5: imeDatoteke = "BEZALKOHOLNAPICA.txt"; break;
        }
        break;
    }


    if (imeDatoteke == NULL) {
        exit(EXIT_FAILURE);
    }
    else {
        *fileIme = malloc(strlen(imeDatoteke) + 1);
        if (*fileIme == NULL) {
            perror("Greska pri alociranju memorije");
            exit(EXIT_FAILURE);
        }
        strcpy(*fileIme, imeDatoteke);
    }
}



void ispisiCijeliKoktel(const char* nazivDatoteke) {

    FILE* file = fopen(nazivDatoteke, "r");
    if (file == NULL) {
        perror("Nije moguce otvoriti datoteku");
        return;
    }

    char c;                                                
    while ((c = fgetc(file)) != EOF) {                    
        putchar(c);                                        
    }
    printf("\n");

    fclose(file);
}



void ispisiDetaljeKoktela(int odabirKoktela, int kategorija, FILE* racun) {

    char datoteka[MAX_LENGTH] = "";
    int praviIzbor = 1;

    switch (kategorija) {
    case 1:
        switch (odabirKoktela) {
        case 1: strcpy(datoteka, "GIN1.txt"); break;
        case 2: strcpy(datoteka, "GIN2.txt"); break;
        case 3: strcpy(datoteka, "GIN3.txt"); break;
        default:
            printf("Ne postoji takav koktel na meniu.\n");
            praviIzbor = 0;
            break;
        }
        break;
    case 2:
        switch (odabirKoktela) {
        case 1: strcpy(datoteka, "TEQUILLA1.txt"); break;
        case 2: strcpy(datoteka, "TEQUILLA2.txt"); break;
        case 3: strcpy(datoteka, "TEQUILLA3.txt"); break;
        case 4: strcpy(datoteka, "TEQUILLA4.txt"); break;
        default:
            printf("Ne postoji takav koktel na meniu.\n");
            praviIzbor = 0;
            break;
        }
        break;
    case 3:
        switch (odabirKoktela) {
        case 1: strcpy(datoteka, "RUM1.txt"); break;
        case 2: strcpy(datoteka, "RUM2.txt"); break;
        case 3: strcpy(datoteka, "RUM3.txt"); break;
        case 4: strcpy(datoteka, "RUM4.txt"); break;
        default:
            printf("Ne postoji takav koktel na meniu.\n");
            praviIzbor = 0;
            break;
        }
        break;
    case 4:
        switch (odabirKoktela) {
        case 1: strcpy(datoteka, "VODKA1.txt"); break;
        case 2: strcpy(datoteka, "VODKA2.txt"); break;
        case 3: strcpy(datoteka, "VODKA3.txt"); break;
        default:
            printf("Ne postoji takav koktel na meniu.\n");
            praviIzbor = 0;
            break;
        }
        break;
    case 5:
        switch (odabirKoktela) {
        case 1: fprintf(racun, "\n"); break;
        case 2: fprintf(racun, "\n"); break;
        case 3: fprintf(racun, "\n"); break;
        case 4: fprintf(racun, "\n"); break;
        case 5: fprintf(racun, "\n"); break;
        case 6: fprintf(racun, "\n"); break;
        default:
            printf("Ne postoji takav koktel na meniu.\n");
            praviIzbor = 0;
            break;
        }
        break;
    default:
        praviIzbor = 0;
        break;
    }


    if (praviIzbor) {

        FILE* file = fopen(datoteka, "r");
        if (file == NULL) {
            return;
        }

        char c;  //cita iz datoteke
        while ((c = fgetc(file)) != EOF) {
            fputc(c, racun); 
        }
        fprintf(racun, "\n");

        fclose(file);
    }
}



float racunanjeCijenaGin(const char* nazivDatoteke, float koktel1, float koktel2, float koktel3, FILE* racun) {

    float cijena = 0.0f;
    int odabrani;

    ispisiCijeliKoktel(nazivDatoteke);
    printf("Odaberite koktel(e) (odabir zavrsite sa 0): ");
    while (scanf("%d", &odabrani) == 1 && odabrani != 0) {
        switch (odabrani) {
        case 1: cijena += koktel1; fprintf(racun, "Odabrani koktel: GIN1 - 4.99\n"); break;
        case 2: cijena += koktel2; fprintf(racun, "Odabrani koktel: GIN2 - 4.49\n"); break;
        case 3: cijena += koktel3; fprintf(racun, "Odabrani koktel: GIN3 - 5.39\n"); break;
        default: printf("Nevazeci odabir.\n"); break;
        }
        ispisiDetaljeKoktela(odabrani, 1, racun);           
    }

    return cijena;
}

float racunanjeCijenaVodka(const char* nazivDatoteke, float koktel1, float koktel2, float koktel3, FILE* racun) {

    float cijena = 0.0f;
    int odabrani;

    ispisiCijeliKoktel(nazivDatoteke);
    printf("Odaberite koktel(e) (odabir zavrsite sa 0): ");
    while (scanf("%d", &odabrani) == 1 && odabrani != 0) {
        switch (odabrani) {
        case 1: cijena += koktel1; fprintf(racun, "Odabrani koktel: VODKA1 - 5.99e\n"); break;
        case 2: cijena += koktel2; fprintf(racun, "Odabrani koktel: VODKA2 - 4.90e\n"); break;
        case 3: cijena += koktel3; fprintf(racun, "Odabrani koktel: VODKA3 - 5.30e\n"); break;
        default: printf("Nevazeci odabir.\n"); break;
        }
        ispisiDetaljeKoktela(odabrani, 1, racun);           
    }

    return cijena;
}

float racunanjeCijenaTequilla(const char* nazivDatoteke, float koktel1, float koktel2, float koktel3, float koktel4, FILE* racun) {

    float cijena = 0.0f;
    int odabrani;

    ispisiCijeliKoktel(nazivDatoteke);
    printf("Odaberite koktel(e) (odabir zavrsite sa 0): ");
    while (scanf("%d", &odabrani) == 1 && odabrani != 0) {                         
        switch (odabrani) {
        case 1: cijena += koktel1; fprintf(racun, "Odabrani koktel: TEQUILLA1 - 4.99e\n"); break;
        case 2: cijena += koktel2; fprintf(racun, "Odabrani koktel: TEQUILLA2 - 3.99e\n"); break;
        case 3: cijena += koktel3; fprintf(racun, "Odabrani koktel: TEQUILLA3 - 4.99e\n"); break;
        case 4: cijena += koktel4; fprintf(racun, "Odabrani koktel: TEQUILLA4 - 4.39e\n"); break;
        default: printf("Nevazeci odabir.\n"); break;
        }
        ispisiDetaljeKoktela(odabrani, 2, racun); 
    }

    return cijena;
}


float racunanjeCijenaRum(const char* nazivDatoteke, float koktel1, float koktel2, float koktel3, float koktel4, FILE* racun) {

    float cijena = 0.0f;
    int odabrani;

    ispisiCijeliKoktel(nazivDatoteke);
    printf("Odaberite koktel(e) (odabir zavrsite sa 0): ");
    while (scanf("%d", &odabrani) == 1 && odabrani != 0) {                         
        switch (odabrani) {
        case 1: cijena += koktel1; fprintf(racun, "Odabrani koktel: RUM1 - 4.99e\n"); break;
        case 2: cijena += koktel2; fprintf(racun, "Odabrani koktel: RUM2 - 4.59e\n"); break;
        case 3: cijena += koktel3; fprintf(racun, "Odabrani koktel: RUM3 - 4.99e\n"); break;
        case 4: cijena += koktel4; fprintf(racun, "Odabrani koktel: RUM4 - 4.79e\n"); break;
        default: printf("Nevazeci odabir.\n"); break;
        }
        ispisiDetaljeKoktela(odabrani, 2, racun);
    }

    return cijena;
}


float racunanjePica(const char* nazivDatoteke, float koktel1, float koktel2, float koktel3, float koktel4, float koktel5, float koktel6, FILE* racun) {

    float cijena = 0.0f;
    int odabrani;

    ispisiCijeliKoktel(nazivDatoteke);

    printf("Odaberite pice (odabir zavrsite sa 0): ");
    while (scanf("%d", &odabrani) == 1 && odabrani != 0) {
        switch (odabrani) {
        case 1: cijena += koktel1; fprintf(racun, "Coca- Cola - 2.20e\n"); break;
        case 2: cijena += koktel2; fprintf(racun, "Schweppes - 2.20e\n"); break;
        case 3: cijena += koktel3; fprintf(racun, "Cedevita - 1.80e\n"); break;
        case 4: cijena += koktel4; fprintf(racun, "Ledeni caj - 2.00e\n"); break;
        case 5: cijena += koktel5; fprintf(racun, "Limunska trava - 2.10e\n"); break;
        case 6: cijena += koktel6; fprintf(racun, "Jamnica - 1.90e\n"); break;
        default: printf("Nevazeci odabir.\n"); break;
        }
        ispisiDetaljeKoktela(odabrani, 5, racun);
    }

    return cijena;
}


int dodatniOdabir(float* ukupnaCijena, FILE* racun) {

    int odabirGlavnog;
    int odabir;

    printf("Zelite li izabrati jos nesto? Da(1)/Ne(2): ");
    if (scanf("%d", &odabir) != 1) {
        printf("Da ili ne?.\n");
        ocistiUlazniTok();
        return dodatniOdabir(ukupnaCijena, racun); // Rekurzivni poziv
    }

    if (odabir == 1) {
        prikaziGlavniIzbornik();
        printf("Odaberite stranicu: ");
        if (scanf("%d", &odabirGlavnog) != 1) {
            printf("Molimo odaberite jednu od stranica.\n");
            ocistiUlazniTok();
            return dodatniOdabir(ukupnaCijena, racun);
        }

        switch (odabirGlavnog) {
        case 1: *ukupnaCijena += racunanjeCijenaGin("GIN.txt", 4.99f, 4.49f, 5.39f, racun); break;
        case 2: *ukupnaCijena += racunanjeCijenaTequilla("TEQUILLA.txt", 4.99f, 3.99f, 4.99f, 4.39f, racun); break;
        case 3: *ukupnaCijena += racunanjeCijenaRum("RUM.txt", 4.99f, 4.59f, 4.99f, 4.79f, racun); break;
        case 4: *ukupnaCijena += racunanjeCijenaVodka("VODKA.txt", 5.99f, 4.90f, 5.30f, racun); break;
        case 5: *ukupnaCijena += racunanjePica("BEZALKOHOLNAPICA.txt", 2.20f, 2.20f, 1.80f, 2.00f, 2.10f, 1.90f, racun); break;
        default: printf("Pogresan odabir.\n"); break;
        }
        return dodatniOdabir(ukupnaCijena, racun);
    }
    else if (odabir == 2) {
        printf("U redu, ispisat cemo racun (:\n");
        return 1;
    }
    else {
        printf("Nevazeci odabir.\n");
        ocistiUlazniTok();
        return dodatniOdabir(ukupnaCijena, racun);
    }
}

void ispisRezervacije(Rezervacija* rezervacija, FILE* racun, int redniBroj) {

    fprintf(racun, "REZERVACIJA %d: \n", redniBroj);
    fprintf(racun, "Prezime: %s\n", rezervacija->prezime);
    fprintf(racun, "Broj osoba: %d\n", rezervacija->brojOsoba);
}

void ispisUkupneCijene(float ukupnaCijena, FILE* racun) {

    fprintf(racun, "\nUKUPNA CIJENA: %.2f\n\n\n", ukupnaCijena);
    fprintf(racun, "                  Hvala!\n\n");
    fprintf(racun, "---------------------------------------------");
    fprintf(racun, "\n\n");
}


void pregledNarudzbi() {

    FILE* file = fopen("narudzbe.txt", "r");
    if (file == NULL) {
        perror("Greska pri otvaranju datoteke.");
        return;
    }

    char c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }
    fclose(file);
}

void spremiNarudzbe() {

    FILE* file = fopen("narudzbe.txt", "w");
    if (file == NULL) {
        perror("Greska pri otvaranju datoteke.");
        return;
    }

    for (int i = 0; i < brojNarudzbi; i++) {
        Rezervacija* r = narudzbe[i];
        fprintf(file, "#%d NARUDZBA\n", i + 1);
        fprintf(file, "Prezime: %s\n", r->prezime);
        fprintf(file, "Broj osoba: %d\n", r->brojOsoba);
        fprintf(file, "\n");
    }

    fclose(file);
}

void izbrisiNarudzbu(int broj) {

    if (broj < 1 || broj > brojNarudzbi) {
        printf("Ne postoji takva narudzba.\n");
        return;
    }

    free(narudzbe[broj - 1]); 
    for (int i = broj - 1; i < brojNarudzbi - 1; i++) {
        narudzbe[i] = narudzbe[i + 1];
    }
    brojNarudzbi--;

    spremiNarudzbe();

    printf("Narudzba #%d je izbrisana.\n", broj);
}

void promijeniBrojOsoba(Rezervacija* rezervacija, int noviBrojOsoba) {
    rezervacija->brojOsoba = noviBrojOsoba;
}

void azurirajNarudzbe(Rezervacija* narudzbe[], int brojNarudzbi, const char* imeDatoteke) {
    FILE* datoteka = fopen(imeDatoteke, "w");
    if (datoteka == NULL) {
        perror("Greska pri otvaranju datoteke");
        return;
    }

    for (int i = 0; i < brojNarudzbi; i++) {
        fprintf(datoteka, "Redni broj: %d, Prezime: %s, Broj osoba: %d\n", i + 1, narudzbe[i]->prezime, narudzbe[i]->brojOsoba);
    }

    fclose(datoteka);
}

void azurirajRacun(Rezervacija* rezervacija, const char* imeDatoteke) {
    FILE* racun = fopen(imeDatoteke, "a");
    if (racun == NULL) {
        perror("Greska pri otvaranju datoteke");
        return;
    }

    ispisRezervacije(rezervacija, racun, brojNarudzbi);
    fclose(racun);
}
