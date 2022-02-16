#include <opencv2/opencv.hpp>
#include <ctime>

int main() {

	// Drawing source image

	cv::Mat img(180, 768, CV_8UC1);
	img = 0;
	cv::Rect2d rc = {0, 0, 768, 60 };
	
	cv::Rect rc1 = { 0, 0, 3, 180 };
	for (int i = 0; i < 768; i += 3) {
		  cv::rectangle(img, rc1, { i / 3.0 }, -1);
		  rc1.x += rc1.width;
	}
	cv::rectangle(img, rc, {250}, 1);
	rc.y += rc.height;
	


	// Gammacorrection with pow

	unsigned int start = clock();
	
	cv::Mat task1{img};
	task1.convertTo(task1, CV_32FC1, 1.0f / 255.0f);
	cv::pow(task1, 2.2, task1);
	task1.convertTo(task1, CV_8UC1, 255.0f);
	task1(rc).copyTo(img(rc));

	unsigned int finish = clock();
	unsigned int total = finish - start;
	std::cout << "Time consumed for standart pow: " << total << " ms." << std::endl;

	cv::rectangle(img, rc, {250}, 1);
	rc.y += rc.height;


	// Gammacorrection by pixel

	start = clock();

	for (int y = rc.y; y < 180; y++){
		for (int x = 0; x < 768; x++){
			img.at<uint8_t>(y, x) = pow(img.at<uint8_t>(y, x) / 255.0f, 2.4) * 255.0f;
		}
	}

	finish = clock();
	total = finish - start;
	std::cout << "Time consumed for every pixel: " << total << " ms." << std::endl;

	cv::rectangle(img, rc, {250}, 1);

	cv::imwrite("lab01.png", img);
	cv::imshow("lab01", img);
	
	cv::waitKey(0);
	cv::destroyAllWindows();
	
	return 0;
}
