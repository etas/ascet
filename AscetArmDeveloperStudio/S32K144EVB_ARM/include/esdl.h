/**
 * Copyright ETAS GmbH, Stuttgart, Germany. All rights reserved.
 *
 * esdl.h is the main header file of the generated model code.
 * It provides:
 *  # definition of standard C types
 *  # type limits
 *  # interfaces for operating system services
 */
#ifndef ESDL_H
#define ESDL_H

/* compatibility level of the ESDL header files */
#define ESDL_HEADER_VERSION (4)

/* callback to user defined types, declarations etc. */
#include "esdl_usercfg.h"

/* operating system/scheduling related services */
#include "esdl_mutex.h"

/* C base types used in generated code */
#if defined(ESDL_AUTOSAR_USE_RTE_TYPE)
    /* Access AUTOSAR types through the RTE header */
    #include "Rte_Type.h"
    /* Map internal boolean values true/false to AUTOSAR standard values TRUE/FALSE */
    #ifndef false
        #define false FALSE
    #endif
    #ifndef true
        #define true  TRUE
    #endif
#elif defined(ESDL_AUTOSAR_USE_STD_TYPES)
    /* Access AUTOSAR types through the Standard Types header */
    #include "Std_Types.h"
    /* Map internal boolean values true/false to AUTOSAR standard values TRUE/FALSE */
    #ifndef false
        #define false FALSE
    #endif
    #ifndef true
        #define true  TRUE
    #endif
#else
    #if defined(ESDL_CUSTOM_BASE_TYPES)
        /* Use customized base type definitions */
        #include ESDL_CUSTOM_BASE_TYPES
    #else
        /* Use native base type definitions */
        #include "esdl_types.h"
    #endif
#endif

/* C type limits */
#include "esdl_limits.h"

#endif /* ESDL_H */
