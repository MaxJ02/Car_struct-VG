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

    //Vtable pekare för car objekt.
    struct car_vtable* vptr;
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

void car_change_transmission(struct car* self, enum car_transmission transmission);

void car_print(FILE* stream, const struct car* self);

void car_delete(struct car* car_ptr);


void file_read(const char* filename, FILE* fp);


struct car_vtable 
{
    void (*car_change_color)(struct car*, char*);
    void (*car_change_transmission)(struct car*, enum car_transmission);
    void (*car_print)(FILE*, const struct car*);
};

struct car_vtable* car_vptr_get();

#endif /* CAR_H_ */
