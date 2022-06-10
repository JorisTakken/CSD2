#include <string>
#include <iostream>
#include <math.h>
#include <thread>
#include <unistd.h> // sleep
#include "jack_module.h"
#include "keypress.h"
#include "bufferDebugger.h"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

float brightness = 0;

float R = 0;
float Red = 0;
float G = 0;
float B = 0;


int numberOfLines(Mat img){
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    Mat lineDet;
    Canny(img, lineDet, 50, 200, 3);
    findContours(lineDet, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
    int numberOfLines = contours.size();
    cout << numberOfLines << endl;

    imshow("original Image", img);
    imshow("canny", lineDet);
}
    
int Brightness(Mat img){
    Mat blur_img;
    blur(img, blur_img, Size(250 , 250));    
    for(int y=0;y<blur_img.rows;y++){
        for(int x=0;x<blur_img.cols;x++){
            Vec3b & color = blur_img.at<Vec3b>(y,x);
            if(color[0] > 127 && color[1] > 127 && color[2] > 127){// get pixel
                brightness += 0.001;
            }
            else{
                brightness -= 0.001;
            }
        }  
    }    
    imshow("blurr", blur_img);

    cout << brightness << endl;
}

int color(Mat img){
    Mat blur_img;
    blur(img, blur_img, Size(250 , 250));    
    for(int y=0;y<blur_img.rows;y++){
        for(int x=0;x<blur_img.cols;x++){
            Vec3b & color = blur_img.at<Vec3b>(y,x);
            
            R = color[0];
            Red += R;
            




            // if(color[0] > 200 && color[1] > 0 && color[2] > 0){// get pixel
            //     R = c;
            // }
            // else if (color[0] > 0 && color[1] > 200 && color[2] > 0){
            //     G = 100;
            // }
            // else if (color[0] > 0 && color[1] > 0 && color[2] > 200){
            //     B = 100;
            // }
        }  
    }    
    cout << Red << "  R" << endl;

    cout << G << "  G" << endl;
    cout << B << "  B" << endl;

}


int main() 
{
    Mat img = imread("/Users/joristakken/Desktop/IMG2.png");
    numberOfLines(img);
    Brightness(img);
    color(img);

    waitKey(0);
    destroyAllWindows();
}

