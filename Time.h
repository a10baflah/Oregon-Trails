#ifndef TIME_H
#define TIME_H
using namespace std;
class Time{
    public:
        Time(); //default constructor
        Time(int m, int d, int y); //parameterized constructor

        void setDate(int m, int d, int y); //set date
        void setTime(int step); //calculate travel time
        void getTime(); // print date

        string getDate();
        int deadline(); //deadline of the game

    private:
        int day;
        int month;
        int year;
        string date;

};
#endif