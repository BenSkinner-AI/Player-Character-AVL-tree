/*
Name: <Ben Skinner>
email <bts277@msstate.edu>
Compiler Used: <Qt Creator>
Program Description:
<This program allows the user to manage player characters with an AVL>
*/
#include "tokenizer.h"
#include <fstream>
#include <avl.h>
#include <iostream>
#include <node.h>

using namespace std;

bool processText(istream& is,AVL lva, bool interactive = true)
{

    string line;
    string command;
    string arg1, arg2;
    string who, name, stat, val;
    Tokenizer tkn;
    while (true)
    {
        if (!interactive)
        {
            if (is.eof()) return true;
        }
        else { cout << ">> "; }

        getline(is, line);
        tkn.setString(line);

        tkn.readWord(command);
        if (command == "exit")
        {
            cout << "Exiting ...." << endl;
            return false;
        }
        if (command == "load")
        {
            // load expects a filename .. so read one more word
            if (!tkn.readWord(arg1)) {
                cout << "Missing file name" << endl;
                continue; // skip back to the top of the read loop
            }
            ifstream fin;
            bool status = true;
            fin.open(arg1);
            if (fin.is_open())
            {

            // status = processText(fin, Data structure, false);
                status = processText(fin, lva, false);
            }
            else { cout << "Failed to open the file" << endl; }
            fin.close();
            if (!status) return false;
        }
        if (command == "add")
        {
            tkn.readWord(who);
            lva.insert(who);
            cout << "Player character " << who << " was added to the list." << endl;
        }

        if (command == "remove")
        {
            tkn.readWord(who);
            lva.remove(who);
            cout << "Player character ' " << who << " ' was removed from the list. " << endl;
        }

        if (command == "display")
        {
            lva.inOrder(cout);
            cout << endl;
        }

        if (command == "set")
        {
            tkn.readWord(name);
            tkn.readWord(stat);
            tkn.readWord(val);
            lva.set(name, stat, val);
        }
        if (command == "search")
        {
            string title, val;
            tkn.readWord(title);
            tkn.readWord(val);
            lva.search(title, val);
        }
    }


}

int main()
{

// <type> inst;

     AVL inst;

    processText(cin, inst);
    return 0;

}
