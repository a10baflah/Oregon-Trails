#include <iostream>
#include "Milestone.h"

using namespace std;

    Milestone::Milestone(){
        location="";
        distance=0;
    }

    void Milestone::setLocation(string place){ //set milestone name
        location=place;
    }
    string Milestone::getLocation(){ //get milestone name
        return location;
    }

    void Milestone::setDistance(int space){ //set milestone distance in miles
        distance=space;
    }
    int Milestone::getDistance(){ //get milestone distance
        return distance;
    }