/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 1994 by Waldorf Electronics
 * Copyright (C) 1995 - 2000, 01, 03 by Ralf Baechle
 * Copyright (C) 1999, 2000 Silicon Graphics, Inc.
 */
#ifndef _ASM_DELAY_H
#define _ASM_DELAY_H

#include <linux/param.h>

extern void __delay(unsigned int loops);
extern void __ndelay(unsigned int ns);
extern void __udelay(unsigned int us);

#define ndelay(ns) __ndelay(ns)
#ifdef CONFIG_TANGOX
void tangox_udelay(unsigned us);
#define udelay(us) tangox_udelay(us)
#else
#define udelay(us) __udelay(us)
#endif

/* make sure "usecs *= ..." in udelay do not overflow. */
#if HZ >= 1000
#define MAX_UDELAY_MS	1
#elif HZ <= 200
#define MAX_UDELAY_MS	5
#else
#define MAX_UDELAY_MS	(1000 / HZ)
#endif

#endif /* _ASM_DELAY_H */
