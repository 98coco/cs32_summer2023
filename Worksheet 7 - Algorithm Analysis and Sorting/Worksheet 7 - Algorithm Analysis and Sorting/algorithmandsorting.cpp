//
//  main.cpp
//  Worksheet 7 - Algorithm Analysis and Sorting
//
//  Created by Coco Li on 8/9/23.
//

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

// 1) What is the time complexity of the following code --> O(n^3) because of the nested loops
int randomeSum(int n){
    int sum = 0;
    for(int i =0; i< n;i++){ //O(n)
        for(int j =0;j<i;j++){ // O(n)
            if (rand() %2 ==1){
                sum+=1;
            }
            for(int k=0; k<j*i;k+=j){ //O(n) --> can "cancel" out the j because we are incrementing k by j; example i = 6, j = 5 --> k < 30 --> k+=5
                //k= 5, k =10, k=15, k= 20, k=25, k=30 as we update k we technically reduce the steps in this for loop because we run this for loop less than 30 times
                
                //this is O(n)
                if (rand() %2 ==1){
                    sum+=1;
                }
            }
        }
    }
    //nested so we multiply to get to O(n^3)
    return sum;
}

//2) What is the time complexity of the following code
int operationFoo(int n, int m, int w){
    int res = 0;
    for (int i = 0; i < n; ++i){  //outer loop runs n times O(n)
        for (int j = m; j>0; j/=2){ // this loop runs log_2m times --> because we are diving until 1 --> O(log_2(n))
            for (int jj = 0; jj<50; jj++){ //jj runs 49 times O(1) because constant
                for (int k = w; k>0;k -=3){ //k
                    //w = 30
                    //loop will run 10 times
                    //w = 60
                    //loop will run 20 times
                    //O(w/3) --> O(w)
                    res += i*j +k;
                }
            }
        }
    }
    return res;
}
//O(wn*log_2m)

//3) What is the time complexity of the following code

//O(a*log_2a)+O(b^2)

int obfuscate(int a, int b) {
    vector<int> v;
    set<int> s;
    for (int i = 0; i < a; i++) { //a times
        v.push_back(i); // O(1)
        s.insert(i); //O(log_(size of set))
        
    }
    v.clear(); //O(n)
    int total = 0;
    if (!s.empty()) { //o(1)
        for (int x = a; x < b; x++) {  //O(b) times
            for (int y = b; y > 0; y--) { // O(b)
                total += (x + y);
            }
        }
    }
    return total; //not right its the next line
//    return v.size() + s.size() + total;
}
//
//4. Here are the elements of an array after each of the first few passes of a sorting
//algorithm discussed in class. Which sorting algorithm is it?
//3 7 4 9 5 2 6 1
//3 7 4 9 5 2 6 1
//3 7 4 9 5 2 6 1
//3 4 7 9 5 2 6 1
//3 4 7 9 5 2 6 1
//3 4 5 7 9 2 6 1
//2 3 4 5 7 9 6 1
//2 3 4 5 6 7 9 1
//1 2 3 4 5 6 7 9

//look at the worksheet because some are bolded
//insertion sort because the left is always sorted as we move on
//
//5. Given the following vectors of integers and sorting algorithms, write down
//what the vector will look like after 3 iterations or steps and whether it has
//been perfectly sorted.

//a. {45, 3, 21, 6, 8, 10, 12, 15} insertion sort (1st step starts at comparing a[1])

//s = 2
// sortMe = A[1] = 3
// i = 0
// a[0] = 45
// a[1] = a[0] = 45
// i = -1
// a[0] = sortMe = 3
// {3,45,21,6,8,10,12,15}

// s = 3
// sortMe = A[2] = 21
// i = 1
// a[1] = 45
// a[2] = a[1] = 45 --> {3,45,45,6,8,10,12,15}
// i = 0
// a[1] = sortMe = 21
// {3,21,45,6,8,10,12,15}

// s = 4
// sortMe = A[3] = 6
// i = 2
// a[2] = 45
// a[3] = a[2] = 45 --> {3,21,45,45,8,10,12,15}
// i = 1
// a[2] = a[1] = 21 --> {3,21,21,45,8,10,12,15}
//i = 0
// a[1] = 6 --> {3,6,21,45,8,10,12,15}

// not fully sorted after 3 iterations

//b. {5, 1, 2, 4, 8} bubble sort (Consider the array after 3 “passes” and after 3 “swaps.” Do the results differ? Does the algorithm know when it’s “done” in either case?)
//j<4
//j=0
// false
// {1,5,2,4,8}
// true;
// false;
//j = 1
//{1,2,5,4,8}
//true;
//false;
//j=2
//{1,2,4,5,8}
//true;
//false;
//sorted after 3 iterations

//c. {-4, 19, 8, 2, -44, 3, 1, 0} quicksort (where pivot is always
//the last element)
//
// {-4,-44,0,19,8,2,3,1}
// {-44,-4,0,1,19,8,2,3}
//not sorted after 3 iterations
//

//6. Consider this function that returns whether or not an integer is a prime number:
bool isPrime(int n) {
    if (n < 2 || n % 2 == 0) return false; //O(1)
    if (n == 2) return true; // O(1)
    for (int i = 3; (i * i) <= n; i += 2) { //O(sqrtn) because at most (i*i) = n where sqrt n gives us a i where i*i = n
        if (n % i == 0) return false;
    }
    return true;
}
//What is its time complexity? O(sqrtn)

//7. fill in the box
// Time Complexity of Inserting an Element to the Beginning
// Linked List: O(1)
// Array/Vector : O(n)
//
// Inserting an element to some posiiton i
//LinkedList: O(1) --> because of pointers
//Array/Vector: O(n) -- >have to shift items around
//
//Getting the value of an element at position i
//Linked List: O(n) or O(1) if the position is the top or end
//Array/Vector: O(1) //because we can just index i
//
//Changing the value of an element at position i
//Linked List: O(n) --> pointers
//Array/Vector: O(1)
//
//Deleting an Element given a reference to it
//Linked List: O(1) --> becauase we can just make a pointer point to that address
//Array/Vector: O(n) --> because we have to check each element in the array befor having a matching address
//

//Write a function for which, given a vector of words and a character, returns
//the number of times that character is present in the entire vector. Then, find
//the time complexity of your algorithm.

int countNumOccurrences(const vector<string>& words, char c){
    int num = 0;
//    vector<string>::const_iterator it; //use an iterator to check words
    for (int i =0; i < words.size();i++){//getting each word //O(depends on the size of vector)
        for (int j = 0; j < words[i].size();j++){ //one for in the vector
            //O(depends on the size of the word)
            if (words[i][j] == c){
                num++;
            }
        }
    }
    return num;
}

//time complexity of this function O(N*K)

//9. Given an array of n integers, where each integer is guaranteed to be between
//1 and 100 (inclusive) and duplicates are allowed, write a function to sort the
//array in O(n) time.
//(Hint: the key to getting a sort faster than O(n log n) is to avoid directly
//comparing elements of the array!) (MV)

void sort(int a[], int n){ //ask abt this in ofh
    
}

int main() {
    vector <string> hi;
    hi.push_back("coco");
    hi.push_back("hi");

    char c = 'k';
    cout << countNumOccurrences(hi,c);
    cout << endl;
    
    cout << 1/2 <<endl;
    cout << min(0,9);
}

