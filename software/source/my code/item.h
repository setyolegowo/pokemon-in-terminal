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
 * Nama File            : item.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */
 
#ifndef __ITEM_H
#define __ITEM_H

#include "itemtype.h"

class Item
{
    private:
        const unsigned char MaxNameLength;
        
        unsigned int ItemNumber;
        char Name[MaxNameLength];
        ItemType Tipe;
        unsigned int Price;
        unsigned int ItemValue;
    public:
        Item();
        ~Item();
        Item(const Item&);
        Item &operator= (Item&);
		
		unsigned int GetItemNumber();
		char* GetName();
		ItemType GetTipe();
		unsigned int GetPrice();
		unsigned int GetItemValue();
};

#endif // __ITEM_H