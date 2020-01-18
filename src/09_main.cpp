#include <iostream>
#include <thread>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

int main(int argc, char** argv)
{
    srand(time(nullptr));
    // if (!set_opencl()) return -1;
    cv::ocl::setUseOpenCL(true);
    std::string video_path = argv[1];
    std::cout << video_path << std::endl;
    cv::namedWindow("lena", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture video_capture;
    cv::VideoWriter video_writer;
    if (!video_capture.open(video_path.c_str(), cv::VideoCaptureAPIs::CAP_IMAGES))
        std::cout << "fuck" << std::endl;
    // video_capture.set(cv::CAP_PROP_FPS, 60.0);
    int video_capture_width = video_capture.get(3);
    int video_capture_height = video_capture.get(4);
    video_writer.open(std::string("./out.avi"), cv::VideoWriter::fourcc('M', 'J', 'P', 'G'),
        15, cv::Size(video_capture_width, video_capture_height));
    video_writer.set(cv::VIDEOWRITER_PROP_QUALITY, 100);
    double blur_size = 5.0;
    double sig_x = 3.0;
    double sig_y = 3.0;

    cv::UMat frame;

    std::array<int, 6> color_options = {
        cv::COLOR_RGB2BGRA,
        cv::COLOR_RGB2GRAY,
        cv::COLOR_RGB2HSV,
        cv::COLOR_RGB2Lab,
        cv::COLOR_RGB2RGBA,
        cv::COLOR_RGB2YCrCb
    };

    bool threshold = false;
    bool rotation = false;
    int color_options_index = 0;
    int frame_index = 0;

    while (true)
    {
        threshold = rand() % 2;
        rotation = (bool)rand() * threshold;
        color_options_index = rand() % color_options.size();
        video_capture >> frame;
        if (frame.empty()) break;
        blur_size = blur_size + 2;
        std::cout << video_capture.get(cv::CAP_PROP_FORMAT) << std::endl;
        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;
        cv::putText(frame, std::string("Katya Zaicheva"), cv::Point(20, 30), cv::FONT_HERSHEY_DUPLEX, 0.7, cv::Scalar(r, g, b), 3);

        // sig_x = sig_x + 0.3;
        // sig_y = sig_y + 0.3;
        // cv::GaussianBlur(frame, frame, cv::Size(blur_size, blur_size), sig_x, sig_y);
        cv::cvtColor(frame, frame, color_options[color_options_index]);
        if (threshold)
        {
            // std::cout << "threshold : " << frame_index << std::endl;
            cv::threshold(frame, frame, 100, 200, cv::THRESH_BINARY);
        }
        if (rotation)
        {
            // std::cout << "rotation : " << frame_index << std::endl;
        }
        // cv::cvtColor(frame, frame, cv::COLOR_Lab2RGB);
        video_writer.write(frame);
        cv::imshow("lena", frame);

        // std::this_thread::sleep_for(std::chrono::milliseconds(500));
        // if (++color_options_index == color_options.size())
        //     color_options_index = 0;
        frame_index++;
        if (cv::waitKey(33) >= 0) break;
    }
    std::cout << "cap fps : " << video_capture.get(cv::CAP_PROP_FPS) << std::endl;
    video_capture.release();
    video_writer.release();

    return 0;
}
