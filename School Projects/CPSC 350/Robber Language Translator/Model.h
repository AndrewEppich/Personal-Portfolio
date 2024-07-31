#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include <string>

using namespace std;

class Model{

    public:
    Model();
    ~Model();
    string translateSingleConsanant(char in);
    string translateSingleVowel(char in);

    private:
    string vowels;
    string consanants;
    string translatedVowel;
    string translatedConsanant;


};

#endif