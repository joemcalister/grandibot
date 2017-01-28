//
//  main.cpp
//  drawingbot
//
//  Created by Joe on 27/11/2016.
//  Copyright © 2016 joemcalister. All rights reserved.
//

#include <unistd.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>
#include <ctime>

using namespace cv;
using namespace std;

#define w 1080
float magnify = 300; 
float rotation = 0; 
float radius = 0; 

void simpleLine(Mat img, Point start, Point end);

int main(void){
    
    // set random seed
    srand(time(NULL));
    int elements = rand()%(500-200 + 1) + 200;
    
    // create image
    Mat circle = Mat::zeros( w, w, CV_8UC3);
    circle = Scalar(255,255,255);

    // create point
    Point lastPoint;
    int count = 0;
    
    // create randoms
    int amp = rand()%(elements-1 + 1) + 1;
    int amp2 = rand()%(elements-1 + 1) + 1;
    
    // determie spacing
    float spacing = 6.2831855/elements;
    
    for (int i = 0; i < elements;i++) {
        
        // create our point
        Point tP;
        tP.x = (sin(spacing*i*amp)*cos(spacing*i*amp2)*magnify) + (w/2);
        tP.y = (sin(spacing*amp*i)*(sin(spacing*i*amp2)*magnify)) + (w/2);
        
        // always keep one point begind to connect to
        if (count == 0)
        {
            // first point
            lastPoint = tP;
        }else {
            // not first
            simpleLine(circle, tP, lastPoint);
            lastPoint = tP;
        }
        
        // itterate count
        count ++;
    }
    
    // determine compression on the png
    vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);

    // save the image to the current folder
    try {
        ostringstream a;
        a << "output.png";
        string filepath(a.str());

        // write image
        imwrite(filepath, circle, compression_params);
        
        // note export
        cout << "Exported!" << endl;
    }
    catch (runtime_error& ex) {
        fprintf(stderr, "Exception converting image to PNG format: %s\n", ex.what());
        return 1;
    }
    
    return 1;
}

void simpleLine( Mat img, Point start, Point end )
{
    line(img, start, end, Scalar(0,0,0), 1, CV_AA);
}

