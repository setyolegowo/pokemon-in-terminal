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
 * Nama File            : store.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */

#ifndef __STORE_H
#define __STORE_H

#include "point.h" 


class Store
{
    private:
        Point TeleportPosition;
    public:
        Store();
        ~Store();
        Store(const Store&);
        Store& operator= (Store&);
        void PrintImage();
        unsigned short Buy(unsigned short);
        unsigned short Sell(unsigned short);
};

// __STORE_H
#endif 
