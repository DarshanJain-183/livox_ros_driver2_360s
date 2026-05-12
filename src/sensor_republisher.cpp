#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/Imu.h>

class SensorRepublisher
{
public:
    SensorRepublisher()
    {
        // -------- Subscribers --------
        sub_lidar1_ = nh_.subscribe("/livox/lidar_192_168_1_190", 10, &SensorRepublisher::lidar1Callback, this);
        sub_lidar2_ = nh_.subscribe("/livox/lidar_192_168_1_160", 10, &SensorRepublisher::lidar2Callback, this);
        // sub_lidar3_ = nh_.subscribe("/livox/lidar_134", 10, &SensorRepublisher::lidar3Callback, this);

        sub_imu1_ = nh_.subscribe("/livox/imu_192_168_1_190", 10, &SensorRepublisher::imu1Callback, this);
        sub_imu2_ = nh_.subscribe("/livox/imu_192_168_1_160", 10, &SensorRepublisher::imu2Callback, this);
        // sub_imu3_ = nh_.subscribe("/livox/imu_134", 10, &SensorRepublisher::imu3Callback, this);

        // -------- Publishers --------
        pub_lidar1_ = nh_.advertise<sensor_msgs::PointCloud2>("/livox/lidar_190", 10);
        pub_lidar2_ = nh_.advertise<sensor_msgs::PointCloud2>("/livox/lidar_160", 10);
        // pub_lidar3_ = nh_.advertise<sensor_msgs::PointCloud2>("/livox/lidar3", 10);

        pub_imu1_ = nh_.advertise<sensor_msgs::Imu>("/livox/imu_190", 10);
        pub_imu2_ = nh_.advertise<sensor_msgs::Imu>("/livox/imu_160", 10);
        // pub_imu3_ = nh_.advertise<sensor_msgs::Imu>("/livox/imu3", 10);
    }

private:
    ros::NodeHandle nh_;

    // Subscribers
    ros::Subscriber sub_lidar1_, sub_lidar2_;
    ros::Subscriber sub_imu1_, sub_imu2_;

    // Publishers
    ros::Publisher pub_lidar1_, pub_lidar2_;
    ros::Publisher pub_imu1_, pub_imu2_;

    // -------- LiDAR Callbacks --------
    void lidar1Callback(const sensor_msgs::PointCloud2::ConstPtr& msg)
    {
        auto new_msg = *msg;
        new_msg.header.frame_id = "livox_lidar_190";
        pub_lidar1_.publish(new_msg);
    }

    void lidar2Callback(const sensor_msgs::PointCloud2::ConstPtr& msg)
    {
        auto new_msg = *msg;
        new_msg.header.frame_id = "livox_lidar_160";
        pub_lidar2_.publish(new_msg);
    }

    // void lidar3Callback(const sensor_msgs::PointCloud2::ConstPtr& msg)
    // {
    //     auto new_msg = *msg;
    //     new_msg.header.frame_id = "livox_lidar3";
    //     pub_lidar3_.publish(new_msg);
    // }

    // -------- IMU Callbacks --------
    void imu1Callback(const sensor_msgs::Imu::ConstPtr& msg)
    {
        auto new_msg = *msg;
        new_msg.header.frame_id = "livox_imu_190";
        pub_imu1_.publish(new_msg);
    }

    void imu2Callback(const sensor_msgs::Imu::ConstPtr& msg)
    {
        auto new_msg = *msg;
        new_msg.header.frame_id = "livox_imu_160";
        pub_imu2_.publish(new_msg);
    }

    // void imu3Callback(const sensor_msgs::Imu::ConstPtr& msg)
    // {
    //     auto new_msg = *msg;
    //     new_msg.header.frame_id = "livox_imu3";
    //     pub_imu3_.publish(new_msg);
    // }
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "sensor_republisher");
    SensorRepublisher node;
    ros::spin();
    return 0;
}
