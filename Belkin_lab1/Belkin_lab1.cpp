#include <iostream>
#include <string>
using namespace std;

struct Pipe
{
    string name;
    float length;
    int diametr;
    bool repair;
};

struct CS
{
    string name;
    int k_cex;
    int k_cex_in_work;
    string class_station;
};

void Menu(Pipe t)
{
    while (1) {
        cout << "Choose option:\n1. Add pipe\n2. Add CS\n3. View all objects\n";
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter name pipe: ";
            cin >> t.name;
            break;
        case 2:
            cout << "КС добавлена!\n";
            break;
        case 3:
            cout << "Название трубы: " << t.name << endl;
            break;
        };
    };
};

int main()
{
    cout << "Hello World!\n";
    Pipe truba;
    truba.name = "Uchastok-1";
    cout << truba.name << endl;
    CS ks;
    Menu(truba);
}

