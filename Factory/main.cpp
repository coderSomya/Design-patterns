#include <iostream>
#include <memory>

class IGameObject {
    public:
        IGameObject(){
        }
        virtual ~IGameObject(){
            std::cout<<"deleting a game object"<<std::endl;
        }
        virtual void update() = 0;
        virtual void render() = 0;
};

enum class GameObjectsType{
    PLANE,
    BOAT
};

class Plane: public IGameObject{
    public:
        ~Plane(){
            std::cout<<"deleting a plane"<<std::endl;
        }
        void update(){
            
        }
        void render(){
            
        }
};
class Boat: public IGameObject{
    public:
        ~Boat(){
            std::cout<<"deleting a boat"<<std::endl;
        }
        void update(){
            
        }
        void render(){
            
        }
};

std::shared_ptr<IGameObject> makeGameObjectFactory(GameObjectsType type){
    if(type==GameObjectsType::PLANE){
        return std::make_shared<Plane>();
    }
    else if(type == GameObjectsType::BOAT){
        return std::make_shared<Boat>();
    }
    else return nullptr;
}

int main(){
    std::shared_ptr<IGameObject> boat1 = makeGameObjectFactory(GameObjectsType::BOAT);
    std::shared_ptr<IGameObject> plane1 = makeGameObjectFactory(GameObjectsType::PLANE);
    
    return 0;
}