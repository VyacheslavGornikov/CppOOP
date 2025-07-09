#include <iostream>
#include <cstring>

class StringBuffer {
    enum {max_size = 1024};
    char *buffer {nullptr};
    int size {0};
public:
    StringBuffer(const char* str)
    {
        size = 0;
        while(str[size] != '\0' && size < max_size-1)
            size++;

        buffer = new char[size+1];
        for(int i = 0;i < size; ++i)
            buffer[i] = str[i];

        buffer[size] = '\0';
    }
    StringBuffer(const StringBuffer& other) : StringBuffer(other.buffer)
    {}
    ~StringBuffer() { delete[] buffer; }

    const char* get_data() const { return buffer; }
    int get_size() const { return size; }

    friend StringBuffer operator+ (const char* str,
                                   const StringBuffer& other);
    const char* operator+= (const char* str)
    {
        size_t str_len = strlen(str) + 1;
        char temp[max_size] {0};
        strncpy(temp, buffer, size);
        delete[] buffer;
        size = size + str_len > max_size ? max_size : size + str_len;
        buffer = new char[size];
        strncpy(buffer, temp, strlen(temp));
        strcat(buffer, str);

        return buffer;
    }
};

StringBuffer operator+ (const char* str, const StringBuffer& other)
{
    char new_str[other.max_size];
    size_t str_len = strlen(str);
    strncpy(new_str, str, str_len);
    strcat(new_str, other.buffer);
    return StringBuffer(new_str);
}

int main(void)
{
    StringBuffer s1 = "World";
    StringBuffer s2 = "Hello, " + s1; // s2: "Hello, World"
    std::cout << s2.get_data() << std::endl;
    s2 += "!"; // s2: "Hello, World!"
    std::cout << s2.get_data() << std::endl;
    StringBuffer cp {s2};
    std::cout << cp.get_data() << std::endl;
    return 0;
}