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
 
//constructor
Player::Player()
{
	
}

//destructor
Player::~Player()
{
	delete [] this->Player;
}

//copy constructor
Player::Player(const Player& P)
{
	this->PlayerNumber = Pl.PlayerNumber;
    this->SumOfDays = Pl.SumOfDays;
    this->DayOrNight = Pl.DayOrNight;
    this->Money = Pl.Money;
    this->Win = Pl.Win;
    this->Lose = Pl.Lose;
	
	this->MaxNameLength = P.MaxNameLength;
	Name = new char[MaxNameLength];
	for (int i=0; i<=MaxNameLength;i++) {
		this->Name[i] = Pl.Name[i];
	}
	this->MaxPartyMonster = Pl.MaxPartyMonster;
	ListPartyMonster = new char[MaxPartyMonster];
	for (int i=0;i<=MaxPartyMonster;i++) {
		this->ListPartyMonster[i] = Pl.ListPartyMonster[i];
	}

return *this;
}

Player Player::operator=(const Player&)
{
	this->PlayerNumber = Pl.PlayerNumber;
    this->SumOfDays = Pl.SumOfDays;
    this->DayOrNight = Pl.DayOrNight;
    this->Money = Pl.Money;
    this->Win = Pl.Win;
    this->Lose = Pl.Lose;
	
	for (int i=0; i<=MaxNameLength;i++) {
		this->Name[i] = Pl.Name[i];
	}

	for (int i=0;i<=MaxPartyMonster;i++) {
		this->ListPartyMonster[i] = Pl.ListPartyMonster[i];
	}

return *this;	
}

void Player::ChangeName(char* N)
{
	for (int i=0;i<=MaxNameLength;i++) {
		this->Name[i] = N[i];
	}
}

void Player::AddListItem(&ListPlayerItem)
{
	
}

void Player::DelListItem(&ListPlayerItem)
{

}

void Player::AddMonster(&ListPlayerMonster)
{
	for (int i=0;
}

void Player::IncMoney(unsigned int N)
{
	this->Money += N;
}

void Player::DecMoney(unsigned int N)
{
	this->Money += N;
}

void Player::ChangeParty()