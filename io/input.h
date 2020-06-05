#ifndef _INPUT_H_
#define _INPUT_H_
#include <types.h>
#include <fstream>


img_proc::Img imread(const char* filepath);

img_proc::Img read_ppm(ifstream &fs);
void write_ppm(ofstream &fs,img_proc::Img img);

void imwrite(const char* filepath,img_proc::Img img);


#endif