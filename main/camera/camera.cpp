#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::VideoCapture cap(0); // Open the default camera (0)
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera." << std::endl;
        return -1;
    }

    std::cout << "Camera opened successfully" << std::endl;

    cv::Mat frame;
    while (true) {
        cap >> frame; // Capture a new frame
        if (frame.empty()) break;

        cv::imshow("Camera", frame); // Display the frame

        if (cv::waitKey(1) == 27) break; // Exit on 'ESC' key
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
