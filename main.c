#include "car.h"

/********************************************************************************
* Detta är versionen av main som använder Vtables för VG uppgiften.
********************************************************************************/

/**************************************************************************************************************************
* main: Program som skapar 3 olika car objekt genom strukten car. Tilldelar attribut till varje bil enskilt via funktionen strcpy
* samt med hjälp av vptr som gör det möjligt att göra koden extremt tydlig. Sedan skrivs varje bil ut för sig i angiven utström
* med hjälp av en vptr till den tidigare funktionen car_print. Sedan ändrar bil 3 färg och växellåda med hjälp av vptrers som pekar
* på respektive change funktion. Sedan är koden väldigt likartad med föregående version men anpassad efter användandet av vpters.
*******************************************************************************************************************************/

int main(void)
{

	struct car car1;
	struct car car2;
	struct car car3;
	strcpy(car1.brand, "Volvo");
	strcpy(car1.model, "V70");
	strcpy(car1.color, "Black");
	car1.year_of_launch = 1995;
	car1.transmission = MANUAL;
	car1.vptr = car_vptr_get();


	strcpy(car2.brand, "BMW");
	strcpy(car2.model, "Z3");
	strcpy(car2.color, "Blue");
	car2.year_of_launch = 2001;
	car2.transmission = AUTOMATIC;
	car2.vptr = car_vptr_get();

	strcpy(car3.brand, "Skoda");
	strcpy(car3.model, "Octavia RS");
	strcpy(car3.color, "White");
	car3.year_of_launch = 2003;
	car3.transmission = MANUAL;
	car3.vptr = car_vptr_get();


	car1.vptr->car_print(stdout, &car1); 
	car2.vptr->car_print(stdout, &car2);
	car3.vptr->car_print(stdout, &car3);


	//Ändrar och Skriver ut car3 igen för att kontrollera att ändringarna lyckades.
	car3.vptr->car_change_color(&car3, "Green");
	car3.vptr->car_change_transmission(&car3, AUTOMATIC);
	car3.vptr->car_print(stdout, &car3);



	struct car* cars[] = { &car1, &car2, &car3 };


	//Öppnar och skriver till filen "cars.txt", om filpekaren returnerar null skrivs ett felutmeddelande ut och 1 returneras för att indikera att ett fel har skett.
	FILE* fp = fopen("cars.txt", "w");
	if (fp == NULL) {
		perror("Error opening file");
		return 1;
	}

	//Här skrivs innehållet ur cars arrayen ut till filen cars.txt via en vptr till funktionen car_print.
	size_t i;
	for (i = 0; i < 3; i++) {
		cars[i]->vptr->car_print(fp, cars[i]);
	}


	// Stänger filen cars.txt
	fclose(fp);

	//Läser av och skriver ut innehållet från angiven fil rad för rad, i angiven utström.
	file_read("cars.txt", stdout);
	


	return 0;
	
}
