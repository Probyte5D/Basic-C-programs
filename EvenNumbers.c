#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // Inclusione per la funzione sqrt()

// Funzione per verificare se un numero è un quadrato perfetto
int quadratoPerfetto(int num) {
    int radice = sqrt(num);  // Calcoliamo la radice quadrata del numero
    return (radice * radice == num);  // Se il quadrato della radice è uguale al numero, è un quadrato perfetto
}

// Funzione per verificare se un numero è divisibile per un altro numero
int divisibilePer(int num, int divisore) {
    if (divisore == 0) {
        printf("Impossibile dividere per zero!\n");
        return 0;
    }
    return (num % divisore == 0);  // Restituisce 1 se è divisibile, 0 altrimenti
}

// Funzione principale del programma
int main() {
    int num, divisore;

    // Chiedo all'utente di inserire un numero
    printf("Inserisci un numero: ");
    scanf("%d", &num);

    // Verifico se il numero è positivo, negativo o zero
    if (num > 0) {
        printf("Il numero e' positivo.\n");
    } else if (num < 0) {
        printf("Il numero e' negativo.\n");
    } else {
        printf("Il numero e' zero.\n");
    }

    // Verifico se il numero è pari o dispari
    if (num % 2 == 0) {
        printf("Il numero e' pari.\n");
    } else {
        printf("Il numero e' dispari.\n");
    }

    // Verifico se il numero è un quadrato perfetto
    if (quadratoPerfetto(num)) {
        printf("Il numero %d e' un quadrato perfetto.\n", num);
    } else {
        printf("Il numero %d non e' un quadrato perfetto.\n", num);
    }

    // Chiedo all'utente di inserire un altro numero per verificare la divisibilità
    printf("Inserisci un divisore per verificare se %d è divisibile: ", num);
    scanf("%d", &divisore);

    if (divisibilePer(num, divisore)) {
        printf("Il numero %d e' divisibile per %d.\n", num, divisore);
    } else {
        printf("Il numero %d non e' divisibile per %d.\n", num, divisore);
    }

    // Chiedo all'utente se vuole continuare
    char scelta;
    printf("Vuoi inserire un altro numero? (s/n): ");
    scanf(" %c", &scelta);  // Nota lo spazio prima di %c per gestire il carattere di nuova linea
    if (scelta == 's' || scelta == 'S') {
        main();  // Chiamata ricorsiva alla funzione main per continuare
    } else {
        printf("Programma terminato.\n");
    }

    return 0;  // Termina il programma con successo
}

