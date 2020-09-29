#include <iostream>

using namespace std;

class Chair{
public:
  virtual ~Chair()=default;
  virtual void description() =0;
};

class victorianChair : public Chair{
    void description(){
        std::cout<<"I am sitting on a victorian chair\n";
    }
};
class modernChair : public Chair{
    void description(){
        std::cout<<"I am sitting on a modern chair\n";
    }
};
class artDecoChair : public Chair{
    void description(){
        std::cout<<"I am sitting on a artDeco chair\n";
    }
};

class Sofa{
public:
  virtual ~Sofa()=default;
  virtual void description() =0;
};

class victorianSofa : public Sofa{
    void description(){
        std::cout<<"I am lying on a victorian Sofa\n";
    }
};
class modernSofa : public Sofa{
    void description(){
        std::cout<<"I am lying on a modern Sofa\n";
    }
};
class artDecoSofa : public Sofa{
    void description(){
        std::cout<<"I am lying on a artDeco Sofa\n";
    }
};

class AbstractFactory{
public:
    virtual ~AbstractFactory()=default;
    virtual Chair* productChair() = 0;
    virtual Sofa* productSofa() = 0;
};

class victorianFactory:public AbstractFactory{
    Chair* productChair(){
        return new victorianChair();
    }
    Sofa* productSofa(){
        return new victorianSofa();
    }
};
class modernFactory:public AbstractFactory{
    Chair* productChair(){
        return new modernChair();
    }
    Sofa* productSofa(){
        return new modernSofa();
    }
};
class artDecoFactory:public AbstractFactory{
    Chair* productChair(){
        return new artDecoChair();
    }
    Sofa* productSofa(){
        return new artDecoSofa();
    }
};
int main()
{
    AbstractFactory* factory=new artDecoFactory();
    Chair* chair=factory->productChair();
    chair->description();
    Sofa* sofa=factory->productSofa();
    delete factory;
    delete chair;
    delete sofa;
    return 0;
}
