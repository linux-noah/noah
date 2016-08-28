#ifndef ZZIP_WARNING
#define ZZIP_WARNING 1
#ifdef __GNUC__
#warning do no not use <zzip-io.h>, update to include <zzip/plugin.h>
#else
#error   do no not use <zzip-io.h>, update to include <zzip/plugin.h>
#endif
#endif
#include "zzip/plugin.h"
