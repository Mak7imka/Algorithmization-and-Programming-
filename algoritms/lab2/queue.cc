#include <iostream>

using namespace std;

const int max_size = 10;

struct Queue {
    char que[max_size];
    int head;
    int tail;
};

void init(Queue* q) {
    q->head = 1;
    q->tail = 0;
    cout << "Чергу iнiцiалiзовано: head = 1, tail = 0\n";
}

void insert(Queue* q, char value) {
    if (q->tail >= max_size - 1) {
        cout << "Помилка: Черга переповнена. Неможливо додати '" << value << "'\n";
        exit(0);
    }
    q->tail++;
    q->que[q->tail] = value;
    cout << "Елемент '" << value << "' додано до черги (insert).\n";
}

int isempty(Queue* q) {
    return q->tail < q->head;
}

void print(Queue* q) {
    if (isempty(q)) {
        cout << "Черга порожня.\n";
        return;
    }

    cout << "Поточна черга (вiд head до tail): ";
    for (int i = q->head; i <= q->tail; i++) {
        cout << q->que[i] << " | ";
    }
    cout << endl;
}

char remove(Queue* q) {
    if (isempty(q)) {
        cout << "Помилка: Черга порожня. Немає елементiв для видалення.\n";
        return '\0';
    }
    char value = q->que[q->head];
    q->head++;
    cout << "Елемент '" << value << "' видалено з черги (remove).\n";
    return value;
}

int main() {
    Queue queue;
    init(&queue);

    cout << "\nДодаємо елементи до черги: A, B, C\n";
    insert(&queue, 'A');
    insert(&queue, 'B');
    insert(&queue, 'C');

    print(&queue);

    cout << "\nВидаляємо два елементи:\n";
    remove(&queue);
    remove(&queue);

    print(&queue);

    cout << "\nПеревiрка порожньої черги:\n";
    if (isempty(&queue))
        cout << "Черга порожня\n";
    else
        cout << "Черга не порожня\n";

    cout << "\nВидаляємо останнiй елемент:\n";
    remove(&queue);

    print(&queue);


    cout << "\nПеревiрка переповнення черги:\n";
    init(&queue);
    for (int i = 0; i < max_size; i++) {
        insert(&queue, 'X' + i);
    }

    print(&queue);

    cout << "\nСпроба додати ще один елемент у повну чергу (очiкувана помилка):\n";
    insert(&queue, '!');

    return 0;
}
