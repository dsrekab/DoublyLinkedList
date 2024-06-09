#include "include/Employee.h"
#include <string>

using namespace std;

Employee::Employee(int Id, const string& Name) : Id (Id), Name(Name) {}

string Employee::toString()
{
    return "[" + to_string(Id) + ":" + Name + "]";
}