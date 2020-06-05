#include <iostream>
#include "io/input.h"
#include "gtk_screen/gtk_screen.h"
using namespace std;
using namespace img_proc;
int main(int argc, char** argv){
    Img imagem;
    imagem = imread(argv[1]);
    imwrite("copy.ppm",imagem);
    imshow(imagem);
    waitKey();
    return 0;
}
