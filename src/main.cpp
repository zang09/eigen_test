#include <ros/ros.h>

#include <Eigen/Dense>
#include <tf/LinearMath/Quaternion.h>
#include <tf/transform_datatypes.h>

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    ros::init(argc, argv, "eigen_test");

    ROS_INFO("\033[1;32m--->\033[0m Node is started.");

    Eigen::Vector3d rpy;
    rpy << 1.57, 1.57/2. , 1.57;

    vector<double> extRPYV = {-1,0,0,
                              0,1,0,
                              0,0,-1};

    Eigen::Matrix3d extRPY;
    extRPY = Eigen::Map<const Eigen::Matrix<double, -1, -1, Eigen::RowMajor>>(extRPYV.data(), 3, 3);
    cout << extRPY << endl;
    cout << rpy << endl;

    Eigen::Vector3d final = extRPY * rpy;
    cout << final << endl;

    ros::spin();
    return 0;
}
