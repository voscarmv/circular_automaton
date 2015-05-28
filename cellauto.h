/* Deterministic cellular automaton V2 */
int imgcelldetermiter2(int **img, int **buffer, int *seq, int len, int iter, int x, int y);

/* Display sequence */
int printseq(int *seq, int len);

/* Initialize sequence seq randomly */
int initseq(int *seq, int len);

/* Copy sequence ori to dest */
int copyseq(int *dest, int*ori, int len);

/* Iteration for deterministic cellular automaton */
int imgcelldetermiter(int **img, int **buffer, int *seq, int len, int iter, int x, int y);

/* Disturb the deterministic sequence */
int disturbseq(int *seq, int len);

/* Save comparison between circle and cells in compare */
int imgcompare(int **compare, int **circle, int **cells, int x, int y);

/* One iteration of cellular automata. Requires buffer image */
int imgcelliter(int **img, int **buffer, int x, int y);

/* Draw circle of radius r with center on (cx,cy) on img */
int imgdrawcircle(int **img, int cx, int cy, int r);

/* Allocate memory to image matrix */
int **imgalloc(int x, int y);

/* Free image matrix memory */
int imgfree(int **img, int x, int y);

/* Assign zeros to all pixels in image matrix */
int imgclear(int **img, int x, int y);

/* Copy (0,0) to (x,y) submatrix from ori image to dest image */
int imgcopy(int **dest, int **ori, int x, int y);

/* Print image matrix in PPM format to stdout */
int printppm(int **img, int x, int y);

/* Set a pixel in img matrix to 1 */
int imgseed(int **img, int x, int y);

/* Save image matrix in PPM format */
void saveppm(char *fname, int **img, int x, int y);
