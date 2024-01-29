
#include<iostream>
#include<queue>

using namespace std;

bool reOrganise(string str) {

    int freq[26] = {};

    for (char ch : str) {
        freq[ch - 'a']++;
    }

    priority_queue<pair<int, char>> maxHeap;

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            maxHeap.push({freq[i], i + 'a'});
        }
    }

    string out = "";

    while (!maxHeap.empty()) {

        if (maxHeap.size() == 1) {

            pair<int, char> maxPair = maxHeap.top();
            maxHeap.pop();

            if (maxPair.first > 1) {
                out = "";
            } else {
                out += maxPair.second;
            }

        } else {

            pair<int, char> firstMaxPair = maxHeap.top();
            maxHeap.pop();

            pair<int, char> secondMaxPair = maxHeap.top();
            maxHeap.pop();

            out += firstMaxPair.second;
            firstMaxPair.first--;

            out += secondMaxPair.second;
            secondMaxPair.first--;

            if (firstMaxPair.first > 0) {
                maxHeap.push(firstMaxPair);
            }

            if (secondMaxPair.first > 0) {
                maxHeap.push(secondMaxPair);
            }

        }
    }

    cout << out << endl;

    return out == "" ? false : true;

}

int main() {

    string str = "aaaaabbbbcccdd";

    reOrganise(str) ? cout << "true" << endl : cout << "false" << endl;

    return 0;
}