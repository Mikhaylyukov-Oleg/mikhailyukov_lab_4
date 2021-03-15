#include <iostream>
#include <cmath>
#define elements_count 200
using namespace std;

double get_number_with_absolute_value_less_than_1();
double get_number();
double calculate_ln_of_1_plus_x(double x);

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "Введите число, по модулю меньшее единицы: ";
    const double x = get_number_with_absolute_value_less_than_1();

    const double ln_of_1_plus_x = calculate_ln_of_1_plus_x(x);

    cout << "ln(1 + " << x << ") = " << ln_of_1_plus_x;

    return 0;
}

double get_number_with_absolute_value_less_than_1()
{
    double res = 0;
    do {
        res = get_number();
        if (res >= 1) {
            cout << "Ошибка: число должно быть меньше, чем 1\n";
            cout << "Введите данные снова: ";
        }
        if (res <= -1) {
            cout << "Ошибка: число должно быть больше, чем -1\n";
            cout << "Введите данные снова: ";
        }
    } while ((res >= 1) || (res <= -1));
    return res;
}

double get_number()
{
    while (true)
    {
        double number;
        cin >> number;
        if (cin.fail())
        {
            cout << "Ошибка: вы ввели не число\n";
            cout << "Введите данные снова: ";
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else {
            cin.ignore(32767, '\n');
            return number;
        }
    }
}

double calculate_ln_of_1_plus_x(double x)
{
    double sum = 0;
    for (int n = 0; n <= elements_count; n++) {
        sum += (pow(-1, n) * pow(x, 2 * n + 1)) / (2 * n + 1);
    }
    return sum;

}