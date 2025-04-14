#include <stdio.h>

// Funzione per calcolare la sequenza di Fibonacci fino al numero n
void fibonacci(int n) {
    int a = 0, b = 1, c, i=0;

    printf("Sequenza di Fibonacci fino a %d termini:\n", n);

    // Stampa i primi due numeri
    printf("%d %d ", a, b);

    // Calcola i numeri successivi nella sequenza
    for (i = 2; i < n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;  // sposta 'a' al valore di 'b'
        b = c;  // sposta 'b' al nuovo valore 'c'
    }

    printf("\n");
}

int main() {
    int num;

    // Input dell'utente
    printf("Inserisci il numero di termini da calcolare nella sequenza di Fibonacci: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Errore! Devi inserire un numero maggiore di 0.\n");
    } else {
        // Chiama la funzione per calcolare la sequenza di Fibonacci
        fibonacci(num);
    }

    return 0;
}

