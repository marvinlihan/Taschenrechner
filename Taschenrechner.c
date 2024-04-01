/* Taschenrechner */

#include <stdio.h>
#include <stdlib.h>

int main() {
    char operation;
    double zahl1;
    double zahl2;
    double zahl3;
    double zahl4;
    double summe = 0;
    double zwischen_summe;
    short int wert_scanf;
    int eingabe_liste[10];

    printf("Erste Zahl: ");
    wert_scanf = scanf("%lf", &zahl1);
    if (wert_scanf != 1)                     //scanf gibt eine 1 zurück, wenn Erfolgreich eine Eingabe gelesen wurde ("warn_unused_result")
        return printf("Fehler bei der Eingabe\n");

    eingabe_liste[0] = zahl1;

    printf("Rechenoperation wählen(+ - * / =): ");
    scanf(" %c", &operation);
    if(operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '=')
        return printf("Fehler bei der Eingabe\n");

    eingabe_liste[1] = operation;

    if(operation == '=')                      // Berechnung für 1 Eintrag
        return printf("Ergebniss: %.2lf\n", zahl1);
    
    printf("Nächste Zahl: ");
    wert_scanf = scanf("%lf", &zahl2);
    if (wert_scanf != 1)                     
        return printf("Fehler bei der Eingabe\n");

    eingabe_liste[2] = zahl2;

    printf("Rechenoperation wählen(+ - * / =): ");
    scanf(" %c", &operation);
    if(operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '=')
        return printf("Fehler bei der Eingabe\n");

    eingabe_liste[3] = operation;

    if(operation == '='){                      // Berechnung für 2 Einträge
        switch (eingabe_liste[1])
        {
        case '+':
            summe = zahl1 + zahl2;
            break;
        case '-':
            summe = zahl1 - zahl2;
            break;
        case '*':
            summe = zahl1 * zahl2;
            break;
        case '/':
            if (zahl2 != 0) {
                    summe = zahl1 / zahl2;
                } else {
                    printf("Division durch Null nicht erlaubt.\n");
                    return 0;
                }
            break;
        }
    return printf("Ergebniss: %.2lf\n", summe);
    }

    printf("Nächste Zahl: ");
    wert_scanf = scanf("%lf", &zahl3);
    if(wert_scanf != 1)                     
        return printf("Fehler bei der Eingabe\n");

    eingabe_liste[4] = zahl3;

    printf("Rechenoperation wählen(+ - * / =): ");
    scanf(" %c", &operation);
    if(operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '=')
        return printf("Fehler bei der Eingabe\n");

    eingabe_liste[5] = operation;

    if(operation == '='){                           // Berechnung für 3 Eingaben
        if(eingabe_liste[1] == eingabe_liste[3]){   
            switch (eingabe_liste[1])
            {
            case '+':
                summe = zahl1 + zahl2 + zahl3;
                break;
            case '-':
                summe = zahl1 - zahl2 - zahl3;
                break;
            case '*':
                summe = zahl1 * zahl2 * zahl3;
                break;
            case '/':
                if (zahl2 != 0 && zahl3 != 0) {
                        summe = zahl1 / zahl2 / zahl3;
                    } else {
                        printf("Division durch Null nicht erlaubt.\n");
                        return 0;
                    }
                break;
            }
        return printf("Ergebniss: %.2lf\n", summe);
        }
        for(int i = 0; i < 4;i++){                  // durchlaufe das Array, bsp. [2][+][2][*][4]
            if(eingabe_liste[i] == '*'){            // suche *
                summe = eingabe_liste[i - 1] * eingabe_liste[i + 1];    // Zahl um das * herum verrechnen [8]
                if(eingabe_liste[1] == '*'){        
                    switch (eingabe_liste[3]){
                    case '+':
                        summe += eingabe_liste[4];
                        break;
                    case '-':
                        summe -= eingabe_liste[4];
                        break;
                    case '/':
                        if(eingabe_liste[4] != 0)
                            summe /= eingabe_liste[4];
                        else{
                            printf("Division durch Null nicht erlaubt.\n");
                            return 0;
                        }
                        break;
                    }
                return printf("Ergebniss: %.2lf\n", summe);
                }
                if(eingabe_liste[3] == '*'){
                    switch (eingabe_liste[1]){      // [+]
                    case '+':
                        summe += eingabe_liste[0];  // summe = 8 + 2
                        break;
                    case '-':
                        summe -= eingabe_liste[0];
                        break;
                    case '/':
                        if(eingabe_liste[2] != 0)
                            summe /= eingabe_liste[0];
                        else{
                            printf("Division durch Null nicht erlaubt.\n");
                            return 0;
                        }
                        break;
                    }
                return printf("Ergebniss: %.2lf\n", summe);
                }
            }
            if(eingabe_liste[i] == '/'){        // gleiche Vorgehensweise, wie mit *
                if(eingabe_liste[2] != 0 && eingabe_liste[4] != 0)
                    summe = eingabe_liste[i - 1] / eingabe_liste[i + 1];
                else{
                    printf("Division durch Null nicht erlaubt.\n");
                     return 0;
                }
                if(eingabe_liste[1] == '/'){
                    switch (eingabe_liste[3])
                    {
                    case '+':
                        summe += eingabe_liste[4];
                        break;
                    case '-':
                        summe -= eingabe_liste[4];
                        break;
                    case '*':
                        summe *= eingabe_liste[4];
                        break;
                    }
                return printf("Ergebniss: %.2lf\n", summe);
                }
                if(eingabe_liste[3] == '/'){
                    switch (eingabe_liste[1])
                    {
                    case '+':
                        summe += eingabe_liste[0];
                        break;
                    case '-':
                        summe -= eingabe_liste[0];
                        break;
                    case '*':
                        summe *= eingabe_liste[0];
                        break;
                    }
                return printf("Ergebniss: %.2lf\n", summe);
                }
            }
        }
    }
        
    
    printf("Nächste Zahl: ");
    wert_scanf = scanf("%lf", &zahl4);
    if (wert_scanf != 1)                    
        return printf("Fehler bei der Eingabe\n");

    eingabe_liste[6] = zahl4;

    printf("Rechenoperation wählen(+ - * / =): =\n");       // Damit Ausgabe einheitlich aussieht
                                                            
        if(eingabe_liste[1] == eingabe_liste[3] && eingabe_liste[1] == eingabe_liste[5]){   // Berechnung für 4 Einträge
            switch (eingabe_liste[1])
            {
            case '+':
                summe = zahl1 + zahl2 + zahl3 + zahl4;
                break;
            case '-':
                summe = zahl1 - zahl2 - zahl3 - zahl4;
                break;
            case '*':
                summe = zahl1 * zahl2 * zahl3 * zahl4;
                break;
            case '/':
                if(zahl2 != 0 && zahl3 != 0 && zahl4 != 0)
                    summe = zahl1 / zahl2 / zahl3 / zahl4;
                else{
                    printf("Division durch Null nicht erlaubt.\n");
                    return 0;
                }
                break;
            }
        return printf("Ergebniss: %.2lf\n", summe);
        }
        if(eingabe_liste[1] == '*' && eingabe_liste[5] == '*'){     // wenn zweimal * vorkommt
            summe = eingabe_liste[0] * eingabe_liste[2];            // Elemente um * herum werden verrechnet 
            zwischen_summe = eingabe_liste[4] * eingabe_liste[6];
            switch (eingabe_liste[3])                               // Element was übrig bleibt wird als Operationszeichen verwendet
            {
            case '+':
                summe += zwischen_summe;
                break;
            case '-':
                summe -= zwischen_summe;
                break;
            case '/':
                if(eingabe_liste[4] != 0)
                    summe /= zwischen_summe;
                else{
                    printf("Division durch Null nicht erlaubt.\n");
                    return 0;
                }
                break;
            }
        return printf("Ergebniss: %.2lf\n", summe);
        }
        if(eingabe_liste[3] == '*' && eingabe_liste[5] == '*'){     // Berechnung für zweimal *, aber andere Position im Array
            summe = eingabe_liste[2] * eingabe_liste[4];
            summe *= eingabe_liste[6];
            switch (eingabe_liste[1])
            {
            case '+':
                summe += eingabe_liste[0];
                break;
            case '-':
                summe -= eingabe_liste[0];
                break;
            case '/':
                if(eingabe_liste[2] != 0)
                    summe /= eingabe_liste[0];
                else{
                    printf("Division durch Null nicht erlaubt.\n");
                    return 0;
                }
            }
        return printf("Ergebniss: %.2lf\n", summe);
        }
        if(eingabe_liste[1] == '*' && eingabe_liste[3] == '*'){     // Berechnung für zweimal *, aber andere Position im Array
            summe = eingabe_liste[0] * eingabe_liste[2];
            summe *= eingabe_liste[4];
            switch (eingabe_liste[5])
            {
            case '+':
                summe += eingabe_liste[6];
                break;
            case '-':
                summe -= eingabe_liste[6];
                break;
            case '/':
                if(eingabe_liste[6] != 0)
                    summe /= eingabe_liste[6];
                else{
                    printf("Division durch Null nicht erlaubt.\n");
                    return 0;
                }
            }
        return printf("Ergebniss: %.2lf\n", summe);
        }
        if(eingabe_liste[1] == '/' && eingabe_liste[5] == '/'){         // identische Vorgehensweise, wie mit *
            if(eingabe_liste[2] != 0 && eingabe_liste[6] != 0){
                summe = eingabe_liste[0] / eingabe_liste[2];
                zwischen_summe = eingabe_liste[4] / eingabe_liste[6];
                switch (eingabe_liste[3])
                {
                case '+':
                    summe += zwischen_summe;
                    break;
                case '-':
                    summe -= zwischen_summe;
                    break;
                case '*':
                    summe *= zwischen_summe;
                    break;
                }
            }
            else{
                printf("Division durch Null nicht erlaubt.\n");
                return 0;
            }
        return printf("Ergebniss: %.2lf\n", summe);
        }
        if(eingabe_liste[3] == '/' && eingabe_liste[5] == '/'){
            if(eingabe_liste[4] != 0 && eingabe_liste[6] != 0){
                summe = eingabe_liste[2] / eingabe_liste[4];
                summe /= eingabe_liste[6];
                switch (eingabe_liste[1])
                {
                case '+':
                    summe += eingabe_liste[0];
                    break;
                case '-':
                    summe -= eingabe_liste[0];
                    break;
                case '*':
                    summe *= eingabe_liste[0];
                    break;
                }
            }
            else{
                printf("Division durch Null nicht erlaubt.\n");
                return 0;
            }
        return printf("Ergebniss: %.2lf\n", summe);
        }
        if(eingabe_liste[1] == '/' && eingabe_liste[3] == '/'){
            if(eingabe_liste[2] != 0 && eingabe_liste[4] != 0){
                summe = eingabe_liste[0] / eingabe_liste[2];
                summe /= eingabe_liste[4];
                switch (eingabe_liste[5])
                {
                case '+':
                    summe += eingabe_liste[6];
                    break;
                case '-':
                    summe -= eingabe_liste[6];
                    break;
                case '*':
                    summe *= eingabe_liste[6];
                    break;
                }
            }
            else{
                printf("Division durch Null nicht erlaubt.\n");
                return 0;
            }
        return printf("Ergebniss: %.2lf\n", summe);
        }
        for(int i = 0; i < 6;i++){                      // Berechnung wenn nur ein * vorkommt
            if(eingabe_liste[i] == '*'){
                summe = eingabe_liste[i - 1] * eingabe_liste[i + 1];        // Elemente um * herum verrechnen
                if(eingabe_liste[1] == '*' && eingabe_liste[5] != '/' && eingabe_liste[3] != '/'){  // '/' wird Seperat betrachtet
                    switch (eingabe_liste[3])
                    {
                    case '+':
                        summe += eingabe_liste[4];
                        break;
                    case '-':
                        summe -= eingabe_liste[4];
                        break;
                    }
                    switch (eingabe_liste[5])
                    {
                    case '+':
                        summe += eingabe_liste[6];
                        break;
                    case '-':
                        summe -= eingabe_liste[6];
                        break;
                    }
                return printf("Ergebniss: %.2lf\n", summe);
                }
                if(eingabe_liste[3] == '*' && eingabe_liste[1] != '/' && eingabe_liste[5] != '/'){
                    switch (eingabe_liste[1])
                    {
                    case '+':
                        summe += eingabe_liste[0];
                        break;
                    case '-':
                        summe = eingabe_liste[0] - summe;
                        break;
                    }
                    switch (eingabe_liste[5])
                    {
                    case '+':
                        summe += eingabe_liste[6];
                        break;
                    case '-':
                        summe -= eingabe_liste[6];
                        break;
                    }
                return printf("Ergebniss: %.2lf\n", summe);
                }
                if(eingabe_liste[5] == '*' && eingabe_liste[1] != '/' && eingabe_liste[3] != '/'){
                    switch (eingabe_liste[3])
                    {
                    case '+':
                        summe += eingabe_liste[2];
                        break;
                    case '-':
                        summe = eingabe_liste[2] - summe;
                        break;
                    }
                    switch (eingabe_liste[1])
                    {
                    case '+':
                        summe += eingabe_liste[0];
                        break;
                    case '-':
                        summe -= eingabe_liste[0];
                        break;
                    }
                return printf("Ergebniss: %.2lf\n", summe);
                }
            }
            if(eingabe_liste[i] == '/'){                // '/' Zeichen in der Eingabe suchen
                if(eingabe_liste[i + 1] != 0){
                    summe = eingabe_liste[i - 1] / eingabe_liste[i + 1];       // Elemente um '/' miteinander verrechnen
                    if(eingabe_liste[1] == '/' && eingabe_liste[3] != '*' && eingabe_liste[5] != '*'){      // Option zweimal * wurde schon betrachtet
                        switch (eingabe_liste[3])
                        {
                        case '+':
                            summe += eingabe_liste[4];
                            break;
                        case '-':
                            summe -= eingabe_liste[4];
                            break;
                        }
                        switch (eingabe_liste[5])
                        {
                        case '+':
                            summe += eingabe_liste[6];
                            break;
                        case '-':
                            summe -= eingabe_liste[6];
                            break;
                        }
                    return printf("Ergebniss: %.2lf\n", summe);
                    }
                    if(eingabe_liste[3] == '/' && eingabe_liste[1] != '*' && eingabe_liste[5] != '*'){
                        switch (eingabe_liste[1])
                        {
                        case '+':
                            summe += eingabe_liste[0];
                            break;
                        case '-':
                            summe = eingabe_liste[4] - summe;
                            break;
                        }
                        switch (eingabe_liste[5])
                        {
                        case '+':
                            summe += eingabe_liste[6];
                            break;
                        case '-':
                            summe -= eingabe_liste[6];
                            break;
                        }
                    return printf("Ergebniss: %.2lf\n", summe);
                    }
                    if(eingabe_liste[5] == '/' && eingabe_liste[1] != '*' && eingabe_liste[3] != '/'){
                        switch (eingabe_liste[3])
                        {
                        case '+':
                            summe += eingabe_liste[4];
                            break;
                        case '-':
                            summe -= eingabe_liste[4];
                            break;
                        }
                        switch (eingabe_liste[5])
                        {
                        case '+':
                            summe += eingabe_liste[6];
                            break;
                        case '-':
                            summe -= eingabe_liste[6];
                            break;
                        }
                    return printf("Ergebniss: %.2lf\n", summe);
                    }
                }
                else{
                    printf("Division durch Null nicht erlaubt.\n");
                    return 0;
                }
            }
            if(eingabe_liste[1] == '*' && eingabe_liste[3] == '/'){     // Berechnung wenn Eingabe ein * Zeichen hat und ein / Zeichen hat, aufgrund von Punkt vor Strich muss jede Option einzelnd betrachtet werden
                summe = eingabe_liste[0] * eingabe_liste[2];
                if(eingabe_liste[4] != 0){
                    summe /= eingabe_liste[4];
                    switch (eingabe_liste[5])
                    {
                    case '+':
                        summe += eingabe_liste[6];
                        break;
                    case '-':
                        summe -= eingabe_liste[6];
                        break;
                    }
                return printf("Ergebniss: %.2lf\n", summe);
                }
                else{
                    printf("Division durch Null nicht erlaubt.\n");
                    return 0;
                }
            }
            if(eingabe_liste[1] == '/' && eingabe_liste[3] == '*'){
                if(eingabe_liste[2] != 0){
                    summe = eingabe_liste[0] / eingabe_liste[2];
                        summe *= eingabe_liste[4];
                        switch (eingabe_liste[5])
                        {
                        case '+':
                            summe += eingabe_liste[6];
                            break;
                        case '-':
                            summe -= eingabe_liste[6];
                            break;
                        }
                    return printf("Ergebniss: %.2lf\n", summe); 
                }
                else{
                    printf("Division durch Null nicht erlaubt.\n");
                    return 0;
                }
            }
            if(eingabe_liste[3] == '*' && eingabe_liste[5] == '/'){
                summe = eingabe_liste[2] * eingabe_liste[4];
                if(eingabe_liste[6] != 0){
                    summe /= eingabe_liste[6];
                    switch (eingabe_liste[1])
                    {
                    case '+':
                        summe += eingabe_liste[0];
                        break;
                    case '-':
                        summe = eingabe_liste[0] - summe;
                        break;
                    }
                return printf("Ergebniss: %.2lf\n", summe);
                }
                else{
                    printf("Division durch Null nicht erlaubt.\n");
                    return 0;
                }
            }
            if(eingabe_liste[3] == '/' && eingabe_liste[5] == '*'){
                if(eingabe_liste[4] != 0){
                    summe = eingabe_liste[2] / eingabe_liste[4];
                        summe *= eingabe_liste[6];
                        switch (eingabe_liste[1])
                        {
                        case '+':
                            summe += eingabe_liste[0];
                            break;
                        case '-':
                            summe = eingabe_liste[0] - summe;
                            break;
                        }
                    return printf("Ergebniss: %.2lf\n", summe); 
                }
                else{
                    printf("Division durch Null nicht erlaubt.\n");
                    return 0;
                }
            }
            if(eingabe_liste[5] == '*' && eingabe_liste[1] == '/'){
                if(eingabe_liste[2] != 0){
                    summe = eingabe_liste[0] / eingabe_liste[2];
                    zwischen_summe = eingabe_liste[4] * eingabe_liste[6];
                        switch (eingabe_liste[3])
                        {
                        case '+':
                            summe += zwischen_summe;
                            break;
                        case '-':
                            summe -= zwischen_summe;
                            break;
                        }
                    return printf("Ergebniss: %.2lf\n", summe); 
                }
                else{
                    printf("Division durch Null nicht erlaubt.\n");
                    return 0;
                }
            }
            if(eingabe_liste[5] == '/' && eingabe_liste[1] == '*'){
                    summe = eingabe_liste[0] * eingabe_liste[2];
                    if(eingabe_liste[6] != 0){
                        zwischen_summe = eingabe_liste[4] / eingabe_liste[6];
                            switch (eingabe_liste[3])
                            {
                            case '+':
                                summe += zwischen_summe;
                                break;
                            case '-':
                                summe -= zwischen_summe;
                                break;
                            }
                        return printf("Ergebniss: %.2lf\n", summe); 
                }
                else{
                    printf("Division durch Null nicht erlaubt.\n");
                    return 0;
                }
            }
        }
}