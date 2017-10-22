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
	int contains_tile;
	struct Tuple coords;
	int visited;
} Square;

typedef struct Blockboard {
	int N;
	struct Tuple tiles[4096];
	struct Tuple agent;
	struct Square squares[4096];
} Blockboard;

#include "Utils.h"
#include "Stack.h"

void generate_args(int argc, char** argv);
struct Blockboard* generate_blockboard(void);

#endif


