// Stack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>




struct Node {
    int value;
    Node* next;
};

struct Stack {
    unsigned size=0;
    Node* head;
};


Node* find_in_List(Stack* list, unsigned idx) {
    Node* q = nullptr;
    if (idx < (*list).size) {

        Node* q = list->head;
        unsigned i = 0;

        while (i < idx) {
            q = q->next;
            i++;
        }
    }
    return q;
}

void push(Stack* stack, int new_val) {
    Node* q = new Node;
    q->value = new_val;
    if (stack->size == 0) {
        stack->head = q;
    }
    else {
        Node* P = find_in_List(stack, (*stack).size - 1);
        if (P == nullptr) {
            P->next = q;
        }
        stack->size++;
    }
}

int pop(Stack * list) {
    int res=-1;
    if (list->size != 0) {
        int res;
        Node* q = find_in_List(list, (*list).size - 1);
        res = q->value;
        delete q;
        (*list).size--;
    }
    else std::cout << "error";
    return res;
}


int top(Stack* list) {
    return find_in_List(list, (*list).size - 1)->value;
}

unsigned lenght(Stack* list) {
    return list->size;
}

void print(Stack* list) {
    Node* q = new Node;
    q = list->head;
    
    for (unsigned i = 0;i<(*list).size;i++) {

        std::cout << q->value << ", ";
        q = q->next;

    }
    std::cout << "\n";
}

int get(Stack* list, unsigned idx) {
    return  find_in_List(list, idx)->value;
}

bool empty(Stack* stack) {
    return stack->size;
}

void clear(Stack* list) {
    Node* q = list->head;
    Node* p = q;
    for (unsigned i = 0; i < (*list).size;i++) {
        p = q;
        q = q->next;
        delete p;
    }
    list->size = 0;
}

int main()
{
    Stack List;
    pop(&List);
    push(&List, 10);
    print(&List);
    List.size = 2;
    Node* p = new Node;
    List.head = p;
    p->value = 10;
    Node* q = new Node;
    q->value = 0;
    p->next = q;

    print(&List);
    push(&List, 1);
    print(&List);
    std::cout << lenght(&List) << '\n';
    std::cout << get(&List, 2) << '\n' << '\n' << '\n' << '\n';
    print(&List);
    std::cout << lenght(&List) << '\n';
    print(&List);
    push(&List, 1);
    print(&List);

    print(&List);

    for (unsigned i = 0; i < 10; i++) {
            push(&List, i);
            //print(&List);
    }
    print(&List);

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
