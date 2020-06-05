#include "gtk_screen.h"
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <types.h>
#include <iostream>
using namespace std;
using namespace img_proc;

void  img_proc::imshow(Img img){
    gtk_init (NULL, NULL);

    unsigned char * data =img.getData();
    int width = img.getWidth();
    int height = img.getHeight();
  
    GError *error =NULL;
    GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("lena_p3_copy_.ppm",&error);//gdk_pixbuf_new_from_data(data,  GdkColorspace(0),false,8,width,height,width*3,NULL,NULL);
    if(pixbuf == NULL){
        cout<<"dammit\n";
        fprintf(stderr, "Loading image 2 failed with error %s\n", error->message);    
    }
    GtkWidget * gtk_img =  gtk_image_new_from_pixbuf( pixbuf);
    gtk_container_add (GTK_CONTAINER (window), gtk_img);

    gtk_widget_show_all (GTK_WIDGET (window));

}
void img_proc::waitKey(){
    gtk_main ();
}