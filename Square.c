#include <stdio.h>
#include <math.h>  // per la funzione sqrt()

int main() {
    double numero;

    printf("Inserisci un numero positivo per calcolare la sua radice quadrata: ");
    scanf("%lf", &numero);

    if (numero < 0) {
        printf("Errore! Il numero deve essere positivo.\n");
    } else {
        float radice = sqrt(numero);
        printf("La radice quadrata di %.2f e' : %.2f\n", numero, radice);
    }

    return 0;
}

