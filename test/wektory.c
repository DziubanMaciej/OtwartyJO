#define CL_TARGET_OPENCL_VERSION 300

#include <JO/jo.h>
#include <stdio.h>
#include <string.h>

#define WIELKOSC_DANYCH 32

int main() {
    /* Inicjalizacja */
    jo_identyfikator_platformy platforma = 0;
    joPobierzIdentyfikatoryPlatform(1, &platforma, NULL);
    jo_identyfikator_urzadzenia urzadzenie = 0;
    joPobierzIdentyfikatoryUrzadzenia(platforma, JO_TYP_URZADZENIA_PG, 1, &urzadzenie, NULL);
    jo_kontekst kontekst = joStworzKontekst(NULL, 1, &urzadzenie, NULL, NULL, NULL);
    jo_kolejka_rozkazow kolejka = joStworzKolejkeRozkazowZWlasciwosciami(kontekst, urzadzenie, NULL, NULL);

    /* Stworzenie buforow i wypelnienie danymi */
    jo_liczba dane[WIELKOSC_DANYCH];
    jo_pamiec buforA = joStworzBufor(kontekst, JO_PAMIEC_PISZ_CZYTAJ, sizeof(dane), NULL, NULL);
    jo_pamiec buforB = joStworzBufor(kontekst, JO_PAMIEC_PISZ_CZYTAJ, sizeof(dane), NULL, NULL);
    jo_pamiec buforC = joStworzBufor(kontekst, JO_PAMIEC_PISZ_CZYTAJ, sizeof(dane), NULL, NULL);
    for (jo_liczba_bz i = 0; i < WIELKOSC_DANYCH; i++) {
        dane[i] = i * 2;
    }
    joZakolejkujPisanieBuforu(kolejka, buforA, JO_FALSZ, 0, sizeof(dane), dane, 0, NULL, NULL);
    for (jo_liczba_bz i = 0; i < WIELKOSC_DANYCH; i++) {
        dane[i] = i * 3;
    }
    joZakolejkujPisanieBuforu(kolejka, buforB, JO_FALSZ, 0, sizeof(dane), dane, 0, NULL, NULL);

    /* Stworzenie programu */
    const char *zrodloProgramu = "void __kernel jadro(__global int* buforA, __global int* buforB, __global int* buforC) {\n"
                                 "    int id = get_global_id(0);\n"
                                 "    buforC[id] = buforA[id] + buforB[id];\n"
                                 "}\n";
    rozmiar_t dlugoscZrodlaProgramu = strlen(zrodloProgramu);
    jo_program program = joStworzProgramZeZrodlem(kontekst, 1, &zrodloProgramu, &dlugoscZrodlaProgramu, NULL);
    joBudujProgram(program, 1, &urzadzenie, NULL, NULL, NULL);
    jo_jadro jadro = joStworzJadro(program, "jadro", NULL);
    joUstawArgumentJadra(jadro, 0, sizeof(buforA), &buforA);
    joUstawArgumentJadra(jadro, 1, sizeof(buforB), &buforB);
    joUstawArgumentJadra(jadro, 2, sizeof(buforC), &buforC);

    /* Wykonanie programu i odczytanie wynikow */
    rozmiar_t wielkoscDanych = WIELKOSC_DANYCH;
    joZakolejkujJadroZakresuND(kolejka, jadro, 1, NULL, &wielkoscDanych, NULL, 0, NULL, NULL);
    joZakolejkujCzytanieBuforu(kolejka, buforC, JO_PRAWDA, 0, sizeof(dane), dane, 0, NULL, NULL);
    for (jo_liczba_bz i = 0; i < WIELKOSC_DANYCH; i++) {
        printf("%d ", dane[i]);
    }
    printf("\n");
}
