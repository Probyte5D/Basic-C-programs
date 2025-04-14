#include <stdio.h>
#include <stdlib.h>

// Funzioni del menu
int mostraMenu(void);
void deposita(float *saldo);
void preleva(float *saldo);
void mostraSaldo(float saldo);

int main() {
    int scelta;
    float saldo = 0.0f; // Saldo iniziale

    do {
      
        scelta = mostraMenu();
        
        switch (scelta) {
            case 1:
                deposita(&saldo);
                system("PAUSE");
                break;
            case 2:
                preleva(&saldo);
                system("PAUSE");
                break;
            case 3:
                mostraSaldo(saldo);
                system("PAUSE");
                break;
            case 4:
                printf("\nGrazie per aver usato il sistema bancario. Arrivederci!\n");
                break;
            default:
                printf("\nScelta non valida. Riprova.\n");
                system("PAUSE");
        }
    } while (scelta != 4);
    
    return 0;
}

// Funzione per mostrare il menu
int mostraMenu(void) {
    int scelta;
    do {
        printf("\n********************************************\n");
        printf("*      SISTEMA DI GESTIONE CONTO BANCARIO  *\n");
        printf("********************************************\n");
        printf("* 1. Deposita denaro                       *\n");
        printf("* 2. Preleva denaro                        *\n");
        printf("* 3. Controlla saldo                       *\n");
        printf("* 4. Esci                                  *\n");
        printf("********************************************\n\n");
        printf("Inserisci la tua scelta: ");
        scanf("%d", &scelta);

        if (scelta < 1 || scelta > 4) {
            printf("\nErrore: inserisci un numero valido!\n");
            system("PAUSE");
        }
    } while (scelta < 1 || scelta > 4);
    
    return scelta;
}

// Funzione per depositare denaro
void deposita(float *saldo) {
    float importo;
    printf("\nInserisci l'importo da depositare: ");
    scanf("%f", &importo);

    if (importo > 0) {
        *saldo += importo;
        printf("\nHai depositato %.2f EUR.\nNuovo saldo: %.2f EUR\n", importo, *saldo);
    } else {
        printf("\nImporto non valido. Il deposito deve essere positivo.\n");
    }
}

// Funzione per prelevare denaro
void preleva(float *saldo) {
    float importo;
    printf("\nInserisci l'importo da prelevare: ");
    scanf("%f", &importo);

    if (importo > 0 && importo <= *saldo) {
        *saldo -= importo;
        printf("\nHai prelevato %.2f EUR.\nNuovo saldo: %.2f EUR\n", importo, *saldo);
    } else if (importo > *saldo) {
        printf("\nFondi insufficienti! Il tuo saldo è %.2f EUR.\n", *saldo);
    } else {
        printf("\nImporto non valido. Il prelievo deve essere positivo.\n");
    }
}

// Funzione per mostrare il saldo
void mostraSaldo(float saldo) {
    printf("\nIl tuo saldo attuale è: %.2f EUR\n", saldo);
}

