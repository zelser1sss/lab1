#include <iostream>
#include <string>
#include <vector>
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
    string type;
};

void AddPipe(vector<Pipe>& pipes)
{
    Pipe newPipe;
    cout << "Input name pipe: ";
    cin >> newPipe.name;
    cout << "Input length pipe: ";
    cin >> newPipe.length;
    cout << "Input diametr pipe: ";
    cin >> newPipe.diametr;
    newPipe.repair = false;
    pipes.push_back(newPipe);
    cout << "New pipe add\n";
};

void AddCS(vector<CS>& cs_list)
{
    CS newCS;
    cout << "Input name CS: ";
    cin >> newCS.name;
    cout << "Input number of workshop: ";
    cin >> newCS.k_cex;
    cout << "Input number of workshop in work: ";
    cin >> newCS.k_cex_in_work;
    cout << "Input type CS: ";
    cin >> newCS.type;
    cs_list.push_back(newCS);
    cout << "New CS add\n";
};

void ViewAllObjects(const vector<Pipe>& pipes, const vector<CS>& cs_list)
{
    if (pipes.empty()) {
        cout << "Pipes empty";
    }
    else {

        cout << "\nAll Pipes:\n--------------------------------------\n";

        for (size_t i = 0; i < pipes.size(); i++) {
            cout << "Pipe " << i + 1 << endl;
            cout << "name: " << pipes[i].name << endl;
            cout << "length: " << pipes[i].length << endl;
            cout << "diametr: " << pipes[i].diametr << endl;
            if (pipes[i].repair == false) {
                cout << "repair: No\n";
            }
            else {
                cout << "repair: Yes\n";
            };
            cout << "--------------------------------------\n";
        };
    };

    if (cs_list.empty()) {
        cout << "CS empty";
    }
    else {

        cout << "\nAll CS:\n--------------------------------------\n";

        for (size_t i = 0; i < cs_list.size(); i++) {
            cout << "CS " << i + 1 << endl;
            cout << "name: " << cs_list[i].name << endl;
            cout << "workshop: " << cs_list[i].k_cex << endl;
            cout << "workshop in work: " << cs_list[i].k_cex_in_work << endl;
            cout << "type: " << cs_list[i].type << endl;
            cout << "--------------------------------------\n";
        };
    };
};

void Menu(vector<Pipe>& pipes, vector<CS>& cs_list)
{
    while (1) {
        cout << "Choose option:\n1. Add pipe\n2. Add CS\n3. View all objects\n4. Edit pipe\n5. Edit Cs\n6. Save\n7. Upload\n0. Exit\n";
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            AddPipe(pipes);
            break;
        case 2:
            AddCS(cs_list);
            break;
        case 3:
            ViewAllObjects(pipes, cs_list);
            break;
        case 0:
            cout << "Exiting...\n";
            return;
        };
    };
};

int main()
{
    vector<Pipe> pipes;
    vector<CS> cs_list;
    Menu(pipes, cs_list);
}