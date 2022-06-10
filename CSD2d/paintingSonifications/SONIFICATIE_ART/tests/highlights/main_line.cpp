#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() 
{
  Mat img = imread("/Users/joristakken/Desktop/IMG.png");
  Mat line;
  Mat values;
  int counter=0;

    for (int i = 0; i < img.rows; i++){
      for (int j = 0; j < img.cols; j++){


        // cout << i;
        line = img.row(i);
        
      }     
    }

    imshow("line", line);
    imshow("img", img);

    waitKey(0);
    return 0;
}