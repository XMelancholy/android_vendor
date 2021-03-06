/* **************************************************************************
 *
 * cspsa_ll_file.h
 *
 * Copyright (C) 2010 ST-Ericsson SA
 *
 * This software is released either under the terms of the BSD-style
 * license accompanying CSPSA or a proprietary license obtained from
 * ST-Ericsson SA.
 *
 * Author: 2010, Louis Verhaard <louis.xl.verhaard@stericsson.com>
 *
 * DESCRIPTION:
 *
 * Low level interface to handle CSPSA stored on file.
 *
 **************************************************************************** */

// =============================================================================
#ifndef INCLUSION_GUARD_CSPSA_LL_FILE_H
#define INCLUSION_GUARD_CSPSA_LL_FILE_H
// =============================================================================

// =============================================================================
//  Configurations
// =============================================================================

// =============================================================================
//  Include Header Files
// =============================================================================

#include "cspsa.h"

// =============================================================================
//  Defines
// =============================================================================

// =============================================================================
//  Macros
// =============================================================================

// =============================================================================
//  Types
// =============================================================================

// =============================================================================
//  Global Function Declarations
// =============================================================================

/**
 * Registers the LL File functions to CSPSA.
 */
CSPSA_Result_t CSPSA_LL_FILE_Init(void);

// =============================================================================
#endif // INCLUSION_GUARD_CSPSA_LL_FILE_H
// =============================================================================
