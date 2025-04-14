#include <stdio.h>

int main() {
    int numero;
    int i = 0;

    printf("Inserisci un numero: ");
    scanf("%d", &numero);

    // Verifica se il numero è positivo, negativo o zero
    if (numero > 0) {
        printf("Il numero %d è positivo.\n", numero);

        // Somma di numeri positivi
        int somma = 0;
        int n;
        printf("\nQuanti numeri vuoi sommare? ");
        scanf("%d", &n);

        printf("Inserisci %d numeri positivi: \n", n);
        for (i = 0; i < n; i++) {
            int valore;
            do {
                printf("Numero %d: ", i + 1);
                scanf("%d", &valore);
                if (valore < 0) {
                    printf("Per favore, inserisci solo numeri positivi!\n");
                }
            } while (valore < 0);

            somma += valore;
        }

        printf("\nLa somma dei numeri positivi inseriti è: %d\n", somma);
    } else {
        printf("Il numero inserito non è positivo.\n");
    }

    return 0;
}

