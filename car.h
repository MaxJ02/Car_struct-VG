#ifndef HEADER_H_
#define HEADER_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum car_transmission
{
    MANUAL,
    AUTOMATIC
};

struct car
{
    char brand[20];
    char model[20];
    char color[20];
    unsigned int year_of_launch;
    enum car_transmission transmission;

    // Funktionspekare enligt uppgift 2
    void (*change_color)(struct car*, const char*);
    void (*change_transmission)(struct car*, enum car_transmission);
    void (*car_print)(FILE*, const struct car*);


    //Vtable pekare för car objekt.
    const struct car_vtable* vptr;
};

void car_init(struct car* self,
    const char* brand,
    const char* model,
    const char* color,
    unsigned int year_of_launch,
    enum car_transmission transmission);

void car_clear(struct car* c);

struct car* car_new(const char* brand,
    const char* model,
    const char* color,
    unsigned int year_of_launch,
    enum car_transmission transmission);

void car_change_color(struct car* car, const char* color);

void car_change_transmission(struct car* self);

void car_print(struct car* self, FILE* stream);

void car_delete(struct car* car_ptr);


void file_read(const char* filename);

struct car_vtable 
{
  void (*change_color)(struct car*, const char*);
  void (*change_transmission)(struct car*, enum car_transmission);
  void (*car_print)(FILE*, const struct car*);
};

#endif /* CAR_H_ */
