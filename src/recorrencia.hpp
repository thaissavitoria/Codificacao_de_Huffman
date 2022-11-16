#ifndef RECORRENCIA_HPP
#define RECORRENCIA_HPP

#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;


class Token
{
public:
    vector<string>Arquivo;///palavras ja tokenizadas
    map<string, int> StpWrds;///Stop Words
    map<string,int> ArquivoSemStp; /// Arquivo sem stop words
    map<string, float> Hash; ///Arquivo em stop words e com o calculo do normalizaw

    void readFile();
    void preencheStpW();
    void removeStpW(vector<string>&arq);
    void mapWords(map<string,float>&Hash); 
    void imprimirMap();///se necessário imprimir o map já sem as stop words
    float maxMin();///pega rp maximo e minimo
};

#endif