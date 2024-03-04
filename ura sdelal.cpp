#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
#include <Windows.h>



int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0, "");

    string slovo;
    int deistvie;

    cout << "Введите слово: ";
    cin >> slovo;
    cout << "Выберите действие:\n1. Слово задом наперед\n2. Вывести слово без гласных\n3. Вывести слово без согласных\n4. Рандомно раскидать буквы в слове\n5. Выйти\n";
    cin >> deistvie;
    string izm = slovo;
    char glasn[] = { 'А','а','О','о','У','у','Е','е','Я','я','Э','э','И','и','Ю','ю','Ё','ё','Ы','ы' };
    char soglasn[] = { 'Й','й','Ц','ц','К','к','Н','н','Г','г','Ш','ш','Щ','щ','З','з','Х','х','Ф','ф','В','в','П','п','Р','р','Л','л','Д','д',
        'Ж','ж','Ч','ч','М','м','С','с','Т','т','Б','б','Ь','ь' };

    switch (deistvie)
    {
    case (1): {
        reverse(izm.begin(), izm.end());
        cout << izm << endl;
        return 0;
    }
    case (2): {
        string result = slovo;
        result.erase(remove_if(result.begin(), result.end(), [&glasn](char c) {
            return find(begin(glasn), end(glasn), c) != end(glasn);
            }), result.end());
        cout << result << endl;
        break;
    }
    case (3): {
        string result = slovo;
        result.erase(remove_if(result.begin(), result.end(), [&soglasn](char c) {
            return find(begin(soglasn), end(soglasn), c) != end(soglasn);
            }), result.end());
        cout << result;
        break;
    }
    case (4): {
        string shuffled = slovo;
        random_shuffle(shuffled.begin(), shuffled.end());
        cout << shuffled;
        break;
    }
    case (5):
    {
        break;
    }
    }
    return 0;
}
