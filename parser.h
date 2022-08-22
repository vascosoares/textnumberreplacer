#ifndef NUMBERSPARSER_PARSER_H
#define NUMBERSPARSER_PARSER_H

#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

namespace numbersparser {

    enum class TokenType {
        Digit,
        Final,
        NeedsDigit,
        Multiple,
        Add
    };
    struct TokenInfo {
        TokenType   Type;
        uint32_t     Digit;
    };

    class Parser {

    public:

        Parser() {
            initTokens();
            //printTokens();
        }

        string ReplaceTextNumbers(const string& sentence) {
            stringstream ss;
            vector<string> tokens = tokenize(sentence);
            uint32_t number = 0;
            uint32_t tempblock = 0;
            bool add = false;
            bool waitingfordigit = false;
            bool inblock = false;
            bool hasnumber = false;

            for (auto token : tokens) {
                //cout << token << endl;
                if ( auto it = nrtokens.find(token); it != nrtokens.end()) {
                    hasnumber = true;
                    auto info = it->second;

                    if (info.Type == TokenType::Digit || info.Type == TokenType::Final) {
                        inblock = true;
                        if (add) {
                            tempblock += info.Digit;
                            if (!waitingfordigit) {
                                add = false;
                            } else {
                                waitingfordigit = false;
                            }
                        } else {
                            tempblock = info.Digit;
                        }
                    } else if (info.Type == TokenType::Multiple) {
                        tempblock *= info.Digit;
                        if (info.Digit == 1000 || info.Digit == 1000000 || info.Digit == 1000000000) {
                            number += tempblock;
                            tempblock = 0;
                            inblock = false;
                        }
                    } else if (info.Type == TokenType::NeedsDigit) {
                        waitingfordigit = true;
                        inblock = true;
                        if (add) {
                            tempblock += info.Digit;
                        } else {
                            tempblock = info.Digit;
                            add = true;
                        }
                    } else if (info.Type == TokenType::Add) {
                        add = true;
                    }
                } else {
                    if (inblock) {
                        number += tempblock;
                        inblock = false;
                    }
                    if (hasnumber) {
                        ss << number << " ";
                        hasnumber = false;
                    }
                    ss << token << " ";
                }
            }
            string trimmed = ss.str();
            trimmed.erase(trimmed.size()-1);
            return trimmed;
        }

    private:
        vector<string> tokenize(string str) {
            vector<string> out;
            string token = "";
            for (auto chr : str) {
                if (chr == ' ') {
                    if (!token.empty()) {
                        out.push_back(token);
                    }
                    token = "";
                } else {
                    token += chr;
                }
            }
            if (!token.empty()) {
                out.push_back(token);
            }
            return out;
        }

        map<string,TokenInfo> nrtokens;

        void printTokens() {
            for (auto token : nrtokens) {
                cout << "key: " << token.first << " value: " << token.second.Digit << endl;
            }
        }

        void initTokens() {
            TokenInfo info;

            //and
            info.Type = TokenType::Add;
            info.Digit = 1;
            nrtokens.insert(make_pair("and", info));

            //one
            info.Type = TokenType::Digit;
            info.Digit = 1;
            nrtokens.insert(make_pair("one", info));

            //two
            info.Type = TokenType::Digit;
            info.Digit = 2;
            nrtokens.insert(make_pair("two", info));

            //three
            info.Type = TokenType::Digit;
            info.Digit = 3;
            nrtokens.insert(make_pair("three", info));

            //four
            info.Type = TokenType::Digit;
            info.Digit = 4;
            nrtokens.insert(make_pair("four", info));

            //five
            info.Type = TokenType::Digit;
            info.Digit = 5;
            nrtokens.insert(make_pair("five", info));

            //six
            info.Type = TokenType::Digit;
            info.Digit = 6;
            nrtokens.insert(make_pair("six", info));

            //seven
            info.Type = TokenType::Digit;
            info.Digit = 7;
            nrtokens.insert(make_pair("seven", info));

            //eight
            info.Type = TokenType::Digit;
            info.Digit = 8;
            nrtokens.insert(make_pair("eight", info));

            //nine
            info.Type = TokenType::Digit;
            info.Digit = 9;
            nrtokens.insert(make_pair("nine", info));

            //ten
            info.Type = TokenType::Final;
            info.Digit = 10;
            nrtokens.insert(make_pair("ten", info));

            //eleven
            info.Type = TokenType::Final;
            info.Digit = 11;
            nrtokens.insert(make_pair("eleven", info));

            //twelve
            info.Type = TokenType::Final;
            info.Digit = 12;
            nrtokens.insert(make_pair("twelve", info));

            //thirteen
            info.Type = TokenType::Final;
            info.Digit = 13;
            nrtokens.insert(make_pair("thirteen", info));

            //fourteen
            info.Type = TokenType::Final;
            info.Digit = 14;
            nrtokens.insert(make_pair("fourteen", info));

            //fifteen
            info.Type = TokenType::Final;
            info.Digit = 15;
            nrtokens.insert(make_pair("fifteen", info));

            //sixteen
            info.Type = TokenType::Final;
            info.Digit = 16;
            nrtokens.insert(make_pair("sixteen", info));

            //seventeen
            info.Type = TokenType::Final;
            info.Digit = 17;
            nrtokens.insert(make_pair("seventeen", info));

            //eighteen
            info.Type = TokenType::Final;
            info.Digit = 18;
            nrtokens.insert(make_pair("eighteen", info));

            //nineteen
            info.Type = TokenType::Final;
            info.Digit = 19;
            nrtokens.insert(make_pair("nineteen", info));

            //twenty
            info.Type = TokenType::NeedsDigit;
            info.Digit = 20;
            nrtokens.insert(make_pair("twenty", info));

            //thirty
            info.Type = TokenType::NeedsDigit;
            info.Digit = 30;
            nrtokens.insert(make_pair("thirty", info));

            //forty
            info.Type = TokenType::NeedsDigit;
            info.Digit = 40;
            nrtokens.insert(make_pair("forty", info));

            //fifty
            info.Type = TokenType::NeedsDigit;
            info.Digit = 50;
            nrtokens.insert(make_pair("fifty", info));

            //sixty
            info.Type = TokenType::NeedsDigit;
            info.Digit = 60;
            nrtokens.insert(make_pair("sixty", info));

            //seventy
            info.Type = TokenType::NeedsDigit;
            info.Digit = 70;
            nrtokens.insert(make_pair("seventy", info));

            //eighty
            info.Type = TokenType::NeedsDigit;
            info.Digit = 80;
            nrtokens.insert(make_pair("eighty", info));

            //ninety
            info.Type = TokenType::NeedsDigit;
            info.Digit = 90;
            nrtokens.insert(make_pair("ninety", info));

            //hundred
            info.Type = TokenType::Multiple;
            info.Digit = 100;
            nrtokens.insert(make_pair("hundred", info));

            //thousand
            info.Type = TokenType::Multiple;
            info.Digit = 1000;
            nrtokens.insert(make_pair("thousand", info));

            //million
            info.Type = TokenType::Multiple;
            info.Digit = 1000000;
            nrtokens.insert(make_pair("million", info));
            info.Type = TokenType::Multiple;
            info.Digit = 1000000;
            nrtokens.insert(make_pair("millions", info));

            //billion
            info.Type = TokenType::Multiple;
            info.Digit = 1000000000;
            nrtokens.insert(make_pair("billion", info));
            info.Type = TokenType::Multiple;
            info.Digit = 1000000000;
            nrtokens.insert(make_pair("billions", info));
        }
    };
}
#endif //NUMBERSPARSER_PARSER_H
