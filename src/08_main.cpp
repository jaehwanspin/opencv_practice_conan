#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>

int main(int argc, char** argv)
{
    cv::ocl::setUseOpenCL(true);

    std::string video_path = argv[1];
    std::cout << video_path << std::endl;
    cv::namedWindow("katya", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture video_capture;
    if (!video_capture.open(video_path.c_str()))
        std::cout << "fuck" << std::endl;;

    double sigma_x, sigma_y;
    sigma_x = 1.0;
    sigma_y = 1.0;
    cv::UMat frame;
    while (true)
    {
        video_capture >> frame;
        if (frame.empty()) break;

        sigma_x = sigma_x + 0.4;
        sigma_y = sigma_y + 0.4;

        cv::GaussianBlur(frame, frame, cv::Size(5, 5),
            sigma_x, sigma_y);

        cv::imshow("katya", frame);
        if (cv::waitKey(33) >= 0) break;
    }

    return 0;


	return 0;
}
