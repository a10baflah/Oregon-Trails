#include <iostream>
#include "Current.h"
#include "Store.h"
#include "Time.h"
#include <cmath>
#include <fstream>


using namespace std;

void Current::setParty(){ //set party names
    cout<<"Enter your name: ";
    cin >> name;
    party.push_back(name);
    cout<<"Enter the name of the other four companions: "<<endl;
    cin >> name;
    party.push_back(name);
    cin >> name;
    party.push_back(name);
    cin >> name;
    party.push_back(name);
    cin >> name;
    party.push_back(name);
}
int Current::getParty(){ //return size of party
    players=party.size();
    return players;
}
Current::Current(){
    miles=0;
    index=0;
    vat=0;
    setParty();
    //set milestones
    path[0].setDistance(102);
    path[0].setLocation("Kansas River Crossing");
    path[1].setDistance(185);
    path[1].setLocation("Big Blue River Crossing");
    path[2].setDistance(304);
    path[2].setLocation("Fort Kearney");
    path[3].setDistance(554);
    path[3].setLocation("Chimney Rock");
    path[4].setDistance(640);
    path[4].setLocation("Fort Laramie");
    path[5].setDistance(830);
    path[5].setLocation("Independence Rock");
    path[6].setDistance(932);
    path[6].setLocation("South Pass");
    path[7].setDistance(989);
    path[7].setLocation("Fort Bridger");
    path[8].setDistance(1151);
    path[8].setLocation("Green River Crossing");
    path[9].setDistance(1295);
    path[9].setLocation("Soda Springs");
    path[10].setDistance(1395);
    path[10].setLocation("Fort Hall");
    path[11].setDistance(1534);
    path[11].setLocation("Snake River Crossing");
    path[12].setDistance(1648);
    path[12].setLocation("Fort Boise");
    path[13].setDistance(1808);
    path[13].setLocation("Blue Mountains");
    path[14].setDistance(1863);
    path[14].setLocation("Fort Walla Walla");
    path[15].setDistance(2040);
    path[15].setLocation("Oregon City");
    
    stop=1;
    next=path[0].getDistance();
    slash="/";
    //choose start date
    cout<<"Do you want to start at the (1) default date or (2) pick a date between 03/01/1847 and 05/01/1847? ";
    cin>>option;
    if(option==1){ //default date
        Time();
    }
    if (option==2){ // set preferred date
        cout<<"Enter month followed by day."<<endl;
        cin>>month;
        cin>>day;
        year=1847;
        clock.setDate(month,day,year);
    }
    shop();//store
}
int Current::box(){ //puzzle funtion
    srand(time(NULL));
    puzzle=(rand() % (10 - 1)) + 1; //pick a random number between 1 and 10
    tries=3; //give user 3 tries
    cout<<"---Welcome to the puzzle!---"<<endl;
    cout<<"In order to pass this puzzle, you must correctly guess a number between 1 to 10. You will be given atmost 3 tries. Good luck!"<<endl;
    while(tries>0){
        cout<<"try! your guess: ";
        cin>>guess;
        if(guess==puzzle){ //if u guess number right
            cout<<"You have passed the puzzle!"<<endl;
            return 1;
        }
        tries--;
    }
    //thid is what happens when u dont guess correctly
    cout<<"You have FAILED the puzzle!"<<endl;
    return 0;
}
void Current::shop(){ //call store
        fstream infile;
        string line="";
        infile.open("store_info.txt"); 
        while(getline(infile,line)){ //print store_info.txt
            cout<<line<<endl;
        }
        stores.setBill(0);
        int receipt=0;
        int option=0;
        while(option!=5){
            cout<<"Welcome to the store, what would you like to buy?"<<endl;
            cout<<"1.Oxen"<<endl;
            cout<<"2.Food"<<endl;
            cout<<"3.Bullets"<<endl;
            cout<<"4.Miscellaneous Supplies"<<endl;
            cout<<"5.Quit"<<endl;
            cin>>option;
            if(option==1){
                stores.buyOxen(); //call buy oxen function
                
            }    
            if(option==2){
                stores.buyFood(); //call buy food function
            }
            if(option==3){
                stores.buyBullets(); //call buy bullets function
            }
            if(option==4){
                stores.buySupplies(); //call buy supplies function
            }
            if(option==5){ //quit store
               
            }
            if(option>5 || option<1){ //invalid inputs
                cout<<"Invalid input."<<endl;
            }

        }
        
    }
void Current::allHunt(){ //hunt function
    srand(time(NULL));
    cout<<"You have chosen to hunt!"<<endl;
    if (stores.getBullets()>10){
        rabbitprob=(rand() % (100 - 1)) + 1; //chances of meeting rabbit
        if(rabbitprob>=1 && rabbitprob<=50){ //if u meet rabbit
            if(stores.getBullets()>10){ //if u have enought bullets to hunt it
                cout<<"You got lucky! You encountered a rabbit!"<<endl;
                cout<<"Do you want to hunt it?: 1. YES, 2. NO "; //if you want to hunt it
                cin>>option;
                if(option==1){
                    cout<<"You must solve this puzzle in order to hunt!"<<endl;
                    mystery=box(); //call puzzle
                    if(mystery==0){ //if u fail puzzle
                        cout<<"Failed the puzzle! Hunt opportunity missed. Movin on!"<<endl;
                    }
                    if(mystery==1){ // if u pass puzzle
                        chef=5;
                        gun=-10;
                        stores.setFood(chef);
                        stores.setBullets(gun);
                    }
                    

                }
            }
        }
        foxprob=(rand() % (100 - 1)) + 1;//chances of meeting fox
        if(foxprob>=1 && foxprob<=25){ //if u meet fox
            if(stores.getBullets()>8){//if u have enought bullets to hunt it
                cout<<"You got lucky! You encountered a fox!"<<endl;
                cout<<"Do you want to hunt it?: 1. YES, 2. NO ";//if you want to hunt it
                cin>>option;
                if(option==1){
                    cout<<"You must solve this puzzle in order to hunt!"<<endl;
                    mystery=box(); //call puzzle function
                    if(mystery==0){ //fail puzzle
                        cout<<"Failed the puzzle! Hunt opportunity missed. Movin on!"<<endl;
                    }
                    if(mystery==1){ //pass puzzle
                        chef=10;
                        gun=-8;
                        stores.setFood(chef);
                        stores.setBullets(gun);
                    }
                    
                }
            }
        }
        deerprob=(rand() % (100 - 1)) + 1;//chances of meeting deer
        if(deerprob>=1 && deerprob<=15){//if u meet deer
            if(stores.getBullets()>5){//if u have enought bullets to hunt it
                cout<<"You got lucky! You encountered a deer!"<<endl;
                cout<<"Do you want to hunt it?: 1. YES, 2. NO ";//if you want to hunt it
                cin>>option;
                if(option==1){
                    cout<<"You must solve this puzzle in order to hunt!"<<endl;
                    mystery=box(); //call puxxle
                    if(mystery==0){ //fail
                        cout<<"Failed the puzzle! Hunt opportunity missed. Movin on!"<<endl;
                    }
                    if(mystery==1){ //pass
                        chef=60;
                        gun=-5;
                        stores.setFood(chef);
                        stores.setBullets(gun);
                    }
                    
                }
            }
        }
        bearprob=(rand() % (100 - 1)) + 1;//chances of meeting bear
        if(bearprob>=1 && bearprob<=7){//if u meet bear
            if(stores.getBullets()>10){//if u have enought bullets to hunt it
            cout<<"You got lucky! You encountered a bear!"<<endl;
            cout<<"Do you want to hunt it?: 1. YES, 2. NO ";//if you want to hunt it
            cin>>option;
            if(option==1){
                cout<<"You must solve this puzzle in order to hunt!"<<endl;
                mystery=box(); //call puzzle
                if(mystery==0){ //fail puzzle
                    cout<<"Failed the puzzle! Hunt opportunity missed. Movin on!"<<endl;
                }
                if(mystery==1){ //pass puzzle
                    chef=200;
                    gun=-10;
                    stores.setFood(chef);
                    stores.setBullets(gun);
                }
                
            }
            }
        }
        mooseprob=(rand() % (100 - 1)) + 1;//chances of meeting moose
        if(mooseprob>=1 && mooseprob<=50){//if u meet moose
            if(stores.getBullets()>12){//if u have enought bullets to hunt it
            cout<<"You got lucky! You encountered a moose!"<<endl;
            cout<<"Do you want to hunt it?: 1. YES, 2. NO "; // choose
            cin>>option;
            if(option==1){
                cout<<"You must solve this puzzle in order to hunt!"<<endl;
                mystery=box(); //call puzzle
                if(mystery==0){ //fail
                    cout<<"Failed the puzzle! Hunt opportunity missed. Movin on!"<<endl;
                }
                if(mystery==1){ //pass
                    chef=500;
                    gun=-12;
                    stores.setFood(chef);
                    stores.setBullets(gun);
                }
                
            }
        }
    }
        cout<<"How well do you want to eat? "<<endl;
        cout<<"(1)Poorly, (2)Moderately, or (3)Well: "; //choose how much u want to eat
        cin>>option;
        if(option==1){ //poorly
            chef=-2*getParty();
            stores.setFood(chef);
        }
        if(option==2){ //moder
            chef=-3*getParty();
            stores.setFood(chef);
        }
        if(option==3){ //well
            chef=-5*getParty();
            stores.setFood(chef);
        }
        if(stores.getFood()>1000){ //if you have more than 1000 lbs of food after hunting,  make it 1000
            cout<<"You have too much food for the wagon to handle. The wagon can not hold more than 1000lbs of food."<<endl;
            chef=1000-stores.getFood();
            stores.setFood(chef);
            
        }
    
    }
    else{
        cout<<"You do not have enough bullets to hunt."<<endl;
    }
    clock.setTime(1); //update time
}

void Current::misfortune(){ //misfortune
    srand(time(NULL));
    int sick=0;
    chance=(rand()%(3))+1; //chances of kind of misfortune
    string disease[6]={"typhoid","cholera","diarrhea","measles","dysentery","fever"}; //diesease
    
    if(chance==1){
        person=(rand()%(party.size())); //random person in party is sick
        sick=(rand()%(5)); // with this disease
        cout<<"OH NO! "<<party[person]<<" has the "<<disease[sick]<<"!"<<endl;
        if(stores.getMed()>0){ //if party has a kit
            cout<<"Party has a medical kit."<<endl;
            death=(rand()%(100))+1;
            if(death>=1 && death<=50){ //death probability
                if(person==0){ //if the person dying is the leader
                    cout<<"You died of "<<disease[sick]<<endl;
                    Quit(); //quit the game
                }
                else{ //other member
                    cout<<"A member of your party died"<<endl;
                    party.erase(party.begin()+person); //delete him from party
                }
            }
        }
        else{ //if u dont have a kit
            cout<<"You do not have a medical kit. Choose to (1) Rest or (2) continue: ";
            cin>>option;
            if(option==1){ //rest
                death=(rand()%(100))+1;
                clock.setTime(3);
                if(death>=1 && death<=30){ //death probaility
                    if(person==0){//if the person dying is the leader
                        cout<<"You died of "<<disease[sick]<<endl;
                        Quit();
                        }
                    else{//other member
                        cout<<"A member of your party died"<<endl;
                        party.erase(party.begin()+person);
                        }
                }

            }
            if(option==2){ //continue
                death=(rand()%(100))+1;
                if(death>=1 && death<=70){ //death prob
                    if(person==0){//if the person dying is the leader
                        cout<<"You died of "<<disease[sick]<<endl;
                        Quit();
                    }
                    else{//other member
                        cout<<"A member of your party died"<<endl;
                    }
                }
            }
        }
    }
    if(chance==2){
        stores.setOxen(-1); //kill an oxen
        cout<<"Oh no! one of your oxens died! you have "<<stores.getOxen()<<" oxen left."<<endl;
        
        if(stores.getOxen()<=0){ //if you have none left
            Quit();
        }
    }
    if(chance==3){

        cout<<"Oh no! one of your wheels is broken!"<<endl;
        if(stores.getParts()>0){ //if u have a spare part
            cout<<"You have a spare part. Wagon is fixed."<<endl;
            stores.setParts(-1); //delete the used part
        } 
        else{ //u have no part
            Quit();
        }
    }
}
void Current::raider(){
    cout<<"Riders ahead! they look hostile!"<<endl;
    cout<<"Do you want to (1)Run, (2)Attack or (3)Surrender: ";
    cin>>option;
    if(option==1){ //run
        stores.setOxen(-1);
        stores.setFood(-10);
        stores.setParts(-1);
    }
    if(option==2){ //attack
        //call puzzle
        mystery=box();
        if(mystery==0){ //fail puzzle
            cout<<"You have lost the battle! You will lose a quarter of your chas."<<endl;
            money= stores.getCash()*(-0.25);
            stores.setCash(money);
        }
        if(mystery==1){ //win puzzle
            cout<<"You have won the battle! You will gain 50 bullets and 50lbs of food."<<endl;
            stores.setFood(50);
            stores.setBullets(50);
        }
    }
    if(option==3){ //surrender
        cout<<"You have surrendered! You lost a quarter of your cash."<<endl;
        money= stores.getCash()*(-0.25);
        stores.setCash(money);
    }
}
void Current::Quit(){ //used when u want to quit game
    stop=0; //variable that used in game function
    victory=0;
}
void Current::choice(){
    option=0;
    srand(time(NULL));
    status(); //print status
        //get random number, if random number is between 1 and 40 call misfortune function
        chance=(rand() % (100 - 1)) + 1; 
        if(chance>=1 && chance<=40){ //prob of misfortune
            misfortune();
        }
        
        attack=((pow((getMiles()/100.0)-4,2)+72)/(pow((getMiles()/100.0)-4,2)+12) - 1)/0.10; //prob of raid
        chance=(rand() % (100 - 1)) + 1;
        if(chance>=1 && chance<=attack){
            raider();
        }
        cout<<"DO YOU WANT TO (1) REST, (2) CONTINUE, (3) HUNT, OR (4) QUIT ? ";
        cin>>option;
        // if optiom==1, do rest function
        if(option==1){
            rest();
        }
        // if option==2 call continue function
        else if(option==2){
            travel();
        }
        // if option==3 call hunt function
        else if(option==3){
            allHunt();
        }
        // if option==4 call quit function
        else if(option==4){
            Quit();
        }
        
    if(miles>=2040){// if u exceed 2040 miles
        stop=0; //stop the game
        victory=1; //indicates you won
    }

}

int Current::travel(){
    srand(time(NULL));
    //generate a number between 70 AND 140 and make it your distance travelled
    int dist=0;
    int road=0;
    dist=(rand() % (140 - 70)) + 70; //generate distance to travel between 70 and 140
    road=dist;
    int count=0;
    while(dist>0){
        count++; //increase miles traveled for this rounf only
        miles++; //incrase milese for whole trip
        dist--;
        if(miles==path[index].getDistance()){ //if you reach a milestone
            if(index==2 ||index==4 ||index==7 ||index==10 || index==12 ||index==14){ //if the milestone is a fort
                cout<<path[index].getDistance()<<endl; //i used this to see how far is the milestone from start
                cout<<"You were prepared to travel "<<road<<" miles but you have arrived at the "<<path[index].getLocation()<<". What do you want to do? "<<endl;
                cout<<"(1) Rest or (2) Continue or (3) visit store "<<endl;
                index++;
                cin>> option;
                if(option==1){//rest
                    break;    //get out of loop so you dont incease miles travelled
                }
                if(option==3){//store
                    //increase tax then shop
                    vat++;
                    stores.setVat(vat);
                    shop();
                }
            }
            else{ //not forts
                cout<<path[index].getDistance()<<endl;//i used this to see how far is the milestone from start
                cout<<"You were prepared to travel "<<road<<" miles but you have arrived at the "<<path[index].getLocation()<<". What do you want to do? "<<endl;
                cout<<"(1) Rest or (2) Continue"<<endl;
                index++;
                cin>> option;
                if(option==1){
                    break;    //get out of loop so you dont incease miles travelled
                }
            }
        }  
    }
    //calc food eaten and update time
    chef=getParty()*14*-3;    
    stores.setFood(chef);
    clock.setTime(14);
    cout<<"Miles Traveled: "<<count<<endl;
    next=path[index].getDistance()-miles; //calc next milestone
    cout<<"Next Milestone: "<<next<<"mi"<<endl;
    return miles;
}
int Current::getMiles(){ //return miles travelled
    return miles;
}
void Current::rest(){
    srand(time(NULL));
    step=(rand() % (3 - 1)) + 1;//generate amount of days to rest
    //multiply 3*person*day
    // increase date by day
    chef=step*getParty()*-3;
    stores.setFood(chef);
    clock.setTime(step);
    
}

string Current::status(){
    //call time function
    //call distance travelled function
    //get next milestones
    //call getfood
    //call getOxen
    //call get bullets
    //call get cash
    cout<<"-------------------------------------------------------------------STATUS------------------------------------------------------------"<<endl;
    cout<<"Current date: ";
    clock.getTime();
    cout<<"Miles traveled: "<<getMiles()<<endl;
    cout<<"Next milestone in: "<<next<<endl;
    cout<<"Oxen: "<<stores.getOxen()<<endl;
    cout<<"Food left: "<<stores.getFood()<<endl;
    cout<<"Number of bullets available: "<<stores.getBullets()<<endl;
    cout<<"Cash: $"<<stores.getCash()<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    
    return slash;
}
void Current::final(){
    ofstream output("results.txt");
    output<<"-------------------------------------------------------------------STATUS------------------------------------------------------------"<<endl;
    output<<"Current date: "<<clock.getDate()<<endl;
    //output<<clock.getTime();
    output<<"Miles traveled: "<<getMiles()<<endl;
    output<<"Next milestone in: "<<next<<endl;
    output<<"Oxen: "<<stores.getOxen()<<endl;
    output<<"Food left: "<<stores.getFood()<<endl;
    output<<"Number of bullets available: "<<stores.getBullets()<<endl;
    output<<"Cash: $"<<stores.getCash()<<endl;
    output<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    
}
int Current::game(){ // the game function
    while(stop!=0){
        if(stores.getOxen()<=0){
            cout<<"You have no more Oxen."<<endl;
            Quit();
        }
        else if(stores.getFood()<=0){
            cout<<"You have run out of food."<<endl;
            Quit();
        }
        else if(clock.deadline()==0){
            cout<<"You have not made it by November 30 1847."<<endl;
            Quit();
        }
        else{
            choice();
        }
    }
    if(victory==0){ //if you lost the game
        cout<<"Game Over. You Lost."<<endl;
        final();
    }
    if(victory==1){ //if you won the game
        cout<<"Congratulations! You won"<<endl;
        final();
    }
    
   return 0;
}