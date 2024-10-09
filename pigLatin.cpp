#include<iostream>
#include<string>
using namespace std;

string pigLatin(string);

int main(){
    string sentence ;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    string pigLatinSentence = "";
    string word = "";

    for(int i = 0; i < sentence.length(); i++){
        if(sentence[i] == ' ' || i == sentence.length() - 1 ){
            if(i == sentence.length() - 1){
            word += sentence[i];
            }
            pigLatinSentence += pigLatin(word) + " ";
            word = "";
        }else{
        word += sentence[i];
    }
    }

    cout << "The Pig Latin sentence is: " << pigLatinSentence << endl;
    return 0;
}
 string pigLatin(string word){
    char firstLetter = word[0];
    word.erase(0,1);
    word += firstLetter;
    word += "ay";
    return word;
 }