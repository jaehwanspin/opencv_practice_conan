#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char** argv)
{
	cv::setUseOptimized(true);
	// cv::setUseOpenVX(true);
	cv::ocl::setUseOpenCL(true);

	std::cout << "ah" << std::endl;

	std::string filename = argv[1];

	cv::VideoCapture video_capture(filename);
	
	cv::UMat edges;

	while (true)
	{
		cv::UMat frame;
		video_capture >> frame;
		if (frame.empty()) break;
		cv::cvtColor(frame, edges, cv::COLOR_BGR2GRAY);

		cv::GaussianBlur(edges, edges, cv::Size(7, 7), 1.5, 1.5);
		cv::Canny(edges, edges, 0, 30, 3);

		cv::imshow("edges", edges);

		if (cv::waitKey(30) >= 0)
			break;
	}

	cv::destroyAllWindows();

	return 0;
}