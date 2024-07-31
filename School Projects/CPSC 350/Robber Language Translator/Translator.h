#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include "Model.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;


class Translator{

    public:
    Translator();
    ~Translator();
    string translateEnglishWord(string englishWord);
    string translateEnglishSentence(string englishSentence);

    private:
    string englishWordTranslation;
    string englishSentence;
    string englishSentenceTranslation;
    int length;
    char ch;
    char cl;
    string vowels;
    string consanants;
    int sentenceLength;
    string word;
    string punct;




};

#endif