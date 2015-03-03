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
using namespace std;

//constructor
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
}

Player::Player(unsigned int _PlayerNumber, char* _Name, unsigned int _SumOfDays, unsigned char _DayOrNight, unsigned int _Money, unsigned int _Win, unsigned int _Lose, list<lItem> _ListPlayerItem, list <PlayerMonster> _ListPlayerMonster) : MaxNameLength(7), MaxPartyMonster(6)
{
	Name = new char[MaxNameLength];
	PlayerNumber = _PlayerNumber;
	for (int i=0;i<=MaxNameLength;i++)
	{	
		Name[i]=_Name[i];
	}
	SumOfDays = _SumOfDays;
	DayOrNight = _DayOrNight;
	Money = _Money;
	Win = _Win;
	Lose = _Lose;
	
	std::list<lItem>::iterator it1;
	it1 = _ListPlayerItem.begin();
	lItem lItemA;
	while (it1 != _ListPlayerItem.end()){
		lItemA = *it1;
		ListPlayerItem.push_back(lItemA);
		it1++;
	}
	
	std::list<PlayerMonster>::iterator it2, it3;
	PlayerMonster i2, i3;
	it2 = _ListPlayerMonster.begin();
	while (it2 != _ListPlayerMonster.end()) {
		i2 = *it2;
		ListPlayerMonster.push_back(i2);
		it2++;
	}
}

Player::Player(const Player& Pl): MaxNameLength(7), MaxPartyMonster(6)
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

unsigned int Player::GetPlayerNumber()
{
	return PlayerNumber;
}
char* Player::GetName() {
	return Name;
}

unsigned int Player::GetSumOfDays()
{
	return SumOfDays;
}

unsigned char Player::GetDayOrNight()
{
	return DayOrNight;
}

unsigned int Player::GetMoney()
{
	return Money;
}

unsigned int Player::GetWin()
{
	return Win;
}

unsigned int Player::GetLose()
{
	return Lose;
}

std::list<lItem> Player::GetItemTuple() {
    return ListPlayerItem;
}

std::list<PlayerMonster> Player::GetListPlayerMonster() {
    return ListPlayerMonster;
}

void Player::clear() {
    delete [] Name;
    Name = new char [MaxNameLength];
    SumOfDays = 0;
	DayOrNight = 0;
	Money = 0;
	Win = 0;
	Lose = 0;
    ListPlayerItem.clear();
	ListPlayerMonster.clear();
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

void Player::AddListItem(unsigned char a, unsigned char b) { //b = jumlah, a = no-item
	bool c = false; //menunjukkan apakah item sudah ada pada ListPlayerItem
	std::list<lItem>::iterator it1; //membuat iterator untuk list of struct Item
	it1 = ListPlayerItem.begin();
	while (it1 != ListPlayerItem.end()) {
		if (it1->noItem == a) {
			it1->nItem = (it1->nItem) + b;
			c = true;
		}
		++it1;
	}
	if (not c) {
        lItem tlItem;
		tlItem.nItem = b;
		tlItem.noItem = a;
        ListPlayerItem.push_back(tlItem);
	}
}

void Player::DelListItem(unsigned char a, unsigned char b) // a adalah no-item dan b adalah banyak item yang akan dihapus
{
	std::list<lItem>::iterator it1;
	it1 = ListPlayerItem.begin();
	while ((it1->noItem != a) && (it1 != ListPlayerItem.end())) {
		it1++;
	}
    if(it1 != ListPlayerItem.end()) {
        if(it1->nItem > b)
            it1->nItem-=b;
        else
            it1 = ListPlayerItem.erase(it1);
    }
}

void Player::AddWin(int i)
{
	this->Win+=i;
}

void Player::AddLose(int i)
{
	this->Lose+=i;
}

void Player::AddMonster(PlayerMonster a)
{
	ListPlayerMonster.push_back(a);
}
void Player::InsertMonster(PlayerMonster a, int i)
{
	if(i == 1)
        ListPlayerMonster.push_front(a);
    else {
        std::list<PlayerMonster>::iterator _it;
        _it = ListPlayerMonster.begin();
        advance(_it, i - 1);
        ListPlayerMonster.insert(_it,a);
    }
}
void Player::DelMonster(unsigned char a) {
    if(a == 1)
        ListPlayerMonster.pop_front();
    else {
        std::list<PlayerMonster>::iterator _it;
        _it = ListPlayerMonster.begin();
        advance(_it, a - 1);
        ListPlayerMonster.erase(_it);
    }
}

void Player::IncMoney(unsigned int N)
{
	this->Money += N;
}

void Player::DecMoney(unsigned int N)
{
	this->Money -= N;
}

void Player::ChangeParty(unsigned int a, unsigned int b) //monster a diganti monster b
// Prekondisi: nomor a dan b dapat dilakukan proses pertukaran disini dan (a != b)
{
	std::list<PlayerMonster>::iterator _it1, _it2;
    _it1 = ListPlayerMonster.begin();
    advance(_it1, a - 1);
    _it2 = ListPlayerMonster.begin();
    advance(_it1, b - 1);
    ListPlayerMonster.insert(_it1, *_it2);
    ListPlayerMonster.insert(_it2, *_it1);
    ListPlayerMonster.erase(_it1);
    ListPlayerMonster.erase(_it2);
}
void Player::AddSumOfDays(int i) {
    this->SumOfDays+=i;
}
void Player::ChangeDayOrNight(int i) {
    this->DayOrNight = i;
}

bool Player::IsItemAda(int a) {
	std::list<lItem>::iterator it4;
	it4 = ListPlayerItem.begin();
	bool ada = false;
	while (it4 != ListPlayerItem.end()) {
		if (a = it4->noItem) {
			ada = true;
		}
		++it4;
	}
	return ada;
}

void Player::RestoreAllMonster(ListOfSkill * _ListOfSkill) {
    if(ListPlayerMonster.size() > 0) {
        std::list<PlayerMonster>::iterator _it4;
        _it4 = ListPlayerMonster.begin();
        while (_it4 != ListPlayerMonster.end()) {
            _it4->RestoreHP();
            _it4->RestoreAllPP(_ListOfSkill);
            _it4->ChangeEffect(0);
            ++_it4;
        }
    }
}

void Player::AddPM(PlayerMonster* _PlayerMonster) {
    ListPlayerMonster.push_back(*_PlayerMonster);
}
void Player::ShowStatus() {
    cout<<"                            S T A T U S   P E M A I N\n";
    cout << "\t Nama : " << Name << endl;
    cout << "\t Uang : " << Money << " Zeny" << endl;
    cout << "\t Total Menang     : " << Win << " (dalam stadium)" <<  endl;
    cout << "\t Total Kalah      : " << Lose << " (dalam stadium)" << endl;
    cout << "\t Jumlah Hari Main : " << SumOfDays << " hari" << endl;
    cout << "\t Status Hari ini  : "; if(DayOrNight == 1) cout << "Siang hari" << endl; else cout << "Malam hari" << endl;
    cout << "\n\n";
}
void Player::PrintListItem(ListOfItem *_ListOfItem) {
    cout<<"                       D A F T A R   I T E M   P E M A I N\n\n";
    if(ListPlayerItem.empty()) { cout << "Kosong" << endl; }
    else {
        cout << "\tNo\tJumlah\tNama Item" << endl;
		cout << "\t--------------------------------------------------" << endl;
        for(list<lItem>::iterator it = ListPlayerItem.begin(); it != ListPlayerItem.end(); ++it) {
            lItem tlItem = *it;
            cout << "\t" << int(tlItem.noItem) << "\t" << int(tlItem.nItem) << "\t";
            _ListOfItem->PrintName(tlItem.noItem);
            cout << endl;
        }
    }
    cout << "\n\n";
}
void Player::PrintListMonster(int hal) {
// hal dapat didefinisikan
    cout<<"                    D A F T A R   M O N S T E R   P L A Y E R\n\n";
    if(ListPlayerMonster.empty()) { cout << " Kosong " << endl; }
    else {
        cout << "  No | Nama Monster   | Level | Health Point" << endl;
        cout << " ------------------------------------------------------------------------------" << endl;
        int i = 1;
        std::list<PlayerMonster>::iterator it = ListPlayerMonster.begin();
        if(i < hal) {
            advance(it, 19);
            i++;
        }
        int no = 19*(hal - 1) + 1;
        while((it != ListPlayerMonster.end()) && (no <= 19)) {
            cout.width(5);
            cout << no << "|";
            cout.width(16);
            cout << it->getName() << "|";
            cout.width(7);
            cout << it->getCurLevel() << "|";
			cout.width(12);
            cout << it->getHP() << "%" << endl;
            no++;
            ++it;
        }
    }
    cout << "\n\n";
}
void Player::PrintListParty() {
    cout<<"              D A F T A R   P A R T Y   M O N S T E R   P L A Y E R\n\n";
    if(ListPlayerMonster.empty()) { cout << " Kosong " << endl; }
    else {
        cout << "  No | Nama Monster   | Level | Health Point" << endl;
        cout << " ------------------------------------------------------------------------------" << endl;
        int i = 1;
        int Total = ListPlayerMonster.size();
        for(std::list<PlayerMonster>::iterator it = ListPlayerMonster.begin(); (it != ListPlayerMonster.end()) && (i <= 6); ++it) {
            cout.width(5);
            cout << i << "|";
            cout.width(16);
            cout << it->getName() << "|";
            cout.width(7);
            cout << it->getCurLevel() << "|";
            cout.width(12);
			cout << it->getHP() << "%" << endl;
            i++;
        }
    }
    cout << "\n\n";
}
void Player::PrintInfoPartyMonster(int no, ListOfMonster * _ListOfMonster, ListOfSkill * _ListOfSkill) {
    list<PlayerMonster>::iterator it;
    it = ListPlayerMonster.begin();
    if(no > 1) advance(it, no - 1);
    PlayerMonster tPM = *it;
    Monster tMonster(_ListOfMonster->getMonster(tPM.getMonsterNumber()));
    int HPMax = 10 + (((tMonster.getHP() + (tPM.getIncHP()) + 100)*(tPM.getCurLevel()))/50);
    int Attack = 5 + (((tMonster.getAttack() + (tPM.getIncAttack()) + 50)*(tPM.getCurLevel()))/50);
    int Defense = 5 + (((tMonster.getDefense() + (tPM.getIncDefense()) + 50)*(tPM.getCurLevel()))/50);
    int Speed = 5 + (((tMonster.getSpeed() + (tPM.getIncSpeed()) + 50)*(tPM.getCurLevel()))/50);
    int CurHP = (tPM.getHP())*HPMax/100;
    
    // Ready
    cout<<"              I N F O   P A R T Y   M O N S T E R   P L A Y E R\n\n";
    cout << "| No Monster : "; cout.width(20); cout << left << tPM.getMonsterNumber();		cout << "|" << " Cur Exp    : " << tPM.getCurExp() << endl;
    cout << "| Nama       : "; cout.width(20); cout << tPM.getName();				cout << "|" << " HP         : " << tPM.getHP() << "% (" << CurHP << "/" << HPMax << ")\n";
    cout << "| Level      : "; cout.width(20); cout << tPM.getCurLevel();			cout << "|" << " Serangan   : " << Attack << endl;
    cout << "| Spesies    : "; cout.width(20); cout << tMonster.getSpesies();		cout << "|" << " Pertahanan : " << Defense << endl;
    cout << "| Stat Efek  : "; cout.width(20); cout << tPM.getStatusEffectName();   cout << "|" << " Kecepatan  : " << Speed << endl;
    cout << "| Elemen 1   : "; cout.width(20); cout << tMonster.getNameElemen1();   cout << "|" << " Skill 1    : "; cout.width(20); cout << left << _ListOfSkill->GetNameSkillFromNumberSkill(tPM.getSkill(0));
		cout << tPM.getPPOfSkill(0) << "/" << _ListOfSkill->GetPPMaxFromNumberSkill(tPM.getSkill(0)) << endl;
    cout << "| Elemen 2   : "; cout.width(20); cout << tMonster.getNameElemen2();	cout << "|" << " Skill 2    : "; cout.width(20); cout << left << _ListOfSkill->GetNameSkillFromNumberSkill(tPM.getSkill(1));
    	cout << tPM.getPPOfSkill(1) << "/" << _ListOfSkill->GetPPMaxFromNumberSkill(tPM.getSkill(1)) << endl;
    cout << "| Umur       : "; cout.width(20); cout << tPM.getCurAge();				cout << "|" << " Skill 3    : "; cout.width(20); cout << left << _ListOfSkill->GetNameSkillFromNumberSkill(tPM.getSkill(2));
    	cout << tPM.getPPOfSkill(2) << "/" << _ListOfSkill->GetPPMaxFromNumberSkill(tPM.getSkill(2)) << endl;
    cout << "| Total Exp  : "; cout.width(20); cout << tPM.getTotalExp();			cout << "|" << " Skill 4    : "; cout.width(20); cout << left << _ListOfSkill->GetNameSkillFromNumberSkill(tPM.getSkill(3));
		cout << tPM.getPPOfSkill(3) << "/" << _ListOfSkill->GetPPMaxFromNumberSkill(tPM.getSkill(3)) << endl; cout<< right;
	
    // cout << " Cur Exp    : " << it->getCurExp() << endl;
    // cout << " HP         : " << it->getHP() << "% (" << CurHP << "/" << HPMax << ")\n";
    // cout << " Serangan   : " << Attack << endl;
    // cout << " Pertahanan : " << Defense << endl;
    // cout << " Kecepatan  : " << Speed << endl;
    // cout << " Skill 1    : " << _ListOfSkill->GetNameSkillFromNumberSkill(it->getSkill(0)); // Nama skill (PP/PPmax)
		// cout.width(15);
		// cout << it->getPPOfSkill(0) << "/" << _ListOfSkill->GetPPMaxFromNumberSkill(it->getSkill(0)) << endl;
    // cout << " Skill 2    : " << _ListOfSkill->GetNameSkillFromNumberSkill(it->getSkill(1));
    	// cout.width(15);
		// cout << it->getPPOfSkill(1) << "/" << _ListOfSkill->GetPPMaxFromNumberSkill(it->getSkill(1)) << endl;
    // cout << " Skill 3    : " << _ListOfSkill->GetNameSkillFromNumberSkill(it->getSkill(2));
    	// cout.width(15);
		// cout << it->getPPOfSkill(2) << "/" << _ListOfSkill->GetPPMaxFromNumberSkill(it->getSkill(2)) << endl;
    // cout << " Skill 4    : " << _ListOfSkill->GetNameSkillFromNumberSkill(it->getSkill(3));
		// cout.width(15);
		// cout << it->getPPOfSkill(3) << "/" << _ListOfSkill->GetPPMaxFromNumberSkill(it->getSkill(3)) << endl;
    
}
bool Player::IsHaveMonsterEgg() {
    std::list<lItem>::iterator it1;
	it1 = ListPlayerItem.begin();
	while ((it1->noItem != 17) && (it1 != ListPlayerItem.end())) {
		it1++;
	}
    if(it1 == ListPlayerItem.end())
        return false;
    else
        return true;
}
void Player::HatchEgg(ListOfMonster * _LOM, ListOfSkill * _LOS, int no_monster, char * _Name) {
    // Level default = 9
    Monster tMonster(_LOM->getMonster(no_monster));
    int i = 0;
    
    
    // Ambil nama
    char Nama[15];
    while(((_Name[i] >= 'A') && (_Name[i] <= 'Z')) || ((_Name[i] >= 'a') && (_Name[i] <= 'z'))) {
        Nama[i] = _Name[i];
        i++;
    }
    for(int j = i; j < 15; j++)
        Nama[j] = '\0';
    
    // 
    int CurAge = 0;
    int CurLevel = 9; // Level default = 9
    int CurExp = 0;
    int TotalExp = CurLevel*CurLevel*CurLevel;
    int ExpMax = ((CurLevel+1)*(CurLevel + 1)*(CurLevel + 1)) - TotalExp;
    int IncHP = 0;
    int HP = 100;
    int IncAttack = 0;
    int Attack = tMonster.getAttack();
    int IncDefense = 0;
    int Defense = tMonster.getDefense();
    int IncSpeed = 0;
    int Speed = tMonster.getSpeed();
    int Skills[4] = {tMonster.getDefaultSkills1(), tMonster.getDefaultSkills2(), tMonster.getDefaultSkills3(), tMonster.getDefaultSkills4()};
    int PPOfSkills[4] = {_LOS->GetPPMaxFromNumberSkill(tMonster.getDefaultSkills1()), _LOS->GetPPMaxFromNumberSkill(tMonster.getDefaultSkills2()), _LOS->GetPPMaxFromNumberSkill(tMonster.getDefaultSkills3()), _LOS->GetPPMaxFromNumberSkill(tMonster.getDefaultSkills4())};
    int StatusEffect = 0;
    
    
    // Konstruksi agar menjadi player monster
    cout << no_monster << " " << Nama << " " << CurAge << " " << CurLevel << " " << CurExp << " " << ExpMax << " " << TotalExp << " " << IncHP << " " << HP << " " << IncAttack << " " << Attack << " " << IncDefense << " " << Defense << " " << IncSpeed << " " << Speed << " " << Skills << " " << PPOfSkills << " " << StatusEffect;
    system("pause");
    PlayerMonster _PM(no_monster, Nama, CurAge, CurLevel, CurExp, ExpMax, TotalExp, IncHP, HP, IncAttack, Attack, IncDefense, Defense, IncSpeed, Speed, Skills, PPOfSkills,StatusEffect);
    ListPlayerMonster.push_back(_PM);
}
int Player::TotalMonster() {
    return ListPlayerMonster.size();
}
PlayerMonster& Player::GetPlayerMonster(int i) {
    list<PlayerMonster>::iterator it;
    it = ListPlayerMonster.begin();
    if(i > 1) {
        advance(it, i - 1);
    }
    return *it;
}
void Player::SaveMonster(ListOfMonster * _LOM, ListOfSkill * _LOS, int no_monster, char * _Name) {
    Monster tMonster(_LOM->getMonster(no_monster));
    int i = 0;
    
    // Ambil nama
    char Nama[15];
    while(((_Name[i] >= 'A') && (_Name[i] <= 'Z')) || ((_Name[i] >= 'a') && (_Name[i] <= 'z'))) {
        Nama[i] = _Name[i];
        i++;
    }
    for(int j = i; j < 15; j++)
        Nama[j] = '\0';
    
    // 
    int CurAge = 0;
    int CurLevel = tMonster.getDefaultLevel();
    int CurExp = 0;
    int TotalExp = CurLevel*CurLevel*CurLevel;
    int ExpMax = ((CurLevel+1)*(CurLevel + 1)*(CurLevel + 1)) - TotalExp;
    int IncHP = 0;
    int HP = 100;
    int IncAttack = 0;
    int Attack = tMonster.getAttack();
    int IncDefense = 0;
    int Defense = tMonster.getDefense();
    int IncSpeed = 0;
    int Speed = tMonster.getSpeed();
    int Skills[4] = {tMonster.getDefaultSkills1(), tMonster.getDefaultSkills2(), tMonster.getDefaultSkills3(), tMonster.getDefaultSkills4()};
    int PPOfSkills[4] = {_LOS->GetPPMaxFromNumberSkill(tMonster.getDefaultSkills1()), _LOS->GetPPMaxFromNumberSkill(tMonster.getDefaultSkills2()), _LOS->GetPPMaxFromNumberSkill(tMonster.getDefaultSkills3()), _LOS->GetPPMaxFromNumberSkill(tMonster.getDefaultSkills4())};
    int StatusEffect = 0;
    
    
    // Konstruksi agar menjadi player monster
    cout << no_monster << " " << Nama << " " << CurAge << " " << CurLevel << " " << CurExp << " " << ExpMax << " " << TotalExp << " " << IncHP << " " << HP << " " << IncAttack << " " << Attack << " " << IncDefense << " " << Defense << " " << IncSpeed << " " << Speed << " " << Skills << " " << PPOfSkills << " " << StatusEffect;
    system("pause");
    PlayerMonster _PM(no_monster, Nama, CurAge, CurLevel, CurExp, ExpMax, TotalExp, IncHP, HP, IncAttack, Attack, IncDefense, Defense, IncSpeed, Speed, Skills, PPOfSkills,StatusEffect);
    ListPlayerMonster.push_back(_PM);
}