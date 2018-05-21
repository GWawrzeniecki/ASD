//
//  Calc.cpp
//  Stack
//
//  Created by Grzegorz Wawrzeniecki on 11.05.2018.
//  Copyright © 2018 Grzegorz Wawrzeniecki. All rights reserved.
//

#include "Calc.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int Calc::doCalc(char *p,Stack* stack){
    while(p!=nullptr){
       
       
        if (!(isdigit(*p)) && (*p != *plus && *p != *min && *p != * multip && *p != *div) && !(strlen(p) > 0)){
            cout << " Podales litere lub nie obslugiwany znak " << *p  << endl;
            cout << " Program zakonczy dzialanie " << endl;
            exit(0);
        }
        
        switch(*p){
                double a;
                double b;
            case '+':
                stack->push(stack->pop()+stack->pop());
                break;
            case'-':
                stack->push(stack->pop()-stack->pop());
                break;
            case'/':
                a = stack->pop();
                b = stack->pop();
                if (b != 0) {
                    stack->push(a/b);
                }else{
                    cout << "Nie dziel przez 0" << endl;
                    exit(0);
                }
                
                break;
            case '*':
                stack->push(stack->pop()*stack->pop());
                break;
            case '!':
                stack->push(stack->silnia(stack->pop()));
                break;
            default:
                break;
        }
        
        
        if(strcmp(p,log10s)==0){//strcmp porownuje lancuchy znakow, jesli sa takie same zwraca 0
            stack->push(log10(stack->pop()));
        }else if(strcmp(p,tans)==0){
            stack->push(tan(stack->pop()));
        }else if(strcmp(p,coss)==0){
            stack->push(cos(stack->pop()));
        }else if(strcmp(p,sins)==0){
            stack->push(sin(stack->pop()));
        }else if(strcmp(p,sqrts)==0){
            stack->push(sqrt(stack->pop()));
        }else if(strcmp(p,abss)==0){
            stack->push(abs(stack->pop()));
        }else if(strcmp(p,pows)==0){
                stack->push(pow(stack->pop(),stack->pop()));
        }else if(strcmp(p,logs) == 0){
            stack->push(log(stack->pop()));
        }else if(strcmp(p,log2s) == 0){
            stack->push(log2(stack->pop()));
        }
        
        if(isdigit(*p)){//Jesli jest liczba
        double dig1 = atof(p);//to wyciagamy wartosc double
        stack->push(dig1);
        }
        
        p=strtok(NULL," ");//Wyciagamy kolejny element
        
    }
    return stack->pop();
}
