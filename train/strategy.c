//
// Created by 董子禛 on 2022/10/19.
//

#include "strategy.h"
#include "map.h"
#include <assert.h>
#include <stdio.h>

int strategyTable[200][3][3][3][3][3];
extern double ave;
extern int generation;
static FILE *fp = NULL;

void startTraining() {
  fp = fopen("train.txt", "w+");

}

void createStrategy() {//生成策略
  for (int times = 0; times < 200; ++times) {
	for (int i = 0; i < 3; ++i) {
	  for (int j = 0; j < 3; ++j) {
		for (int k = 0; k < 3; ++k) {
		  for (int l = 0; l < 3; ++l) {
			for (int m = 0; m < 3; ++m) {
				strategyTable[times][i][j][k][l][m] = randomInt(0, 6);
			}
		  }
		}
	  }
	}
  }
}

void finalStrategy() {//打印最终策略
  fp = fopen("strategy.txt", "w+");
  assert(fp != NULL);

  for (int i = 0; i < 3; ++i) {
	for (int j = 0; j < 3; ++j) {
	  for (int k = 0; k < 3; ++k) {
		for (int l = 0; l < 3; ++l) {
		  for (int m = 0; m < 3; ++m) {
			fprintf(fp, "%d\t", strategyTable[199][i][j][k][l][m]);
		  }
		}
	  }
	}
  }
  fclose(fp);
}

void printTraining() {
  fprintf(fp, "%d:%f\n",generation, ave);
}

void exitProgramme() {
  fclose(fp);
}