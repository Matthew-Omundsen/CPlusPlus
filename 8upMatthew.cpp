//Name: Matthew Omundsen
//Date: 10/03/25
//Program description: 8up card game using deck.h

// ACTUAL 8UP GAME
// shuffle deck before each game
// create 8 stacks each with one card on them
// nested for loop that compares every card on top of the stacks with each other
// if 2 cards are the same, put new cards on them
// if no cards are the same, game over and restart

#include <iostream>
#include "Deck.h"
#include <stack>
#include <vector>
#include <random>

int main() {
    random_device rd;
    mt19937 gen(rd());  // seeded once, seed is to get a different random number for each iteration of the while loop
    uniform_int_distribution<> dist(20, 100); // 20-100 range
    Deck deck;
    Card card;
    char user_input = 'y'; // allows user to play the game
    while (user_input == 'y') {
    int num_of_shuffles = 0;
    bool game_won = false;
    while (game_won == false) {
        cout << '\n';
        num_of_shuffles++;
        deck.MakeEmpty();
        deck.GenerateDeck();
        int shuffles = dist(gen); // random number between 20-100
        // cout << shuffles << "\n"; use this line to see number of shuffles
    for (int counter = 0; counter < shuffles; counter++) { // for loop must shuffle the deck a random number of times
        deck.Shuffle();
    }
    bool win_statement = true; // possible exit condition for while loop
    int cards_remaining = 44; // 52 cards - 8 cards initially put in the stacks = 44 cards remaining
    // creates 8 stacks of type card in an array
    vector <stack<Card>> stacks(8); 
    // for loop puts one card in each of the 8 stacks
    for (int counter = 0; counter < 8; counter++) {
        card = deck.GetNextItem();
        stacks[counter].push(card);
        cout << card.ToString() << "\n"; //this line will print the starting cards if it is desired
    }
    //while loop that loops the actual gameplay until no cards are left in deck or game is lost
    while (cards_remaining != 0 && win_statement == true) {
        bool match_found = false;
        //for loop that will loop through all 8 stacks and compare their top cards
        for (int stack1counter = 0; stack1counter < 8 && !match_found; stack1counter++) {
            Card card1 = stacks[stack1counter].top();
            for (int stack2counter = stack1counter + 1; stack2counter < 8; stack2counter++) {    
                Card card2 = stacks[stack2counter].top();
                // adds a card to both stacks if their cards are the same
                if (card1.GetRank() == card2.GetRank() && card1.ComparedTo(card2) != EQUAL) {
                    card = deck.GetNextItem();
                    stacks[stack1counter].push(card);
                    card = deck.GetNextItem();
                    stacks[stack2counter].push(card);
                    match_found = true;
                    cards_remaining -= 2;
                    break; // restart search with fresh tops
                }      
            }
        }
        if (match_found == false) { // if no matches are found, then game over
            win_statement = false;
            cout << "You lose :(\nCards left in deck: " << cards_remaining << "\n";
        }
    }
    if (cards_remaining == 0) {
        game_won = true;
        cout << "\nYou win!\nNumber of shuffles needed: " << num_of_shuffles << endl;
    }
    }
    cout << "Press y to play again: ";
    cin >> user_input;
}
}

            

        
        
        
        
        




