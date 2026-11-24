#include <iostream>
#include <list>
#include <string>
#include <iomanip>

using namespace std;

// Опис структури Track відповідно до варіанта
struct Track {
    string title;
    string artist;
    int duration;
    int releaseYear;
};

// Допоміжна функція для виведення списку в читабельному вигляді
void printTracks(const list<Track>& tracks) {
    cout << left << setw(22) << "Назва"
         << setw(18) << "Виконавець"
         << setw(15) << "Тривалість"
         << "Рік" << endl;
    cout << string(60, '-') << endl;
    for (const Track& t : tracks) {
        cout << left << setw(22) << t.title
             << setw(18) << t.artist
             << setw(15) << t.duration
             << t.releaseYear << endl;
    }
}

int main() {
    // Створення списку з 5 початкових записів
    list<Track> tracks = {
        {"Shum", "Go_A", 172, 2021},
        {"Intro", "The xx", 85, 2009},
        {"Stefania", "Kalush", 179, 2022},
        {"Solovey", "Go_A", 176, 2020},
        {"Interlude", "Okean Elzy", 65, 2016}
    };

    // 1. Виведення початкового списку
    cout << "Початковий список треків:\n";
    printTracks(tracks);

    // 2. Додавання запису на початок (push_front) і в кінець (push_back)
    tracks.push_front({"Obiymy", "Okean Elzy", 225, 2013});
    tracks.push_back({"Kalyna", "Go_A", 190, 2022});

    cout << "\nПісля додавання на початок та в кінець:\n";
    printTracks(tracks);

    // 3. Фільтрація: вивести треки заданого виконавця (наприклад, "Go_A")
    string targetArtist = "Go_A";
    cout << "\nТреки виконавця \"" << targetArtist << "\":\n";
    for (const Track& t : tracks) {
        if (t.artist == targetArtist) {
            cout << t.title << " (" << t.duration << " сек, " << t.releaseYear << " р.)\n";
        }
    }

    // 4. Видалення за умовою: видалити треки, коротші за 90 сек (за допомогою ітераторів)
    list<Track>::iterator it = tracks.begin();
    while (it != tracks.end()) {
        if (it->duration < 90) {
            it = tracks.erase(it);
        } else {
            it++;
        }
    }

    cout << "\nПісля видалення треків, коротших за 90 сек:\n";
    printTracks(tracks);

    // 5. Сортування за тривалістю зростанням методом sort
    tracks.sort([](const Track& a, const Track& b) {
        return a.duration < b.duration;
    });

    cout << "\nПісля сортування за тривалістю зростанням:\n";
    printTracks(tracks);

    return 0;
}