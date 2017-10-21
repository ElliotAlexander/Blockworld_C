
#include "headers/main.h"

int N_arg = 3;


int main (int argc, char **argv){

	generate_args(argc, argv);
	generate_blockboard();

}

void generate_args(int argc, char** argv){
	int c = 0;
	while((c = getopt(argc, argv, "n: a: t:")) != -1){

		// Program arguments
		switch(c){

			// Size of grid (nxn).
			case 'n':
			{
				int state_val;
				state_val = sscanf(optarg, "%d", &N_arg);
				printf("Parsing N = %d | Return code : %d \n", N_arg, state_val);
				break;
			}

			// position of agent
			case 'a':
			{
				int x,y, state_val;
				state_val = sscanf(strtok(optarg, ","), "%d", &x);
				state_val = state_val && (sscanf(strtok(NULL, ","), "%d", &y));
				printf("Parsed agent position of [%d,%d] | return state %d\n", x, y, state_val);
				break;
			}

			// Tiles to be filled.
			case 't':
			{
				int i = 0;
				char* tuple_arr[128];
				struct Tuple tile_arr[N_arg*N_arg];

				tuple_arr[i] = strtok(optarg, ":");
				while(tuple_arr[i] != NULL){
					i += 1;
					tuple_arr[i] = strtok(NULL, ":");
				}

				for(int x = 0; x < i; x++){
					tile_arr[x].x = strtol(strtok(tuple_arr[x], ","), NULL, 10);
					tile_arr[x].y = strtol(strtok(NULL, ","), NULL, 10);
					printf("Loaded tuple [%d,%d]\n", tile_arr[x].x, tile_arr[x].y);
				}

				break;
			}
			default: {
				printf("Unrecognised arg. Skipping.\n");
				break;
			}
		}
	}
}


void generate_blockboard(void){
	struct Blockboard new_board;
	new_board.N = N_arg;
	new_board.i_max = N_arg*N_arg;
	new_board.tiles = (struct Tuple**)malloc(sizeof(struct Tuple) * new_board.i_max);
}


int coord_to_index(struct Tuple t, struct Blockboard b){
	int index = ((t.y * b.N) + (t.x % b.N));
	return index;
}
