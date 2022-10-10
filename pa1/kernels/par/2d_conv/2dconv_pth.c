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
#include <pthread.h>

//#include "xmem/xmalloc.h"
#include "2d_convolution.h"

// #define printf(...)
// #define fprintf(...)
// #define fflush(...)

struct indices{
    int curr_row;
    int curr_col;
};

algPixel_t *tmpBuf;

void* multiply_accumulate(void* index)
{
  float sum = 0.0;
  int m = 0, n = 0;
  struct indices* curr_index = (struct indices* )index;
  int row = curr_index->curr_row;
  int col = curr_index->curr_col;
  int rowOffset = nFilterRowsFD / 2;
  int colOffset = nFilterColsFD / 2;
  int rowBegIndex = rowOffset;
  int colBegIndex = colOffset;
  int pxlPos = 0;
  int fltPos = 0;

  for (int i = row - rowOffset; i <= row + rowOffset; i++)
  {
    n = 0;
    for (int j = col - colOffset; j <= col + colOffset; j++)
    {
      pxlPos = i * (N + nFilterColsFD) + j;
      fltPos = m * nFilterColsFD + n;
      sum += ((fltPixel_t) tmpBuf[pxlPos] * FD[fltPos]);
      n++;
    }
    m++;
  }
  output[(row - rowBegIndex) * N + (col - colBegIndex)] = (algPixel_t) (sum);

  return NULL;
}

int
conv2d ()
{
  // float sum = 0.0;
  // int m = 0, n = 0;
  // int i = 0, j = 0;
  // int row = 0, col = 0;
  int rowOffset = nFilterRowsFD / 2;
  int colOffset = nFilterColsFD / 2;
  int rowBegIndex = rowOffset;
  int colBegIndex = colOffset;
  // int pxlPos = 0;
  // int fltPos = 0;

  tmpBuf = (algPixel_t *)calloc((M + nFilterRowsFD) * (N + nFilterColsFD), sizeof(algPixel_t));
  // if (!tmpBuf)
  // {
  //   fprintf(stderr, "File %s, Line %d, Memory Allocation Error\n", __FILE__, __LINE__);
  //   return -1;
  // }

  for (int row = 0; row < M; row++)
  {
    {
      memcpy((void *)(tmpBuf + (row + rowOffset) * (N + nFilterColsFD) + colOffset), 
	  (void *)(frame + row * N), N * sizeof(algPixel_t));
    }
  }

  pthread_t thread_id[M][N];

  for (int row = rowBegIndex; row < M + rowOffset; row++)
  {
    for (int col = colBegIndex; col < N + colOffset; col++)
    {
      struct indices index = {row, col};
      pthread_create(&thread_id[row][col], NULL, multiply_accumulate, (void* )&index);
    }
      // __asm__("nop");
  }

  pthread_exit(NULL);

  free((void *)tmpBuf);

  return 0;
}