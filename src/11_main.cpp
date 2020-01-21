#include <opencv2/core/mat.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>


int main(int argc, char** argv)
{
	cv::ocl::setUseOpenCL(true);
	
	cv::Mat matrix_1 = cv::imread(argv[1]);
	cv::Mat matrix_2 = cv::imread(argv[1]);

	cv::Mat matrix_3;

	cv::namedWindow("ah", cv::WINDOW_AUTOSIZE);
	cv::imshow("ah", matrix_1);

	cv::bitwise_and(matrix_1, matrix_2, matrix_3);

	cv::namedWindow("fuck", cv::WINDOW_AUTOSIZE);
	cv::imshow("fuck", matrix_3);

	cv::bitwise_or(matrix_1, matrix_2, matrix_3);

	cv::namedWindow("that", cv::WINDOW_AUTOSIZE);
	cv::imshow("that", matrix_3);

	cv::bitwise_not(matrix_1, matrix_3);

	cv::namedWindow("shit", cv::WINDOW_AUTOSIZE);
	cv::imshow("shit", matrix_3);

	cv::waitKey(0);

	return 0;
}