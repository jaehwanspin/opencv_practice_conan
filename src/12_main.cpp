#include <iostream>
#include <string>

#include <opencv2/core/mat.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char** argv)
{
	std::string img_filename = argv[1];
	cv::Mat img = cv::imread(img_filename);
	cv::circle(img, cv::Point(50, 50), 50, cv::Scalar(0, 0, 0), 3, cv::LineTypes::LINE_AA);

	cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
	cv::imshow("image", img);
	cv::waitKey(0);

	return 0;
}