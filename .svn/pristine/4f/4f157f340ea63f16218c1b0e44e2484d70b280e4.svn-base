#include <stdio.h>
#include <stdlib.h>
#include "hw4_provided.h"
#include "hw4.h"

int main()
{
	//Hiding one image in another
	char *pic1 = "uchicago.png";
	char *pic2 = "happyface.png";
	char *pic3 = "temp1.png";
	encode(pic2, pic1, pic3);
	//Decoding back to the original
	char *pic4 = "uchicagoafter.png";
	decode(pic3, pic4);

	//Hiding the opposite image
	char *pic5 = "temp2.png";
	encode(pic1, pic2, pic5);
	//Decoding back to the original
	char *pic6 = "happyfaceafter.png";
	decode(pic5, pic6);
}