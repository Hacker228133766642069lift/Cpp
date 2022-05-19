// queueueueueueueueueueueue.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct Node {
    int val;
    Node* next;
};

struct Queue {
    unsigned size;
    Node* head;
    Node* tail;
};

Node* createNode(int value) {
    return new Node{ value, nullptr };
}

Node* ith_node(Queue* list, unsigned idx) {
    Node* node = list->head;
    for (int i = 0; i < idx; ++i) {
        node = node->next;
    }
    return node;
}

void enQueue(Queue* list, int new_val) {
    Node* new_node = createNode(new_val);
    if (list->size != 0) {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    else {
        list->tail = new_node;
        list->head = new_node;
    }
    list->size++;
}

int deQueue(Queue* list) {

    int head_val = list->head->val;
    delete list->tail;

    list->size--;
    if (list->size != 0) {
        Node* new_tail = ith_node(list, list->size - 1);
        list->tail = new_tail;
        new_tail->next = nullptr;
    }
    else {
        list->head = nullptr;
        list->tail = nullptr;
    }
    return head_val;
}

int front(Queue* queue) {
    if (queue->size == 0)
        return 0;
    return queue->head->val;
}

int rear(Queue* queue) {
    if (queue->size == 0)
        return 0;
    return queue->tail->val;
}

unsigned length(Queue* list) {
    return list->size;
}

void print(Queue* list) {
    if (list->size != 0) {
        for (int idx = 0; idx < list->size; ++idx) {
            std::cout << ith_node(list, idx)->val << " ";
        }
        std::cout << std::endl;
    }
    else
        std::cout << "list is empty" << std::endl;
}


void clear(Queue* list) {
    for (unsigned i = list->size; i > 0; --i) {
        deQueue(list);
    }
}

Queue* createQueue(unsigned size) {
    Queue* tmp = new Queue{ 0, nullptr, nullptr };
    for (int i = 0; i < size; ++i) {
        enQueue(tmp, 0);
    }
    return tmp;
}

int main() {
    Queue list1 = *createQueue(2);
    print(&list1);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
