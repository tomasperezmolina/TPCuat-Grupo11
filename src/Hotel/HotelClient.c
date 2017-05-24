#include "HotelClient.h"
#include <malloc.h>
#include <memory.h>

HotelClient* newHotelClient(char* name, char* surname, int DNI){
    HotelClient* result = malloc(sizeof(HotelClient));
    result->DNI = DNI;
    result->name = malloc(sizeof(char)*strlen(name) + 1);
    strcpy(result->name, name);
    result->surname = malloc(sizeof(char)*strlen(surname) + 1);
    strcpy(result->surname, surname);

    return result;
}
void destroyHotelClient(HotelClient* client){
    free(client->name);
    free(client->surname);
    free(client);
}