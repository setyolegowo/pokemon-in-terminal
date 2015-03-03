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
 * Nama File            : listofitem.cpp
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */
 
#ifndef __LIST_ITEM_PLAYER_H
#define __LIST_ITEM_PLAYER_H

#include <list>
#include <iostream>
#include "listofitem.h"

using std::list;
using std::string;

typedef struct {
	int No;
	int Quantity;
} DataItem;

class ListItemOfPlayer
{
	
    public:
		// Item *tabelItem;
        ListItemOfPlayer();
        ~ListItemOfPlayer();
        ListItemOfPlayer(const ListItemOfPlayer&);
        ListItemOfPlayer& operator= (ListItemOfPlayer&);
		void ReadFromFile();
		void PrintListItemPlayer();
	private :
        list<DataItem> tabelItemPlayer;
		int nItemPlayer;
		ListOfItem ListItem;

		
};

#endif // __LISTOFITEM_H