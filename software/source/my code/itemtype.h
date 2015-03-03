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
 * Nama File            : itemtype.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */
 
#ifndef __ITEMTYPE_H
#define __ITEMTYPE_H
#include <iostream>
using namespace std;

class ItemType
{
    private:
        const unsigned char MaxNameLength;
        unsigned char IndeksItemType;
        char Name[MaxNameLength];
        string Description;
    public:
        ItemType();
        ~ItemType();
        ItemType(const ItemType&);
        ItemType& operator= (ItemType&);
        
        // Getter Setter
		char* GetName();
		unsigned char GetIndeks();
		string GetDesc();
        
        // Operasi lain
        void PrintDescription();
};

#endif // __ITEMTYPE_H