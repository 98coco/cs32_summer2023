//
//  main.cpp
//  CS 32 Project 3
//
//  Created by Coco Li on 7/27/23.
//

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <cstring>
//#include <cassert>
using namespace std;
const int MAXRESULTS = 20; // Max matches that can be found
const int MAXDICTWORDS = 30000; // Max words that can be read in

int readFile(istream &dictfile, string dict[], int &wordCounter){  //helper function for vocabulary Creator
    string word;
    if (wordCounter == MAXDICTWORDS){ //base case 
        return MAXDICTWORDS;
    }
    if (dictfile.eof()){ //base case -- have finished reading the end of the file but not at the MAXDICTWORDS
        wordCounter =  wordCounter - 1; //because of getline
        return wordCounter;
    }
    getline(dictfile,word); //puts the dictfile word into string word
    dict[wordCounter] = word;
    wordCounter++;
    readFile(dictfile,dict,wordCounter); // incrementing
    return wordCounter;
}

//Puts each string in dictfile into the array dict. Returns the number of words
//read into dict. This number should not be larger than MAXDICTWORDS since that is
//the size of the array.

int vocabularyCreator(istream &dictfile, string dict[]){
    int wordCounter = 0;
    readFile(dictfile,dict,wordCounter);
    return wordCounter;
}

//Puts all the possibilities of word which are found in dict into results. Returns
//the number of matched words found. This number should not be larger than
//MAXRESULTS since that is the size of the array. The size is the number of words
//inside the dict array

bool checkInDict(string &word, const string dict[],int &size, int wordCounter){
    if (dict[wordCounter] == word){
        return true;
    }
    if (wordCounter >= size){ //out of bounds
        return false;
    }
    wordCounter++;
    return checkInDict(word, dict, size, wordCounter);
}

bool checkInResults(string &prefix, int rIC, string results[]){
    if (rIC >= MAXRESULTS){
        return false; //out of bounds and was not found
    }
    if (results[rIC] == prefix){
        return true;
    }
    rIC++;
    return checkInResults(prefix, rIC, results);
}

void addToResults(string &prefix, string results[],int &rIA){
    if (rIA >= MAXRESULTS){
        return; //no more space in our array results so do not add
    }
    results[rIA] = prefix;
}

//i is our iterator for current permutation
//max is the size of our rest
//size will be the amount of words in our dictionary
//results is where we place all the anagrams
//rIA is results iterator for adding to array
//rIC is results iterator for checking array

void permutationLoop(string prefix, string &rest, int i, size_t max, int &size, const string dict[],string results[], int &rIA, int rIC){
    if(rest == ""){  //finished going thru rest
        if (checkInDict(prefix, dict,size,0) == true){ //make sure it is a word
            if (checkInResults(prefix, rIC, results) == false){ //not in results, so we can add
                addToResults(prefix, results,rIA); //add to results, since it is not in results
                rIA++; //update the next index we are at in the array
                return;
            }
        }
        return;
    }
    if (i>= max){
        return;
    }
    char temp = rest[i]; //char we need to add
    string rest2 = rest.substr(0,i) + rest.substr(i+1,rest.size()-(i+1)); //need to delete rest[i] --> can do (0,i) even when i = 0 because exclusive
    string prefix2 = prefix + temp; //need new strings bc we dont wanna override
    permutationLoop(prefix2,rest2,0,rest.size(),size,dict,results,rIA,rIC); //calls the permutation function on the new rest
    permutationLoop(prefix,rest,i+1,rest.size(),size,dict,results,rIA,rIC); //calls permutation function on the initial rest
    return;
}

//potential functions just return size of result and call the functions above?
int potentialSequences(string word, const string dict[], int size, string results[]){
    int rIA = 0; //rIA is results iterator for adding to array
    int rIC = 0; //rIC is results iterator for checking array
    permutationLoop("", word, 0, word.size(),size,dict,results,rIA,rIC); //create permutation, see if its a word,check if we alr have that in the results, if not we can add to results
    
    //check size of results --> can just return RIA because RIA is updated in our permutationLoop function(pass by reference) and holds where we are in the results array
    return rIA;
}

void outcomeDisclosure(const string results[], int size){
    if (size > MAXRESULTS){
        return;
    }
    if (size == 0){return;}
    outcomeDisclosure(results,size-1); //returning then printing
    cout << "matching word " << results[size-1] << endl;
}

int main()
{
string results[MAXRESULTS];
string dict[MAXDICTWORDS];
ifstream dictfile; // file containing the list of words
int nwords; // number of words read from dictionary
string word;
dictfile.open("words.txt");
if (!dictfile) {
cout << "File not found!" << endl;
return (1);
}
    
    nwords = vocabularyCreator(dictfile, dict);
    cout << "Please enter a string for an anagram: ";
    cin >> word;
    int numMatches = potentialSequences(word, dict, nwords, results);
    if (!numMatches) {
    cout << "No matches found" << endl;
    }
    else {
    outcomeDisclosure(results, numMatches);
    }


//    if (checkInDict("coco", dict, 5, 0) == true){
//        cout << "pass" << endl;
//    }
//    else{
//        cout << "not passed" << endl;
//    }
    
//string exampleDict[] = {"kool", "moe", "dee"};
//int numResults = potentialSequences("kloo", exampleDict,3,results);
//assert(numResults == 1 && results[0] == "kool");

//    string doubleLetters[] = {"happy","moo","oom","soon","noos","book","settle","goodness"};
//    int anagramsFound = potentialSequences("oom", doubleLetters, 8, results);
//    assert(anagramsFound == 2 && results[0] == "oom" && results[1] == "moo");
//
//    anagramsFound = potentialSequences("happy", doubleLetters, 8, results);
//    assert(anagramsFound == 1 && results[0] == "happy");
//
//    anagramsFound = potentialSequences("goodness", doubleLetters, 8, results);
//    assert(anagramsFound == 1 && results[0] == "goodness");
//
//    anagramsFound = potentialSequences("settle", doubleLetters, 8, results);
//    assert(anagramsFound == 1 && results[0] == "settle");
    
    
    //tesst this
//    string longWords[] = {"ambidextrous","bejeweled", "california","ricochet"};
//    int anagramsFound = potentialSequences("bejeweled", longWords, 4, results);
//    assert(anagramsFound == 1 && results[0] == "bejeweled");
    
//   int anagramsFound = potentialSequences("ambidextrous", longWords, 4, results);
//    assert(anagramsFound == 1 && results[0] == "ambidextrous");
    
//    anagramsFound = potentialSequences("rambunctious", longWords, 4, results);
//    assert(anagramsFound == 0); //not in dictionary
    
//    outcomeDisclosure(doubleLetters, 8);
    
//    cout << "all test past!" <<endl;

return 0;
    
}

