#define CL_TARGET_OPENCL_VERSION 300

#include <JO/jo.h>
#include <stdio.h>
#include <string.h>

int main() {
    /* Inicjalizacja */
    jo_identyfikator_platformy platforma = 0;
    joPobierzIdentyfikatoryPlatform(1, &platforma, NULL);
    jo_identyfikator_urzadzenia urzadzenie = 0;
    joPobierzIdentyfikatoryUrzadzenia(platforma, JO_TYP_URZADZENIA_GPU, 1, &urzadzenie, NULL);
    jo_kontekst kontekst = joStworzKontekst(NULL, 1, &urzadzenie, NULL, NULL, NULL);
    jo_kolejka_rozkazow kolejka = joStworzKolejkeRozkazowZWlasciwosciami(kontekst, urzadzenie, NULL, NULL);

    char bufor[1024];
    joPobierzInformacjeUrzadzenia(urzadzenie, JO_NAZWA_URZADZENIA, sizeof(bufor), bufor, NULL);
    printf("Urzadzenie: %s", bufor);
    joPobierzInformacjeUrzadzenia(urzadzenie, JO_DOSTAWCA_URZADZENIA, sizeof(bufor), bufor, NULL);
    printf(" (dostawca:  %s)\n\n", bufor);
}
