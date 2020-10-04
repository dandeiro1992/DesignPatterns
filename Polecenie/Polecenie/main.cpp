#include <iostream>

using namespace std;
class Light{
public:
    bool light=false;
};
class ICommand {
public:
    Light* light;
    explicit ICommand(Light* light){
        this->light=light;
    }
    virtual void execute() =0;
    virtual void undo() = 0;
    void toString(){
        std::cout<<"light is on:\t"<<light->light<<"\n";
    }
};


class LightOnCommand : public ICommand{
public:
    using ICommand::ICommand;
    void execute(){
        this->light->light=true;
    }
    void undo(){
        this->light->light=false;
    }
};
class LightOffCommand : public ICommand{
public:
    using ICommand::ICommand;
    void execute(){
        this->light->light=false;
    }
    void undo(){
        this->light->light=true;
    }
};

class Invoker{
public:
    ICommand* command;
    Invoker(){

    }
    Invoker(ICommand* command){
        this->command=command;
    }
    void switchOn(){
        command->execute();
    }
    void undo(){
        command->undo();
    }
    void set(ICommand* command){
        this->command=command;
    }
};
int main()
{
    Light light;
    LightOnCommand* turnOn = new LightOnCommand(&light);
    LightOffCommand* turnOff = new LightOffCommand(&light);
    Invoker pilot = Invoker();
    pilot.set(turnOn);
    pilot.switchOn();
    turnOn->toString();
    cout << "Hello World!" << endl;
    return 0;
}
