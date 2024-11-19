//
//  main.cpp
//  CS 32 Homework 4
//
//  Created by Coco Li on 8/18/23.
//

#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include <cassert>
#include "WordTree.h"
using namespace std;

int main() {
    // insert code here...
        
        cout << "testing add function for multiple values, distinct words, total words: " << endl;
        WordTree w;
        w.add("Harry");
        w.add("Niall");
        w.add("Niall");
        w.add("Liam");
        w.add("Louis");
        w.add("Harry");
        w.add("Niall");
        w.add("Zayn");
        cout << w;
        assert(w.distinctWords() == 5);
        assert(w.totalWords() == 8);

        cout << endl;

        cout << "testing add function for one value, distinct words, total words: " << endl;
        WordTree z;
        z.add("Zayn");
        z.add("Zayn");
        z.add("Zayn");
        cout << z;
        cout << z.distinctWords() << endl;
        cout << z.totalWords() << endl;
        assert(z.distinctWords() == 1);
        assert(z.totalWords() == 3);

        cout << endl;

        cout << "testing copy constructor: " << endl;
        WordTree l;
        l = z;
        cout << z;
        assert(l.distinctWords() == 1);
        assert(l.totalWords() == 3);

        cout << endl;

        cout << "testing assignment operator on Word tree w and z --> assigning w to z: " << endl;
        w = z;
        cout << w;
        assert(w.distinctWords() == 1);
        assert(w.totalWords() == 3);

        cout << endl;
        cout << "testing adding when first letter is the same: " << endl;

        WordTree k;

        k.add("Kim");
        k.add("Kanye");
        k.add("Kanye");
        k.add("Kanye");
        assert(k.distinctWords() == 2);
        assert(k.totalWords() == 4);

        cout << k << endl;
        

    //    ifstream fin;
    //    ofstream fout;
    //    string filename;
    //    cout << "Enter name of file with text to analyze: ";
    //    cin >> filename;
    //    fin.open(filename.c_str());
    //    if (fin.fail()) {
    //    cout << "Error opening file.\n";
    //    exit(1);
    //    }
    //    cout << "\nAnalyzing " << filename << ".\n";
    //    WordTree myTree;
    //    WordType Word;
    //
    //    while (fin >> Word) {
    //     myTree.add(Word);
    //    }
    //
    //    fin.close();
    //    fout.open("doi.txt");
    //    cout << "\nWord counts:\n\n";
    //    cout << myTree;
    //    fout << myTree;
    //    cout << "\nTotal number of words in text: " << myTree.totalWords() << ".\n";
    //    fout << "\nTotal number of words in text: " << myTree.totalWords() << ".\n";
    //    cout << "Number of distinct words appearing in text: "
    //    << myTree.distinctWords() << ".\n";
    //    fout << "Number of distinct words appearing in text: "
    //    << myTree.distinctWords() << ".\n";
    //    fout.close();
        
        cout <<endl;
        
        cout << "adding the words repeatedly but in random order: " << endl;
        WordTree iAmGettingAB;
        iAmGettingAB.add("coco");
        iAmGettingAB.add("slays");
        iAmGettingAB.add("she");
        iAmGettingAB.add("she");
        iAmGettingAB.add("she");
        iAmGettingAB.add("she");
        iAmGettingAB.add("be");
        iAmGettingAB.add("coco");
        iAmGettingAB.add("slays");
        iAmGettingAB.add("coco");
        iAmGettingAB.add("slays");
        iAmGettingAB.add("coco");
        iAmGettingAB.add("slays");
        iAmGettingAB.add("coco");
        iAmGettingAB.add("coco");
        iAmGettingAB.add("slays");
        iAmGettingAB.add("coco");
        iAmGettingAB.add("coco");
        iAmGettingAB.add("she");
        iAmGettingAB.add("she");
        iAmGettingAB.add("be");
        iAmGettingAB.add("be");
        iAmGettingAB.add("be");
        iAmGettingAB.add("be");
        iAmGettingAB.add("she");
        iAmGettingAB.add("be");
        iAmGettingAB.add("she");
        iAmGettingAB.add("be");
        iAmGettingAB.add("be");
        iAmGettingAB.add("slays");
        iAmGettingAB.add("slays");
        iAmGettingAB.add("slays");

        cout << iAmGettingAB << endl;
        
        assert(iAmGettingAB.distinctWords() == 4);
        assert(iAmGettingAB.totalWords() == 32);
        
        cout << endl;
        
        //just zayn before
        assert(w.distinctWords() == 1);
        assert(w.totalWords() == 3);
        
        cout << "assign w to iAmGettingAB and print what w is: " <<endl;
        w = iAmGettingAB;
        cout << w << endl;
        assert(w.distinctWords() == 4);
        assert(w.totalWords() == 32);
        cout << endl;
        
        cout << "copy construct manifest class to be iAmGettingAB" <<endl;
        WordTree manifest;
        manifest = iAmGettingAB;
        cout << manifest << endl;
        assert(manifest.distinctWords() == 4);
        assert(manifest.totalWords() == 32);
        cout << endl;
        
        cout << "sweet like fruit duh: " << endl;
        
        WordTree fruit;
            
        fruit.add("dragonfruit");
        fruit.add("grapes");
        fruit.add("blackberries");
        fruit.add("apple");
        fruit.add("apple");
        fruit.add("banana");
        fruit.add("apple");
        fruit.add("cherry");
        fruit.add("nectarines");
        fruit.add("banana");
        fruit.add("strawberry");
        fruit.add("cherry");
        fruit.add("grapes");
        fruit.add("strawberry");
        fruit.add("strawberry");
        fruit.add("blackberries");
        fruit.add("nectarines");
        fruit.add("cherry");
        fruit.add("cherry");
        fruit.add("apple");
        fruit.add("banana");
        fruit.add("dragonfruit");

        cout<< fruit << endl;
        assert(fruit.distinctWords() == 8);
        assert(fruit.totalWords() == 22);
        cout << endl;

        cout << "check aliasing by assigning fruit to itself: " << endl;
        fruit = fruit;
        cout<< fruit << endl;
        assert(fruit.distinctWords() == 8);
        assert(fruit.totalWords() == 22);
        cout << endl;

    return 0;
}
