#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int imgcompare(int **compare, int **circle, int **cells, int x, int y){
	int i, j, ctr = 0;

	for(i = 0; i < x; i ++)
		for(j = 0; j < y; j ++)
			if(circle[i][j] == cells[i][j]){
				compare[i][j] = 0;
				if(cells[i][j] == 255)
					ctr ++;
			}
			else
				compare[i][j] = 255;

	return ctr;
}

int imgcelliter(int **img, int **buffer, int x, int y){
	int i, j, rx, ry, ctr = 0;

	imgcopy(buffer, img, x, y);

	for(i = 0; i < x; i ++)
		for(j = 0; j < y; j ++)
			if(buffer[i][j] > 0){
				ctr ++;
				rx = (rand() % 3 - 1);
				ry = (rand() % 3 - 1);
				if(img[i + rx][j + ry] == 0){
					img[i + rx][j + ry] = 255;
					ctr ++;
				}
			}

	return ctr;
}

int imgdrawcircle(int **img, int cx, int cy, int r){
	int i, j, a, b, ctr = 0;

	for(i = cy - r; i < cy + r; i ++){
		a = cy - i;
		b = sqrt(r * r - a * a);
		for(j = cx - b; j < cx + b; j ++){
			img[i][j] = 255;
			ctr ++;
		}
	}

	return ctr;
}

int imgseed(int **img, int x, int y){
	img[x][y] = 255;
	return 0;
}

int printppm(int **img, int x, int y){
	int i, j;
	printf("P3\n%d %d\n256\n", x, y);
	for(i = 0; i < x; i ++)
		for(j = 0; j < y; j ++)
			printf(
				"%d %d %d\n",
				img[i][j] % 256,
				img[i][j] % 256,
				img[i][j] % 256
			);
	return 0;
}

int imgcopy(int **dest, int **ori, int x, int y){
	int i, j;
	for(i = 0; i < x; i ++)
		for(j = 0; j < y; j ++)
			dest[i][j] = ori[i][j];
	return 0;
}

int imgclear(int **img, int x, int y){
	int i, j;
	for(i = 0; i < x; i ++)
		for(j = 0; j < y; j ++)
			img[i][j] = 0;

	return 0;
}

int **imgalloc(int x, int y){
	int i;

	int **img = malloc(sizeof(int *) * x);
	for(i = 0; i < x; i ++)
		img[i] = malloc(sizeof(int) * y);

	return img;
}

int imgfree(int **img, int x, int y){
	int i;

	for(i = 0; i < x; i ++)
		free(img[i]);
	free(img);

	return 0;
}

void saveppm(char *fname, int **img, int x, int y){
	int i, j;
	FILE *fp = fopen(fname, "w");
	fprintf(fp, "P3\n%d %d\n255\n", x, y);
	for(i = 0; i < x; i ++, fprintf(fp, "\n"))
		for(j = 0; j < y; j ++)
				if(img[i][j])
					fprintf(
						fp,
						"%d %d %d\n",
						img[i][j] % 256,
						img[i][j] % 256,
						img[i][j] % 256
					);
				else
					fprintf(fp, "0 0 0\n");
	fclose(fp);
	return;
}
