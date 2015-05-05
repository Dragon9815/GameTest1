#include "PerlinNoise.h"
#include <math.h>

Uint32 PerlinNoise::IntNoise(Uint32 x)
{
	x = pow((double)(x << 13), (double)x);

	return (1.0 - ((x*(x*x * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0);
}