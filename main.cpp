#include <ncurses.h>
#include <iostream>
using namespace std;

char papan[3][3];
char pemainSekarang = 'X';
bool gameAktif = true;

void initPapan() {
    char angka = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            papan[i][j] = angka;
            angka++;
        }
    }

}
void gambarPapan() {
    clear();
    mvprintw(1, 10, "=== TIC TAC TOE ===");
    mvprintw(2, 10, "Pemain: ");
    mvaddch(2, 18, pemainSekarang);
  
    mvprintw(3, 10, "+---+---+---+");

    for (int i = 0; i < 3; i++) {
        int y = 4 + (i * 2);

        mvprintw(y, 10, "| ");
        mvaddch(y, 12, papan[i][0]);
        mvprintw(y, 13, " | ");
        mvaddch(y, 16, papan[i][1]);
        mvprintw(y, 17, " | ");
        mvaddch(y, 20, papan[i][2]);
        mvprintw(y, 21, " |");

        if (i < 2) {
            mvprintw(y + 1, 10, "|---|---|---|");
        }
    }

    mvprintw(9, 10, "+---+---+---+"); 
    
    mvprintw(11, 10, "Pilih posisi (1-9) atau 'q' untuk keluar");
    refresh();
}



bool cekMenang(){
    for (int i = 0; i < 3; i++) {
        if (papan[i][0] == papan[i][1] && papan[i][1] == papan[i][2]) {
            return true;
        }
    }
    for (int j = 0; j < 3; j++) {
        if (papan[0][j] == papan[1][j] && papan[1][j] == papan[2][j]) {
            return true;
        }
    }
    if (papan[0][0] == papan[1][1] && papan[1][1] == papan[2][2]) {
        return true;
    }
    if (papan[0][2] == papan[1][1] && papan[1][1] == papan[2][0]) {
        return true;
    }
    return false;
}

bool cekSeri() {
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (papan[y][x] != 'X' && papan[y][x] != 'O')
                return false;
        }
    }
    return true;
}

void pemain() {
    char input = getch();
    
    if (input == 'q' || input == 'Q') {
        gameAktif = false;
        return;
    }
    
    if (input >= '1' && input <= '9') {
        int posisi = input - '1';
        int baris = posisi / 3;
        int kolom = posisi % 3;
        
        if (papan[baris][kolom] != 'X' && papan[baris][kolom] != 'O') {
            papan[baris][kolom] = pemainSekarang;
            
            if (cekMenang()) {
                gambarPapan();
                mvprintw(12, 10, "PEMAIN ");
                mvaddch(12, 17, pemainSekarang);
                mvprintw(12, 18, " MENANG!");
                mvprintw(13, 10, "Tekan tombol apapun untuk keluar...");
                refresh();
                getch();
                gameAktif = false;
            } else if (cekSeri()) {
                gambarPapan();
                mvprintw(12, 10, "PERMAINAN SERI!");
                mvprintw(13, 10, "Tekan tombol apapun untuk keluar...");
                refresh();
                getch();
                gameAktif = false;
            } else {
                if (pemainSekarang == 'X') {
                    pemainSekarang = 'O';
                } else {
                    pemainSekarang = 'X';
                }
            }
        } else {
            mvprintw(12, 10, "Posisi sudah terisi! Tekan tombol untuk lanjut...");
            refresh();
            getch();
        }
    }
}

int main() {
    initscr();
    noecho();
    cbreak();
    
    initPapan();
    
    while (gameAktif) {
        gambarPapan();
        pemain();
    }
    
    endwin();
    return 0;
}

