//
// Created by 董子禛 on 2022/10/10.
//
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include "strategy.h"
#include "run.h"
#include "reproduce.h"
#include "offspring.h"

int board[12][12];
int r;
int c;
int score;
int generation;
extern int strategyTable[200][3][3][3][3][3];
extern int childTable[200][3][3][3][3][3];
extern int father;
extern int mother;
extern double ave;


int main() {
  srand(time(0));
  createStrategy();
  startTraining();
  for ( generation = 0; generation < 1000; ++generation) {
	oneGeneration();
	printf("%d:%f\n" , generation,ave);
	arrangeOrder();
	printTraining();
	for (int times = 0; times < 95; ++times) {
	  selectingCouples();
	  generateOffspring(times, mother, father);
	}
	childGrowth();
  }
  exitProgramme();
  finalStrategy();//打印最终策略表
  system("pause");
  return 0;
}