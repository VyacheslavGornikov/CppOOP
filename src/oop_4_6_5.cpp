#include <iostream>
#include <string>

// здесь объявляйте классы
enum { max_persons = 255 };

class Employee
{
public:
    virtual const std::string& get_fname() const = 0; // для получения имени сотрудника
    virtual const std::string& get_lname() const = 0; // для получения фамилии сотрудника
    virtual short get_old() const = 0; // для получения возраста сотрудника
    virtual ~Employee() = default;
};

class Lector : public Employee
{
    std::string first_name, last_name;
    short old {0};
    int salary {0};
public:
    Lector(const std::string& first_name = "", const std::string& last_name = "", short old = 0, int salary = 0) :
    first_name(first_name), last_name(last_name), old(old), salary(salary) {}
    void set_salary(int salary) { this->salary =salary; } // задает значение поля salary с проверкой на положительность параметра salary (если не так, то поле не менять)
    int get_salary() const { return salary; } // возвращает значение поля salary (зарплата)
    virtual const std::string& get_fname() const override { return first_name; } // для получения имени сотрудника
    virtual const std::string& get_lname() const override { return last_name; } // для получения фамилии сотрудника
    virtual short get_old() const override { return old; } // для получения возраста сотрудника
};

class Laborant : public Employee
{
    std::string first_name, last_name;
    short old {0};
    std::string job_title;
public:
    Laborant(const std::string& first_name = "", const std::string& last_name = "",
    short old = 0, const std::string& job_title = "") :
    first_name(first_name), last_name(last_name), old(old), job_title(job_title) {}
    void set_job_title(const std::string& job_title) { this->job_title = job_title; } // задает значение поля job_title (должность)
    const std::string& get_job_title() const { return job_title; } // возвращает значение поля job_title
    virtual const std::string& get_fname() const override { return first_name; } // для получения имени сотрудника
    virtual const std::string& get_lname() const override { return last_name; } // для получения фамилии сотрудника
    virtual short get_old() const override { return old; } // для получения возраста сотрудника
};

int main(void)
{
    // здесь продолжайте функцию main
    Employee* staff[max_persons] {nullptr};
    staff[0] = new Lector ("Sergey", "Balakirev", 33, 85000);
    staff[1] = new Laborant ("Elena", "Pozdnjakova", 27, "Programmer");
    staff[2] = new Lector ("Olga", "Levkina", 38, 120000);
    int staff_count = 3;

    for (int i = 0; i < staff_count; i++)
    {
        std::cout << staff[i]->get_fname();
        if (i != staff_count - 1) std::cout << " ";
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память (если необходимо)
    for (int i = 0; i < staff_count; i++)
        delete staff[i];
    return 0;
}