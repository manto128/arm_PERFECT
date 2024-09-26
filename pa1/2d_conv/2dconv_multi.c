/* -*-Mode: C;-*- */

/**BeginCopyright************************************************************
 *
 * $HeadURL$
 * $Id: 85fd4f00e63e8f99862277e21fcdb88da31f9a08 $
 *
 *---------------------------------------------------------------------------
 * Part of PERFECT Benchmark Suite (hpc.pnnl.gov/projects/PERFECT/)
 *---------------------------------------------------------------------------
 *
 * Copyright ((c)) 2014, Battelle Memorial Institute
 * Copyright ((c)) 2014, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * 1. Battelle Memorial Institute (hereinafter Battelle) and Georgia Tech
 *    Research Corporation (GTRC) hereby grant permission to any person
 *    or entity lawfully obtaining a copy of this software and associated
 *    documentation files (hereinafter "the Software") to redistribute
 *    and use the Software in source and binary forms, with or without
 *    modification.  Such person or entity may use, copy, modify, merge,
 *    publish, distribute, sublicense, and/or sell copies of the
 *    Software, and may permit others to do so, subject to the following
 *    conditions:
 * 
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimers.
 * 
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in
 *      the documentation and/or other materials provided with the
 *      distribution.
 * 
 *    * Other than as used herein, neither the name Battelle Memorial
 *      Institute nor Battelle may be used in any form whatsoever without
 *      the express written consent of Battelle.
 * 
 *      Other than as used herein, neither the name Georgia Tech Research
 *      Corporation nor GTRC may not be used in any form whatsoever
 *      without the express written consent of GTRC.
 * 
 *    * Redistributions of the software in any form, and publications
 *      based on work performed using the software should include the
 *      following citation as a reference:
 * 
 *      Kevin Barker, Thomas Benson, Dan Campbell, David Ediger, Roberto
 *      Gioiosa, Adolfy Hoisie, Darren Kerbyson, Joseph Manzano, Andres
 *      Marquez, Leon Song, Nathan R. Tallent, and Antonino Tumeo.
 *      PERFECT (Power Efficiency Revolution For Embedded Computing
 *      Technologies) Benchmark Suite Manual. Pacific Northwest National
 *      Laboratory and Georgia Tech Research Institute, December 2013.
 *      http://hpc.pnnl.gov/projects/PERFECT/
 *
 * 2. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *    FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 *    BATTELLE, GTRC, OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 *    STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 *    OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 **EndCopyright*************************************************************/

/**************************/
/***    UNCLASSIFIED    ***/
/**************************/

/***

  ALL SOURCE CODE PRESENT IN THIS FILE IS UNCLASSIFIED AND IS
  BEING PROVIDED IN SUPPORT OF THE DARPA PERFECT PROGRAM.

  THIS CODE IS PROVIDED AS-IS WITH NO WARRANTY, EXPRESSED, IMPLIED, 
  OR OTHERWISE INFERRED. USE AND SUITABILITY FOR ANY PARTICULAR
  APPLICATION IS SOLELY THE RESPONSIBILITY OF THE IMPLEMENTER. 
  NO CLAIM OF SUITABILITY FOR ANY APPLICATION IS MADE.
  USE OF THIS CODE FOR ANY APPLICATION RELEASES THE AUTHOR
  AND THE US GOVT OF ANY AND ALL LIABILITY.

  THE POINT OF CONTACT FOR QUESTIONS REGARDING THIS SOFTWARE IS:

  US ARMY RDECOM CERDEC NVESD, RDER-NVS-SI (JOHN HODAPP, 
  john.hodapp@us.army.mil), 10221 BURBECK RD, FORT BELVOIR, 
  VA 22060-5806

  THIS HEADER SHALL REMAIN PART OF ALL SOURCE CODE FILES.

 ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "xmem/xmalloc.h"
#include "2d_convolution.h"

// #define printf(...)
// #define fprintf(...)
// #define fflush(...)
#define MAGIC_INSTRUCTION __asm__ __volatile__ ("mov r9, r9");

typedef struct {
  int tid;
  algPixel_t *in;
  algPixel_t *out;
  int nRows;
  int nCols;
  fltPixel_t *filter;
  float normFactor;
  int nFilterRows;
  int nFilterCols;
  algPixel_t *tmpBuf;
} params_t;

void *conv2d_thd (void *params_thd)
{
  params_t *params = (params_t *)params_thd;
  int tid = params->tid;
  algPixel_t *in = params->in;
  algPixel_t *out = params->out;
  int nRows = params->nRows;
  int nCols = params->nCols;
  fltPixel_t *filter = params->filter;
  float normFactor = params->normFactor;
  int nFilterRows = params->nFilterRows;
  int nFilterCols = params->nFilterCols;
  algPixel_t *tmpBuf = params->tmpBuf;
  float sum = 0.0;
  int m = 0, n = 0;
  int i = 0, j = 0;
  int row = 0, col = 0;
  int rowOffset = nFilterRows / 2;
  int colOffset = nFilterCols / 2;
  int rowBegIndex = rowOffset;
  int colBegIndex = colOffset;
  int pxlPos = 0;
  int fltPos = 0;

  for (row = rowBegIndex + (tid * nRows / 4); row < (((tid+1) * nRows / 4) + rowOffset); row++)
  {
    for (col = colBegIndex; col < nCols + colOffset; col++)
    {
      sum = 0;
      m = 0;
      for (i = row - rowOffset; i <= row + rowOffset; i++)
      {
        n = 0;
        for (j = col - colOffset; j <= col + colOffset; j++)
        {
          pxlPos = i * (nCols + nFilterCols) + j;
          fltPos = m * nFilterCols + n;
          sum += ((fltPixel_t) tmpBuf[pxlPos] * filter[fltPos]);
          n++;
        }
        m++;
      }
      out[(row - rowBegIndex) * nCols + (col - colBegIndex)] = (algPixel_t) (sum / normFactor);
    }
  }

  return NULL;
}

int
conv2d (algPixel_t *in, algPixel_t *out, int nRows, int nCols, fltPixel_t *filter, float normFactor, int nFilterRows, int nFilterCols)
{
  // int tid;
  params_t params[4];
  // pthread_t thds[4];
  int row = 0, col = 0;
  int rowOffset = nFilterRows / 2;
  int colOffset = nFilterCols / 2;
  
  algPixel_t *tmpBuf = (algPixel_t *)calloc((nRows + nFilterRows) * (nCols + nFilterCols), sizeof(algPixel_t));
  if (!tmpBuf)
  {
    // fprintf(stderr, "File %s, Line %d, Memory Allocation Error\n", __FILE__, __LINE__);
    return -1;
  }

  for (row = 0; row < nRows; row++)
  {
    {
      memcpy((void *)(tmpBuf + (row + rowOffset) * (nCols + nFilterCols) + colOffset), 
	  (void *)(in + row * nCols), 
	  nCols * sizeof(algPixel_t));
    }
  }
  
  int tid;
  for (tid = 0; tid < 4; tid++) {
    params[tid].tid = tid;
    params[tid].in = in;
    params[tid].out = out;
    params[tid].nRows = nRows;
    params[tid].nCols = nCols;
    params[tid].filter = filter;
    params[tid].normFactor = normFactor;
    params[tid].nFilterRows = nFilterRows;
    params[tid].nFilterCols = nFilterCols;
    params[tid].tmpBuf = tmpBuf;
  }
  
  //LVA_FUNCTION(3, &in[0], &in[nRows * nCols - 1], 0);
  // LVA_FUNCTION(3, (char *)&in[0] + 64, (char *)&in[nRows * nCols - 1] - 64, 0);
  //LVA_FUNCTION(3, &out[0], &out[nRows * nCols - 1], 0);
  //LVA_FUNCTION(3, &tmpBuf[0], &tmpBuf[(nRows + nFilterRows) * (nCols + nFilterCols) - 1], 0);
  // LVA_FUNCTION(3, (char *)&tmpBuf[0] + 64, (char *)&tmpBuf[(nRows + nFilterRows) * (nCols + nFilterCols) - 1] - 64, 0);
  // for (tid = 1; tid < 4; tid++) pthread_create(&thds[tid], NULL, conv2d_thd, &params[tid]);
  MAGIC_INSTRUCTION;
  tid = 1;
  conv2d_thd(&params[0]);
  MAGIC_INSTRUCTION;
  // for (tid = 1; tid < 4; tid++) pthread_join(thds[tid], NULL);
  // LVA_BX_INSTRUCTION;

  free((void *)tmpBuf);

  return 0;
}