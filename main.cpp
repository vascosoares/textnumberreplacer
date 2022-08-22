#include <iostream>
#include "parser.h"
#include "tests.h"

using namespace std;
using namespace numbersparser;
using namespace tests;

int main(int argc, char** argv) {

    if (argc < 2) {
        throw std::runtime_error("Argument is missing!");
    }

    std::stringstream ss;

    ss << argv[1];
    cout << " INPUT: " << ss.str() << endl;

    if (ss.str() != "test") {
        Parser parser;
        string temp = parser.ReplaceTextNumbers(ss.str());
        cout << "OUTPUT: " << temp << endl;
    } else {
        Tests::Test();
    }
    return 0;
}
