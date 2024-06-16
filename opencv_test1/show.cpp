#include "show.h"

void show(cv::Mat image,int color)
{
    cv::Mat outimage;
    cv::cvtColor(image,outimage,color);
    if (image.empty())
    {
        std::cout<<"error\n";
    }
    else
    {
    cv::namedWindow("image",cv::WINDOW_NORMAL);
    cv::imshow("image",outimage);
    cv::waitKey(0);
    }
}