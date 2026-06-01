#include <iostream>
#include <cstdlib> 
using namespace std;

const int max_size = 10;

struct Stack_tag {
    char data[max_size];
    int size;
};

void pushSt(Stack_tag* st, char value) {
    if (st->size >= max_size) {
        cout << "Помилка: Stack Overflow. Неможливо додати '" << value << "'\n";
        exit (0);
    }
    st->data[st->size] = value;
    st->size++;
    cout << "Елемент '" << value << "' додано до стеку (push).\n";
}

char popSt(Stack_tag* st) {
    if (st->size == 0) {
        cout << "Помилка: Stack Underflow. Стек порожнiй\n";
        exit (0);
    }
    st->size--;
    char value = st->data[st->size];
    cout << "Елемент '" << value << "' знято з вершини стеку (pop).\n";
    return value;
}

char peekSt(Stack_tag* st) {
    if (st->size == 0) {
        cout << "Помилка: Stack is empty. Немає вершини для перегляду (peek).\n";
        return '\0';
    }
    char value = st->data[st->size - 1];
    cout << "Вершина стеку (peek): '" << value << "'\n";
    return value;
}

void printStackValue(char symbol) {
    cout << symbol << " | ";
}

void printSt(Stack_tag& st, void (*printFunc)(char)) {
    if (st.size == 0) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Поточний вмiст стеку: ";
    for (int i = st.size - 1; i >= 0; --i) {
        printFunc(st.data[i]);
    }
    cout << endl;
}

int main() {
    Stack_tag stack;
    stack.size = 0;

    cout << "\nДодаємо елементи: 3, 5, 7\n";
    pushSt(&stack, '3');
    pushSt(&stack, '5');
    pushSt(&stack, '7');

    printSt(stack, printStackValue);

    cout << "\nПереглядаємо поточну вершину стеку:\n";
    peekSt(&stack);

    cout << "\nЗнiмаємо елементи зi стеку:\n";
    popSt(&stack);
    printSt(stack, printStackValue);

    popSt(&stack);
    printSt(stack, printStackValue);

    popSt(&stack);
    printSt(stack, printStackValue);

    popSt(&stack);

    cout << "\nСпроба перегляду вершини порожнього стеку:\n";
    char peek_result = peekSt(&stack);
    if (peek_result == '\0') {
        cout << "Продовжуємо виконання після помилки перегляду порожнього стеку.\n\n\n";
    }
    


    for (int i = 0; i < max_size; i++) {
        char value = 'A' + i;
        cout << "Крок " << i + 1 << ": Додаємо елемент '" << value << "'\n";
        pushSt(&stack, value);
        printSt(stack, printStackValue);
        cout << "Поточний розмір стеку: " << stack.size << "/" << max_size << "\n\n";
    }

    cout << "Стек досяг максимального розміру " << max_size << " елементів.\n";
    printSt(stack, printStackValue);

    cout << "\nСпроба додати елемент 'Z' у вже повний стек (Stack Overflow):\n";
    pushSt(&stack, 'Z');
    
    return 0;
}
