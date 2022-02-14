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

//Turns number into letter
char intToAlphabet( int i )
{
   return static_cast<char>('a' - 1 + i);
}

int main() {
    //Start of random word generator (from the 55000 words in dictionary.txt)
    int n=getrand(1,1000);
    int ran;
    for (int i=1; i<=n; i++) {
        ran = getrand(1,55000); //random value from 1 to 55000
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

    cout << "Welcome to Hangman! \n" << "Enter 1 to see used letters \n" << "Enter any other number to give up \n\n";
    //user interaction loop
    while(rights < length && lives > 0){

        cout << "You have " << lives << " lives \n";

        //prints out current response with filled in guesses
        for(int i = 0; i < length; i++){
            cout << response[i];
        }

        cout << "\nEnter a letter:";
        cin >> guess;

        //Check if input is a number or letter
        if(isdigit(guess[0])){
            //Display used letters
            if(guess[0] == '1'){
                cout << "\n";
                cout << "Already used: ";
                for(int i = 0; i < 26; i++){
                    if(used[i] == true){
                        cout << intToAlphabet(i+1) << " ";
                    }
                }
                cout << "\n\n";
            }
            //Quit game if any number other than 1 is used
            else{
                lives = -1;
            }
        }
        else{
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
    }

    if(lives > 0){
        cout << "Congrats the word was: " + word + "\nYou survivied with " << lives << " lives left";
    }
    else{
        cout << "The word was " + word;
    }

    return 0;
}