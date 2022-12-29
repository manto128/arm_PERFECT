/* -*-Mode: C;-*- */

/**BeginCopyright************************************************************
 *
 * $HeadURL$
 * $Id: e6492e14e55f43a3042be10e2e19617a4b4f195d $
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <time.h>

//#include "../../lib/xmalloc.h"
#include "wami_lucas_kanade.h"
#include "dx.h"
#include "dy.h"

#define M 512  /* columns */
#define N 512  /* rows */


int main (int argc, char * argv[])
{
  /* Warped input gradients */
  fltPixel_t * gradX_warped;
  fltPixel_t * gradY_warped;
  /* Steepest descent */
  fltPixel_t * I_steepest;
  /* Hessian */
  float * H;
  /* Parameter set p */
  float p_in[6];
  /* Warp/ pixel transformation matrix */
  float W_xp[9];

  // gradX = calloc (M * N, sizeof(fltPixel_t));
  // gradY = calloc (M * N, sizeof(fltPixel_t));
  gradX_warped = calloc (M * N, sizeof(fltPixel_t));
  gradY_warped = calloc (M * N, sizeof(fltPixel_t));
  I_steepest = calloc (6 * M * N, sizeof(fltPixel_t));
  H = calloc (6 * 6, sizeof(float));

  if (!gradX_warped || !gradY_warped || !I_steepest || !H) {
    fprintf(stderr, "ERROR: Allocation failed.\n");
    free (gradX_warped);
    free (gradY_warped);
    free (I_steepest);
    free (H);
    exit(-1);
  }

  /* Warp the gradient I with W(x;p) */
  /* p */
  p_in[0] = -0.035;      /* horizontal compression */
  p_in[1] = 0.01;        /* horizontal distortion */
  p_in[2] = -0.01;       /* vertical distortion */
  p_in[3] = -0.035;      /* vertical compression */
  p_in[4] = 5.5;         /* horizontal translation */
  p_in[5] = 5.5;         /* vertical translation */

  /* W(x;p) */
  W_xp[0] = 1.0 + p_in[0];  W_xp[1] = p_in[2];        W_xp[2] = p_in[4];
  W_xp[3] = p_in[1];        W_xp[4] = 1.0 + p_in[3];  W_xp[5] = p_in[5];
  W_xp[6] = 0.0;            W_xp[7] = 0.0;            W_xp[8] = 1.0;

  warp_image (dx, M, N, W_xp, gradX_warped);
  warp_image (dy, M, N, W_xp, gradY_warped);
  
  /* Compute the steepest descent images Gradient * Jacobian */
  steepest_descent (gradX_warped, gradY_warped, M, N, I_steepest);

  /* Compute the Hessian matrix */
  hessian (I_steepest, M, N, 6, H);

  free (gradX_warped);
  free (gradY_warped);
  free (I_steepest);
  free (H);

  return 0;
}





