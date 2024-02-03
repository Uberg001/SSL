all: TablasDeConversion ConversionTest

TablasDeConversion: TablasDeConversion.c Conversion.c Conversion.h
	gcc -Wall -Werror -o TablasDeConversion TablasDeConversion.c Conversion.c

ConversionTest: ConversionTest.c Conversion.c Conversion.h
	gcc -Wall -Werror -o ConversionTest ConversionTest.c Conversion.c

test: ConversionTest
	./ConversionTest