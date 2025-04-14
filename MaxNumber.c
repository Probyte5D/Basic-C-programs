#include <stdio.h>
#include <stdlib.h>

// Funzione per determinare il massimo tra tre numeri
int massimo(int a, int b, int c) {
    // Confronto a, b e c per trovare il numero massimo
    if (a > b && a > c) {
        return a; // Se 'a' è maggiore di entrambi 'b' e 'c', ritorna 'a'
    } else if (b > c && b > a) {
        return b; // Se 'b' è maggiore di entrambi 'a' e 'c', ritorna 'b'
    } else {
        return c; // Altrimenti ritorna 'c'
    }
}

int main() {
    // Dichiarazione delle variabili
    int max, x = 5, y = 6, z = 2;
    
    // Stampa dei tre numeri
    printf("I tre numeri sono: %d, %d, %d\n", x, y, z);
    
    // Chiamata alla funzione massimo per trovare il massimo tra x, y e z
    max = massimo(x, y, z);
    
    // Stampa del massimo
    printf("Il maggiore tra i tre numeri è: %d\n", max);
    
    return 0; // Termina il programma con successo
}

