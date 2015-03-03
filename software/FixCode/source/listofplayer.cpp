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
#include <fstream>
#include <iostream>
#include <cassert>
#include "listofplayer.h"

using namespace std;

ListOfPlayer::ListOfPlayer() {
}

ListOfPlayer::~ListOfPlayer() {
    tabelPlayer.clear();
    tabelPlayer.~list();
}

ListOfPlayer::ListOfPlayer(const ListOfPlayer& LOP) {
    list<string>::iterator it;
    list<string> tPlayer;
    
    tPlayer = LOP.tabelPlayer;
    it = tPlayer.begin();
    while(it != tPlayer.end()) {
        this->tabelPlayer.push_back(*it);
    }
}

ListOfPlayer& ListOfPlayer::operator= (ListOfPlayer& LOP) {
    list<string>::iterator it;
    list<string> tPlayer;
    
    this->tabelPlayer.clear();
    tPlayer = LOP.tabelPlayer;
    it = tPlayer.begin();
    while(it != tPlayer.end()) {
        this->tabelPlayer.push_back(*it);
    }
    return *this;
}

bool ListOfPlayer::IsOnTable(char * _Name)
{
    list<string>::iterator it;
    bool IsPlayerExist = false;
    
    it = tabelPlayer.begin();
    while(!IsPlayerExist && (it != tabelPlayer.end()))
    {
        string tNama = *it;
        int i = 0;
        int j = 0;
        while((tNama[j] >= 'a') && (tNama[j] <= 'z'))
            j++;
        // Maka j adalah panjang nama terdaftar yang benar
            
        while(i < j)
        {
            if(tNama[i] == _Name[i])
                i++;
            else
                break;
        }
        if((i == j) && (_Name[i] == '\0'))
            IsPlayerExist = true;
        ++it;
    }
    return IsPlayerExist; // Sementara!!!
}

void ListOfPlayer::ReadFromFile()
{
    ifstream myfile("player/player.txt",ifstream::in);
    
    tabelPlayer.clear();
    if(myfile.is_open()) {
        while(myfile.good())
        {
            char cur_stream[20];
            string nama;
            
            myfile.getline(cur_stream,20);
            int i = 0;
            while(cur_stream[i] != ';')
            {
                nama+=cur_stream[i];
                i++;
            }
            if(i > 0)
                tabelPlayer.push_back(nama);
        }
    } else
        throw(2);
    
    myfile.close();
}
void ListOfPlayer::SavePlayer(Player &_Player) // ### BELUM BERES
{      
    // Menyimpan untuk membaca isi file
    char PlayerFile[22] = "player/player-";
    char PlayerItem[18] = "item/item-";
    char PlayerMonsters[24] = "monster/monster-";
    ofstream myfile;
    
    char * ActiveName = _Player.GetName();
    
    // Membuat nama file
    int i = 0;
    while(ActiveName[i] != '\0')
    {
        PlayerFile[i + 14] = ActiveName[i];
        PlayerItem[i + 10] = ActiveName[i];
        PlayerMonsters[i + 16] = ActiveName[i];
        i++;
    }
    PlayerFile[i + 14] = '\0';
    PlayerItem[i + 10] = '\0';
    PlayerMonsters[i + 16] = '\0';
    
    // Change data of player
    remove(PlayerFile); //system("pause");
    myfile.open(PlayerFile,ofstream::out);
    assert(myfile.is_open());
    if(myfile.is_open()) {
        myfile << _Player.GetSumOfDays() << " ";
        myfile << int(_Player.GetDayOrNight()) << " ";
        myfile << _Player.GetMoney() << " ";
        myfile << _Player.GetWin() << " ";
        myfile << _Player.GetLose() << " ;";
    }
    myfile.close();
    
    // ::: Membuat data Item
    // -> Membuat file data
    remove(PlayerItem); //system("pause");
    myfile.open(PlayerItem,ofstream::out);
    assert(myfile.is_open());
    if(myfile.is_open()) {
        list<lItem>::iterator it;
        list<lItem> GIT;
        GIT = _Player.GetItemTuple();
        for(it = GIT.begin(); it != GIT.end(); ++it) {
            myfile << int(it->noItem) << " " << int(it->nItem) << ";\n";  // NoItem, Qty
        }
        myfile << ";";
    }
    myfile.close();
    
    // ::: Membuat data Monster
    // -> Membuat file daftar monster
    remove(PlayerMonsters); //system("pause");
    myfile.open(PlayerMonsters,ofstream::out);
    assert(myfile.is_open());
    if(myfile.is_open()) { // ### BELUM
        list<PlayerMonster> _PM;
        _PM = _Player.GetListPlayerMonster();
        list<PlayerMonster>::iterator itPM;
        for(itPM = _PM.begin(); itPM != _PM.end(); ++itPM) {
            PlayerMonster tPM(*itPM);
            myfile << tPM.getMonsterNumber() << " ";
            myfile << tPM.getName() << " ";
            myfile << tPM.getCurAge() << " ";
            myfile << tPM.getCurLevel() << " ";
            myfile << tPM.getCurExp() << " ";
            myfile << tPM.getExpMax() << " ";
            myfile << tPM.getTotalExp() << " ";
            myfile << tPM.getIncHP() << " ";
            myfile << tPM.getHP() << " "; //cout << tPM.getHP() << " "; system("pause");
            myfile << tPM.getIncAttack() << " ";
            myfile << tPM.getAttack() << " ";
            myfile << tPM.getIncDefense() << " ";
            myfile << tPM.getDefense() << " ";
            myfile << tPM.getIncSpeed() << " ";
            myfile << tPM.getSpeed() << " ";
            myfile << tPM.getSkill(0) << " ";
            myfile << tPM.getSkill(1) << " ";
            myfile << tPM.getSkill(2) << " ";
            myfile << tPM.getSkill(3) << " ";
            int * PPOfSkills = tPM.getPPOfSkills();
            myfile << PPOfSkills[0] << " ";
            myfile << PPOfSkills[1] << " ";
            myfile << PPOfSkills[2] << " ";
            myfile << PPOfSkills[3] << " ";
            myfile << tPM.getStatusEffect() << " ";
            myfile << ";\n";
        }
        myfile << ";"; // MonsterNumber, Name, CurAge, CurLevel, CurExp, ExpMax, TotalExp, IncHP, HP, IncAttack, Attack, IncDefense, Defense, IncSpeed, Speed, Skills*, PPOfSkills*, StatusEffect
    }
    myfile.close();
}

void ListOfPlayer::ReadPlayer(Player * _Player, char * _Name) // ### BELUM BERES
// Prekondisi, _Name ada dalam tabelPlayer.
{
    _Player->clear();
    _Player->ChangeName(_Name);
    char cur_stream[100];
    
    // Menyimpan untuk membaca isi file
    char PlayerFile[22] = "player/player-";
    char PlayerItem[18] = "item/item-";
    char PlayerMonsters[24] = "monster/monster-";
    ifstream myfile;
    
    // Membuat nama file
    int i = 0;
    while(_Name[i] != '\0')
    {
        PlayerFile[i + 14] = _Name[i];
        PlayerItem[i + 10] = _Name[i];
        PlayerMonsters[i + 16] = _Name[i];
        i++;
    }
    PlayerFile[i + 14] = '\0';
    PlayerItem[i + 10] = '\0';
    PlayerMonsters[i + 16] = '\0';
    
    // Change data of player
    myfile.open(PlayerFile,ifstream::in);
    assert(myfile.is_open());
    if(myfile.is_open()) {
        myfile.getline(cur_stream,100);
        i = 0;
        int val = 0;
        while(cur_stream[i] != ' ')
        {
            val = 10*val + (cur_stream[i] - '0');
            i++;
        }
        i++;
        _Player->AddSumOfDays((unsigned int)val);
        
        val = 0;
        while(cur_stream[i] != ' ')
        {
            val = 10*val + (cur_stream[i] - '0');
            i++;
        }
        i++;
        _Player->ChangeDayOrNight((unsigned char) val);
        
        val = 0;
        while(cur_stream[i] != ' ')
        {
            val = 10*val + (cur_stream[i] - '0');
            i++;
        }
        i++;
        _Player->IncMoney((unsigned int)val);
        
        val = 0;
        while(cur_stream[i] != ' ')
        {
            val = 10*val + (cur_stream[i] - '0');
            i++;
        }
        i++;
        _Player->AddWin((unsigned int)val);
        
        val = 0;
        while(cur_stream[i] != ' ')
        {
            val = 10*val + (cur_stream[i] - '0');
            i++;
        }
        i++;
        _Player->AddLose((unsigned int) val);
    }
    myfile.close();
    
    // ::: Membuat data Item
    // -> Membuat file data
    
    myfile.open(PlayerItem,ifstream::in);
    assert(myfile.is_open());
    if(myfile.is_open()) {
        while(myfile.good()) {
            int noItem, nItem;
            i = 0;
            myfile.getline(cur_stream,100);
            if(cur_stream[0] != ';') {
                // Membaca no item
                int val = 0;
                while(cur_stream[i] != ' ')
                {
                    val = 10*val + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                noItem = val;
                
                // Membaca qty item
                val = 0;
                while(cur_stream[i] != ';')
                {
                    val = 10*val + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                nItem = val;
                
                // cout << "D 3 : " << noItem << ", " << nItem << endl;
                // system("pause");
                _Player->AddListItem((unsigned char) noItem, (unsigned char) nItem);
            }
        }
    }
    myfile.close();
    
    // ::: Membuat data Monster
    // -> Membuat file daftar monster
    myfile.open(PlayerMonsters,ifstream::in);
    assert(myfile.is_open());
    assert(_Player->TotalMonster() == 0);
    // cout << "Test 1\n";  system("pause");
    if(myfile.is_open()) {
        int no = 0;
        while(myfile.good()) {
            myfile.getline(cur_stream,100);
            if((cur_stream[0] >= '0') && (cur_stream[0] <= '9')) {
                i = 0;
                int j;
                // cout << "Test 3\n";  system("pause");
                unsigned int MonsterNumber = 0;
                while(cur_stream[i] != ' ') {
                    MonsterNumber = 10*MonsterNumber + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                // cout << "Test MonsterNumber\n";  system("pause");
                char Name[15];
                j = 0;
                while(cur_stream[i] != ' ') {
                    Name[j] = cur_stream[i];
                    i++;
                    j++;
                }
                while(j < 15) {
                    Name[j] = '\0';
                    j++;
                }
                i++;
                // cout << "Test Name\n";  system("pause");
                unsigned int CurAge = 0;
                while(cur_stream[i] != ' ') {
                    CurAge = 10*CurAge + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                // cout << "Test Age\n";  system("pause");
                unsigned int CurLevel = 0;
                while(cur_stream[i] != ' ') {
                    CurLevel = 10*CurLevel + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                // cout << "Test Level\n";  system("pause");
                unsigned int CurExp = 0;
                while(cur_stream[i] != ' ') {
                    CurExp = 10*CurExp + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                // cout << "Test CurExp\n";  system("pause");
                unsigned int ExpMax = 0;
                while(cur_stream[i] != ' ') {
                    ExpMax = ExpMax*10 + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                // cout << "Test ExpMax\n";  system("pause");
                unsigned int TotalExp = 0;
                while(cur_stream[i] != ' ') {
                    TotalExp = TotalExp*10 + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                // cout << "Test TotalExp\n";  system("pause");
                unsigned int IncHP = 0;
                while(cur_stream[i] != ' ') {
                    IncHP = 10*IncHP + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                // cout << "Test IncHP\n";  system("pause");
                unsigned int HP = 0;
                while(cur_stream[i] != ' ') {
                    HP = 10*HP + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                // cout << "Test HP\n";  system("pause");
                unsigned int IncAttack = 0;
                while(cur_stream[i] != ' ') {
                    IncAttack = 10*IncAttack + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                // cout << "Test IncAttack\n";  system("pause");
                unsigned int Attack = 0;
                while(cur_stream[i] != ' ') {
                    Attack = 10*Attack + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                // cout << "Test Attack\n";  system("pause");
                unsigned int IncDefense = 0;
                while(cur_stream[i] != ' ') {
                    IncDefense = 10*IncDefense + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                // cout << "Test IncDefense\n";  system("pause");
                unsigned int Defense = 0;
                while(cur_stream[i] != ' ') {
                    Defense = 10*Defense + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                // cout << "Test Defense\n";  system("pause");
                unsigned int IncSpeed = 0;
                while(cur_stream[i] != ' ') {
                    IncSpeed = IncSpeed*10 + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                // cout << "Test IncSpeed\n";  system("pause");
                unsigned int Speed = 0;
                while(cur_stream[i] != ' ') {
                    Speed = 10*Speed + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                // cout << "Test Speed\n";  system("pause");
                int Skills[4] = {0, 0, 0, 0};
                while(cur_stream[i] != ' ') {
                    Skills[0] = 10*Skills[0] + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                while(cur_stream[i] != ' ') {
                    Skills[1] = 10*Skills[1] + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                while(cur_stream[i] != ' ') {
                    Skills[2] = 10*Skills[2] + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                while(cur_stream[i] != ' ') {
                    Skills[3] = 10*Skills[3] + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                // cout << "Test Skills\n";  system("pause");
                int PPOfSkills[4] = {0, 0, 0, 0};
                while(cur_stream[i] != ' ') {
                    PPOfSkills[0] = 10*PPOfSkills[0] + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                while(cur_stream[i] != ' ') {
                    PPOfSkills[1] = 10*PPOfSkills[1] + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                while(cur_stream[i] != ' ') {
                    PPOfSkills[2] = 10*PPOfSkills[2] + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                while(cur_stream[i] != ' ') {
                    PPOfSkills[3] = 10*PPOfSkills[3] + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                // cout << "Test PPOfSkills\n";  system("pause");
                int StatusEffect = 0;
                while((cur_stream[i] != ';') && (cur_stream[i] != ' ')) {
                    StatusEffect = 10*StatusEffect + (cur_stream[i] - '0');
                    i++;
                }
                i++;
                // cout << "Test StatusEffect\n";  system("pause");
                // Menyimpan ke list
                // cout << MonsterNumber << " " << Name << " " << CurAge << " " << CurLevel << " " << CurExp << " " << ExpMax << " " << TotalExp << " " << IncHP << " " << HP << " " << IncAttack << " " << Attack << " " << IncDefense << " " << Defense << " " << IncSpeed << " " << Speed << " " << Skills << " " << PPOfSkills << " " << StatusEffect << endl;
                // system("pause");
                PlayerMonster _PM(MonsterNumber, Name, CurAge, CurLevel, CurExp, ExpMax, TotalExp, IncHP, HP, IncAttack, Attack, IncDefense, Defense, IncSpeed, Speed, Skills, PPOfSkills, StatusEffect);
                _Player->AddPM(&_PM);
                
                no++;
            }
        }
        assert(_Player->TotalMonster() == no);
    }
    myfile.close();

}
void ListOfPlayer::MakePlayer(Player * _Player, char * _Name)
// Prekondisi: panjang char * terdefinisi (dapat langsung diaplikasikan ke fungsi ini)
{
    char PlayerFile[22] = "player/player-";
    char PlayerItem[18] = "item/item-";
    char PlayerMonster[24] = "monster/monster-";
    ofstream myfile;
    
    // Membuat nama file
    int i = 0;
    while(_Name[i] != '\0')
    {
        PlayerFile[i + 14] = _Name[i];
        PlayerItem[i + 10] = _Name[i];
        PlayerMonster[i + 16] = _Name[i];
        i++;
    }
    PlayerFile[i + 14] = '\0';
    PlayerItem[i + 10] = '\0';
    PlayerMonster[i + 16] = '\0';
    
    // ::: Membuat data Player :::
    // -> Mengisi _Player
    _Player->ChangeName(_Name);
    _Player->IncMoney(12500);
    _Player->ChangeDayOrNight(1);
    // -> Membuat file data
    myfile.open(PlayerFile,ofstream::out);
    assert(myfile.is_open());
    if(myfile.is_open()) {
        myfile << "0 1 12500 0 0 ;"; // SumOfDays, DayOrNight, Money, Win, Lose
    }
    myfile.close();
    
    // ::: Membuat data Item
    // -> Membuat file data
    myfile.open(PlayerItem,ofstream::out);
    assert(myfile.is_open());
    if(myfile.is_open())
        myfile << ";"; // NoItem, Qty
    myfile.close();
    
    // ::: Membuat data Monster
    // -> Membuat file daftar monster
    myfile.open(PlayerMonster,ofstream::out);
    assert(myfile.is_open());
    if(myfile.is_open())
        myfile << ";"; // MonsterNumber, Name, CurAge, CurLevel, CurExp, TotalExp, IncHP, HP, IncAttack, IncDefense, IncSpeed, {Skill}, {PPOfSkill}, Effect
    myfile.close();
    
    // ::: UPDATE DATA PLAYER :::
    string name = _Name;
    tabelPlayer.push_back(name);
    remove("player/player.txt");
    myfile.open("player/player.txt",ofstream::out);
    assert(myfile.is_open());
    std::list<string>::iterator it;
    
    it = tabelPlayer.begin();
    if(myfile.is_open()) {
        while(it != tabelPlayer.end())
        {
            myfile << *it;
            myfile << ";\n";
            ++it;
        }
    }
    myfile << ";";
    myfile.close();
}
void ListOfPlayer::PrintPlayerRegistered()
{   
    if(tabelPlayer.empty())
        std::cout << "\n Kosong.\n";
    else {
        std::list<string>::iterator it;
        it = tabelPlayer.begin();
        while(it != tabelPlayer.end())
        {
            std::cout << *it << endl;
            it++;
        }
    }
}