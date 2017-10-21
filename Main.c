#include "headers/main.h"

int N_arg = 3;
struct Tuple g_tile_arr[4096];
struct Tuple g_agent;


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
					g_tile_arr[x].x = strtol(strtok(tuple_arr[x], ","), NULL, 10);
					g_tile_arr[x].y = strtol(strtok(NULL, ","), NULL, 10);
					g_tile_arr[x].initialised = 1;
					printf("Loaded tuple [%d,%d]\n", g_tile_arr[x].x, g_tile_arr[x].y);
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


struct Blockboard generate_blockboard(void){
	printf("Generating new block board.\n");
	struct Blockboard new_board;
	new_board.N = N_arg;
	new_board.i_max = N_arg*N_arg;
	for(int i = 0; i < 4096; i++){
		if(g_tile_arr[i].initialised == 1){
			struct Tuple t;
			t.initialised = 1;
			t.x = g_tile_arr[i].x;
			t.y = g_tile_arr[i].y;
			new_board.tiles[i] = t;
			coord_to_index(new_board.tiles[i], new_board);
		} else {
			break;
		}
	}

	return new_board;
}


int coord_to_index(struct Tuple t, struct Blockboard b){
	int index = (((t.y-1) * b.N) + (t.x % (b.N+1)));
	return index;
}
