#include <iostream>
#include <string>
#include <sstream>

#include <opencv2/core/core.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>

int main(int argc, char** argv)
{
	cv::useOpenVX();
	cv::ocl::setUseOpenCL(true);

	cv::Mat img1 = cv::Mat::ones(cv::Size(512, 512), CV_8UC3);
	cv::Mat img2(512, 512, CV_8UC3, cv::Scalar(1, 255, 122));
	cv::Mat img3(512, 512, CV_8UC3, cv::Scalar(1, 255, 122));
	
	cv::rectangle(img1, cv::Point(100, 100), cv::Point(400, 400),
		cv::Scalar(0, 255, 0), 2);

	cv::line(img1, cv::Point(0, 0), cv::Point(500, 0), cv::Scalar(255, 0, 0), 5);
	cv::line(img1, cv::Point(0, 0), cv::Point(0, 500), cv::Scalar(255, 0, 0), 5);

	cv::circle(img2, cv::Point(256, 256), 50, cv::Scalar(0, 255, 255), 5);
	cv::circle(img2, cv::Point(128, 128), 50, cv::Scalar(0, 0, 0), 5);

	cv::ellipse(img3, cv::Point(256, 256), cv::Size(200, 200), 30.0, 15.0, -30.0, cv::Scalar(0, 255, 255), 10);

	cv::imshow("img", img1);
	cv::imshow("img2", img2);
	cv::imshow("img3", img3);
	

	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}