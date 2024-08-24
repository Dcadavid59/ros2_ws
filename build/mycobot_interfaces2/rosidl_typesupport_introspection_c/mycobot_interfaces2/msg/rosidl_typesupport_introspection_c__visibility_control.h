// generated from
// rosidl_typesupport_introspection_c/resource/rosidl_typesupport_introspection_c__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef MYCOBOT_INTERFACES2__MSG__ROSIDL_TYPESUPPORT_INTROSPECTION_C__VISIBILITY_CONTROL_H_
#define MYCOBOT_INTERFACES2__MSG__ROSIDL_TYPESUPPORT_INTROSPECTION_C__VISIBILITY_CONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mycobot_interfaces2 __attribute__ ((dllexport))
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_IMPORT_mycobot_interfaces2 __attribute__ ((dllimport))
  #else
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mycobot_interfaces2 __declspec(dllexport)
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_IMPORT_mycobot_interfaces2 __declspec(dllimport)
  #endif
  #ifdef ROSIDL_TYPESUPPORT_INTROSPECTION_C_BUILDING_DLL_mycobot_interfaces2
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_PUBLIC_mycobot_interfaces2 ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mycobot_interfaces2
  #else
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_PUBLIC_mycobot_interfaces2 ROSIDL_TYPESUPPORT_INTROSPECTION_C_IMPORT_mycobot_interfaces2
  #endif
#else
  #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mycobot_interfaces2 __attribute__ ((visibility("default")))
  #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_IMPORT_mycobot_interfaces2
  #if __GNUC__ >= 4
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_PUBLIC_mycobot_interfaces2 __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_PUBLIC_mycobot_interfaces2
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // MYCOBOT_INTERFACES2__MSG__ROSIDL_TYPESUPPORT_INTROSPECTION_C__VISIBILITY_CONTROL_H_