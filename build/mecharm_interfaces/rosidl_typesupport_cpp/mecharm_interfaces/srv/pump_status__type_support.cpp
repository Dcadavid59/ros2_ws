// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from mecharm_interfaces:srv/PumpStatus.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "mecharm_interfaces/srv/detail/pump_status__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace mecharm_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _PumpStatus_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PumpStatus_Request_type_support_ids_t;

static const _PumpStatus_Request_type_support_ids_t _PumpStatus_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PumpStatus_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PumpStatus_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PumpStatus_Request_type_support_symbol_names_t _PumpStatus_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, mecharm_interfaces, srv, PumpStatus_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, mecharm_interfaces, srv, PumpStatus_Request)),
  }
};

typedef struct _PumpStatus_Request_type_support_data_t
{
  void * data[2];
} _PumpStatus_Request_type_support_data_t;

static _PumpStatus_Request_type_support_data_t _PumpStatus_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PumpStatus_Request_message_typesupport_map = {
  2,
  "mecharm_interfaces",
  &_PumpStatus_Request_message_typesupport_ids.typesupport_identifier[0],
  &_PumpStatus_Request_message_typesupport_symbol_names.symbol_name[0],
  &_PumpStatus_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PumpStatus_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PumpStatus_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace mecharm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<mecharm_interfaces::srv::PumpStatus_Request>()
{
  return &::mecharm_interfaces::srv::rosidl_typesupport_cpp::PumpStatus_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, mecharm_interfaces, srv, PumpStatus_Request)() {
  return get_message_type_support_handle<mecharm_interfaces::srv::PumpStatus_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "mecharm_interfaces/srv/detail/pump_status__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mecharm_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _PumpStatus_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PumpStatus_Response_type_support_ids_t;

static const _PumpStatus_Response_type_support_ids_t _PumpStatus_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PumpStatus_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PumpStatus_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PumpStatus_Response_type_support_symbol_names_t _PumpStatus_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, mecharm_interfaces, srv, PumpStatus_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, mecharm_interfaces, srv, PumpStatus_Response)),
  }
};

typedef struct _PumpStatus_Response_type_support_data_t
{
  void * data[2];
} _PumpStatus_Response_type_support_data_t;

static _PumpStatus_Response_type_support_data_t _PumpStatus_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PumpStatus_Response_message_typesupport_map = {
  2,
  "mecharm_interfaces",
  &_PumpStatus_Response_message_typesupport_ids.typesupport_identifier[0],
  &_PumpStatus_Response_message_typesupport_symbol_names.symbol_name[0],
  &_PumpStatus_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PumpStatus_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PumpStatus_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace mecharm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<mecharm_interfaces::srv::PumpStatus_Response>()
{
  return &::mecharm_interfaces::srv::rosidl_typesupport_cpp::PumpStatus_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, mecharm_interfaces, srv, PumpStatus_Response)() {
  return get_message_type_support_handle<mecharm_interfaces::srv::PumpStatus_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "mecharm_interfaces/srv/detail/pump_status__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mecharm_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _PumpStatus_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PumpStatus_type_support_ids_t;

static const _PumpStatus_type_support_ids_t _PumpStatus_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PumpStatus_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PumpStatus_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PumpStatus_type_support_symbol_names_t _PumpStatus_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, mecharm_interfaces, srv, PumpStatus)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, mecharm_interfaces, srv, PumpStatus)),
  }
};

typedef struct _PumpStatus_type_support_data_t
{
  void * data[2];
} _PumpStatus_type_support_data_t;

static _PumpStatus_type_support_data_t _PumpStatus_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PumpStatus_service_typesupport_map = {
  2,
  "mecharm_interfaces",
  &_PumpStatus_service_typesupport_ids.typesupport_identifier[0],
  &_PumpStatus_service_typesupport_symbol_names.symbol_name[0],
  &_PumpStatus_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t PumpStatus_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PumpStatus_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace mecharm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<mecharm_interfaces::srv::PumpStatus>()
{
  return &::mecharm_interfaces::srv::rosidl_typesupport_cpp::PumpStatus_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp
