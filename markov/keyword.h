#ifndef KEYWORD
#define KEYWORD

#include <iostream>
#include "nextword.h"
using namespace std;

class KeyWordElement {
public:

    KeyWordElement(string);
    string word;
    KeyWordElement* next;
    NextWordList* nextwordlist;
};

class KeyWordList {
public:

    KeyWordList();

    KeyWordElement* add(string word);
    void printlist();

    KeyWordElement* first = NULL;
    KeyWordElement* findWord(string word);
    void foundNextWord(string keyword, string nextword);

    KeyWordElement* addUnique(string keyword);

    void remove(int index);
    int findIndex(string searchword);
    string get(int index);
    int size();
    int count;

    string getRandomNextWord(string keyword);
    string getRandomWord();

    int choice;
    int keywordelementcount;
    int runningcount;

    void choplast(int);
    string buildString();
};

#endif // KEYWORD
