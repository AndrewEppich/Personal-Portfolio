#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H
#include <fstream>
#include <string>
#include "Stack.h"
#include <iostream>

using namespace std;

class SpeakerView{

    public:
    SpeakerView(string inputFileName);
    virtual ~SpeakerView();
    void mainPart();
    void computeOutput();
    void printResults();

    private:
    ifstream reader;
    int m_lines;
    int m_width;
    Stack** myArray;
    string m_inputFileName;
    void readFileLines();
    void readFileWidth();
    void readFileDimensions();
    double **createColumnGrid();
    void populateStacks(double **grid);

};


#endif