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
 * Deskripsi            : Kelas Item 
 *                        menjelaskan tentang item yang digunakan untuk membantu 
 *						  pemain dalam pertarungan monster, misalnya menaikkan 
 *						  Max Health Point, menggunakan Ball untuk menangkap  
 *						  monster , dan lain-lain
 * 
 */
 
#ifndef __ITEM_H
#define __ITEM_H

#include <string>

class Item
{
    private:
        const unsigned char MaxNameLength;
        unsigned int ItemNumber;
        char *Name;
        int Tipe;
        unsigned int Price;
        unsigned int ItemValue;
		char *Desc;
    public:
        Item();
        ~Item();
		Item(unsigned int, char*, unsigned int, unsigned int, unsigned int, char*);
        Item(const Item&);
        Item& operator= (const Item&);
		
		unsigned int GetItemNumber();
		char* GetName();
		int GetTipe();
		unsigned int GetPrice();
		unsigned int GetItemValue();
		char* GetDesc();
		
};

#endif // __ITEM_H