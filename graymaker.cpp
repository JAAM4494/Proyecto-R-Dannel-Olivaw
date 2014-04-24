#include "graymaker.h"

void grayMaker::img_a_matriz(IplImage * img)
{
    //printf("entre a img_a_matriz\n");
    CvMat *mat = cvCreateMat(img->height,img->width,CV_32FC3 );
    cvConvert(img,mat);
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<11;j++)
        {
            CvScalar scal = cvGet2D( mat,j,i);
            printf( "(%.f,%.f,%.f)  ",scal.val[0], scal.val[1], scal.val[2] );
        }
        printf("\n");
    }
    int depth = img->depth;
    printf("%d", depth);
}

int grayMaker::estandarizar_colores(int color_inicial)
{  //42-127-213
    //printf("entre a estandarizar_colores\n");
    int color_final;
    if (color_inicial < 42)
        color_final=0;
    else if(color_inicial < 127)
        color_final=85;
    else if(color_inicial < 213)
        color_final=170;
    else
        color_final=255;
    return color_final;
}

int grayMaker::maximumValue (int array[])
{
    //printf("entre a maximumValue\n");
    int max = array[0];
    int i;
    int max_indice=0;

    for(i = 0; i<16; i++)
    {
        if(array[i] >= max)
        {
            max = array[i];
            max_indice=i;
        }
    }
    return max_indice;
}

int grayMaker::primer_indice(int color)
{
    //printf("entre a primer_indice\n");
    if(color==0)
        return 0;
    else if(color==85)
        return 4;
    else if(color==170)
        return 8;
    else
        return 12;
}

int grayMaker::segundo_indice(int color)
{
    //printf("entre a segundo_indice\n");
    if((color==0) || (color == 85))
        return 0;
    else
        return 2;
}

int grayMaker::final_indice(int color)
{
    //printf("entre a final_indice\n");
    /*
    if((color==0) || (color == 85))
        return 0;
    else
        return 1;
    */
    return !((color==0) || (color == 85));
}

void grayMaker::pinta_sector(IplImage * img, CvRect sector)
{
    //printf("entre a pinta_sector\n");
    int i,j,cont,filas,colum,indice_max,indice;
    int colorRGB[3];// [R,G,B]
    int lista_colores[4][16];
    int lista_conts[16];

    for (filas=0; filas < 4; filas++)
    {
        for (colum=0; colum < 16; colum++)
        {
            lista_colores[filas][colum] = 0;
        }
    }
    for (i = sector.y; i < (sector.y + sector.height); i++)
    {
        for (j = sector.x; j < (sector.x + sector.width); j++)
        {
            indice=0;
            colorRGB[0] = ((uchar*)(img->imageData + i * img->widthStep))[j*3+2];//red
            indice=primer_indice(colorRGB[0]);
            colorRGB[1] = ((uchar*)(img->imageData + i * img->widthStep))[j*3+1];//green
            indice=indice+segundo_indice(colorRGB[1]);
            colorRGB[2] = ((uchar*)(img->imageData + i * img->widthStep))[j*3];//blue
            indice=indice+final_indice(colorRGB[2]);

            if(lista_colores[3][indice]==0)
            {
                lista_colores[0][indice]=colorRGB[0];
                lista_colores[1][indice]=colorRGB[1];
                lista_colores[2][indice]=colorRGB[2];
                lista_colores[3][indice]=1;
            }
            else
                lista_colores[3][indice]=lista_colores[3][indice]+1;
        }
    }
    for (cont=0; cont < 16; cont++)
    {
        lista_conts[cont]=lista_colores[3][cont];
    }
    indice_max=maximumValue(lista_conts);
    for (i = sector.y; i < (sector.y + sector.height); i++)
    {
        for (j = sector.x; j < (sector.x + sector.width); j++)
        {
            ((uchar*)(img->imageData + i * img->widthStep))[j*3] = (lista_colores[2][indice_max]+lista_colores[1][indice_max]+lista_colores[0][indice_max])/3;//blue
            ((uchar*)(img->imageData + i * img->widthStep))[j*3+1] = (lista_colores[2][indice_max]+lista_colores[1][indice_max]+lista_colores[0][indice_max])/3;//green
            ((uchar*)(img->imageData + i * img->widthStep))[j*3+2] = (lista_colores[2][indice_max]+lista_colores[1][indice_max]+lista_colores[0][indice_max])/3;//red

        }

    }
}

void grayMaker::estandariza_imagen(IplImage * img, CvRect sector)
{
    //printf("entre a estandariza_imagen\n");
    int i,j,color_r,color_g,color_b;
    for (i = sector.y; i < (sector.y + sector.height); i++)
    {
        for (j = sector.x; j < (sector.x + sector.width); j++)
        {
            color_b = estandarizar_colores(((uchar*)(img->imageData + i * img->widthStep))[j*3]);
            color_g = estandarizar_colores(((uchar*)(img->imageData + i * img->widthStep))[j*3+1]);
            color_r = estandarizar_colores(((uchar*)(img->imageData + i * img->widthStep))[j*3+2]);
            ((uchar*)(img->imageData + i * img->widthStep))[j*3] = color_b;//blue
            ((uchar*)(img->imageData + i * img->widthStep))[j*3+1] = color_g;//green
            ((uchar*)(img->imageData + i * img->widthStep))[j*3+2] = color_r;//red
        }
    }
}
