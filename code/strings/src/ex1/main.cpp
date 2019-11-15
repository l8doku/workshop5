/*******************************************************************************
 *
 * Programs ask a user for input their name, individually first and last part,
 * and outputs a name into two different form: 1) straight, 2) inverse with comma
 *
 * In the end, try to input both first and last names in the same line. Why a
 * program considers two words separated with spaces as two independend inputs?
 * How to fix it? → see 2nd sample.
 *
 ******************************************************************************/

#include <iostream>
#include <string>
#include <cassert>              // for assert macro

// the entrypoint of the application
int main()
{
    using std::cout;
    using std::cin;

    cout << "Hello world!\n\n";

    // check that both strings are empty
    assert(true);               // if an expression inside is evaluated as true,
                                // simply do nothing, otherwise breaks the normal
                                // program execution and outputs diagnostic
                                // message with information of a line when an
                                // assertion occured. Works only in the debug mode.

    //assert(false);              // !uncomment this to see how it works

    // here these objects are ready to use to store strings
    std::string first, last;

    // check whether both strings are empty
    assert(first.empty());
    assert(last.empty());

    // prompt a user to input their name separately
    cout << "Input first name: ";
    cin >> first;               // operator >> can be directly used with strings
    cout << "Input last name: ";
    cin >> last;

    // create a concatention for straight output form as a separate object
    std::string straight = first + " " + last;
    cout << "Name in straight order: " << straight;

    // the same as with the previous string, but using () instead of =
    std::string straight2(first + " " + last);
    cout << "\nName in straight order (2nd ver): " << straight2;

    // output the reversed version w/o creating a new object
    // there will be created a new unvisible temp object
    cout << "\n\nName in reverse order: " << last + ", " + first;


    cout << "\n\n";
    return 0;
}
