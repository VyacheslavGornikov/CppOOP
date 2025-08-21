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
    NodePtr<T> prev{nullptr};
    NodePtr<T> next{nullptr};
public:
    Object(T data) : data(data) {}
    const T& get_data() const { return data; }
    NodePtr<T> get_prev() const { return prev; }
    NodePtr<T> get_next() const { return next; }
    void set_prev(NodePtr<T> prev) { this->prev = prev; }
    void set_next(NodePtr<T> next) { this->next = next; }
};

template <typename T>
class LinkedList {
    NodePtr<T> head = nullptr;
    NodePtr<T> tail = nullptr;
    size_t size = 0;
    NodePtr<T> get_node_at_index(size_t index);
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
    void remove(size_t index);
    void insert(size_t index, const T& data);
};

template <typename T>
NodePtr<T> LinkedList<T>::get_node_at_index(size_t index)
{
    auto current = head;
    size_t count = 0;

    while (count < index) {
        current = current->get_next();
        count++;
    }

    return current;
}

template <typename T>
void LinkedList<T>::push_back(const T& data) {
    auto new_node = std::make_shared<Object<T>>(data);

    if (is_empty()) {
        head = tail = new_node;
    } else {
        NodePtr<T> prev = tail;
        tail->set_next(new_node);
        tail = new_node;
        tail->set_prev(prev);
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
        head->set_prev(new_node);
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
        tail = tail->get_prev();
        tail->set_next(nullptr);
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
    else {
        head->set_prev(nullptr);
    }
    size--;
}

template <typename T>
T& LinkedList<T>::operator[](size_t index) {
    if (index >= size)
        throw LinkedListIndexError("Invalid element index.");

    auto current = get_node_at_index(index);

    return const_cast<T&>(current->get_data());
}

template <typename T>
void LinkedList<T>::remove(size_t index)
{
    if (index >= size)
        throw LinkedListIndexError("Invalid element index.");

    auto current = get_node_at_index(index);

    if (head == tail)
    {
        head = tail = nullptr;
    }

    else if (current == head)
    {
        head = head->get_next();
        head->set_prev(nullptr);
    }
    else if (current == tail)
    {
        tail = tail->get_prev();
        tail->set_next(nullptr);
    }
    else
    {
        auto prev = current->get_prev();
        auto next = current->get_next();
        prev->set_next(next);
        next->set_prev(prev);
    }

    size--;
}

template <typename T>
void LinkedList<T>::insert(size_t index, const T& data)
{
    if (index > size)
        throw LinkedListIndexError("Invalid element index.");



    if (index == 0)
    {
        push_front(data);
    }
    else if (index == size)
    {
        push_back(data);
    }
    else
    {
        auto new_node = std::make_shared<Object<T>>(data);
        auto current = get_node_at_index(index);
        auto prev = current->get_prev();

        prev->set_next(new_node);
        new_node->set_prev(prev);
        new_node->set_next(current);
        current->set_prev(new_node);

        size++;
    }
}

struct Complex {
    double re{0}, im{0};
};

int main() {
    LinkedList<std::string> lst; // создание пустого двусвязного списка

    lst.push_back("hello"); // добавление элемента в конец
    lst.push_back("C++");
    lst.push_front("OOP"); // добавление элемента в начало
    lst.push_front("Balakirev");
    lst.push_front("Sergey");
    lst.pop_back(); // удаление последнего элемента
    lst.pop_front(); // удаление первого элемента

    size_t indx = 1;

    lst.remove(indx); // удаление элемента по индексу indx (индекс с нуля: 0, 1, ...)
    lst.insert(indx, "Insert elemenet"); // вставка элемента так, чтобы у него был индекс indx

    std::string s = lst[0]; // получение данных из элемента с индексом 0
    std::cout << "lst[0] = " << lst[0] << std::endl;
    lst[0] = "hello"; // изменение данных в элементе с индексом 0

    LinkedList<unsigned> lst_u; // еще один двусвязный список

    lst_u.push_back(1);
    lst_u.push_back(2);
    lst_u.push_back(3);

    unsigned var = lst_u[1];
    std::cout << "var = " << var << std::endl;
    lst_u[0] = 15;

    // перебор элементов с конца в начало
    std::shared_ptr< Object<std::string> > ptr_lst = lst.get_tail();
    std::cout << "reversed string lst" << std::endl;
    while(ptr_lst) {
        std::string res = ptr_lst->get_data();
        std::cout << res << " ";
        ptr_lst = ptr_lst->get_prev();
    }
    std::cout << std::endl;

    // перебор элементов с начала и до конца
    std::shared_ptr< Object<unsigned> > ptr_lst_u = lst_u.get_head();
    std::cout << "direct unsigned lst" << std::endl;
    while(ptr_lst_u) {
        unsigned a = ptr_lst_u->get_data();
        std::cout << a << " ";
        ptr_lst_u = ptr_lst_u->get_next();
    }
    std::cout << std::endl;
}