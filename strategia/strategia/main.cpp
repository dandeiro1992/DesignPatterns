#include <iostream>

using namespace std;
class IFlyBehaviour{
public:
    virtual ~IFlyBehaviour(){}
    virtual void fly()=0;
};

class Fly : public IFlyBehaviour{
    void fly(){
        std::cout<<"I fly! \n";
    }
};

class NoFly : public IFlyBehaviour{
    void fly(){
        std::cout<<"I don't fly \n";
    }
};

class Duck{
public:
    Duck(string name="Damian");
    virtual ~Duck();
    void setIFlyBehaviour(IFlyBehaviour *fb);
    void setName(string name);
    void lataj(){
        this->fb->fly();
    }
private:
  string name;
  IFlyBehaviour *fb;

};



int main()
{
    Duck Kaczka = Duck();
    Kaczka.setIFlyBehaviour(new NoFly());
    Kaczka.lataj();
    Duck *Kaczka2=new Duck();
    IFlyBehaviour *fb=new Fly();
    Kaczka2->setIFlyBehaviour(fb);
    Kaczka2->lataj();
    Kaczka2->setIFlyBehaviour(new NoFly());
    Kaczka2->lataj();
    return 0;
}

Duck::Duck(string name)
{
    this->name=name;
}

Duck::~Duck()
{
    delete this->fb;
}

void Duck::setIFlyBehaviour(IFlyBehaviour *fb)
{
    this->fb=fb;
}

void Duck::setName(string name)
{
    this->name=name;
}
