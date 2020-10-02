#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Menu{
private:
    std::vector<Menu*> menusVector;
    Menu* currentMenu;
    Menu* mainMenu;
    std::function<string()> function;
public:
    Menu(std::function<string()> function){
        this->function=function;
    }
    Menu(Menu *mainMenu,std::function<string()>function){
        this->mainMenu=mainMenu;
        this->function=function;
    }
    ~Menu()=default;
    void exit(){
        setCurrentMenu(mainMenu);
        currentMenu->display();
    }
    void chooseOption(int option){
        setCurrentMenu(menusVector[option]);
    }
    void display(){
        std::cout<<function();
        for (auto menu : menusVector){
            menu->display();
        }
    }
    void addMenu(Menu* menu){
        menusVector.push_back(menu);
    }
    void removeMenu(Menu* menu){
        menusVector.erase(std::find(menusVector.begin(),menusVector.end(),menu));
    }
    vector<Menu*> getMenusVector(){
        return menusVector;
    }
    void setMainMenu(Menu* menu){
        mainMenu=menu;
    }
    void setFunction(string* function){
        function=function;
    }
    void setCurrentMenu(Menu* menu){
        this->currentMenu=menu;
    }
    Menu* getCurrentMenu(){
        return this->currentMenu;
    }
};

string mainMenuFunction(){
    return "Main menu\n";
}

string aboutFunction(){
    return "About menu\n";
}
string info(){
    return "info \n";
}
string controlsMenu(){
    return "Controls Menu \n";
}
string keyboardMenuFunction(){
    return "Keyboard Menu \n";
}
string mouseMenuFunction(){
    return "Mouse Menu \n";
}
int main()
{
    Menu* mainMenu = new Menu(mainMenuFunction);
    mainMenu->setMainMenu(mainMenu);
    Menu* aboutMenu = new Menu(mainMenu,aboutFunction);
    Menu* controls = new Menu(mainMenu,controlsMenu);
    Menu* keyboardMenu = new Menu(controls,keyboardMenuFunction);
    Menu* mouseMenu = new Menu(controls,mouseMenuFunction);

    mouseMenu->display();

    delete mouseMenu;
    delete keyboardMenu;
    delete controls;
    delete aboutMenu;
    delete mainMenu;
    cout << "Hello World!" << endl;
    return 0;
}
