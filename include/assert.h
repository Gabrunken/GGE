#ifndef assert_h_
#define assert_h_

#include <stdlib.h>

#ifdef DEBUG
#include <stdio.h>
#define DEBUG_ASSERT(x, reason)\
{if(!x){printf("Assertion failed on file %s and line %d, reason: %s\n", __FILE__, __LINE__, reason); exit(1);}}
#else
#define ASSERT(x)\
{if(!x){exit(1);}}
#endif

#endif
