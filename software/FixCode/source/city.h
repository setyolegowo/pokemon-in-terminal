/* ************************************************************************** */
/*                                  POKERANCH                                 */
/* ************************************************************************** */

/*
 * Nama / NIM           : Lubis Sucipto / 13511025
 *                        Muhammad Rizky W / 13511037
 *                        Andreas Dwi Nugroho / 13511051
 *                        Setyo Legowo / 13511071
 *                        Fawwaz Muhammad / 13511083
 *                        Asep Saepudin / 13511093
 * Nama File            : city.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */
 
#ifndef __CITY_H
#define __CITY_H

#include "area.h"
#include "point.h"
#include "home.h"
#include "store.h"
#include "combinatorium.h"
#include "stadium.h"

class City:public Area
{
    private:
        const unsigned char MaxNameLength;
        const unsigned char NBuilding;
        
        char *NamaCity;
        Point *TeleportPosition;
        Home home;
        Store store;
        Combinatorium combinatorium;
        Stadium stadium;
    public:
        City();
        ~City();
        City(const City&);
        City &operator= (City&);

        
        void FixUnstapableArea();
        void PrintBuilding(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,bool);
        //Print the building 
        //Parameter 1 : Offset X from left started with 0 like array in C
        //Parameter 2 : Offset Y from top  started with 0 like array in C
        //Parameter 3 : Width of the building
        //Parameter 4 : Height of the building
        //Parameter 5 : Type of building (0 means clear area), 1 means unstapabel area, 2 means monster
        //              3 means man, 4 means gate
        //Parameter 6 : Identify is the print method fill out the entire square 
        //This function automatically set the inside of square by 0;


        unsigned char ValidTeleport();
        // Mengembalikan true jika koordinat player saat ini sah untuk melakukan teleport
        // TIDAK PERLU TAHU 

        void DoTeleport(int);
        // PANGGIL AJA YANG INI GAK PERLU YANG ATAS karean ini udah include teleport dan validat
        // parameter destination value :
        // 5 teleport ke combinatrium
        // 4 teleport ke home
        // 6 teleport ke stadium
        // 7 teleport ke store


        // virtual void PrintMap();
};

#endif // __CITY_H