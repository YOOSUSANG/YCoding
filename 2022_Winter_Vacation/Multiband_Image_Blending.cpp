#include<iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
using namespace cv;
using namespace std;
vector<Mat>GaussianPyramid(Mat img, int depth = 8) {
	vector<Mat> pyramid;
	Mat img2;
	pyramid.push_back(img); //맨처음 이미지 넣기

	for (int i = 0; i < depth-1; i++) {
		pyrDown(img, img2);// 이미지를 half 나눠주기 pyrDown(img1,img2) img1을 반으로 나눠 img2에 저장한다.
		pyramid.push_back(img2); //반으로 나눠진 결과가 저장된 img2를 pyramid에 넣는다.
		img = img2;//원본 교체
	}
	return pyramid;
}

vector<Mat>LaplacianPyramid(Mat img, int depth = 8) {
	vector<Mat> pyramid;
	Mat uimg,small;
	//LaplacianPyramid 수행 과정
	for (int i = 0; i < depth-1; i++) { //depth개 들어가기 위한 depth-1
		pyrDown(img, small);// 반으로 나누기
		pyrUp(small, uimg, img.size());// 반으로 나눈 small을 img.size()크기만큼 uimg에 저장하기(크기가 같아야 하므로)
		pyramid.push_back(img - uimg);// img - uimg
		img = small;
	}
	pyramid.push_back(img); // 마지막에 있는거 넣기
	return pyramid;
}
// LaplacianPyramid한 결과들을 합치는 과정 즉 High와 low들을 합쳐주면 원본이 나오지 않을까?
Mat recontrcut(const vector<Mat>& pyramid) {
	Mat ret = pyramid.back(); //LaplacianPyramid한 결과에서 가장 끝에 있는 값 저장(즉 마지막에 넣었던거)
	//-2부터는 맨뒤에 앞에 있는 것 부터 
	for (int i = pyramid.size()-2; i >= 0; i--) {
		pyrUp(ret, ret, pyramid[i].size()); // ret를 up한것을 ret에 저장해주는데 이떄 pyramid[i].size()로 저장
		ret += pyramid[i];// up한 것을 LaplacianPyramid한 결과와 더해주면 원본이 나옴
	}
	return ret;
}
//mask가 섞이는 과정 mask가 0.5되면 두 이미지는 반반씩 섞어짐
Mat blend(Mat img1, Mat img2, Mat mask) {
	Mat mul1, mul2, mask2, sum;
	multiply(img1, mask, mul1);// img1과 mask를 곱한 결과를 mul1에 저장
	mask2 = Scalar::all(1) - mask; //rgb값이므로 all
	multiply(img2, mask2, mul2);
	add(mul1, mul2, sum);//mul1 + mul2 가 sum
	return sum;
}

int main(){
	Mat image1 = imread("C:/users/유수상/OneDrive - 아주대학교/바탕 화면/apple.jpg");
	Mat image2 = imread("C:/users/유수상/OneDrive - 아주대학교/바탕 화면/orange.jpg");
	Mat mask = imread("C:/users/유수상/OneDrive - 아주대학교/바탕 화면/mask.png");; //흰색, 검은색을 불러오는 것
	image1.convertTo(image1, CV_32F,1/255.f);
	image2.convertTo(image2, CV_32F, 1/255.f);
	mask.convertTo(mask, CV_32F, 1/255.f);
	
	vector<Mat> LpImage1 = LaplacianPyramid(image1);
	vector<Mat> LpImage2 = LaplacianPyramid(image2);
	vector<Mat> Gmask = GaussianPyramid(mask);
	vector<Mat> res;
	Mat reImage;
	Mat org = blend(image1, image2, mask);
	for (int i = 0; i < Gmask.size(); i++) {
		res.push_back(blend(LpImage1[i], LpImage2[i], Gmask[i]));
	}
	reImage = recontrcut(res);
	imshow("result", reImage);
	imshow("original", org);
	waitKey();
	


}


