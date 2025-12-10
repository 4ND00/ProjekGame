#include <iostream>
#include <ncurses.h>
using namespace std;

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

void cekSeri(){
  
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
