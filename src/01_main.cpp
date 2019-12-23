#include <iostream>
#include <string>

#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>

int main(int argc, char** argv)
{
    std::cout << "5252" << std::endl;

    std::string img_name = argv[1];
    cv::Mat img = cv::imread(img_name.c_str(), -1);
    if (img.empty()) return -1;
    std::cout << "image read" << std::endl;
    cv::namedWindow("lena", cv::WINDOW_AUTOSIZE);
    cv::imshow("lena", img);
    cv::waitKey(0);
    cv::destroyWindow("lena");

    return 0;
}