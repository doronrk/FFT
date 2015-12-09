//
//  FFT.h
//  FFT
//
//  Created by Doron Roberts-Kedes on 12/2/15.
//  Copyright (c) 2015 doronrk. All rights reserved.
//

#ifndef __FFT__FFT__
#define __FFT__FFT__

#include <stdio.h>
#include <vector>
#include <iostream>
#include <complex>
#include <math.h> 

using namespace std;

namespace FFTDoron
{
    const complex<float> j (0.0, 1.0);
    const float pi = 3.14159265359;
    class FFTDoron
    {
    public:
        static void fft(vector<complex<float>>* signal);
        static void fftHelper(vector<complex<float>>* signal, int start, int incr);
        static vector<complex<float>> fftOrig(vector<complex<float>> signal);
    };
}

#endif /* defined(__FFT__FFT__) */
