#ifndef UTILS_H
#define UTILS_H

#include "Main.h"
struct Tuple generate_successors(struct Blockboard* b);
struct Tuple index_to_coords(int i, struct Blockboard b);
int coord_to_index(struct Tuple t, struct Blockboard b);


#endif
