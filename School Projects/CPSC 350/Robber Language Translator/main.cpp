#include "FileProcessor.h"
#include "Translator.h"

int main(int argc, char **argv)
{
    FileProcessor f;
    Translator t;
    try
    {
        f.processFile();
        exit(EXIT_SUCCESS);

    }
    catch (runtime_error &excpt)
    {
        cerr << excpt.what() << endl;
        cout << "runtime error" << endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}