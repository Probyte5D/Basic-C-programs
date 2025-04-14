#include <stdio.h>

// Funzione che verifica se un anno è bisestile
int is_bisestile(int anno) {
    // Un anno è bisestile se:
    // - è divisibile per 4, ma NON per 100, oppure
    // - è divisibile per 400
    if ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0)) {
        return 1;  // Anno bisestile
    }
    return 0;  // Anno non bisestile
}

// Funzione che restituisce il numero di giorni di un mese (considerando l'anno bisestile per febbraio)
int procedura_mese(int m1, int anno) {
    switch (m1) {
        case 4: case 6: case 9: case 11:
            return 30;  // Mesi con 30 giorni
        case 2:
            return is_bisestile(anno) ? 29 : 28;  // Febbraio: 29 giorni se bisestile, altrimenti 28
        default:
            return 31;  // Mesi con 31 giorni
    }
}

// Funzione che calcola i giorni intermedi tra due mesi (non inclusi)
int somma_Intermedia(int m1, int m2, int anno) {
    int i = 0, sommaIntermedia = 0;
    
    if (m2 > m1) {
        // Se il mese di fine è successivo al mese di inizio
        for (i = m1 + 1; i < m2; i++) {
            sommaIntermedia += procedura_mese(i, anno);  // Somma i giorni di ogni mese intermedio
        }
    }
    return sommaIntermedia;
}

// Funzione che calcola la somma totale dei giorni tra due date
int somma_Totale(int m1, int m2, int somma, int g1, int g2, int GiorniIntermedi, int anno) {
    int sommaTotale = 0;
    
    if (m1 != m2) {
        // Se i mesi di inizio e fine sono diversi
        sommaTotale = somma + g2 + GiorniIntermedi;  // Somma i giorni del mese di inizio, giorni intermedi e giorni del mese finale
    } else {
        // Se i mesi sono uguali
        sommaTotale = g2 - g1;  // La somma è solo la differenza tra il giorno finale e quello di inizio
    }
    return sommaTotale;
}

int main() {
    int somma = 0;
    int m1, g1, anno1;

    // Inserimento della data di inizio
    do {
        printf("INSERISCI UNA DATA DI INIZIO (GIORNO, MESE, ANNO):\n");
        scanf("%d %d %d", &g1, &m1, &anno1);
        
        // Verifica se la data inserita è valida
        if (g1 < 1 || g1 > procedura_mese(m1, anno1) || m1 < 1 || m1 > 12) {
            printf("Data non valida! RIPROVA.\n");
        }
    } while (g1 < 1 || g1 > procedura_mese(m1, anno1) || m1 < 1 || m1 > 12);
    
    printf("Data di inizio valida! DATA: %d/%d/%d\n", g1, m1, anno1);
    somma = procedura_mese(m1, anno1) - g1;  // Giorni rimanenti nel mese di inizio

    int m2, g2, anno2;

    // Inserimento della data di fine
    do {
        printf("\nINSERISCI UNA DATA DI FINE (GIORNO, MESE, ANNO):\n");
        scanf("%d %d %d", &g2, &m2, &anno2);
        
        // Verifica se la data inserita è valida
        if (g2 < 1 || g2 > procedura_mese(m2, anno2) || m2 < 1 || m2 > 12) {
            printf("Data non valida! RIPROVA.\n");
        }
    } while (g2 < 1 || g2 > procedura_mese(m2, anno2) || m2 < 1 || m2 > 12);
    
    printf("Data di fine valida! DATA: %d/%d/%d\n", g2, m2, anno2);
    
    // Calcolo dei giorni intermedi
    int GiorniMese = procedura_mese(m1, anno1);
    int GiorniIntermedi = somma_Intermedia(m1, m2, anno1);
    
    // Calcolo dei giorni totali
    int GiorniTot = somma_Totale(m1, m2, somma, g1, g2, GiorniIntermedi, anno1);

    // Gestione delle date al contrario (data finale prima della data di inizio)
    if ((anno2 < anno1) || (anno2 == anno1 && m2 < m1) || (anno2 == anno1 && m2 == m1 && g2 < g1)) {
        printf("La data di fine è precedente alla data di inizio! Riprova con date corrette.\n");
    } else {
        // Visualizzazione del risultato finale
        printf("\nSOMMA TOTALE: %d giorni\n", GiorniTot);
    }

    return 0;
}

