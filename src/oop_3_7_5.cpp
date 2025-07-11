#include <iostream>
#include <string>
#include <random>

class RandomPassword
{
    std::string password = "";
    std::string password_mask = "";
    int min_length {0};
    int max_length {0};
    int length {0};

    std::mt19937 gen;
    std::uniform_int_distribution<int> length_dist;
    std::uniform_int_distribution<int> char_dist;
public:
    RandomPassword(std::string psw_chars, int min_length, int max_length) :
    password_mask(psw_chars), min_length(min_length), max_length(max_length),
    gen(std::random_device{}()), length_dist(min_length, max_length),
    char_dist(0, psw_chars.size() - 1)
    {}

    std::string operator() ()
    {
        length = length_dist(gen);

        password.clear();
        for (int i = 0; i < length; i++)
            password += password_mask[char_dist(gen)];

        return password;
    }

    int get_last_length() const { return length; }
};

int main(void)
{
    RandomPassword rnd("qwertyuiopasdfghjklzxcvbnm0123456789!@#$%&*", 5, 15);
    std::string psw_1 = rnd(); // psw_1: hqt5!v@gk
    std::string psw_2 = rnd();
    std::cout << psw_1 << "\t" << psw_2 << std::endl;
    return 0;
}