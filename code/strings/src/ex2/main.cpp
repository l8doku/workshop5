/*******************************************************************************
 *
 * Modified version of sample 1, which allows a user to input a complex name that
 * consist of more than 1 word (separated by spaces).
 *
 ******************************************************************************/

#include <iostream>
#include <string>
#include <sstream>

// the entrypoint of the application
int main()
{
    using std::cout;
    using std::cin;

    cout << "Hello world!\n\n";


    // here these objects are ready to use to store strings
    //std::string first, last;


    // prompt a user to input their name separately
    cout << "Input first name: ";
    //cin >> first;                 // if we use >> only part before the very first
                                    // space character is considered


    // We going to uset cin.getline() method, which can't work with std::string
    // directly. Hence, we have to use a buffer, implemented as an array of
    // char(acters).
    // We suppose that a name can't exceed 254 symbols (why not 255?)
    char buf[255];
    const size_t bufSize = sizeof(buf); // get the actual size of the buffer
                                        // at the compilation stage

    cin.getline(buf, bufSize);
    std::string first(buf);             // initialize a string w/ the buffer

    cout << "Input last name: ";
    cin.getline(buf, bufSize);
    std::string last = buf;             // the same as std::string last(buf)

    // create a concatention for straight output form as a separate object
    std::string straight = first;
    straight.append(" ");               // append effectively appends the string with
    straight.append(last);              // another string

    cout << "Name in straight order: " << straight;

    // using std::stringstream allows to combine different string even
    // more efficiently
    std::stringstream ss;
    ss << last + ", " + first;

    // output the reversed version w/o creating a new object
    // there will be created a new unvisible temp object
    cout << "\n\nName in reverse order: "
         << ss.str();                   // ss.str() creates a string from a stream


    cout << "\n\n";
    return 0;
}
