#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

int brojRezervacija = 1;

void unesiRezervaciju(Rezervacija** rez) {
    
    *rez = (Rezervacija*)malloc(sizeof(Rezervacija));
    if (*rez == NULL) {
        perror("Greska pri alociranju memorije");
        exit(EXIT_FAILURE);
    }

    (*rez)->prezime[0] = '\0';       
    (*rez)->brojOsoba = 0;

    printf("===================================\n");
    printf("         Dobrodosli u bar!          \n");
    printf("===================================\n");
    printf("Na koje prezime je rezervacija? -  ");
    if (scanf("%99s", (*rez)->prezime) != 1) {
        printf("Greska pri unosu prezimena.\n");
        free(*rez);
        exit(EXIT_FAILURE);
    }

    printf("Za koliko osoba? - ");
    if (scanf("%d", &((*rez)->brojOsoba)) != 1) {
        printf("Greska pri unosu broja osoba.\n");
        free(*rez);
        exit(EXIT_FAILURE);
    }
    printf("U redu sacekajte.\n\n");

    brojRezervacija++;
}


void prikaziGlavniIzbornik() {

    printf("                                  =============================\n");
    printf("                                           KOKTEL MENI\n");
    printf("                                  =============================\n");
    printf("                                        1. GIN KOKTELI\n");
    printf("                                       2. TEQUILLA KOKTELI\n");
    printf("                                         3. RUM KOKTELI\n");
    printf("                                        4. VODKA KOKTELI\n");
    printf("                                      5. BEZALKOHOLNA PICA\n");
    printf("                                  ==============================\n");
}


void ocistiUlazniTok() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void prviMenu(int *izbor, char** fileIme) {

    static const char* datoteke[] = {
    "GIN.txt",
    "TEQUILLA.txt",
    "RUM.txt",
    "VODKA.txt",
    "BEZALKOHOLNAPICA.txt"
    };

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
            //perror("Nije moguce otvoriti datoteku");
            return;
        }

        char c;
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
    char* fileIme = NULL;
    int odabir;

    do {
        printf("Zelite li izabrati jos nesto? Da(1)/Ne(2): ");
        if (scanf("%d", &odabir) != 1) {
            printf("Da ili ne?.\n");
            continue;
        }

        if (odabir == 1) {
            prikaziGlavniIzbornik();
            printf("Odaberite stranicu: ");
            if (scanf("%d", &odabirGlavnog) != 1) {
                printf("Molimo odaberite jednu od stranica.\n");
                continue;
            }

            switch (odabirGlavnog) {
            case 1: *ukupnaCijena += racunanjeCijenaGin("GIN.txt", 4.99f, 4.49f, 5.39f, racun); break;
            case 2: *ukupnaCijena += racunanjeCijenaTequilla("TEQUILLA.txt", 4.99f, 3.99f, 4.99f, 4.39f, racun); break;
            case 3: *ukupnaCijena += racunanjeCijenaRum("RUM.txt", 4.99f, 4.59f, 4.99f, 4.79f, racun); break;
            case 4: *ukupnaCijena += racunanjeCijenaVodka("VODKA.txt", 5.99f, 4.90f, 5.30f, racun); break;
            case 5: { float novaCijenaPica = racunanjePica("BEZALKOHOLNAPICA.txt", 2.20f, 2.20f, 1.80f, 2.00f, 2.10f, 1.90f, racun);
                      *ukupnaCijena += novaCijenaPica;  break; }
            default: printf("Pogresan odabir.\n"); break;
            }
        }
        else if (odabir == 2) {
            printf("U redu, ispisat cemo racun (:\n");
        }
        else {
            printf("Nevazeci odabir.\n");
        }

    } while (odabir != 2);

    free(fileIme);
    return 1;
}


void ispisUkupneCijene(float ukupnaCijena, FILE* racun) {

    fprintf(racun, "\nUKUPNA CIJENA: %.2f\n\n\n", ukupnaCijena);
    fprintf(racun, "                  Hvala!\n\n");
    fprintf(racun, "---------------------------------------------");
}
