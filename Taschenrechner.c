#include <stdio.h>

double potenz(double basis, double exponent){   // Potenz Funktion
    double summe = 1;
    for(int i = 0; i < exponent; i++){
        summe *= basis;          
    }
    return summe;
}

double fakultät(double summe){  // Fakultät berechnen, noch nicht 100% richtig z.b.(5! - 5! != 0)
    if(summe < 1)
        return 1;
    else
    return summe *fakultät(summe - 1);
}

int main() {
    char operation;
    double zahl;
    double summe = 0;

    printf("Erste Zahl: ");
    scanf("%lf", &summe);

    while (1) { // Endlosschleife, 1 = true -> Endlosschleife, damit Benutzer endloss viele Rechnungen machen kann
        printf("Rechenoperation wählen(+ - * / = ^ !): ");
        scanf(" %c", &operation); // Beachte das Leerzeichen vor %c, um Whitespaces zu überspringen

        if (operation == '!') { //Fakultät berechnen
            summe = fakultät(summe);   
            printf("Rechenoperation wählen(+ - * / = ^ !): ");  // Operation wählen nach der Fakultät, um weiter zu rechnen, oder abzubrechen(=)
            scanf(" %c", &operation);
        }

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
            case '^':
                summe = potenz(summe, zahl);
                break;
            default:
                printf("%c ist nicht verfügbar\n", operation);
                break;
        }
    }

    return 0;
}