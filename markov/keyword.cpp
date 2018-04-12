#include <iostream>
#include <fstream>
#include "keyword.h"
#include "nextword.h"
using namespace std;

KeyWordElement::KeyWordElement(string keyword) {

    word = keyword;
    next = NULL;
    nextwordlist = new NextWordList();
}

KeyWordList::KeyWordList() {

    first = NULL;
    count = 0;
    keywordelementcount = 0;
    choice = 0;
    runningcount = 0;
}


KeyWordElement* KeyWordList::findWord(string wordToFind) {

    KeyWordElement* currentElement = first;

    while (currentElement != NULL) {

        if (currentElement->word == wordToFind) {
            return currentElement;
        }

        currentElement = currentElement->next;
    }

    return NULL;
}

int KeyWordList::findIndex(string wordToFind) {

    int index = count-1;
    KeyWordElement* currentElement = first;

    while (currentElement != NULL) {

        if (currentElement->word == wordToFind) {
            return index;
        }

        currentElement = currentElement->next;
        index--;
    }

    return -1;
}

void KeyWordList::foundNextWord(string keyword, string nextword) {

    KeyWordElement* elem = this->addUnique(keyword);

    if (elem != NULL) {

        elem->nextwordlist->foundNextWord(nextword);

    }
}


string KeyWordList::getRandomWord() {

    KeyWordElement* currentElement = first;

    int keywordelementcount = 0;

    while (currentElement != NULL) {
        keywordelementcount++;
        currentElement = currentElement->next;
    }

    choice = rand()%keywordelementcount;
    //cout << choice << " ";

    currentElement = first;

    int runningcount = -1;

    while (currentElement != NULL) {

        runningcount++;

        if (runningcount >= choice) {
            break;
        }

        currentElement = currentElement->next;
    }

    return currentElement->word;
}

string KeyWordList::getRandomNextWord(string keyword) {

    KeyWordElement* element = findWord(keyword);
    return element->nextwordlist->getRandomWord();
}


string KeyWordList::buildString() {

    KeyWordElement* current = first;
    string stringofwords;

    while (current != NULL) {

        if (stringofwords != "") {

            stringofwords = " " + stringofwords;
        }

        stringofwords = current->word + stringofwords;
        current = current->next;
    }

    return stringofwords;
}

void KeyWordList::choplast(int order) {

    KeyWordElement* currentElement = first;
    KeyWordElement* newlast = NULL;
    KeyWordElement* tail = NULL;
    int counter = 0;

    while (currentElement != NULL) {

        counter++;


        if (counter == order) {

            newlast = currentElement;
        }

        if (counter > order) {

            tail = currentElement;
        }

        currentElement = currentElement->next;
    }

    delete tail;
    newlast->next = NULL;
}


KeyWordElement* KeyWordList::add(string word) {

    KeyWordElement* newword = new KeyWordElement(word);
    newword->next = first;
    first = newword;
    count++;
    return newword;
}

KeyWordElement* KeyWordList::addUnique(string keyword) {

    if (this->findWord(keyword) == NULL) {
        KeyWordElement* elem = this->add(keyword);
        return elem;
    }

    return findWord(keyword);
}


int KeyWordList::size() {

    return count;
}

void KeyWordList::printlist() {

    KeyWordElement* currentElement = first;

    while (currentElement != NULL) {

        cout << currentElement->word << endl;
        currentElement->nextwordlist->printlist();
        currentElement = currentElement->next;

        cout << endl;
    }
}
