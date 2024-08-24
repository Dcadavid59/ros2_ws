// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mycobot_interfaces:msg/MyArucoCoords.idl
// generated code does not contain a copyright notice

#ifndef MYCOBOT_INTERFACES__MSG__DETAIL__MY_ARUCO_COORDS__STRUCT_H_
#define MYCOBOT_INTERFACES__MSG__DETAIL__MY_ARUCO_COORDS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MyArucoCoords in the package mycobot_interfaces.
typedef struct mycobot_interfaces__msg__MyArucoCoords
{
  float x;
  float y;
  float z;
  float rx;
  float ry;
  float rz;
  int16_t id;
  bool flag;
  float distance;
} mycobot_interfaces__msg__MyArucoCoords;

// Struct for a sequence of mycobot_interfaces__msg__MyArucoCoords.
typedef struct mycobot_interfaces__msg__MyArucoCoords__Sequence
{
  mycobot_interfaces__msg__MyArucoCoords * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mycobot_interfaces__msg__MyArucoCoords__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MYCOBOT_INTERFACES__MSG__DETAIL__MY_ARUCO_COORDS__STRUCT_H_
