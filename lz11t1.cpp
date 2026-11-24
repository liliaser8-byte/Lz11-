#include <iostream>
#include <list>

using namespace std;

int main() {
    int N;
    cout << "Введіть кількість елементів списку N: ";
    cin >> N;

    // Перевірка, чи є N додатним числом (вимога завдання)
    if (N <= 0) {
        cout << "Помилка: кількість елементів N має бути додатним числом!" << endl;
        return 1;
    }

    list<int> numbers;
    cout << "Введіть " << N << " цілих чисел:\n";
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        numbers.push_back(val);
    }

    // Виведення початкового списку
    cout << "\nПочатковий список: ";
    for (int x : numbers) {
        cout << x << " ";
    }
    cout << endl;

    // 1. Вставити 25 перед кожним додатним елементом (як у Прикладі 2)
    list<int>::iterator it = numbers.begin();
    while (it != numbers.end()) {
        if (*it > 0) {
            numbers.insert(it, 25);
        }
        it++;
    }

    // Виведення проміжного результату (після вставки)
    cout << "Після вставки 25 перед додатними: ";
    for (int x : numbers) {
        cout << x << " ";
    }
    cout << endl;

    // 2. Вилучити всі від'ємні числа (як у Прикладі 1)
    it = numbers.begin();
    while (it != numbers.end()) {
        if (*it < 0) {
            it = numbers.erase(it); // erase повертає ітератор на наступний елемент
        } else {
            it++;
        }
    }

    // Виведення результуючого списку
    cout << "Результуючий список (після вилучення від'ємних): ";
    for (int x : numbers) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}