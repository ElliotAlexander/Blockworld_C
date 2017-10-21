#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void parse_arguments(int argc, char ** argv);

typedef struct Tuple {
    int x;
    int y;
} tTuple;

#endif
