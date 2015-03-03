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
#include "listofitem.h"
using namespace std;
#include <cstdlib>

using std::ifstream;
using std::string;
using std::list;
using std::cout;
using std::endl;

ListOfItem::ListOfItem() : MaxItemList(50) {
    nItem = 0;
}

ListOfItem::~ListOfItem() {
    tblItem.clear();
    tblItem.~list();
	nItem = 0;
}

ListOfItem::ListOfItem(const ListOfItem& LOP) : MaxItemList(LOP.MaxItemList) {
	list<Item>::iterator it;
    list<Item> tTabel;
    
    tTabel = LOP.tblItem;
    it = tTabel.begin();
    while(it != tTabel.end())
    {
        tblItem.push_back(*it);
    }
}

ListOfItem& ListOfItem::operator= (ListOfItem& LOP) {
    list<Item>::iterator it;
    list<Item> tTabel;
    
    this->tblItem.clear();
    tTabel = LOP.tblItem;
    it = tTabel.begin();
    while(it != tTabel.end())
    {
        this->tblItem.push_back(*it);
    }

    return *this;
}

int ListOfItem::GetNItem() {
	return nItem;

}

void ListOfItem::ReadFromFile()
{
    ifstream myfile("item/item.txt",ifstream::in);
    
    tblItem.clear();
    nItem = 0;
    if(myfile.is_open()) {
        while(myfile.good())
        {
            // char cur_stream[100];
			string cur_stream;
            char nama[13];
			char desc[100];
            int i = 0;
            unsigned char no;
            
            getline(myfile,cur_stream);
            // => Get Number of item
            no = 0;
            while(cur_stream[i] != ' ')
            {
                no = 10*no + (cur_stream[i] - '0');
                i++;
            }
            i++; // Lewati karakter spasi
            
            // => Get nama item
            int j = 0;
            while(cur_stream[i] != ' ')
            {
                nama[j] = cur_stream[i];
                i++;
                j++;
            }
            while(j < 12) {
                nama[j] = '\0';
                j++;
            }
            i++; // Lewati karakter spasi
            
            // => Get Type
            int n = cur_stream[i] - '0';
            i++;
            i++;
            
            // => Get Price
            int Price = 0;
            while(cur_stream[i] != ' ') {
                Price = 10*Price + (cur_stream[i] - '0');
                i++;
            }
            i++;
            
            // => Get Value
            int Value = 0;
            while(cur_stream[i] != ' ') {
                Value = 10*Value + (cur_stream[i] - '0');
                i++;
            }
			i++;
			
			// => Get desc
            int k = 0;
            while(cur_stream[i] != ',')
            {
                desc[k] = cur_stream[i];
                i++;
                k++;
            }
			desc[k] = '\0';
            
            // Masukkan ke tipe item
            Item tItem(no,nama,n,Price,Value,desc);
            
            // Masukkan ke list
            tblItem.push_back(tItem);
			nItem++;
        }
    } else
        throw(2);
    
    myfile.close();
}

int ListOfItem::IsOnTable(char * Name) {
    std::list<Item>::iterator it;
    bool IsItemExist = false;
    int n = 0;
    
    it = tblItem.begin();
    while(!IsItemExist && (it != tblItem.end()))
    {
        char * tNama = it->GetName();
        int i = 0;
        int j = 0;
        while(((tNama[j] >= 'a') && (tNama[j] <= 'z')) || ((tNama[j] >= 'A') && (tNama[j] <= 'Z'))) {
            if((tNama[j] >= 'A') && (tNama[j] <= 'Z'))
                tNama[j] += 32;
            j++;
        }
        // Maka j adalah panjang nama terdaftar yang benar
            
        while(i < j)
        {
            if(tNama[i] == Name[i])
                i++;
            else
                break;
        }
        if((i == j) && (Name[i] == '\0')) {
            IsItemExist = true;
            n = it->GetItemNumber();
        }
        ++it;
    }
    return n; // Sementara!!!
}

void ListOfItem::PrintListItem()
// Format keluaran: [no]\t[nama]\t[price]\t[description]
{
    cout<<"                      B A R A N G   Y A N G   D I J U A L\n";
    for (std::list<Item>::iterator i = tblItem.begin(); i != tblItem.end(); i++) {
        Item tItem = *i;
        cout.width(4);
        cout << tItem.GetItemNumber(); 
        cout.width(13);
        cout << tItem.GetName() << " " << tItem.GetPrice() << "\t" << tItem.GetDesc() << endl;
        nItem++;
    }
    cout << endl;
}
void ListOfItem::PrintName(int i) {
    list<Item>::iterator it;
    it = tblItem.begin();
    std::advance(it, i - 1);
    Item tItem = *it;
    cout << tItem.GetName();
}
void ListOfItem::PrintPrice(int i) {
    list<Item>::iterator it;
    it = tblItem.begin();
    std::advance(it, i - 1);
    Item tItem = *it;
    cout << tItem.GetPrice();
}
int ListOfItem::GetPrice(int i) {
    list<Item>::iterator it;
    it = tblItem.begin();
    std::advance(it, i - 1);
    Item tItem = *it;
    return tItem.GetPrice();
}
int ListOfItem::GetValue(int i) {
    list<Item>::iterator it;
    it = tblItem.begin();
    std::advance(it, i - 1);
    Item tItem = *it;
    return tItem.GetItemValue();
}
void ListOfItem::PrintDescription(int i) {
    list<Item>::iterator it;
    it = tblItem.begin();
    std::advance(it, i - 1);
    Item tItem = *it;
    cout << tItem.GetDesc();
}