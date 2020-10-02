#include <vector>
#include <stdio.h>

using namespace std;

class menuNode
{
    char *title;
    char *text;
    menuNode *parent;
    vector<menuNode*> subnodes;

    public:
        menuNode(char *title,
                char *text);

        void addSubmenu(menuNode *subnode);
        char *getTitle();
        char *getText();
        int size();
        menuNode* childAtNdx(int ndx);
};

menuNode::menuNode(char *title, char *text)
{
    this->title = title;
    this->text = text;
    this->parent = 0;
    subnodes = vector<menuNode*>();
}

void menuNode::addSubmenu(menuNode *subnode)
{
    subnode->parent = this;
    this->subnodes.push_back(subnode);
}

char *menuNode::getTitle()
{ return title; }

char *menuNode::getText()
{ return text; }

int menuNode::size()
{ return subnodes.size(); }

menuNode* menuNode::childAtNdx(int ndx)
{
    if (ndx == 0) return parent;
    else return subnodes[ndx - 1];
}

void showMenu(menuNode *node)
{
    printf(" .:%s:. \n", node->getTitle());
    printf("%s\n", node->getText());
    int max = node->size() + 1;
    for(int i = 0; i < max; i++)
    {
        char *text;
        if (node->childAtNdx(i) == 0)
        { text = "return"; }
        else
        { text =  node->childAtNdx(i)->getTitle(); }
        printf(" - %2d : %s\n", i, text);
    }
}

void menuSession(menuNode *menu)
{
    while (menu)
    {
        showMenu(menu);

        int choice;
        scanf("%d", &choice);

        if (choice > menu->size())
        { printf("invalid child\n"); continue; }

        menu = menu->childAtNdx(choice);
    }
}

int main()
{
    menuNode mainMenu = menuNode("main menu", "this is main menu");

    mainMenu.addSubmenu(new menuNode("sub1", "sub1 text"));
    mainMenu.addSubmenu(new menuNode("sub2", "sub2 text"));

    menuSession(&mainMenu);
}
