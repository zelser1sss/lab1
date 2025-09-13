#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
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
            cout << "Error! Input 'Yes' or 'No'\n";
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
        cout << "CS empty\n\n";
    }
    else {

        cout << "\nAll CS:\n--------------------------------------\n";

        for (size_t i = 0; i < cs_list.size(); i++) {
            cout << "CS " << i + 1 << endl;
            cout << "name: " << cs_list[i].name << endl;
            cout << "workshop: " << cs_list[i].k_cex << endl;
            cout << "workshop in work: " << cs_list[i].k_cex_in_work << endl;
            cout << "type: " << cs_list[i].type << endl;
            cout << "--------------------------------------\n\n";
        };
    };
};

void EditPipe(vector<Pipe>& pipes)
{   
    if (pipes.empty()) {
        cout << "\nPipes empty\n\n";
        return;
    }

    int i;
    cout << "\nInput pipe number: ";
    while (!(cin >> i) || i <= 0 ||  i > pipes.size()) {
        cout << "Error! Input type: int. And > 0. And < size pipes\nInput positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    };

    string status;
    cout << "\nIs the pipe being repaired?(Yes/No): ";
    while (true) {
        cin >> status;
        if (status == "Yes") {
            pipes[i - 1].repair = true;
            cout << "Status change in true\n\n";
            break;
        }
        else if (status == "No") {
            pipes[i - 1].repair = false;
            cout << "Status change in false\n\n";
            break;
        }
        else {
            cout << "Error! Input 'Yes' or 'No'\n";
        };
    };
};

void EditCS(vector<CS>& cs_list)
{
    if (cs_list.empty()) {
        cout << "\nCS empty\n\n";
        return;
    };

    int i;
    cout << "\nInput CS number: ";
    while (!(cin >> i) || i <= 0 || i > cs_list.size()) {
        cout << "Error! Input type: int. And > 0. And < size cs_list\nInput positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    };

    while (1) {
        cout << "\n--------------------------------------\n";
        cout << "CS " << i << endl;
        cout << "works: " << cs_list[i - 1].k_cex_in_work << "/" << cs_list[i - 1].k_cex << endl;
        cout << "\nChoose option:\n1. Run workshop +1\n2. Stop workshop -1\n3. Exit\n";
        cout << "--------------------------------------\n\n";
        int option;

        while (!(cin >> option)) {
            cout << "Error type.\nInput positive number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        };

        switch (option)
        {
        case 1:
            if ((cs_list[i - 1].k_cex_in_work + 1) <= cs_list[i - 1].k_cex) {
                cs_list[i - 1].k_cex_in_work++;
            }
            else {
                cout << "\nThe number of workshop workers cannot be greater than the total number of workshops.\n";
            };
            break;
        case 2:
            if ((cs_list[i - 1].k_cex_in_work - 1) >= 0) {
                cs_list[i - 1].k_cex_in_work--;
            }
            else {
                cout << "\nThe number of workshop workers cannot be less than zero.\n";
            };
            break;
        case 3:
            cout << "\nExiting...\n\n";
            return;
        default:
            cout << "Invalid option! Try again.\n";
            break;
        };
    };
};

void Save(const vector<Pipe>& pipes, const vector<CS>& cs_list)
{
    if (!(pipes.empty())) {
        ofstream pipes_save;
        pipes_save.open("pipes.txt");
        if (pipes_save.is_open())
        {
            for (size_t i = 0; i < pipes.size(); i++) {
                pipes_save << pipes[i].name << "|" << pipes[i].length << "|" << pipes[i].diametr << "|" << pipes[i].repair << "|" << endl;
            };
            cout << "\nPipes are saved!\n";
        };
        pipes_save.close();
    }
    else {
        cout << "\nPipes empty\n";
    };

    if (!(cs_list.empty())) {
        ofstream cs_save;
        cs_save.open("cs_list.txt");
        if (cs_save.is_open())
        {
            for (size_t i = 0; i < cs_list.size(); i++) {
                cs_save << cs_list[i].name << "|" << cs_list[i].k_cex << "|" << cs_list[i].k_cex_in_work << "|" << cs_list[i].type << "|" << endl;
            };
        };
        cout << "CS are saved!\n\n";
        cs_save.close();
    }
    else {
        cout << "CS empty\n\n";
    };
};

void Upload(vector<Pipe>& pipes, vector<CS>& cs_list)
{
    pipes.clear();
    cs_list.clear();

    string line;
    ifstream pipes_upload("pipes.txt");
    if (pipes_upload.is_open()) {
        while (getline(pipes_upload, line)) {

            if (line.empty() || line.find_first_not_of(' ') == string::npos) {
                continue;
            };

            vector<size_t> pos = { 0 };
            for (size_t i = 0; i < 4; i++) {
                size_t found_pos = line.find('|', pos[i]);
                pos.push_back(found_pos + 1);
            };

            vector<string> sub;
            for (int i = 0; i < (pos.size() - 1); i++) {
                string found_sub = line.substr(pos[i], pos[i + 1] - pos[i] - 1);
                sub.push_back(found_sub);
            };

            Pipe newPipe;
            newPipe.name = sub[0];
            newPipe.length = stof(sub[1]);
            newPipe.diametr = stoi(sub[2]);
            if (stoi(sub[3]) == 1) {
                newPipe.repair = true;
            }
            else {
                newPipe.repair = false;
            };

            pipes.push_back(newPipe);
        };
        cout << "\nPipes are uploaded!\n";
        pipes_upload.close();
    }
    else {
        cout << "\nFile 'pipes.txt' not found\n";
        pipes_upload.close();
    };

    ifstream cs_upload("cs_list.txt");
    if (cs_upload.is_open()) {
        while (getline(cs_upload, line)) {

            if (line.empty() || line.find_first_not_of(' ') == string::npos) {
                continue;
            };

            vector<size_t> pos = { 0 };
            for (size_t i = 0; i < 4; i++) {
                size_t found_pos = line.find('|', pos[i]);
                pos.push_back(found_pos + 1);
            };

            vector<string> sub;
            for (int i = 0; i < (pos.size() - 1); i++) {
                string found_sub = line.substr(pos[i], pos[i + 1] - pos[i] - 1);
                sub.push_back(found_sub);
            };

            CS newCS;
            newCS.name = sub[0];
            newCS.k_cex = stoi(sub[1]);
            newCS.k_cex_in_work = stoi(sub[2]);
            newCS.type = sub[3];

            cs_list.push_back(newCS);
        };
        cout << "CS are uploaded!\n\n";
        cs_upload.close();
    }
    else {
        cout << "File 'cs_list.txt' not found\n\n";
        cs_upload.close();
    };
};

void Menu(vector<Pipe>& pipes, vector<CS>& cs_list)
{
    while (1) {
        cout << "--------------------------------------\n";
        cout << "Choose option:\n1. Add Pipe\n2. Add CS\n3. View all objects\n4. Edit pipe\n5. Edit CS\n6. Save\n7. Upload\n0. Exit\n";
        cout << "--------------------------------------\n\n";
        int option;

        while (!(cin >> option)) {
            cout << "Error type.\nInput positive number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        };
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
        case 4:
            EditPipe(pipes);
            break;
        case 5:
            EditCS(cs_list);
            break;
        case 6:
            Save(pipes, cs_list);
            break;
        case 7:
            Upload(pipes, cs_list);
            break;
        case 0:
            cout << "\nExiting...\n";
            return;
        default:
            cout << "Invalid option! Try again.\n";
            break;
        };
    };
};

int main()
{
    vector<Pipe> pipes;
    vector<CS> cs_list;
    Menu(pipes, cs_list);
}