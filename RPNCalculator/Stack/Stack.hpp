//
//  Stack.hpp
//  Stack
//
//  Created by Grzegorz Wawrzeniecki on 11.05.2018.
//  Copyright © 2018 Grzegorz Wawrzeniecki. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#define MAX_TAB 200;
#include <iostream>

class Stack{
private:
    double stack[200];///Tablica o stalej wielkosci 200,
    int i = 0;//Indeks
public:
    void push(double element);
    int pop();
    int silnia(int k);
    int getSize();
};
#endif /* Calc_hpp */
