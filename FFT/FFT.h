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

using namespace std;

namespace FFTDoron
{
    class FFTDoron
    {
    public:
        static vector<float> fft(vector<float> signal);
    };
}

#endif /* defined(__FFT__FFT__) */
