//
//  FFT.cpp
//  FFT
//
//  Created by Doron Roberts-Kedes on 12/2/15.
//  Copyright (c) 2015 doronrk. All rights reserved.
//

#include "FFT.h"

using namespace std;

namespace FFTDoron
{
    
    void FFTDoron::fft(vector<complex<float>>* signal)
    {
        fftHelper(signal, 0, 1);
    }
    
    void FFTDoron::fftHelper(vector<complex<float>>* signal, int start, int incr)
    {
        //cerr << start << "," << incr << endl;
        long N = signal->size()/incr;
        if (N == 1)
        {
            return;
        }
        /*
        for (int i = 0; i < N; ++i)
        {
            int index = start + i * incr;
            cerr << index << " ";
        }
        cerr << endl;
         */
        fftHelper(signal, start, incr*2);
        fftHelper(signal, start+incr, incr*2);
        for (int i = 0; i < N/2; ++i)
        {
            int index = start + i * incr;
            complex<float> twiddle = exp(-2 * pi * j * (i /(float) N));
            complex<float> t = (*signal)[index];
            (*signal)[index] = t + twiddle * (*signal)[index + N/2];
            (*signal)[index + N/2] = t - twiddle * (*signal)[index + N/2];
        }
    }

    vector<complex<float>> FFTDoron::fftOrig(vector<complex<float>> signal)
    {
        // TODO: invalid argument check
        long N = signal.size();
        vector<complex<float>> spec = vector<complex<float>>(N);
        if (N == 1)
        {
            spec[0] = signal[0];
            return spec;
        }
        vector<complex<float>> even = vector<complex<float>>(N/2);
        vector<complex<float>> odd = vector<complex<float>>(N/2);
        for (int i = 0; i < N; ++i)
        {
            if (i % 2 == 0)
            {
                even[i/2] = signal[i];
            }
            else
            {
                odd[(i-1)/2] = signal[i];
            }
        }
        even = fftOrig(even);
        odd = fftOrig(odd);
        for (int i = 0; i < N/2; ++i)
        {
            spec[i] = even[i];
            spec[i + N/2] = odd[i];
        }
        for (int i = 0; i < N/2; ++i)
        {
            complex<float> twiddle = exp(-2 * pi * j * (i /(float) N));
            complex<float> t = spec[i];
            spec[i] = t + twiddle * spec[i + N/2];
            spec[i + N/2] = t - twiddle * spec[i + N/2];
        }
        return spec;
    }
}