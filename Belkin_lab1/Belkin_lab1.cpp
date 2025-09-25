#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include <clocale>
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

int ProverkaInt()
{
    int value;
    while (!(cin >> value) || value <= 0) {
        cout << "Ошибка! Введите ПОЛОЖИТЕЛЬНОЕ ЦЕЛОЕ ЧИСЛО: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    };
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
};

float ProverkaFloat()
{
    float value;
    while (!(cin >> value) || value <= 0) {
        cout << "Ошибка! Введите ПОЛОЖИТЕЛЬНОЕ ЧИСЛО: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    };
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
};

void AddPipe(vector<Pipe>& pipes)
{
    Pipe newPipe;
    cout << "\nВведите название трубы: ";
    getline(cin, newPipe.name);

    cout << "Введите длину трубы (км): ";
    newPipe.length = ProverkaFloat();

    cout << "Введите диаметр трубы (мм): ";
    newPipe.diametr = ProverkaInt();
    
    string status;
    cout << "Труба на ремонте?(Yes/No): ";
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
            cout << "Ошибка! Введите 'Yes' или 'No': ";
        };
    };

    pipes.push_back(newPipe);
    cout << "\nНовая труба добавлена\n\n";
};

void AddCS(vector<CS>& cs_list)
{
    CS newCS;
    cout << "\nВведите название КС: ";
    getline(cin, newCS.name);

    cout << "Введите общее количество цехов: ";
    newCS.k_cex = ProverkaInt();

    cout << "Введите количество цехов в работе: ";
    newCS.k_cex_in_work = ProverkaInt();
    if (newCS.k_cex_in_work > newCS.k_cex) {
        cout << "Ошибка! Количество цехов в работе не может быть больше общего количества цехов\nВведите корректное число: ";
        newCS.k_cex_in_work = ProverkaInt();
    };

    cout << "Введите тип КС: ";
    getline(cin, newCS.type);

    cs_list.push_back(newCS);
    cout << "\nНовая КС добавлена\n\n";
};

void ViewAllObjects(const vector<Pipe>& pipes, const vector<CS>& cs_list)
{
    if (pipes.empty()) {
        cout << "\nТРУБ НЕТ\n";
    }
    else {

        cout << "\nВСЕ ТРУБЫ:\n--------------------------------------\n";

        for (size_t i = 0; i < pipes.size(); i++) {
            cout << "Труба " << i + 1 << endl;
            cout << "Название: " << pipes[i].name << endl;
            cout << "Длина (км): " << pipes[i].length << endl;
            cout << "Диаметр (мм): " << pipes[i].diametr << endl;
            if (pipes[i].repair == false) {
                cout << "В ремонте: Нет\n";
            }
            else if (pipes[i].repair == true){
                cout << "В ремонте: Да\n";
            };
            cout << "--------------------------------------\n";
        };
    };

    if (cs_list.empty()) {
        cout << "КС НЕТ\n\n";
    }
    else {

        cout << "\nВСЕ КС:\n--------------------------------------\n";

        for (size_t i = 0; i < cs_list.size(); i++) {
            cout << "КС " << i + 1 << endl;
            cout << "Название: " << cs_list[i].name << endl;
            cout << "Общее количество цехов: " << cs_list[i].k_cex << endl;
            cout << "Количество цехов в работе: " << cs_list[i].k_cex_in_work << endl;
            cout << "Тип: " << cs_list[i].type << endl;
            cout << "--------------------------------------\n";
        };
        cout << endl;
    };
};

void EditPipe(vector<Pipe>& pipes)
{   
    if (pipes.empty()) {
        cout << "\nТРУБ НЕТ\n\n";
        return;
    }

    int i;
    cout << "\nВведите номер трубы: ";
    i = ProverkaInt();
    while (i > pipes.size()) {
        cout << "Ошибка! Введите число не превышающее общего количества труб: ";
        i = ProverkaInt();
    };

    string status;
    cout << "\nТруба в ремонте?(Yes/No): ";
    while (true) {
        cin >> status;
        if (status == "Yes") {
            pipes[i - 1].repair = true;
            cout << "Статус 'в ремонте' сменен на 'Да'\n\n";
            break;
        }
        else if (status == "No") {
            pipes[i - 1].repair = false;
            cout << "Статус 'в ремонте' сменен на 'Нет'\n\n";
            break;
        }
        else {
            cout << "Ошибка! Введите 'Yes' или 'No': ";
        };
    };
};

void EditCS(vector<CS>& cs_list)
{
    if (cs_list.empty()) {
        cout << "\nКС НЕТ\n\n";
        return;
    };

    int i;
    cout << "\nВведите номер КС: ";
    i = ProverkaInt();
    while (i > cs_list.size()) {
        cout << "Ошибка! Введите число не превышающее общего количества КС: ";
        i = ProverkaInt();
    };

    while (1) {
        cout << "\n--------------------------------------\n";
        cout << "КС " << i << endl;
        cout << "В работе: " << cs_list[i - 1].k_cex_in_work << "/" << cs_list[i - 1].k_cex << endl;
        cout << "\nВыберите опцию:\n1. Запустить цех (+1)\n2. Остановить цех (-1)\n3. Выход\n";
        cout << "--------------------------------------\n\n";
        int option;
        option = ProverkaInt();

        switch (option)
        {
        case 1:
            if ((cs_list[i - 1].k_cex_in_work + 1) <= cs_list[i - 1].k_cex) {
                cs_list[i - 1].k_cex_in_work++;
            }
            else {
                cout << "\nВсе цеха уже в работе!\n";
            };
            break;
        case 2:
            if ((cs_list[i - 1].k_cex_in_work - 1) >= 0) {
                cs_list[i - 1].k_cex_in_work--;
            }
            else {
                cout << "\nВсе цеха уже остановлены!\n";
            };
            break;
        case 3:
            cout << "\nВыходим...\n\n";
            return;
        default:
            cout << "Неизвестная опция. Попробуйте еще раз!\n";
            break;
        };
    };
};

void Save(const vector<Pipe>& pipes, const vector<CS>& cs_list)
{
    ofstream save;
    save.open("save.txt");
    if (save.is_open()) {
        if (!(pipes.empty())) {
            save << "ТРУБЫ\n";
            for (size_t i = 0; i < pipes.size(); i++) {
                save << pipes[i].name << "|" << pipes[i].length << "|" << pipes[i].diametr << "|" << pipes[i].repair << "|" << endl;
            };
            cout << "\nСписок труб сохранен!\n";
        }
        else {
            save << "ТРУБ НЕТ\n";
            cout << "\nТРУБ НЕТ\n";
        };

        if (!(cs_list.empty())) {
            save << "КС\n";
            for (size_t i = 0; i < cs_list.size(); i++) {
                save << cs_list[i].name << "|" << cs_list[i].k_cex << "|" << cs_list[i].k_cex_in_work << "|" << cs_list[i].type << "|" << endl;
            };
            cout << "Список КС сохранен!\n\n";
        }
        else {
            save << "КС НЕТ";
            cout << "КС НЕТ\n\n";
        };
    };
};

void Upload(vector<Pipe>& pipes, vector<CS>& cs_list)
{
    pipes.clear();
    cs_list.clear();

    string line;
    string state = "None";
    ifstream upload("save.txt");

    if (!(upload.is_open())) {
        cout << "\nФайл 'save.txt' не найден\n";
        upload.close();
        return;
    };

    while (getline(upload, line)) {

        if (line.empty() || line.find_first_not_of(' ') == string::npos) {
            continue;
        };

        if ("ТРУБ НЕТ" == line) {
            cout << "\nТРУБ НЕТ\n";
            continue;
        } 
        else if ("ТРУБЫ" == line) {
            state = "Trubs";
            continue;
        };

        if ("КС НЕТ" == line) {
            cout << "КС НЕТ\n\n";
            continue;
        }
        else if ("КС" == line) {
            state = "CS";
            continue;
        };

        vector<size_t> pos = { 0 };
        for (size_t i = 0; i < 4; i++) {
            size_t found_pos = line.find('|', pos[i]);
            pos.push_back(found_pos + 1);
        };

        vector<string> sub;
        for (size_t i = 0; i < (pos.size() - 1); i++) {
            string found_sub = line.substr(pos[i], pos[i + 1] - pos[i] - 1);
            sub.push_back(found_sub);
        };

        if (state == "Trubs") {
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

        if (state == "CS") {
            CS newCS;
            newCS.name = sub[0];
            newCS.k_cex = stoi(sub[1]);
            newCS.k_cex_in_work = stoi(sub[2]);
            newCS.type = sub[3];

            cs_list.push_back(newCS);
        };
    };
    upload.close();
};

void Menu(vector<Pipe>& pipes, vector<CS>& cs_list)
{
    while (1) {
        cout << "--------------------------------------\n";
        cout << "Выберите опцию:\n1. Добавить трубу\n2. Добавить КС\n3. Просмотр всех объектов\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n8. Выход\n";
        cout << "--------------------------------------\n\n";
        int option;
        option = ProverkaInt();

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
        case 8:
            cout << "\nВыходим...\n";
            return;
        default:
            cout << "Неизвестная опция. Попробуйте еще раз\n\n";
            break;
        };
    };
};

int main()
{
    setlocale(LC_ALL, "");
    vector<Pipe> pipes;
    vector<CS> cs_list;
    Menu(pipes, cs_list);
}