// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RotateImage.h"
#include <atlconv.h>

int _tmain(int argc, _TCHAR* argv[])
{
	Mat src, dst;		
	if (2 != argc)
	{
		cout << "usage: test  imagename";
		return 0;
	}

	USES_CONVERSION;
	src = imread(W2A(argv[1]), 1);	
	Point pt(50, 50);
	Mat rot_mat;
	rotateImage(src, dst, rot_mat, pt, 30);
	Point pt_warped = warpAffine_point(pt, rot_mat);
	line(dst, Point(pt_warped.x - 10, pt_warped.y), Point(pt_warped.x + 10, pt_warped.y), Scalar(0, 0, 255), 2);
	line(dst, Point(pt_warped.x, pt_warped.y - 10), Point(pt_warped.x, pt_warped.y + 10), Scalar(0, 0, 255), 2);
	imwrite("rotated_img.jpg", dst);

	string window_name = "haha...";
	namedWindow(window_name);
	imshow(window_name, dst);

	waitKey(0);

	return 0;
}

