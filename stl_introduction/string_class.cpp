/*
Used in order to avoid character array
Contains a character array internally
*/
#include <iostream>
#include <string>
using namespace std;


int main() {
    string s0; // empty string
    string s1 = "Hello World"; // Direct creation. Use double quotes.
                               // Single quote is for character.
    string s2("String using constructor"); // Using constructor.
    string s3(s2); // Using copy constructor.
    string s4 = s3; // Direct assignment.
    // create string from character array.
    char a[] = {'a', 'b', 'c', 'd', '\0'};
    string s5(a);
    // check if empty
    if (s0.empty()) {
        cout << "s0 is an empty string" << endl;
    }
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    cout << "s5: " << s5 << endl;

    // append to string
    s0.append("Appended string");
    cout << "new s0: "<< s0 << endl;
    s0 += " More appended";
    cout << "new s0: "<< s0 << endl;

    // clearing strings
    cout << "s0 - length before clear: " << s0.length() << endl;
    s0.clear();
    cout << "s0 - length after clear: " << s0.length() << endl;

    // comparison
    string s6 = "Apple";
    string s7 = "Mango";
    cout << "s6: " << s6 << ", s7: " << s7 << endl;
    cout << "s6 - s7: " << s6.compare(s7) << endl;
    cout << "s7 - s6: " << s7.compare(s6) << endl;
    cout << "s7 - s7: " << s7.compare(s7) << endl;
    // direct comparison
    if (s6 > s7) {
        cout << "s6 > s7" << endl;
    } else {
        cout << "s7 > s6" << endl;
    }

    // index access
    cout << "First element of s7: " << s7[0] << endl;

    // Find substrings
    string s8 = "Find the apple in the string";
    string word = "apple";
    int aindx = s8.find(word);
    cout << "Index of apple is: " << aindx << endl;

    // erasing a word: string.erase(startindex, endindex)
    s8.erase(aindx, word.length() + 1);
    cout << "s8 after erasing word: " << s8 << endl;

    // iterate over all items of string with index
    // uses an index
    cout << "Iteration over all strings" << endl;
    for (int i=0; i< s8.length(); i++) {
        cout << "Index " << i << ": " << s8[i] << endl;
    }
    cout << "End iteration" << endl;

    // iterate over all items of string with iterators
    // Returns an iterator.
    cout << "Iteration over all strings with iterators" << endl;
    for(string::iterator c=s8.begin(); c!=s8.end(); c++) {
        cout << "Character: " << (*c) << endl;
    }
    cout << "End iteration with iterators" << endl;

    // iterate with for each loop
    // Returns actual values.
    cout << "Iteration with for each" << endl;
    for(char c: s8) {
        cout << "Each Character: " << c << endl;
    }
    cout << "End iteration with for each" << endl;
    return 0;
}
