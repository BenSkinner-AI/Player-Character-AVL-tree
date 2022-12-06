/*
Name: <Ben Skinner>
email <bts277@msstate.edu>
Compiler Used: <Qt Creator>
Program Description:
<This program allows the user to manage player characters with an AVL>
*/
#pragma once
#include <iostream>
#include <sstream>
#include <string>

using std::istream;
using std::stringstream;
using std::string;


class Tokenizer
{
private:
    stringstream ss;
public:
    Tokenizer() { ss.exceptions(std::ios::failbit); }
    Tokenizer(const string& source) { ss.str(source); ss.exceptions(std::ios::failbit); }

    void setString(const string& str);
    bool isEmpty() ;
    bool readLine(string& line);
    bool readInteger(int& val);
    bool readWord(string& val);
    bool readDouble(double& val);
    bool readChar(char& val);
    void rewind();
    void clear();
};
