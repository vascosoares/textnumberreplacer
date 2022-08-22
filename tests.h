#ifndef NUMBERSPARSER_TESTS_H
#define NUMBERSPARSER_TESTS_H

#include <iostream>
#include <sstream>
#include <cassert>
#include "parser.h"

using namespace std;
using namespace numbersparser;

namespace tests {

    class Tests {
    public:
        Tests() = delete;
        ~Tests() = delete;

        static void Test() {
            TestDigits();
            TestDozens();
            TestHundreds();
            TestThousands();
            TestMillions();
            TestBillions();
        };

        static void TestDigits() {
            Parser parser;

            string teststr = "I have one apple.";
            string replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 1 apple.");

            teststr = "I have ten apples.";
            replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 10 apples.");

            teststr = "I have seventeen apples.";
            replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 17 apples.");
        };

        static void TestDozens() {
            Parser parser;

            string teststr = "I have forty apples.";
            string replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 40 apples.");

            teststr = "I have twenty three apples.";
            replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 23 apples.");

            teststr = "I have ninety six apples.";
            replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 96 apples.");
        };

        static void TestHundreds() {
            Parser parser;

            string teststr = "I have one hundred apples.";
            string replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 100 apples.");

            teststr = "I have two hundred and twenty apples.";
            replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 220 apples.");

            teststr = "I have five hundred and ninety six apples.";
            replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 596 apples.");
        };

        static void TestThousands() {
            Parser parser;

            string teststr = "I have one thousand apples.";
            string replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 1000 apples.");

            teststr = "I have two thousand and twenty apples.";
            replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 2020 apples.");

            teststr = "I have five thousand and three hundred and ninety six apples.";
            replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 5396 apples.");
        };

        static void TestMillions() {
            Parser parser;

            string teststr = "I have seven million apples.";
            string replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 7000000 apples.");

            teststr = "I have two million and twenty apples.";
            replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 2000020 apples.");

            teststr = "I have two million and twenty thousand apples.";
            replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 2020000 apples.");

            teststr = "I have four millions and three hundred and ninety six apples.";
            replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 4000396 apples.");
        };

        static void TestBillions() {
            Parser parser;

            string teststr = "I have one billion apples.";
            string replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 1000000000 apples.");

            teststr = "I have one billion and twenty five million apples.";
            replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 1025000000 apples.");

            teststr = "I have one billion and twenty thousand apples.";
            replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 1000020000 apples.");

            teststr = "I have one billions and thirty five millions and one hundred and twenty thousand and forty five apples.";
            replacedstr = parser.ReplaceTextNumbers(teststr);
            cout << " INPUT: " << teststr << endl;
            cout << "OUTPUT: " << replacedstr << endl;
            assert(replacedstr == "I have 1035120045 apples.");
        };
    };
}
#endif //NUMBERSPARSER_TESTS_H


