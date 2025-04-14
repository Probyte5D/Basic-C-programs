#include <stdio.h>  // Include per le funzioni di input e output

#define RIGHE 10   // Numero di righe (es. tabellina da 1 a 10)
#define COLONNE 10 // Numero di colonne (es. tabellina da 1 a 10)

// Funzione per riempire la matrice con i risultati della tabellina
void riempiPitagorica(int miaMat[RIGHE][COLONNE]) {
	int x=0, y=0;
    for (x = 0; x < RIGHE; x++) {    // Seleziona la riga
        for (y = 0; y < COLONNE; y++) { // Riempie la colonna
            miaMat[x][y] = (x + 1) * (y + 1); // Calcola il prodotto
        }
    }
}

// Funzione per visualizzare la matrice
void mostraMatrice(int miaMat[RIGHE][COLONNE]) {
	int x=0, y=0;
    for (x = 0; x < RIGHE; x++) { // Cicla sulle righe
        for (y = 0; y < COLONNE; y++) { // Cicla sulle colonne
            printf("%4d", miaMat[x][y]); // Stampa ogni numero
        }
        printf("\n"); // Aggiunge una nuova riga dopo ogni riga della matrice
    }
}

int main(void) {
    int miaMat[RIGHE][COLONNE]; // Matr0rice per memorizzare i risultati
    riempiPitagorica(miaMat);    // Riempi la matrice con i risultati della tabellina
    mostraMatrice(miaMat);       // Visualizza la matrice
    return 0;                    // Termina il programma
}

