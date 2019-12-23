#include <iostream>
#include <string>

#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core/ocl.hpp>

int main(int argc, char** argv)
{
    cv::ocl::setUseOpenCL(true);
    std::string img_name = argv[1];
    cv::UMat img_gpu_1 = cv::imread(img_name, -1)
        .getUMat(cv::AccessFlag::ACCESS_RW, cv::USAGE_DEFAULT);
    cv::UMat img_gpu_2;


    cv::namedWindow("lena1", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("lena2", cv::WINDOW_AUTOSIZE);

    cv::imshow("lena1", img_gpu_1);

    cv::pyrDown(img_gpu_1, img_gpu_2);
    cv::imshow("lena2", img_gpu_2);

    cv::waitKey(0);

    return 0;
}