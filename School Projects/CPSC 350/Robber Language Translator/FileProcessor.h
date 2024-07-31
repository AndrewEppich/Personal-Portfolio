#ifndef FILEPROCESSOR_H
#include "Translator.h"
#include <iostream>
#include <fstream>
using namespace std;


class FileProcessor{

    public:
    FileProcessor();
    ~FileProcessor();
    void processFile();

    private: 
    string line;
    string lineTranslation;



};


#endif