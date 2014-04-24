#ifndef GRAYMAKER_H
#define GRAYMAKER_H

#include <opencv/cv.h>
#include <string.h>
#include <stdio.h>
#include <opencv/highgui.h>

class grayMaker
{
private:
    void img_a_matriz(IplImage * img);
    int estandarizar_colores(int color_inicial);
    int maximumValue(int array[]);
    int primer_indice(int color);
    int segundo_indice(int color);
    int final_indice(int color);
public:


    void pinta_sector(IplImage * img, CvRect sector);
    void estandariza_imagen(IplImage * img, CvRect sector);

};

#endif // GRAYMAKER_H
