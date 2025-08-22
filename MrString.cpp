/*
String Pair
One person hands over the list of digits to Mr. String, But Mr. String understands only strings. Within strings also he understands only vowels. Mr. String needs your help to find the total number of pairs that add up to a certain digit 
D
D. The rules to calculate digit 
D
D is as follows:

Take all digits and convert them into their textual representation. Next, sum up the number of vowels i.e. 
a
,
e
,
i
,
o
,
u
 
a,e,i,o,u  from all textual representations. This sum is the digit 
D
D. Now, once digit 
D
D is known find out all unordered pairs of numbers in input whose sum is equal to 
D
D.

Input Format
The first line of the input contains an integer, 
T
T, denoting the number of test cases.
The first line of each test case will contain a single integer 
N
N, denoting the size of the array.
The second line of each test case contains 
N
N space-separated integers denoting elements of the array.
Output Format
Lower case representation of the textual representation of the number of pairs in input that sum up to digit 
D
D.

Constraints
1
≤
T
≤
10
1≤T≤10
1
≤
N
≤
1000
1≤N≤1000
1
≤
n
u
m
s
[
i
]
≤
100
1≤nums[i]≤100
Sample 1:
Input
Output
2
5
1 2 3 4 5
3
7 4 2
one
zero
Explanation:
For the first test case,
N
=
5
N=5 and array elements are 
[
1
,
2
,
3
,
4
,
5
]
[1,2,3,4,5].
1
1 -> one -> 
o
,
e
o,e
2
2 -> two -> 
o
o
3
3 -> three -> 
e
,
e
e,e
4
4 -> four -> 
o
,
u
o,u
5
5 -> five – > 
i
,
e
i,e
Thus, count of vowels in textual representation of numbers in input = 
2
+
1
+
2
+
2
+
2
2+1+2+2+2 = 
9
9. Number 
9
9 is the digit 
D
D referred to in the section above. Now from given list of number 
1
,
2
,
3
,
4
,
5
1,2,3,4,5 -> find all pairs that sum up to 
9
9. Upon processing this we know that only a single unordered pair 
4
,
5
4,5 sum up to 
9
9. Hence the answer is 
1
1.
However, output specification requires you to print the textual representation of number 
1
1 which is one. Hence the output is one.

For the second test case,
N
=
3
N=3 and array elements are 
[
7
,
4
,
2
]
[7,4,2].
7
7 -> seven -> 
e
,
e
e,e
4
4 -> four -> 
o
,
u
o,u
2
2 -> two -> 
o
o
Thus, count of vowels in textual representation of numbers in input = 
2
+
2
+
1
2+2+1 = 
5
5. Number 
5
5 is the digit 
D
D referred to in the section above. Since no pairs add up to 
5
5, the answer is 
0
0. The textual representation of 
0
0 is zero. Hence the output is zero.
*/

#include <bits/stdc++.h>
using namespace std;

vector<string>on={"","one","two","three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nineteen"};
vector<string>t={"","","twenty","thirty", "forty", "fifty", 
    "sixty", "seventy", "eighty", "ninety"};
    
string v(int n){
    if(n==0){
        return "zero";
    }
    if(n<20){
        return on[n];
    }
    if(n<100){
        return t[n/10]+(n%10?" "+on[n%10]:"");
    }
    if(n<1000){
        return t[n/100]+"hundred"+(n%100?" "+v(n%100):"");
    }
    return "too big";
}

int countvowel(string n){
    int c=0;
    for(int i=0;i<n.length();i++){
        if(n[i]=='a'||n[i]=='e'||n[i]=='i'||n[i]=='o'||n[i]=='u'){
            c++;
        }
    }
    return c;
}
int main() {
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       vector<int>arr(n);
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
       int c=0,p=0;
       for(int i=0;i<n;i++){
           c+=countvowel(v(arr[i]));
       }
       for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               if(arr[i]+arr[j]==c){
                   p++;
               }
           }
       }
       cout<<v(p)<<endl;
    }
	// your code goes here
	return 0;
}

