#ifndef _IEDLL_H
#define _IEDLL_H

#include "ie.h"

void __stdcall Navigate(CAObjHandle objHandle, char *urlStr);
void __stdcall Navigate2(CAObjHandle seqContext, char *urlStr);

#endif /* _IEDLL_H */
