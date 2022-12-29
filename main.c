#include "car.h"

/********************************************************************************
* Detta är versionen av main som använder Vtables för VG uppgiften. 
********************************************************************************/

/**************************************************************************************************************************
* main: Program som skapar 3 olika car objekt genom strukten car. Tilldelar attribut till dessa
* och placerar de sedan i strukten cars. Sedan skrivs varje bil ut för sig via anropp av funktionen
* car_print till angiven utström, i detta fall stdout. Bil 3 ändrar sedan färg och växellåda
* genom anropp av funktionerna car_change_color och car_change_transmission. Bil 3 skrivs sedan
* ut igen för att kontrollera att ändringarna verkligen sker. Sedan Öppnar och skriver till filen "cars.txt",
* om filpekaren returnerar null skrivs ett felutmeddelande ut och 1 returneras för att indikera att ett fel har skett.
* Lyckas däremot programmet öppna och skriva i filen "cars.txt så skrivs innehållet ur cars arrayen ut till filen via funktionen car_print.
* Filen cars.txt stängs och sedan skriver programmet ut innehållet från angiven fil rad för rad, i angiven utström.
*******************************************************************************************************************************/




int main(void)
{

	struct car car1;
  struct car car2;
  struct car car3;
  car_init(&car1, "Volvo", "V70", "Black", 1995, MANUAL);
  car_init(&car2, "BMW", "Z3", "Blue", 2001, AUTOMATIC);
  car_init(&car3, "Skoda", "Octavia RS", "White", 2003, MANUAL);
 
	struct car* cars[] = { &car1, &car2, &car3 };

  c.vptr->car_print(&car1, stdout);
  c.vptr->car_print(stdout, &car2);
  c.vptr->car_print(&car3, stdout);

  c.vptr->change_color(&car3, "Green")

  c.vptr->change_transmission(&c, MANUAL);  
    
	//car_change_transmission(&car3);
        
	//Skriver ut car3 igen för att kontrollera att ändringarna lyckades.
	//car_print(&car3, stdout);
  c.vptr->car_print(&car3, stdout);
	
	//Öppnar och skriver till filen "cars.txt", om filpekaren returnerar null skrivs ett felutmeddelande ut och 1 returneras för att indikera att ett fel har skett.
	FILE* fp = fopen("cars.txt", "w");
	if (fp == NULL) {
		perror("Error opening file");
		return 1;
	}

	//Här skrivs innehållet ur cars arrayen ut till filen cars.txt via funktionen car_print
	size_t i;
	for (i = 0; i < 3; i++) {
		car_print(cars[i], fp);
	}

	// Stänger filen cars.txt
	fclose(fp);

	//Skriver ut innehållet från angiven fil rad för rad, i angiven utström.
	file_read("cars.txt", stdout);

	return 0;
}
