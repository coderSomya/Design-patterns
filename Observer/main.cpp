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
        ISubject& subject;
    public:
        //make it the responsibility of the observer
        //to be attached to a subject
        explicit Watcher(ISubject& _subject, std::string _name): name(_name), subject(_subject){
            subject.addObserver(this);
        };
        
        ~Watcher(){
            subject.removeObserver(this);
        }
        
        void onNotify() override{
            std::cout<<name+" watching"<<std::endl;
        }
};

int main(){
    Streamer streamer("India's got Latent");
    
    Watcher w1(streamer, "somya");
    Watcher w2(streamer, "aditya");
    
    streamer.notify();
    return 0;
}



