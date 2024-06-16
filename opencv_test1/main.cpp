#include <opencv2/opencv.hpp>
#include <opencv2/core/utils/logger.hpp>
#include <iostream>
#include "show.h"
#include "NHWC_to_NCHW.h"

using namespace cv;
using namespace std;


int main()
{
    Mat image = imread("/home/javenhawl/images/mm.jpeg",1);

    show(image,0);  //0原图

    Mat imgs[3];
    split(image,imgs);  //通道分离

    show(imgs[0],0);    //B
    show(imgs[1],0);    //G
    show(imgs[2],0);    //R

    Mat t=imgs[0];
    imgs[0]=imgs[2];
    imgs[2]=t;

    /*Mat image_RGB;
    cvtColor(image,image_RGB,COLOR_BGR2RGB);
    Mat image_chw;
    image_RGB.convertTo(image_chw,CV_32FC3,1.0f/255.0);

    vector<Mat> input_channels(3);
    split(image_chw,input_channels);

    vector<float> result(image.rows*image.cols*3);
    auto data = result.data();
    int channelLength=image.rows*image.cols;
    for (int i=0;i<3;++i)
    {
        memcpy(data,input_channels[i].data,channelLength*sizeof(float));
        data+= channelLength;
    }*///法一（不懂）查vector,memcpy

    Mat blob_image;
    blob_image=dnn::blobFromImage(image,1.0/255.0,image.size(),true,false,CV_32F);
    imwrite("NCHW_mm.jpeg",blob_image);

    return 0;
}