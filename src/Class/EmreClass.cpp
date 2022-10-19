#include "../../include/class_cpp_pkg/EmreClass.hpp"

namespace class_cpp_pkg
{
    EmreClass::EmreClass(ros::NodeHandle &t_node_handle) : m_node_handle{t_node_handle},
                                                           m_is_lidar_recieved{false},
                                                           m_rate{10},
                                                           m_sleep{20},
                                                           ClassUtils()
    {
        ROS_INFO("IN CONSTRUCTURE..");

        m_subscriber_lidar = m_node_handle.subscribe("/points_points", 10, &EmreClass::lidarCallBack, this);

        m_publisher_point_cloud = m_node_handle.advertise<sensor_msgs::PointCloud2>("/nereye", 1);

        std::thread c_thread(&EmreClass::threadFunction, this);

        c_thread.join();
    }

    EmreClass::~EmreClass()
    {
        ROS_INFO("IN DESCTRUCRER");
    }

    void EmreClass::lidarCallBack(const sensor_msgs::PointCloud2::ConstPtr &t_point_cloud)
    {
        m_is_lidar_recieved = true;
        std::cout << "IN LIDAR CALL BACK " << std::endl;
        m_point_cloud = *t_point_cloud;
        // m_is_lidar_recieved = false;
    }

    void EmreClass::threadFunction()
    {

        while (ros::ok())
        {

            if (m_is_lidar_recieved == true)
            {
                m_publisher_point_cloud.publish(m_point_cloud);
                m_classUtils.lidarPointsPrinter(m_point_cloud);
                
            }
            else
            {
                ROS_INFO("DATA HAS NOT BEEN RECEIVED....");
                m_sleep.sleep();
            }
            ros::spinOnce();
            m_rate.sleep();
        }
    }

}