#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main() {
    VideoCapture vid_capture("/Users/joristakken/Desktop/zwartofwit/Bounces/IMG.mov");
    // VideoCapture vid_capture("/Users/joristakken/Downloads/JAIRTHEMOVIE_AdobeCreativeCloudExpress.mp4");
    
    while (vid_capture.isOpened()){
        Mat original;
        vid_capture >> original;

        Mat blurred;
        blur(original, blurred, Size(250 , 250));

        Mat line;
        Canny(original, line, 50, 20, 3);

        float val=0;

        for(int y=0;y<blurred.rows;y++){
            for(int x=0;x<blurred.cols;x++){
                Vec3b & color = blurred.at<Vec3b>(y,x);

                if(color[0] > 50 && color[1] > 100 && color[2] > 10)
                    {// get pixel
                    // ... do something to the color ....
                    color[0] = 13;
                    color[1] = 200;
                    color[2] = 13;

                    val += 0.0001;
                // set pixel
                //image.at<Vec3b>(Point(x,y)) = color;
                //if you copy value
                }
                else{
                    color[0] = 103;
                    color[1] = 20;
                    color[2] = 103;

                    val -= 0.0001;
                }
                // cout << val << " ";
            }  
        }

        


        imshow("original", original);
        imshow("blurred", blurred);
        // imshow("line", line);

        char c=(char)waitKey(25);
        if(c==27)
            break;

    }
    
    vid_capture.release();
    destroyAllWindows();

    return 0; 
}