#include <iostream>
#include <string>
#include <memory>

class LinkedListIndexError : public std::exception {
    std::string msg;
public:
    LinkedListIndexError(const std::string& message) : msg(message) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

template <typename T>
class Object;

template <typename T>
using NodePtr = std::shared_ptr<Object<T>>;

template <typename T>
class Object {
protected:
    T data{0};
    NodePtr<T> next{nullptr};
public:
    Object(T data) : data(data) {}
    const T& get_data() const { return data; }
    NodePtr<T> get_next() const { return next; }
    void set_next(NodePtr<T> next) { this->next = next; }
};

template <typename T>
class LinkedList {
    NodePtr<T> head = nullptr;
    NodePtr<T> tail = nullptr;
    size_t size = 0;
public:
    LinkedList() = default;
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    NodePtr<T> get_head() const { return head; }
    NodePtr<T> get_tail() const { return tail; }
    size_t get_size() const { return size; }
    bool is_empty() const { return head == nullptr; }

    void push_back(const T& data);
    void push_front(const T& data);
    void pop_back();
    void pop_front();

    T& operator[](size_t index);
};

template <typename T>
void LinkedList<T>::push_back(const T& data) {
    auto new_node = std::make_shared<Object<T>>(data);

    if (is_empty()) {
        head = tail = new_node;
    } else {
        tail->set_next(new_node);
        tail = new_node;
    }
    size++;
}

template <typename T>
void LinkedList<T>::push_front(const T& data) {
    auto new_node = std::make_shared<Object<T>>(data);

    if (is_empty()) {
        head = tail = new_node;
    } else {
        new_node->set_next(head);
        head = new_node;
    }
    size++;
}

template <typename T>
void LinkedList<T>::pop_back() {
    if (is_empty()) return;

    if (head == tail) {
        head = tail = nullptr;
    } else {
        auto current = head;
        while (current->get_next() != tail) {
            current = current->get_next();
        }
        current->set_next(nullptr);
        tail = current;
    }
    size--;
}

template <typename T>
void LinkedList<T>::pop_front() {
    if (is_empty()) return;

    head = head->get_next();
    if (head == nullptr) {
        tail = nullptr;
    }
    size--;
}

template <typename T>
T& LinkedList<T>::operator[](size_t index) {
    if (index >= size)
        throw LinkedListIndexError("Invalid element index.");

    auto current = head;
    size_t count = 0;

    while (count < index) {
        current = current->get_next();
        count++;
    }

    return const_cast<T&>(current->get_data());
}

struct Complex {
    double re{0}, im{0};
};

int main() {
    LinkedList<Complex> lst;

    lst.push_back(Complex{1, 2});
    lst.push_back(Complex{3, 4});
    lst.push_front(Complex{-1, -2});
    lst.pop_back();
    lst.pop_front();

    Complex d = lst[0];
    std::cout << "Complex d: " << d.re << " " << d.im << std::endl;
    lst[0] = Complex{5, 8};

    LinkedList<int> lst_int;
    lst_int.push_back(1);
    lst_int.push_back(2);
    lst_int.push_back(3);

    int var = lst_int[1];
    std::cout << "int var: " << var << std::endl;
    lst_int[2] = -5;

    // Перебор первого списка
    std::shared_ptr<Object<Complex>> ptr_lst = lst.get_head();
    while(ptr_lst) {
        Complex res = ptr_lst->get_data();
        std::cout << res.re << "," << res.im << " ";
        ptr_lst = ptr_lst->get_next();
    }
    std::cout << std::endl;

    // Перебор второго списка
    std::shared_ptr<Object<int>> ptr_lst_int = lst_int.get_head();
    while(ptr_lst_int) {
        int a = ptr_lst_int->get_data();
        std::cout << a << " ";
        ptr_lst_int = ptr_lst_int->get_next();
    }
    std::cout << std::endl;

    return 0;
}