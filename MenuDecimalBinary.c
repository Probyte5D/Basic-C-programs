#include <stdio.h>
#include <math.h>

void convertiInBinario(int numero) {
    int binario[32];
    int indice = 0;
    int i=0;
    
    if (numero == 0) {
        printf("0");
        return;
    }

    while (numero > 0) {
        binario[indice++] = numero % 2;
        numero /= 2;
    }

    for (i = indice - 1; i >= 0; i--) {
        printf("%d", binario[i]);
    }
}

int convertiInDecimale(long long binario) {
    int decimale = 0, base = 0;

    while (binario > 0) {
        int cifra = binario % 10;
        decimale += cifra * pow(2, base);
        binario /= 10;
        base++;
    }

    return decimale;
}

void mostraMenu() {
    int scelta;
    do {
        printf("\n********************************************\n");
        printf("*        CONVERTITORE DECIMALE/BINARIO    *\n");
        printf("********************************************\n");
        printf("* 1. Converti decimale in binario         *\n");
        printf("* 2. Converti binario in decimale         *\n");
        printf("* 3. Esci                                 *\n");
        printf("********************************************\n\n");
        printf("Inserisci la tua scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1: {
                int numero;
                printf("Inserisci un numero decimale: ");
                scanf("%d", &numero);
                printf("Binario: ");
                convertiInBinario(numero);
                printf("\n");
                break;
            }
            case 2: {
                long long binario;
                printf("Inserisci un numero binario: ");
                scanf("%lld", &binario);
                printf("Decimale: %d\n", convertiInDecimale(binario));
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
    mostraMenu();
    return 0;
}

