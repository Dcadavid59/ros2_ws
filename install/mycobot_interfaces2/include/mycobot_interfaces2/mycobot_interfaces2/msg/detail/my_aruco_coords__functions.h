// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from mycobot_interfaces2:msg/MyArucoCoords.idl
// generated code does not contain a copyright notice

#ifndef MYCOBOT_INTERFACES2__MSG__DETAIL__MY_ARUCO_COORDS__FUNCTIONS_H_
#define MYCOBOT_INTERFACES2__MSG__DETAIL__MY_ARUCO_COORDS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "mycobot_interfaces2/msg/rosidl_generator_c__visibility_control.h"

#include "mycobot_interfaces2/msg/detail/my_aruco_coords__struct.h"

/// Initialize msg/MyArucoCoords message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mycobot_interfaces2__msg__MyArucoCoords
 * )) before or use
 * mycobot_interfaces2__msg__MyArucoCoords__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mycobot_interfaces2
bool
mycobot_interfaces2__msg__MyArucoCoords__init(mycobot_interfaces2__msg__MyArucoCoords * msg);

/// Finalize msg/MyArucoCoords message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mycobot_interfaces2
void
mycobot_interfaces2__msg__MyArucoCoords__fini(mycobot_interfaces2__msg__MyArucoCoords * msg);

/// Create msg/MyArucoCoords message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mycobot_interfaces2__msg__MyArucoCoords__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mycobot_interfaces2
mycobot_interfaces2__msg__MyArucoCoords *
mycobot_interfaces2__msg__MyArucoCoords__create();

/// Destroy msg/MyArucoCoords message.
/**
 * It calls
 * mycobot_interfaces2__msg__MyArucoCoords__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mycobot_interfaces2
void
mycobot_interfaces2__msg__MyArucoCoords__destroy(mycobot_interfaces2__msg__MyArucoCoords * msg);

/// Check for msg/MyArucoCoords message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mycobot_interfaces2
bool
mycobot_interfaces2__msg__MyArucoCoords__are_equal(const mycobot_interfaces2__msg__MyArucoCoords * lhs, const mycobot_interfaces2__msg__MyArucoCoords * rhs);

/// Copy a msg/MyArucoCoords message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mycobot_interfaces2
bool
mycobot_interfaces2__msg__MyArucoCoords__copy(
  const mycobot_interfaces2__msg__MyArucoCoords * input,
  mycobot_interfaces2__msg__MyArucoCoords * output);

/// Initialize array of msg/MyArucoCoords messages.
/**
 * It allocates the memory for the number of elements and calls
 * mycobot_interfaces2__msg__MyArucoCoords__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mycobot_interfaces2
bool
mycobot_interfaces2__msg__MyArucoCoords__Sequence__init(mycobot_interfaces2__msg__MyArucoCoords__Sequence * array, size_t size);

/// Finalize array of msg/MyArucoCoords messages.
/**
 * It calls
 * mycobot_interfaces2__msg__MyArucoCoords__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mycobot_interfaces2
void
mycobot_interfaces2__msg__MyArucoCoords__Sequence__fini(mycobot_interfaces2__msg__MyArucoCoords__Sequence * array);

/// Create array of msg/MyArucoCoords messages.
/**
 * It allocates the memory for the array and calls
 * mycobot_interfaces2__msg__MyArucoCoords__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mycobot_interfaces2
mycobot_interfaces2__msg__MyArucoCoords__Sequence *
mycobot_interfaces2__msg__MyArucoCoords__Sequence__create(size_t size);

/// Destroy array of msg/MyArucoCoords messages.
/**
 * It calls
 * mycobot_interfaces2__msg__MyArucoCoords__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mycobot_interfaces2
void
mycobot_interfaces2__msg__MyArucoCoords__Sequence__destroy(mycobot_interfaces2__msg__MyArucoCoords__Sequence * array);

/// Check for msg/MyArucoCoords message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mycobot_interfaces2
bool
mycobot_interfaces2__msg__MyArucoCoords__Sequence__are_equal(const mycobot_interfaces2__msg__MyArucoCoords__Sequence * lhs, const mycobot_interfaces2__msg__MyArucoCoords__Sequence * rhs);

/// Copy an array of msg/MyArucoCoords messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mycobot_interfaces2
bool
mycobot_interfaces2__msg__MyArucoCoords__Sequence__copy(
  const mycobot_interfaces2__msg__MyArucoCoords__Sequence * input,
  mycobot_interfaces2__msg__MyArucoCoords__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MYCOBOT_INTERFACES2__MSG__DETAIL__MY_ARUCO_COORDS__FUNCTIONS_H_
