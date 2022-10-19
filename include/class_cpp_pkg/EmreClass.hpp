#pragma once

#include <iostream>

#include "ros/ros.h"
#include "sensor_msgs/PointCloud2.h"
#include <thread>
#include <chrono>

#include "../../include/class_cpp_pkg/ClassUtils.hpp"


namespace class_cpp_pkg
{

    class EmreClass : public ClassUtils
    {
        public:

        EmreClass(ros::NodeHandle &t_node_handle);

        ~EmreClass();

        private:

        ros::NodeHandle m_node_handle;

        ros::Subscriber m_subscriber_lidar;

        ros::Publisher m_publisher_point_cloud; 

        sensor_msgs::PointCloud2 m_point_cloud;

        ros::Rate m_rate;

        ros::Rate m_sleep;

        ClassUtils m_classUtils;

        bool m_is_lidar_recieved;

        void lidarCallBack(const sensor_msgs::PointCloud2::ConstPtr &t_point_cloud);

        void threadFunction();
    };

}