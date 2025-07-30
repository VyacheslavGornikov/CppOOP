#include <iostream>

class PhysicInterface {
public:
    virtual void forward(int speed) = 0; // движение вперед
    virtual void stop() = 0; // останов
    virtual void left(double angle) = 0; // поворот влево
    virtual void right(double angle) = 0; // поворот вправо

    virtual ~PhysicInterface() { }
};

// здесь объявляйте классы
class Car
{
protected:
    int speed {0}; // скорость
    int x {0}, y{0}; // координаты автомобиля (на карте)
    int weight {0}; // вес
    double angle {0.0}; // угол поворота
public:
    Car(int x, int y, int weight) : x(x), y(y), weight(weight) {}
    void get_coords(int& x, int& y) const { x = this->x; y = this->y; } // получение текущих координат
    int get_speed() const { return speed; } // возвращает значение поля speed
    int get_weight() const { return weight; } // возвращает значение поля weight
    double get_angle() const { return angle; } // возвращает значение поля angle
    virtual ~Car() {}
};

class Train
{
protected:
    int speed {0}; // скорость
    int x {0}, y{0}; // координаты поезда (на карте)
    int weight {0}; // вес
    double power {0.0}; // мощность
public:
    Train(int x, int y, int weight, double power) : x(x), y(y), weight(weight), power(power) {}
    void get_coords(int& x, int& y) const { x = this->x; y = this->y; } // получение текущих координат
    int get_speed() const { return speed; } // возвращает значение поля speed
    int get_weight() const { return weight; } // возвращает значение поля weight
    double get_power() const { return power; } // возвращает значение поля power
    virtual ~Train() {}
};

class ModelCar : public Car, public PhysicInterface
{
public:
    ModelCar(int x, int y, int weight) : Car(x, y, weight) {}
    virtual void forward(int speed) override { this->speed = speed; } // заносит значение speed в поле speed
    virtual void stop() override { speed = 0; } // устанавливает значение speed равным 0
    virtual void left(double angle) { this->angle = angle; } // задает значение поля angle равным параметру angle
    virtual void right(double angle) { this->angle = -angle; } // задает значение поля angle равным параметру -angle
    virtual ~ModelCar() {}
};

class ModelTrain : public Train, public PhysicInterface
{
public:
    ModelTrain(int x, int y, int weight, double power) : Train(x, y, weight, power) {}
    virtual void forward(int speed) { this->speed = speed; } // заносит значение speed в поле speed
    virtual void stop() { speed = 0; } // устанавливает значение speed равным 0
    virtual void left(double angle) {} // ничего не делает (пустое тело)
    virtual void right(double angle) {} // ничего не делает (пустое тело)
    virtual ~ModelTrain() {}
};

int main(void)
{
    // здесь продолжайте функцию main
    PhysicInterface* obj_lst[] =
    {
        new ModelCar (0, 0, 1200),
        new ModelTrain (-5, 7, 534200, 574.33),
        new ModelCar (11, 24, 1920),
        new ModelCar (-1, 12, 945)
    };

    for (PhysicInterface* interface : obj_lst)
    {
        interface->forward(7);
    }
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память (если необходимо)
    for (PhysicInterface* interface : obj_lst)
    {
        delete interface;
    }

    return 0;
}