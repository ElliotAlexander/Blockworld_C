#include "headers/DepthFirstSearch.h"


struct Tile* DepthFirstSearch(struct Blockboard* board){
	struct Stack S;
	Stack_Init(&S);

	for(int x = 0; x < board->N; x++){
		board->squares[x].visited = 0;
	}



}
