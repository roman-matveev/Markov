#include <iostream>
#include <fstream>
#include "nextword.h"
#include "keyword.h"
using namespace std;

NextWordElement::NextWordElement(string keyword) {

    word = keyword;
    count = 1;
    next = NULL;
}

NextWordList::NextWordList() {

    first = NULL;
    count = 0;
    totalcount = 0;
    choice = 0;
    runningcount = 0;
}


string NextWordList::getRandomWord() {

    NextWordElement* currentElement = first;

    int totalcount = 0;

    while (currentElement != NULL) {
        totalcount += currentElement->count;
        currentElement = currentElement->next;
    }

    choice = rand()%totalcount;
    //cout << choice << " ";

    currentElement = first;

    int runningcount = -1;

    while (currentElement != NULL) {

        runningcount += currentElement->count;

        if (runningcount >= choice) {
            break;
        }

        currentElement = currentElement->next;
    }

    return currentElement->word;
}


void NextWordList::foundNextWord(string nextwordToFind) {

    NextWordElement* currentElement = first;

    while (currentElement != NULL) {

        if (currentElement->word == nextwordToFind) {
            currentElement->count++;
            return;

        }

        currentElement = currentElement->next;
    }

    add(nextwordToFind);
}


void NextWordList::add(string word) {

    NextWordElement* newword = new NextWordElement(word);
    newword->next = first;
    first = newword;
    count++;
}

void NextWordList::printlist() {

    NextWordElement* currentElement = first;

    while (currentElement != NULL) {

        cout << "   - " << currentElement->word << " " << currentElement->count << endl;
        cout << "";
        currentElement = currentElement->next;
    }
}
