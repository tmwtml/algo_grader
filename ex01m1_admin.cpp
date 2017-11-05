#include <stdio.h>

typedef struct _BLOCK {
	int sx, sy;	// top left corner
	int gx, gy;	// gap location relative to the top left corner
} BLOCK;

static int ix = 0;
FILE * fo = NULL;
FILE * fi = NULL;

void output(BLOCK b) {
	fprintf(fo, "%d %d %d\n", b.gx + b.gy*2, b.sx, b.sy);
}

void tile(int n, BLOCK b) {
	if (n==2) {	// base case
		output(b);
	}
	else
	{
		BLOCK x;
		const int n_2 = n/2;	// rounded down

		// block in the middle
		x.sx = b.sx + n_2 - 1; x.sy = b.sy + n_2 - 1;
		x.gx = (b.gx < n_2)? 0: 1;
		x.gy = (b.gy < n_2)? 0: 1;
		output(x);


		{	// default divisions' starting positions
			// 0-topleft, 1-topright, 2-bottomleft 3-bottomright
			const int SX[4]={b.sx, b.sx+n_2, b.sx, b.sx+n_2};
			const int SY[4]={b.sy, b.sy, b.sy+n_2, b.sy+n_2};

			// default divisions' relative hole positions
			// 0-bottomright, 1-bottomleft, 3-topright, 4-topleft
			const int GX[4]={n_2-1, 0, n_2-1, 0};
			const int GY[4]={n_2-1, n_2-1, 0, 0};

			const int special_block = x.gx + x.gy*2;

			for (int i = 0; i < 4; i++) {
				BLOCK c;

				// assign division's initial positions/ relative hole positions
				c.sx = SX[i];
				c.sy = SY[i];
				if (i != special_block) {
					c.gx = GX[i];
					c.gy = GY[i];
				} else {
					c.gx = b.gx - ((x.gx) ? n_2: 0);
					c.gy = b.gy - ((x.gy) ? n_2: 0);
				}

				// tile a division
				tile(n_2, c);
			}
		}

	}
}

int main( ) {
	int n;
	BLOCK b;
	b.sx = 0;
	b.sy = 0;
	b.gx = 1;
	b.gy = 1;

	//fi = fopen("input.txt", "rt");
	fi = stdin;
	if (!fi) {
		fprintf(stderr, "error open input.txt\n");
		return -1;
	}
	fscanf(fi, "%d %d %d", &n, &b.gx, &b.gy);
	fclose(fi);

	//fo = fopen("output.txt", "wt");
	fo = stdout;
	if (!fo) {
		fprintf(stderr, "error writing output.txt\n");
		return -1;
	}
	fprintf(fo, "%d\n", (n*n-1)/3);

	tile(n, b);

	fclose(fo);

	return 0;
}
