#include <iostream>
#include "Company.h"

using namespace std;

int main() {
    Address address("Iran", "Tehran", "East");
//    Address address1(address);
//    cout << address1 << endl;
//    cin >> address1;
//    cout << address1 << endl;
//    address.setStreet("ali");
//    address.setCity("Taj");
//    address.setCountry("India");
//    cout << address.getCountry() << address.getCity() << address.getStreet();
//**********************************************************************************************
//    Person person("ali", "84@jo12313", address);
//    Person person1 = person;
//    cout << person1 << endl;
//    cin >> person1;
//    cout << person1;
//**********************************************************************************************
    cout << "Enter 10 employee information" << endl;
    Employee **employees = new Employee *[10];
    for (int i = 0; i < 10; ++i) {
        employees[i] = new Employee;
        cin >> *employees[i];
    }
//    Employee employee("ali", "99*11111", address, 5, 10, 4, 3);
//    Employee employee1(employee);
//    cout << employee1 << endl;
//    cout << employee.calculateSalary() << endl;
//    cout << employee.efficiency() << endl;
//    cin >> employee1;
//    employee = employee1;
//    cout << employee << endl;
//**********************************************************************************************
    Boss boss("mohammad", "99*22222", address, 5, 10, 10, 8, 10);
//    Boss boss1(boss);
//    cout << boss1 << endl;
//    cout << boss1.calculateSalary() << endl;
//    cin >> boss1;
//    boss = boss1;
//    cout << boss << endl;
//**********************************************************************************************
    Company company(10000000, boss, employees);
    Company company1(company);
    cout << company1 << endl;
//    cin >> company1;
//    company = company1;
//    cout << company << endl;
//    cout << company.maxEfficiency() << endl;
//    cout << "Average employees' efficiency: " << company.averageEfficiency() << endl;
//    company.changeOfBoss();
//    cout << company << endl;
//    if (company.isEnoughBudget()) {
//        company.payForService();
//        company.gift();
//    }
//    company.toSave();
    return 0;
}
