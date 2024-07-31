#include "Model.h"

Model::Model(){
    vowels = "aeiou";
    consanants = "bcdfghjklmnpqrstvwxyz";
}
 

Model::~Model(){
   
}

string Model::translateSingleVowel(char in){
    translatedVowel = "";
    translatedVowel += in;

    return translatedVowel;
}

string Model::translateSingleConsanant(char in){
    translatedConsanant = "";
    translatedConsanant += in;
    translatedConsanant += 'o';
    translatedConsanant += in;
    
    return translatedConsanant;

}