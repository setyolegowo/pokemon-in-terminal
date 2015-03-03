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
 * Nama File            : pokeranch.cpp
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Kamis, 14 Maret 2013
 * Deskripsi            : 
 * - 
 */

#include <iostream>
#include "pokeranch.h"

using std::cout;
using std::cin;
using std::endl;

#include "mynamespace.cpp"

PokeRanch::PokeRanch()
{
    listSkill.ReadFromFile();
    listItem.ReadFromFile();
    listPlayer.ReadFromFile();
}
PokeRanch::~PokeRanch()
{
    listSkill.ListOfSkill::~ListOfSkill();
    listItem.ListOfItem::~ListOfItem();
    listPlayer.ListOfPlayer::~ListOfPlayer();
}
void PokeRanch::LookTable()
{
    int i;
    bool Exit = false;
    
    while(!Exit) {
        cout << "\n\n.:: LOOK TABLE ::.\n\n";
        cout << "    1. Look Skill\n";
        cout << "    2. Look Item\n";
        cout << "    3. Look Monster\n";
        cout << "    4. Look Player\n";
        cout << "    5. Exit\n";
        cout << "\n\tChoose > ";
        cin >> i;
        switch(i)
        {
            case 1: listSkill.PrintList(); break;
            case 2: listItem.PrintListItem(); break;
            case 3: break;
            case 4: listPlayer.PrintPlayerRegistered(); break;
            default: Exit = true; break;
        }
    }
}
void PokeRanch::Start()
{
	bool Exit = false;
    unsigned char state = 255; // State maksudnya adalah posisi
    char user_input[255];
    char building[13];
    char GetName[8];
    char GetDirection[5];
    char GetNameItem[13];
    unsigned char command_respon = 255;
    unsigned char BuildingNumber = 0;
    short PlayerStep;
    short PlayerStepBringEgg;
    const short MaxPlayerStep = 700;
    const short MaxStepToCatch = 30;
    int i, j, num;
    
    while(!Exit)
    {
        // Penampilan di depan layar
        switch(state)
        {
            // [## STORY ##]
            case 0 : // Tampilan pemain pertama kali bermain
                i = 0;
            case 1 : // Tampilan pemain pertama kali bermain tampilan selanjutnya
                // -> Menampilkan story per langkah
                interface::BeginStory(i);
                interface::show_info(int(command_respon));
                // -> Menampilkan tampilan permintaan input
                interface::Input();
                cin.getline(user_input,255);
                break;
            // [## HOME ##]
            case 2 : // Tampilan di rumah.
                // -> Menampilkan gambar rumah
                interface::Home();
                interface::show_nonBattle(int(command_respon));
                // -> Menampilkan tampilan permintaan input
                interface::Input2();
                cin.getline(user_input,255);
                break;
            // [## CITY ##]
            case 3 :
                // -> Menampilkan gambar kota
                if((command_respon <= 10) || (command_respon == 255)) {
                    interface::City();
                    city.DrawPlayerPosition();
                    city.PrintMap();
                    cout << endl << "================================================================================";
                    if(command_respon == 10) Trainer.ShowStatus();
                    else interface::show_nonBattle(int(command_respon));
                } else {
                    interface::MiniCity();
                    switch(command_respon)
                    {
                        case 11: Trainer.PrintListItem(&listItem); break;
                        case 12: Trainer.PrintListMonster(num); break;
                        case 13: Trainer.PrintListParty(); Trainer.PrintInfoPartyMonster(num, &listMonster, &listSkill); break;
                    }
                }
                // -> Menampilkan tampilan permintaan input
                interface::Input2();
                cin.getline(user_input,255);
                break;
            // [## COMBINATORIUM ##]
            case 4 :
                // -> Menampilkan gambar combinatorium
                interface::Combinatorium();
                interface::show_nonBattle(int(command_respon));
                // -> Menampilkan tampilan permintaan input
                interface::Input2();
                cin.getline(user_input,255);
                break;
            // [## STADIUM ##]
            case 5 :
                // -> Menampilkan gambar stadium
                interface::Stadium();
                interface::show_nonBattle(int(command_respon));
                // -> Menampilkan tampilan permintaan input
                interface::Input2();
                cin.getline(user_input,255);
                break;
            // [## STORE ##] [## SHOP ##]
            case 6:
                // -> Menampilkan gambar toko
                interface::Store();
                if((command_respon < 10) || (command_respon == 255)) {
                    interface::Store();
                    interface::show_nonBattle(int(command_respon));
                } else {
                    interface::MiniStore();
                    switch(command_respon)
                    {
                        case 10: listItem.PrintListItem(); break;
                    }
                }
                // -> Menampilkan tampilan permintaan input
                interface::Input2();
                cin.getline(user_input,255);
                break;
            // [## OUTER AREA ##]
            case 7: // OUTER AREA
                outerArea.RandomUnstapable();
                outerArea.RandomMonster();
                outerArea.DrawTeleport();
            case 8:
                // -> Menampilkan area terluar
                interface::ClearScreen();
                outerArea.DrawPlayerPosition();
                outerArea.PrintMap();
                interface::OuterArea();
                interface::show_nonBattle(int(command_respon));
                // -> Menampilkan tampilan permintaan input
                interface::Input2();
                cin.getline(user_input,255);
                break;
            // [## STORY ##]
            case 9: // Battle OUTER AREA
                break;
            case 10: // Battle STADIUM
                break;
            case 11:
                // -> Menampilkan gambar rumah
                interface::Home();
                interface::show_info(int(command_respon));
                // -> Menampilkan tampilan permintaan input
                interface::Input2();
                cin.getline(user_input,255);
                break;
            case 12:
                // -> Menampilkan gambar kota
                interface::City();
                interface::show_info(int(command_respon));
                // -> Menampilkan tampilan permintaan input
                interface::Input2();
                cin.getline(user_input,255);
                break;
            case 13:
                // -> Menampilkan gambar Poke Store
                interface::Store();
                interface::show_info(int(command_respon));
                // -> Menampilkan tampilan permintaan input
                interface::Input2();
                cin.getline(user_input,255);
                break;
            default: // Default adalah menu tampilan utama
                // -> Menampilkan tampilan utama
                interface::start_game();
                interface::show_info(int(command_respon));
                // -> Menampilkan tampilan permintaan input
                interface::Input();
                cin.getline(user_input,255);
                break;
        }
        
        // Proses input
        switch(state)
        {
            // [## STORY ##]
            case 0: 
            case 1: // Pemberian cerita awal
                command_respon = input_manager::getNoCommand(user_input);
                if(command_respon > 0) {
                    if((command_respon >= 3) && (command_respon <= 5)) {
                        if(command_respon == 3) { command_respon = 3; } 
                        else if(command_respon == 4) { Exit = true; } 
                        else {
                            if(i < 26) {
                                i++;
                                state = 1;
                            } else {
                                listPlayer.MakePlayer(&Trainer, GetName);
                                i = 0; // Reset
                                state = 2; // Goto Home
                            }
                            command_respon = 255;
                        }
                    } else command_respon = 1; // berarti menggunakan komando yang lain
                } else command_respon = 1;
                break;
            // [## HOME ##]
            case 2: // Di bangunan HOME
                command_respon = input_manager::getNoCommand(user_input);
                if(command_respon > 0) {
                    if(((command_respon >= 6) && (command_respon <= 8)) || ((command_respon >= 2) && (command_respon <= 4))) {
                        switch(command_respon)
                        {
                            case 2:
                                // Jika nama pengguna yang di load ditemukan, game reset dan meload nama pengguna tersebut
                                if(listPlayer.IsOnTable(GetName)) {
                                    listPlayer.ReadPlayer(&Trainer,GetName);
                                    state=2;
                                    command_respon = 255;
                                }
                                break;
                            case 3: command_respon = 2; break; // Tampilkan help
                            case 4: Exit = true; break; // Keluar dari program tanpa melakukan proses save
                            case 6:
                            case 7:
                                if(Trainer.GetDayOrNight() == 0) {
                                    Trainer.AddSumOfDays(1);
                                    Trainer.ChangeDayOrNight(1);
                                } else Trainer.ChangeDayOrNight(0); // Waktu bertambah.
                                Trainer.RestoreAllMonster(&listSkill); // Restore HP dan stat monster-player
                                if(command_respon == 7) listPlayer.SavePlayer(Trainer); // Menyimpan data pengguna, menulis ke file.
                                command_respon = 2;
                                break;
                            case 8:
                                state = 3;
                                city.FixUnstapableArea();
                                command_respon = 255;
                                city.UpdatePlayerPosition(1,0);
                                // Pindah state ke kota.
                                break;
                        }
                    } else command_respon = 1; // berarti menggunakan komando yang lain
                } else command_respon = 1;
                break;
            // [## CITY ##]
            case 3: // State 3 adalah state di kota
                command_respon = input_manager::getNoCommand(user_input);
                if(command_respon > 0) { // Menerima: 3, 9, 10, 11, 12, 13, 14, 15, 16, 17
                    if((command_respon == 3) || (command_respon == 4) || ((command_respon >= 9) && (command_respon <= 18))) {
                        if(command_respon == 3) {
                            // Menampilkan HELP
                            num = input_manager::getNumberN(user_input,2);
                            if(num == 1) command_respon = 3;
                            else if(num == 2) command_respon = 4;
                            else command_respon = 1;
                        } else if(command_respon == 4) { Exit = true; } // Keluar dari permainan
                        else {
                            switch(command_respon)
                            {
                                case 9: // Melakukan teleport ke suatu nama bangunan
                                    input_manager::getSecond(user_input,building,13);
                                    if(building[0] == 0) command_respon = 1;
                                    else {
                                        BuildingNumber = input_manager::getNoBuilding(building);
                                        command_respon = 255;
                                        switch(BuildingNumber)
                                        {
                                            case 1: city.DoTeleport(1); break;
                                            case 2: city.DoTeleport(2); break;
                                            case 3: city.DoTeleport(3); break;
                                            case 4: city.DoTeleport(4); break;
                                            case 5: city.DoTeleport(5); break;
                                                // Posisi pemain pindah sesuai dengan posisi pintu bangunan
                                                // command_respon = 255; // ## BELUM
                                                // break;
                                            default: command_respon = 1; break; // Maka nomor bangunan tidak terdefinisi
                                        }
                                    }
                                    break;
                                case 10: // Melakukan gerak
                                    num = input_manager::getNumberN(user_input, 3);
                                    input_manager::getSecond(user_input, GetDirection, 5);
                                    i = input_manager::getNumDirection(GetDirection);
                                    if(i > 0) {
                                        city.MovePlayerPosition(i,num);
                                        command_respon = 255;
                                    } else command_respon = 1;
                                    i = 0; // Reset
                                    break;
                                case 11: // Menampilkan list monster // ### BELUM
                                    num = input_manager::getNumberN(user_input,2);
                                    if((num > 0) && ((num - 1) <= ((Trainer.TotalMonster() - 1)/19)) && (Trainer.TotalMonster() > 0)) command_respon = 12;
                                    else command_respon = 1;
                                    break;
                                case 12: // Menampilkan list party // ### BELUM
                                    num = input_manager::getNumberN(user_input,2);
                                    if((num > 0) && (num <= Trainer.TotalMonster()) && (num <= 6)) command_respon = 13;
                                    else command_respon = 1;
                                    break;
                                case 13: // Menampilkan list item
                                    command_respon = 11;
                                    break;
                                case 14: // Menampilkan status pemain (Nama pemain, Money, Win, Lose, SumOfDay, DayOrNight)
                                    command_respon = 10;
                                    break;
                                case 15: // Melakukan set dari nomor-list-monster ke no-party pemain
                                    num = input_manager::getNumberN(user_input,2);
                                    if((num > 0) && (num <= Trainer.TotalMonster())) { // Jika masukan player benar
                                        if(num > 1) Trainer.ChangeParty(1, num);
                                        command_respon = 255;
                                    } else command_respon = 1;
                                    break;
                                case 16: // Menukar posisi party [1..6]
                                    i = input_manager::getNumberN(user_input,2);
                                    j = input_manager::getNumberN(user_input,3);
                                    num = Trainer.TotalMonster();
                                    if((i > 0) && (j > 0) && (i <= num) && (j <= num) && (i <= 6) && (j <= 6)) { // Jika masukan player benar
                                        if(i != j) Trainer.ChangeParty(i, j);
                                        command_respon = 255;
                                    } else command_respon = 1;
                                    break;
                                case 17: // Menghapus monster dari list-monster-pemain.
                                    i = input_manager::getNumberN(user_input,2);
                                    if((i > 0) && (i <= Trainer.TotalMonster()) && (Trainer.TotalMonster() > 1)) {
                                        Trainer.DelMonster(i);
                                        command_respon = 255;
                                    } else command_respon = 1;
                                    break;
                                case 18:
                                    // Jika posisinya memungkinkan maka masuk ke dalam bangunan.
                                    // Teleport bisa ke titik teleport yang sedang diinjaknya.
                                    // Pertama, deteksi apakah titik teleport tersebut milik siapa, atau bukan milik siapa2
                                    // Lalu, pindah ke state bangunan tersebut.
                                    city.UpdatePlayerPosition(1,0);
                                    switch(city.ValidTeleport()) {
                                        case 5 : 
                                            if(Trainer.TotalMonster() > 0)
                                                state = 4;
                                            else command_respon = 1;
                                            break;
                                        case 4 : state = 2; 
                                            // -> Jika player punya monster egg, maka menetas disini
                                            if(Trainer.IsHaveMonsterEgg()) {
                                                // Beri nama untuk monster
                                                cout << "\n\t Telor monster Anda telah menetas. Beri nama: ";
                                                cin.getline(user_input,255);
                                                while(((user_input[0] < 'A') || (user_input[0] > 'Z')) && ((user_input[0] < 'a') || (user_input[0] > 'z'))) {
                                                    cout << "Karakter tidak diterima. Beri nama yang terdiri dari alfabet saja.\n";
                                                    cout << "Beri nama: ";
                                                    cin.getline(user_input,255);
                                                }
                                                int no_monster = input_manager::RandomMonsterEggHatched();
                                                Trainer.HatchEgg(&listMonster, &listSkill, no_monster, user_input);
                                                Trainer.DelListItem(17,1);
                                            }
                                            break;
                                        case 6 : 
                                            if(Trainer.TotalMonster() > 0) state = 5;
                                            else command_respon = 1;
                                            break;
                                        case 7 : state = 6; break;
                                        case 8 : 
                                            if(Trainer.TotalMonster() > 0) {
                                                state = 7;
                                                outerArea.ChangeFloorLevel(1); 
                                            } else command_respon = 1;
                                            break;
                                    }
                                    if(command_respon == 18) command_respon = 255;
                                    break;
                            }
                        }
                    } else command_respon = 1; // berarti menggunakan komando yang lain
                } else command_respon = 1;
                break;
            // [## COMBINATORIUM ##]
            case 4: // State 4, trainer berada di Combinatorium
            // Asumsi: Kombinasi selalu berhasil untuk monster yang bisa dikombinasi.
                command_respon = input_manager::getNoCommand(user_input);
                if(command_respon > 0) { // Menerima: 3, 4, 8, 25
                    if(command_respon == 3) command_respon = 5;
                    else if(command_respon == 4) Exit = true;
                    else if(command_respon == 8) {
                        state = 3;
                        city.FixUnstapableArea();
                        city.UpdatePlayerPosition(1,0);
                        command_respon = 255;
                    } else if(command_respon == 25) {
                    
                    
                    
                        // Melakukan proses kombinasi...
                        
                        
                        
                        
                    } else command_respon = 1; // berarti menggunakan komando yang lain
                } else command_respon = 1;
                break;
            // [## STADIUM ##]
            case 5: // State 5, trainer berada di stadium
                command_respon = input_manager::getNoCommand(user_input);
                if(command_respon > 0) { // Menerima: 3, 4, 8, 26
                    if(command_respon == 3) command_respon = 6;
                    else if(command_respon == 4) Exit = true;
                    else if(command_respon == 8) {
                        state = 3;
                        city.FixUnstapableArea();
                        city.UpdatePlayerPosition(1,0);
                        command_respon = 255;
                    } else if(command_respon == 26) {
                    
                    
                    
                    
                        // Melakukan proses battle...
                        // Periksa juga jumlah taruhannya
                        
                        
                        
                        
                        
                    } else command_respon = 1; // berarti menggunakan komando yang lain
                } else command_respon = 1;
                break;
            // [## SHOP ##] [## STORE ##]
            case 6:
                command_respon = input_manager::getNoCommand(user_input);
                if(command_respon > 0) { // Menerima: 3, 4, 8, 27, 28, 29
                    if(command_respon == 3) command_respon = 7;
                    else if(command_respon == 4) Exit = true;
                    else if(command_respon == 8) {
                        state = 3;
                        city.FixUnstapableArea();
                        city.UpdatePlayerPosition(1,0);
                        command_respon = 255;   
                    } else if(command_respon == 27) {
                        input_manager::getSecond(user_input, GetNameItem, 12);
                        i = listItem.IsOnTable(GetNameItem);
                        if(i > 0) {
                            num = input_manager::getNumberN(user_input, 3);
                            j = listItem.GetPrice(i);
                            // cout << i << ", " << j << ", " << num << ": " << GetNameItem << endl;
                            // system("pause");
                            if(j*num <= Trainer.GetMoney()) {
                                Trainer.DecMoney(j*num);
                                Trainer.AddListItem((unsigned char) i, (unsigned char) num);
                                command_respon = 255;
                            } else
                                command_respon = 1;
                        }
                    } else if(command_respon == 28) {
                        input_manager::getSecond(user_input, GetNameItem, 12);
                        i = listItem.IsOnTable(GetNameItem);
                        if(i > 0) {
                            num = input_manager::getNumberN(user_input, 3);
                            j = listItem.GetPrice(i);
                            // cout << i << ", " << j << ", " << num << ": " << GetNameItem << endl;
                            // system("pause");
                            if(j*num <= Trainer.GetMoney()) {
                                Trainer.IncMoney(j*num/2);
                                Trainer.DelListItem((unsigned char) i, (unsigned char) num);
                                command_respon = 255;
                            } else
                                command_respon = 1;
                        }
                    } else if(command_respon == 29) {
                        command_respon = 10;
                    } else command_respon = 1; // berarti menggunakan komando yang lain
                } else command_respon = 1;
                break;
            // [## OUTER AREA ##]
            case 7: // OUTER AREA
            case 8:
                state = 8;
                outerArea.EnableMoves();
                command_respon = input_manager::getNoCommand(user_input);
                if(command_respon > 0) { // Menerima: 3, 4, 10, 11, 12, 13, 14, 16, 17, 18
                    if(command_respon == 3) {
                        command_respon = 8;
                    } else if(command_respon == 4) {
                        Exit = true;
                    } else if((command_respon >=10) && (command_respon <= 18) && (command_respon != 15)){
                        switch(command_respon)
                        {
                            case 10:
                                num = input_manager::getNumberN(user_input, 3);
                                input_manager::getSecond(user_input, GetDirection, 5);
                                i = input_manager::getNumDirection(GetDirection);
                                if(i > 0) {
                                    outerArea.UpdatePlayerPosition(i,num);
                                    if(outerArea.IsBattleWithMonster())
                                        state = 9;
                                    command_respon = 255;
                                } else command_respon = 1;
                                i = 0;
                                break;
                            case 18:
                                // outerArea.UpdatePlayerPosition(1,0);
                                cout << int(outerArea.ValidTeleport()) << endl;
                                system("pause");
                                if(int(outerArea.ValidTeleport()) == 9) {
                                    if(outerArea.GetFloorLevel() == 1) {
                                        state = 3;
                                        city.FixUnstapableArea();
                                        city.UpdatePlayerPosition(1,0);
                                    } else {
                                        outerArea.ChangeFloorLevel(outerArea.GetFloorLevel() - 1);
                                        state = 7;
                                    }
                                    command_respon = 255;
                                } else if(int(outerArea.ValidTeleport()) == 10) {
                                    if(outerArea.GetFloorLevel() == 7)
                                        command_respon = 1;
                                    else {
                                        outerArea.ChangeFloorLevel(outerArea.GetFloorLevel() - 1);
                                        state = 7;
                                    }
                                } else command_respon = 1;
                                break;
                            // CASE LAIN BELUM
                            
                        }
                    } else command_respon = 1; // berarti menggunakan komando yang lain
                } else command_respon = 1;
                break;
            // [## BATTLE 1 ##]
            case 9: // Battle OUTER AREA
                BattleWild(&command_respon);
                if(command_respon == 0) {
                    state = 2;
                    if(Trainer.GetDayOrNight() == 1) {
                        Trainer.AddSumOfDays(1);
                        Trainer.ChangeDayOrNight(0);
                    } else Trainer.ChangeDayOrNight(1); // Waktu bertambah.
                    Trainer.RestoreAllMonster(&listSkill);
                    city.DoTeleport(3);
                    command_respon = 255;
                } else {
                    state = 8;
                    command_respon = 255;
                }
                outerArea.EnableMoves();
                break;
            // [## BATTLE 2 ##]
            case 10: // Battle Stadium
                command_respon = input_manager::getNoCommand(user_input);
                if(command_respon > 0) { // Menerima: 3, 4, 22, 23, 24
                    if(command_respon == 3) command_respon = 7;
                    else if(command_respon == 4) Exit = true;
                    else if((command_respon >= 22) && (command_respon <= 25)) {
                        
                        
                        
                        // Komando-komado game...
                        
                        
                        
                        
                        command_respon = 255;  
                    } else command_respon = 1; // berarti menggunakan komando yang lain
                } else command_respon = 1;
                break;
            case 11:
                command_respon = input_manager::getNoCommand(user_input);
                if(command_respon > 0) {
                    switch(command_respon)
                    {
                        case 2: // ### BELUM
                            // Jika nama pengguna yang di load ditemukan, game reset dan meload nama pengguna tersebut
                            break;
                        case 3: command_respon = 7; break; // Tampilkan help
                        case 4: Exit = true; break;
                        case 8:
                            state = 12;
                            command_respon = 255;
                            // Pindah state ke kota.
                            break;
                        default: command_respon = 1; break;
                    }
                } else command_respon = 1;
                break;
            case 12:// State 3 adalah state di kota, tapi terbatas (Hanya bisa ke HOME atau STORE)
                command_respon = input_manager::getNoCommand(user_input);
                if(command_respon > 0) { // Menerima: 3, 4, 10, 18
                    if(command_respon == 3) command_respon = 8; // Menampilkan HELP
                    else if(command_respon == 4) Exit = true; // Keluar dari permainan
                    else if(command_respon == 10) {
                        num = input_manager::getNumberN(user_input, 2);
                        input_manager::getSecond(user_input, GetDirection, 5);
                        i = input_manager::getNumDirection(GetDirection);
                        if(i > 0) {
                            outerArea.UpdatePlayerPosition(i,num);
                            command_respon = 255;
                        } else command_respon = 1;
                        i = 0;
                    } else if(command_respon == 18) { // ### BELUM
                        // Hanya bisa menerima posisi didepan bangunan store atau rumah.
                    } else command_respon = 1; // berarti menggunakan komando yang lain
                } else command_respon = 1;
                break;
            case 13:
                command_respon = input_manager::getNoCommand(user_input);
                if(command_respon > 0) { // Menerima: 3, 4, 8, 27, 29
                    if(command_respon == 3) command_respon = 9;
                    else if(command_respon == 4) Exit = true;
                    else if(command_respon == 8) {
                        state = 12;
                        command_respon = 255;
                    // } else if(command_respon == 27) {
                        
                    // } else if(command_respon == 29) {
                        
                    } else command_respon = 1; // berarti menggunakan komando yang lain
                } else command_respon = 1;
                break;
            // [## MAINMENU ##]
            default: // Default adalah bagian penerima input
                command_respon = input_manager::getNoCommand(user_input);
                if(command_respon > 0) {
                    if((command_respon >= 1) && (command_respon <= 4)) {
                        if(command_respon == 1) {
                            input_manager::getSecond(user_input, GetName, 7);
                            if(!listPlayer.IsOnTable(GetName)) {
                                if(GetName[0] == '\0') command_respon = 4; // Teks tidak masuk akal
                                else {
                                    command_respon = 255;
                                    state = 0;
                                }
                            } else command_respon = 5; // User ada
                        } else if(command_respon == 2) {
                            input_manager::getSecond(user_input, GetName, 7);
                            if(listPlayer.IsOnTable(GetName)) {
                                listPlayer.ReadPlayer(&Trainer,GetName);
                                state=2;
                                PlayerStep = 0;
                                command_respon = 255;
                            } else {
                                if(GetName[0] == '\0') command_respon = 4; // Teks tidak masuk akal
                                else command_respon = 6;
                            }
                        } else if(command_respon == 3) command_respon = 2;
                        else Exit = true;// pasti command_respon == 4
                    } else command_respon = 1; // berarti menggunakan komando yang lain
                } else command_respon = 1;
                break;
        }
    }
}
void PokeRanch::BattleWild(unsigned char *result)
{
    struct MonsterActive {
        unsigned short NoMonster;
        short HPMax;
        short HP;
        short Atk;
        short Dfn;
        short Spd;
        float Acc;
    };
    int WildMonsterEffect;
    MonsterActive WildMonster;
    MonsterActive ActiveMonster;
    unsigned short MN,PN = 1; // Buat nomor monster dan Party Number
    char user_input[50];
    char item_use[20];
    int item_num_use, num, try_escape;
    unsigned char command_respon;
    bool EscapeSuccesfully = false, SuccessUseBall = false;
    int SkillUsePlayer;
    int SkillUseWildM;
    
    // //Mengambil no-monster liar secara acak sesuai level lantai...
    MN = (unsigned short) input_manager::RandomSelectMonsterFloor(outerArea.GetFloorLevel());
    cout << int(MN) << endl;

    // //Mengeset Monster Liar Aktif ke variabel lokal.
    Monster MR(listMonster.getMonster(int(MN)));
    
    // *** 1 ***
    // //Melakukan konstruksi HP, Attack, Defense, Speed, dan Accuracy Monster Liar
    WildMonster.HPMax = (((MR.getHP()+ 100)*MR.getDefaultLevel())/50) + 10;
    WildMonster.HP = WildMonster.HPMax;
    WildMonster.Atk = (((MR.getAttack()+ 50)*MR.getDefaultLevel())/50) + 5;
    WildMonster.Dfn = (((MR.getDefense()+ 50)*MR.getDefaultLevel())/50) + 5;
    WildMonster.Spd = (((MR.getSpeed()+ 50)*MR.getDefaultLevel())/50) + 5;
    WildMonster.Acc = 1.0;
    WildMonsterEffect = 0;
    
    // *** 2 ***
    //Memilih monster player yang akan diaktifkan dari listParty yang HP != 0
    PlayerMonster PlayerMonster1 = Trainer.GetPlayerMonster(PN);
    while((PlayerMonster1.getHP() == 0) && (PN < 7) && (PN < Trainer.TotalMonster())) {
        PN++;
        PlayerMonster1 = Trainer.GetPlayerMonster(PN);
    }
    Monster Monster1(listMonster.getMonster(PlayerMonster1.getMonsterNumber()));
    cout << PN << " : " << PlayerMonster1.getMonsterNumber() << endl;
    
    if((PN < 7) && (PN <= Trainer.TotalMonster())) { // Jika monster yang availabel bertarung
        // *** 3 ***
        // //Melakukan konstruksi HP, Attack, Defense, Speed, dan Accuracy Monster Pemain
        ActiveMonster.HPMax = (((Monster1.getHP() + PlayerMonster1.getIncHP() + 100)*PlayerMonster1.getCurLevel())/50) + 10;
        ActiveMonster.HP = ActiveMonster.HPMax*(PlayerMonster1.getHP())/100;
        ActiveMonster.Atk = (((Monster1.getAttack()+ PlayerMonster1.getIncAttack() + 50)*PlayerMonster1.getCurLevel())/50) + 5;
        ActiveMonster.Dfn = (((Monster1.getDefense()+ PlayerMonster1.getIncDefense() + 50)*PlayerMonster1.getCurLevel())/50) + 5;
        ActiveMonster.Spd = (((Monster1.getSpeed() + PlayerMonster1.getIncSpeed() + 50)*PlayerMonster1.getCurLevel())/50) + 5;
        ActiveMonster.Acc = 1.0;

        bool AcceptCR = false; // Menentukan apakah komando akan masuk kedalam battle.
        bool ChangePoke = false;
        command_respon = 255;
        
        while((ActiveMonster.HP != 0) && (WildMonster.HP !=0) && (!EscapeSuccesfully) && (!SuccessUseBall))
        {
            do {
                // *** 4 ***
                // Menampilkan pertarungan
                // Wild Monster: Level, element1, percent HP, StatusEfek
                // PlayerMonster: Level, element1, percent HP, CurrentHP/HPMax, StatusEfek, ListSkill dengan curPP/PPMax
                interface::BattleWildTitle();
                if(command_respon == 255) {
                    cout << " Level        : " << MR.getDefaultLevel() << "   " << MR.getSpesies() << endl;
                    cout << " Health Point : " << 100*WildMonster.HP/WildMonster.HPMax << "%" << endl;
                    cout << " Elemen       : " << MR.getNameElemen1() << endl; // 
                    cout << " Status Efek  : " << input_manager::getStatusEffectName(WildMonsterEffect) << endl;
                    cout.width(58);
                    cout << " Level        : " << PlayerMonster1.getCurLevel() << "   " << PlayerMonster1.getName() << "  " << endl;
                    cout.width(58);
                    cout << " Health Point : " << ActiveMonster.HP << "/" << ActiveMonster.HPMax << endl;
                    cout.width(58);
                    cout << " Elemen       : " << Monster1.getNameElemen1() << endl; // 
                    cout.width(58);
                    cout << " Status Efek  : " << PlayerMonster1.getStatusEffectName() << endl;
                    cout << "\n================================================================================\n";
                    cout.width(20);
                    cout << listSkill.GetNameSkillFromNumberSkill(PlayerMonster1.getSkill(0));
                    cout.width(40);
                    cout << listSkill.GetNameSkillFromNumberSkill(PlayerMonster1.getSkill(1)) << endl;
                    cout.width(20);
                    cout << PlayerMonster1.getPPOfSkill(0) << "/" << listSkill.GetPPMaxFromNumberSkill(PlayerMonster1.getSkill(0));
                    cout.width(40);
                    cout << PlayerMonster1.getPPOfSkill(1) << "/" << listSkill.GetPPMaxFromNumberSkill(PlayerMonster1.getSkill(1)) << endl << endl;
                    cout.width(20);
                    cout << listSkill.GetNameSkillFromNumberSkill(PlayerMonster1.getSkill(2));
                    cout.width(40);
                    cout << listSkill.GetNameSkillFromNumberSkill(PlayerMonster1.getSkill(3)) << endl;
                    cout.width(20);
                    cout << PlayerMonster1.getPPOfSkill(2) << "/" << listSkill.GetPPMaxFromNumberSkill(PlayerMonster1.getSkill(2));
                    cout.width(40);
                    cout << PlayerMonster1.getPPOfSkill(3) << "/" << listSkill.GetPPMaxFromNumberSkill(PlayerMonster1.getSkill(3)) << endl << endl;
                } else if(command_respon == 3) {
                    cout << "\n   \"ESCAPE\"           : Kabur";
                    cout << "\n   \"ITEM <item-name>\" : Menggunakan item";
                    cout << "\n   \"LIST_PARTY\"       : Melihat daftar party.";
                    cout << "\n   \"LIST-ITEM\"        : Melihat daftar item didalam tas.";
                    cout << "\n";
                } else if(command_respon == 12) {
                    Trainer.PrintListParty();
                    Trainer.PrintInfoPartyMonster(num, &listMonster, &listSkill);
                } else if(command_respon == 13) {
                    Trainer.PrintListItem(&listItem);
                }
                // *** 5 ***
                // Meminta perintah dari user
                cout << "\n================================================================================";
                cout << " Command > ";
                cin.getline(user_input,50);
                command_respon = input_manager::getNoCommand(user_input);
                
                // *** 6 ***
                // Pemeriksaan perintah diterima atau tidak
                if(command_respon > 0) {
                    if(command_respon == 3) {
                        AcceptCR = false; // Show help
                    } else if(command_respon == 12) {
                        // List Party
                        num = input_manager::getNumberN(user_input, 3);
                        AcceptCR = false;
                    } else if(command_respon == 13) {
                        // List Item
                        AcceptCR = false;
                    } else if(command_respon == 21) {
                        // Want to escape dan menentukan berhasil kabur atau tidak
                        // Jika tidak player is first but failed
                        if(((PlayerMonster1.getCurLevel()*32/(MR.getDefaultLevel()/4) + 30)*try_escape) > 255) {
                            EscapeSuccesfully = true;
                        } else {
                            try_escape++;
                        }
                        AcceptCR = true;
                    } else if(command_respon == 22) {
                        // Name of item use <-- Harus dicek dahulu item yang bisa digunakan
                        input_manager::getSecond(user_input,item_use,19);
                        if(((item_use[0] >= 'A') && (item_use[0] <= 'Z')) || ((item_use[0] >= 'a') && (item_use[0] <= 'z'))) item_num_use = 0;
                        else item_num_use = listItem.IsOnTable(item_use);
                        cout << item_use << " : " << item_num_use << endl;
                        system("pause");
                        if(((item_num_use > 0)  && (item_num_use < 8)) || ((item_num_use < 17) && (item_num_use > 11))) { 
                            if(Trainer.IsItemAda(item_num_use)) AcceptCR = true;
                            else AcceptCR = false;
                        }
                        else {
                            AcceptCR = false;
                            command_respon = 0;
                        }
                    } else if(command_respon == 24) {
                        // Use skill <-- Cek nomor skill yang akan dipakai
                        SkillUsePlayer = input_manager::getNumberN(user_input, 2);
                        if((SkillUsePlayer <= 4) && (SkillUsePlayer > 0)) {
                            if((PlayerMonster1.getPPOfSkill(SkillUsePlayer - 1) > 0) && (PlayerMonster1.getSkill(SkillUsePlayer - 1) > 0)) {
                                AcceptCR = true;a
                                SkillUsePlayer--; // Digunakan lagi saat penggunaan skill
                                command_respon = 255;
                            } else { 
                                command_respon = 0;
                                AcceptCR = false;
                            }
                        } else {
                            AcceptCR = false;
                            command_respon = 0; // <-- Tanda komando tidak diterima
                        }
                    } else {
                        command_respon = 0;
                    }
                } else command_respon = 0;
                if(command_respon == 0) {
                    cout << "\n\tKomando tidak diterima..."; input_manager::delay(1);
                    command_respon = 255;
                }
            } while(!AcceptCR);
            if(!EscapeSuccesfully) { // ==>>Use of battle
                // Penentuan Skill Wild Monster
                unsigned char turn = 1;
                // *** 8 ***
                // Penentuan first term
                bool IsPlayerFirst;
                if((command_respon >= 21) || (command_respon <= 23)) {
                    if(command_respon == 21) {
                        turn = 2;
                        cout << "\n\t\tGagal Kabur"; input_manager::delay(1);
                    }
                    IsPlayerFirst = true;
                } else { // command_respon == 24
                    // Perhitungan speed dan penentuan siapa yang pertama
                    if((WildMonster.Spd < ActiveMonster.Spd) && ((rand() % 10) > 2))
                        IsPlayerFirst = true;
                    else
                        IsPlayerFirst = false;
                }
                // *** 9 ***
                int Damage;
                while(turn <= 2) {
                    cout << "\n\n Turn " << int(turn) << " : ";
                    // Player phase
                    if((IsPlayerFirst && (turn == 1)) || (!IsPlayerFirst && (turn == 2))) {
                        // *** 9a ***
                        cout << " --> Fase pemain"; input_manager::delay(1);
                        if(command_respon == 22) { // Jika mengunakan item
                            if((item_num_use >= 1) && (item_num_use <= 3)) {
                                cout << "\n\t--> Mencoba melempar bola monster"; input_manager::delay(3);
                                if(((100*(3*WildMonster.HPMax - 2*WildMonster.HP)*(rand() % 10)/7)/(3*WildMonster.HPMax*item_num_use)) < 20) {
                                    cout << "\n\t Anda berhasil menangkap monster ini. Beri nama: ";
                                    cin.getline(user_input,50);
                                    while(((user_input[0] < 'A') || (user_input[0] > 'Z')) && ((user_input[0] < 'a') || (user_input[0] > 'z'))) {
                                        cout << "\n\t Karakter tidak diterima. Beri nama yang terdiri dari alfabet saja.";
                                        cout << "\n\t Beri nama: ";
                                        cin.getline(user_input,50);
                                    }
                                    Trainer.SaveMonster(&listMonster, &listSkill, MN, user_input);
                                    SuccessUseBall = true;
                                    Trainer.DelListItem(item_num_use,1);
                                    turn = 2;
                                    if(PN >= 6) cout << "\n\t--> Monster ini telah dikirim ke rumah Anda.";
                                } else {
                                    cout << "\n\t--> Gagal menangkap monster";
                                }
                            } else if((item_num_use >= 4) && (item_num_use <= 7)) {
                                if(Trainer.IsItemAda(item_num_use)) {
                                    if(ActiveMonster.HP+listItem.GetValue(item_num_use) >= ActiveMonster.HPMax)
                                        ActiveMonster.HP = ActiveMonster.HPMax;
                                    else
                                        ActiveMonster.HP+=listItem.GetValue(item_num_use);
                                    Trainer.DelListItem(item_num_use, 1);
                                } else {
                                    cout << "\n\t--> Item tidak ada...";
                                }
                            } else if((item_num_use >= 12) && (item_num_use <= 16)) {
                                if(Trainer.IsItemAda(item_num_use)) {
                                    if(listItem.GetValue(item_num_use) == PlayerMonster1.getStatusEffect()) {
                                        cout << "\n\t--> Berhasil menyehatkan monster player dari " << PlayerMonster1.getStatusEffectName();
                                        PlayerMonster1.ChangeEffect(0);
                                    } else {
                                        cout << "\n\t--> Gagal menyehatkan monster player dari " << PlayerMonster1.getStatusEffectName();
                                    }
                                } else {
                                    cout << "\n\t--> Item tidak ada...";
                                }
                            } else {
                                cout << "\n\t--> Item tidak ada...";
                            }
                             input_manager::delay(1);
                        } else { // Jika menggunakan skill
                            // *** 9b ***
                            Skill UseSkill = listSkill.GetSkill(PlayerMonster1.getSkill(SkillUsePlayer));
                            cout << "\n\t--> Monster pemain menggunakan skill " << listSkill.GetNameSkillFromNumberSkill(PlayerMonster1.getSkill(SkillUsePlayer)); input_manager::delay(1);
                            if((int(double(UseSkill.GetAccuracy() + (((rand() % 20) + 96)/100))*ActiveMonster.Acc) > 100) && (PlayerMonster1.getStatusEffect() != 6)) {
                                PlayerMonster1.DecreasePP(SkillUsePlayer);
                                if(UseSkill.GetTarget() == 1) {
                                    switch(UseSkill.GetPowerEffect()) {
                                    case 0:
                                        if((PlayerMonster1.getStatusEffect() == 1) && ((rand()%5) > 2)) cout << "\n\t--> Monter pemain tersengat.";
                                        else if((PlayerMonster1.getStatusEffect() == 5) && ((rand()%5) > 2)) cout << "\n\t--> Monter pemain kedinginan.";
                                        else {
                                            Damage = (((((PlayerMonster1.getCurLevel()*2/5)+2)*ActiveMonster.Atk*UseSkill.GetPower()/(50*WildMonster.Dfn))+2)*(((rand() % 20)+194)/100)*(100 - (rand() % 16))/100);
                                            if((UseSkill.GetStrWeak(1) == MR.getElemen0()) || (UseSkill.GetStrWeak(1) == MR.getElemen1())) {
                                                Damage*=2;
                                                cout << "\n\t--> Skill ini sangat efektif --> "; 
                                            } else if((UseSkill.GetStrWeak(2) == MR.getElemen0()) || (UseSkill.GetStrWeak(2) == MR.getElemen0())) {
                                                Damage/=2;
                                                cout << "\n\t--> Skill ini sangat tidak efektif --> "; 
                                            }
                                            if(WildMonster.HP <= Damage) WildMonster.HP = 0;
                                            else WildMonster.HP-=Damage;
                                        }
                                        break;
                                    case 1: WildMonster.Atk-=WildMonster.Atk/10; cout << "\n\t-->  Kekuatan serang monster liar menurun.";  break;
                                    case 2: WildMonster.Dfn-=WildMonster.Dfn/10; cout << "\n\t-->  Pertahanan monster liar menurun.";  break;
                                    case 3: WildMonster.Spd-=WildMonster.Spd/10; cout << "\n\t-->  Kecepatan monster liar menurun.";  break;
                                    case 4: WildMonster.Acc-=WildMonster.Acc/10; cout << "\n\t-->  Akurasi monster liar menurun.";  break;
                                    }
                                    input_manager::delay(1);
                                    // Add effect to foo
                                    if(UseSkill.GetEffect() > 0) {
                                        if((UseSkill.GetProsenEfek()*float((rand() % 20) + 95)/100) > 100) {
                                            if(WildMonsterEffect == 0){
                                                WildMonsterEffect = UseSkill.GetEffect(); 
                                                cout << "\n\t-->  Monster liar terkena efek " << input_manager::getStatusEffectName(WildMonsterEffect); input_manager::delay(1);
                                            }
                                        }
                                    }
                                } else {
                                    switch(UseSkill.GetPowerEffect()) {
                                    case 0:
                                        cout << "\n\t--> Health point monster pemain meningkat";
                                        if(ActiveMonster.HP+UseSkill.GetPower() >= ActiveMonster.HPMax)
                                            ActiveMonster.HP = ActiveMonster.HPMax;
                                        else
                                            ActiveMonster.HP+=UseSkill.GetPower();
                                        break;
                                    case 1: ActiveMonster.Atk+=ActiveMonster.Atk/10; cout << "\n\t--> Kekuatan serang monster pemain meningkat"; break;
                                    case 2: ActiveMonster.Dfn+=ActiveMonster.Dfn/10; cout << "\n\t--> Pertahanan monster pemain meningkat"; break;
                                    case 3: ActiveMonster.Spd+=ActiveMonster.Spd/10; cout << "\n\t--> Kecepatan monster pemain meningkat"; break;
                                    case 4: ActiveMonster.Acc+=ActiveMonster.Acc/10; cout << "\n\t--> Akurasi monster pemain meningkat"; break;
                                    }
                                    input_manager::delay(1);
                                }
                            } else {
                                cout << "\n\t--> Gagal menggunakan skill " << listSkill.GetNameSkillFromNumberSkill(PlayerMonster1.getSkill(SkillUsePlayer)); input_manager::delay(1);
                            }
                        }
                    }
                    // Wild Monster Phase
                    if((!IsPlayerFirst && (turn == 1)) || (IsPlayerFirst && (turn == 2))) {
                        int wild_no_skill = rand() % 4;
                        while(MR.getDefaultSkills(wild_no_skill) == 0) wild_no_skill = rand() % 4;
                        cout << "\n\t--> Fase monster liar";
                        cout << "\n\t--> Monster liar menggunakan skill " << listSkill.GetNameSkillFromNumberSkill(MR.getDefaultSkills(wild_no_skill)); input_manager::delay(1);
                        Skill UseSkill = listSkill.GetSkill(MR.getDefaultSkills(wild_no_skill));
                        if(int(double(UseSkill.GetAccuracy() + (((rand() % 20) + 97)/100))*WildMonster.Acc) > 100) {
                            if(UseSkill.GetTarget() == 1) {
                                switch(UseSkill.GetPowerEffect()) {
                                    case 0:
                                        if((WildMonsterEffect == 1) && ((rand()%5) > 2)) cout << "\n\t--> Monter liar tersengat.";
                                        else if((WildMonsterEffect == 5) && ((rand()%5) > 2)) cout << "\n\t--> Monter pemain kedinginan.";
                                        else {
                                            Damage = (((((MR.getDefaultLevel()*2/5)+2)*WildMonster.Atk*UseSkill.GetPower()/(50*ActiveMonster.Dfn))+2)*(((rand() % 20)+194)/100)*(100 - (rand() % 16))/100);
                                            if((UseSkill.GetStrWeak(1) == Monster1.getElemen0()) || (UseSkill.GetStrWeak(1) == Monster1.getElemen1())) {
                                                Damage*=2;
                                                cout << "\n\t--> Skill ini sangat efektif";
                                            } else if((UseSkill.GetStrWeak(2) == Monster1.getElemen0()) || (UseSkill.GetStrWeak(2) == Monster1.getElemen1())) {
                                                Damage/=2;
                                                cout << "\n\t--> Skill ini sangat tidak efektif";
                                            }
                                            if(ActiveMonster.HP <= Damage) ActiveMonster.HP = 0;
                                            else ActiveMonster.HP-=Damage;
                                        }
                                        break;
                                    case 1: ActiveMonster.Atk-=ActiveMonster.Atk/10; cout << "\n\t-->  Kekuatan serang monster pemain menurun."; break;
                                    case 2: ActiveMonster.Dfn-=ActiveMonster.Dfn/10; cout << "\n\t-->  Pertahanan monster pemain menurun."; break;
                                    case 3: ActiveMonster.Spd-=ActiveMonster.Spd/10; cout << "\n\t-->  Kecepatan monster pemain menurun."; break;
                                    case 4: ActiveMonster.Acc-=ActiveMonster.Acc/10; cout << "\n\t-->  Akurasi monster pemain menurun."; break;
                                }
                                input_manager::delay(1);
                                // Add effect to foo
                                if(UseSkill.GetEffect() > 0) {
                                    if((UseSkill.GetProsenEfek()*float((rand() % 20) + 95)/100) > 100) {
                                        if(PlayerMonster1.getStatusEffect() == 0) {
                                            PlayerMonster1.ChangeEffect(UseSkill.GetEffect());
                                            cout << "\n\t--> Monster liar terkena efek " << PlayerMonster1.getStatusEffectName();
                                        }
                                        else cout << "\n\t--> Gagal menggunakan skill efek.";
                                        input_manager::delay(1);
                                    }
                                }
                            } else {
                                switch(UseSkill.GetPowerEffect()) {
                                case 0:
                                    cout << "\n\t--> Health point monster liar meningkat";
                                    if(WildMonster.HP+UseSkill.GetPower() >= WildMonster.HPMax)
                                        WildMonster.HP = WildMonster.HPMax;
                                    else
                                        WildMonster.HP+=UseSkill.GetPower();
                                    break;
                                case 1: WildMonster.Atk+=WildMonster.Atk/10; cout << "\n\t--> Kekuatan serang monster liar meningkat"; break;
                                case 2: WildMonster.Dfn+=WildMonster.Dfn/10; cout << "\n\t--> Pertahanan monster liar meningkat"; break;
                                case 3: WildMonster.Spd+=WildMonster.Spd/10; cout << "\n\t--> Kecepatan monster liar meningkat"; break;
                                case 4: WildMonster.Acc+=WildMonster.Acc/10; cout << "\n\t--> Akurasi monster liar meningkat";break;
                                }
                                input_manager::delay(1); 
                            }
                        } else {
                            cout << "\n\t--> Gagal menggunakan skill " << listSkill.GetNameSkillFromNumberSkill(MR.getDefaultSkills(wild_no_skill)); input_manager::delay(1);
                        }
                    }
                    if((PlayerMonster1.getStatusEffect() >= 2) && (PlayerMonster1.getStatusEffect() <= 4)) {
                        ActiveMonster.HP-=ActiveMonster.HPMax/10;
                        if(PlayerMonster1.getStatusEffect() == 3) {
                            ActiveMonster.HP-=ActiveMonster.HPMax/10;
                            cout << "\n\n --> Monster pemain keracunan yang sangat kuat";
                        } else if(PlayerMonster1.getStatusEffect() == 1) {
                            cout << "\n\n --> Monster pemain keracunan";
                        } else {
                            cout << "\n\n --> Monster pemain terbakar.";
                        }
                        input_manager::delay(2);
                    }
                    if((WildMonsterEffect >= 2) && (WildMonsterEffect <= 4)) {
                        ActiveMonster.HP-=ActiveMonster.HPMax/10;
                        if(WildMonsterEffect == 3) {
                            ActiveMonster.HP-=ActiveMonster.HPMax/10;
                            cout << "\n\n --> Monster liar keracunan yang sangat kuat";
                        } else if(WildMonsterEffect == 1) {
                            cout << "\n\n --> Monster liar keracunan";
                        } else {
                            cout << "\n\n --> Monster liar terbakar.";
                        }
                        input_manager::delay(2);
                    }
                    turn++;
                }
                command_respon = 255;
            }
            AcceptCR = false;
        }
        // Pertarungan selesai
        PlayerMonster1.ChangeHP(100*ActiveMonster.HP/ActiveMonster.HPMax);
        Trainer.DelMonster(PN);
        Trainer.InsertMonster(PlayerMonster1,PN);
    }
    if(WildMonster.HP == 0) {
        int Money = 11*MR.getDefaultLevel()*WildMonster.HPMax;
        int Exp = (WildMonster.HPMax/WildMonster.HPMax)*(MR.getDefaultLevel()/PlayerMonster1.getCurLevel())*0.03*(MR.getDefaultLevel()*MR.getDefaultLevel()*MR.getDefaultLevel());
        cout << "\n\t--> Berhasil mengalahkan monster liar.\n"; input_manager::delay(1);
        cout << "\n\t--> Anda mendapatkan " << Money << " Zeny dan " << Exp << " Exp.\n"; input_manager::delay(1);
        Trainer.IncMoney(Money);
        PlayerMonster1.AddExp(Exp);
        Trainer.DelMonster(PN);
        Trainer.InsertMonster(PlayerMonster1,PN);
        *result = 1;
        // Get Money and Experience
    } else if(EscapeSuccesfully){
        cout << "\n\t--> Anda berhasil kabur\n"; input_manager::delay(1);
        *result = 2;
    } else if(ActiveMonster.HP == 0){
        Trainer.DecMoney(Trainer.GetMoney()/4);
        cout << "\n\t--> Semua monster anda kalah.\n"; input_manager::delay(1);
        // Loss money and get out to home
        *result = 0;
    } else if(SuccessUseBall) {
        *result = 3;
    }
}