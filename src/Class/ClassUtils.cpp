#include "../../include/class_cpp_pkg/ClassUtils.hpp"


namespace class_cpp_pkg
{

ClassUtils::ClassUtils()
{
    ROS_INFO("COUNSTROCTOR");

}

ClassUtils::~ClassUtils()
{

}

void ClassUtils::lidarPointsPrinter(sensor_msgs::PointCloud2 &t_point_cloud)
{

 std::cout<<"POINTS ARE PRINTING..."<<std::endl;

}

}