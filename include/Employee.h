#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

struct Employee
{
    int Id;
    string Name;

    Employee(int Id, const string& Name);

    string toString();
};

#endif