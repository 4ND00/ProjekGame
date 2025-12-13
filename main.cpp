#include <ncurses.h>

void initPapan(){
  char board[3][3];

void initBoard() {
    char angka = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = angka;  // isi 1–9 untuk panduan posisi
            angka++;
        }
    }

}
  
}

void gambarPapan(){
  
}

void pemain(){
  
}

void cekMenang(){
  
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

    return true;
}
  
}

int main() {
    initscr();   
    noecho();

    initBoard();  
    drawBoard();  

    getch();      
    endwin();     
    return 0;
}
