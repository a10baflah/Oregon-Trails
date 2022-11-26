#include <iostream>
#include<string>
#include "Time.h"

using namespace std;

Time::Time(){ //default constructor
    day=1;
    month=3;
    year=1847;

}

Time::Time(int m, int d, int y){ //parmartized constructor
    month=m;
    day=d;
    year=y;
}
void Time::setDate(int m, int d, int y){ // set date
    month=m;
    day=d;
    year=y;
}
void Time::setTime(int step){ //step is the amount of days that pass in journey
    while(step>0){
        day++; //increase day
        step--; //decrease day(step)
        if(day==31){
            //if days is 31 and the month is one of the one down below. it will reset day to 1 and increase month
            if(month==4 || month==6 || month==9 || month==11){//these months only have 30 days
                day=1;
                month++;
            }
        }
        if(day==32){
            //if days is 32 and the month is one of the one down below. it will reset day to 1 and increase month
            if(month==1 ||month==3 || month==5 || month==7 || month==8 || month==10){//these months only have 31 days
                day=1;
                month++;
            }
        }
    }

}
void Time::getTime(){// print date
    cout<<month<<"/"<<day<<"/"<<year<<endl;
}
string Time::getDate(){
    date=(to_string(month))+"/"+(to_string(day))+"/"+(to_string(year));
    return date;
}
int Time::deadline(){ //this is what happens if you exceed nov 30 1847
    if(month==12){
        return 0;
    }
    if(year==1848){
        return 0;
    }
    else{
        return 1;
    }
}