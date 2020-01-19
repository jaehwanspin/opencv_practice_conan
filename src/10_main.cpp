#include <iostream>
#include <string>
#include <array>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main(int argc, char** argv)
{
	const std::string video_filename = argv[1];

	cv::namedWindow("katya", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("log_polar", cv::WINDOW_AUTOSIZE);

	cv::VideoCapture video_capture(video_filename);

	double fps = video_capture.get(cv::CAP_PROP_FPS);
	cv::Size size(
		(int)video_capture.get(cv::CAP_PROP_FRAME_WIDTH),
		(int)video_capture.get(cv::CAP_PROP_FRAME_HEIGHT)
	);

	cv::VideoWriter video_writer;

	video_writer.open("10_out.mp4", cv::VideoWriter::fourcc('X', '2', '6', '4'),
		fps, size);

	cv::Mat logpolar_frame, bgr_frame;

	while (true)
	{
		video_capture >> bgr_frame;

		if (bgr_frame.empty()) break;

		cv::imshow("katya", bgr_frame);

		cv::logPolar(bgr_frame, logpolar_frame,
			cv::Point2f(
				bgr_frame.cols / 2,
				bgr_frame.rows / 2
			),
			80, cv::WARP_FILL_OUTLIERS
		);

		cv::imshow("log_polar", logpolar_frame);
		video_writer << logpolar_frame;

		char c = cv::waitKey(10);
		if (c == 27) break;
	}

	video_capture.release();
	video_writer.release();

	return 0;
}