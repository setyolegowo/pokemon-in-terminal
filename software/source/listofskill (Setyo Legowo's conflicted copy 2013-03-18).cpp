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
 * Nama File            : listofskill.cpp
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */

#include <iostream>
#include <fstream>
#include "listofskill.h"
#include "skill.h"
using std::ifstream;
using std::list;
using std::cout;

ListOfSkill::ListOfSkill() {}
ListOfSkill::~ListOfSkill()
{
    tabelSkill.clear();
    tabelSkill.~list();
}
ListOfSkill::ListOfSkill(const ListOfSkill& LS)
{

}
ListOfSkill& ListOfSkill::operator=(ListOfSkill& LS)
{
    return *this;
}
void ListOfSkill::ReadFromFile()
{
    int i;
    ifstream myfile("skill/skill.txt",ifstream::in);
    
    tabelSkill.clear();
    if(myfile.is_open())
    {
        while(myfile.good())
        {
            char cur_stream[100];
            myfile.getline(cur_stream,100);
            
            // .:: operasi terhadap cur_stream ::.
            // -> tambah nomor skill
            int no_skill = 0;
            i = 0;
            while(cur_stream[i] != ' ')
            {
                no_skill = no_skill*10 + (cur_stream[i] - '0');
                i++;
            }
            i++; // Lewati 1 spasi
            
            // -> ambil nama skill
            char nama_skill[21];
            int j = 0;
            while(cur_stream[i] != ' ')
            {
                nama_skill[j] = cur_stream[i];
                i++;
                j++;
            }
            while(j <= 21) // 21 adalah panjang nama skill
            {
                nama_skill[j] = '\0';
                j++;
            }
            i++; // Lewati 1 spasi
            
            // -> Target
            int target = 0;
            target = cur_stream[i] - '0';
            i+=2; // lewati 1 karakter target dan 1 spasi
            
            // -> Elemen
            int Elemen = 0;
            Elemen = cur_stream[i] - '0';
            i+=2; // lewati 1 karakter elemen dan 1 spasi
            
            // -> StrWeak
            char StrWeak[2];
            StrWeak[0] = 0;
            StrWeak[1] = 0;
            i++; // Lewati karakter '{'
            while(cur_stream[i] != ',')
            {
                StrWeak[0] = 10*StrWeak[0] + cur_stream[i] - '0';
                i++;
            }
            i++; // lewati karakter ','
            while(cur_stream[i] != '}')
            {
                StrWeak[1] = 10*StrWeak[1] + cur_stream[i] - '0';
                i++;
            }
            i+=2; // lewati karakter '}' dan karakter ','
            
            // -> Power
            int Power = 0;
            while(cur_stream[i] != ' ')
            {
                Power = 10*Power + cur_stream[i] - '0';
                i++;
            }
            i++; // lewati karakter spasi
            
            // -> PowerEffect
            int PowerEffect = 0;
            while(cur_stream[i] != ' ')
            {
                PowerEffect = 10*Power + cur_stream[i] - '0';
                i++;
            }
            i++; // lewati karakter spasi
            
            // -> Accuracy
            int Akurasi = 0;
            while(cur_stream[i] != ' ')
            {
                Akurasi = 10*Akurasi + cur_stream[i] - '0';
                i++;
            }
            i++; // lewati karakter spasi
            
            // -> Effect
            int Efek = 0;
            while(cur_stream[i] != ' ')
            {
                Efek = 10*Efek + cur_stream[i] - '0';
                i++;
            }
            i++; // lewati karakter spasi
            
            // -> Prpobability Effect
            int ProbEfek = 0;
            while(cur_stream[i] != ' ')
            {
                ProbEfek = 10*ProbEfek + cur_stream[i] - '0';
                i++;
            }
            i++; // lewati karakter spasi
            
            // -> PPMax
            int PPMax = 0;
            while(cur_stream[i] != ',')
            {
                PPMax = 10*PPMax + cur_stream[i] - '0';
                i++;
            }
            
            //Memasukkan ke skill
            Skill TSkill;
            tabelSkill.push_back(TSkill);
        }
        myfile.close();
    }
    // else
        // throw(2);
}

void ListOfSkill::PrintList()
{	
	std::list<Skill>::iterator _S1; //membuat iterator untuk list of struct Item
    Skill tSkill;
    
	_S1 = tabelSkill.begin();
	while (_S1 != tabelSkill.end()) {
		tSkill = *_S1;
        cout << tSkill.GetName();
		_S1++;
	}
}
