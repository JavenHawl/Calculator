#include <opencv2/opencv.hpp>
#include "NHWC_to_NCHW.h"


int img_prerpocess(cv::Mat input_image, float *out_data,int img_h, int img_w) 
{
	int image_area = input_image.cols * input_image.rows;
	unsigned char* pimage = input_image.data;
	// / 将 HWC 转为 CHW/
	float *hw_r = out_data + image_area * 0;
	float *hw_g = out_data + image_area * 1;
	float *hw_b = out_data + image_area * 2;
	//BGR -> RGB ///
	for(int i = 0; i < image_area; ++i, pimage += 3)
    {
	    *hw_r++ = pimage[2] / 255.0f;
	    *hw_g++ = pimage[1] / 255.0f;
	    *hw_b++ = pimage[0] / 255.0f;
	}
	
	return 0;

}

