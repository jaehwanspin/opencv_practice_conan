#include <iostream>
#include <string>
#include <array>

#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>

int main(int argc, char** argv)
{
    std::cout << "program starts" << std::endl;

    std::string img_name = argv[1];

    cv::Mat lena = cv::imread(img_name, cv::IMREAD_COLOR);

    // create a matrix for split
    std::array<cv::Mat, 3> bgr;

    // create a zero matrix
    cv::Mat zFillMatrix = cv::Mat::zeros(lena.size(), CV_8UC1);

    // split image into 3 single-channel matrices
    cv::split(lena, bgr);

    // create 3 channel Color Matrix
    cv::Mat R[] = { zFillMatrix, zFillMatrix, bgr[2] };
    cv::Mat G[] = { zFillMatrix, bgr[1], zFillMatrix };
    cv::Mat B[] = { bgr[0], zFillMatrix, zFillMatrix };
    cv::merge(R, 3, bgr[2]);
    cv::merge(G, 3, bgr[1]);
    cv::merge(B, 3, bgr[0]);

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

    return 0;
}
