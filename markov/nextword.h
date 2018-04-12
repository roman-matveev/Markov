#ifndef NEXTWORD
#define NEXTWORD

#include <iostream>
//#include "keyword.h"
using namespace std;

class NextWordElement {
public:

    NextWordElement(string);
    string word;
    int count;
    NextWordElement* next;
};

class NextWordList {
public:

    NextWordList();
    string getRandomWord();
    void foundNextWord(string nextword);
    void add(string word);
    void printlist();
    int count;
    int totalcount;
    int choice;
    int runningcount;

private:
    NextWordElement* first;

};

#endif // NEXTWORD
