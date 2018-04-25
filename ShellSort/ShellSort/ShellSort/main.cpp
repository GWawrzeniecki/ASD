//
//  main.cpp
//  ShellSort
//
//  Created by Grzegorz Wawrzeniecki on 22.04.2018.
//  Copyright © 2018 Grzegorz Wawrzeniecki. All rights reserved.
//

#include <iostream>
using namespace std;

void show(int * tab, int size){
    cout << endl;
    for (int i = 0; i < size;  i++) {
        cout << tab[i] << " ";
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
   
        while (size > 0) {
            cin >> size;
            
            tab = new int[size];
            for (int i = 0; i < size;  i++) {
                cin >> tab[i];
            }
            
            ShellSort(tab, size);
            show(tab,size );
            delete [] tab;
            
        }
    return 0;
}
