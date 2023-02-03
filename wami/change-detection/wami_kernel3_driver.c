/* -*-Mode: C;-*- */

/**BeginCopyright************************************************************
 *
 * $HeadURL$
 * $Id: 11dcfc83dec2b02b0c1cde73d71def759ccc0525 $
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
#include <assert.h>

#include "../lib/wami_params.h"
#include "../lib/wami_utils.h"
#include "wami_gmm.h"
#include "wami_morpho.h"
#include "means.h"
#include "variances.h"
#include "weights.h"

int main(int argc, char **argv)
{
    float (*mu)[WAMI_GMM_IMG_NUM_COLS][WAMI_GMM_NUM_MODELS] = NULL;
    float (*sigma)[WAMI_GMM_IMG_NUM_COLS][WAMI_GMM_NUM_MODELS] = NULL;
    float (*weights)[WAMI_GMM_IMG_NUM_COLS][WAMI_GMM_NUM_MODELS] = NULL;
    u8 (*foreground)[WAMI_GMM_IMG_NUM_ROWS][WAMI_GMM_IMG_NUM_COLS] = NULL;
    u8 (*morph)[WAMI_GMM_IMG_NUM_COLS] = NULL;
    u16 (*frames)[WAMI_GMM_IMG_NUM_ROWS][WAMI_GMM_IMG_NUM_COLS] = NULL;

    const size_t num_pixels = WAMI_GMM_IMG_NUM_ROWS * WAMI_GMM_IMG_NUM_COLS;

    mu = XMALLOC(sizeof(float) * num_pixels * WAMI_GMM_NUM_MODELS);
    sigma = XMALLOC(sizeof(float) * num_pixels * WAMI_GMM_NUM_MODELS);
    weights = XMALLOC(sizeof(float) * num_pixels * WAMI_GMM_NUM_MODELS);
    foreground = XMALLOC(sizeof(u8) * num_pixels * WAMI_GMM_NUM_FRAMES);
    morph = XMALLOC(sizeof(u8) * num_pixels);
    frames = XMALLOC(sizeof(u16) * num_pixels * WAMI_GMM_NUM_FRAMES);

    memset(mu, 0, sizeof(float) * num_pixels * WAMI_GMM_NUM_MODELS);
    memset(sigma, 0, sizeof(float) * num_pixels * WAMI_GMM_NUM_MODELS);
    memset(weights, 0, sizeof(float) * num_pixels * WAMI_GMM_NUM_MODELS);
    memset(foreground, 0, sizeof(u8) * num_pixels * WAMI_GMM_NUM_FRAMES);
    memset(morph, 0, sizeof(u8) * num_pixels);
    memset(frames, 0, sizeof(u16) * num_pixels * WAMI_GMM_NUM_FRAMES);

    for (int i = 0; i < WAMI_GMM_IMG_NUM_COLS; i++) {
        for(int j = 0; j < WAMI_GMM_NUM_MODELS; j++) {
            (*mu)[i][j] = means[i][j];
            (*sigma)[i][j] = variances[i][j];
            (*weights)[i][j] = weight_data[i][j];
        }
    }

    for (int i = 0; i < WAMI_GMM_NUM_FRAMES; ++i)
    {
        wami_gmm(
            (u8 (*)[WAMI_GMM_IMG_NUM_COLS]) &foreground[i][0][0],
            mu,
            sigma,
            weights,
            (u16 (*)[WAMI_GMM_IMG_NUM_COLS]) &frames[i][0][0]);
    }

    FREE_AND_NULL(mu);
    FREE_AND_NULL(sigma);
    FREE_AND_NULL(weights);
    FREE_AND_NULL(foreground);
    FREE_AND_NULL(morph);
    FREE_AND_NULL(frames);

    return 0;
}
