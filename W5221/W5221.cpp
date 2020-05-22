#include <iostream>  
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int bgSub_demo()
{
	VideoCapture capVideo(0);
	if (!capVideo.isOpened()) {
		std::cout << "Unable to open video!" << std::endl;
		return -1;
	}
	int cnt = 0;
	Mat frame;
	Mat bgMat;
	Mat subMat;
	Mat bny_subMat;
	Mat bgModelMat;

	while (1) {
		capVideo >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);
		if (cnt == 0) {
			frame.copyTo(bgMat);
		}
		else {
			absdiff(frame, bgMat, subMat);
			threshold(subMat, bny_subMat, 20, 255, CV_THRESH_BINARY);
			imshow("b_subMat", bny_subMat);
			imshow("frame", frame);
			waitKey(30);
		}
		cnt++;

	}
	return 0;
}



int main()
{
	double start = static_cast<double>(cvGetTickCount());
	bgSub_demo();
	double time = ((double)cvGetTickCount() - start) / cvGetTickFrequency();
	cout << "processing time:" << time / 1000 << "ms" << endl;
	system("pause");
	return 0;
}