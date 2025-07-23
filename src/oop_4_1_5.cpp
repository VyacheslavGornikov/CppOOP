#include <iostream>

// здесь объявляйте класс
class Clock
{
protected:
    unsigned time_current {0}; // текущее время в секундах
public:
    Clock() = default;
    Clock(unsigned time) : time_current(time)
    {}
    void set_time(unsigned tm) { time_current = tm; } // заносит в поле time_current значение tm
    unsigned get_hours() const { return time_current / 3600; } // возвращает количество часов в time_current
    unsigned get_minutes() const { return (time_current % 3600) / 60; } // возвращает количество минут в time_current (за вычетом часов)
    unsigned get_seconds() const { return (time_current % 3600) % 60; } // возвращает количество секунд в time_current (за вычетом часов и минут)
};

class ClockShow : public Clock
{
public:
    enum time_format { tm_hhmmss = 1, tm_hms = 2, tm_ssmmhh = 3, tm_smh = 4};
private:
    enum time_format format {tm_hhmmss}; // формат отображения времени
public:
    ClockShow() : Clock()
    {}
    ClockShow(unsigned time) : Clock(time)
    {}
    ClockShow(unsigned time, time_format tm_format) : ClockShow(time)
    { format = tm_format; }

    void show_time() const
    {
        switch (format)
        {
            case tm_hhmmss:
                printf("%02u:%02u:%02u", get_hours(), get_minutes(), get_seconds());
                break;
            case tm_hms:
                printf("%u:%u:%u", get_hours(), get_minutes(), get_seconds());
                break;
            case tm_ssmmhh:
                printf("%02u:%02u:%02u", get_seconds(), get_minutes(), get_hours());
                break;
            case tm_smh:
                printf("%u:%u:%u", get_seconds(), get_minutes(), get_hours());
                break;
            default:
                break;
        }
    }// выполняет отображение в консоль времени заданном формате

};

int main()
{
    // здесь продолжайте функцию main
    unsigned time;
    std::cin >> time;
    ClockShow clock(time, ClockShow::tm_hms);
    clock.show_time();

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}