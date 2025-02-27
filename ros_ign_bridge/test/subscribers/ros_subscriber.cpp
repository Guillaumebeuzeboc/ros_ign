/*
 * Copyright (C) 2018 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include <gtest/gtest.h>
#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/ColorRGBA.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Header.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseArray.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Transform.h>
#include <geometry_msgs/TransformStamped.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Vector3.h>
#include <mav_msgs/Actuators.h>
#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/Odometry.h>
#include <rosgraph_msgs/Clock.h>
#include <sensor_msgs/BatteryState.h>
#include <sensor_msgs/CameraInfo.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/JointState.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/MagneticField.h>
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/PointCloud2.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <tf2_msgs/TFMessage.h>
#include <chrono>
#include "../test_utils.h"

//////////////////////////////////////////////////
/// \brief A class for testing ROS topic subscription.
template <typename ROS_T>
class MyTestClass
{
  /// \brief Class constructor.
  public: MyTestClass(const std::string &_topic)
  {
    this->sub = this->n.subscribe(_topic, 1000, &MyTestClass::Cb, this);
  }

  /// \brief Member function called each time a topic update is received.
  public: void Cb(const ROS_T& _msg)
  {
    ros_ign_bridge::testing::compareTestMsg(_msg);
    this->callbackExecuted = true;
  };

  /// \brief Member variables that flag when the actions are executed.
  public: bool callbackExecuted = false;

  /// \brief ROS node handle;
  private: ros::NodeHandle n;

  /// \brief ROS subscriber;
  private: ros::Subscriber sub;
};

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, Bool)
{
  MyTestClass<std_msgs::Bool> client("bool");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, ColorRGBA)
{
  MyTestClass<std_msgs::ColorRGBA> client("color");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, Empty)
{
  MyTestClass<std_msgs::Empty> client("empty");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, Int32)
{
  MyTestClass<std_msgs::Int32> client("int32");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, Float)
{
  MyTestClass<std_msgs::Float32> client("float");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, Double)
{
  MyTestClass<std_msgs::Float64> client("double");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, Header)
{
  MyTestClass<std_msgs::Header> client("header");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, String)
{
  MyTestClass<std_msgs::String> client("string");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, Quaternion)
{
  MyTestClass<geometry_msgs::Quaternion> client("quaternion");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, Vector3)
{
  MyTestClass<geometry_msgs::Vector3> client("vector3");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, Clock)
{
  MyTestClass<rosgraph_msgs::Clock> client("clock");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, Point)
{
  MyTestClass<geometry_msgs::Point> client("point");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, Pose)
{
  MyTestClass<geometry_msgs::Pose> client("pose");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, PoseArray)
{
  MyTestClass<geometry_msgs::PoseArray> client("pose_array");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, PoseStamped)
{
  MyTestClass<geometry_msgs::PoseStamped> client("pose_stamped");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, Transform)
{
  MyTestClass<geometry_msgs::Transform> client("transform");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, TransformStamped)
{
  MyTestClass<geometry_msgs::TransformStamped> client("transform_stamped");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, TF2Message)
{
  MyTestClass<tf2_msgs::TFMessage> client("tf2_message");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, Twist)
{
  MyTestClass<geometry_msgs::Twist> client("twist");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, Image)
{
  MyTestClass<sensor_msgs::Image> client("image");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, CameraInfo)
{
  MyTestClass<sensor_msgs::CameraInfo> client("camera_info");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, FluidPressure)
{
  MyTestClass<sensor_msgs::FluidPressure> client("fluid_pressure");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, Imu)
{
  MyTestClass<sensor_msgs::Imu> client("imu");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, JointStates)
{
  MyTestClass<sensor_msgs::JointState> client("joint_states");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, LaserScan)
{
  MyTestClass<sensor_msgs::LaserScan> client("laserscan");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, MagneticField)
{
  MyTestClass<sensor_msgs::MagneticField> client("magnetic");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

TEST(ROSSubscriberTest, NavSatFix)
{
  MyTestClass<sensor_msgs::NavSatFix> client("navsat");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, Actuators)
{
  MyTestClass<mav_msgs::Actuators> client("actuators");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted); 
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, OccupancyGrid)
{
  MyTestClass<nav_msgs::OccupancyGrid> client("map");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, Odometry)
{
  MyTestClass<nav_msgs::Odometry> client("odometry");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, PointCloud2)
{
  MyTestClass<sensor_msgs::PointCloud2> client("pointcloud2");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, BatteryState)
{
  MyTestClass<sensor_msgs::BatteryState> client("battery_state");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, Marker)
{
  MyTestClass<visualization_msgs::Marker> client("marker");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(ROSSubscriberTest, MarkerArray)
{
  MyTestClass<visualization_msgs::MarkerArray> client("marker_array");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVarAndSpin(
    client.callbackExecuted, 10ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "ros_string_subscriber");

  return RUN_ALL_TESTS();
}
