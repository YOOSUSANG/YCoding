// OpenCvYSS.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include "PSNR.h"
using namespace cv;
using namespace std;
Mat bound1, boundary,b2; //mat선언
Mat se = getStructuringElement(MORPH_CROSS, Size(3, 3), Point(1, 1));//3 by 3 cross 생성
int ok = 0;
void CallBackFunc(int event, int x, int y, int flags, void* userdata) {
	if (event == EVENT_LBUTTONDOWN) {
		cout << x << "," << y << endl;
		b2.at<uchar>(y, x) = 255; //시작점
		ok = 1;

	}
}
int main() {
	REPORT_DATA stats;
	Mat Org = imread("C:/Users/yoosusang/final/Profile.png", 0); //흑백을 출력하기 
	int key;
	b2 = Mat::zeros(Org.rows, Org.cols, 0);
	erode(Org, bound1, se); //우선 erode하기
	boundary = Org - bound1;// 원본에서 뺴주기 경계면 형성
	Mat bc = 255 - boundary; //경게면이 아닌 곳
	while (1) {
		imshow("pro3", boundary);
		setMouseCallback("pro3", CallBackFunc, NULL); //boundary에 마우스 클릭 설정
		if (ok == 1) {//마우스를 클릭하면 시작
			dilate(b2,b2, se); // 시작점을 se와 dilate
			b2 = b2 & bc;//boundary 여집합인 bc와 교집합
			boundary = boundary | b2; // boundary에 추가하기 위한 합집합
		}
		key = waitKey(5);
		if (key == 27)
			break;

	}
}
