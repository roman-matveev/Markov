#include <iostream>
#include <fstream>
#include "keyword.h"
#include "nextword.h"
#include <cstdlib>
#include <ctime>
using namespace std;

string process(string in) {

    string out;
    char sym;

    for (unsigned int i = 0; i < in.size(); i++) {

        sym = in[i];

        if (sym >= 'a' && sym <= 'z') {
            out = out + sym;
        }

        if (sym >= 'A' && sym <= 'Z') {
            out = (sym - 'A') + 'a';
        }
    }

    return out;
}

int main() {

    srand(time(0));

    KeyWordList* keywordlist;
    keywordlist = new KeyWordList();

    KeyWordList* words;
    words = new KeyWordList();

    ifstream book("warandpeace.txt");
    string word, keyword, word1, word2, nextword;
    const int order = 4;

    for (int i = 0; i < order; i++) {

        book >> word;
        word = process(word);
        words->add(word);
    }

    while (!book.eof()) {

        string stringofwords = words->buildString();

        book >> nextword;
        nextword = process(nextword);

        keywordlist->foundNextWord(stringofwords, nextword);

        words->add(nextword);
        words->choplast(order);
    }

    //keywordlist->printlist();

    string startword = keywordlist->getRandomWord();

    for (int i = 0; i < 500; i++) {

        nextword = keywordlist->getRandomNextWord(startword);
        cout << nextword << " ";
        startword = startword.substr(startword.find(" ")+1,startword.size());
        startword = startword + " " + nextword;
    }

    return 0;
}
