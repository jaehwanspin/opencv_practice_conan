#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(size_t argc, char** argv)
{
	cv::setUseOptimized(true);
	cv::setUseOpenVX(true);
	cv::ocl::setUseOpenCL(true);

	return 0;
}