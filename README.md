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
3. Add RotateImage.h to the "test" project: (Project\Header Files) Add -> Existing Item...
4. Add RotateImage.cpp to the "test" project: (Project\Source Files) Add -> Existing Item...
5. Add "<OpenCV_Folder>\install\include" to Additional Include Directories: (Project) Properities -> Configuration Properties -> C/C++ -> General -> Additional Include Directories.
6. Add "<OpenCV_Folder>\lib\Release" (or "<OpenCV_Folder>\lib\Debug") to Additional Library Directories: (Project) Properities -> Configuration Properties -> Linker -> General -> Additional Libray Directories.
7. Add necessary Static Libraries to Additional Dependencies: (Project) Properities -> Configuration Properties -> Linker -> Input -> Additional Dependencies. The necessary Static Libraries are:
   * opencv_core2411.lib
   * opencv_highgui2411.lib
   * opencv_imgproc2411.lib
8. Include necessary header files in test.cpp.
<pre><code>#include "RotateImage.h"
#include &ltatlconv.h&gt</code></pre>
9. Copy following codes to the "_tmain" fuction that is defined in test.cpp.
<pre><code>Mat src, dst;		
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
return 0;</code></pre>
10. Build the "test" project.

## Contact with us
Email: chenjiechun@neepu.edu.cn
   

