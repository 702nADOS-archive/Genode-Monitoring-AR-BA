#include <stdint.h>

typedef int16_t  ferret_time_t;
typedef uint16_t ferret_utime_t;
typedef unsigned short l4_cap_idx_t;
typedef l4_cap_idx_t l4re_ds_t;

enum SensorType
{
	FERRET_UNDEFINED = 0,
	FERRET_SCALAR    = 1,
	FERRET_HISTO     = 2,
	FERRET_HISTO_2D  = 3,
	FERRET_LIST      = 4,
	FERRET_TBUF      = 5,
	FERRET_HISTO64   = 6,
};
