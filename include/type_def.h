/*
 * File that contains the type definitions for the modules that are developed in this project
 */

#ifndef _TYPE_DEF_H_
#define _TYPE_DEF_H_

// Define the type used for function pointer
typedef void (*callback)(void);

// C has no boolean type. Need to define it.
enum _bool {
    F = 0,
    T = 1
};
typedef enum _bool bool_t;

#endif

