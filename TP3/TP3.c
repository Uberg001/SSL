#include <stdio.h>
#include <stdbool.h>

bool esIdentificador(char* lexema){
      int tabla_transiciones[4][3] = {
        // a-zA-Z   a-zA-Z0-9_   Otros
        {1, -1, -1},  // Estado 0
        {1, 2, -1},   // Estado 1
        {2, 2, -1},   // Estado 2
        {-1, -1, -1}  // Estado de rechazo
    };

    int estado_actual = 0;
    int i = 0;

    while (lexema[i] != '\0') {
        char caracter = lexema[i];
        int tipo_caracter;

        // Obtener el tipo de carácter (a-zA-Z, a-zA-Z0-9_, otros)
        if ((caracter >= 'a' && caracter <= 'z') || (caracter >= 'A' && caracter <= 'Z')) {
            tipo_caracter = 0; // Letra (a-zA-Z)
        } else if ((caracter >= '0' && caracter <= '9') || caracter == '_') {
            tipo_caracter = 1; // Número (a-zA-Z0-9_)
        } else {
            tipo_caracter = 2; // Otros
        }

        estado_actual = tabla_transiciones[estado_actual][tipo_caracter];
        if (estado_actual == -1)
            return false; 
        i++;
    }

    // El lexema es aceptado si termina en uno de los estados de aceptación: 1 o 2
    return estado_actual == 1 || estado_actual == 2;
}

bool esPalabraClave(char* lexema){
    int tabla_transiciones[15][14] = {
        //  s  |  i  |  c  |  t  |  a  |  d  |  m  |  o  |  n  |  e  |  r  |  g  |  u  |  l  |
        {  1,  -1,   5,   6,   9,  -1,  11,  -1,  -1,  13,  -1,  -1,  14,  -1}, // Estado 0
        { -1,   2,   5,  -1,  -1,  -1,  -1,   3,  -1,  -1,  -1,   7,  -1,  -1}, // Estado 1
        { -1,  -1,   5,  -1,  -1,  -1,  -1,   4,  -1,  -1,  -1,  -1,  -1,  -1}, // Estado 2
        { -1,  -1,   5,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // Estado 3
        { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // Estado 4 (Rechazo)
        { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // Estado 5 (Rechazo)
        { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // Estado 6 (Rechazo)
        { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // Estado 7 (Rechazo)
        { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // Estado 8 (Rechazo)
        { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // Estado 9 (Rechazo)
        { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // Estado 10 (Rechazo)
        { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   7,  -1,  -1}, // Estado 11
        { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   8,  -1,  -1,  -1}, // Estado 12
        { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   10, -1,  -1,  -1,  -1,   12}, // Estado 13
        { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // Estado 14
    };

    int estado_actual = 0;
    int i = 0;

    while (lexema[i] != '\0') {
        char caracter = lexema[i];
        int tipo_caracter;

        switch (caracter) {
            case 's': tipo_caracter = 0; break;
            case 'i': tipo_caracter = 1; break;
            case 'c': tipo_caracter = 2; break;
            case 't': tipo_caracter = 3; break;
            case 'a': tipo_caracter = 4; break;
            case 'd': tipo_caracter = 5; break;
            case 'm': tipo_caracter = 6; break;
            case 'o': tipo_caracter = 7; break;
            case 'n': tipo_caracter = 8; break;
            case 'e': tipo_caracter = 9; break;
            case 'r': tipo_caracter = 10; break;
            case 'g': tipo_caracter = 11; break;
            case 'u': tipo_caracter = 12; break;
            case 'l': tipo_caracter = 13; break;
            default:  return false; 
        }

        estado_actual = tabla_transiciones[estado_actual][tipo_caracter];
        if (estado_actual == -1)
            return false; 
        i++;
    }

    return estado_actual >= 5 && estado_actual <= 13;
}

bool esOperador(char* lexema){
    int tabla_transiciones[11][10] = {
        //   +  |   -  |   *  |   /  |   ^  |   =  |   <  |   >  |  <=  |  >=
        {   1,   2,   3,   4,   5,   6,   7,   8,   9,  10}, // Estado 0
        {   1,   1,   1,   1,   1, -1, -1, -1, -1, -1}, // Estado 1
        {   1,   1,   1,   1,   1, -1, -1, -1, -1, -1}, // Estado 2
        {   1,   1,   1,   1,   1, -1, -1, -1, -1, -1}, // Estado 3
        {  -1,  -1,  -1,  -1,  -1,   5,   7,   8, -1, -1}, // Estado 4
        {  -1,  -1,  -1,  -1,  -1,   6, -1, -1, -1, -1}, // Estado 5
        {  -1,  -1,  -1,  -1,  -1, -1, -1, -1, -1, -1}, // Estado 6
        {  -1,  -1,  -1,  -1,  -1, -1, -1, -1,   8, -1}, // Estado 7
        {  -1,  -1,  -1,  -1,  -1, -1, -1, -1, -1,   9}, // Estado 8
        {  -1,  -1,  -1,  -1,  -1, -1, -1, -1, -1, -1}, // Estado 9 (Rechazo)
        {  -1,  -1,  -1,  -1,  -1, -1, -1, -1, -1, -1}, // Estado 10 (Rechazo)
    };

    int estado_actual = 0;
    int i = 0;

    while (lexema[i] != '\0') {
        char caracter = lexema[i];
        int tipo_caracter;

        switch (caracter) {
            case '+': tipo_caracter = 0; break;
            case '-': tipo_caracter = 1; break;
            case '*': tipo_caracter = 2; break;
            case '/': tipo_caracter = 3; break;
            case '^': tipo_caracter = 4; break;
            case '=': tipo_caracter = 5; break;
            case '<': tipo_caracter = 6; break;
            case '>': tipo_caracter = 7; break;
            case '<=': tipo_caracter = 8; break;
            case '>=': tipo_caracter = 9; break;
            default:  return false; 
        }

        estado_actual = tabla_transiciones[estado_actual][tipo_caracter];
        if (estado_actual == -1)
            return false; 
        i++;
    }

    return estado_actual >= 1 && estado_actual <= 4;
}

bool esDelimitador(char* lexema){
    int tabla_transiciones[12][12] = {
        //   ;  |  |  |  ,  |  :  |  (  |  )  |  =  | ->  |  [  |  ]  |  =>
        {  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11}, // Estado 0
        { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, // Estado 1 
        { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, // Estado 2 
        { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, // Estado 3 
        { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, // Estado 4 
        { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, // Estado 5 
        { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, // Estado 6 
        { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, // Estado 7 
        { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, // Estado 8 
        { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, // Estado 9 
        { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, // Estado 10 
        { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, // Estado 11 
    };

    int estado_actual = 0;
    int i = 0;

    while (lexema[i] != '\0') {
        char caracter = lexema[i];
        int tipo_caracter;

        switch (caracter) {
            case ';': tipo_caracter = 0; break;
            case '|': tipo_caracter = 1; break;
            case ',': tipo_caracter = 2; break;
            case ':': tipo_caracter = 3; break;
            case '(': tipo_caracter = 4; break;
            case ')': tipo_caracter = 5; break;
            case '=': tipo_caracter = 6; break;
            case '->': tipo_caracter = 7; break;
            case '[': tipo_caracter = 8; break;
            case ']': tipo_caracter = 9; break;
            case '=>': tipo_caracter = 10; break;
            default:  return false; 
        }

        estado_actual = tabla_transiciones[estado_actual][tipo_caracter];
        if (estado_actual == -1)
            return false; 
        i++;
    }

    return estado_actual >= 1 && estado_actual <= 11;
}

bool esLiteral(char* lexema){
    int tabla_transiciones[14][8] = {
        //   +  |   -  |  0  |  1-9 |  ,  |   /   |   A-F   |   B-F
        {   1,   1,   2,    3, -1,   -1,     10,     -1}, // Estado 0
        {  -1,  -1,   2,    3,   4,     9,     10,       9}, // Estado 1
        {  -1,  -1,  -1,   -1, -1,    11,     -1,     -1}, // Estado 2
        {  -1,  -1,   3,    3,   5,     8,     -1,     -1}, // Estado 3
        {  -1,  -1,   5,    5, -1,   -1,     -1,     -1}, // Estado 4
        {  -1,  -1,   5,    5,   6,   -1,     -1,     -1}, // Estado 5
        {  -1,  -1,   7,    7,   -1,   -1,     -1,     -1}, // Estado 6
        {   12,  12,   8,    8,   -1,   -1,     -1,     -1}, // Estado 7
        {   12,  12,   8,    8,   -1,   -1,     -1,     -1}, // Estado 8
        {  -1,  -1,   5,    5,   -1,   -1,     -1,     -1}, // Estado 9
        {   12,  12,   2,    3,   -1,   -1,     -1,     -1}, // Estado 10
        {  -1,  -1,  -1,   -1,   4,   -1,     -1,     -1}, // Estado 11
        {   12,  12,  -1,   -1,   4,   -1,     13,     -1}, // Estado 12
        {  -1,  -1,  -1,   -1,   4,   -1,     -1,     -1}, // Estado 13
    };

    int estado_actual = 0;
    int i = 0;

    while (lexema[i] != '\0') {
        char caracter = lexema[i];
        int tipo_caracter;

        switch (caracter) {
            case '+': tipo_caracter = 0; break;
            case '-': tipo_caracter = 1; break;
            case '0': tipo_caracter = 2; break;
            case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                tipo_caracter = 3; break;
            case ',': tipo_caracter = 4; break;
            case '/': tipo_caracter = 5; break;
            case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
                tipo_caracter = 6; break;
            default:  return false;
        }

        estado_actual = tabla_transiciones[estado_actual][tipo_caracter];
        if (estado_actual == -1)
            return false; 
        i++;
    }

    return estado_actual == 2 || estado_actual == 3 || estado_actual == 5 || estado_actual == 6 ||
           estado_actual == 7 || estado_actual == 8 || estado_actual == 10 || estado_actual == 12 ||
           estado_actual == 13;
} 

int main(){
    char lexema[100];
    printf("Ingrese una cadena: ");
    scanf("%s", lexema);

    //Check Identificadores
    if (esIdentificador(lexema))
        printf("El lexema es aceptado por el LR de identificadores. \n");
    else
        printf("El lexema no es aceptado por el LR de identificadores. \n");
    //Check PalabraClave
    if (esPalabraClave(lexema))
        printf("El lexema es aceptado por el LR de PalabraClave. \n");
    else
        printf("El lexema no es aceptado por el LR de PalabraClave. \n");
    //Check Operador
    if (esOperador(lexema))
        printf("El lexema es aceptado por el LR de Operadores. \n");
    else
        printf("El lexema no es aceptado por el LR de Operadores. \n");
    //Check Delimitador
    if (esDelimitador(lexema))
        printf("El lexema es aceptado por el LR de delimitadores. \n");
    else
        printf("El lexema no es aceptado por el LR de delimitadores. \n");
    //Check Literal
    if (esLiteral(lexema))
        printf("El lexema es aceptado por el LR de literales. \n");
    else
        printf("El lexema no es aceptado por el LR de literales. \n");

    return 0;
}