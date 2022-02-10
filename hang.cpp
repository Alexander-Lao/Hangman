#include <iostream>
#include <fstream> //file reader
#include <bits/stdc++.h>
using namespace std;

string word;
int rights = 0;
string guess;
string temp;
bool alreadyAnswered;
int prevRights = 0;
int lives = 10;

bool used [26];

//Function for random number generator
mt19937 seed(chrono::high_resolution_clock::now().time_since_epoch().count());
int getrand(int l,int r) {
    uniform_int_distribution<> gen(l,r);
    return gen(seed);
}


int main() {
    //Start of random word generator (from the 1000 words in dictionary.txt)
    int n=getrand(1,1000);
    int ran;
    for (int i=1; i<=n; i++) {
        ran = getrand(1,1000); //random value from 1 to 1000
    }

    ifstream dictionary; 

    dictionary.open("dictionary.txt"); //there are a couple of sketchy words in here
    if(dictionary.is_open()){
        string x;

        for (int i = 0 ; i < ran ; i++){ 
	        dictionary >> x;
        } 
        word = x;
        dictionary.close();
    }
    int length = word.length();
    //End of random word generator

    string answer[length];
    string response[length];

    //Setting the correct answer and current user response
    for(int i = 0; i < length; i++){
        answer[i].push_back(word[i]); 
        answer[i] = answer[i] + " ";
        response[i] = "_ ";
    }

    //user interaction loop
    while(rights < length && lives > 0){

        cout << "you have " << lives << " lives \n";

        //prints out current response with filled in guesses
        for(int i = 0; i < length; i++){
            cout << response[i];
        }

        cout << "\n Enter a letter:";
        cin >> guess;

        int x = guess[0];
        x -= 97; //Changes char into number
        if(used[x] == true){
            alreadyAnswered = true;
        }
        else{
            used[x] = true;
        }
        
        //wins when user guesses right answer
        if(guess == word){
            rights = length;
        }

        temp = "";
        temp.push_back(guess[0]);

        //check if guess is right, if it is, add letter to response
        for(int i = 0; i < length; i++){
            if(answer[i] ==  temp + " " && temp + " " != response[i]){
                response[i] = answer[i];
                rights++;
            }
        }

        if (prevRights == rights && alreadyAnswered == false){
            lives--;
        }
        prevRights = rights;
        alreadyAnswered = false;
    }

    if(lives > 0){
        cout << "Congrats the word was: " + word + "\nYou survivied with " << lives << " lives left";
    }
    else{
        cout << "The word was " + word;
    }

    return 0;
}