#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// OpenCV includes opencv提供的跨平台io函数
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

// OpenCV command line parser functions
// Keys accecpted by command line parser
const char* keys =
{
	"{help h usage ? | | print this message}"
	"{@video | | Video file, if not defined try to use webcamera}"
};

int main(int argc, const char** argv)
{

	VideoCapture cap; 
	// 读取视频。open的参数为0时，会读取摄像头
	cap.open("D:\\opencvStudy\\123.mp4");
	//if (videoFile != "")
	//	cap.open(videoFile);
	//else
	//	cap.open(0);
	//检查读取是否成功
	if (!cap.isOpened())  
		return -1;

	//打开一个窗口 并命名为video
	namedWindow("Video", 1);

	//使用无限循环来显示帧
	for (;;)
	{
		Mat frame;
		//操作抓取帧
		cap >> frame;  
		if (frame.empty())
			return 0;
		//显示
		imshow("Video", frame);
		//等待30毫秒
		if (waitKey(30) >= 0) break;
	}
	//释放所有视频资源
	cap.release();

	return 0;
}
