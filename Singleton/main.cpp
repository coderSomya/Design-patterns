#include <iostream>
#include <vector>
#include <string>

class Logger{
    public:
        static Logger* getInstance(){
            if(s_instance == nullptr){
                s_instance = new Logger;
            }
            return s_instance;
        }
        void addMessage(std::string s){
            messages.push_back(s);
        }
        void printMessages(){
            for(std::string message: messages){
                std::cout<<message<<std::endl;
            }
        }
    private:
        Logger(){
            std::cout<<"created.."<<std::endl;
        }
        ~Logger(){
            std::cout<<"destroyed.."<<std::endl;
        }

        static Logger* s_instance;
        std::vector<std::string> messages;
};

Logger* Logger::s_instance = nullptr;
int main(){
    
    Logger::getInstance()->addMessage("msg 1");
    Logger::getInstance()->addMessage("msg 2");
    Logger::getInstance()->addMessage("msg 3");
    
    Logger::getInstance()->printMessages();
    
    return 0;
}
