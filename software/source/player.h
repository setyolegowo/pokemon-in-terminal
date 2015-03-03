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
#include "playerofmonster.h"
#include "listofitem.h"
#include "listofskill.h"
#include "listofmonster.h"
//#include "item.h"

using namespace std;

struct lItem{
    unsigned int noItem; //jumlah item
    unsigned char nItem; //nama item
};
class Player
{
    private:
        const unsigned char MaxNameLength; //Maksimal jumlah karakter nama
        const unsigned char MaxPartyMonster; //Maksimal jumlah party monster
        unsigned int PlayerNumber; //Nomor pemain
        char *Name; //Nama pemain
        unsigned int SumOfDays; //Jumlah hari, digunakan sebagai parameter waktu
        unsigned char DayOrNight; //Menunjukkan siang (0) atau malam (1)
        unsigned int Money; //Jumlah uang player
        unsigned int Win; //Jumlah kemenangan player di stadium
        unsigned int Lose; //Jumlah kekalahan player di stadium
		std::list<lItem> ListPlayerItem; //List item yang dimiliki player
		std::list<PlayerMonster> ListPlayerMonster; //List monster yang dimiliki player, mungkin ada spesies monster yang lebih dari 1 pada listPlayerMonster
	public:
        Player(); //ctor
        ~Player(); //dtor
		Player(unsigned int, char*, unsigned int, unsigned char, unsigned int, unsigned int, unsigned int, list<lItem>, list <PlayerMonster>);
        Player(const Player&); //cctor
        Player operator=(const Player&);
		unsigned int GetPlayerNumber();
		char* GetName();
		unsigned int GetSumOfDays(); //Mengembalikan nilai SumOfDays
		unsigned char GetDayOrNight(); //Mengembalikan nilai DayOrNight
		unsigned int GetMoney(); //Mengembalikan nilai Money
		unsigned int GetWin(); //Mengembalikan nilai Win
		unsigned int GetLose(); //Mengembalikan nilai Lose
		std::list<lItem> GetItemTuple(); //Mengembalikan ListPlayerItem
        std::list<PlayerMonster> GetListPlayerMonster(); //Mengembalikan ListPlayerMonster
        void clear(); // Menghapus semua data player
        PlayerMonster& GetPlayerMonster(int);
        void InsertMonster(PlayerMonster, int);
		bool IsItemAda(int); //Mengecek apakah item bernomor int ada pada ListPlayerItem
        void ChangeName(char*); //Mengubah nama pemain
		void ChangePlayerNumber(unsigned int); //Mengubah nomor pemain
        void AddListItem(unsigned char, unsigned char); //Menambahkan Item pada List
        void DelListItem(unsigned char, unsigned char); //Menghapus Item pada List
        void AddMonster(PlayerMonster); //Menambahkan Monster pada ListPlayerMonster
        void DelMonster(unsigned char); //Menghapus Monster pada ListPlayerMonster
        void IncMoney(unsigned int); //Menambahkan sejumlah uang pemain
        void DecMoney(unsigned int); //Mengurangi sejumlah uang pemain
        void ChangeParty(unsigned int, unsigned int); //Menukar urutan list monster player
		void AddWin(int); //Menambahkan jumlah kemenangan pemain di stadium
		void AddLose(int); //Menambahkan jumlah kekalahan pemain di stadium
        void AddSumOfDays(int); // Menambah jumlah SumOfDays
        void ChangeDayOrNight(int); // Mengganti status siang atau malam
        void RestoreAllMonster(ListOfSkill *); // Menrestore HP dan status semua monster yang dimiliki pemain.
        void AddPM(PlayerMonster*); // Menambah Player Monster ke listPlayerMonster
        void ShowStatus();
        void PrintListItem(ListOfItem *);
        void PrintListMonster(int);
        void PrintListParty();
        void PrintInfoPartyMonster(int, ListOfMonster*, ListOfSkill *);
        bool IsHaveMonsterEgg();
        void HatchEgg(ListOfMonster *, ListOfSkill *, int, char *);
        void SaveMonster(ListOfMonster *, ListOfSkill *, int, char *);
        int TotalMonster();
};

#endif // __PLAYER_H