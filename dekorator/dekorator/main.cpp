#include <iostream>

using namespace std;
class Beverage{
private:
  int quantity=1;
  int price;
public:
  Beverage(){}
  Beverage(int price){
      this->price=price;
  }
  virtual ~Beverage()=default;
  void setQuantity(int n){
      this->quantity=n;
  }
  int getQuantity() const{
      return this->quantity;
  }
  virtual void getDescription() = 0;
  virtual int cost() = 0;

  int getPrice() const{
    return this->price;
  }
  void setPrice(int price){
      this->price=price;
  }
};

class Late : public Beverage{
public:
    Late(int price):Beverage(price){}
    ~Late(){}
    void getDescription(){
     std::cout<<"Late\n";
    }
    int cost(){
        return this->getQuantity()*this->getPrice();
    }
};

class Espresso : public Beverage{
public:
    Espresso(int price){
        this->setPrice(price);
    }
    ~Espresso(){}
    void getDescription(){
     std::cout<<" Espresso\n";
    }
    int cost(){
        return this->getQuantity()*this->getPrice();
    }
};

class Decorator : public Beverage{
private:
    Beverage *beverage;
public:
    Decorator(int price):Beverage(price){}
    ~Decorator(){}
    void setBeverage(Beverage *beverage){
        this->beverage=beverage;
    }
    Beverage* getBeverage(){
        return this->beverage;
    }
};

class Soya : public Decorator{
public:
    Soya(int price):Decorator(price){}
    ~Soya(){}
    int cost(){
        return getBeverage()->cost()+this->getPrice();
    }
    void getDescription(){
        std::cout<<"Soya ";
        this->getBeverage()->getDescription();
    }
};
class Caramel : public Decorator{
public:
    Caramel(int price):Decorator(price){}
    int cost(){
        return getBeverage()->cost()+this->getPrice();
    }
    void getDescription(){
        std::cout<<"Caramel ";
        this->getBeverage()->getDescription();
    }
};
int main()
{
    Late *late=new Late(5);
    Soya *soya =new Soya(10);
    Caramel *caramel = new Caramel(100);
    soya->setBeverage(late);
    caramel->setBeverage(soya);
    std::cout<<"Opis zamowienia:\n";
    caramel->getDescription();
    std::cout<<"\n";
    std::cout<<"koszt zamowienia:\n";
    std::cout<<caramel->cost()<<"\n";
    delete caramel;
    delete late;
    delete soya;

    return 0;
}

