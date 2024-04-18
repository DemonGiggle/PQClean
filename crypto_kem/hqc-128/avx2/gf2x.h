#ifndef GF2X_H
#define GF2X_H


/**
 * @file gf2x.h
 * @brief Header file for gf2x.c
 */

#include <immintrin.h>
#include <stdint.h>

void PQCLEAN_HQC128_AVX2_vect_mul(__m256i *o, const __m256i *v1, const __m256i *v2);


#endif
