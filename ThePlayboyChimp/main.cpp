//
//  main.cpp
//  The Playboy Chimp
//
//  Created by Grzegorz Wawrzeniecki on 03.04.2018.
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
    return m;
    
};

int main(int argc, const char * argv[]) {
    
    int ammountChimps = 0;
    int ammountLuchu;
    cin >> ammountChimps;//Ilosc wysokosci szympansic
    int *heightsChimps = new int[ammountChimps];
    
    //Wczytywanie wysokosci szympansic
    for(int i = 0; i < ammountChimps; i++){
        cin >> heightsChimps[i];
    }
    
    cin >> ammountLuchu;//Ilosc wysokosci Luchu
    int *heigthsLuchu = new int[ammountLuchu];
    
    //Wczytywanie wysokosci Luchu
    for(int i = 0; i < ammountLuchu; i++){
        cin >> heigthsLuchu[i];
    }
    
    clock_t start, end;
    
    start = clock();
    for(int i = 0; i < ammountLuchu; i++){//Dla kazdej wysokosci luchu szukamy 2 partnerek
        int index2,index= 0;
        index = szukaj(heightsChimps, ammountChimps, heigthsLuchu[i]);
        index2 = index;
        
        
        //Sprawdzamy czy nie ma powtorzen i przesywamy odpowiednio indeks
        int* begin = &heightsChimps[index-1];
        int* now = &heightsChimps[index];
        
        while (*begin == *now && index >= 0) {
            now--;
            begin--;
            index--;
            
        }
        
        
        //Szukamy pierwszej wysokosci, najwyzsza ze wszystkich ale mniejsza od Luchu
        
        //Jesli jest mniejsza od Luchu to podstawiamy
        if(heightsChimps[index] < heigthsLuchu[i]){
            index = heightsChimps[index];
        }else if (heightsChimps[index] >= heigthsLuchu[i]){//Jesli jest wyzsza od Luchu
            if(index > 0)//Sprawdzamy czy to nie jest pierwszy element
                index = heightsChimps[index-1];//I jesli nie to przypisujemy poprzedni element
            
            if (index <= 0)//Jesli to jest pierwzszy element i nie jest on mniejszy od Luchu ustawiamy na -1
                index = -1;
        }
        //Szukamy drugiej wysokosci, wiekza od Luchu ale najmniejsza z nich wszystkich
        
        begin = &heightsChimps[index2];
        now = &heightsChimps[index2+1];
        
        //Sprawdzamy czy nie ma powtorzen i przesywamy odpowiednio indeks
        while (*begin == *now && index < ammountChimps) {
            now++;
            begin++;
            index2++;
        }
        
        if(heightsChimps[index2] > heigthsLuchu[i] ){//Jesli jest wieksze od Luchu to podstawiamy
            index2 = heightsChimps[index2];
        }else if(index2 < ammountChimps-1 &&  heightsChimps[index2+1] > heigthsLuchu[i]){//Sprawdzamy czy to nie jest ostatni indeks i czy nastepny jest wiekszy od Luchu
            index2 = heightsChimps[index2+1];//Jesli nie jest to ostatni indeks i jest wiekszy od Luchu przypisujemy do indeksu
        }else{
            index2 = -1;
        }
        
        
        if(index == -1){
            cout << "X";
        }else{
            cout << index;
        }
        cout << " ";
        if (index2 == -1) {
            cout << "X";
        }else{
            cout << index2;
        }
        cout << endl;
        
    }
    end = clock();
    cout << "Time required for execution: "
    << (double)(end-start)/CLOCKS_PER_SEC
    << " seconds." << "\n\n";
    
    
    delete[] heightsChimps;
    delete[] heigthsLuchu;
    return 0;
}
