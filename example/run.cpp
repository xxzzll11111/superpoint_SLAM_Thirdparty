#include <run.hpp>

using namespace std;

void RUN_ExactSP(SuperPoint& superpoint, const cv::Mat& image, std::vector<cv::KeyPoint>& kpts, std::vector<std::vector<float> >& dspts)
{
    superpoint.ExactSP(image, kpts, dspts);
}