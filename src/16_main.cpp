#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char** argv)
{
	cv::Vec2f vec1 = {3, 4};
	cv::Vec2f vec2 = {4, 5};
	cv::Vec2f vec3 = vec2 - vec1;
	cv::Vec2f vec4;
	cv::Matx22f mat1 = {1, 2, 3, 4};
	// cv::Vec2f vec5;

	cv::multiply(vec1, vec2, vec4);
	// cv::multiply(vec1, mat1, vec5);
	
	// double dotdot = vec1.dot(vec2);
	// std::printf("%f\n", dotdot);
	std::cout << vec3 << std::endl;
	std::cout << vec4 << std::endl;
	// std::cout << vec5 << std::endl;

	return 0;
}