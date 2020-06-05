#ifndef _TYPES_H_
#define _TYPES_H_
#include <memory>
#include <cstring>
#include <iostream>
using namespace std;

namespace img_proc
{   
        //based on opencv color spaces
    enum colorSpaceCode{CS_8U=1,CS_8U3=3};
        

    class Img{
        private:

            int width;
            int height;
            int channels;
            unsigned char * data;

            unsigned int color_space_code;


        public:

            explicit Img();
            Img(const Img &img2) {
                width = img2.width; 
                height = img2.height; 
                data = img2.data;
        
            } 
        
            
            explicit Img(int width, int height,img_proc::colorSpaceCode code=CS_8U3,unsigned char* data=NULL);


            inline int getWidth(){
                return width;
            }
            inline int getHeight(){
                return height;
            }
            inline int getChannels(){
                return channels;
            } 
            inline unsigned char* getData(){
                return data;
            }

            inline Img & operator = (const Img & img){

                this->width = img.width;
                this->height = img.height;
                this->channels = img.channels;
                this->data = img.data;
                return *this;

            };


    };
}
#endif
