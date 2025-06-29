#include <opencv2/opencv.hpp>
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

int main() {
    cv::VideoCapture cap(0); // Open the default camera (0)
    if (!cap.isOpened()) {
        cerr << "Error: Could not open camera." << endl;
        return -1;
    }

    cout << "Camera opened successfully" << endl;

    cv::Mat frame;
    while (true) {
        cap >> frame; // Capture a new frame
        if (frame.empty()){
            cerr << "Error: Could not read frame." << endl;
        }

        cv::imshow("Camera", frame); // Display the frame

        if (cv::waitKey(1) == 27) break; // Exit on 'ESC' key
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
