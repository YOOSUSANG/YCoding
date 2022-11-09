#include<iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
#include <string>
/*
  canny와 HoughCircles을 이용하여 coin counting   
*/
using namespace cv;
using namespace std;
Mat gray0,gray1,gray2,gray3;
vector<Vec3f> circles0, circles1, circles2, circles3;
Mat coin0, coin1, coin2, coin3, coin4, coin5;
Mat circle_image0, circle_image1, circle_image2, circle_image3;
Mat rgray0,rgray1,rgray2,rgray3;
void on_trackbar0(int pos ,void*) {
	int th1 = getTrackbarPos("cannyT1", "img0");
	int th2 = getTrackbarPos("cannyT2", "img0");
	Canny(gray0,rgray0, th1, th2, 3);
	imshow("img0", rgray0);
}
void on_trackbar1(int pos, void*) {
	int th1 = getTrackbarPos("cannyT1", "img1");
	int th2 = getTrackbarPos("cannyT2", "img1");
	Canny(gray1, rgray1, th1, th2, 3);
	imshow("img1", rgray1);
}
void on_trackbar2(int pos, void*) {
	int th1 = getTrackbarPos("cannyT1", "img2");
	int th2 = getTrackbarPos("cannyT2", "img2");
	Canny(gray2, rgray2, th1, th2, 3);
	imshow("img2", rgray2);
}
void on_trackbar3(int pos, void*) {
	int th1 = getTrackbarPos("cannyT1", "img3");
	int th2 = getTrackbarPos("cannyT2", "img3");
	Canny(gray3, rgray3, th1, th2, 3);
	imshow("img3", rgray3);
}
int main() {
	coin0 = imread("C:/Users/유수상/OneDrive - 아주대학교/바탕 화면/ㅎㄱ/3학년 2학기/컴퓨터비전/pro2/coins0.jpg");
	coin1 = imread("C:/Users/유수상/OneDrive - 아주대학교/바탕 화면/ㅎㄱ/3학년 2학기/컴퓨터비전/pro2/coins1.jpg");
	coin2 = imread("C:/Users/유수상/OneDrive - 아주대학교/바탕 화면/ㅎㄱ/3학년 2학기/컴퓨터비전/pro2/coins2.jpg");
	coin3 = imread("C:/Users/유수상/OneDrive - 아주대학교/바탕 화면/ㅎㄱ/3학년 2학기/컴퓨터비전/pro2/coins3.jpg");
	coin4 = imread("C:/Users/유수상/OneDrive - 아주대학교/바탕 화면/ㅎㄱ/3학년 2학기/컴퓨터비전/pro2/coins4.jpg");
	coin5 = imread("C:/Users/유수상/OneDrive - 아주대학교/바탕 화면/ㅎㄱ/3학년 2학기/컴퓨터비전/pro2/coins5.jpg");
	
	circle_image0 = coin3.clone();
	cvtColor(coin3, gray0, COLOR_BGR2GRAY);
	GaussianBlur(gray0, gray0, Size(3, 3),0);
	//threshold1 (낮은 경계), threshold2(높은 경계)
	//threshold1보다 작으면 경계x, threshold2이상이면 강한 엣지
	Canny(gray0,rgray0,51,130, 3);
	 
	/*input, output ,gradient, 1, 감지된 중심사이의 최소거리, 내부 엣지 상한 임계값
	중심을 위한 threshold, 감지할 최소 반경, 감지할 최대 반경*/
	HoughCircles(rgray0, circles0, HOUGH_GRADIENT, 1, 70, 100, 50, 10, 77); 
 	for (size_t i = 0; i < circles0.size(); i++) {
		Vec3i c = circles0[i];
		Point center = Point(c[0], c[1]);
		// draw the circle center
		circle(circle_image0, center, 1, Scalar(0, 100, 100), 3, LINE_AA);
		// draw the circle outline
		int radius = c[2];
		circle(circle_image0, center, radius, Scalar(255, 0, 255), 3, LINE_AA);
	}
	
	putText(circle_image0, "Count: " + to_string(circles0.size()), Point(40, 80),FONT_HERSHEY_DUPLEX, 0.75, (255, 0, 0), 2, LINE_AA);
	imshow("img0",circle_image0);
	/*imshow("img1", circle_image1);
	imshow("img2", circle_image2);
	imshow("img3", circle_image3);*/


	/*createTrackbar("cannyT1", "img0",0,255, on_trackbar0);
	createTrackbar("cannyT2", "img0", 0, 500, on_trackbar0);
	createTrackbar("cannyT1", "img1", 0, 255, on_trackbar1);
	createTrackbar("cannyT2", "img1", 0, 500, on_trackbar1);
	createTrackbar("cannyT1", "img2", 0, 255, on_trackbar2);
	createTrackbar("cannyT2", "img2", 0, 500, on_trackbar2);
	createTrackbar("cannyT1", "img3", 0, 255, on_trackbar3);
	createTrackbar("cannyT2", "img3", 0, 500, on_trackbar3);*/
	waitKey();
}


