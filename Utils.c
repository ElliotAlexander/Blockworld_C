#include "headers/Utils.h"


int coord_to_index(struct Tuple t, struct Blockboard b){
	int index = (((t.y-1) * b.N) + (t.x % (b.N+1)));
	return index;
}

struct Tuple index_to_coords(int i, struct Blockboard b){
	int x = i % b.N;
	int y = (i - x) / b.N;
	struct Tuple return_t;
	return_t.x = x;
	return_t.y = y;
	return_t.initialised = 1;
	return return_t;
}

void make_move(struct Tuple* agent, struct Tuple* target, struct Blockboard* board){


}


struct Tuple generate_successors(struct Blockboard* b){
	struct Tuple agent = b->agent;
	//struct Tuple xPlus = { x = (agent->x + 1), y = agent->y};
}



