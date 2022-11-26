#ifndef STORE_H
#define STORE_H
using namespace std;

class Store
{
    public:

    Store(); //default constructor

    
    int receipt(); // see amount of things left

    void buyOxen();
    int getOxen();
    void setOxen(int buf);
   // void setOxen(int o);

    void buyFood(); //for buying food
    double getFood(); // print current amount of food
    void setFood(double lb); //change amont of food after hunting, traveling etc..

    void buyBullets(); //for buying bullets
    int getBullets(); //print bullets
    void setBullets(int ammo); // change amount of bullets by amount of 'ammo'

    void buySupplies(); //for buyingg wagon parts and medical kits
    int getParts(); //get parts
    void setParts(int extra); //change wagon parts by amount 'extra'
    int getMed(); // get med
    void setMed(int kit); // change medical kit by ammount 'kit'
   
    double getCash(); // get cash
    double getBill(); // get bill
    void setCash(double p); // change cash by 'p'
    void setBill(int a);//set bill

    void setVat(int v); //change tax
    double getVat(); // get tax


    private:
    double tax;
    int food;
    double foodPrice;
    int bullets;
    double bulletsPrice;
    int oxen;
    double oxenPrice;
    int supplies;
    int suppliesPrice;
    int med;
    double medPrice;
    int parts;
    double partsPrice;
    double cash;
    double bill;
    
};
#endif