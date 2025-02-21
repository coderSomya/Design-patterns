#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

struct Character{
    int x;
    int y;
    std::string name;

    Character(std::string _name) : name(_name){}

    void move(int _x, int _y){
        x=_x;
        y=_y;
    }
};

class Command {
    public:
        virtual ~Command() {}
        virtual void execute(Character &c) = 0;
        virtual void undo(Character &c) = 0;
};

class Move: public Command {
    private:
       int x;
       int y;
    public:
       ~Move(){
          std::cout<<"moving out"<<std::endl;
       }
       void execute(Character &c){
         std::cout<<c.name + " moved"<<std::endl;
         int randomx = rand()%10;
         int randomy = rand()%10;
         c.move(randomx,randomy);
         x = randomx;
         y = randomy;
       }
       void undo(Character &c){
        std::cout<<c.name + " unmoved"<<std::endl;
        c.move(-x,-y);
       }
};


int main(){
    srand(time(NULL));
    Character somya("somya");

    std::vector<Command*> command_queue;
    Move* m1 = new Move;
    command_queue.push_back(m1);
    Move* m2 = new Move;
    command_queue.push_back(m2);
    Move* m3 = new Move;
    command_queue.push_back(m3);
    Move *m4 = new Move;
    command_queue.push_back(m4);

    for (int i=0; i<command_queue.size(); i++){
        command_queue[i]->execute(somya);
        std::cout<<somya.x<<" "<<somya.y<<std::endl;
    }

    return 0;
}