#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cellauto.h"

#define SEQLEN 8

int main(){
	int s = 500;
/*
	Image layers
*/
	int **cells = imgalloc(s, s);
	int **buffer = imgalloc(s, s);
	int **circle = imgalloc(s, s);
	int **compare = imgalloc(s, s);

	imgclear(cells, s, s);
	imgclear(circle, s, s);
	imgclear(compare, s, s);

	imgseed(cells, s / 2, s / 2);

	int circlearea = imgdrawcircle(circle, s / 2, s / 2, s / 3);
	int cellsarea = 1;

	int hits = 0;
	int error;
	char fname[64];

	int i = 0;
	while(cellsarea <= circlearea){
		hits = imgcompare(compare, circle, cells, s, s);
		printf(
			"cell%04d.ppm %d %d %.2f %d %.2f\n",
			i,
			cellsarea,
			circlearea,
			(double) (cellsarea * 100) / circlearea,
			hits,
			(double) (hits * 100) / circlearea
		);
		sprintf(fname, "cell%04d.ppm", i ++);
		saveppm(fname, compare, s, s);
		error = circlearea - hits;
		cellsarea = imgcelliter(cells, buffer, s, s);
		i ++;
	}

	imgfree(cells, s, s);
	imgfree(buffer, s, s);
	imgfree(circle, s, s);
	imgfree(compare, s, s);

	return 0;
}
