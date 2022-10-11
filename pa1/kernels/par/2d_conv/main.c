/* -*-Mode: C;-*- */

/**BeginCopyright************************************************************
 *
 * $HeadURL$
 * $Id: 3824146209f01fefa9a42b92b431ccda926f23c6 $
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

// #include "bareBench.h"
#include "input_array_xs.h"
// #include "out_xs.h"
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
//#include <time.h>

//#include "timer.h"

//#include "xmem/xmalloc.h"
//#include "octave.h"
#include "2d_convolution.h"

//#if !defined(BATCH_SIZE)
#define BATCH_SIZE (1)
//#endif

#if 1
#define M 64  /* columns */
#define N 48  /* rows */
#define FILENAME "../../../input/input_small.mat"
#define SIZE "small"

#elif INPUT_SIZE == INPUT_SIZE_SMALL
#define M 640  /* columns */
#define N 480  /* rows */
#define FILENAME "../../../input/input_small.mat"
#define SIZE "small"

#elif INPUT_SIZE == INPUT_SIZE_MEDIUM
#define M 1920  /* columns */
#define N 1080  /* rows */
#define FILENAME "../../../input/input_medium.mat"
#define SIZE "medium"

#elif INPUT_SIZE == INPUT_SIZE_LARGE
#define M 3840  /* columns */
#define N 2160  /* rows */
#define FILENAME "../../../input/input_large.mat"
#define SIZE "large"

#else
#error "Unhandled value for INPUT_SIZE"
#endif



int main (int argc, char * argv[])
{
  int * frame;
  int * output;
  int i, j;

  int nFilterRowsFD = 9; 
  int nFilterColsFD = 9;

	  
  fltPixel_t FD[] =  {
			 1,   3,   4,   5,   6,   5,  4,    3,  1,
			 3,   9,  12,  15,  18,  15,  12,   9,  3,
			 4,  12,  16,  20,  24,  20,  16,  12,  4,
			 5,  15,  20,  25,  30,  25,  20,  15,  5,
			 6,  18,  24,  30,  36,  30,  24,  18,  6,
			 5,  15,  20,  25,  30,  25,  20,  15,  5,
			 4,  12,  16,  20,  24,  20,  16,  12,  4,
			 3,   9,  12,  15,  18,  15,  12,   9,  3,
			 1,   3,   4,   5,   6,   5,   4,   3,  1
  };

 
  for (i = 0; i < nFilterRowsFD * nFilterColsFD; i++)
  {
    FD[i] /= (1024.0);
  }

  //ABSO TODO : seed with known val
  //srand (time (NULL));

  //STATS_INIT ();  //updated to dummy
  //PRINT_STAT_STRING ("kernel", "2d_convolution");
  //PRINT_STAT_INT ("rows", N);
  //PRINT_STAT_INT ("columns", M);
  //PRINT_STAT_INT ("num_frames", BATCH_SIZE);

  frame = calloc (M * N * BATCH_SIZE, sizeof(algPixel_t));
  output = calloc (M * N * BATCH_SIZE, sizeof(algPixel_t));

  if (!frame || !output) {
    // fprintf(stderr, "ERROR: Allocation failed.\n");
    exit(-1);
  }

  /* load image */
  //tic ();

  //printf("Starting read array  \n");
  //read_array_from_octave (frame, N, M, FILENAME);
  memcpy(frame, inp_data, M * N * sizeof(algPixel_t));
  // FILE *f = fopen("input_array.h", "w");
  
  // if(f == NULL)
  // {
  //     printf("Error: File error\n");
  // }

  // int r,c;
  // for(r=0; r<N; r++)
  // {
  //   for(c=0; c<M; c++)
  //   {
  //       fprintf(f, "%d", frame[r*N+c]);
  //       fprintf(f, "%s", ",");
  //       fprintf(f, "%s", " ");
  //   }
  //   fprintf(f, "%s", "\n");
  // }
  // fclose(f);

  //PRINT_STAT_DOUBLE ("time_load_image", toc ());

  /* Make BATCH_SIZE-1 copies */
  //tic ();
  // for (i = 1; i < BATCH_SIZE; i++) {
  //   memcpy (&frame[i * M * N], frame, M * N * sizeof(algPixel_t));
  // }
  //PRINT_STAT_DOUBLE ("time_copy", toc ());

  /* Perform the 2D convolution */
  //tic ();

  // __asm__ __volatile__("mov r9, r9");
  for (i = 0; i < BATCH_SIZE; i++) {
    conv2d (&frame[i * M * N], &output[i * M * N], N, M, FD, 1.0, nFilterRowsFD, nFilterColsFD);
  }
  // __asm__ __volatile__("mov r9, r9");
  //PRINT_STAT_DOUBLE ("time_2d_convolution", toc ());

  /* Write the results out to disk */
  //for (i = 0; i < BATCH_SIZE; i++) {
    //char buffer [30];
    //sprintf (buffer, "2dconv_output." SIZE ".%d.mat", i);
    //write_array_to_octave (&output[i * M * N], N, M, buffer, "output");
  //}
  //PRINT_STAT_STRING ("output_file", "2dconv_output." SIZE ".#.mat");

  //STATS_END ();

  //int flag = 1;


  //check correctness
  // for(i=0; i<N; i++)
  // {
  //  for(j=0; j<M; j++)
  //  {
  //      printf("%d ", output[i*M + j]);
  //  }
  //  printf("\n");
  // }

  
  free (output);
  free (frame);

  return 0;
}

