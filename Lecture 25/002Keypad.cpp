/*

Given a phone keypad as shown below, and an n digit number, print all words which are possible by
pressing the n digits on the keypad.

 1()     2(abc) 3(def)
 4(ghi)  5(jkl) 6(mno)
 7(pqrs) 8(tuv) 9(wxyz)

*/

#include<iostream>

using namespace std;

string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// void f(char* inp, char* out, int i, int j) {

//     // base case
//     if (inp[i] == '\0') { // i == n
//         out[j] = '\0';
//         cout << out << endl;
//         return;
//     }

//     // recursive case

//     // you've to decisions for the remaining n-i starting from the ith digit

//     int d = inp[i] - '0';

//     if (d == 0 or d == 1) {
//         // skip this digit
//         f(inp, out, i + 1, j);
//         return;
//     }

//     string optionString = keypad[d];

//     for (char option : optionString) {
//         out[j] = option;
//         f(inp, out, i + 1, j + 1);
//     }

// }

void f(char* inp, string out, int i) {

    // base case
    if (inp[i] == '\0') { // i == n
        cout << out << endl;
        return;
    }

    // recursive case

    // you've to decisions for the remaining n-i starting from the ith digit

    int d = inp[i] - '0';

    if (d == 0 or d == 1) {
        // skip this digit
        f(inp, out, i + 1);
        return;
    }

    string optionString = keypad[d];

    for (char option : optionString) {
        out.push_back(option);
        f(inp, out, i + 1);
        out.pop_back(); // backtracking step
    }

}


int main() {

    // char inp[] = "213";
    // char out[10];

    // f(inp, out, 0, 0);

    char inp[] = "213";
    string out;

    f(inp, out, 0);


    return 0;
}