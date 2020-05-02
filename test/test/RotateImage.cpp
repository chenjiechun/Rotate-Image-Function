#include "stdafx.h"
#include "RotateImage.h"


float MinFloat_4(float _a, float _b, float _c, float _d)
{
	float minVal;
	minVal = _a;
	if (_b < minVal)
		minVal = _b;
	if (_c < minVal)
		minVal = _c;
	if (_d < minVal)
		minVal = _d;

	return minVal;
}
float MaxFloat_4(float _a, float _b, float _c, float _d)
{
	float maxVal;
	maxVal = _a;
	if (_b > maxVal)
		maxVal = _b;
	if (_c > maxVal)
		maxVal = _c;
	if (_d > maxVal)
		maxVal = _d;

	return maxVal;
}


void getTranslation(int _imgWidth, int _imgHeight, int& _tx, int& _ty, int & _newWidth, int& _newHeight, int _cx = 10, int _cy = 10, float _beta = 0)
{
	int x_0, y_0;
	float x_01, y_01;
	float alpha_0;
	float l_0;
	int x_1, y_1;
	float x_11, y_11;
	float alpha_1;
	float l_1;
	int x_2, y_2;
	float x_21, y_21;
	float alpha_2;
	float l_2;
	int x_3, y_3;
	float x_31, y_31;
	float alpha_3;
	float l_3;
	const float M_PI = 3.1415926;

	x_0 = _imgWidth - 1 - _cx;
	y_0 = _cy;
	l_0 = sqrt(pow(x_0, 2) + pow(y_0, 2));
	alpha_0 = asin(y_0 / l_0);
	x_1 = -1 * _cx;
	y_1 = _cy;
	l_1 = sqrt(pow(x_1, 2) + pow(y_1, 2));
	alpha_1 = M_PI - asin(y_1 / l_1);
	x_2 = -1 * _cx;
	y_2 = -1 * (_imgHeight - 1 - _cy);
	l_2 = sqrt(pow(x_2, 2) + pow(y_2, 2));
	alpha_2 = M_PI + asin(abs(y_2) / l_2);
	x_3 = _imgWidth - 1 - _cx;
	y_3 = -1 * (_imgHeight - 1 - _cy);
	l_3 = sqrt(pow(x_3, 2) + pow(y_3, 2));
	alpha_3 = 2 * M_PI - asin(abs(y_3) / l_3);

	x_01 = l_0 * cos(alpha_0 + _beta);
	y_01 = l_0 * sin(alpha_0 + _beta);
	x_11 = l_1 * cos(alpha_1 + _beta);
	y_11 = l_1 * sin(alpha_1 + _beta);
	x_21 = l_2 * cos(alpha_2 + _beta);
	y_21 = l_2 * sin(alpha_2 + _beta);
	x_31 = l_3 * cos(alpha_3 + _beta);
	y_31 = l_3 * sin(alpha_3 + _beta);

	float minX, minY, maxX, maxY;
	minX = MinFloat_4(x_01, x_11, x_21, x_31);
	minY = MinFloat_4(y_01, y_11, y_21, y_31);
	maxX = MaxFloat_4(x_01, x_11, x_21, x_31);
	maxY = MaxFloat_4(y_01, y_11, y_21, y_31);

	int cx_new = (int)(-1 * minX + 0.5);
	int cy_new = (int)(maxY + 0.5);
	_tx = cx_new - _cx;
	_ty = cy_new - _cy;
	_newWidth = (int)(maxX - minX + 0.5);
	_newHeight = (int)(maxY - minY + 0.5);
}

void rotateImage(Mat& img, Mat& rotatedImg, Mat& _rot_mat, Point center, float degreesCCW = 30)
{
	//Mat rot_mat;
	_rot_mat = getRotationMatrix2D(center, degreesCCW, 1.0);
	float rad = degreesCCW * 3.1415926 / 180;
	int tx, ty;
	int newW, newH;
	getTranslation(img.cols, img.rows, tx, ty, newW, newH, center.x, center.y, rad);
	_rot_mat.at<double>(0, 2) += tx;
	_rot_mat.at<double>(1, 2) += ty;
	
	warpAffine(img, rotatedImg, _rot_mat, Size(newW, newH));	
}

Point warpAffine_point(Point _origPoint, Mat _rot_mat)
{
	int xx = (int)(_origPoint.x * _rot_mat.ptr<double>(0)[0] + _origPoint.y * _rot_mat.ptr<double>(0)[1] + _rot_mat.ptr<double>(0)[2] + 0.5);
	int yy = (int)(_origPoint.x * _rot_mat.ptr<double>(1)[0] + _origPoint.y * _rot_mat.ptr<double>(1)[1] + _rot_mat.ptr<double>(1)[2] + 0.5);
	return Point(xx, yy);
}