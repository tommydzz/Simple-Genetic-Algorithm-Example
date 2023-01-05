//
// Created by 董子禛 on 2022/11/3.
//

#include "offspring.h"
#include "reproduce.h"
#include "map.h"

#define MU 200

extern int strategyTable[200][3][3][3][3][3];
int childTable[200][3][3][3][3][3];

void generateOffspring(int times, int mom, int dad) {//基因重组与变异
  int *p = (int *)&strategyTable[mom];
  int *q = (int *)&strategyTable[dad];
  int *a = (int *)&childTable[2 * times];
  int *b = (int *)&childTable[2 * times + 1];
  for (int i = 0; i < 60; ++i) {
	if (randomInt(0, MU) != 0) {
	  *(a + i) = *(p + i);
	} else {
	  *(a + i) = randomInt(0, 6);
	}
	if (randomInt(0, MU) != 0) {
	  *(b + i) = *(q + i);
	} else {
	  *(b + i) = randomInt(0, 6);
	}
  }
  for (int i = 60; i < 120; ++i) {
	if (randomInt(0, MU) != 0) {
	  *(a + i) = *(q + i);
	} else {
	  *(a + i) = randomInt(0, 6);
	}
	if (randomInt(0, MU) != 0) {
	  *(b + i) = *(p + i);
	} else {
	  *(b + i) = randomInt(0, 6);
	}
  }
  for (int i = 120; i < 180; ++i) {
	if (randomInt(0, MU) != 0) {
	  *(a + i) = *(p + i);
	} else {
	  *(a + i) = randomInt(0, 6);
	}
	if (randomInt(0, MU) != 0) {
	  *(b + i) = *(q + i);
	} else {
	  *(b + i) = randomInt(0, 6);
	}
  }
  for (int i = 180; i < 243; ++i) {
	if (randomInt(0, MU) != 0) {
	  *(a + i) = *(q + i);
	} else {
	  *(a + i) = randomInt(0, 6);
	}
	if (randomInt(0, MU) != 0) {
	  *(b + i) = *(p + i);
	} else {
	  *(b + i) = randomInt(0, 6);
	}
  }
  for (int i = 0; i < 10; ++i) {//后十个直接复制最强的
	for (int k = 0; k < 3; ++k) {
	  for (int l = 0; l < 3; ++l) {
		for (int m = 0; m < 3; ++m) {
		  for (int n = 0; n < 3; ++n) {
			for (int i1 = 0; i1 < 3; ++i1) {
			  childTable[199 - i][k][l][m][n][i1] = strategyTable[199 - i][k][l][m][n][i1];
			}
		  }
		}
	  }
	}
  }
}

void childGrowth() {//子代变为本代
  for (int k = 0; k < 200; ++k) {
	for (int l = 0; l < 3; ++l) {
	  for (int m = 0; m < 3; ++m) {
		for (int n = 0; n < 3; ++n) {
		  for (int i1 = 0; i1 < 3; ++i1) {
			for (int i = 0; i < 3; ++i) {
			  strategyTable[k][l][m][n][i1][i] = childTable[k][l][m][n][i1][i];
			}
		  }
		}
	  }
	}
  }
}

