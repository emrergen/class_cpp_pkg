#include "../../include/class_cpp_pkg/EmreClass.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "class");

    ros::NodeHandle node_handle;

    class_cpp_pkg::EmreClass emre_class(node_handle);

    ros::spin();

    return 0;
}