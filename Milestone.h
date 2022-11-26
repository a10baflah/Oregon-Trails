#ifndef MILESTONE_H
#define MILESTONE_H

#include <string>
using namespace std;

class Milestone {
    public: 

    Milestone();

    void setLocation(string place); // set milestone name
    string getLocation(); // get milestone name

    void setDistance(int space); //set milestone distance from start
    int getDistance(); //get milestone distance

    private:
    string location;
    int distance;
};

#endif