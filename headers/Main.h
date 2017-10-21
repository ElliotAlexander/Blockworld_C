#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void generate_args(int argc, char** argv);
void generate_blockboard(void);

typedef struct Tuple {
    int x;
    int y;
} tTuple;

typedef struct Square {
	int is_full;
	struct Tuple contains_tile;
} blank_Square;

typedef struct Blockboard{
	int N;
	int i_max;
	struct Tuple** tiles;
	struct Tuple agent;
} block_board;

#endif
