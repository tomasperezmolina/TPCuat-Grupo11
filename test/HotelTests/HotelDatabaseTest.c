#include <wchar.h>
#include "../CUTest/CuTest.h"
#include "../../src/Hotel/HotelDatabase.h"

void TestAdd(CuTest* tc){

    HotelDatabase* hotelDatabase = newHotelDatabase(1, "Vista");

    char* Alfonso = "Alfonso";
    char* Ravera = "Ravera";
    char* Roberta = "Roberta";
    char* Caballero = "Caballero";
    char* Ricardo = "Ricardo";

    HotelClient* client1 = newHotelClient(Alfonso,Ravera, 420);
    HotelClient* client2 = newHotelClient(Roberta,Caballero, 65);
    HotelClient* client3 = newHotelClient(Ricardo, Ricardo, 666);

    addClient(hotelDatabase, client1);
    addClient(hotelDatabase, client2);
    addClient(hotelDatabase, client3);

    CuAssertIntEquals(tc, 0, client1->clientID);
    CuAssertIntEquals(tc, 1, client2->clientID);
    CuAssertIntEquals(tc, 2, client3->clientID);
    CuAssertIntEquals(tc, 3, hotelDatabase->clientAmount);

    destroyHotelClient(client1);
    destroyHotelClient(client2);
    destroyHotelClient(client3);

    Room* room1 = newRoom(DELUXE, 500);
    Room* room2 = newRoom(SINGLE, 200);
    Room* room3 = newRoom(MASTER, 990);

    addRoom(hotelDatabase, room1);
    addRoom(hotelDatabase, room2);
    addRoom(hotelDatabase, room3);

    CuAssertIntEquals(tc, 0, room1->number);
    CuAssertIntEquals(tc, 1, room2->number);
    CuAssertIntEquals(tc, 2, room3->number);
    CuAssertIntEquals(tc, 3, hotelDatabase->roomAmount);

    destroyRoom(room1);
    destroyRoom(room2);
    destroyRoom(room3);

    HotelInvoice* invoice1 = newHotelInvoice("dadadsa", 15, 6000, 5, 2);
    HotelInvoice* invoice2 = newHotelInvoice("dacxz", 12, 1023, 5, 2);
    HotelInvoice* invoice3 = newHotelInvoice("xcvdfgd", 68, 1000006, 2, 7);

    addInvoice(hotelDatabase, invoice1);
    addInvoice(hotelDatabase, invoice2);
    addInvoice(hotelDatabase, invoice3);

    CuAssertIntEquals(tc, 0, invoice1->invoiceID);
    CuAssertIntEquals(tc, 1, invoice2->invoiceID);
    CuAssertIntEquals(tc, 2, invoice3->invoiceID);
    CuAssertIntEquals(tc, 3, hotelDatabase->invoiceAmount);
}

void TestRemove(CuTest* tc){
    HotelDatabase* hotelDatabase = newHotelDatabase(1, "Vista");

    HotelClient* client1 = newHotelClient("Alfonso","Ravera", 420);
    HotelClient* client2 = newHotelClient("Roberta","Caballero", 65);

    addClient(hotelDatabase, client1);
    addClient(hotelDatabase, client2);



    Room* room1 = newRoom(DELUXE, 500);
    Room* room2 = newRoom(SINGLE, 200);

    addRoom(hotelDatabase, room1);
    addRoom(hotelDatabase, room2);

    HotelInvoice* invoice1 = newHotelInvoice("dadadsa", 15, 6000, 5, 2);
    HotelInvoice* invoice2 = newHotelInvoice("dacxz", 12, 1023, 5, 2);

    addInvoice(hotelDatabase, invoice1);
    addInvoice(hotelDatabase, invoice2);
}

CuSuite* getHotelDatabaseTestSuite(){
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestAdd);
    SUITE_ADD_TEST(suite, TestRemove);
    return suite;
}