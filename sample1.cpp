#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// OpenCV includes opencv提供的跨平台io函数
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

int main( int argc, const char** argv )
{
	// 读取图像的主函数
	Mat color= imread("../lena.jpg");
	// 将图片转为灰度图
	Mat gray= imread("../lena.jpg", IMREAD_GRAYSCALE);

	//注  读取图片第二个入参的枚举定义
	// enum ImreadModes {
    //    IMREAD_UNCHANGED            = -1, //!< If set, return the loaded image as is (with alpha channel, otherwise it gets cropped). Ignore EXIF orientation.
    //    IMREAD_GRAYSCALE            = 0,  //!< If set, always convert image to the single channel grayscale image (codec internal conversion).
    //    IMREAD_COLOR                = 1,  //!< If set, always convert image to the 3 channel BGR color image.
    //    IMREAD_ANYDEPTH             = 2,  //!< If set, return 16-bit/32-bit image when the input has the corresponding depth, otherwise convert it to 8-bit.
    //    IMREAD_ANYCOLOR             = 4,  //!< If set, the image is read in any possible color format.
    //    IMREAD_LOAD_GDAL            = 8,  //!< If set, use the gdal driver for loading the image.
    //    IMREAD_REDUCED_GRAYSCALE_2  = 16, //!< If set, always convert image to the single channel grayscale image and the image size reduced 1/2.
    //    IMREAD_REDUCED_COLOR_2      = 17, //!< If set, always convert image to the 3 channel BGR color image and the image size reduced 1/2.
    //    IMREAD_REDUCED_GRAYSCALE_4  = 32, //!< If set, always convert image to the single channel grayscale image and the image size reduced 1/4.
    //    IMREAD_REDUCED_COLOR_4      = 33, //!< If set, always convert image to the 3 channel BGR color image and the image size reduced 1/4.
    //    IMREAD_REDUCED_GRAYSCALE_8  = 64, //!< If set, always convert image to the single channel grayscale image and the image size reduced 1/8.
    //    IMREAD_REDUCED_COLOR_8      = 65, //!< If set, always convert image to the 3 channel BGR color image and the image size reduced 1/8.
    //    IMREAD_IGNORE_ORIENTATION   = 128 //!< If set, do not rotate the image according to EXIF's orientation flag.
    //  };
	
	//检查打开图片是否成功
	if(! color.data ) 
	{
		cout << "Could not open or find the image" << std::endl ;
	 	return -1;
	}

	// 将灰度图 写到本地。第一个参数 图片名称以及路径。第二个参数 保存的矩阵图片
	imwrite("lenaGray.jpg", gray);
	
	// 获取图像的列数和行数 也就是 宽度和高度
	int myRow=color.rows-1;
	int myCol=color.cols-1;
	//访问图片的像素
	auto pixel= color.at<Vec3b>(myRow, myCol);
	cout << "Pixel value (B,G,R): (" << (int)pixel[0] << "," << (int)pixel[1] << "," << (int)pixel[2] << ")" << endl;
	
	// 显示图片
	imshow("Lena BGR", color);
	imshow("Lena Gray", gray);
	// w等待用户按键 关闭
	waitKey(0);
	return 0;
}
