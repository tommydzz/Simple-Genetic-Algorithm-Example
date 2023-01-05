//
// Created by 董子禛 on 2022/10/19.
//

#include "strategy.h"
#include "map.h"
#include <assert.h>
#include <stdio.h>

int strategyTable[200][3][3][3][3][3];
static FILE *fp = NULL;


void readStrategy() {
  fp = fopen("strategy.txt", "r");
  assert(fp != NULL);
	for (int i = 0; i < 3; ++i) {
	  for (int j = 0; j < 3; ++j) {
		for (int k = 0; k < 3; ++k) {
		  for (int l = 0; l < 3; ++l) {
			for (int m = 0; m < 3; ++m) {
			  fscanf(fp, "%d", &strategyTable[0][i][j][k][l][m]);
			}
		  }
		}
	  }
	}
  fclose(fp);
}


