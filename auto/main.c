//
// Created by 董子禛 on 2022/10/10.
//
#include "map.h"
#include "strategy.h"
#include "run.h"
#include "time.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <windows.foundation.h>
int board[12][12];
int r;
int c;
int score;

extern int strategyTable[200][3][3][3][3][3];

void clearScreen(){
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD coordScreen = { 0, 0 };
  SetConsoleCursorPosition( hConsole, coordScreen );
  CONSOLE_CURSOR_INFO cursor_info={1,0};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
//这是一个 C 函数，用于清除屏幕上的内容并将光标移到屏幕的左上角。它通过调用 Windows API 函数来实现这一功能。
//函数中的 GetStdHandle 函数用于获取标准输出（即屏幕）的句柄。COORD 结构体用于表示屏幕坐标，并将其设置为（0，0）表示左上角。SetConsoleCursorPosition 函数用于将光标移到指定的坐标。
//CONSOLE_CURSOR_INFO 结构体用于描述控制台光标的信息，其中包括光标的大小和是否可见。将光标的大小设置为 1 并将其设置为不可见（即设置 bVisible 字段为 0），可以使得调用 Set consoleCursorPosition 函数时不会显示光标。
//总的来说，这个函数用于清除屏幕上的内容并将光标移到屏幕的左上角，同时隐藏光标。
int main() {
  srand(time(0));

  readStrategy();
  createMaps();
  printMaps();
  clearScreen();
  for (int steps = 0; steps < 200; ++steps) {//走200步
	executeAll(0);
	printMaps();
	usleep(100000);
	clearScreen();
  }
  system("cls");
  printf("final score is %d\n",score);
  system("pause");
  return 0;
}
