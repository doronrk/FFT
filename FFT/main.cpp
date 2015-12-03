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
    // insert code here...
    cout << "Hello, World!\n";
    vector<float> signal;
    vector<float> result = FFTDoron::FFTDoron::fft(signal);
    return 0;
}
