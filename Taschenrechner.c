#include <stdio.h>

int main() {
    char operation;
    double zahl;
    double summe = 0;

    printf("Erste Zahl: ");
    scanf("%lf", &summe);

    while (1) { // Endlosschleife, 1 = true -> Endlosschleife
        printf("Rechenoperation wählen(+ - * / =): ");
        scanf(" %c", &operation); // Beachte das Leerzeichen vor %c, um Whitespaces zu überspringen

        if (operation == '=') { // Abbruch, wenn Benutzer '=' wählt
            printf("Ergebniss: %.2lf\n", summe);
            break;
        }

        printf("Nächste Zahl: ");
        scanf("%lf", &zahl);

        switch (operation) { // Berechnung basierend auf der gewählten Operation
            case '+':
                summe += zahl;
                break;
            case '-':
                summe -= zahl;
                break;
            case '*':
                summe *= zahl;
                break;
            case '/':
                if (zahl != 0) {
                    summe /= zahl;
                } else {
                    printf("Division durch Null nicht erlaubt.\n");
                    return 0;
                }
                break;
            default:
                printf("%c ist nicht verfügbar\n", operation);
                break;
        }
    }

    return 0;
}