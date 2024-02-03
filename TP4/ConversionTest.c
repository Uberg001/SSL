#include <stdio.h>
#include <assert.h>
#include "Conversion.h"

int main() {
    // Pruebas de Celsius a Fahrenheit
    assert(celsiusAFahrenheit(0) == 32);
    assert(celsiusAFahrenheit(100) == 212);
    
    // Pruebas de Fahrenheit a Celsius
    assert(fahrenheitACelsius(32) == 0);
    assert(fahrenheitACelsius(212) == 100);
    
    printf("Todos los tests pasaron\n");
    return 0;
}