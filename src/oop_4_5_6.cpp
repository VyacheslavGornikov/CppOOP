#include <iostream>

enum type_life {
    lf_protists = 1,
    lf_plants = 2,
    lf_animals = 3,
    lf_mosses = 4,
    lf_flowering = 5,
    lf_worms = 6,
    lf_mammals = 7,
    lf_human = 8,
    lf_monkeys = 9
};

class Protists {
    const type_life type {lf_protists}; // вид живого организма
public:
    virtual const type_life get_type() const { return type; }
    virtual ~Protists() { }
};

class Plants : public Protists
{
    const type_life type {lf_plants}; // вид живого организма
public:
    virtual const type_life get_type() const override { return type; }
    virtual ~Plants() { }
};

class Mosses : public Plants
{
    const type_life type {lf_mosses}; // вид живого организма
public:
    virtual const type_life get_type() const override { return type; }
    virtual ~Mosses() { }
};

class Flowering : public Plants
{
    const type_life type {lf_flowering}; // вид живого организма
public:
    virtual const type_life get_type() const override { return type; }
    virtual ~Flowering() { }
};

class Animals : public Protists
{
    const type_life type {lf_animals}; // вид живого организма
public:
    virtual const type_life get_type() const override { return type; }
    virtual ~Animals() { }
};

class Worms : public Animals
{
    const type_life type {lf_worms}; // вид живого организма
public:
    virtual const type_life get_type() const override { return type; }
    virtual ~Worms() { }
};

class Mammals : public Animals
{
    const type_life type {lf_mammals}; // вид живого организма
public:
    virtual const type_life get_type() const override { return type; }
    virtual ~Mammals() { }
};

class Human : public Mammals
{
    const type_life type {lf_human}; // вид живого организма
public:
    virtual const type_life get_type() const override { return type; }
    virtual ~Human() { }
};

class Monkeys : public Mammals
{
    const type_life type {lf_monkeys}; // вид живого организма
public:
    virtual const type_life get_type() const override { return type; }
    virtual ~Monkeys() { }
};

int main(void)
{
    // здесь продолжайте функцию main
    Protists* life[] =
    {
        new Plants,
        new Flowering,
        new Flowering,
        new Monkeys,
        new Animals,
        new Worms,
        new Worms,
        new Human,
        new Monkeys,
        new Mammals,
        new Animals,
        new Animals
    };

    Animals* lf_lst1[] =
    {
        dynamic_cast<Animals*>(life[4]),
        dynamic_cast<Animals*>(life[10]),
        dynamic_cast<Animals*>(life[11])
    };
    Monkeys* lf_lst2[] =
    {
        dynamic_cast<Monkeys*>(life[3]),
        dynamic_cast<Monkeys*>(life[8])
    };
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память (если необходимо)
    for (size_t i = 0; i < sizeof(lf_lst1) / sizeof(lf_lst1[0]); i++)
    {
        delete lf_lst1[i];
    }

    for (size_t i = 0; i < sizeof(lf_lst2) / sizeof(lf_lst2[0]); i++)
    {
        delete lf_lst2[i];
    }
    return 0;
}