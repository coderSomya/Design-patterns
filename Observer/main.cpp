#include <forward_list>
#include <iostream>
#include <string>

class IObserver{
    public:
        IObserver(){};
        
        ~IObserver(){};
        
        virtual void onNotify() = 0;
};

class ISubject{
    private:
        std::forward_list<IObserver*> observers;
    public:
        ISubject(){};
        
        ~ISubject(){};
        
        virtual void addObserver(IObserver* observer){
            observers.push_front(observer);
        }
        virtual void removeObserver(IObserver* observer){
            observers.remove(observer);
        }
        virtual void notify(){
            for(auto& o: observers){
                o->onNotify();
            }
        }
};

class Streamer: public ISubject{
    private:
       std::string show;
    public: 
        Streamer(std::string _show): show(_show){};
        
        ~Streamer(){};
};

class Watcher : public IObserver{
    private:
        std::string name;
    public:
        explicit Watcher(std::string _name): name(_name){};
        
        ~Watcher() {};
        
        void onNotify() override{
            std::cout<<name+" watching"<<std::endl;
        }
};

int main(){
    Streamer streamer("India's got Latent");
    
    Watcher w1("somya");
    Watcher w2("aditya");
    
    streamer.addObserver(&w1);
    streamer.addObserver(&w2);
    
    streamer.notify();
    return 0;
}



