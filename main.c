#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

extern int brojRezervacija;

int main() {

    FILE* racunClear = fopen("racun.txt", "w");
    if (racunClear == NULL) {
        perror("Greska pri otvaranju racun.txt za čišćenje");
        return 1;
    }
    fclose(racunClear);

    int izbor;
    char* fileIme = NULL;
    float ukupnaCijena = 0.0f;
    int izlaz = 0;

    do {
        prikaziIzbornik();
        printf("Odaberite opciju: ");
        if (scanf("%d", &izbor) != 1) {
            printf("Nevažeći unos. Pokušajte ponovno.\n");
            ocistiUlazniTok();
            continue;
        }
        printf("\n");
        ocistiUlazniTok();

        switch (izbor) {
        case 1: {

            ukupnaCijena = 0.0f;
            if (brojNarudzbi >= MAX_NARUDZBI) {
                printf("Dosegnut maksimalan broj narudžbi.\n");
                break;
            }

            Rezervacija* novaNarudzba = NULL;
            unesiRezervaciju(&novaNarudzba);

            narudzbe[brojNarudzbi++] = novaNarudzba;
            qsort(narudzbe, brojNarudzbi, sizeof(Rezervacija*), usporediRezervacije);

            FILE* racun = fopen("racun.txt", "a");
            if (racun == NULL) {
                perror("Greska pri otvaranju datoteke");
                return 1;
            }
            fprintf(racun, "\n\n          ISPIS RACUNA - Koktel Bar\n\n");
            ispisRezervacije(novaNarudzba, racun, brojNarudzbi);

            prikaziGlavniIzbornik();
            printf("\nOdaberite stranicu: ");
            int odabir;
            if (scanf("%d", &odabir) != 1) {
                printf("Molimo odaberite jednu od stranica.\n");
                fclose(racun);
                continue;
            }

            prviMenu(&odabir, &fileIme);

            switch (odabir) {
            case 1: ukupnaCijena += racunanjeCijenaGin(fileIme, 4.99f, 4.49f, 5.39f, racun); break;
            case 2: ukupnaCijena += racunanjeCijenaTequilla(fileIme, 4.99f, 3.99f, 4.99f, 4.39f, racun); break;
            case 3: ukupnaCijena += racunanjeCijenaRum(fileIme, 4.99f, 4.59f, 4.99f, 4.79f, racun); break;
            case 4: ukupnaCijena += racunanjeCijenaVodka(fileIme, 5.99f, 4.90f, 5.30f, racun); break;
            case 5: {
                float novaCijenaPica = racunanjePica(fileIme, 2.20f, 2.20f, 1.80f, 2.00f, 2.10f, 1.90f, racun);
                ukupnaCijena += novaCijenaPica; break;
            }
            default: printf("Pogrešan odabir.\n"); break;
            }

            dodatniOdabir(&ukupnaCijena, racun);

            long int pozicija = ftell(racun);
            if (pozicija == -1L) {
                perror("Greska pri dobivanju pozicije u datoteci");
                fclose(racun);
                continue;
            }
            fprintf(racun, "Broj narudžbe: %ld\n", pozicija);
            ispisUkupneCijene(ukupnaCijena, racun);

            free(fileIme);
            fclose(racun);
            break;
        }

        case 2: {

            spremiNarudzbe();
            FILE* file = fopen("narudzbe.txt", "r");
            if (file == NULL) {
                perror("Greska pri otvaranju datoteke.");
                break;
            }

            char c;
            while ((c = fgetc(file)) != EOF) {
                putchar(c);
            }
            fclose(file);
            break;
        }

        case 3: {
            if (brojNarudzbi == 0) {
                printf("Nema narudzbi za brisanje.\n");
                break;
            }

            printf("Unesite redni broj narudzbe koju zelite izbrisati: ");
            int broj;
            if (scanf("%d", &broj) != 1) {
                printf("Pokusajte ponovno.\n");
                ocistiUlazniTok();
                break;
            }

            izbrisiNarudzbu(broj);
            break;
        }

        case 4: {
            if (brojNarudzbi == 0) {
                printf("Nema narudzbi za azuriranje.\n");
                break;
            }

            printf("Unesite redni broj narudzbe koju zelite azurirati: ");
            int broj;
            if (scanf("%d", &broj) != 1 || broj < 1 || broj > brojNarudzbi) {
                printf("Pogresan unos. Pokusajte ponovno.\n");
                ocistiUlazniTok();
                break;
            }

            printf("Unesite novi broj osoba: ");
            int noviBrojOsoba;
            if (scanf("%d", &noviBrojOsoba) != 1) {
                printf("Pogresan unos. Pokusajte ponovno.\n");
                ocistiUlazniTok();
                break;
            }

            promijeniBrojOsoba(narudzbe[broj - 1], noviBrojOsoba); 
            azurirajNarudzbe(narudzbe, brojNarudzbi, "narudzbe.txt");
            azurirajRacun(narudzbe[broj - 1], "racun.txt");  
            break;
        }
        case 5: {

            char prezimeZaPretragu[MAX_LENGTH];
            printf("Unesite prezime za pretragu: ");
            fgets(prezimeZaPretragu, MAX_LENGTH, stdin);
            prezimeZaPretragu[strcspn(prezimeZaPretragu, "\n")] = '\0';

            
            Rezervacija kljuc = { .prezime = "" };
            strcpy(kljuc.prezime, prezimeZaPretragu);
            Rezervacija* ptrKljuc = &kljuc;

            Rezervacija** rezultat = (Rezervacija**)bsearch(&ptrKljuc, narudzbe, brojNarudzbi, sizeof(Rezervacija*), usporediRezervacije);

            if (rezultat != NULL) {
                printf("Narudzba pronadena: %s, Broj osoba: %d\n", (*rezultat)->prezime, (*rezultat)->brojOsoba);
            }
            else {
                printf("Narudzba nije pronadena.\n");
            }
            break;
        }
        case 6:
            izlaz = 1;
            break;

        default:
            printf("Pokusajte ponovno.\n");
            break;
        }

    } while (!izlaz);

    for (int i = 0; i < brojNarudzbi; i++) {
        free(narudzbe[i]);
    }

    return 0;
}
