/* Programming Assignment no: 1.                                         p3.cpp
 * Author: Parag khodke
 * Version: Created on feb-28 (On X' Code)
 * Copyright © Best practice for programmers based on industry and education
 standards.This is for eduction purpose only.
 all rights reserved , use with my express written permission only
 * Descripition: This program is written in c++.
 * we create a wish game here.
 * iostream for input,output, string library for I/O string and print.
 * time library to generate random values for suits and cards.
 * create array of string for suits and aray of string for cardsValue
 * use random function to choose randomly suits and randomly caedValue
 * set genie suits value and genie card Values.
 * checking users suits entry if not valid print menu again
 * if user enter quit-it will exit the code
 * again checking users card value to genie card value,
 * if both true-get a wish,if not-exit the code.
 * we comment out genies " suits and card value "
 */

#include <iostream> // for the standard stream
#include<string> // string header
#include<time.h> // time library
#include<math.h> // math library
#include <fstream> // for file stream

using namespace std;

int main()
{
    string userName; // for user name
    string userSuitsName; // for suits of a card
    string userCardNumber; // for cards values for
    
    string SuitsNumber[4] = { "hearts ", "diamonds ", "clubs ", "spades "} ; // create 4 string name for suits
    string cardsValue [13] = {"ace", "two","three","four", "five", "six",
        "seven","eight", "nine","ten","jack","queen","king"}; //create 13 string elements for cards_value
    
    srand( time(0) ); // use random function
    
    int indexOfcards = rand() % 4 ; //  random index for suits
    int indexOfSuits = rand() % 13 ; // random index for cardsvalue
    
    string GenieSuitsChoice = SuitsNumber[indexOfcards]; // store genie suits choice derived from random index
    //cout<< "Secret Genie suits choice is:- "<<GenieSuitsChoice << "\n"; // print genie cards'value
    
    string genieCardsValue; // string for users cards value
    genieCardsValue = cardsValue[indexOfSuits];// store genie card value choice derived from random function
    //cout<< "Secret Genie Cards Value: " << genieCardsValue<< "\n"; // print genie value
    
    cout <<"\n\nHello user! kindly, Please enter your name ?" << endl; // print greetings !
    cin >> userName; // get users name
    cout <<"\nWelcome " << userName <<", Thank you for choosing the game.\n\n";// print username and thank him first to choose game
    cout << "\tIn this game, Your wish will be granted ";
    cout << "if you can guess the card chosen by genie.";
    cout << "\n\tThe genie will choose a card at random and you have to guess:";
    cout << "which one it is. n\tIf you choose correctly, ";
    cout << "\nyour wish is granted!\n\nLets play the game now"  << endl; // explain game
    
    
    // while loop to till following conditions are true
    while (1) {
    
        cout << "\n\nPlease guess your suits from below choice: \n" << endl; // print statement to enter players name
        for( int i =0; i< 4; i++) // for loop to print suits option
        {
            cout<< "" <<SuitsNumber[i] <<endl; // print suits value for user
        }
        cout << "quit game"<<endl<<endl; // print quit option on bottom of suits number
        cin>> userSuitsName; // get user suits name
        cout << "\nyou entered:-" << userSuitsName <<endl; // print users suits entry
       
        bool isInSuit = false; // set false flag for suits
        bool isInCardValue = false; // set flag false for cards value
        
        for (int j=0; j< 4; j++){ // for loop to print suits name from suits menu
            if (SuitsNumber[j] == userSuitsName){ // compare if users suit number entry is in suits menu or not
                isInSuit = true; // set flat for suits True
                break; // break loop if flag is true
            }
        }
        if (userSuitsName != "quit" && isInSuit){ // checking users suit and quit option
           
            if (userSuitsName == GenieSuitsChoice ){// compare users suit name to genie suits
                
                while(true){
                    cout<<"\n\nPlease guess your card from below choice:\n\n"; // print statement to enter players name
                    // cout << "\n\nyou are just one steps away to get your wish.\n"; // print general statements for guess correct suits name
                    
                    for (int i=0; i<13; i++){ //for loop to print cards value
                        cout<< "" <<cardsValue[i] << endl; // print card values menu for users
                    }
                    cout<< "quit game"<<endl; // print quit menu below the cards value
                    cout<< "\n\nEnter your guess for card value\n";
                    cin>> userCardNumber; // get user card value
                    cout <<"\nYou entered :-" << userCardNumber <<endl;
                    
                    for (int j=0; j< 13; j++){ // for loop to print cards value menu
                        if ( cardsValue[j] == userCardNumber){ // compare users card nummber from suitsn option
                            isInCardValue = true; // flat set for cards value here..
                            break;
                        }
                    }
                    if (userCardNumber != "quit" && isInCardValue ){ // checking users entry is in card value and did not input quit option
                        if (userCardNumber == genieCardsValue ) // if both matces with genie users card value and genies card value
                        {
                            cout << "\nCongratulations.!! "<<userName ;
                            cout << "\nYour guess for suits is :- "; // print congratulation message for users
                            cout<< userCardNumber << " of "<< userSuitsName ; // print user's both suits name and cards value
                            cout<<", is matches with Genies ! ";
                            cout << "\nYou can make a wish now\n\n";
                            break;
                        }
                        else{
                            cout<<"Sorry, " << userName << " You entered :- "; // print users card value entry
                            cout << userCardNumber ;
                            cout << " ,for card value which is wrong";
                            cout <<"\nYou can visit the game again !! ";
                            cout << "thank you \n" ;
                            break;
                        }
                    }
                    else if (userCardNumber == "quit"){ // checking quit options
                        cout<<"\n\nThank you parag for playing the game.";
                        cout << "Hope you had some fun\n";
                        break; //close game if user enter quit game
                    }
                    else{
                        cout << "Wrong input for card value! ";
                        cout<< "try again from below option ";
                        
                    }
                }
                break;
            }
            else{
                cout<<userName<<", Your guess for suits is invalid!";
                cout << "You can try again from start!\n";
                break; // exit game if user did not guess the correct cards
            }
        }
        else if(userSuitsName == "quit"){// exit from first quit
            cout<< "\n\nThank you " <<userName << " for Playing game\n"; // print thank you for using game if user quit the game
            break;
        }
        else{//done
            cout<< "\n\n"<<userName<<", Your guess is Invalid Suits choice,"; // print users invalid suits choice
            cout << " Please try again from menu.";
        }
    }
    cout << "\nYour selection was :-" ;
    cout <<userSuitsName <<  ","  << userCardNumber <<"."<< endl; // print users suits and card number
    cout << "Thank you for using'get your wish' game by P. khodke.. Bye!!!\n\n";
    return 0; // return 0 to main
}



