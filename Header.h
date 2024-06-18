#ifndef HEADER_H
#define HEADER_H

#define MAX_LENGTH 50

typedef struct {         
    char prezime[MAX_LENGTH];
    int brojOsoba;
} Rezervacija;


void prikaziGlavniIzbornik();
void prviMenu(int izbor, char** fileIme);
void ocistiUlaznitok();
void ispisiCijeliKoktel(const char* nazivDatoteke);                                 
void ispisiDetaljeKoktela(int odabirKoktela, int kategorija, FILE* racun);
float racunanjeCijenaGin(const char* nazivDatoteke, float koktel1, float koktel2, float koktel3, FILE* racun);
float racunanjeCijenaVodka(const char* nazivDatoteke, float koktel1, float koktel2, float koktel3, FILE* racun);
float racunanjeCijenaTequilla(const char* nazivDatoteke, float koktel1, float koktel2, float koktel3, float koktel4, FILE* racun);
float racunanjeCijenaRum(const char* nazivDatoteke, float koktel1, float koktel2, float koktel3, float koktel4, FILE* racun);
float racunanjePica(const char* nazivDatoteke, float koktel1, float koktel2, float koktel3, float koktel4, float koktel5, float koktel6, FILE* racun);
int dodatniOdabir( float* ukupnaCijena, FILE* racun);
void unesiRezervaciju(Rezervacija** rez);
void ispisUkupneCijene(float ukupnaCijena, FILE* racun);


inline int comparePrezimena(const void* a, const void* b) {
    return strcmp(((Rezervacija*)a)->prezime, ((Rezervacija*)b)->prezime);                      
}

#endif
