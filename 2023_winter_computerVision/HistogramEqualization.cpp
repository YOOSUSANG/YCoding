#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
#include<map>
/*
Histogram Equalization 구현
*/
using namespace std;
using namespace cv;
void HisEqualize(InputArray input, OutputArray output) {
	const Mat& img = input.getMat();  // input에 해당하는 mat 꺼내기
	int size = img.rows * img.cols;
	output.create(img.size(), img.type()); // img와 같은 mat 을 output으로 새롭게 만들기
	Mat dst = output.getMat();// ouput에서 mat 꺼내기
	map<uchar, int> m; // 각 명암값에 해당하는 화소의 개수 세기
	map<uchar, double> his1; // h'(lin) 
	map<uchar, double> his2; //  C(lin)
	map<uchar, int>heq; // round(C(lin) * (L-1))

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			if (m.count(img.at<uchar>(i, j))){ // 명암값이 존재하면 해당 화소의 개수 증가 아니면 1로 지정 
				m[img.at<uchar>(i, j)] += 1;
			}
			else {
				m.insert(make_pair(img.at<uchar>(i, j), 1)); 
			}
		}
	}

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		his1.insert(make_pair(iter->first, m[iter->first] / (double) size));
	}

	for (int i = 0; i <= 255; i++) {
		his1.insert(make_pair(i,0));
	}

	for (auto iter = his1.begin(); iter != his1.end(); iter++) {
		if ((int)iter->first == 0)
			his2.insert(make_pair(iter->first, his1[iter->first]));
		else 
			his2.insert(make_pair(iter->first, his2[((int)iter->first) - 1] + iter->second));

		heq.insert(make_pair(iter->first, round(his2[(int)iter->first] * (double)255)));
	}
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			dst.at<uchar>(i, j) = heq[img.at<uchar>(i, j)];
		}
	}	
}
int main () {
	Mat img = imread("C:/Users/360avm/Desktop/Bimg_20170118190830_ydbdnodw.png",0);
	Mat dst1,dst2;
	equalizeHist(img, dst1);
	HisEqualize(img, dst2);
	imshow("welsh corgi", img); // 원본 이미지
	imshow("his welsh corgi li", dst1); // 라이브러리 사용
	imshow("his welsh corgi cr", dst2); // 구현한 함수 사용
	waitKey();
	return 0;
}
