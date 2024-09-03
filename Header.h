#ifndef HEADER_H
#define MAX_LENGTH 50
#define MAX_NARUDZBI 50

typedef struct {         
    char prezime[MAX_LENGTH];
    int brojOsoba;
} Rezervacija;

Rezervacija* narudzbe[MAX_NARUDZBI];
int brojNarudzbi;


void unesiRezervaciju(Rezervacija** rez);
void prikaziIzbornik();
void prikaziGlavniIzbornik();
void ocistiUlazniTok();
void prviMenu(int *izbor, char** fileIme);
void ispisiCijeliKoktel(const char* nazivDatoteke);                                 
void ispisiDetaljeKoktela(int odabirKoktela, int kategorija, FILE* racun);
float racunanjeCijenaGin(const char* nazivDatoteke, float koktel1, float koktel2, float koktel3, FILE* racun);
float racunanjeCijenaVodka(const char* nazivDatoteke, float koktel1, float koktel2, float koktel3, FILE* racun);
float racunanjeCijenaTequilla(const char* nazivDatoteke, float koktel1, float koktel2, float koktel3, float koktel4, FILE* racun);
float racunanjeCijenaRum(const char* nazivDatoteke, float koktel1, float koktel2, float koktel3, float koktel4, FILE* racun);
float racunanjePica(const char* nazivDatoteke, float koktel1, float koktel2, float koktel3, float koktel4, float koktel5, float koktel6, FILE* racun);
int dodatniOdabir( float* ukupnaCijena, FILE* racun);
void ispisUkupneCijene(float ukupnaCijena, FILE* racun);
void ispisRezervacije(novaNarudzba, racun);

void pregledNarudzbi();
void izbrisiNarudzbu(int broj);
void spremiNarudzbe();

void promijeniBrojOsoba(Rezervacija* rezervacija, int noviBrojOsoba);
void azurirajNarudzbe(Rezervacija* narudzbe[], int brojNarudzbi, const char* imeDatoteke);
void azurirajRacun(Rezervacija* rezervacija, const char* imeDatoteke);


inline int usporediRezervacije(const void* a, const void* b) {

    Rezervacija* rezA = *(Rezervacija**)a;
    Rezervacija* rezB = *(Rezervacija**)b;
    return strcmp(rezA->prezime, rezB->prezime);
}


#endif
