#include <iostream>

using namespace std;
class Furniture{
public:
    virtual ~Furniture()=default;
    virtual void description() =0;
    virtual void sit() = 0;
};

class Chair:public Furniture{
public:
  virtual ~Chair()=default;
  void sit(){
        std::cout<<"Checking sitting on chair option\n";
    }
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

class Sofa:public Furniture{
public:
    virtual ~Sofa()=default;
    void sit(){
          std::cout<<"Checking sitting on sofa option\n";
      }
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
    virtual Furniture* productChair() = 0;
    virtual Furniture* productSofa() = 0;
};

class victorianFactory:public AbstractFactory{
    Furniture* productChair(){
        return new victorianChair();
    }
    Furniture* productSofa(){
        return new victorianSofa();
    }
};
class modernFactory:public AbstractFactory{
    Furniture* productChair(){
        return new modernChair();
    }
    Furniture* productSofa(){
        return new modernSofa();
    }
};
class artDecoFactory:public AbstractFactory{
    Furniture* productChair(){
        return new artDecoChair();
    }
    Furniture* productSofa(){
        return new artDecoSofa();
    }
};
int main()
{
    AbstractFactory* factory=new victorianFactory();
    Furniture* chair=factory->productChair();
    chair->description();
    chair->sit();
    Furniture* sofa=factory->productSofa();
    delete factory;
    delete chair;
    delete sofa;
    return 0;
}
