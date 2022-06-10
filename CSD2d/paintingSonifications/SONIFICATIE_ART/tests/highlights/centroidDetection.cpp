#include "centroidDetection.h"
//We used ciska's code for image processing, used session_04 code;
// code is taken from https://learnopencv.com/find-center-of-blob-centroid-using-opencv-cpp-python/ , and altered by Rahsaan Bleijs 2022

CentroidDetection::CentroidDetection(){
}

CentroidDetection::~CentroidDetection(){
}


void CentroidDetection::binaryImage(Mat& image){
  // processing image to binary
    cvtColor(image, gray_camera, COLOR_BGR2GRAY);
    int h = gray_camera.rows;
    int w = gray_camera.cols;

    for(int i = 0; i < h; i++) {
        uchar* row = gray_camera.ptr<uchar>(i);
        for(int j = 0; j < w; j++) {
            row[j] = row[j] * 0.80; //contrast down
            row[j] = row[j] > 90 ? 0 : 255; //making image binary
        }
    }
}

void CentroidDetection::edgeDetection(){
    // make canny output (edge detection)
    Canny(gray_camera, canny_output, 100, 500,3);
}

void CentroidDetection::findingcontours(){
  // findingcontours
    findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
}

void CentroidDetection::makePoints(){
    // make points

    mu = vector<Moments>(contours.size());
    mc = vector<Point2f>(contours.size());

    for( int i = 0; i<contours.size(); i++ ){
      mu[i] = moments(contours[i], false );
    }
    // get the centroid of figures with formula
    for( int i = 0; i<contours.size(); i++){
      mc[i] = Point2f(mu[i].m10/(mu[i].m00 + 1e-5 ), mu[i].m01/(mu[i].m00 + 1e-5));
    }
}

void CentroidDetection::drawBigCentroid(Mat& image){
  // drawing the big blue centroid
    Moments m = moments(gray_camera,true);
    Point p(m.m10/m.m00, m.m01/m.m00);
    // circle(camera,(447,63), 63, (0,0,255), -1);
    circle(image, p, 5, Scalar(255,0,0), -1);
}

void CentroidDetection::drawPoints(Mat& image){
  // drawing contours and centroids on image
    binaryImage(image);
    edgeDetection();
    findingcontours();
    makePoints();

    Mat drawing(canny_output.size(), CV_8UC3, Scalar(255,255,255));
    for( int i = 0; i<contours.size(); i++){
      Scalar color = Scalar(167,151,111); // B G R values
      drawContours(image, contours, i, color, 2, 8, hierarchy, 0, Point());
      circle(image, mc[i], 5, Scalar(0,255,0), -1, 8, 0);
    //   std::cout << mc[i] << std::endl;
    }
}

void CentroidDetection::listGen(){
  // creating vectors for x and y
  xValues = vector<float>(mc.size());
  yValues = vector<float>(mc.size());

  // putting coordinates into separate lists
  for(int i = 0; i < mc.size(); i++){
    if(mc[i] != Point2f(0)){
      xValues[i] = float(mc[i].x);
      yValues[i] = float(mc[i].y);
    }
  }
  // creating list to send to params
  for(int j = 0; j < 11; j++){
    if(j < 5){
      paramUnscaled[j] = xValues[j];
    } else if (j > 4 && j < 10){
      paramUnscaled[j] = yValues[j];
    } else if(j == 10) {
      paramUnscaled[j] = j;
    }
  }
}
