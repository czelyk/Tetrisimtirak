#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>

#define randnum(min, max)\
  ((rand() % (int)(((max) + 1) - (min))) + (min))
int gotoxy(int x, int y) {

  COORD coord = {
    x,
    y
  };
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

  return 0;
}
int main(void) {
  char ch;
  int x;
  int xS;
  int y;
  int a;
  char gorunen;
  int top;
  int b;
  int h = 0;
  int level = 1;
  int g = 0;
  int kaybetme = 0;
  int kazanma = 0;
  int puan = 0;
  int hiz;

  while (kaybetme < 5) {
    if (kazanma == 5) {
      level++;
      kazanma = 0;
    }

    srand(time(NULL));
    top = (rand() % 10);
    if (top == 5 || top == 6 || top == 7)
      gorunen = 2;
    else if (top == 0 || top == 1 || top == 2 || top == 3 || top == 4)
      gorunen = 1;
    else
      gorunen = 36;

    hiz = 300 - level * 10;
    x = 25;
    y = 25;

    while (h < 25) {

      y = h;
      h++;
      Sleep(hiz);

      a = (rand() % 3);

      if (a == 1)
        x++;
      else if (a == 2)
        x--;
      else
        x;

      gotoxy(x, y);

      printf("%c", gorunen);

      if (kbhit()) {

        ch = getch();

        if (ch == 54)
          xS += 4;

        if (ch == 52)
          xS -= 4;

        if (ch == 27)
          break;
      }
      system("cls");
      gotoxy(xS, 25);

      printf("%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 217);

      gotoxy(5, 27);
      printf("KutuKonumu: %d YemKonumu: %d Uzaklik: %d Seviye: %d Hiz: %d Puan: %d Hak: %d", xS, x, 25 - h, level, hiz, puan, 5 - kaybetme);
    }
    if (xS + 1 < x && xS + 5 > x) {
      system("cls");
      gotoxy(xS, 25);
      printf("%c%c%c%c%c%c%c", 192, 43, 43, 43, 43, 43, 217);
      if (gorunen == 1)
        puan += 50;
      else if (gorunen == 2)
        puan += 100;
      else
        puan += 1000;
      kazanma++;
      h = 0;

    } else {
      system("cls");
      gotoxy(xS, 25);
      printf("%c%c%c%c%c%c%c", 192, 126, 126, 126, 126, 126, 217);
      kaybetme++;
      h = 0;
    }

  }
  gotoxy(15, 20);
  printf("OYUN BITTI\n\n\n\n\n\n\n\n");
  return 0;
}