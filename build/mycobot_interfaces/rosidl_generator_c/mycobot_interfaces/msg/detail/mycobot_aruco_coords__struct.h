// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mycobot_interfaces:msg/MycobotArucoCoords.idl
// generated code does not contain a copyright notice

#ifndef MYCOBOT_INTERFACES__MSG__DETAIL__MYCOBOT_ARUCO_COORDS__STRUCT_H_
#define MYCOBOT_INTERFACES__MSG__DETAIL__MYCOBOT_ARUCO_COORDS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MycobotArucoCoords in the package mycobot_interfaces.
typedef struct mycobot_interfaces__msg__MycobotArucoCoords
{
  uint8_t structure_needs_at_least_one_member;
} mycobot_interfaces__msg__MycobotArucoCoords;

// Struct for a sequence of mycobot_interfaces__msg__MycobotArucoCoords.
typedef struct mycobot_interfaces__msg__MycobotArucoCoords__Sequence
{
  mycobot_interfaces__msg__MycobotArucoCoords * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mycobot_interfaces__msg__MycobotArucoCoords__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MYCOBOT_INTERFACES__MSG__DETAIL__MYCOBOT_ARUCO_COORDS__STRUCT_H_
