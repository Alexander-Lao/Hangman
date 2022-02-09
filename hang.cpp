#include <iostream>
using namespace std;

string word = "dictionary";

int main() {

    int length = word.length();
    string answer[length];
    string response[length];

    for(int i = 0; i < length; i++){
        answer[i].push_back(word[i]); //Change char into string to add space behind
        answer[i] = answer[i] + " ";
        response[i] = "_ ";
    }

    int rights = 0;
    string guess;
    string temp;

    while(rights < length){

        for(int i = 0; i < length; i++){
            cout << response[i];
        }
        cout << "\n Enter a letter:";
        cin >> guess;
        temp = "";
        temp.push_back(guess[0]);


        for(int i = 0; i < length; i++){
            if(answer[i] ==  temp + " "){
                response[i] = answer[i];
                rights++;
            }
        }
    }
    cout << "Congrats the word was: " + word;

    return 0;
}