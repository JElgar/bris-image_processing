#include <iostream>
#include <opencv2/core/hal/interface.h>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"

void
grayscale_threshold ()
{
    std::cout << "Thresholding mandrill.jpg (grayscale)" << std::endl;

    // read the source image from file (as grayscale)
    cv::Mat image = cv::imread("mandrill.jpg", cv::IMREAD_GRAYSCALE);

    uchar thr = 128;

    // Threshold by looping through all the pixels
    for (int y = 0; y < image.rows; y++)
        for (int x = 0; x < image.cols; x++)
            image.at<uchar>(y,x) = image.at<uchar>(y, x) > thr ? 255 : 0;

    // save the image
    cv::imwrite("thr_mandrill.jpeg", image);

    std::cout << "saving output at: thr_mandrill.jpg" << std::endl;

    // free memory
    image.release();
}

#define px(y,x) image.at<cv::Vec3b>(y,x)

void
rgb_threshold ()
{
    std::cout << "Thresholding mandrill.jpg (colour)" << std::endl;

    cv::Mat image = imread("mandrillRGB.jpg", cv::IMREAD_COLOR);

    uchar thr = 200;

    for (int y = 0; y < image.rows; y++)
        for (int x = 0; x < image.cols; x++)
            px(y,x) = px(y,x)[0] > thr ? px(y,x).all(255) : px(y,x).all(0);

    // save the image
    cv::imwrite("rgb_mandrill.jpg", image);

    std::cout << "saving output at: rgb_mandrill.jpg" << std::endl;

    // free memory
    image.release();
}

void 
fixFirst () {
    cv::Mat image = cv::imread("mandrill0.jpg", cv::IMREAD_COLOR);
    for (int y = 0; image.rows; y++) {
        for (int x = 0; x < image.cols; x++) {
          cv::Vec3b pixel = image.at<cv::Vec3b>(y, x);
          px(y,x)[0] = pixel[2];
          px(y,x)[1] = pixel[0];
          px(y,x)[2] = pixel[1];
        }
    }
    image.release();
}

int
main (int argc, char **argv)
{
    //grayscale_threshold ();
    //rgb_threshold ();
    fixFirst();
}
