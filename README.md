# Rotate-Image-Function
## Brief description
In OpenCV, two functions, i.e. "getRotationMatrix2D" and "warpAffine" are provided to rotate an image. However, as shown in Fig.1 (b), the image rotated by these functions directly is cut off. That is, the rotated image is not kept in the field of view. To overcome this problem, we developed a C++ function that can be used to rotate an image around arbitrary point. Using this function, as shown in Fig. 1 (c), the rotated image cannot be cut off.  
|![Alt text](/images/img_orig.jpg)|  ![Alt text](/images/rotated_img_1.jpg)|  ![Alt text](/images/rotated_img_2.jpg)|
|    :---:    | :---:      |:---:      |
|   (a) original image    | (b) rotated image (use "getRotationMatrix2D" and "warpAffine" directly)| (b) rotated image (use our function)|
Fig.1 Illustration of image rotation 

## Requirement
* Windows (Windows7 has been validated).
* C++ compiler \[Visual studio 2013 (Community version) has been validated].
* OpenCV \[OpenCV(2.4.11) has been validated].
## How to create a test program using Visual Studio 2013
1. Create a project named test:  FILE -> New -> Project... -> Visual C++ -> Win32 -> Win32 Console Application.
2. Copy MotionBlur.h and MotionBlur.cpp to the directory that contains test.cpp.
3. Add MotionBlur.h to the "test" project: (Project\Header Files) Add -> Existing Item...
4. Add MotionBlur.cpp to the "test" project: (Project\Source Files) Add -> Existing Item...
5. Add "<OpenCV_Folder>\install\include" to Additional Include Directories: (Project) Properities -> Configuration Properties -> C/C++ -> General -> Additional Include Directories.
6. Add "<OpenCV_Folder>\lib\Release" (or "<OpenCV_Folder>\lib\Debug") to Additional Library Directories: (Project) Properities -> Configuration Properties -> Linker -> General -> Additional Libray Directories.
7. Add necessary Static Libraries to Additional Dependencies: (Project) Properities -> Configuration Properties -> Linker -> Input -> Additional Dependencies. The necessary Static Libraries are:
   * opencv_core2411.lib
   * opencv_highgui2411.lib
   * opencv_imgproc2411.lib
8. Include necessary header files in test.cpp.
<pre><code>#include &ltiostream&gt
#include "MotionBlur.h"
#include &ltatlconv.h&gt
using namespace std;</code></pre>
9. Copy following codes to the "_tmain" fuction that is defined in test.cpp.
<pre><code>Mat m_kernel;	
if (2 != argc)
{
    cout << "usage: blur_test  imagename";
    return 0;
}
int res = createMotionBlurKernel(m_kernel, 4, 120);
if (res < 0)
{
    printf("create kernel error!\n");
    return -1;
}
USES_CONVERSION;
Mat srcImg = imread(W2A(argv[1]));
Mat dstImg;
filter2D(srcImg, dstImg, -1, m_kernel);
string window_name = "haha...";
namedWindow(window_name);
imshow(window_name, dstImg);
waitKey(0);
return 0;</code></pre>
10. Build the "test" project.

## Contact with us
Email: chenjiechun@neepu.edu.cn
   

