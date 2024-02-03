#include "Conversion.h"

double celsiusAFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double fahrenheitACelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}