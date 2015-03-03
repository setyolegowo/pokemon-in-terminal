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
 * Nama File            : listofitem.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : Kelas ListOfItem 
 *						  Kelas ini digunakan untuk menampung daftar item ke 
 *						  dalam suatu list dan menampilkan list atau daftar 
 *						  item yang dimiliki.
 */
 
 
#ifndef __LISTOFITEM_H
#define __LISTOFITEM_H

#include <list>
#include <iostream>
#include "item.h"

using std::list;

class ListOfItem
{
    public:
		// Item *tabelItem;
        ListOfItem();
        ~ListOfItem();
        ListOfItem(const ListOfItem&);
        ListOfItem& operator= (ListOfItem&);
        void ReadFromFile();
		int GetNItem();
		int IsOnTable(char *);
		void PrintListItem();
		void PrintName(int);
		void PrintPrice(int);
		int GetPrice(int);
        int GetValue(int);
		void PrintDescription(int);
		list<Item> tblItem;
	private :
		const unsigned short MaxItemList;
		int nItem;
		
};

#endif // __LISTOFITEM_H