#include <iostream>
#include <string>
#include <array>

#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>

#include "utils.hpp"

#define ONCE 0

void example(const cv::UMat& image)
{
    cv::namedWindow("in", cv::WINDOW_AUTOSIZE);
    
    cv::imshow("in", image);

    cv::UMat out;
    image.copyTo(out);
#if   ONCE == 1
    cv::GaussianBlur(image, out, cv::Size(5, 5), 2, 0);
    cv::imshow("out", out);
#else
    const size_t frames_count = 500;
    std::array<cv::UMat, frames_count> frames;

    for (cv::UMat& frame : frames)
    {
        cv::GaussianBlur(out, frame, cv::Size(5, 5), 3, 3);
        std::cout << "gaussian bloom processing" << std::endl;
        frame.copyTo(out);
    }
    std::cout << "gaussian bloom processing done" << std::endl;
    cv::namedWindow("out", cv::WINDOW_AUTOSIZE);
    for (cv::UMat& frame : frames)
    {
        cv::Mat single_frame = frame.getMat(cv::AccessFlag::ACCESS_READ);
        cv::imshow("out", single_frame);
        //std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
#endif

    cv::waitKey(0);
}

int main(int argc, char** argv)
{
    if (!fucking::setGPU()) return -1;
    std::string img_name = argv[1];
    cv::UMat in = cv::imread(img_name, -1).getUMat(cv::ACCESS_RW, cv::USAGE_DEFAULT);

    example(in);

    return 0;
}
