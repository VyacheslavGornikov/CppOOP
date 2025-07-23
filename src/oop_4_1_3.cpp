#include <iostream>
#include <string>

class Animal
{
protected:
    std::string name;
    short old {0};
public:
    Animal() = default;
    Animal(std::string name, short old) : name(name), old(old)
    {}
    const std::string& get_name() const { return name; } // возвращает значение поля name
    short get_old() const { return old; } // возвращает значение поля oldпереданные значения
};

class Cat : public Animal
{
    int color {0};  // цвет кота
    double weight {0.0}; // вес кота
public:
    Cat(const std::string& name, short old, int color, double weight) :
    color(color), weight(weight) { this->name = name; this->old = old; }
    int get_color() const { return color; } // возвращает значение поля color
    double get_weight() const { return weight; } // возвращает значение поля weight
    void set_info(const std::string& name, short old, int color, double weight)
    {
        this->name = name;
        this->old = old;
        this->color = color;
        this->weight = weight;
    } // заносит в соответствующие поля переданные значения
};

class Dog : public Animal
{
    std::string breed; // порода собаки
    short length {0}; // длина собаки
public:
    Dog(const std::string& name, short old, const std::string& breed, short length) :
    breed(breed), length(length)
    { this->name = name; this->old = old; }
    const std::string& get_breed() const { return breed; } // возвращает значение поля breed
    short get_length() const { return length; } // возвращает значение поля length
    void set_info(const std::string& name, short old, const std::string& breed, short length)
    {
        this->name = name;
        this->old = old;
        this->breed = breed;
        this->length = length;
    } // заносит в соответствующие поля переданные значения
};