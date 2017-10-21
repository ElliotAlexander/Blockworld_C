#include "headers/main.h"

int N = 3;


int main (int argc, char **argv){

	int c = 0;
	while((c = getopt(argc, argv, "n:a:t:")) != -1){
		// Program arguments
		switch(c){

			// Size of grid (nxn).
			case 'n':
			{
				int state_val;
				state_val = sscanf(optarg, "%d", &N);
				printf("Parsing N = %d | Return code : %d \n", N, state_val);
				break;
			}

			// position of agent
			case 'a':
			{	
				char* tuple_string;
				tuple_string = optarg;
				int x,y;
				int state_val = sscanf(strtok(tuple_string, ","), "%d", &x);
				state_val = state_val && (sscanf(strtok(NULL, ","), "%d", &y));
				printf("Parsed agent position of [%d,%d] | return state %d\n", x, y, state_val);
				break;
			}

			// Tiles to be filled.
			case 't':
			{
				int i = 0;
				char* tuple_arr[128];
				struct Tuple tile_arr[N*N];

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
		}
	}


}


void parse_arguments(int argc, char **argv){
	printf("Loading arguments...\n");


}
