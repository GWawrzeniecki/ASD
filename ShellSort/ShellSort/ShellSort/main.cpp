//
//  main.cpp
//  ShellSort
//
//  Created by Grzegorz Wawrzeniecki on 22.04.2018.
//  Copyright © 2018 Grzegorz Wawrzeniecki. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

void show(int * tab, int size){
    printf("\n");
    for (int i = 0; i < size;  i++) {
        
        printf("%d", tab[i]);
        printf("%s", " ");
        
    
}
}
void ShellSort(int *tab, int size){
    for (int gap = size/ 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size;i++) {
            int temp = tab[i];
            int j;
            for (j = i - gap; j>=0 && tab[j] > temp; j -=gap) {
                tab[j + gap] =tab[j];
            }
            
            tab[j+gap] = temp;
        }
    }
}


int main(int argc, const char * argv[]) {
   
    int size = 1;
    int *tab;
   
        while (true) {
            
            scanf("%d", &size);
            if(size == 0){
                return 0;
            }
            tab = new int[size];
            for (int i = 0; i < size;  i++) {
                scanf("%d", &tab[i]);
            }
            
            ShellSort(tab, size);
            show(tab,size );
            delete [] tab;
            
        }
    return 0;
}
