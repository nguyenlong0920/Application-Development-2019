#include <stdio.h>
#include <math.h>
#include "sound.h"

// this function take 1 second of samples (16000 in our case)
// and calculate 80 pieces of RMS value,
// and then turns this values into decibels,
// and display them as barchart
void displayWAVDATA(short s[]){
	double rms[80];		// because we have 16000 samples, 16000/80=200
				// therefore every 200 samples makes one RMS
	int i, j;		// neslp counters
	short *ptr = s;		// use poiter point to the beginning of the samples

				// outer loop repeats 80 times
	for (i = 0; i < 80; i++){
		double sum = 0;	// initialize the sum
		for (j = 0; j < 200; j++){
				// acculate the sum
			sum += (*ptr)*(*ptr);
				//pointer increasement
			ptr++;
		}
		rms[i] = sqrt(sum/200);
		printf("RMS[%d] = %f\n", i , rms[i]);
	}
}

void showID(char *name, char*value){
	printf("%s", name);
	for(int i=0; i<4; i++){
		printf("%c", value[i]);
	}
	puts("");		// \n
}
// function definition
void displayWAVHDR(struct WAVHDR h){
	showID("Chunk ID: ", h.ChunkID);
	printf("Chunk size: %d\n", h.ChunkSize);
	showID("Format: ", h.Format);
	showID("Subchunk1 ID: ", h.Subchunk1ID);
	printf("Subchunk1 size: %d\n", h.Subchunk1Size);
	printf("Audio Format: %d\n", h.AudioFormat);
	printf("Number of Channels: %d\n", h.NumChannels);
	printf("Sample Rate: %d\n", h.SampleRate);
	printf("Byte Rate: %d\n", h.ByteRate);
	printf("Block Align: %d\n", h.BlockAlign);
	printf("Bits per sample: %d\n", h.BitsPerSample);
	showID("Subchunk 2 ID: ", h.Subchunk2ID);
	printf("Subchunk 2 size: %d\n", h.Subchunk2Size);
}
