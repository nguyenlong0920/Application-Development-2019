#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "screen.h"				//for user-defined header, use double quotes
#include "sound.h"

int main(){
	FILE *f;
	short sd[RATE];				// for all samples in 1 second
	while(1) {
		int ret = system(CMD);
		if (ret == SIGINT) break;
		f = fopen("test.wav", "r");	// open this file for read only
		clearScreen();
		setColors(YELLOW,bg(BLUE));
		if (f == NULL){
			printf("Cannot open the wav file\n");
			return 1;
		}
		struct WAVHDR h;		// instance of wav header
		fread(&h, sizeof(h), 1, f);	// read wav header to h
		displayWAVHDR(h);		// show wav header information
		fread(&sd, sizeof(sd), 1, f);
		displayWAVDATA(sd);
		fclose(f);			// close the open file
	}
}
