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

#include <iostream>
#include <fstream>
#include "listitemofplayer.h"
#include <cstdlib>
using namespace std;
using std::ifstream;
using std::string;

ListItemOfPlayer::ListItemOfPlayer()  {
    nItemPlayer = 0;
}

ListItemOfPlayer::~ListItemOfPlayer() {
    tabelItemPlayer.clear();
    tabelItemPlayer.~list();
	nItemPlayer = 0;
}

ListItemOfPlayer::ListItemOfPlayer(const ListItemOfPlayer& LIP)  {
	list<DataItem>::iterator it;
    list<DataItem> tTabel;
    
    tTabel = LIP.tabelItemPlayer;
    it = tTabel.begin();
    while(it != tTabel.end())
    {
        tabelItemPlayer.push_back(*it);
    }
	nItemPlayer = LIP.nItemPlayer;
}

ListItemOfPlayer& ListItemOfPlayer::operator= (ListItemOfPlayer& LIP) {
    list<DataItem>::iterator it;
    list<DataItem> tTabel;
    
    this->tabelItemPlayer.clear();
    tTabel = LIP.tabelItemPlayer;
    it = tTabel.begin();
    while(it != tTabel.end())
    {
        this->tabelItemPlayer.push_back(*it);
    }
	nItemPlayer = LIP.nItemPlayer;
	
    return *this;
}

void ListItemOfPlayer::ReadFromFile()
{	
	// string filename; // diisi item/item.nama   // nama didapat dari parameter method ini
	
	// std::ostringstream oss; // string as stream

	// oss << "item/item." << nama; // write to string stream
	// std::string filename = oss.str(); // get string out of stream
	
    ifstream myfile("item/item.nama",ifstream::in);
    
    tabelItemPlayer.clear();
    nItemPlayer = 0;
    if(myfile.is_open()) {
        while(myfile.good())
        {
			string cur_stream;
			int Quant = 0;
            int i = 0;
            int no = 0;
            
            getline(myfile,cur_stream);
            // => Get Number of item
            no = 0;
            while(cur_stream[i] != ' ')
            {
                no = 10*no + (cur_stream[i] - '0');
                i++;
            }
            i++; // Lewati karakter spasi
            
            // => Get quantity of item
            while(cur_stream[i] != ',')
            {
                Quant = 10*Quant + (cur_stream[i] - '0');
                i++;
            }
			i++;
            
            // Masukkan ke tipe item
            DataItem DItem;
			DItem.No = no;
			DItem.Quantity = Quant;
			// (no,Quant);
			// cout << Quant << " ";
			// cout << no << endl;
            
            // Masukkan ke list
            tabelItemPlayer.push_back(DItem);
			nItemPlayer++;
        }
    } else
        throw(2);
    
    myfile.close();
}


void ListItemOfPlayer::PrintListItemPlayer()
{
	Item tItem;
	int i;
	int k;
	char y;
	DataItem *TItem;
	DataItem DItem;
	Item DtItem;
	TItem = new DataItem[50];
	int nItemPlayer = 0;
	k = 0;
	
	for (std::list<DataItem>::iterator i = tabelItemPlayer.begin(); i != tabelItemPlayer.end(); i++) {
			DItem = *i;
			TItem[k]=DItem;
			k++;
			nItemPlayer++;
		}
	ListOfItem L;
	L.ReadFromFile();
	int m = 0;
	int b;
	int end;
	end = 4;
	do {		system("cls");
	
		cout << "No" << "    ";
		cout << "Jumlah" << "\t";
		cout << "Nama Item" << endl;
		cout << "-------------------------" << endl;
		
		for (b=m; b < end; b++) {
			cout << TItem[b].No << "\t";
			cout << TItem[b].Quantity << "\t";
			
			for (std::list<Item>::iterator n = L.tblItem.begin(); n != L.tblItem.end(); n++) {
				DtItem = *n;
				if (TItem[b].No == DtItem.GetItemNumber())
					cout << DtItem.GetName() << endl;
			}
			
			
			// cout <<  TItem[b].GetItemValue() << "\t";
			// cout <<  TItem[b].GetDesc() << endl;
			// cout << endl;
		}
		cout << "Next ? " ;
		cin >> y ;
		cout << endl;
		
		if (y == 'Y') {
		m = end;
		if  ( end+8 <= nItemPlayer ) {
		end = end+8; } else { end = nItemPlayer;} }
	} while (y == 'Y');
	delete [] TItem;
}