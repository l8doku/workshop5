/*******************************************************************************
 *
 * Reads a string containing spaces and outputs individual words of the string
 * one word per a line.
 *
 ******************************************************************************/

#include <iostream>
#include <string>
#include <sstream>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;

    cout << "Hello world!\n\n";

    // prompt a user to input their name separately
    cout << "Input a sentence (not longer than 1023 chars): ";
    char buf[1024];
    const size_t bufSize = sizeof(buf); // get the actual size of the buffer
                                        // at the compilation stage
    cin.getline(buf, bufSize);

    // подход "в лоб"
    string str(buf);
    size_t len = 0;                     // len of the current word
    size_t beg = 0, end = 0;            // positions of the beginning and the end
                                        // of a word for cutting
    for(size_t i = 0; i < str.length(); ++i)
    {
        char ch = str[i];               // get current symbol
        if(isspace(ch))                 // func. isspace() returns true on spaces, tabs...
        {
            // if a word can be extracted
            len = end - beg;
            if(len != 0)
            {
                string aWord = str.substr(beg, len);
                cout << aWord << endl;
            }

            // now move both cursors
            beg = end = i + 1;
        }
        else                            // not space
            ++end;
    }

    // the very last word must be considered separately
    len = end - beg;
    if(len != 0)                        // mention, that here we have a code repetition,
    {                                   // think of how to cope with such a problem
        string aWord = str.substr(beg, len);
        cout << aWord << endl;
    }



    // NB: этот подход придержим до след. семинара, когда будет больше потоков
//        // simplest approach is to use string stream
//        std::stringstream ss(buf);

//        // we use stringstream::good() to determine whether the buffer is in "good" state
//        // stringstream::eof() returns true when we reach the enf of stream
//        while(ss.good() && !ss.eof())
//        {
//            std::string str;
//            ss >> str;
//            cout << str << endl;
//        }


    cout << "\n\n";
    return 0;
}
