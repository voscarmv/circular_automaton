// circular_automaton, Copyright 2013 Vicente Oscar Mier Vela <vomv1988@gmail.com>
// This file is part of circular_automaton.

// circular_automaton is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// circular_automaton is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with circular_automaton. If not, see <http://www.gnu.org/licenses/>.

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
	while(cellsarea <= circlearea + circlearea/4){
		hits = imgcompare(compare, circle, cells, s, s);
		printf(
			"img/cell%04d.ppm %d %d %.2f %d %.2f\n",
			i,
			cellsarea,
			circlearea,
			(double) (cellsarea * 100) / circlearea,
			hits,
			(double) (hits * 100) / circlearea
		);
		fflush(NULL);
		sprintf(fname, "img/cell%04d.ppm", i ++);
		saveppm(fname, compare, s, s);
		error = circlearea - hits;
		cellsarea = imgcelliter(cells, buffer, s, s);
	}

	imgfree(cells, s, s);
	imgfree(buffer, s, s);
	imgfree(circle, s, s);
	imgfree(compare, s, s);

	return 0;
}
