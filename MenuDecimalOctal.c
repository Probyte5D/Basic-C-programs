#include <stdio.h>

void convertiInOttale(int numero) {
    int ottale[32];
    int indice = 0;
    int i=0;
    
    if (numero == 0) {
        printf("0");
        return;
    }

    while (numero > 0) {
        ottale[indice++] = numero % 8;
        numero /= 8;
    }

    for (i = indice - 1; i >= 0; i--) {
        printf("%d", ottale[i]);
    }
}

int convertiInDecimaleDaOttale(long long ottale) {
    int decimale = 0, base = 0;

    while (ottale > 0) {
        int cifra = ottale % 10;
        decimale += cifra * (1 << (base * 3)); // potenza di 8 è 3^base
        ottale /= 10;
        base++;
    }

    return decimale;
}

void mostraMenuOttale() {
    int scelta;
    do {
        printf("\n********************************************\n");
        printf("*       CONVERTITORE DECIMALE/OTTALE      *\n");
        printf("********************************************\n");
        printf("* 1. Converti decimale in ottale          *\n");
        printf("* 2. Converti ottale in decimale          *\n");
        printf("* 3. Esci                                 *\n");
        printf("********************************************\n\n");
        printf("Inserisci la tua scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1: {
                int numero;
                printf("Inserisci un numero decimale: ");
                scanf("%d", &numero);
                printf("Ottale: ");
                convertiInOttale(numero);
                printf("\n");
                break;
            }
            case 2: {
                long long ottale;
                printf("Inserisci un numero ottale: ");
                scanf("%lld", &ottale);
                printf("Decimale: %d\n", convertiInDecimaleDaOttale(ottale));
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
    mostraMenuOttale();
    return 0;
}

