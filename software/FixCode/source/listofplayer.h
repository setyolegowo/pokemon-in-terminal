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
 * Nama File            : listofplayer.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */

#ifndef __LISTOFPLAYER_H
#define __LISTOFPLAYER_H

#include <list>
#include <string>
#include "listofplayer.h"
#include "player.h"

using std::list;
using std::string;

class ListOfPlayer
{
    private:
        list<string> tabelPlayer;
    public:
        ListOfPlayer();
        ~ListOfPlayer();
        ListOfPlayer(const ListOfPlayer&);
        ListOfPlayer &operator=(ListOfPlayer&);
        bool IsOnTable(char *);
        void ReadFromFile();
        void SavePlayer(Player&);
        void ReadPlayer(Player *, char *);
        void MakePlayer(Player *, char *);
        void PrintPlayerRegistered();		
};

#endif // __LISTOFPLAYER_H