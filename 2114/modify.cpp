#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string>

void main() {
	FILE* fp; fp = fopen("test.txt", "wb"); 
	if (fp) { 
		for (int i = 0; i < 10; i++) { 
			fwrite(&i, sizeof(int), 1, fp); 
		} 
		fclose(fp); 
	} 
	fp = fopen("test.txt", "rb+"); 
	if (fp) { 
		fpos_t filepos = sizeof(int) * 3; fsetpos(fp, &filepos); 
		int i = 10; int nco = fwrite(&i, sizeof(int), 1, fp); fclose(fp); 
	} 
	fp = fopen("test.txt", "rb"); 
	if (fp) { int nval; for (int i = 0; i < 11; i++) { 
		fread(&nval, sizeof(int), 1, fp); 
	} 
	fclose(fp); 
	}

}