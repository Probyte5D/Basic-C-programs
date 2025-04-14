#include <stdio.h>
#include <stdlib.h>

// Funzione principale del programma
int main() {
    // Dichiarazione delle variabili per i voti delle tre materie
    float votoinf, votoita, votomat;
    
    // Chiedo all'utente di inserire i voti per le tre materie
    printf("Inserisci tre voti: voto informatica, voto italiano, voto matematica (separati da uno spazio): ");
    
    // Leggo i valori dei voti inseriti dall'utente
    int validInput = scanf("%f %f %f", &votoinf, &votoita, &votomat); // I voti sono separati da uno spazio
    
    // Verifica se l'input è valido (i voti devono essere numeri)
    if (validInput != 3) {
        printf("Errore nell'input. Per favore inserisci valori numerici validi.\n");
        return 1; // Uscita con errore
    }

    // Controllo se i voti sono nel range valido (0 - 10)
    if (votoinf < 0 || votoinf > 10 || votoita < 0 || votoita > 10 || votomat < 0 || votomat > 10) {
        printf("Errore: I voti devono essere compresi tra 0 e 10.\n");
        return 1; // Uscita con errore
    }
    
    // Dichiarazione delle variabili per la somma e la media dei voti
    float somma, media;
    
    // Calcolo la somma dei voti
    somma = votoinf + votoita + votomat;
    
    // Calcolo la media dei voti
    media = somma / 3;
    
    // Stampo i voti individuali
    printf("Voto Informatica: %.2f\n", votoinf);
    printf("Voto Italiano: %.2f\n", votoita);
    printf("Voto Matematica: %.2f\n", votomat);
    
    // Stampo la somma dei voti
    printf("Somma dei voti: %.2f\n", somma);
    
    // Stampo la media dei voti con due decimali
    printf("La media dei voti e': %.2f\n", media);
    
    // Aggiunta di funzionalità per determinare il giudizio
    if (media >= 9) {
        printf("Eccellente!\n");
    } else if (media >= 7) {
        printf("Buono!\n");
    } else if (media >= 5) {
        printf("Sufficiente.\n");
    } else {
        printf("Insufficiente.\n");
    }

    return 0; // Termina il programma con successo
}

