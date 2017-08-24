#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class FighterHero{
    public :
    int health;
    public :
    FighterHero(){
        srand((unsigned)time(0));
        health = rand()%20+180;
    };
    public :
    int attack(){
        int attackpoints=rand()%10+10;
        return attackpoints;
    }
    public :
    void damage(int points){
        health=health-points;
    }
};
class FighterMonster{
    public :
    int health;
    public :
    FighterMonster(){
        health = rand()%20+180;
    };
    public :
    int attack(){
        int attackpoints=rand()%10+10;
        return attackpoints;
    }
    public :
    void damage(int points){
        health=health-points;
    }
};
string attackname(int n){
    switch(n){
        case 0:return "Flamethrow";
        case 1:return "Waterblast";
        case 2:return "Boneclaws";
        case 3:return "Electricshock";
        case 4:return "Magicalstorm";
    }
    return "Invalid attack";
}
int main(){
    FighterHero hero=FighterHero();
    FighterMonster monster = FighterMonster();
    char pa;
    int choose_attack,random_start;
    bool herowin = false,playagain=true;
    srand((unsigned)time(0));
    random_start = rand()%2+1;
    cout << "You are assigned the task of killing the evil monster\nby using your Superhero's powers!" << endl;
    cout << "Superhero has five unique powers, so does the Monster.\nLet's start!\n\n";
    cout << "To make this game interesting -->>\n";
    cout << "Your healthpoints and Monster's healthpoints are randomly chosen -->\n";
    
    while(playagain){
        cout << "Your starting healthpoint is " << hero.health << endl;;
        cout << "Monster's starting healthpoint is " << monster.health << endl;
        cout << endl;
        if (random_start == 1){
            cout<<"Monster is going to start this game by attacking your Super Hero first!\n\n";
            choose_attack = rand()%5;
            int attacks[5];
            for(int i=0;i<5;i++){
                attacks[i]=monster.attack();
                cout<<"Monster's "<<attackname(i)<<" was "<<attacks[i]<<endl;
            }
            
            cout << "Monster choose " << attackname(choose_attack) << endl;
            if(attacks[choose_attack]<13)
                cout<<"Superhero was able to defend the attack and did not lose any point\n";
            else{
                hero.damage(attacks[choose_attack]);
                cout << "Monster's attack did " << attacks[choose_attack] << " damage!" << endl;
            }
            if(hero.health<=0){
                herowin=false;
                break;
            }
            cout << "Your superhero now has " << hero.health << " healthpoints\n\n";
            cout << "It's your turn to attack now!\n\n";
        }
        else
            cout<<"You are going to start this game by attacking the monster first!\n\n";
        while(monster.health>0 && hero.health>0){
            do{
                cout << "Choose your attack-->\n";
                cout << "press 1 --> FLamethrow!\n";
                cout << "press 2 --> Waterblast!\npress 3 --> Boneclaws!\n";
                cout << "press 4 --> Electricshock!\npress 5 --> Magicalstorm!\n";
                cin >> choose_attack;
            }
            while(choose_attack>5||choose_attack<1);
            choose_attack-=1;
            int attacks[5];
            for(int i=0;i<5;i++){
                attacks[i]=hero.attack();
                cout<<attackname(i)<<" was "<<attacks[i]<<endl;
            }
            cout << "You choose " << attackname(choose_attack) << endl;
            if(attacks[choose_attack]<13)
                cout<<"Monster was able to defend the attack and did not lose any point\n";
            else{
                monster.damage(attacks[choose_attack]);
                cout << "Your attack did " << attacks[choose_attack] << " damage!" << endl;
            }
            
            if(monster.health<=0){
                herowin=true;
                break;
            }
            cout << "The monster now has " << monster.health << " healthpoints\n";
            cout << "The monster is going to attack your superhero now!\n\n";
            choose_attack = rand()%5;
            
            for(int i=0;i<5;i++){
                attacks[i]=monster.attack();
                cout<<"Monster's "<<attackname(i)<<" was "<<attacks[i]<<endl;
            }
            
            cout << "Monster choose " << attackname(choose_attack) << endl;
            if(attacks[choose_attack]<13){
                cout<<"Superhero was able to defend the attack and did not lose any point\n";
                cout << "It's your turn to attack the monster now!\n\n";}
            else
            {
                hero.damage(attacks[choose_attack]);
                cout << "Monster's attack did " << attacks[choose_attack] << " damage!" << endl;
            }
            if(hero.health<=0){
                herowin=false;
                break;
            }
            cout << "Your superhero now has " << hero.health << " healthpoints\n";
            cout << "It's your turn to attack the monster!\n\n";
            
        }
        if(herowin){
            cout << "Congratulations!!\nYour superhero has killed the monster!\n";
            cout << "Your superhero won with " << hero.health << " healthpoints left.\n";
        }
        else{
            cout << "Your super hero died!!\nYou lost!\n";
            cout << "The Monster still had " << monster.health << " healthpoints left.\n";
        }
        cout<<"Do you want to play Again?(y/n)";
        cin>>pa;
        if(pa=='n' || 'N')
            playagain=false;
        hero.health = rand()%20+180;
        monster.health = rand()%20+180;
    }
    return 0;
}
