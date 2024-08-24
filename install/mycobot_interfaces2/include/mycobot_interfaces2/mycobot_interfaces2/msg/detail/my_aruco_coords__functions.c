// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mycobot_interfaces2:msg/MyArucoCoords.idl
// generated code does not contain a copyright notice
#include "mycobot_interfaces2/msg/detail/my_aruco_coords__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
mycobot_interfaces2__msg__MyArucoCoords__init(mycobot_interfaces2__msg__MyArucoCoords * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // distance
  // x
  // y
  // z
  // rx
  // ry
  // rz
  return true;
}

void
mycobot_interfaces2__msg__MyArucoCoords__fini(mycobot_interfaces2__msg__MyArucoCoords * msg)
{
  if (!msg) {
    return;
  }
  // id
  // distance
  // x
  // y
  // z
  // rx
  // ry
  // rz
}

bool
mycobot_interfaces2__msg__MyArucoCoords__are_equal(const mycobot_interfaces2__msg__MyArucoCoords * lhs, const mycobot_interfaces2__msg__MyArucoCoords * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // distance
  if (lhs->distance != rhs->distance) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // rx
  if (lhs->rx != rhs->rx) {
    return false;
  }
  // ry
  if (lhs->ry != rhs->ry) {
    return false;
  }
  // rz
  if (lhs->rz != rhs->rz) {
    return false;
  }
  return true;
}

bool
mycobot_interfaces2__msg__MyArucoCoords__copy(
  const mycobot_interfaces2__msg__MyArucoCoords * input,
  mycobot_interfaces2__msg__MyArucoCoords * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // distance
  output->distance = input->distance;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // rx
  output->rx = input->rx;
  // ry
  output->ry = input->ry;
  // rz
  output->rz = input->rz;
  return true;
}

mycobot_interfaces2__msg__MyArucoCoords *
mycobot_interfaces2__msg__MyArucoCoords__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces2__msg__MyArucoCoords * msg = (mycobot_interfaces2__msg__MyArucoCoords *)allocator.allocate(sizeof(mycobot_interfaces2__msg__MyArucoCoords), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mycobot_interfaces2__msg__MyArucoCoords));
  bool success = mycobot_interfaces2__msg__MyArucoCoords__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mycobot_interfaces2__msg__MyArucoCoords__destroy(mycobot_interfaces2__msg__MyArucoCoords * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mycobot_interfaces2__msg__MyArucoCoords__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mycobot_interfaces2__msg__MyArucoCoords__Sequence__init(mycobot_interfaces2__msg__MyArucoCoords__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces2__msg__MyArucoCoords * data = NULL;

  if (size) {
    data = (mycobot_interfaces2__msg__MyArucoCoords *)allocator.zero_allocate(size, sizeof(mycobot_interfaces2__msg__MyArucoCoords), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mycobot_interfaces2__msg__MyArucoCoords__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mycobot_interfaces2__msg__MyArucoCoords__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mycobot_interfaces2__msg__MyArucoCoords__Sequence__fini(mycobot_interfaces2__msg__MyArucoCoords__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mycobot_interfaces2__msg__MyArucoCoords__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mycobot_interfaces2__msg__MyArucoCoords__Sequence *
mycobot_interfaces2__msg__MyArucoCoords__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces2__msg__MyArucoCoords__Sequence * array = (mycobot_interfaces2__msg__MyArucoCoords__Sequence *)allocator.allocate(sizeof(mycobot_interfaces2__msg__MyArucoCoords__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mycobot_interfaces2__msg__MyArucoCoords__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mycobot_interfaces2__msg__MyArucoCoords__Sequence__destroy(mycobot_interfaces2__msg__MyArucoCoords__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mycobot_interfaces2__msg__MyArucoCoords__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mycobot_interfaces2__msg__MyArucoCoords__Sequence__are_equal(const mycobot_interfaces2__msg__MyArucoCoords__Sequence * lhs, const mycobot_interfaces2__msg__MyArucoCoords__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mycobot_interfaces2__msg__MyArucoCoords__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mycobot_interfaces2__msg__MyArucoCoords__Sequence__copy(
  const mycobot_interfaces2__msg__MyArucoCoords__Sequence * input,
  mycobot_interfaces2__msg__MyArucoCoords__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mycobot_interfaces2__msg__MyArucoCoords);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mycobot_interfaces2__msg__MyArucoCoords * data =
      (mycobot_interfaces2__msg__MyArucoCoords *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mycobot_interfaces2__msg__MyArucoCoords__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mycobot_interfaces2__msg__MyArucoCoords__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mycobot_interfaces2__msg__MyArucoCoords__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
