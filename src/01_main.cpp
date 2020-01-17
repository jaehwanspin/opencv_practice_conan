#include <iostream>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <opencv2/core/ocl.hpp>

int main(int argc, char** argv)
{
    cv::ocl::setUseOpenCL(true);
    std::cout << "fucking hell" << std::endl;

    std::string img_name = argv[1];
    cv::UMat img = cv::imread(img_name.c_str(), -1).getUMat(cv::ACCESS_RW, cv::USAGE_DEFAULT);
    if (img.empty()) return -1;
    std::cout << "image read" << std::endl;
    cv::namedWindow("lena", cv::WINDOW_AUTOSIZE);
    cv::imshow("lena", img);
    cv::waitKey(0);
    cv::destroyWindow("lena");

    return 0;
}
