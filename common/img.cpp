#include <types.h>
#include <iostream>
img_proc::Img::Img(){
    int width = 0;
    int height = 0;
    int channels = 0;
    this->data = NULL;
    
}

img_proc::Img::Img(int width, int height,img_proc::colorSpaceCode code,unsigned char* data)
{
    this->width = width;
    this->height = height;
    this->channels = code;
    
    this->data = new unsigned char [width*height*channels];
    memcpy(this->data,data+1,width*height*channels);

    
}
