#include "Translator.h"
#include "Model.h"

Translator::Translator()
{
    punct = ".,!?;:-_&()*/";
    vowels = "aeiou";
    consanants = "bcdfghjklmnpqrstvwxyz";
}

Translator::~Translator()
{
}

string Translator::translateEnglishWord(string englishWord)
{
    Model m;
    englishWordTranslation = "";
    length = englishWord.length();
    for (int i = 0; i < length; ++i)
    {
        ch = englishWord[i];
        if (vowels.find(tolower(ch)) != string::npos)
        {
            englishWordTranslation += m.translateSingleVowel(tolower(ch));
        }
        else if (consanants.find(tolower(ch)) != string::npos)
        {
            englishWordTranslation += m.translateSingleConsanant(tolower(ch));
        }
        else
        {
            englishWordTranslation += ch;
        }
    }
    return englishWordTranslation;
}
string Translator::translateEnglishSentence(string englishSentence)
{
    Model m;
    englishSentenceTranslation = "";
    sentenceLength = englishSentence.length();
    int i = 0;
    while (i < sentenceLength)
    {
        word = "";
        cl = englishSentence[i];
        while (i < sentenceLength && !isspace(cl) && punct.find(cl) == string::npos)
        {
            word += cl;
            i++;
            if (i < sentenceLength)
                cl = englishSentence[i];
        }
        if (!word.empty())
        {
            englishSentenceTranslation += translateEnglishWord(word);
        }

        if (i < sentenceLength && isspace(cl))
        {
            englishSentenceTranslation += cl;
            i++;
        }
        else if (i < sentenceLength && punct.find(cl) != std::string::npos)
        {
            englishSentenceTranslation += cl;
            i++;
        }
    }
    return englishSentenceTranslation;
}
