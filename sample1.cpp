#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

const int CV_GUI_NORMAL = 0x10;

int main(int argc, const char** argv)
{
	// Read images
	Mat lena = imread("D:\\opencvLearn\\Chapter_03/lena.jpg");
	Mat photo = imread("D:\\opencvLearn\\Chapter_03/photo.jpg");

	// 创建窗口 并允许调整窗口大小
	namedWindow("Lena", WINDOW_NORMAL); 
	if (!lena.data) {
		cout << "Lena image missing!" << endl;
		return -1;
	}
	//创建窗口 并自动调整适应显示图，但不能调整窗口大小
	namedWindow("Photo", WINDOW_AUTOSIZE);
	if (!photo.data) {
		cout << "Lena image missing!" << endl;
		return -1;
	}
	//移动窗口（因为创建的时候 窗口是叠加的）
	moveWindow("Lena", 10, 10);
	moveWindow("Photo", 520, 10);

	// 显示图片
	imshow("Lena", lena);
	imshow("Photo", photo);

	//窗口大小调整。
	resizeWindow("Lena", 512, 512);

	// 等待按键
	waitKey(0);

	// 销毁窗口
	destroyWindow("Lena");
	destroyWindow("Photo");

	// 创建批量窗口
	for (int i = 0; i < 10; i++)
	{
		ostringstream ss;
		ss << "Photo " << i;
		namedWindow(ss.str());
		moveWindow(ss.str(), 20 * i, 20 * i);
		imshow(ss.str(), photo);
	}

	waitKey(0);
	// 销毁全部窗口
	destroyAllWindows();
	return 0;
}
