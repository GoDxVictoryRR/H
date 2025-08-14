/*
Problem Statement
Ravi discovered a special type of number called Filo Numbers, which are any numbers that can be expressed as a sum of consecutive natural numbers.
He found that every positive integer can be represented as a Filo Number. However, he realized that some integers can be expressed as a Filo Number in multiple ways.
Now, he needs help calculating how many different ways a given positive integer N can be expressed as a Filo Number.

Input Format
The first and only line of input contains an integer N.

Output Format
Print an integer which represent the number of ways N can be expressed as a Filo Number.

Constraints
1 <= N <= 10^6

Sample Testcase 0
Testcase Input
9
Testcase Output
3
Explanation
There are three ways in which nine can be expressed as a Filo Number -> 
(9), (2 + 3 + 4), (4+5)
Sample Testcase 1
Testcase Input
15
Testcase Output
4
Explanation
There are four ways in which 15 can be expressed as a Filo Number ->
(15), (8+7), (4+5+6), (1+2+3+4+5)
*/
#include <iostream>
using namespace std;

// Placeholder function where user will write their logic
int countFiloWays(int n) {
    // Write your logic here
    int c=0;
    for(int k=1;k*(k-1)/2<n;k++){
        int num=n-k*(k-1)/2;
        if(num%k==0){
            c++;
        }
    }
    return c; 
}

int main() {
    int n;
    cin >> n;

    // Call user logic function and print the output
    int result = countFiloWays(n);
    cout << result << endl;

    return 0;
}
