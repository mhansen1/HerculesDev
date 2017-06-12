/*
 * This file contains all of the type definitions used for this project. This is done
 * to localize all of them so that any users that happen to use my code will know what
 * I'm defining, so they don't need to do it again, or so that there are no conflicts
 * with types.
 */

#ifndef _TYPE_DEF_H_
#define _TYPE_DEF_H_

#include <stdint.h>

// Define the type used for function pointer
typedef void (*callback)(void);

// C has no boolean type. Need to define it.
enum _bool {
    F = 0,
    T = 1
};
typedef enum _bool bool_t;

// Holds the program structure for the N2HET memory
typedef struct het_memory {
	uint32_t program_field;
	uint32_t control_field;
	uint32_t data_field;
	uint32_t reserved_field;
} het_memory_t;

#endif

