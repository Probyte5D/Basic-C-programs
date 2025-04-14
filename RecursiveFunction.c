#include <stdio.h>
#include <stdlib.h>

// Dichiarazione della funzione ricorsiva 'f' che prende un intero 'n' come parametro
int f(int n); // Funzione che stampa i numeri da 0 a n in ordine crescente

int main(int argc, char *argv[]) {
    // Chiamata alla funzione 'f' con il valore 5
    f(5); // Inizia la ricorsione con n = 5
    return 0; // Termina il programma
}

// Definizione della funzione ricorsiva 'f' che stampa i numeri da 0 a n
f(int n) {
    // Caso base: quando n è negativo, la funzione termina senza fare nulla
    if (n < 0) {
        return; // Se n < 0, la funzione non fa nulla e ritorna
    } else {
        // Chiamata ricorsiva: 'f' chiama se stessa con n-1
        f(n - 1); // Prima chiama se stessa per stampare i numeri minori

        // Stampa il valore di n dopo che la chiamata ricorsiva è stata completata
        printf("%d\n", n); // Dopo la chiamata ricorsiva, stampa il valore corrente di n
    }
};

