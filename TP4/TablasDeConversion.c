#include <stdio.h>
#include "Conversion.h"

int main() {
    double celsius, fahrenheit;

    printf("Tabla de conversión de Celsius a Fahrenheit\n");
    printf("Celsius\tFahrenheit\n");
    for (celsius = 0; celsius <= 100; celsius += 10) {
        fahrenheit = celsiusAFahrenheit(celsius);
        printf("%.2f\t%.2f\n", celsius, fahrenheit);
    }

    printf("\nTabla de conversión de Fahrenheit a Celsius\n");
    printf("Fahrenheit\tCelsius\n");
    for (fahrenheit = 32; fahrenheit <= 212; fahrenheit += 20) {
        celsius = fahrenheitACelsius(fahrenheit);
        printf("%.2f\t%.2f\n", fahrenheit, celsius);
    }

    return 0;
}