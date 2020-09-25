#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <memory>
using namespace std;

class IObserver{
public:
    virtual void update() = 0;
};

class IDisplay{
public:
    virtual void display() = 0;
};

class IObservable{
public:
    virtual void add(std::unique_ptr<IObserver> observer) = 0;
    virtual void remove(std::unique_ptr<IObserver> observer) = 0;
    virtual void notify() = 0;
};

class WeatherStation : public IObservable{
public:
    WeatherStation(){}
    ~WeatherStation(){}
    void add(std::unique_ptr<IObserver> observer){
        observers.push_back(std::move(observer));
    }
    void remove(std::unique_ptr<IObserver> observer){
        observers.erase(find(observers.begin(),observers.end(),observer));
    }
    void notify(){
        for (auto &observer : observers){
            observer->update();
        }
    }
    void setTemperature(){
        temperature+=5;
    }
    int getTemperature(){
        return temperature;
    }
private:
    vector<std::unique_ptr<IObserver>> observers;
    int temperature = 0;
};


class PhoneDisplay : public IObserver,IDisplay{
private:
    int variable = 5;
    WeatherStation *observable;
public:
    PhoneDisplay(WeatherStation *observable){
       this->observable=observable;
    }
    void update(){
        variable+=100;
        display();
    }
    void display(){
        cout<<"Wyswietlam na ekranie telefonu variable = "<<variable<<" temperature = "<<observable->getTemperature()<<"\n";
    }
};
class LCDDisplay : public IObserver,IDisplay{
private:
    int variable = 6;
    WeatherStation *observable;
public:
    LCDDisplay(WeatherStation *observable){
       this->observable=observable;
    }
    void update(){
        variable+=200;
        display();
    }
    void display(){
        cout<<"Wyswietlam na ekranie LCD variable = "<<variable<<" temperature = "<<observable->getTemperature()<<"\n";
    }
};
int main()
{
    WeatherStation *station = new WeatherStation();
    PhoneDisplay *xiaomi = new PhoneDisplay(station);
    LCDDisplay sharp = LCDDisplay(station);
    station->add(std::make_unique<PhoneDisplay>(PhoneDisplay(station)));
    station->add(std::make_unique<decltype(sharp)>(sharp));
    for (int i=0;i<10;i++)
    {
        station->setTemperature();
        station->notify();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return 0;
}
