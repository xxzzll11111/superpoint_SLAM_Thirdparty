#include <net_init.hpp>

using namespace std;

SuperPoint net_init(const std::string& model_file, const std::string& trained_file, int keep_k_points)
{
    SuperPoint superpoint = SuperPoint(model_file, trained_file, keep_k_points);
    
    return superpoint;
}