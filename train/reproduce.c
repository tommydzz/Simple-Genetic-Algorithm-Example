//
// Created by 董子禛 on 2022/11/3.
//

#include "reproduce.h"
#include "map.h"
#include "strategy.h"
#include "run.h"

double sum;
double average[200];//一代中各个小黄在100张地图中的均值
int mother;
int father;
double ave;//每一代的平均值
extern int score;
extern int strategyTable[200][3][3][3][3][3];

void oneGeneration() {
  double temp = 0;
  for (int numberYellow = 0; numberYellow < 200; ++numberYellow) {//小黄200个
	sum = 0;
	for (int numberMap = 0; numberMap < 100; ++numberMap) {//地图100个
	  createMaps();
	  for (int steps = 0; steps < 200; ++steps) {//走200步
		executeAll(numberYellow);
	  }
	  sum += score;
	}
	average[numberYellow] = sum / 100;
  }
  for (int i = 0; i < 200; ++i) {
	temp = temp + average[i];
  }
  ave = temp / 200;
}

void arrangeOrder() {//按照average的值对策略表从小到大排序
  double buf;
  int buff;
  for (int i = 0; i < 199; ++i)
  {
	for (int j = 0; j < 199 - i; ++j)
	{
	  if (average[j] > average[j + 1]) {

		for (int k = 0; k < 3; ++k) {
		  for (int l = 0; l < 3; ++l) {
			for (int m = 0; m < 3; ++m) {
			  for (int n = 0; n < 3; ++n) {
				for (int i1 = 0; i1 < 3; ++i1) {
				  buff = strategyTable[j][k][l][m][n][i1];
				  strategyTable[j][k][l][m][n][i1] = strategyTable[j + 1][k][l][m][n][i1];
				  strategyTable[j + 1][k][l][m][n][i1] = buff;
				}
			  }
			}
		  }
		}
		buf = average[j];
		average[j] = average[j + 1];
		average[j + 1] = buf;
	  }
	}
  }
}

void selectingCouples() {//按照排序结果选择父本母本
  int a = randomInt(1, 20100);

  for (int i = 0; i < 200; ++i) {
	if (i * (i + 1) / 2 < a && a <= (i + 1) * (i + 2) / 2) {
	  mother = i;
	  break;
	}
  }
  a = randomInt(1, 20100);
  for (int i = 0; i < 200; ++i) {
	if (i * (i + 1) / 2 < a && a <= (i + 1) * (i + 2) / 2) {
	  father = i;
	  break;
	}
  }

}

