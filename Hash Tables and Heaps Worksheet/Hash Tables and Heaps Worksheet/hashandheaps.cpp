//
//  main.cpp
//  Hash Tables and Heaps Worksheet
//
//  Created by Coco Li on 8/18/23.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

int firstUniqueChar(std::string s) {
    unordered_map<char,int> count; //what we will use to check whether smth repeats
    for (int i = 0; i < s.size(); i++){
        count[s[i]]++ ; //placing the char into the map and giving it a value to say how many of the char is in it --> this is a way in c++ that counts how many occurences of one char there is (unordered_maps can do this mostly because it uses a hash functoin that assigns the char to a bucket. if there is a repeating char then the hash function will return to the same bucket and use a close hash table
    }
    for (int i = 0; i < count.size(); i++){
        if (count[s[i]] == 1){
            return i;
        }
    }
    return -1;
}

//use an unordered_set to store the target values
//4,8,3,7,9,2,5,
//target 15

//add each item and put it in the set

bool twoSum(int arr[], int n, int target){ //where n is the size of the array
    unordered_set<int> numsArr; //the value we need to match
    for (int i = 0; i < n; i++){
        int compliment = target - arr[i];
        if (numsArr.find(compliment) != numsArr.end()){
            return true; //we return true because if it equal the end then there was no value found that would give us the target calue  --> end() gives us past the last node
        }
        else{
            numsArr.insert(arr[i]); //put into the set
        }
    }
    return false;
}

// Given a string, compute its hash value based on prime numbers int

int calculateHash(string word){
    int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    int hash_val = 1;
    for(int i = 0; i < word.size(); i++) {
    // Multiplying by prime numbers ensures that all words // with the same characters will have the same product
        hash_val *= primes[word[i]-'a'];
    }
    return hash_val;
}

vector<vector<string>> groupAnagrams(vector<string> strs) {
    unordered_map <int, vector<string>> anagrams; //int will be the key of where we hash the function to
    for (int i = 0; i < strs.size(); i++){
        int key = calculateHash(strs[i]); //calculate the hash value of the word and then store this key in a map to tell us where its at
        anagrams[key].push_back(strs[i]); //at that key value store the word
        //words anagrams of each other will be stored at the same key within the map
        //REMEMBER HASH FUNCTION JUST GIVES US WHERE TO STORE THE VALUE!!!
        //IF WE DO NOT STORE THAT VALUE IN THE HASH FUNCTION THERE WILL BE AMBIGUITY AND EVENTUALLY LEAD TO COLLISIONS
    }
    vector<vector<string>> results; //will store our anagrams tgt --> 2d vector
    //for each word's anagrams, they are currently stored in a vector of strings within the map
    //now we want to store each of the anagrams vector into another vector
    
    
//    for (int j = 0; j < anagrams.size(); j++){ //use anagrams cuz thats where our data is current stored
//        results.push_back(anagrams[j]); //put each of the vetor
//    }
//   ^^ DO NOT USE THE FOR LOOP LIKE THIS BECAUSE IT WONT GET U ALL THE GROUPED ANAGRAMS --> YOU ARE USING J AS THE INDEX TO GO INTO THE ANAGRAMS BUT IN ANAGRAMS THE INDEXES ARE STORED BY KEY HASHED VALUES NOT INDEXES LIKE AN ARRAY --> MUST USE AN ITERATOR
    unordered_map<int, vector<string>>::iterator it = anagrams.begin(); //this iterator will traverse thru the key values
    while (it != anagrams.end()){
        results.push_back(it -> second);
        //doing it -> second because within results we want to push the value from anagrams into the inner vector
        //recall we are storing each words anagram (which in itself is alr a vector) into another vector specfiically for the anagrams
        it++;
    }
    return results;
}

bool isMaxHeap(const int arr[], int len){
    for (int i = 0; i < len; i++){
        int left = 2*i+1;
        int right = 2*i+2;
        //left < len and right < len to check that the children are within the bounds? --> check during ofh
        if ((left < len && arr[i] <= arr[2*i+1]) || (right < len && arr[i] <= arr[2*i+2])) //greataer than or equal to its 2 children
        {
            return false;
        }
    }
    return true;
}

struct Node {
    int val;
    Node* left;
    Node* right;
   };
   
bool isMinHeap(Node* head){  //can use recursion --> min should be at the top
    if (head == nullptr){
        return true;
    }
    //have to make sure children are not nullptr because a minHeap can still be valid if its children are nullptrs
    if ((head -> left != nullptr && head -> left -> val < head -> val) || (head -> right != nullptr && head -> right -> val < head -> val)){
        return false;
    }
    bool leftRes = isMinHeap(head ->left); //check left nodes
    bool rightRes = isMinHeap(head-> right);
    return leftRes && rightRes;
    //if both are true will return true --> if one is false but the other true it will return false
    //recall && mean both have to be true to return true
 }

class Bank {
public:
    void insert (int amount, int userId, int accountId);
    int search (int userId, int accountId);
private:
    unordered_map<int, unordered_map<int,int>> bankDataBase;
    //where the outer map maps the accountID and the balance to the userID
    //iner map maps the balance to the accountId
};


void Bank::insert(int amount, int userId, int accountId){
    auto userMap = bankDataBase.find(userId); //first check to find if there is a userID of person we want to add
    if (userMap ==  bankDataBase.end()){
        //create new account
        unordered_map<int, int> accountMap;
        accountMap.insert({accountId,amount});
        bankDataBase.insert({userId,accountMap});
    }
    else{ //add accountId to an already exisiting user
        auto userAccountMap = userMap -> second;  //found the matching userId so we want to now get the account Map which is the inner map
        userAccountMap.insert({accountId,amount}); //add the account map int
        bankDataBase.insert({userId,userAccountMap});
    }
}

int Bank::search(int userId, int accountId){
    auto userMap = bankDataBase.find(userId); //userMap will point to the foudn element
    if (userMap == bankDataBase.end()){//count find it
        return -1;
    }
    else{ //found user Id so now we want to find match account
        unordered_map<int, int> accountMap = userMap -> second;
        auto account = accountMap.find(accountId);
        if (account != accountMap.end()){ //found match account ID so we return the account ID number
            return account -> second;
        }
    }
    return -1;
}



int main() {
    // insert code here...
    cout << " 我爱" << "baobao" << endl;
    return 0;
}


