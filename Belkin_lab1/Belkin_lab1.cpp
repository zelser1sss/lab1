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
    cout << "\nInput name pipe: ";
    cin >> newPipe.name;

    cout << "Input length pipe: ";
    while (!(cin >> newPipe.length) || newPipe.length <= 0) {
        cout << "Error! Input type: float. And > 0\nInput positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    };

    cout << "Input diametr pipe: ";
    while (!(cin >> newPipe.diametr) || newPipe.diametr <= 0) {
        cout << "Error! Input type: int. And > 0\nInput positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    };
    
    string status;
    cout << "Is the pipe being repaired?(Yes/No): ";
    while (true) {
        cin >> status;
        if (status == "Yes") {
            newPipe.repair = true;
            break;
        }
        else if (status == "No") {
            newPipe.repair = false;
            break;
        }
        else {
            cout << "Error! Input 'Yes' or 'No'";
        };
    };

    pipes.push_back(newPipe);
    cout << "New pipe add\n\n";
};

void AddCS(vector<CS>& cs_list)
{
    CS newCS;
    cout << "\nInput name CS: ";
    cin >> newCS.name;

    cout << "Input number of workshop: ";
    while (!(cin >> newCS.k_cex) || newCS.k_cex <= 0) {
        cout << "Error! Input type: int. And > 0\nInput positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    };

    cout << "Input number of workshop in work: ";
    while (!(cin >> newCS.k_cex_in_work) || newCS.k_cex_in_work < 0 || newCS.k_cex_in_work > newCS.k_cex) {
        cout << "Error! Input type: int. And > 0. And < workshop\nInput positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    };

    cout << "Input type CS: ";
    cin >> newCS.type;

    cs_list.push_back(newCS);
    cout << "New CS add\n\n";
};

void ViewAllObjects(const vector<Pipe>& pipes, const vector<CS>& cs_list)
{
    if (pipes.empty()) {
        cout << "\nPipes empty\n";
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
            else if (pipes[i].repair == true){
                cout << "repair: Yes\n";
            };
            cout << "--------------------------------------\n";
        };
    };

    if (cs_list.empty()) {
        cout << "CS empty\n";
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
        cout << "Choose option:\n1. Add Pipe\n2. Add CS\n3. View all objects\n4. Edit pipe\n5. Edit CS\n6. Save\n7. Upload\n0. Exit\n";
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