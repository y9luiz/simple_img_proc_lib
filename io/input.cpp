#include <input.h>
#include <iostream>
#include <string.h>

using std::cout;
using namespace img_proc;
img_proc::Img imread(const char* filepath){
    std::ifstream fs;
    fs.open(filepath);
    if(!fs.is_open()){
        cout<<"could not open the file "<<filepath<<"\n";
        exit(0);

    }
   return  read_ppm(fs);

}
int n = 0 ;

img_proc::Img read_ppm(ifstream &fs){

    string data;
    int count_lines =0;
    img_proc::colorSpaceCode code;
    int width=-1;
    int height=-1;
    int max_val=-1;

    unsigned char * ptr;


    while(count_lines<4){
        fs>>data;
        if(data == "P3" || data == "P6")
        {
            code = img_proc::CS_8U3;
        }
        else if(data == "P2"){
            
            code = img_proc::CS_8U;

        }
        else if(width<0){
            width = atoi(data.c_str());
        }
        else if(height<0){
            height = atoi(data.c_str());
           
            ptr = (unsigned char*)  malloc(width*height*code*sizeof(unsigned char));
        }
    
        count_lines+=1;
    }

  std::string str;
  while(getline(fs,str)){
    str.append("\n");
      memcpy(ptr+n,str.c_str(),str.size());
      n+= str.size();
  }


  fs.close();
  Img img(width,height,code,(unsigned char*)ptr) ;
  return img;
}

void imwrite(const char * filename,Img img){

    ofstream fs(filename);

     if(!fs.is_open()){
        cout<<"could not open the file "<<filename<<"\n";
        exit(0);

    }
    write_ppm(fs,img);
    fs.close();

}
void write_ppm(ofstream &fs,Img img){
    int width = img.getWidth();
    int height = img.getHeight();
    fs<<"P6\n";
    fs<<width<<" ";
    fs<<height<<"\n";
    fs<<"255\n";
    int spaces =0;
    unsigned char * ptr = img.getData();
    fs<<ptr+1<<'\0';
    
    fs.close();
}