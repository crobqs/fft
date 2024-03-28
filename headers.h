#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <errno.h>
#include <assert.h>
#include <fcntl.h>
#include <stdint.h>
#include <limits.h>
#include <pthread.h>
#include <complex.h>
#include <sys/queue.h>

#define BTOS(var__) (const char*)((var__) ? "true" : "false")
#define PRINT_CMPLX(var__) { float complex t__ = (var__); printf("%g + %g\n", crealf(t__), cimagf(t__)); }
#define ISWHOLE(var__) (bool)(((float)var__ - (float)((int)(var__))) == .0f)