//
//  main.cpp
//  FFT
//
//  Created by Doron Roberts-Kedes on 12/2/15.
//  Copyright (c) 2015 doronrk. All rights reserved.
//

#include <iostream>
#include "FFT.h"

using namespace std;

int main(int argc, const char * argv[])
{
    complex<float> j (0.0, 1.0);
    //int sigArr[] = {1,0,0,0,0,0,0,0};
    //int sigArr[] = {0,1,2,3,4,5,6,7};
    //float sigArr[] = {.1, .5, .1, .2, -.3, -.9, .4, .15};
    complex<float> sigArr[] = {j*=3, .5, .1, .2, -.3, -.9, .4, .15};
    vector<complex<float>> signal;
    for (int i = 0; i < 8; ++i)
    {
        signal.push_back(sigArr[i]);
    }
    vector<complex<float>> result = FFTDoron::FFTDoron::fft(signal);
    for (int i = 0; i < signal.size(); i++)
    {
        cout << "result: " << result[i] << endl;
    }
    return 0;
}
