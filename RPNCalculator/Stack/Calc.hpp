//
//  Calc.hpp
//  Stack
//
//  Created by Grzegorz Wawrzeniecki on 11.05.2018.
//  Copyright © 2018 Grzegorz Wawrzeniecki. All rights reserved.
//

#ifndef Calc_hpp
#define Calc_hpp

#include <iostream>
#include "Stack.hpp"
using namespace std;

class Calc{
public:
    int doCalc (char* p,Stack* stack);
    
private:
    const char*  plus = "+";
    const char*  min = "-";
    const char*  multip ="*";
    const char*  div = "/";
    const char* log10s = "log10";
      const char* tans = "tan";
      const char* coss = "cos";
      const char* sins = "sin";
      const char* sqrts = "sqrt";
      const char* abss = "abs";
      const char* pows = "pow";
      const char* logs = "log";
      const char* log2s = "log2";
    
    
    
    
    
};

#endif /* Calc_hpp */
