#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main() 
{
    Mat img = imread("/Users/joristakken/Desktop/IMG.png");

    Mat blur_img;
    blur(img, blur_img, Size(250 , 250));

    Mat lineDet;
    Canny(img, lineDet, 50, 200, 3);

    imshow("normal",img);
    imshow("blur",blur_img);
    imshow("lineDet",lineDet);

    waitKey(0);
}