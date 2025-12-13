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
  
}
void drawBoard() {
    clear();
    mvprintw(1, 10, "=== TIC TAC TOE ===");
    mvprintw(2, 10, "Pemain: ");
    mvaddch(2, 18, pemainSekarang);
  
    mvprintw(3, 10, "+---+---+---+");

    for (int i = 0; i < 3; i++) {
        int y = 4 + (i * 2);

        mvprintw(y, 10, "| ");
        mvaddch(y, 12, board[i][0]);
        mvprintw(y, 13, " | ");
        mvaddch(y, 16, board[i][1]);
        mvprintw(y, 17, " | ");
        mvaddch(y, 20, board[i][2]);
        mvprintw(y, 21, " |");

        if (i < 2) {
            mvprintw(y + 1, 10, "|---|---|---|");
        }
    }

    mvprintw(9, 10, "+---+---+---+"); 
    
    mvprintw(11, 10, "Pilih posisi (1-9) atau 'q' untuk keluar");
    refresh();
}


void pemain(){
  
}

bool cekMenang() {
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
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}


bool cekSeri() {

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (papan[y][x] == ' ')
                return false;
        }
    }

    return true;
}
int main() {
    initscr();
    noecho();
    cbreak();
    
    initPapan();
    
    endwin();
    return 0;
}

