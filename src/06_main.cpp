#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>


int main(int argc, char** argv)
{
    std::cout << "program starts" << std::endl;
    cv::Mat lena = cv::imread(argv[1], cv::IMREAD_COLOR);

    // create a matrix for split
    cv::Mat bgr[3];

    // split image into 3 single-channel matrices
    cv::split(lena, bgr);

    // create 4 windows
    cv::namedWindow("Original Image");
    cv::namedWindow("Red Channel");
    cv::namedWindow("Green Channel");
    cv::namedWindow("Blue Channel");

    // show 4 windows
    cv::imshow("Original Image", lena);
    cv::imshow("Red Channel", bgr[2]);  // caution : the red channel index is 2!
    cv::imshow("Green Channel", bgr[1]);
    cv::imshow("Blue Channel", bgr[0]);

    cv::waitKey(0);
    return 0;
}
