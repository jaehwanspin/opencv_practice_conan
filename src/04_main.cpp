#include <iostream>
#include <string>

#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core/ocl.hpp>

void example(const cv::UMat& image)
{
    cv::namedWindow("in", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("out", cv::WINDOW_AUTOSIZE);

    cv::imshow("in", image);

    cv::UMat out;
    cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);
    for (int i = 0; i < 1000; i++)
        cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);

    cv::imshow("out", out);
    cv::waitKey(0);
}

int main(int argc, char** argv)
{
    cv::ocl::setUseOpenCL(true);
    
    std::string img_name = argv[1];
    cv::UMat in = cv::imread(img_name, -1).getUMat(cv::ACCESS_RW, cv::USAGE_DEFAULT);

    example(in);

    return 0;
}