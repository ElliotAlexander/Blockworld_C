#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>



typedef struct Tuple {
	int x;
	int y;
	int initialised;
} Tuple;

typedef struct Square {
	int is_full;
	struct Tuple contains_tile;
} blank_Square;

typedef struct Blockboard{
	int N;
	int i_max;
	struct Tuple tiles[4096];
	struct Tuple agent;
} block_board;

void generate_args(int argc, char** argv);
struct Blockboard generate_blockboard(void);
int coord_to_index(struct Tuple, struct Blockboard b);

#endif
