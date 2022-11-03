// OpenCvYSS.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
using namespace cv;
using namespace std;
void myMedianFilter(InputArray input, OutputArray output, int windowSize) {
	const Mat& img = input.getMat();// img참조 InputArray>Mat
	int len = (windowSize - 1) / 2;//상하좌우 범위 설정 windosSize가 3이면 픽셀기준으로 -1~1까지만 볼 수 있음(픽셀은 가운데값이라고 생각)
	output.create(img.size(), img.type());//output을 입력크기만큼 만들어주고
	Mat dst = output.getMat();//아웃풋에서 Mat 꺼내오기
	for (int i = 0; i < img.rows; i++) { //모든 픽셀들을 돌아서 midian 계산
		for (int j = 0; j < img.cols; j++) {//마찬가지로
			vector<uchar> vec; //입력 영상의 해당 픽셀 및 주변의 범위 값들을 넣어주기 위한 것
			for (int y = -len; y <=len; y++) {// 자신을 기준으로 주변값 계산 ( 상 하 )
				for (int x = -len; x <= len; x++) {//자신을 기준으로  주변값 계산( 좌 우 )  
					vec.push_back(img.at<uchar>(min(img.rows - 1, max(0, i + y)), min(img.cols - 1, max(0, j + x)))); //필터링
				}
			}
			sort(vec.begin(), vec.end());//오름차순 정렬
			dst.at<uchar>(i, j) = vec[vec.size() / 2];//구한 중간값을 픽셀에 넣기.
		}
	}
}
int main() {
	Mat image = imread("C:/Users/yoosusang/image/MedianFilterInput.png",0); //흑백을 출력하기 위한 0
	Mat out;
	myMedianFilter(image, out, 5);
	imshow("Medianresult", out);//결과 출력
	waitKey();
}
