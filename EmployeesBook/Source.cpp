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
        cout << "������, ����� ���" << endl;
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
        cout << "��� �����\n" << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        file << employees[i].firstName << " " << employees[i].lastName << " " << employees[i].phoneNumber << " " << employees[i].salary << endl;
    }

    file.close();
}

int main() {
    employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;

    setlocale(LC_ALL, "Russian");
    fromFile(employees, employeeCount);

    while (true) {
        cout << "����:" << endl;
        cout << "1. ��������� ���������� �����" << endl;
        cout << "2. ������ � ����" << endl;
        cout << "3. �������� ��� ����� �����������" << endl;
        cout << "4. ����� �� �������" << endl;
        cout << "5. ����� �� ��������� ���������� �����" << endl;
        cout << "6. ���������� �� �������" << endl;
        cout << "7. ���������� ����������" << endl;
        cout << "8. �������� ����������" << endl;
        cout << "9. �����\n" << endl;

        int choice;
        cout << "�������� �����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            fromFile(employees, employeeCount);
            cout << "���������� ��������� �� �����" << endl;
            break;
        case 2:
            toFile(employees, employeeCount);
            cout << "���������� �������� � ����" << endl;
            break;
        case 3:
            displayEmployees(employees, employeeCount);
            break;
        case 4:
            char searchLastName[50];
            cout << "������� �������: ";
            cin >> searchLastName;
            searchByLastName(employees, employeeCount, searchLastName);
            break;
        case 5:
            double minSal, maxSal;
            cout << "������� ����������� ���������� �����: ";
            cin >> minSal;
            cout << "������� ������������ ���������� �����: ";
            cin >> maxSal;
            searchBySal(employees, employeeCount, minSal, maxSal);
            break;
        case 6:
            sortEmpLastName(employees, employeeCount);
            cout << "���������� �������������" << endl;
            break;
        case 7:
            addEmployee(employees, employeeCount);
            cout << "����� ��������� ��������" << endl;
            break;
        case 8:
            removeEmployee(employees, employeeCount);
            break;
        case 9:
            return 0;
        default:
            cout << "��� ������ ��������" << endl;
            break;
        }

        cout << endl;
    }

    return 0;
}