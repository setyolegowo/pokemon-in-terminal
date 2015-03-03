#ifndef __MY_NAMESPACE
#define __MY_NAMESPACE

namespace interface
{
#ifdef __WIN64
    void ClearScreen() { system("cls"); }
#elsif __WIN32
    void ClearScreen() { system("cls"); }
#else
    void ClearScreen() { system("clear"); }
#endif
    void start_game()
    {
        ClearScreen();
        cout<<"\n";
        cout<<"               ____        __           ____                   __   \n";
        cout<<"              / __ " << char(92) << "____  / /_____     / __ " << char(92) << "____ _____  _____/ /_  \n";
        cout<<"             / /_/ / __ " << char(92) << "/ //_/ _ " << char(92) << "   / /_/ / __ `/ __ " << char(92) << "/ ___/ __ " << char(92) << " \n";
        cout<<"            / ____/ /_/ / ,< /  __/  / _, _/ /_/ / / / / /__/ / / / \n";
        cout<<"           /_/    " << char(92) << "____/_/|_|" << char(92) << "___/  /_/ |_|" << char(92) << "__,_/_/ /_/" << char(92) << "___/_/ /_/  \n";
        cout<<"\n";
        cout<<"              Dibuat oleh : 13511025 Lubis Sucipto\n";
        cout<<"                            13511037 Muhammad Rizky W\n";
        cout<<"                            13511051 Andreas Dwi Nugroho\n";
        cout<<"                            13511071 Setyo Legowo\n";
        cout<<"                            13511083 Fawwaz Muhammad\n";
        cout<<"                            13511093 Asep Saepudin\n\n";
        cout<<"-------------------------==:: Pejuang Kemerdekaan ::==--------------------------";
    }
    void BeginStory(int i)
    {
        ClearScreen();
        cout<<"================================================================================";
        cout<<"||                             P E M B U K A A N                              ||";
        cout<<"================================================================================";
        cout<<"||                                                                            ||";
        cout<<"||                                                                            ||";
        cout<<"||                                                                            ||";
        cout<<"||                                                                            ||";
        switch(i) // Disediakan 2 baris
        {
            case 0:
                cout<<"||                   Halo. Sangat senang bertemu denganmu.                    ||";
                cout<<"||                                                                            ||";
                break;
            case 1:
                cout<<"||                     Selamat datang di dunia PokeRanch.                     ||";
                cout<<"||                                                                            ||";
                break;
            case 2:
                cout<<"||                              Nama saya Virtue.                             ||";
                cout<<"||                                                                            ||";
                break;
            case 3:
                cout<<"||                Oh ya, saya biasanya disebut Poke Profesor.                 ||";
                cout<<"||                                                                            ||";
                break;
            case 4:
                cout<<"||                        Sebelum bergerak lebih jauh,                        ||";
                cout<<"||                apakah ini adalah petualangan pertama kamu?                 ||";
                break;
            case 5:
                cout<<"||                        Jika kamu membutuhkan saran,                        ||";
                cout<<"||                    Ketikkan saja \"HELP\" pada terminal                      ||";
                break;
            case 6:
                cout<<"||                  Di dunia ini, terdapat makhluk hidup dan                  ||";
                cout<<"||               memiliki habitatnya sendiri yang disebut Poke.               ||";
                break;
            case 7:
                cout<<"||                  Orang-orang disini hidup bersama dengan                   ||";
                cout<<"||                             damai bersama Poke.                            ||";
                break;
            case 8:
                cout<<"||                  Saat orang-orang bermain bersama-sama,                    ||";
                cout<<"||                 dan sekali-kali bekerja besama dengannya.                  ||";
                break;
            case 9:
                cout<<"||             Beberapa orang menggunakan Poke untuk bertarung                ||";
                cout<<"||                   dan membentuk ikatan kuat dengannya.                     ||";
                break;
            case 10:
                cout<<"||                          Apa yang saya lakukan?                            ||";
                cout<<"||                                                                            ||";
                break;
            case 11:
                cout<<"||                 Saya meneliti Poke secara terus menerus                    ||";
                cout<<"||                           selama hidup saya.                               ||";
                break;
            case 12:
                cout<<"||                Sekarang, kenapa kamu tidak menceritakan                    ||";
                cout<<"||                         sedikit tentang dirimu?                            ||";
                break;
            case 13:
                cout<<"||                             Oh, tentu saja.                                ||";
                cout<<"||             Nama kamu Okep ya? Bukan? Wah, salah ternyata.                 ||";
                break;
            case 14:
                cout<<"||                  Wah, nama yang sangaaaaaaaaat bagus.                      ||";
                cout<<"||                                                                            ||";
                break;
            case 15:
                cout<<"||                   Nah, semua orang di dunia ini tahu                       ||";
                cout<<"||                                  bahwa                                     ||";
                break;
            case 16:
                cout<<"||                   terdapat seorang Trainer Poke yang                       ||";
                cout<<"||                            yang sangat kuat.                               ||";
                break;
            case 17:
                cout<<"||             Kamu dapat mencari tahu siapa dia setelah kamu                 ||";
                cout<<"||                merasa kuat untuk melawan dia di stadium.                   ||";
                break;
            case 18:
                cout<<"||                  Dalam perjalananmu nanti, kamu akan                       ||";
                cout<<"||             bertemu Poke-Poke yang tak terhitung jumlahnya.                ||";
                break;
            case 19:
                cout<<"||                Saya percaya bahwa kamu akan membantu saya                  ||";
                cout<<"||                                                                            ||";
                break;
            case 20:
                cout<<"||                  untuk mengumpulkan semua Poke yang ada.                   ||";
                cout<<"||                                                                            ||";
                break;
            case 21:
                cout<<"||                  Sebelum mulai, kamu harus membeli dulu                    ||";
                cout<<"||                      telor monster yang ada di toko.                       ||";
                break;
            case 22:
                cout<<"||                Setelah itu, kamu harus bergerak beberapa                   ||";
                cout<<"||                         langkah di dalam kota.                             ||";
                break;
            case 23:
                cout<<"||                   Setelah telor monstermu menetas, maka                    ||";
                cout<<"||                kamu akan bebas berpetualang di dunia Poke.                 ||";
                break;
            case 24:
                cout<<"||                Satu hal lagi, mungkin ini adalah pertemuan                 ||";
                cout<<"||         pertama dan terakhir aku dengan kamu sebagai trainer baru.         ||";
                break;
            case 25:
                cout<<"||                             Huahahaha.......                               ||";
                cout<<"||                                 v(^_^)v                                    ||";
                break;
            case 26:
                cout<<"||              Baiklah, sekarang waktunya kamu Berpetualang.                 ||";
                cout<<"||                                                                            ||";
                break;
            default:
                cout << "ADA ERROR\n\n";
                break;
        }
        cout<<"||                                                                            ||";
        cout<<"||                                                                            ||";
        cout<<"||                                                                            ||";
        cout<<"||                                                                            ||";
        cout<<"||                                                                            ||";
        cout<<"-------------------------==:: Pejuang Kemerdekaan ::==--------------------------";
    }
    void show_nonBattle(int cc)
    {
        cout<<"                               I N F O R M A S I\n";
        switch(cc)
        {
            case 0: // Disediakan 6 baris efektif
                cout<<"";
                break;
            case 1: // disediakan 6 baris efektif
                cout << "\n\tPERHATIAN: Komando tidak diterima. Ketikkan HELP untuk bantuan.\n\n\n\n\n\n\n";
                break;
            case 2: // disediakan 6 baris efektiif
                cout << "\n   \"LOAD <player-name>\"  : Menggunakan data yang telah disimpan sebelumnya.";
                cout << "\n   \"SLEEP\" : Mengembalikan HP monster ke maksimum.";
                cout << "\n   \"SAVE\"  : Menyimpan state permainan.";
                cout << "\n   \"HELP\"  : Menampilkan bantuan.";
                cout << "\n   \"OUT\"   : Keluar dari rumah.";
                cout << "\n   \"EXIT\"  : Keluar dari permainan. (Tidak melakukan proses SAVE)";
                cout << "\n\n";
                break;
            case 3: // disediakan 6 baris efektif
                cout << "\n   \"HELP\"  : Menampilkan bantuan.";
                cout << "\n   \"EXIT\"  : Keluar dari permainan. (Tidak melakukan proses SAVE)";
                cout << "\n   \"TELEPORT <name-place>\" : Melakukan teleport ke <name-place>";
                cout << "\n   \"MOVE <direction> [n]\" : Bergerak ke arah <direction> sebanyak n langkah.";
                cout << "\n   \"LIST-MONSTER [page]\" : Menampilkan daftar monster pada halaman [page].";
                cout << "\n   \"LIST-PARTY [page]\" : Menampilkan daftar party pada halaman [page].";
                cout << "\n        Halaman 1 dari 2";
                cout << "\n";
                break;
            case 4: // disediakan 6 baris efektif
                cout << "\n   \"LIST-ITEM\" : Menampilkan daftar item pada halaman [page].";
                cout << "\n   \"STATUS\" : Menampilkan status trainer.";
                cout << "\n   \"SET <no-monster>\" : Mengeset dari daftar monster ke party no satu.";
                cout << "\n   \"SWITCH <no-party> <no-party>\" : Mengganti urutan dalam party.";
                cout << "\n   \"DISMISS <no-monster>\" : Membuang monster dari daftar monster.";
                cout << "\n   \"ENTRY\" : Masuk ke dalam bangunan jika player didepan pintu masuk bangunan.";
                cout << "\n        Halaman 2 dari 2";
                cout << "\n";
                break;
            case 5: // disediakan 6 baris efektif
                cout << "\n   \"HELP\"  : Menampilkan bantuan.";
                cout << "\n   \"EXIT\"  : Keluar dari permainan. (Tidak melakukan proses SAVE)";
                cout << "\n   \"OUT\" : Keluar dari Combinatorium";
                cout << "\n   \"COMBINE <no-party> <no-party>\" : Mengkombinasikan 2 monster sehingga berevolusi.";
                cout << "\n\n\n\n";
                break;
            case 6: // disediakan 6 baris efektif
                cout << "\n   \"HELP\"  : Menampilkan bantuan.";
                cout << "\n   \"EXIT\"  : Keluar dari permainan. (Tidak melakukan proses SAVE)";
                cout << "\n   \"OUT\" : Keluar dari Combinatorium";
                cout << "\n   \"BATTLE <bet>\" : Bertarung di stadium dengan taruhan sebesar <bet>.\n";
                cout << "\nINFO: Jika melakukan <bet> >= 500.000 Zeny, maka bertarung dengan trainer kuat.";
                cout << "\n\n";
                break;
            case 7:
                cout << "\n   \"HELP\"  : Menampilkan bantuan.";
                cout << "\n   \"EXIT\"  : Keluar dari permainan. (Tidak melakukan proses SAVE)";
                cout << "\n   \"OUT\" : Keluar dari Poke Store.";
                cout << "\n   \"LIST-SELL\" : Menampilkan daftar item yang dijual di Poke Store.";
                cout << "\n   \"BUY <name-item> [Qty]\" : Beli <nama-item> sebanyak [Qty].";
                cout << "\n   \"SELL <name-item> [Qty]\" : Beli <nama-item> sebanyak [Qty].";
                cout << "\n\n";
                break;
            case 8:
                cout << "\n   \"HELP\"  : Menampilkan bantuan.";
                cout << "\n   \"EXIT\"  : Keluar dari permainan. (Tidak melakukan proses SAVE)";
                cout << "\n   \"MOVE <direction> [n]\" : Bergerak ke arah <direction> sebanyak n langkah.";
                cout << "\n   \"LIST-MONSTER [page]\" : Menampilkan daftar monster pada halaman [page].";
                cout << "\n   \"LIST-PARTY [page]\" : Menampilkan daftar party pada halaman [page].";
                cout << "\n\n        Halaman 1 dari 2";
                cout << "\n";
                break;
            case 9:
                cout << "\n   \"LIST-ITEM [page]\" : Menampilkan daftar item pada halaman [page].";
                cout << "\n   \"STATUS\" : Menampilkan status trainer.";
                cout << "\n   \"SWITCH <no-party> <no-party>\" : Mengganti urutan dalam party.";
                cout << "\n   \"DISMISS <no-monster>\" : Membuang monster dari daftar monster.";
                cout << "\n   \"ENTRY\" : Masuk ke dalam bangunan jika player didepan pintu masuk bangunan.";
                cout << "\n\n        Halaman 2 dari 2";
                cout << "\n";
                break;
            case 10:
                cout << "\n";
                cout << "\n    Uang Taruhan tidak mencukupi atau Taruhan minimum adalah 50.000 Zeny";
                cout << "\n\n\n\n\n\n";
                break;
            default:
                cout<<"\n\n\n\n\n\n\n\n";
                break;
        }
    }
    void show_info(int cc) // Dipakai untuk halaman depan dan pembukaan
    {
        switch(cc)
        {
            case 1: // disediakan 3 baris efektif
                cout << "\n\tPERHATIAN: Komando tidak diterima. Ketikkan HELP untuk bantuan.\n\n\n\n";
                break;
            case 2: // Help pada main menu. Disediakan 3 baris efektif
                cout<<"\n\t\"NEW <nama-pengguna>\": Membuat pengguna baru.";
                cout<<"\n\t\"LOAD <nama-pengguna>\": Menggunakan data tersimpan dari pengguna.";
                cout<<"\n\t\"EXIT\": Keluar dari permainan";
                cout<<"\n\n";
                break;
            case 3: // Disediakan 3 baris efektif
                cout<<"\n\t\"NEXT\": Cerita selanjutnya.";
                cout<<"\n\t\"EXIT\": Keluar dari permainan";
                cout<<"\n\n\n";
                break;
            case 4:
                cout<<"\n\tGALAT: Nama pemain tidak dapat diterima.\n\n\n\n";
                break;
            case 5:
                cout<<"\n\tGALAT: Nama pemain sudah ada.\n\n\n\n";
                break;
            case 6:
                cout << "\n\tGALAT: Nama pemain tidak ditemukan.\n\n\n\n";
                break;
            case 7: // disediakan 6 baris efektif
                cout<<"                               I N F O R M A S I\n";
                cout << "\n   \"LOAD <player-name>\"  : Menggunakan data yang telah disimpan sebelumnya.";
                cout << "\n   \"HELP\"  : Menampilkan bantuan.";
                cout << "\n   \"OUT\"   : Keluar dari rumah.";
                cout << "\n   \"EXIT\"  : Keluar dari permainan. (Tidak melakukan proses SAVE)";
                cout << "\n\n\n\n";
                break;
            case 8: // disediakan 6 baris efektif
                cout<<"                               I N F O R M A S I\n";
                cout << "\n   \"HELP\"  : Menampilkan bantuan.";
                cout << "\n   \"ENRTY\" : Masuk kedalam bangunan jika pemain didepan pintu.";
                cout << "\n   \"MOVE <direction> [n]\" : Bergerak ke arah <direction> sebanyak n langkah.";
                cout << "\n   \"EXIT\"  : Keluar dari permainan. (Tidak melakukan proses SAVE)";
                cout << "\n\n\n\n";
                break;
            case 9:
                cout<<"                               I N F O R M A S I\n";
                cout << "\n   \"HELP\"  : Menampilkan bantuan.";
                cout << "\n   \"LIST-SELL\" : Menampilkan daftar item yang dijual di Poke Store.";
                cout << "\n   \"BUY <name-item> [Qty]\" : Beli <nama-item> sebanyak [Qty].";
                cout << "\n   \"OUT\"   : Keluar dari Poke Store.";
                cout << "\n   \"EXIT\"  : Keluar dari permainan. (Tidak melakukan proses SAVE)";
                cout << "\n\n\n";
                break;
            default: // disediakan 3 baris efektif
                cout << "\n\n\n\n\n";
                break;
        }
    }
    void Input()
    {
        cout<<"================================================================================";
        cout<<"  Baris komando:\n\n";
        cout<<"  > ";
    }
    void Input2()
    {
        cout<<"================================================================================";
        cout<<"  > ";
    }
    void Home()
    {
        ClearScreen();
        cout<<"\n";
        cout<<"                               _,                _.\n";
        cout<<"                              (  `)            (`  ).\n";
        cout<<"                           .=( ` ,_ `)    .-``(      ).\n";
        cout<<"                          (.__.:-`-_.'   (.,,(.       '`.\n";
        cout<<"                                              `--`--`'`\n";
        cout<<"                                 ____.........__H_\n";
        cout<<"                              __/%%%%|%%%%%%%|%%%%\\\n";
        cout<<"                         _ ()/%%|:II:|II:::II|:II:|_ _ _\n";
        cout<<"                        |-(()|--|:II:|II:H:II|:II:|-|-|-|\n";
        cout<<"                        `'.'\"^  ^` \"^ \"^|\"|^'\"' `^`-.^~'\"\n";
        cout<<"                                    R U M A H\n";
        cout<<"================================================================================"; // 13
    }
    void City()
    {
        ClearScreen();
        cout<<"=. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . =";
        cout<<"=                              K O T A    P O K E                              =";
        cout<<" ==============================================================================";
    }
    void MiniCity()
    {
        ClearScreen();
        cout<<"=. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . =";
        cout<<"=                              K O T A    P O K E                              =";
        cout<<"================================================================================";
    }
    void Combinatorium()
    {
        ClearScreen();
        cout<<"\n";
        cout<<"                         |ZZzzz                     |ZZzzz\n";
        cout<<"                         |       COMBINATORIUM      |\n";
        cout<<"                         |                         / \\\n";
        cout<<"                        /^\\                       |~~~|\n";
        cout<<"                     |^^^^^^^|                    |   |\n";
        cout<<"                     |    +[]|/\\/\\/\\/\\^/\\/\\/\\/\\/|^^^^^^^|\n";
        cout<<"                     |+[]+   |~~~~~~~~~~~~~~~~~~|    +[]|\n";
        cout<<"                     |       |  []   /^\\   []   |+[]+   |\n";
        cout<<"                     |   +[]+|  []  || ||  []   |   +[]+|\n";
        cout<<"                     |[]+    |      || ||       |[]+    |\n";
        cout<<"                     |_______|------------------|_______|\n";
        cout<<"================================================================================";
    }
    void Stadium()
    {
        ClearScreen();
        cout<<"\n";
        cout<<"                                       I~\n"; // 2
        cout<<"                                   I~ /V\\  I~\n";
        cout<<"                               I~ /V\\ | | /V\\  I~\n";
        cout<<"                          @ @ /V\\ | |_|_|_| | /V\\ @ @      \n";
        cout<<"                     @ @ @@@@@| |_| |_/V\\_| |_| |@@@ @ @ @  \n";
        cout<<"                  @ @@@@@@@ @@| | |_|_|_|_|_| | |@ @@@@@@@@ @\n";
        cout<<"                 @@@@ @@ @@@@@|_|_V_V|   |V_V_|_|@@@@@@@@ @@@@\n";
        cout<<"           _._._._._._._._._._._._._._._._._._._._._._._._._._._._._\n";
        cout<<"       :::::::::::::::::::::::::::::::|X|:::::::::::::::::::::::::::::::\n";
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . "; // 11
        cout<<"                                 S T A D I U M\n"; // 12
        cout<<"================================================================================";
    }
    void Store()
    {
        ClearScreen();
        cout<<"\n\n\n";
        cout<<"               .-.                                .-.                  \n";
        cout<<"              (_) )-.          /            .--.-'   /                 \n";
        cout<<"                 /   \\  .-._. /-.   .-.    (  (_)---/---.-._.).--..-.  \n";
        cout<<"                /     )(   ) /   )./.-'_    `-.    /   (   )/   ./.-'_ \n";
        cout<<"             .-/  `--'  `-'_/    \\(__.'   _    )  /     `-'/    (__.'  \n";
        cout<<"            (_/                          (_.--'                        \n\n\n";
        cout<<"                              P O K E   S T O R E\n"; // 12
        cout<<"================================================================================";
    }
    void MiniStore()
    {
        ClearScreen();
        cout<<"\n";
        cout<<"                              P O K E   S T O R E\n"; // 12
        cout<<"================================================================================";
    }
    void OuterArea()
    {
        cout<<"\n\n";
        cout<<"                              O U T E R   A R E A\n"; // 12
        cout<<"================================================================================";
    }
    void BattleWildTitle() {
        ClearScreen();
        cout<<"\n";
        cout<<"                P E R T A R U N G A N   M O N S T E R   L I A R\n";
        cout<<"================================================================================";
    }
    void BattleStadiumTitle() {
        ClearScreen();
        cout<<"\n";
        cout<<"                         S T A D I U M   T R A I N E R\n";
        cout<<"================================================================================";
    }
}
namespace input_manager
{
    bool IsSame(char * _input1, char * _input2, int _pinput1, int _pinput2)
    {
        bool IsSame = true;
        int i = 0;
        if(_pinput1 > _pinput2)
            IsSame = false;
        else
        {
            while(IsSame && i <= _pinput1)
            {
                if(_input1[i] == _input2[i])
                    i++;
                else
                    IsSame = false;
            }
        }
        
        return IsSame;
    }
    void getSecond(char * _Input, char * _Output, int n)
    // Prekondisi: Komando harus yang terdefinisi
    {
        int i = 0;
        int j;
        bool isValid = true;
        
        // Lewati command
        while(((_Input[i] >= 'A') && (_Input[i] <= 'Z')) || ((_Input[i] >= 'a') && (_Input[i] <= 'z')) || ((_Input[i] == '-') && (i > 0)))
            i++;
        while(((_Input[i] > ' ') && (_Input[i] < 'A')) || ((_Input[i] > 'Z') && (_Input[i] < 'a')) || (_Input[i] > 'z'))
            i++;
        
        if(_Input[i] == ' ') {
            while(_Input[i] == ' ')
                i++;
            // sekarang, i menunjuk setelah karakter spasi
            if(((_Input[i] >= 'A') && (_Input[i] <= 'Z')) || ((_Input[i] >= 'a') && (_Input[i] <= 'z'))) {
                j = 0;
                while(((_Input[i] >= 'A') && (_Input[i] <= 'Z')) || ((_Input[i] >= 'a') && (_Input[i] <= 'z')))
                {
                    if((_Input[i] >= 'A') && (_Input[i] <= 'Z'))
                        _Output[j] = _Input[i] + 32;
                    else
                        _Output[j] = _Input[i];
                    i++;
                    j++;
                }
                if(((_Input[i] > ' ') && (_Input[i] < 'A')) || ((_Input[i] > 'Z') && (_Input[i] < 'a')) || (_Input[i] > 'z'))
                    isValid = false;
            } else
                isValid = false;
        } else
            isValid = false;
        
        if(isValid) {
            while(j <= n)
            {
                _Output[j] = '\0';
                j++;
            }
        } else {
            _Output[0] = 0;
        }
    }
    int getNumberN(char * _Input, int _N)
    // Prekondisi: Komando harus yang terdefinisi
    {
        int i = 0;
        int j = 2;
        bool isValid = true;
        
        // Lewati command
        while(((_Input[i] >= 'A') && (_Input[i] <= 'Z')) || ((_Input[i] >= 'a') && (_Input[i] <= 'z')) || ((_Input[i] == '-') && (i > 0)))
            i++;
        while(((_Input[i] > ' ') && (_Input[i] < 'A')) || ((_Input[i] > 'Z') && (_Input[i] < 'a')) || (_Input[i] > 'z'))
            i++;
        while(j < _N) {
            while(_Input[i] == ' ')
                i++;
            while(_Input[i] > ' ')
                i++;
            j++;
        }
        if(_Input[i] == ' ') {
            int nomor = 0;
            while(_Input[i] == ' ')
                i++;
            // sekarang, i bukanlah yang menunjuk karakter spasi
            if((_Input[i] >= '1') && (_Input[i] <= '9')) {
                while((_Input[i] >= '0') && (_Input[i] <= '9'))
                {
                    nomor = 10*nomor + (_Input[i] - '0');
                    i++;
                }
                if(((_Input[i] > ' ') && (_Input[i] < '0')) || (_Input[i] > '9'))
                    isValid = false;
            } else
                isValid = false;
            if(isValid)
                return nomor;
            else
                return 0;
        } else
            return 1;
    }
    char getNoBuilding(char * _Input)
    {
        int i = 0;
    
        // Mendapatkan panjang array
        while(_Input[i] != '\0')
            i++;
        
        // Prediksi
        if((_Input[0] == 'h') && (i == 4)) {
            if((_Input[1] == 'o') && (_Input[2] == 'm') && (_Input[3] == 'e'))
                return 3;
            else
                return 0;
        } else if((_Input[0] == 'c') && (i == 13)) {
            if((_Input[1] == 'o') && (_Input[2] == 'm') && (_Input[3] == 'b') && (_Input[4] == 'i') && (_Input[5] == 'n')) {
                if((_Input[6] == 'a') && (_Input[7] == 't') && (_Input[8] == 'o') && (_Input[9] == 'r') && (_Input[10] == 'i')) {
                    if((_Input[11] == 'u') && (_Input[12] == 'm'))
                        return 1;
                    else
                        return 0;
                } else
                    return 0;
            } else
                return 0;
        } else if((_Input[0] == 'g') && (i == 4)) {
            if((_Input[1] == 'a') && (_Input[2] == 't') && (_Input[3] == 'e'))
                return 2;
            else
                return 0;
        } else if(_Input[0] == 's') {
            if((_Input[1] == 't') && (i == 7)) {
                if((_Input[2] == 'a') && (_Input[3] == 'd') && (_Input[4] == 'i') && (_Input[5] == 'u') && (_Input[6] == 'm'))
                    return 4;
                else
                    return 0;
            } else if((_Input[1] == 'h') && (i == 4)) {
                if((_Input[2] == 'o') && (_Input[3] == 'p'))
                    return 5;
                else
                    return 0;
            } else
                return 0;
        } else
            return 0;
    }
    char getNoCommand(char * _Input)
    {
        int i = 0;
        int j = 0;
        bool IsInputDiterima = true;
        char command[15];
        
        // Pisah Input
        while(((_Input[i] >= 'A') && (_Input[i] <= 'Z')) || ((_Input[i] >= 'a') && (_Input[i] <= 'z')) || ((_Input[i] == '-') && (i > 0)))
        // while(_Input[i] != ' ')
        {
            if((_Input[i] >= 'A') && (_Input[i] <= 'Z'))
                command[i] = _Input[i] + 32;
            else
                command[i] = _Input[i];
            i++;
        }
        if(((_Input[i] > ' ') && (_Input[i] < 'A')) || ((_Input[i] > 'Z') && (_Input[i] < 'a')) || (_Input[i] > 'z'))
        {
            command[i] = _Input[i];
            i++;
        }
        // Prediksi komando
        // => Sistem Tree dengan pemisahan command
        if((command[0] >= 'b') && (command[0] <= 't') && (i >= 2) && (i <= 12))
        {
            if(command[0] == 'm') {
                if(i != 4)
                    return 0;
                else {
                    if((command[1] == 'o') && (command[2] == 'v') && (command[3] == 'e'))
                        return 10;
                    else
                        return 0;
                }
            } else if(command[0] < 'm') { // [c .. n]
                if(command[0] == 'i') {
                    if(i != 4)
                        return 0;
                    else {
                        if((command[1] == 't') && (command[2] == 'e') && (command[3] == 'm'))
                            return 22;
                        else
                            return 0;
                    }
                } else if(command[0] < 'i'){
                    if(command[0] == 'b') {
                        if((command[1] == 'a') && (i == 6)) {
                            if((command[2] == 't') && (command[3] == 't') && (command[4] == 'l') && (command[5] == 'e'))
                                return 26;
                            else
                                return 0;
                        } else if((command[1] == 'u') && (i == 3)) {
                            if(command[2] == 'y')
                                return 27;
                            else
                                return 0;
                        } else
                            return 0;
                    } else if(command[0] == 'c') {
                        if((command[1] == 'h') && (i == 6)) {
                            if((command[2] == 'a') && (command[3] == 'n') && (command[4] == 'g') && (command[5] == 'e'))
                                return 23;
                            else
                                return 0;
                        } else if((command[1] == 'o') && (i == 7)) {
                            if((command[2] == 'm') && (command[3] == 'b') && (command[4] == 'i') && (command[5] == 'n') && (command[6] == 'e'))
                                return 25;
                            else
                                return 0;
                        } else
                            return 0;
                    } else if((command[0] == 'd') && (i == 7)){
                        if((command[1] == 'i') && (command[2] == 's') && (command[3] == 'm') && (command[4] == 'i') && (command[5] == 's') && (command[6] == 's'))
                            return 17;
                        else
                            return 0;
                    } else if(command[0] == 'e') {
                        if((command[1] == 'n') && (i == 5)) {
                            if((command[2] == 't') && (command[3] == 'r') && (command[4] == 'y'))
                                return 18;
                            else
                                return 0;
                        } else if((command[1] == 's') && (i == 6)) {
                            if((command[2] == 'c') && (command[3] == 'a') && (command[4] == 'p') && (command[5] == 'e'))
                                return 21;
                            else
                                return 0;
                        } else if((command[1] == 'x') && (i == 4)) {
                            if((command[2] == 'i') && (command[3] == 't'))
                                return 4;
                            else
                                return 0;
                        } else
                            return 0;
                    } else if((command[0] == 'h') && (i == 4)) {
                        if((command[1] == 'e') && (command[2] == 'l') && (command[3] == 'p'))
                            return 3;
                        else
                            return 0;
                    } else
                        return 0;
                } else if(command[0] == 'l') {
                    if(i < 9)
                        if((command[1] == 'o') && (i == 4)) {
                            if((command[2] == 'a') && (command[3] == 'd'))
                                return 2;
                            else
                                return 0;
                        } else
                            return 0;
                    else {
                        if((command[1] == 'i') && (command[2] == 's') && (command[3] == 't') && (command[4] == '-')) {
                            if((command[5] == 'i') && (i == 9)) {
                                if((command[6] == 't') && (command[7] == 'e') && (command[8] == 'm'))
                                    return 13;
                                else
                                    return 0;
                            } else if((command[5] == 'm') && (i == 12)) {
                                if((command[6] == 'o') && (command[7] == 'n') && (command[8] == 's') && (command[9] == 't') && (command[10] == 'e') && (command[11] == 'r'))
                                    return 11;
                                else
                                    return 0;
                            } else if((command[5] == 'p') && (i == 10)) {
                                if((command[6] == 'a') && (command[7] == 'r') && (command[8] == 't') && (command[9] == 'y'))
                                    return 12;
                                else
                                    return 0;
                            } else if((command[5] == 's') && (i == 9)) {
                                if((command[6] == 'e') && (command[7] == 'l') && (command[8] == 'l'))
                                    return 29;
                                else
                                    return 0;
                            } else
                                return 0;
                        } else
                            return 0;
                    }
                } else
                    return 0;
            } else { // [n .. t]
                if(command[0] == 's') {
                    if((command[1] == 'a') && (i == 4)) {
                        if((command[2] == 'v') && (command[3] == 'e'))
                            return 7;
                        else
                            return 0;
                    } else if(command[1] == 'e') {
                        if((command[2] == 't') && (i == 3))
                            return 15;
                        else if((command[2] == 'l') && (command[3] == 'l') && (i == 4))
                            return 28;
                        else
                            return 0;
                    } else if((command[1] == 'k') && (i == 5)) {
                        if((command[2] == 'i') && (command[3] == 'l') && (command[4] == 'l'))
                            return 24;
                        else
                            return 0;
                    } else if((command[1] == 'l') && (i == 5)) {
                        if((command[2] == 'e') && (command[3] == 'e') && (command[4] == 'p'))
                            return 6;
                        else
                            return 0;
                    } else if((command[1] == 't') && (i == 6)) {
                        if((command[2] == 'a') && (command[3] == 't') && (command[4] == 'u') && (command[5] == 's'))
                            return 14;
                        else
                            return 0;
                    } else if((command[1] == 'w') && (i == 6)) {
                        if((command[2] == 'i') && (command[3] == 't') && (command[4] == 'c') && (command[5] == 'h'))
                            return 16;
                        else
                            return 0;
                    } else
                        return 0;
                } else if(command[0] < 's') {
                    if(command[0] == 'n') {
                        if((command[1] == 'e') && (command[2] == 'w') && (i == 3))
                            return 1;
                        else if((command[1] == 'e') && (command[2] == 'x') && (command[3] == 't') && (i == 4))
                            return 5;
                        else
                            return 0;
                    } else if((command[0] == 'o') && (i == 3)) {
                        if((command[1] == 'u') && (command[2] == 't'))
                            return 8;
                        else
                            return 0;
                    } else
                        return 0;
                } else if((command[0] == 't') && (i == 8)) {
                    if((command[1] == 'e') && (command[2] == 'l') && (command[3] == 'e') && (command[4] == 'p') && (command[5] == 'o') && (command[6] == 'r') && (command[7] == 't'))
                        return 9;
                    else
                        return 0;
                } else
                    return 0;
            }
        } else
            return 0;
    }
    int RandomSelectMonsterFloor(int Floor)
    {
        unsigned char MF01[4] = {10,7,20,18};
        unsigned char MF02[9] = {12,15,95,23,26,33,30,52,79};
        unsigned char MF03[10] = {37,48,21,39,42,50,35,44,60,97};
        unsigned char MF04[7] = {13,46,11,24,54,68,99};
        unsigned char MF05[9] = {8,58,82,92,70,80,85,27,31};
        unsigned char MF06[8] = {49,66,28,41,19,43,73,64};
        unsigned char MF07[12] = {16,22,56,87,96,100,47,77,14,38,40,34};
        unsigned char MF08[12] = {25,29,9,53,81,83,93,45,51,88,98,59};
        unsigned char MF09[9] = {55,71,101,32,84,36,86,57,76};
        unsigned char MF10[5] = {74,78,89,90,91};
        int getN;
        switch(Floor)
        {
            case 1:
                getN = int(MF01[rand() % 4]);
                break;
            case 2:
                getN = int(MF02[rand() % 9]);
                break;
            case 3:
                getN = int(MF03[rand() % 10]);
                break;
            case 4:
                getN = int(MF04[rand() % 7]);
                break;
            case 5:
                getN = int(MF05[rand() % 9]);
                break;
            case 6:
                getN = int(MF06[rand() % 8]);
                break;
            case 7:
                getN = int(MF07[rand() % 12]);
                break;
            case 8:
                getN = int(MF08[rand() % 12]);
                break;
            case 9:
                getN = int(MF09[rand() % 9]);
                break;
            case 10:
                getN = int(MF10[rand() % 5]);
                break;
        }
        // int getN = int(MF[rand() % int(n)]);
        return getN;
    }
    int RandomMonsterEggHatched() {
        unsigned char ME[9] = {1,4,7,10,12,15,18,20,95};
        return int(ME[rand() % 9]);
    }
    unsigned char getNumDirection(char * _GetDirection) {
        int i = 0;
        while(_GetDirection[i] != '\0')
            i++;
        
        if((_GetDirection[0] == 'd') && (i == 4)) {
            if((_GetDirection[1] == 'o') && (_GetDirection[2] == 'w') && (_GetDirection[3] == 'n')) return 3;
            else return 0;
        } else if((_GetDirection[0] == 'l') && (i == 4)) {
            if((_GetDirection[1] == 'e') && (_GetDirection[2] == 'f') && (_GetDirection[3] == 't')) return 4; 
            else return 0;
        } else if((_GetDirection[0] == 'r') && (i == 5)) {
            if((_GetDirection[1] == 'i') && (_GetDirection[2] == 'g') && (_GetDirection[3] == 'h') && (_GetDirection[4] == 't')) return 2;
            else return 0;
        } else if((_GetDirection[0] == 'u') && (i == 2)) {
            if(_GetDirection[1] == 'p') return 1; 
            else return 0;
        } else return 0;
    }
    char* getStatusEffectName(int StatusEffect) {
        char * NameOfStatusEffect;
        if (StatusEffect == 0) {
            NameOfStatusEffect[0] = 'N';
            NameOfStatusEffect[1] = 'o';
            NameOfStatusEffect[2] = 'E';
            NameOfStatusEffect[3] = 'f';
            NameOfStatusEffect[4] = 'f';
            NameOfStatusEffect[5] = 'e';
            NameOfStatusEffect[6] = 'c';
            NameOfStatusEffect[7] = 't';
            NameOfStatusEffect[8] = '\0';
            NameOfStatusEffect[9] = '\0';
            NameOfStatusEffect[10] = '\0';
            NameOfStatusEffect[11] = '\0';
            return NameOfStatusEffect;
        }
        else if (StatusEffect == 1) {
            NameOfStatusEffect[0] = 'P';
            NameOfStatusEffect[1] = 'a';
            NameOfStatusEffect[2] = 'r';
            NameOfStatusEffect[3] = 'a';
            NameOfStatusEffect[4] = 'l';
            NameOfStatusEffect[5] = 'y';
            NameOfStatusEffect[6] = 's';
            NameOfStatusEffect[7] = '\0';
            NameOfStatusEffect[8] = '\0';
            NameOfStatusEffect[9] = '\0';
            NameOfStatusEffect[10] = '\0';
            NameOfStatusEffect[11] = '\0';
            return NameOfStatusEffect;
        }
        else if (StatusEffect == 2) {
            NameOfStatusEffect[0] = 'P';
            NameOfStatusEffect[1] = 'o';
            NameOfStatusEffect[2] = 'i';
            NameOfStatusEffect[3] = 's';
            NameOfStatusEffect[4] = 'o';
            NameOfStatusEffect[5] = 'n';
            NameOfStatusEffect[6] = '\0';
            NameOfStatusEffect[7] = '0';
            NameOfStatusEffect[8] = '\0';
            NameOfStatusEffect[9] = '\0';
            NameOfStatusEffect[10] = '\0';
            NameOfStatusEffect[11] = '\0';
            return NameOfStatusEffect;
        }
        else if (StatusEffect == 3) {
            NameOfStatusEffect[0] = 'B';
            NameOfStatusEffect[1] = 'a';
            NameOfStatusEffect[2] = 'd';
            NameOfStatusEffect[3] = 'P';
            NameOfStatusEffect[4] = 'o';
            NameOfStatusEffect[5] = 'i';
            NameOfStatusEffect[6] = 's';
            NameOfStatusEffect[7] = 'o';
            NameOfStatusEffect[8] = 'n';
            NameOfStatusEffect[9] = '\0';
            NameOfStatusEffect[10] = '\0';
            NameOfStatusEffect[11] = '\0';
            return NameOfStatusEffect;
        }
        else if (StatusEffect == 4) {
            NameOfStatusEffect[0] = 'B';
            NameOfStatusEffect[1] = 'u';
            NameOfStatusEffect[2] = 'r';
            NameOfStatusEffect[3] = 'n';
            NameOfStatusEffect[4] = '\0';
            NameOfStatusEffect[5] = '\0';
            NameOfStatusEffect[6] = '\0';
            NameOfStatusEffect[7] = '\0';
            NameOfStatusEffect[8] = '\0';
            NameOfStatusEffect[9] = '\0';
            NameOfStatusEffect[10] = '\0';
            NameOfStatusEffect[11] = '\0';
            return NameOfStatusEffect;
        }
        else if (StatusEffect == 5) {
            NameOfStatusEffect[0] = 'F';
            NameOfStatusEffect[1] = 'r';
            NameOfStatusEffect[2] = 'e';
            NameOfStatusEffect[3] = 'e';
            NameOfStatusEffect[4] = 'z';
            NameOfStatusEffect[5] = 'e';
            NameOfStatusEffect[6] = '\0';
            NameOfStatusEffect[7] = '\0';
            NameOfStatusEffect[8] = '\0';
            NameOfStatusEffect[9] = '\0';
            NameOfStatusEffect[10] = '\0';
            NameOfStatusEffect[11] = '\0';
            return NameOfStatusEffect;
        }
        else if (StatusEffect == 6) {
            NameOfStatusEffect[0] = 'S';
            NameOfStatusEffect[1] = 'l';
            NameOfStatusEffect[2] = 'e';
            NameOfStatusEffect[3] = 'e';
            NameOfStatusEffect[4] = 'p';
            NameOfStatusEffect[5] = '\0';
            NameOfStatusEffect[6] = '\0';
            NameOfStatusEffect[7] = '\0';
            NameOfStatusEffect[8] = '\0';
            NameOfStatusEffect[9] = '\0';
            NameOfStatusEffect[10] = '\0';
            NameOfStatusEffect[11] = '\0';
            return NameOfStatusEffect;
        }
    }
    void delay(int jeda) {
        //Kamus Lokal
        int i; int c; int d;
        for (i=jeda; i>0; i--)
            for ( c = 1 ; c <= 32560  ; c++ )
                for ( d = 1 ; d <= 10000 ; d++ ) { }
    }
}


#endif // __MY_NAMESPACE