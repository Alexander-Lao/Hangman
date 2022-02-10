#include <iostream>
#include <fstream> //file reader
using namespace std;

string word;

int rights = 0;
string guess;
string temp;


int main() {
    //Start of random word generator (from the 1000 words in dictionary.txt)
    srand(time(0));
    int ran = (rand() %1000 * rand() %1000) %1000 +1; //random value from 1 to 1000

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

    // cout << word +"\n"; //Prints out the correct answer, DELETE AT END

    string answer[length];
    string response[length];

    //Setting the correct answer and current user response
    for(int i = 0; i < length; i++){
        answer[i].push_back(word[i]); 
        answer[i] = answer[i] + " ";
        response[i] = "_ ";
    }

    //user interaction loop
    while(rights < length){

        //prints out current response with filled in guesses
        for(int i = 0; i < length; i++){
            cout << response[i];
        }

        cout << "\n Enter a letter:";
        cin >> guess;
        temp = "";
        temp.push_back(guess[0]);

        //check if guess is right, if it is, add letter to response
        for(int i = 0; i < length; i++){
            if(answer[i] ==  temp + " " && response[i] != answer[i]){
                response[i] = answer[i];
                rights++;
            }
        }
    }
    cout << "Congrats the word was: " + word;

    return 0;
}