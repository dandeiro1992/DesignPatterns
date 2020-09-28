#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
class Transport{
public:
    virtual ~Transport()=default;
    virtual void doStuff() = 0;
};
class Ship : public Transport{
public:
    void doStuff(){
     std::cout<<"J go by ship\n";
    }
};
class Truck : public Transport{
public:
    void doStuff(){
     std::cout<<"J go by truck\n";
    }
};
class Factory{
public:
    virtual ~Factory()=default;
    virtual Transport* createTransport() =0;
    void showState(){
        Transport* transport = createTransport();
        transport->doStuff();
        delete transport;
    }
};
class shipFactory :public Factory{
public:
    ~shipFactory()=default;
    Transport* createTransport(){
        return new Ship();
    }
};
class truckFactory :public Factory{
public:
    Transport* createTransport(){
        return new Truck();
    }
};

int main()
{
    shipFactory* shipfactory = new shipFactory();
    truckFactory* truckfactory = new truckFactory();
    Transport* transport = truckfactory->createTransport();
//    shipfactory->showState();
//    transport->doStuff();
//    delete transport;
//    delete truckfactory;
//    delete shipfactory;
    int counter=0;
    std::cout<<sizeof(Transport);
    while (counter<30000000){
        Transport* trans = truckfactory->createTransport();
        delete trans;
        counter++;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    return 0;
}
