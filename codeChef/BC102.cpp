#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  getline(cin, s);
  stringstream ss(s);
  // get the first word
  string firstWord;
  ss >> firstWord;
  // reverse the first word
  string reversed = "";
  for (int i = firstWord.length()-1; i >= 0; i--) {
    reversed += firstWord.at(i);
  }
  // put the rest of the string in a vector
  vector<string> restOfWords;
  string temp;
  while(ss >> temp) {
    restOfWords.push_back(temp);
  }
  // concatenate the reversed word and the rest of the words together
  string finalWord = reversed;
  for (auto it = restOfWords.begin(); it != restOfWords.end(); it++) {
    finalWord += " " + *it;
  }
  cout << finalWord << endl;
}