#include <stdio.h>
#include <ctype.h>

void convertiInEsadecimale(int numero) {
    if (numero == 0) {
        printf("0");
        return;
    }

    char esadecimale[32];
    int indice = 0;
    int i=0;

    while (numero > 0) {
        int resto = numero % 16;
        if (resto < 10)
            esadecimale[indice++] = resto + '0';
        else
            esadecimale[indice++] = resto - 10 + 'A';
        numero /= 16;
    }

    for (i = indice - 1; i >= 0; i--) {
        printf("%c", esadecimale[i]);
    }
}

int convertiInDecimaleDaEsadecimale(const char esadecimale[]) {
    int decimale = 0;
    int i = 0;

    while (esadecimale[i] != '\0') {
        decimale *= 16;

        if (isdigit(esadecimale[i])) {
            decimale += esadecimale[i] - '0';
        } else if (esadecimale[i] >= 'A' && esadecimale[i] <= 'F') {
            decimale += esadecimale[i] - 'A' + 10;
        } else if (esadecimale[i] >= 'a' && esadecimale[i] <= 'f') {
            decimale += esadecimale[i] - 'a' + 10;
        } else {
            printf("Input esadecimale non valido.\n");
            return -1; // Indica errore
        }

        i++;
    }
    return decimale;
}

void mostraMenuEsadecimale() {
    int scelta;
    do {
        printf("\n********************************************\n");
        printf("*     CONVERTITORE DECIMALE/ESADECIMALE   *\n");
        printf("********************************************\n");
        printf("* 1. Converti decimale in esadecimale      *\n");
        printf("* 2. Converti esadecimale in decimale      *\n");
        printf("* 3. Esci                                 *\n");
        printf("********************************************\n\n");
        printf("Inserisci la tua scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1: {
                int numero;
                printf("Inserisci un numero decimale: ");
                scanf("%d", &numero);
                if (numero < 0) {
                    printf("Il numero deve essere positivo.\n");
                } else {
                    printf("Esadecimale: ");
                    convertiInEsadecimale(numero);
                    printf("\n");
                }
                break;
            }
            case 2: {
                char esadecimale[32];
                printf("Inserisci un numero esadecimale: ");
                scanf("%s", esadecimale);
                int decimale = convertiInDecimaleDaEsadecimale(esadecimale);
                if (decimale != -1) {
                    printf("Decimale: %d\n", decimale);
                }
                break;
            }
            case 3:
                printf("Uscita dal programma...\n");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    } while (scelta != 3);
}

int main() {
    mostraMenuEsadecimale();
    return 0;
}

