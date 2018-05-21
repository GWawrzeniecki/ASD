//
//  main.cpp
//  WyszukiwanieBinarne
//
//  Created by Grzegorz Wawrzeniecki on 02.04.2018.
//  Copyright © 2018 Grzegorz Wawrzeniecki. All rights reserved.
//

#include <iostream>
#include <time.h>
using namespace std;

int szukaj(int* tab,int len, int key){
    int l,r,m;
    l = 0;
    r = len -1;
    
    while (l <= r) {
        m = (l + r)/2;
        
        if(tab[m] == key)
            return m;
        
        if(tab[m] > key){
            r = m -1;
        }else{
            l = m + 1;
        }
    }
    
    return -1;// W przypadku nie znalezienia klucza zwracamy -1
};

int RecSzukaj(int* tab,int len, int key, int l, int p){

    if(l > p)
        return -1;

    int m = (l + p)/2;

    if(tab[m] == key) return m;
    
    if(tab[m] > key) return RecSzukaj(tab, len, key, l, m-1);
    else
        return RecSzukaj(tab, len, key, m+1, p);
}

int main(int argc, const char * argv[]) {
    
    int size;
    int key;
    cout<< " Podaj ilosc elementow" << endl;
    cin >> size;
    int *tab = new int[size];
    
    cout << " Podaj elementy tablicy posortowane niemalejaco" << endl;
    for(int i = 0; i < size; i++){
        cin >> tab[i];
    }
    
    cout << " Podaj szukana wartosc " << endl;
    cin >> key;
    
    int index = szukaj(tab, size, key);
    int RecIndex = RecSzukaj(tab, size, key, 0, size-1);
    
    cout << "Szukana wartosc jest pod indexem  = " << index << endl;
    cout << "Rec = " << RecIndex << endl;
    
    delete[] tab;
    return 0;
}
