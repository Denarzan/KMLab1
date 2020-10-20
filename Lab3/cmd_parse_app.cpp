#include <stdio.h>
#include <unistd.h>
#include <map>
#include <string>
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[]){
    int rez=0;
	map <string, bool> used;

	int option_index = -1;
	const char* short_options = "hvldcbV::?";
	
	const struct option long_options[] = {
        {"help",0,NULL,'h'},
        {"list",0,NULL,'l'},
        {"version",0,NULL,'v'},
		{"dota",0,NULL,'d'},
		{"csgo",0,NULL,'c'},
		{"borderlands3",0,NULL,'b'},
		{"value",2,NULL,'V'},
        {NULL,0,NULL,0},
    };


	while ((rez = getopt_long(argc,argv,short_options,long_options, &option_index)) != -1){
		switch (rez){
		case 'h': { 
			if (used["h"] == false) {
				printf("Arg: Help\n"); 
				used["h"] = true;
				break;
			} 
			break;
		}
		case 'v': {
			if (used["v"] == false) {
				printf("Arg: version\n"); 
				used["v"] = true;
				break;
			}
			break;
		}
		case 'l': {
			if (used["l"] == false) {
				printf("Arg: List\n"); 
				used["l"] = true;
				break;
			}
			break;
		}
		case 'd': {
			if (used["d"] == false) {
				printf("Arg: dota <3\n"); 
				used["d"] = true;
				break;
			}
			break;
		}
		case 'c': {
			if (used["c"] == false) {
				printf("Arg: csgo =)\n"); 
				used["c"] = true;
				break;
			}
			break;
		}
		case 'b': {
			if (used["b"] == false) {
				printf("Arg: borderlands3 aeeee\n"); 
				used["b"] = true;
				break;
			}
			break;
		}
		case 'V': {
			if (used["V"] == false) {
				if (optarg == NULL) {
					printf("Arg: value\n"); 
					used["V"] = true;
				} else {
					printf("Arg: %s value\n", optarg); 
					used["V"] = true;
				}
				
				break;
			}
			break;
		}
		default: {
			printf("This key is not found\n");
			break;
			}
        };
		option_index = -1;
	};
};
