#include <iostream>
#include <string>

using namespace std;

class Human
{
private:

public:
    int age;
    int weight;
    string name;

    void Print ()
    {
        cout << "Имя: " << name << "\nВес: " << weight << "\nВозраст " << age <<
        endl;
    }

    Human(/* args */);
    ~Human();
};

Human::Human(/* args */)
{
}

Human::~Human()
{
}


int main (void)
{
    Human firstHuman;

    firstHuman.age = 25;
    firstHuman.name = "Ivanod Ivan Ivanovich";
    firstHuman.weight = 70;

    cout << "Age:" << firstHuman.age << endl;
    cout << firstHuman.name << endl;
    cout << firstHuman.weight << endl;

    firstHuman.Print();

    Human secondHuman;
    secondHuman.Print();

    return EXIT_SUCCESS;
}
