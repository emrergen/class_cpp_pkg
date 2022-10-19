#include <iostream>
#include "ros/ros.h"
#include "sensor_msgs/PointCloud2.h"

namespace class_cpp_pkg
{
    class ClassUtils
    {

        public:

        ClassUtils();

        ~ClassUtils();

        void lidarPointsPrinter(sensor_msgs::PointCloud2 &t_cloud);

    };


}