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

int main(int argc, const char * argv[]) {
    
    int sigArr[] = {1,0,0,0,0,0,0};
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
