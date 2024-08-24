// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mycobot_interfaces:msg/MyArucoCoords.idl
// generated code does not contain a copyright notice

#ifndef MYCOBOT_INTERFACES__MSG__DETAIL__MY_ARUCO_COORDS__BUILDER_HPP_
#define MYCOBOT_INTERFACES__MSG__DETAIL__MY_ARUCO_COORDS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mycobot_interfaces/msg/detail/my_aruco_coords__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mycobot_interfaces
{

namespace msg
{

namespace builder
{

class Init_MyArucoCoords_distance
{
public:
  explicit Init_MyArucoCoords_distance(::mycobot_interfaces::msg::MyArucoCoords & msg)
  : msg_(msg)
  {}
  ::mycobot_interfaces::msg::MyArucoCoords distance(::mycobot_interfaces::msg::MyArucoCoords::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mycobot_interfaces::msg::MyArucoCoords msg_;
};

class Init_MyArucoCoords_flag
{
public:
  explicit Init_MyArucoCoords_flag(::mycobot_interfaces::msg::MyArucoCoords & msg)
  : msg_(msg)
  {}
  Init_MyArucoCoords_distance flag(::mycobot_interfaces::msg::MyArucoCoords::_flag_type arg)
  {
    msg_.flag = std::move(arg);
    return Init_MyArucoCoords_distance(msg_);
  }

private:
  ::mycobot_interfaces::msg::MyArucoCoords msg_;
};

class Init_MyArucoCoords_id
{
public:
  explicit Init_MyArucoCoords_id(::mycobot_interfaces::msg::MyArucoCoords & msg)
  : msg_(msg)
  {}
  Init_MyArucoCoords_flag id(::mycobot_interfaces::msg::MyArucoCoords::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_MyArucoCoords_flag(msg_);
  }

private:
  ::mycobot_interfaces::msg::MyArucoCoords msg_;
};

class Init_MyArucoCoords_rz
{
public:
  explicit Init_MyArucoCoords_rz(::mycobot_interfaces::msg::MyArucoCoords & msg)
  : msg_(msg)
  {}
  Init_MyArucoCoords_id rz(::mycobot_interfaces::msg::MyArucoCoords::_rz_type arg)
  {
    msg_.rz = std::move(arg);
    return Init_MyArucoCoords_id(msg_);
  }

private:
  ::mycobot_interfaces::msg::MyArucoCoords msg_;
};

class Init_MyArucoCoords_ry
{
public:
  explicit Init_MyArucoCoords_ry(::mycobot_interfaces::msg::MyArucoCoords & msg)
  : msg_(msg)
  {}
  Init_MyArucoCoords_rz ry(::mycobot_interfaces::msg::MyArucoCoords::_ry_type arg)
  {
    msg_.ry = std::move(arg);
    return Init_MyArucoCoords_rz(msg_);
  }

private:
  ::mycobot_interfaces::msg::MyArucoCoords msg_;
};

class Init_MyArucoCoords_rx
{
public:
  explicit Init_MyArucoCoords_rx(::mycobot_interfaces::msg::MyArucoCoords & msg)
  : msg_(msg)
  {}
  Init_MyArucoCoords_ry rx(::mycobot_interfaces::msg::MyArucoCoords::_rx_type arg)
  {
    msg_.rx = std::move(arg);
    return Init_MyArucoCoords_ry(msg_);
  }

private:
  ::mycobot_interfaces::msg::MyArucoCoords msg_;
};

class Init_MyArucoCoords_z
{
public:
  explicit Init_MyArucoCoords_z(::mycobot_interfaces::msg::MyArucoCoords & msg)
  : msg_(msg)
  {}
  Init_MyArucoCoords_rx z(::mycobot_interfaces::msg::MyArucoCoords::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_MyArucoCoords_rx(msg_);
  }

private:
  ::mycobot_interfaces::msg::MyArucoCoords msg_;
};

class Init_MyArucoCoords_y
{
public:
  explicit Init_MyArucoCoords_y(::mycobot_interfaces::msg::MyArucoCoords & msg)
  : msg_(msg)
  {}
  Init_MyArucoCoords_z y(::mycobot_interfaces::msg::MyArucoCoords::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_MyArucoCoords_z(msg_);
  }

private:
  ::mycobot_interfaces::msg::MyArucoCoords msg_;
};

class Init_MyArucoCoords_x
{
public:
  Init_MyArucoCoords_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MyArucoCoords_y x(::mycobot_interfaces::msg::MyArucoCoords::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_MyArucoCoords_y(msg_);
  }

private:
  ::mycobot_interfaces::msg::MyArucoCoords msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mycobot_interfaces::msg::MyArucoCoords>()
{
  return mycobot_interfaces::msg::builder::Init_MyArucoCoords_x();
}

}  // namespace mycobot_interfaces

#endif  // MYCOBOT_INTERFACES__MSG__DETAIL__MY_ARUCO_COORDS__BUILDER_HPP_
