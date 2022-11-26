#ifndef CURRENT_H
#define CURRENT_H

#include "Store.h"
#include "Milestone.h"
#include "Time.h"

#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Current{
    public:
    Current(); //constructor
    int box(); // puzzle function

    void choice(); // menu choices
    int travel(); //travel function
    void rest(); //rest function

    void setParty(); //make party
    int getParty(); //get party size

    string status(); //status function
    void Quit(); // call it when u want to quit game

    void shop(); //for visiting store
    void allHunt(); //for hunt function
    int getMiles(); //get miles travelled

    void misfortune(); //set misfortune function when u are unlucky :(
    void raider(); // raider function when u meet raiders

    int game(); // the game function
    void final();
    
    private:
    string date;
    string slash;
    string name;
    int stop;
    int victory;
    int players;
    int foxprob;
    int rabbitprob;
    int deerprob;
    int bearprob;
    int mooseprob;
    int puzzle;
    int tries;
    int guess;
    int mystery;
    double attack;
    int vat;
    int chef;
    int gun;
    double money;
    int chance;
    int person;
    int death;
    int step;
    int day;
    int month;
    int year;
    int index;
    int miles;
    int dist;
    int next;
    int option;
    static const int size=16;
    //int stones[size];
    //string path[size];
    vector<string> party;
    Store stores;
    Milestone path[size];
    Time clock;
    

};

#endif