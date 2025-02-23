#include <forward_list>
#include <iostream>

class Observer{
    private:
        std::string name;
    public:
        Observer(std::string _name) : name(_name){}
        void onNotify(){
            std::cout<<name+" notified by the subject"<<std::endl;
        }
};

class Subject{
    private:
        std::forward_list<Observer*> observers;
    public:
        void addObserver(Observer* observer){
            observers.push_front(observer);
        }
        void removeObserver(Observer* observer){
            observers.remove(observer);
        }
        void notify(){
            for(auto& o: observers){
                o->onNotify();
            }
        }
};

int main(){
    Subject sub;
    
    Observer o1("somya");
    Observer o2("wang");
    Observer o3("lasaro");
    
    sub.addObserver(&o1);
    sub.addObserver(&o2);
    sub.addObserver(&o3);
    
    sub.removeObserver(&o1);
    
    sub.notify();
    return 0;
}



