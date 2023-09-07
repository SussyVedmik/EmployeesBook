#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct employee {
    char firstName[50];
    char lastName[50];
    char phoneNumber[20];
    double salary;
};

const int MAX_EMPLOYEES = 1000;

void fromFile(employee employees[], int& count) {

    setlocale(LC_ALL, "Russian");

    ifstream file("employees.txt");
    if (!file) {
        cout << "ошибка, файла нет" << endl;
        return;
    }

    count = 0;
    while (file >> employees[count].firstName >> employees[count].lastName >> employees[count].phoneNumber >> employees[count].salary) {
        count++;
    }

    file.close();
}

void toFile(employee employees[], int count) {

    setlocale(LC_ALL, "Russian");

    ofstream file("employees.txt");
    if (!file) {
        cout << "нет файла\n" << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        file << employees[i].firstName << " " << employees[i].lastName << " " << employees[i].phoneNumber << " " << employees[i].salary << endl;
    }

    file.close();
}

void displayEmployees(employee employees[], int count) {

    setlocale(LC_ALL, "Russian");

    for (int i = 0; i < count; i++) {
        cout << "Имя: " << employees[i].firstName << endl;
        cout << "Фамилия: " << employees[i].lastName << endl;
        cout << "Телефонный номер: " << employees[i].phoneNumber << endl;
        cout << "Заработная плата: " << employees[i].salary << endl;
        cout << endl;
    }
}

void searchByLastName(employee employees[], int count, const char* lastName) {

    setlocale(LC_ALL, "Russian");

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].lastName, lastName) == 0) {
            cout << "Имя: " << employees[i].firstName << endl;
            cout << "Фамилия: " << employees[i].lastName << endl;
            cout << "Телефонный номер: " << employees[i].phoneNumber << endl;
            cout << "Заработная плата: " << employees[i].salary << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Сотрудник с фамилией " << lastName << " не найден." << endl;
    }
}

void searchBySal(employee employees[], int count, double minSalary, double maxSalary) {

    setlocale(LC_ALL, "Russian");

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (employees[i].salary >= minSalary && employees[i].salary <= maxSalary) {
            cout << "Имя: " << employees[i].firstName << endl;
            cout << "Фамилия: " << employees[i].lastName << endl;
            cout << "Телефонный номер: " << employees[i].phoneNumber << endl;
            cout << "Заработная плата: " << employees[i].salary << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Сотрудники с зп в диапазоне от " << minSalary << " до " << maxSalary << " не найдены" << endl;
    }
}

void sortEmpLastName(employee employees[], int count) {

    setlocale(LC_ALL, "Russian");

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(employees[j].lastName, employees[j + 1].lastName) > 0) {
                employee buf = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = buf;
            }
        }
    }
}

void addEmployee(employee employees[], int& count) {

    setlocale(LC_ALL, "Russian");

    if (count >= MAX_EMPLOYEES) {
        cout << "Уже максимальное количество сотрудников" << endl;
        return;
    }

    cout << "Введите имя нового сотрудника: ";
    cin >> employees[count].firstName;
    cout << "Введите фамилию нового сотрудника: ";
    cin >> employees[count].lastName;
    cout << "Введите телефонный номер нового сотрудника: ";
    cin >> employees[count].phoneNumber;
    cout << "Введите заработную плату нового сотрудника: ";
    cin >> employees[count].salary;

    count++;
}

void removeEmployee(employee employees[], int& count) {

    setlocale(LC_ALL, "Russian");

    char lastName[50];
    cout << "Введите фамилию сотрудника для удаления: ";
    cin >> lastName;

    int num = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].lastName, lastName) == 0) {
            num = i;
            break;
        }
    }

    if (num == -1) {
        cout << "Сотрудник с фамилией " << lastName << " не найден" << endl;
    }
    else {
        for (int i = num; i < count - 1; i++) {
            employees[i] = employees[i + 1];
        }
        count--;
        cout << "Сотрудник удален" << endl;
    }
}

int main() {
    employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;

    setlocale(LC_ALL, "Russian");
    fromFile(employees, employeeCount);

    while (true) {
        cout << "Меню:" << endl;
        cout << "1. Загрузить информацию файла" << endl;
        cout << "2. Запись в файл" << endl;
        cout << "3. Показать всю книгу сотрудников" << endl;
        cout << "4. Поиск по фамилии" << endl;
        cout << "5. Поиск по диапазону заработной платы" << endl;
        cout << "6. Сортировка по фамилии" << endl;
        cout << "7. Добавление сотрудника" << endl;
        cout << "8. Удаление сотрудника" << endl;
        cout << "9. Выход\n" << endl;

        int choice;
        cout << "Выберите опцию: ";
        cin >> choice;

        switch (choice) {
        case 1:
            fromFile(employees, employeeCount);
            cout << "Информация загружена из файла" << endl;
            break;
        case 2:
            toFile(employees, employeeCount);
            cout << "Информация записана в файл" << endl;
            break;
        case 3:
            displayEmployees(employees, employeeCount);
            break;
        case 4:
            char searchLastName[50];
            cout << "Введите фамилию: ";
            cin >> searchLastName;
            searchByLastName(employees, employeeCount, searchLastName);
            break;
        case 5:
            double minSal, maxSal;
            cout << "Введите минимальную заработную плату: ";
            cin >> minSal;
            cout << "Введите максимальную заработную плату: ";
            cin >> maxSal;
            searchBySal(employees, employeeCount, minSal, maxSal);
            break;
        case 6:
            sortEmpLastName(employees, employeeCount);
            cout << "Сотрудники отсортированы" << endl;
            break;
        case 7:
            addEmployee(employees, employeeCount);
            cout << "Новый сотрудник добавлен" << endl;
            break;
        case 8:
            removeEmployee(employees, employeeCount);
            break;
        case 9:
            return 0;
        default:
            cout << "Нет такого варианта" << endl;
            break;
        }

        cout << endl;
    }

    return 0;
}