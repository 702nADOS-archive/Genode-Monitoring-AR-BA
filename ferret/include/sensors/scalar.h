/**
 * \file   ferret/include/sensors/scalar.h
 * \brief  Functions to operate on the most basic sensors type: scalars.
 *
 * \date   08/11/2005
 * \author Martin Pohlack  <mp26@os.inf.tu-dresden.de>
 * \author Bjoern Doebel   <doebel@tudos.org>
 */
/*
 * (c) 2005-2009 Technische Universität Dresden
 * This file is part of TUD:OS and distributed under the terms of the
 * GNU General Public License 2.
 * Please see the COPYING-GPL-2 file for details.
 */
#ifndef __FERRET_INCLUDE_SENSORS_SCALAR_H_
#define __FERRET_INCLUDE_SENSORS_SCALAR_H_

#include <sensors/common.h>
//#include <types.h>
#include <stdint.h>

/* fixme: - convert data to array
 *        - optionally support word sized data entries for faster access
 */

typedef struct
{
    ferret_common_t header;

    int16_t   low;       // lower bound for valid range
    int16_t   high;      // upper bound for valid range
    int16_t  val_min;   // minimum value put in so far
    int16_t   val_max;   // maximum value put in so far
    long long       val_count; // number of values inserted
    int16_t   val_sum;   // sum of all values inserted
    int16_t   data;      // finally the data itself
}  ferret_scalar_t;

#endif
