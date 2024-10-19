#include<iostream>
#include<ctime>
using namespace std;


class Enemy{
    public:

int EnemyHealth = 100;

int maxDmg = 30;
int minDmg = 5;
Enemy(){
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"You may have won against this lil squids. "<<endl;
    cout<<"But you NO chance againts me Hero...\n"<<"HAHHAhAHA"<<endl;
    cout<<"HERE COMES YOUR BIGGEST ENEMY"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
}
void PlayerStats(){
    cout<<"Villain's Max health is: "<<EnemyHealth<<"."<<endl;
    cout<<"Villain's Max damange is  "<<maxDmg<<"."<<endl;
    }

int GetHealth(){
return EnemyHealth;
}

int GiveDamage(){
srand(time(0));
int randomDmg = (rand()% (maxDmg - minDmg + 1)+ minDmg);
cout<<"Damage given by the Villain: "<<randomDmg<<" to our Hero"<<endl;
return randomDmg;
}

int TakeDamage(int Dmg){
    EnemyHealth = EnemyHealth - Dmg;
    if(EnemyHealth > 0){
    cout<<"Villain's Health is "<<EnemyHealth<<"."<<endl;
    }
else {  
    cout<<"***************************************"<<endl;
    cout<<"*                                     *"<<endl;
    cout<<"*       Villain Defeated              *"<<endl;
    cout<<"*           You Won!                  *"<<endl;
    cout<<"*                                     *"<<endl;
    cout<<"***************************************"<<endl;
    
}
return 0;
}

};


class Player{
    private:
    int PlayerWife;

public:

int PlayerHealth = 100;

int maxDmg = 35;
int minDmg = 10;

int maxHeal = 20;
int minHeal =5;

Player(){
    cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Long ago there was a hero, when crime was just a normal thing to be happen."<<endl;
    cout<<"Our hero used to fight the criminals and put them in their right place i.e JAIL."<<endl;
    cout<<"Time passed by crime rate came all the way to 0."<<endl;
    cout<<"Our hero had no choose but to pick a normal job even though he had super cool ass powers"<<endl;
    cout<<"But little does he know the evil had returned with a being a bigger threath to the world has ever known."<<endl;
    cout<<"Soon after he got but to his job of saving the world and defeated countless enemies as expected but.."<<endl;
    cout<<"The real threath was waiting for the right moment in the shadows....."<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
}
void PlayerStats(){
    cout<<"Hero's Max health is: "<<PlayerHealth<<"."<<endl;
    cout<<"Hero's Max damange is  "<<maxDmg<<"."<<endl;
    cout<<"Hero's Max Healing power is "<<maxHeal<<"."<<endl;
}
int GetHealth(){
   return PlayerHealth;
}

int GiveDamage(){
srand(time(0));
int randomDmg = (rand()% (maxDmg - minDmg + 1)+ minDmg);
cout<<"Damage given by the Hero: "<<randomDmg<<" To the Villain"<<endl;
return randomDmg;
}

int TakeDamage(int Dmg){
    PlayerHealth = PlayerHealth - Dmg;
    if(PlayerHealth >0 ){
        cout<<"Hero's health is: "<<PlayerHealth<<"."<<endl;
    }
else{
    cout<<"***************************************"<<endl;
    cout<<"*                                     *"<<endl;
    cout<<"*                HERO DIED            *"<<endl;
    cout<<"*                GAME OVER            *"<<endl;
    cout<<"*                                     *"<<endl;
    cout<<"***************************************"<<endl;
}
return 0;
}

void Heal(){

srand(time(0));
int randomHeal = (rand()% (maxHeal - minHeal + 1)+ minHeal);
PlayerHealth = PlayerHealth + randomHeal; 
cout<<"Hero's healed with HP of: "<<randomHeal<<endl;
cout<<"Hero's health after healing: "<<PlayerHealth<<endl;
}

};
void Battleloop(Player Hero , Enemy villain){
     
    char Playerchoice;
    do {
        cout<<"Press A to attack or H to heal"<<endl;
        cin>>Playerchoice;
        if(Playerchoice == 'a' || Playerchoice == 'A'){
             villain.TakeDamage(Hero.GiveDamage());
           
            if(villain.GetHealth()>0){
                Hero.TakeDamage(villain.GiveDamage());

        }
        }
         else if (Playerchoice == 'h' || Playerchoice == 'H'){
            Hero.Heal();
            
            if(villain.GetHealth()>0){
                Hero.TakeDamage(villain.GiveDamage());
            }
            }
    
    else{
cout<<"Wrong Input!!"<<endl;
    }
}while(Hero.GetHealth()>0 && villain.GetHealth() > 0 );
}


int main (){
    char Playerinput;
    Player p1;
    cout<<"Press S to start the game or anyother key to exit."<<endl;
    cin>>Playerinput;
    if(Playerinput == 's' || Playerinput=='S'){
        p1.PlayerStats();
        Enemy e1;
        e1.PlayerStats();
        cout<<"----------------------------------------------------------"<<endl;
        Battleloop(p1,e1);
    }else{
        cout<<"Thanks for playing"<<endl;
    }
    
    return 0;
}