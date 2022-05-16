#include <opencv2/opencv.hpp>
#include <ctime>

int main() {

	// Drawing source image

	cv::Mat img(450, 300, CV_8UC1);
	for (int i = 0; i < 150; i++)
	{
		for (int j = 0; j < 150; j++)
		{
			img.at<uint8_t>(j, i) = 0;
			img.at<uint8_t>(j, i+150) = 127;
			img.at<uint8_t>(j+150, i) = 255;
			img.at<uint8_t>(j+300, i) = 127;
			img.at<uint8_t>(j+150, i+150) = 0;
			img.at<uint8_t>(j+300, i+150) = 255;
		}
		
	}
	cv::circle(img, cv::Point(75, 75), 50, 255, cv::FILLED);
	cv::circle(img, cv::Point(75+150, 75), 50, 0, cv::FILLED);
	cv::circle(img, cv::Point(75, 75+150), 50, 127, cv::FILLED);
	cv::circle(img, cv::Point(75+150, 75+150), 50, 127, cv::FILLED);
	cv::circle(img, cv::Point(75, 75+300), 50, 255, cv::FILLED);
	cv::circle(img, cv::Point(75+150, 75+300), 50, 0, cv::FILLED);

	cv::imwrite("K.png", img);
	cv::imshow("K", img);

	//I1

	cv::Mat kernel_f = (cv::Mat_<int>(2, 2) << 1, 0, 0, -1);
	cv::Mat I1;
	cv::filter2D(img, I1, -1, kernel_f, {-1, -1}, 0.0);
	cv::imwrite("I1.png", I1);
	cv::imshow("I1", I1);

	//I2

	cv::Mat kernel_s = (cv::Mat_<int>(2, 2) << 0, 1, -1, 0);
	cv::Mat I2;
	cv::filter2D(img, I2, -1, kernel_s, {-1, -1}, 0.0);
	cv::imwrite("I2.png", I2);
	cv::imshow("I2", I2);

	//Mean geometry

	cv::Mat gm(img);
	for(int i = 0; i < img.rows; i++){
		for(int j = 0; j < img.cols; j++){
			gm.at<uchar>(i, j) = sqrt(I1.at<uchar>(i, j) * I2.at<uchar>(i, j));
		}
	}
	cv::imwrite("gm.png", gm);
	cv::imshow("gm", gm);
	
	cv::waitKey(0);
	
	return 0;
}