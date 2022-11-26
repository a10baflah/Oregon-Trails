
#include <iostream>
#include "Store.h"

using namespace std;

    Store::Store(){ // initialize everything to default
        oxen=0;
        food=0;
        bullets=0;
        med=0;
        parts=0;
        cash=1600;
        bill=0.0;
        tax=1;
    }
    void Store::setVat(int v){ //update tax
        tax=(v*0.25)+1;
    }
    double Store::getVat(){ // get tax
        return tax;
    }

    void Store::buyOxen(){
        //increase tax depending on fort
        double oxenCost=40*tax; //cost of yoke with tax
        int o=10;
        cout<<"You must spend between $100 to $200 dollars on oxen. There are 2 oxen in a yoke and the price of each yoke is $40.0."<<endl;
        while(o<3 || o>5){
        cout<<"How many yokes do you wish to purchase?: ";
        cin>>o; //pick amount of yoke between 3 and 5

        if(o>=3 && o<=5){
            oxenPrice=oxenCost*o; //this is final bill
            if(oxenPrice>cash){ //if bill is greater than cash
                cout<<"You do not have enough money to buy this amount. Please choose a fewer amount."<<endl;
                o=0;
                break;
            }
            else{
            oxen=oxen+(o*2); //set oxen number
            cash=cash-oxenPrice; //subtract bill from cash
            bill=bill+oxenPrice; // update bill
            }
        }
        else{ //not by limit
            if(o>5){
                cout<<"You have chosen to spend more than $200 on yokes, please choose again."<<endl;
            }
            if(o<3){
                cout<<"You have chosen to spend less than $100 on yokes, please choose again."<<endl;
            }
        }

        }
        cout<<endl;
        cout<<"Your current bill is: "<<bill<<endl; //print bill
        
    }
    int Store::getOxen(){ //print oxen
        return oxen;
    }
    void Store::setOxen(int buf){ //change oxen by 'buf'
        oxen=oxen+(buf);
    }


    void Store::buyFood(){
        double foodCost=0.5*tax; //food cost
        int b=1111;
        cout<<"I recommend at least 200 lbs. per person at the price of $0.5 per pound. "<<endl;
        cout<<"Remember the wagon cannot hold more than 1000 lbs. of food."<<endl;
        while(b>1000 || b<0){
            cout<<"How many pounds of food do you wish to purchase?: ";
            cin>>b;
            if(b<=1000){//if food lbs less than 1000
                foodPrice=foodCost*b; //the total price 
                if(foodPrice>cash){ //if you dont have enough money
                    cout<<"You do not have enough money to buy this amount. Please choose a fewer amount."<<endl;
                    b=1111;
                }
                else{
                food=food+b;//update food amount
                cash=cash-foodPrice; //subtrct cash by total amoun of bill
                bill=bill+foodPrice; //update bill
                }
            }
            else{// if you buy more than limit
                cout<<"You can't buy more than 1000 lbs of food"<<endl;
            }
        }
        cout<<endl;
        cout<<"Your current bill is: "<< bill<<endl;
    }

    double Store::getFood(){ //get food in pounds
        return food;
    }
    void Store::setFood(double lb){ //change food by lb
        food=food+(lb);
    }

    void Store::buyBullets(){
        //increase tax depending on fort
        double bulletCost=2*tax; //cost of box of bulllets with tax
        int c=-1;
        while(c<0){
            cout<<"A box of 20 bullets costs $2.0."<<endl;
            cout<<"How many boxes do you wish to purchase?: "<<endl;
            cin>>c;
            if(c>=0){
                bulletsPrice=c*bulletCost; //total price of bullets
                if(bulletsPrice>cash){ //if u dont have enough money
                    cout<<"You do not have enough money to buy this amount. Please choose a fewer amount."<<endl;
                    c=-1;
                }
                else{ 
                bullets=bullets+(20*c);//amount of bullets
                cash=cash-bulletsPrice; //pay
                bill=bill+bulletsPrice; //total bill
                }
                }
            }
        cout<<endl;
        cout<<"Your current bill is: "<<bill<<endl;
    }

    int Store::getBullets(){ //get amount of bullets
        return bullets;
    }
    void Store::setBullets(int ammo){ //change bulets by 'ammo'
        bullets=bullets+(ammo);
    }
    void Store::buySupplies(){
        //increase tax depending on fort
        double medCost=25*tax; //cost of medical kit
        double partCost=20*tax; // cost of wagon parts
        int m=-1;
        int p=-1;
        while(p<0){
            cout<<"A wagon part (wheels, axels, tongues) costs $20.0."<<endl;
            cout<<"How many parts do you wish to purchase?: ";
            cin>>p;
            if(p>=0){
                partsPrice=p*partCost; //total price of wago parts
                if(partsPrice>cash){ //if u dont have enough money
                    cout<<"You do not have enough money to buy this amount. Please choose a fewer amount."<<endl;
                    p=-1;
                }
                else{
                parts=parts+p; //total amount  of parts
                cash=cash-partsPrice; //pay
                bill=bill+partsPrice; //bill
                }
            }
        
        }
        while(m<0){
            cout<<"A medical aid kit costs $25.0."<<endl;
            cout<<"How many kits do you wish to purchase?: ";
            cin>>m;
            if(m>=0){
                medPrice=m*medCost; //total price of meds
                if(medPrice>cash){ // not enough money
                    cout<<"You do not have enough money to buy this amount. Please choose a fewer amount."<<endl;
                    m=-1;
                }
                else{
                med=med+m; // meds
                cash=cash-medPrice; //pay
                bill=bill+medPrice; //bill
                }
            }
            supplies=med+parts; //supplies is med +parts

            
        }
        cout<<endl;
        cout<<"Your current bill is: "<<bill<<endl;
        
    }

    int Store::getParts(){ //get parts
        return parts;
    }
    void Store::setParts(int extra){ //change pasrts by 'extra'
        parts=parts+(extra);
    }
    int Store::getMed(){ //get meds
        return med;
    }
    void Store::setMed(int kit){ //change med by 'kit'
        med=med+(kit);
    }

    double Store::getCash(){ //get cash
        return cash;
    }
    void Store::setCash(double p){ //change cash
        cash=cash+(p);
    }
    double Store::getBill(){ //get bill
       return bill;
    }
    void Store::setBill(int a){ //set bill
        bill=a;
    }

    int Store::receipt(){ //see amount
        cout<<"Oxen: "<<oxen<<endl;
        cout<<"food: "<<food<<endl;
        cout<<"bullets: "<<bullets<<endl;
        cout<<"supplies: "<<supplies<<endl;

        return bill;
    }
    
