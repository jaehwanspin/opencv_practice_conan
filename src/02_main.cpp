#include <iostream>

#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>

int main(int argc, char** argv)
{
    std::string video_path = argv[1];
    std::cout << video_path << std::endl;
    cv::namedWindow("lena", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture video_capture;
    if (!video_capture.open(video_path.c_str()))
        std::cout << "fuck" << std::endl;;

    cv::Mat frame;
    while (true)
    {
        video_capture >> frame;
        if (frame.empty()) break;
        cv::imshow("lena", frame);
        if (cv::waitKey(33) >= 0) break;
    }

    return 0;
}