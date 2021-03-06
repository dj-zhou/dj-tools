/**************************************************************************
   File Name      : main.c
   Author         : Dingjiang Zhou
                    Boston University, Boston, 02215
   Email          : zhoudingjiang@gmail.com
   Create Time    : Fri, Aug. 09th, 2013. 00:45:50 PM
   Last Modified  : Sat, Oct. 01st, 2016. 09:11:08 AM
   Purpose        : to clean the ~ folder in Linux computer.
**************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
 

// ------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	float data_float; 
	uint8_t * data_ptr = (uint8_t*) (&data_float);
	uint8_t data_u8[4];
	if (argc == 1) {
		printf("usage: \n");
		printf("    float-to-u8 <float number>\n");
		printf("    float-to-u8 <float nubmer> l/b\n");
		printf("    float-to-u8 <float number> little/big\n"); 
	}
	else if (argc == 2) {
		data_float = atof(argv[1]); 
		for (int i=0;i<4;i++) {
			data_u8[i] = *data_ptr;
			data_ptr++; 
		} 
		printf(" float: %f <=> u8: [%d, %d, %d, %d] (little endian)\n",
		data_float,data_u8[0],data_u8[1],data_u8[2],data_u8[3]);
		printf(" float: %f <=> u8: [0x%02X, 0x%02X, 0x%02X, 0x%02X] (little endian)\n",
		data_float,data_u8[0],data_u8[1],data_u8[2],data_u8[3]);
	}
	else if (argc == 3) {
		data_float = atof(argv[1]); 
		for (int i=0;i<4;i++) {
			data_u8[i] = *data_ptr;
			data_ptr++; 
		} 
		data_float = atof(argv[1]);
		if(argv[2][0] == 'l') {
			printf(" float: %f <=> u8: [%d, %d, %d, %d] (little endian)\n",
			data_float,data_u8[0],data_u8[1],data_u8[2],data_u8[3]);
			printf(" float: %f <=> u8: [0x%02X, 0x%02X, 0x%02X, 0x%02X] (little endian)\n",
			data_float,data_u8[0],data_u8[1],data_u8[2],data_u8[3]);
		}
		else if (argv[2][0] == 'b') {
			printf(" float: %f <=> u8: [%d, %d, %d, %d] (big endian)\n",
			data_float,data_u8[3],data_u8[2],data_u8[1],data_u8[0]);
			printf(" float: %f <=> u8: [0x%02X, 0x%02X, 0x%02X, 0x%02X] (big endian)\n",
			data_float,data_u8[3],data_u8[2],data_u8[1],data_u8[0]);
		}
	}
	return 0;
}


/* --------------------------- end of file ----------------------------- */



