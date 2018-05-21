//
//  Stack.cpp
//  Stack
//
//  Created by Grzegorz Wawrzeniecki on 11.05.2018.
//  Copyright © 2018 Grzegorz Wawrzeniecki. All rights reserved.
//


#include "Stack.hpp"
#include <iostream>
#define MAX_TAB 200;

using namespace std;

void Stack::push(double element){
    if (i < 200) {//jesli stos nie jest przepełniony
        stack[i] = element;
        i++;
    } else {
        cout << "Stack is full" << endl;
    }
}

int Stack::pop(){
    if (i > 0)// Jesli stos nie jest pusty
        return stack[--i];
    
    cout << " Podales za malo wartosci" << endl;
    cout << " Program zakonczy dzialanie " << endl;
    exit(0);
}

int Stack::silnia(int k){
    int result = 1;
    
    for (int i = 1; i<=k;i++)
        result*= i;
    
    return result;
}

int Stack::getSize(){
    return i;
}
