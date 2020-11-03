#include <iostream>
#include <string>
#include <opencv2/core/hal/interface.h>
#include <opencv2/imgcodecs.hpp>

// void
// grayscale_threshold ()
// {
//     std::cout << "Thresholding mandrill.jpeg (grayscale)" << std::endl;
//
//     // read the source image from file (as grayscale)
//     cv::Mat image = cv::imread("mandrill.jpeg", cv::IMREAD_GRAYSCALE);
//
//     uchar thr = 128;
//
//     // Threshold by looping through all the pixels
//     for (int y = 0; y < image.rows; y++)
//         for (int x = 0; x < image.cols; x++)
//             image.at<uchar>(y,x) = image.at<uchar>(y, x) > thr ? 255 : 0;
//
//     // save the image
//     cv::imwrite("thr_mandrill.jpeg", image);
//
//     std::cout << "saving output at: thr_mandrill.jpeg" << std::endl;
//
//     // free memory
//     image.release();
// }
//
// #define px(y,x) image.at<cv::Vec3b>(y,x)
//
// void
// rgb_threshold ()
// {
//     std::cout << "Thresholding mandrill.jpeg (colour)" << std::endl;
//
//     cv::Mat image = imread("mandrillRGB.jpeg", cv::IMREAD_COLOR);
//
//     uchar thr = 200;
//
//     for (int y = 0; y < image.rows; y++)
//         for (int x = 0; x < image.cols; x++)
//             px(y,x) = px(y,x)[0] > thr ? px(y,x).all(255) : px(y,x).all(0);
//
//     // save the image
//     cv::imwrite("rgb_mandrill.jpeg", image);
//
//     std::cout << "saving output at: rgb_mandrill.jpeg" << std::endl;
//
//     // free memory
//     image.release();
// }

#define px(y,x) image->at<cv::Vec3b>(y,x)

void
mandrill_one (cv::Mat *image)
{
    for (int y = 0; y < image->rows; y++) {
        for (int x = 0; x < image->cols; x++) {
            cv::Vec3b pixel = image->at<cv::Vec3b>(y, x);
            px(y,x)[0] = pixel[2];
            px(y,x)[1] = pixel[0];
            px(y,x)[2] = pixel[1];
        }
    }
}

void
mandrill_two (cv::Mat *image)
{
  
    int redChannelOffset = 32;
    // Copy image
    cv::Mat newImage;
    image->copyTo(newImage); // BGR

    for (int y = 0; y < image->rows; y++) {
        for (int x = 0; x < image->cols; x++) {
            px(y,x)[2] = newImage.at<cv::Vec3b>((y-redChannelOffset + image->rows) %image->rows, (x-redChannelOffset + image->cols)%image->cols)[2];
        }
    }
}


void
mandrill_three (cv::Mat *image)
{
  
    int redChannelOffset = 32;
    // Copy image
    cv::Mat newImage;
    image->copyTo(newImage); // BGR

    for (int y = 0; y < image->rows; y++) {
        for (int x = 0; x < image->cols; x++) {
            px(y,x)[2] = newImage.at<cv::Vec3b>((y-redChannelOffset + image->rows) %image->rows, (x-redChannelOffset + image->cols)%image->cols)[2];
        }
    }
}

int
main (int argc, char **argv)
{
    if (argc == 1) {
        std::cout << "please provide an argument" << std::endl;
        return (1);
    }

    cv::Mat image;

    std::string arg = std::string(argv[1]);
    if (arg == std::string("1")) {
        image = imread("mandrill0.jpeg", cv::IMREAD_COLOR);
        mandrill_one(&image);
        cv::imwrite("mandrill0_recovered.jpeg", image);
    } else if (arg == std::string("2")) {
        image = imread("mandrill1.jpeg", cv::IMREAD_COLOR);
        mandrill_two(&image);
        cv::imwrite("mandrill1_recovered.jpeg", image);
    }

    // free memory
    image.release();

    return 0;
}


















