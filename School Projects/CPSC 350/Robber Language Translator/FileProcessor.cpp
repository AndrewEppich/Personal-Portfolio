#include "FileProcessor.h"

FileProcessor::FileProcessor(){

}

FileProcessor::~FileProcessor(){

}

void FileProcessor::processFile() {
    Translator t;
    ifstream inFile("RobberLang.txt");
    ofstream outFile("translation.html");

    if (outFile.is_open() && inFile.is_open()) {
        outFile << "<!DOCTYPE html>\n";
        outFile << "<html>\n";
        outFile << "<head>\n";
        outFile << "<title>Translation</title>\n";
        outFile << "</head>\n";
        outFile << "<body>\n";

        string line;
        string lineTranslation;

        while (getline(inFile, line)) {
            lineTranslation = t.translateEnglishSentence(line);
            outFile << "<p><strong>" << line << "</strong></p>\n";
            outFile << "<br />\n";
            outFile << "<p><em>" << lineTranslation << "</em></p>\n";
        }

        outFile << "</body>\n";
        outFile << "</html>\n";
        if (!getline(inFile, line)){
            inFile.close();
            outFile.close();
        }
        
    }

}