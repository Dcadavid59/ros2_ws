// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mecharm_interfaces:srv/SetCoords.idl
// generated code does not contain a copyright notice

#ifndef MECHARM_INTERFACES__SRV__DETAIL__SET_COORDS__STRUCT_H_
#define MECHARM_INTERFACES__SRV__DETAIL__SET_COORDS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetCoords in the package mecharm_interfaces.
typedef struct mecharm_interfaces__srv__SetCoords_Request
{
  float x;
  float y;
  float z;
  float rx;
  float ry;
  float rz;
  int8_t speed;
  int8_t model;
} mecharm_interfaces__srv__SetCoords_Request;

// Struct for a sequence of mecharm_interfaces__srv__SetCoords_Request.
typedef struct mecharm_interfaces__srv__SetCoords_Request__Sequence
{
  mecharm_interfaces__srv__SetCoords_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mecharm_interfaces__srv__SetCoords_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetCoords in the package mecharm_interfaces.
typedef struct mecharm_interfaces__srv__SetCoords_Response
{
  bool flag;
} mecharm_interfaces__srv__SetCoords_Response;

// Struct for a sequence of mecharm_interfaces__srv__SetCoords_Response.
typedef struct mecharm_interfaces__srv__SetCoords_Response__Sequence
{
  mecharm_interfaces__srv__SetCoords_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mecharm_interfaces__srv__SetCoords_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MECHARM_INTERFACES__SRV__DETAIL__SET_COORDS__STRUCT_H_
