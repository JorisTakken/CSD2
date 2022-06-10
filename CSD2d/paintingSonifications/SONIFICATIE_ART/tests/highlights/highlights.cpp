#include "highlights.h"
//We used ciska's code for image processing, used session_04 code;
// code is taken from https://learnopencv.com/find-center-of-blob-centroid-using-opencv-cpp-python/ , and altered by Rahsaan Bleijs 2022

Highlights::Highlights(){
}

Highlights::~Highlights(){
}

void Highlights::binaryImage(Mat& image,Mat& gray_image){
  // processing image to binary
    cvtColor(image, gray_image, COLOR_BGR2GRAY);
    int h = gray_image.rows;
    int w = gray_image.cols;

    for(int i = 0; i < h; i++) {
        uchar* row = gray_image.ptr<uchar>(i);
        for(int j = 0; j < w; j++) {
            row[j] = row[j] * 0.80;         //contrast down
            row[j] = row[j] > 90 ? 0 : 255; //making image binary

            cout << row[10]; 
        }
    }   
   
}
