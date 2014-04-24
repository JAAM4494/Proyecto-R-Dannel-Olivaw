#include "graymaker.h"

int main(int argc, char *argv[])
{
    grayMaker myGraymaker;

    const char nom_imagen[]= "/home/elda/c++/R-Dannel-Olivaw/imagen_color.jpeg";

    float ancho=0, alto=0, divisiones = 75;

    IplImage * img = cvLoadImage( nom_imagen, CV_LOAD_IMAGE_COLOR);

    ancho=img->width/(divisiones*3/2);
    alto=img->height/divisiones;

    CvRect rect0 = cvRect(0, 0, img->width, img->height);

    myGraymaker.estandariza_imagen(img,rect0);

    CvRect rect = cvRect(0, 0, ancho, alto);

    for(int i=0;i<divisiones;i++)
    {
        for(int j=0;j<divisiones*3/2;j++)
        {

            rect.x = j*ancho;
            rect.y = i*alto;
            cvSetImageROI(img, rect);

            myGraymaker.pinta_sector(img,rect);

            cvResetImageROI(img);
        }
    }
    cvNamedWindow("image", 1);
    cvShowImage("image", img);
    cvWaitKey(0);
    cvDestroyAllWindows();
    cvReleaseImage(&img);

    return 0;
}
