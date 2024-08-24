// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mycobot_interfaces2:msg/MyArucoCoords.idl
// generated code does not contain a copyright notice

#ifndef MYCOBOT_INTERFACES2__MSG__DETAIL__MY_ARUCO_COORDS__STRUCT_H_
#define MYCOBOT_INTERFACES2__MSG__DETAIL__MY_ARUCO_COORDS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MyArucoCoords in the package mycobot_interfaces2.
typedef struct mycobot_interfaces2__msg__MyArucoCoords
{
  int16_t id;
  float distance;
  float x;
  float y;
  float z;
  float rx;
  float ry;
  float rz;
} mycobot_interfaces2__msg__MyArucoCoords;

// Struct for a sequence of mycobot_interfaces2__msg__MyArucoCoords.
typedef struct mycobot_interfaces2__msg__MyArucoCoords__Sequence
{
  mycobot_interfaces2__msg__MyArucoCoords * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mycobot_interfaces2__msg__MyArucoCoords__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MYCOBOT_INTERFACES2__MSG__DETAIL__MY_ARUCO_COORDS__STRUCT_H_
