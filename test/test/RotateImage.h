#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace cv;
using namespace std;

void rotateImage(Mat&, Mat&, Mat&, Point, float);
Point warpAffine_point(Point, Mat);