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
