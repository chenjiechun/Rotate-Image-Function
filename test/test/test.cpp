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
	rotateImage(src, dst, pt, 30);	
	string window_name = "haha...";
	namedWindow(window_name);
	imshow(window_name, dst);

	waitKey(0);

	return 0;
}

