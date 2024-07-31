#include "Stack.h"
#include "SpeakerView.h"
#include <sstream>
#include <string>

SpeakerView::SpeakerView(string inputFileName){
    m_lines = 0;
    m_width = 0;
    m_inputFileName = inputFileName;
    readFileDimensions();
}

SpeakerView::~SpeakerView(){
    if (reader.is_open()){
        reader.close();
    }
}

void SpeakerView::computeOutput(){
    double** grid = createColumnGrid();
    populateStacks(grid);
}

void SpeakerView::readFileDimensions(){
    readFileLines();
    readFileWidth();
}

void SpeakerView::readFileWidth(){
    try{
        reader.open(m_inputFileName);
    }
    catch(...){
        cout << "Error opening file" << endl;
    }
    if (m_lines == 0){
        return;
    }
    reader.clear();
    reader.seekg(0);
    string line;

    if (getline(reader, line)){

        if (getline(reader, line)){
            istringstream iss(line);
            double number;

            while (iss >> number){
                m_width ++;
            }
        }
    }

}
void SpeakerView::readFileLines(){
    try{
        reader.open(m_inputFileName);
    }
    catch(...){
        cout << "Error opening file" << endl;
    }
    string line;
    if (getline(reader, line)){

        istringstream stream(line);
        string firstWord;
        stream >> firstWord;

        if (firstWord != "BEGIN"){
            cout << "The file does not start with 'BEGIN' " << endl;
            exit(0);
        }
        }
        else{
            cout << "The file is empty" << endl;
            exit(0);
        }

        while (getline(reader, line)){
            if (line == "END"){
                break;
            }
            else{
                m_lines++;
            }
        }

    }

double** SpeakerView::createColumnGrid(){
    if (!reader.is_open())
    {
        reader.open(m_inputFileName);
    }
    reader.clear();
    reader.seekg(0);
    double **grid;
    grid = new double *[m_width];
    for (int i = 0; i < m_width; i++)
    {
        grid[i] = new double[m_lines];
    }
    string line;
    if (getline(reader, line))
    {
        for (int i = m_lines - 1; i >= 0; i--)
        {
            for (int j = m_width - 1; j >= 0; j--)
            {
                double value;
                if (reader >> value)
                {
                    grid[j][i] = value; 
                }
            }
        }
    }

    return grid;
}

void SpeakerView::populateStacks(double** grid){
    myArray = new Stack*[m_width];

    for (int i = 0; i < m_width; i++) {
        myArray[i] = new Stack(m_lines);
    }

    for (int i = 0; i < m_width; i++) {
        for (int j = 0; j < m_lines; j++) {
            myArray[i]->push(grid[i][j]);
        }
    }
    
    

}

void SpeakerView::printResults(){
    cout << "People Able to See in Current Arrangement:\n" << endl;
    for(int i = m_width-1; i >= 0; i--){
        cout << "Column " << (m_width - i) << ": ";
        cout << "Able to see: " << myArray[i]->getSize() << " ";
        cout << "Heights: ";
        myArray[i] -> print();
        cout << endl;
    }
}
