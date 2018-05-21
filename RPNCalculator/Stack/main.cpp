//
//  main.cpp
//  Stack
//
//  Created by Grzegorz Wawrzeniecki on 04.05.2018.
//  Copyright © 2018 Grzegorz Wawrzeniecki. All rights reserved.
//

#include<iostream>
#include<cmath>
#include "Stack.hpp"
#include "Calc.hpp"
#define MAX_TAB 200


using namespace std;

int main(int argc,const char*argv[]){
    
    
    Stack* stack=new Stack();
    Calc* calc = new Calc();
    char inputTab[MAX_TAB];
    cin.getline(inputTab,MAX_TAB);//Wczytanie calej lini do tablicy
    char*p=strtok(inputTab," ");//podział lini poprzez spacje
    
    
    cout<<"Wynik"<<endl;
    cout << calc->doCalc(p, stack) << endl;
    
    
    delete stack;
    return 0;
    
}
