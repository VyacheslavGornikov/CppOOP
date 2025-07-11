#include <iostream>
#include <memory>

class Object {
    int data {0};
    std::shared_ptr<Object> next {nullptr};
public:
    Object(int d) : data(d), next(nullptr)
        { }

    int get_data() const { return data; }
    std::shared_ptr<Object>& get_next() { return next; }
};

using shared_obj_ptr = std::shared_ptr<Object>;

class Stack {
    shared_obj_ptr top {nullptr};
public:
    shared_obj_ptr get_top() { return top; }

    void push(int data)
    {
        shared_obj_ptr node = std::make_shared<Object>(data);
        node->get_next() = top;
        top = node;
    }

    shared_obj_ptr pop() {
        if (!top) return nullptr;
        shared_obj_ptr ptr = top;
        top = top->get_next();
        return ptr;
    }

    const Stack& operator= (const Stack& right)
    {
        if (this == &right) return right;

        top = nullptr;

        shared_obj_ptr current = right.top;

        Stack temp;
        while (current)
        {
            temp.push(current.get()->get_data());
            current = current.get()->get_next();
        }

        current = temp.top;
        while (current)
        {
            this->push(current.get()->get_data());
            current = current.get()->get_next();
        }
        return *this;
    }

    void operator+= (const int data) { this->push(data); }
    void operator-- () { this->pop(); }
    void operator-- (int) { this->pop(); }
};

int main(void)
{
    Stack s1, s2;
    s1.push(10); s1.push(-5);

    shared_obj_ptr p {s1.get_top()};
    while(p) {
        std::cout << p->get_data() << " ";
        p = p->get_next();
    }
    std::cout << std::endl;

    s2 = s1; // копирование стека s1 в стек s2 (стеки должны быть независимы, полная копия)
    p = s2.get_top();
    while(p) {
        std::cout << p->get_data() << " ";
        p = p->get_next();
    }
    std::cout << std::endl;

    s2 += 7; // добавление наверх стека нового элемента со значением 7 (поле data)
    p = s2.get_top();
    while(p) {
        std::cout << p->get_data() << " ";
        p = p->get_next();
    }
    std::cout << std::endl;

    s2--; // удаление верхнего объекта из стека (аналог метода pop)
    p = s2.get_top();
    while(p) {
        std::cout << p->get_data() << " ";
        p = p->get_next();
    }
    std::cout << std::endl;

    --s2; // удаление верхнего объекта из стека (аналог метода pop)
    p = s2.get_top();
    while(p) {
        std::cout << p->get_data() << " ";
        p = p->get_next();
    }
    std::cout << std::endl;

    return 0;
}