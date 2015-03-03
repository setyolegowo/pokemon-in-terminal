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

#include <list>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "listofplayer2.h"

using namespace std;

ListOfPlayer::ListOfPlayer() {
	
}

ListOfPlayer::~ListOfPlayer() {
    tabelPlayer.clear();
	tabelPlayer.~list();
}

ListOfPlayer::ListOfPlayer(const ListOfPlayer& LP) {
    list<Player>::iterator it;
	list<Player> tPlayer;
    
	tPlayer = LP.tabelPlayer;
    for(it = tPlayer.begin(); it != tPlayer.end(); ++it)
        this->tabelPlayer.push_back(*it);
}

ListOfPlayer& ListOfPlayer::operator= (ListOfPlayer& LP) {
    list<Player>::iterator it;
	list<Player> tPlayer;
    
	this->tabelPlayer.clear();
	tPlayer = LP.tabelPlayer;
    for(it = tPlayer.begin(); it != tPlayer.end(); ++it)
        this->tabelPlayer.push_back(*it);
	return *this;
}

void ListOfPlayer::ReadFromFile()
{
    ifstream myfile("player/player.txt");
    
    tabelPlayer.clear();
    if(myfile.is_open()) {
        while(myfile.good())
        {
			char cur_stream[1000];
            myfile.getline(cur_stream,1000);
            int i = 0;
			//PlayerNumber
			unsigned int PlayerNumber = 0;
			while(cur_stream[i] != ' ') {
				PlayerNumber = PlayerNumber*10 + (cur_stream[i] - '0');
				i++;
			}
			i++;
			//Name
			char Name[7];
			int j = 0;
            while(cur_stream[i] != ' ') {
                Name[j]=cur_stream[i];
                i++;
				j++;
            }
			while (j < 7) {
				Name[j] = '\0';
				j++;
			}
			i++;
			//SumOfDays
			unsigned int SumOfDays = 0;
			while(cur_stream[i] != ' ') {
				SumOfDays = SumOfDays*10 + (cur_stream[i] - '0');
				i++;
			}
			i++;
			//DayOrNight
			unsigned char DayOrNight;			
			while(cur_stream[i] != ' ') {
				DayOrNight+=cur_stream[i];
				i++;
			}
			i++;
			//Money
			unsigned int Money = 0;
			while(cur_stream[i] != ' ') {
				Money = Money*10 + (cur_stream[i] - '0');
				i++;
			}
			i++;
			//Win
			unsigned int Win;
			while(cur_stream[i] != ' ') {
				Win = Win*10 + (cur_stream[i] - '0');
				i++;
			}
			i++;
			//Lose
			unsigned int Lose;
			while(cur_stream[i] != ' ') {
				Money = Money*10 + (cur_stream[i] - '0');
				i++;
			}
			i+=2;
			//Item
			lItem lItem1;
			list<lItem> TlItem;
			unsigned int noItem; //jumlah item
			unsigned char nItem; //nama item
			while(cur_stream[i] != '}') {
				while(cur_stream[i] != ' ') {
					noItem = noItem*10 + (cur_stream[i] - '0');
					i++;
				}
				i++;
				while((cur_stream[i] != ' ') || (cur_stream[i] != '}')) {
					nItem+=cur_stream[i];
					i++;
				}
				lItem1.noItem = noItem;
				lItem1.nItem = nItem;
				TlItem.push_front(lItem1);
			}
			i+=2;
			list<unsigned char> LPlMonster;
			unsigned char monster;
			while(cur_stream[i] != '}') {
				while((cur_stream[i] != ' ') || (cur_stream[i] != '}')) {
					monster+=cur_stream[i];
					i++;
				}
				LPlMonster.push_front(monster);
				i++;
			}
			i+=2;
			list<unsigned char> LPaMonster;
			unsigned char Monster;
			while(cur_stream[i] != '}') {
				while((cur_stream[i] != ' ') || (cur_stream[i] != '}')) {
					Monster+=cur_stream[i];
					i++;
				}
				LPaMonster.push_front(Monster);
				i++;
			}
			cout<<endl;
			Player TPlayer(PlayerNumber,Name,SumOfDays,DayOrNight,Money,Win,Lose,TlItem,LPlMonster,LPaMonster);
			tabelPlayer.push_back(TPlayer);
        }
    } else
        throw(2);
    
    myfile.close();
}

void ListOfPlayer::PrintList() 
{
	list<Player>::iterator it1;
	Player tPlayer;
	
	it1 = tabelPlayer.begin();
	while (it1 != tabelPlayer.end()) {
		tPlayer = *it1;
		/*cout<<"Nomor Pemain = "<<tPlayer.GetPlayerNumber<<endl;
		//cout<<"Nama = "<<tPlayer.GetName<<endl;
		cout<<"Jumlah hari = "<<tPlayer.SumOfDays<<endl;
		cout<<"Keadaan hari = "<<tPlayer.DayOrNight<<endl;
		cout<<"Jumlah Uang = "<<tPlayer.Money<<endl;
		cout<<"Jumlah Kemenangan = "<<tPlayer.Win<<endl;
		cout<<"Jumlah Kekalahan = "<<tPlayer.Lose<<endl;
		
		list<lItem>::iterator it2;
		lItem lItemB;
		it2 = ListPlayerItem.begin();
		while (it2 != ListPlayerItem.end()) {
			lItemB = *it2;
		}
		it1++;*/
	}
}

void ListOfPlayer::DataList(int _PlayerNumber){
	list<Player>::iterator it1;
	Player tPlayer;
	
	it1 = tabelPlayer.begin();
	while (it1 != tabelPlayer.end()) {
		tPlayer = *it1;
		/*if(_PlayerNumber==tPlayer.GetPlayerNumber()){
		cout<<"Nomor Pemain = "<<tPlayer.GetPlayerNumber<<endl;
		}
		it1++;*/
	}
}