//
// Created by 董子禛 on 2022/11/2.
//

#include "run.h"
#include "map.h"

int movement;
extern int r;
extern int c;
extern int score;
extern int board[12][12];
extern int strategyTable[200][3][3][3][3][3];

void run(int input) {
  if (input == 0) {
	input = randomInt(1, 6);
  }
  switch (input) {
	case 1:
	  if (board[r - 1][c] != 2) {
		r -= 1;
	  } else {
		score -= 5;
	  }
	  break;
	case 2:
	  if (board[r + 1][c] != 2) {
		r += 1;
	  } else {
		score -= 5;
	  }
	  break;
	case 3:
	  if (board[r][c - 1] != 2) {
		c -= 1;
	  } else {
		score -= 5;
	  }
	  break;
	case 4:
	  if (board[r][c + 1] != 2) {
		c += 1;
	  } else {
		score -= 5;
	  }
	  break;
	case 5: break;
	case 6:
	  if (board[r][c] == 1) {
		board[r][c] = 0;
		score += 10;
	  } else {
		score -= 2;
	  }
	  break;
	default: break;
  }
}

void executeAll(int times) {
  int up = board[r - 1][c];
  int down = board[r + 1][c];
  int left = board[r][c - 1];
  int right = board[r][c + 1];
  int position = board[r][c];
  movement = strategyTable[times][up][down][left][right][position];
  run(movement);
}