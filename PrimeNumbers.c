#include <stdio.h>

// Funzione per verificare se un numero e primo
int verificaPrimo(int numero) {
    int i = 0;
    if (numero <= 1) return 0;  // 0 e 1 non sono numeri primi
    for (i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0;  // Il numero e divisibile per un altro numero, quindi non e primo
        }
    }
    return 1;  // Il numero e primo
}

// Funzione per stampare tutti i numeri primi fino a un dato numero
void stampaNumeriPrimiFinoA(int limite) {
    int i = 0;
    printf("Numeri primi fino a %d:\n", limite);
    for (i = 2; i <= limite; i++) {
        if (verificaPrimo(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Funzione per calcolare la somma dei numeri primi fino a un dato numero
int sommaNumeriPrimiFinoA(int limite) {
    int somma = 0;
    int i = 0;
    for (i = 2; i <= limite; i++) {
        if (verificaPrimo(i)) {
            somma += i;
        }
    }
    return somma;
}

int main() {
    int numero;

    // Verifica se un singolo numero e primo
    printf("Inserisci un numero per verificare se e primo: ");
    scanf("%d", &numero);

    if (verificaPrimo(numero)) {
        printf("%d e un numero primo.\n", numero);
    } else {
        printf("%d non e un numero primo.\n", numero);
    }

    // Stampa tutti i numeri primi fino a un dato numero
    int limite;
    printf("\nInserisci un numero per vedere tutti i numeri primi fino a quel numero: ");
    scanf("%d", &limite);
    stampaNumeriPrimiFinoA(limite);

    // Calcola la somma dei numeri primi fino a un dato numero
    int somma = sommaNumeriPrimiFinoA(limite);
    printf("La somma dei numeri primi fino a %d e: %d\n", limite, somma);

    return 0;
}

