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
* Nama File            : player.cpp
* Bahasa               : C++
* Compiler             : g++
* Tanggal Diperbaharui : 
* Deskripsi            : 
* - 
*/


#include <iostream>
#include "player.h"
 
//constructor, belum selesai
Player::Player(): MaxNameLength(7), MaxPartyMonster(6)
{
	Name = new char [MaxNameLength];
	PlayerNumber = 0;
	DayOrNight = 0;
	Money = 0;
	Win = 0;
	Lose = 0;
}

//destructor
Player::~Player()
{
	delete [] Name;
	ListPlayerItem.clear();
	ListPlayerMonster.clear();
	ListPartyMonster.clear();
}

//copy constructor
Player::Player(const Player& Pl) : MaxNameLength(7), MaxPartyMonster(6)
{
	this->PlayerNumber = Pl.PlayerNumber;
    this->SumOfDays = Pl.SumOfDays;
    this->DayOrNight = Pl.DayOrNight;
    this->Money = Pl.Money;
    this->Win = Pl.Win;
    this->Lose = Pl.Lose;
}

Player Player::operator=(const Player& Pl)
{
	this->PlayerNumber = Pl.PlayerNumber;
    this->SumOfDays = Pl.SumOfDays;
    this->DayOrNight = Pl.DayOrNight;
    this->Money = Pl.Money;
    this->Win = Pl.Win;
    this->Lose = Pl.Lose;
	
	for (int i=0;i<=MaxNameLength;i++) {
		this->Name[i] = Pl.Name[i];
	}

}

void Player::ChangeName(char* N)
{
	for (int i=0;i<=MaxNameLength;i++) {
		this->Name[i] = N[i];
	}
}
void Player::ChangePlayerNumber(unsigned int a)
{
	PlayerNumber = a;
}

void Player::AddListItem(unsigned char a, unsigned char b) { //a = jumlah, b = nama item
	bool c = false; //menunjukkan apakah item sudah ada pada ListPlayerItem
	std::list<lItem>::iterator it1; //membuat iterator untuk list of struct Item
	it1 = ListPlayerItem.begin();
	while (it1 != ListPlayerItem.end()) {
		if (it1->Item = b) {
			it1->nItem = it1->nItem + a;
			c = true;
		}
		it1++;
	}
	if (not c) {;
		it1++;
		it1->Item = b;
		it1->nItem = a;
	}
}

void Player::DelListItem(unsigned char a, unsigned char b)
{
	std::list<lItem>::iterator it1;
	it1 = ListPlayerItem.begin();
	while ((it1->Item != b) || (it1 != ListPlayerItem.end())) {
		it1++;
	}
	if (it1->nItem > 1) {
		it1->nItem = it1->nItem - 1;
	}
	else
		it1 = ListPlayerItem.erase(it1);
}

void Player::AddWin()
{
	this->Win++;
}

void Player::AddLose()
{
	this->Lose++;
}

void Player::AddMonster(short unsigned int a)
{
	ListPlayerMonster.push_back(a);
}

void Player::DelMonster(short unsigned int a)
{
	ListPlayerMonster.remove(a);
}

void Player::IncMoney(unsigned int N)
{
	this->Money += N;
}

void Player::DecMoney(unsigned int N)
{
	this->Money += N;
}

void Player::ChangeParty(unsigned int a, unsigned int b) //monster a diganti monster b
{
	ListPartyMonster.remove(a);
	ListPartyMonster.push_back(b);
}