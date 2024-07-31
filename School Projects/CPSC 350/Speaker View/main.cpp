#include "Stack.h"
#include "SpeakerView.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc > 1){
        SpeakerView s(argv[1]);
        s.computeOutput();
        s.printResults();
    }else{
        cout << "Enter a valid file input in command line argument" << endl;
        return 0;
    }

    

    return 0;
}
