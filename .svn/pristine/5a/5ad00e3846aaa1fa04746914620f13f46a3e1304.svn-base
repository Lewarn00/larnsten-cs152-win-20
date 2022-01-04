#include <stdio.h>
#include <stdlib.h>
#include "hw4_provided.h"
#include "hw4.h"

//A function to construct an image with a hidden image inside it.
void hide_image(
	unsigned int ref_r[ROWS][COLS], 
	unsigned int ref_g[ROWS][COLS], 
	unsigned int ref_b[ROWS][COLS], 
	unsigned int hid_r[ROWS][COLS], 
	unsigned int hid_g[ROWS][COLS], 
	unsigned int hid_b[ROWS][COLS], 
	unsigned int res_r[ROWS][COLS], 
	unsigned int res_g[ROWS][COLS], 
	unsigned int res_b[ROWS][COLS], 
	unsigned int height, unsigned int width)
{
	if(width > COLS || height > ROWS)
	{
		printf("Array size too big.\n");
	}
	else
	{
		//Looping through the size of all images.
		//Checking if each pixel value in the hidden image is greater than 128.
		//Then changing the cooresponding point in the resulting 
		//image to be odd or even accordingly.
		for(int i = 0; i < height; i++){
			for(int j = 0; j < width; j++){
				if(hid_r[i][j] >= 128){
					if(ref_r[i][j] % 2 == 0){
						res_r[i][j] = ref_r[i][j]+1;
					}else{
						res_r[i][j] = ref_r[i][j];
					}	
				}else if(hid_r[i][j] < 128){
					if(ref_r[i][j] % 2 != 0){
						res_r[i][j] = ref_r[i][j]-1;
					}else{
						res_r[i][j] = ref_r[i][j];
					}						
				}
				if(hid_g[i][j] >= 128){
					if(ref_g[i][j] % 2 == 0){
						res_g[i][j] = ref_g[i][j]+1;
					}else{
						res_g[i][j] = ref_g[i][j];
					}	
				}else if(hid_g[i][j] < 128){
					if(ref_g[i][j] % 2 != 0){
						res_g[i][j] = ref_g[i][j]-1;
					}else{
						res_g[i][j] = ref_g[i][j];
					}								
				}
				if(hid_b[i][j] >= 128){
					if(ref_b[i][j] % 2 == 0){
						res_b[i][j] = ref_b[i][j]+1;
					}else{
						res_b[i][j] = ref_b[i][j];
					}	
				}else if(hid_b[i][j] < 128){
					if(ref_b[i][j] % 2 != 0){
						res_b[i][j] = ref_b[i][j]-1;
					}else{
						res_b[i][j] = ref_b[i][j];
					}								
				}
			}
		}
	}
}

//A function to extract the hidden image within an image.
void extract_image(
	unsigned int res_r[ROWS][COLS], 
	unsigned int res_g[ROWS][COLS], 
	unsigned int res_b[ROWS][COLS], 
	unsigned int hid_r[ROWS][COLS], 
	unsigned int hid_g[ROWS][COLS], 
	unsigned int hid_b[ROWS][COLS], 
	unsigned int height, unsigned int width){

	if(width > COLS || height > ROWS)
	{
		printf("Array size too big.\n");
	}
	else
	{
		//Looping through the image and assigning the pixel of the hidden image
		//a value of 255 if the cooresponding pixel in the image is odd,
		//or a value of 0 if it is even. 
		for(int i = 0; i < height; i++){
			for(int j = 0; j < width; j++){
				if (res_r[i][j] % 2 == 0){
					hid_r[i][j] = 0;
				}else{
					hid_r[i][j] = 255;	
				}
				if (res_g[i][j] % 2 == 0){
					hid_g[i][j] = 0;
				}else{
					hid_g[i][j] = 255;		
				}
				if (res_b[i][j] % 2 == 0){
					hid_b[i][j] = 0;
				}else{
					hid_b[i][j] = 255;
				}
			}
		}	
	}	
}

//A function to encode an image in another.
void encode(char *ref_filename, char *hid_filename, char *enc_filename){

	//Initialize variables
	unsigned int ref_r[ROWS][COLS];
    unsigned int ref_g[ROWS][COLS];
    unsigned int ref_b[ROWS][COLS];
    unsigned int width1;
    unsigned int length1;

	unsigned int hid_r[ROWS][COLS];
    unsigned int hid_g[ROWS][COLS];
    unsigned int hid_b[ROWS][COLS];
    unsigned int width2;
    unsigned int length2;

	unsigned int res_r[ROWS][COLS];
	unsigned int res_g[ROWS][COLS]; 
	unsigned int res_b[ROWS][COLS];

	//Read in the image that will contain a hidden image.
	provided_read_png(ref_filename, ref_r, ref_g, 
		ref_b, &width1, &length1);
	//Read in the image that will be hidden.
	provided_read_png(hid_filename, hid_r, hid_g, 
		hid_b, &width2, &length2);
	//Hide the hidden image in the other.
	hide_image(ref_r, ref_g, ref_b, 
	hid_r, hid_g, hid_b, 
	res_r, res_g, res_b, width1, length1);
	//Write the new image to a new file.
    provided_write_png(enc_filename, res_r, res_g, 
    res_b, width2, length2);
}
//A function to decode an image into its hidden image.
void decode(char *enc_filename, char *hid_filename){
	//Initialize variables.
	unsigned int res_r[ROWS][COLS];
    unsigned int res_g[ROWS][COLS];
    unsigned int res_b[ROWS][COLS];
    unsigned int width;
    unsigned int length;

	unsigned int hid_r[ROWS][COLS];
    unsigned int hid_g[ROWS][COLS];
    unsigned int hid_b[ROWS][COLS];
    //Read the image that containes a hidden image.
	provided_read_png(enc_filename, res_r, 
		res_g, res_b, &width, &length);
	//Find the hidden image pixel values.
	extract_image(res_r, res_g, res_b, 
	hid_r, hid_g, hid_b, length, width);
	//Write the hidden image to a new file.
    provided_write_png(hid_filename, hid_r, hid_g, 
    hid_b, width, length);
}