#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main() {
  cv::Mat image(256, 256, CV_8UC1, cv::Scalar(0));

  putText(image, "HelloOpenCV!", cv::Point(70, 70),
		cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, cv::Scalar(255), 1, cv::LINE_AA);
  
  imwrite("myimage.jpg", image);
  
  namedWindow("Display window", cv::WINDOW_AUTOSIZE);
  imshow("Display window", image);
  cv::waitKey(0);
  image.release();
}
