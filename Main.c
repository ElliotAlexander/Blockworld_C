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
				int state_val;
				state_val = sscanf(strtok(optarg, ","), "%d", &g_agent.x);
				state_val = state_val && (sscanf(strtok(NULL, ","), "%d", &g_agent.y));
				printf("Parsed agent position of [%d,%d] | return state %d\n", g_agent.x, g_agent.y, state_val);
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

	// Basic parameters. 
	struct Blockboard new_board;
	new_board.N = N_arg;
	new_board.i_max = N_arg*N_arg;

	// Add tiles. 
	for(int i = 0; i < 4096; i++){
		if(g_tile_arr[i].initialised == 1){

			//  We copy data directly so we can reset the blockboard later. 
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

	printf("Added tiles to blockboard.\nGenerating agent tile.\n");
	
	int x = 0;
	while(new_board.tiles[x].initialised == 1){
		if(new_board.tiles[x].x == g_agent.x && new_board.tiles[x].y == g_agent.y){
			printf("New blockboard rejected. Tiles and agents colide!. [(%d,%d) && (%d,%d)]\nPress enter to exit.", g_agent.x, g_agent.y, new_board.tiles[x].x, new_board.tiles[x].y);
			getchar();
			exit(0);
		}
		x += 1;
	}
	new_board.agent = g_agent;

	return new_board;
}


int coord_to_index(struct Tuple t, struct Blockboard b){
	int index = (((t.y-1) * b.N) + (t.x % (b.N+1)));
	return index;
}
