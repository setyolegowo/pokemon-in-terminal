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
 * Nama File            : player.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */
 
#ifndef __PLAYER_H
#define __PLAYER_H

#include <iostream>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include "monster.h"
#include "item.h"

using namespace std;

class Player
{
    private:
		struct lItem {
			unsigned char Item;
			unsigned char nItem;
		};	
        const unsigned char MaxNameLength; //Maksimal jumlah karakter nama
        const unsigned char MaxPartyMonster; //Maksimal jumlah party monster
        unsigned int PlayerNumber; //Nomor pemain
        char *Name; //Nama pemain
        unsigned int SumOfDays; //Jumlah hari, digunakan sebagai parameter waktu
        unsigned char DayOrNight; //Menunjukkan siang atau malam
        unsigned int Money; //Jumlah uang player
        unsigned int Win; //Jumlah kemenangan player di stadium
        unsigned int Lose; //Jumlah kekalahan player di stadium
		std::list<lItem> ListPlayerItem; //List item yang dimiliki player
		std::list<unsigned char> ListPlayerMonster; //List monster yang dimiliki player
		std::list<unsigned char> ListPartyMonster; //List monster yang ada pada party player
    public:
        Player(); //ctor
        ~Player(); //dtor
        Player(const Player&); //cctor
        Player operator=(const Player&);
        void ChangeName(char*); //Mengubah nama pemain
		void ChangePlayerNumber(unsigned int); //Mengubah nomor pemain
        void AddListItem(unsigned char, unsigned char); //Menambahkan Item pada List
        void DelListItem(unsigned char, unsigned char); //Menghapus Item pada List
        void AddMonster(unsigned char); //Menambahkan Monster pada ListPlayerMonster
        void DelMonster(unsigned char); //Menghapus Monster pada ListPlayerMonster
        void IncMoney(unsigned int); //Menambahkan sejumlah uang pemain
        void DecMoney(unsigned int); //Mengurangi sejumlah uang pemain
        void ChangeParty(unsigned int, unsigned int); //Mengubah list party monster
		void AddWin(); //Menambahkan jumlah kemenangan pemain di stadium
		void AddLose(); //Menambahkan jumlah kekalahan pemain di stadium
};

#endif // __PLAYER_H