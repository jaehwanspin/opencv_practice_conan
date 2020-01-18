#include <iostream>
#include <fstream>
#include <thread>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

int g_slider_position = 0;

int g_run = 1;
int g_dont_set = 0;

cv::VideoCapture g_video_capture;

void on_trackbar_slide(int pos, void*)
{
    if (!g_dont_set)
    {
        g_run = 1;
        g_video_capture.set(cv::CAP_PROP_POS_FRAMES, pos);
    }
    g_dont_set = 0;
}

int main(int argc, char** argv)
{
    std::string video_name = std::string(argv[1]);
    cv::namedWindow("lena", cv::WINDOW_AUTOSIZE);
    g_video_capture.open(video_name);

    int frames = (int)g_video_capture.get(cv::CAP_PROP_FRAME_COUNT);
    int temp_w = (int)g_video_capture.get(cv::CAP_PROP_FRAME_WIDTH);
    int temp_h = (int)g_video_capture.get(cv::CAP_PROP_FRAME_HEIGHT);

    std::cout << "video has " << frames << " frames of dimensions("
              << temp_w << ", " << temp_h << ")." << std::endl;

    cv::createTrackbar("position", "lena", &g_slider_position, frames, on_trackbar_slide);

    cv::Mat frame;

    while (true)
    {
        if (g_run != 0)
        {
            g_video_capture >> frame;
            if (frame.empty()) break;
            int current_pos = (int)g_video_capture.get(cv::CAP_PROP_POS_FRAMES);
            g_dont_set = 1;

            cv::setTrackbarPos("position", "lena", current_pos);
            cv::imshow("lena", frame);

            g_run = 1;
        }

        char c = (char)cv::waitKey(10);
        if (c == 's')
        {
            g_run = 1;
            std::cout << "single step, run = " << g_run << std::endl;
        }
        if (c == 'r')
        {
            g_run = -1;
            std::cout << "run mode, run = " << g_run << std::endl;
        }
        if (c == 27)
        {
            break;            
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
