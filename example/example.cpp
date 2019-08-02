#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <algorithm>
#include <iosfwd>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <SuperPoint.hpp>
#include <net_init.hpp>
#include <run.hpp>


// using namespace caffe;  // NOLINT(build/namespaces)
using std::string;
using namespace std;


int main()
{
  SuperPoint superpoint = net_init("../model/superpoint.prototxt", "../model/superpoint.caffemodel", 1000);

  cv::Mat image = cv::imread("../data/example.png", 0);

  std::vector<cv::KeyPoint> kpts;
  std::vector<std::vector<float> > dspts;

  RUN_ExactSP(superpoint, image, kpts, dspts);

//   cv::Mat inputimg(Height, Width, CV_32FC1, tmpfloat);
  for(int i = 0; i < kpts.size(); i++)
  { 
    cv::Point p(kpts[i].pt.x, kpts[i].pt.y);
    cv::circle(image, p , 5, (0, 255, 0), -1);
  }
  cv::imshow("src", image);
  cv::waitKey();
  return 0;
}
