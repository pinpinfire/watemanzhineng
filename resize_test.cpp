#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

struct box_b
{
	int left_x = 100;
	int left_y = 100;
	int right_x = 200;
	int right_y = 300;
};

int main(int argc, char* argv[])
{
	int mode = atoi(argv[1]);
	// mode = 1: 拉伸填充
	// mode = 2: 保持原比例填充


	box_b box;
	int width = box.right_x - box.left_x;
	int length = box.right_y - box.left_y;
	Mat background = imread("file/2.jpg");
	Mat a = imread("file/1.jpg");
	Mat a_resize;
	if (mode == 1)
	{
		resize(a, a_resize, Size(width, length));
		Mat imageROI = background(Rect(box.left_x, box.left_y, a_resize.cols, a_resize.rows));
		a_resize.copyTo(imageROI);
		imwrite("file/1_result.jpg", background);
		imshow("a", background);
	}
	if (mode == 2)
	{
		double scale = min((double)width / a.cols, (double)length / a.rows);
		resize(a, a_resize, Size(scale * a.cols, scale * a.rows));
		Mat imageROI = background(Rect(box.left_x, box.left_y, a_resize.cols, a_resize.rows));
		a_resize.copyTo(imageROI);
		imwrite("file/2_result.jpg", background);
		imshow("a", background);
	}
	waitKey(0);
	system("pause");

	return 0;
}