//
// Created by 董子禛 on 2022/10/10.
//

#include "map.h"
#include<stdlib.h>

extern int board[12][12];
extern int r;
extern int c;
extern int score;


int randomInt(int x, int y) {
  int ret = (rand() % (y - x + 1) + x);
  return ret;
}/*generate random integers from x to y*/



void createMaps() {
  r = 1;
  c = 1;
  score = 0;
  for (int i = 0; i < 12; ++i) {
	board[0][i] = 2;
	board[i][0] = 2;
	board[11][i] = 2;
	board[i][11] = 2;
  }/*generate boundary*/

  for (int i = 1; i < 11; ++i) {
	for (int j = 1; j < 11; ++j) {
	  board[i][j] = randomInt(0, 1);
	}
  }/*generate map inside*/
}


