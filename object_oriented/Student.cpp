#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

class Student
{
public:
    Student()
    {
    }
    virtual ~Student()
    {
    }

    Student(string _name, int _age)
    {
        this->name = _name;
        this->age = _age;
    }
    string getName()
    {
        return this->name;
    }
    int getAge()
    {
        return this->age;
    }
    string to_string()
    {
        stringstream s;
        s << this->name << " " << std::to_string(this->age);
        return s.str();
    }

protected:
    string name;
    int age;
};

class goodStudent : public Student
{
public:
    goodStudent(string _name, int _age, int _ID) : Student(_name, _age)
    {
        this->deansListID = _ID;
    }
    int getDeansListID()
    {
        return this->deansListID;
    }
    // good student id
    string to_string()
    {
        return Student::to_string() + " " + std::to_string(this->deansListID);
    }

private:
    int deansListID;
};

int main()
{
    // read size form input
    int num;
    cin >> num;
    // create map
    map<int, Student> mp;

    // main variables
    int id = 0;
    string name;
    int age;
    Student *s;

    // main loop
    for (int i = 0; i < num; i++)
    {
        string intro = "";
        cin >> name >> age;
        if (i % 2 == 0)
        {
            s = new Student(name, age);
        }
        else
        {
            s = new goodStudent(name, age, i);
        }

        intro += s->Student::to_string();
        // insert into map
        mp.insert({id, *s});
        if (dynamic_cast<goodStudent *>(s))
        {
            intro += " is a good Student";
        }
        else
        {
            intro += " is trying his best";
        }
        cout << intro << endl;
        id++;
    }
    cout << "enter student is to search" << endl;
    int studentId;
    cin >> studentId;
    auto it = mp.find(studentId);
    if (it != mp.end())
    {
        cout << "student number " << studentId << " is " << mp[studentId].to_string() << endl;
    }
    else
    {
        cout << "not found";
    }
    return 0;
}