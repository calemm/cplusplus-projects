
/*
 * Author: Sabrina Ip
 * Date: Oct 4, 2015
 *
 * This program takes text from standard input
 * and gives the count for words, lines, characters,
 * as well as unique lines and unique words.
 *
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string; 
#include <set>
using std::set;
#include <stdio.h>
#include <ctype.h>


unsigned long countWords(const string& s, set<string>& wl) {
	int wordCount = 0;
	string word; //stores each letter until whitespace is reached
	int n = s.length(); //n is the input string's length
	int state = 0; //0 is whitespace, 1 is non-whitespace
	for (int i = 0; i < n; i++) { //goes through each character in s
		if (state == 0) { //start, or previous character was whitespace
			if (isspace(s[i])) {} //do nothing
			else {
				state = 1;
				word+= s[i]; //adds the letter into word
			}
		}
		else { //previous character was non-whitespace
			if (isspace(s[i])) {
				wordCount++;
				wl.insert(word);
				state = 0;
				word.clear();
			}
			else { // s[i] is not whitespace)
				word+= s[i];
			}
		}
	}
	if (n>0 && !(isspace(s[n-1]))) {
		wl.insert(word);
		wordCount++;
		word.clear();
	}
	return wordCount;
}

int main() {
	string line;
	set<string> wordSet;
	
	int lineCount = 0;
	int wordCount = 0;
	int wordCountHolder = 0;
	int characterCount = 0;
	int characterCountHolder = 0;
	int uniqueLineCount = 0;
	set<string> uniqueLineSet;
	int uniqueWordCount = 0;
	
	while(getline(cin, line)) {
		lineCount++;
		wordCountHolder = countWords(line, wordSet);
		if (lineCount == 1) {
			characterCountHolder = line.length();
		} else {
			characterCountHolder = line.length()+1; //accounts for new line
		}
		uniqueLineSet.insert(line);


		wordCount += wordCountHolder;
		characterCount += characterCountHolder;
		uniqueLineCount = uniqueLineSet.size();
		uniqueWordCount = wordSet.size();

	}

	cout << "lines: " << lineCount << endl;
	cout << "words: " << wordCount << endl;
	cout << "characters: " << characterCount << endl;
	cout << "unique lines: " << uniqueLineCount << endl;
	cout << "unique words: " << uniqueWordCount << endl;
	return 0;
}
