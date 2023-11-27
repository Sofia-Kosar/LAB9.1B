#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

enum Major { KI, INF, MATH, PHYSICS, ART };
string majorStr[] = { "Комп’ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика", "Трудове навчання" };

struct Student
{
    string prizv;
    unsigned int kurs;
    Major major;
    union
    {
        int program;
        int nummeth;
        int pedagog;
    };
    int physics;
    int math;
    int IT;
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void CountGoodGrades(Student* p, const int N);
double CalculatePercentGoodPhysicsMath(Student* p, const int N);

int main()
{

    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    int N;
    cout << "Введіть N: "; cin >> N;

    Student* p = new Student[N];
    Create(p, N);
    Print(p, N);
    CountGoodGrades(p, N);

    double percent = CalculatePercentGoodPhysicsMath(p, N);
    cout << "Процент студентів, які отримали '5' і з фізики і з математики: " << fixed << setprecision(2) << percent << "%" << endl;

    delete[] p;
    return 0;
}

void Create(Student* p, const int N)
{
    int major;

    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
        cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

        cout << " прізвище: "; getline(cin, p[i].prizv);
        cout << " курс: "; cin >> p[i].kurs;
        cout << " спеціальність (0 - Комп’ютерні науки, 1 -Інформатика , 2 -Математика та економіка , 3 -Фізика та інформатика, 4 -Трудове навчання): ";
        cin >> major;
        p[i].major = static_cast<Major>(major);
        p[i].major = (Major)major;
        cout << " фізика "; cin >> p[i].physics;
        cout << " математика "; cin >> p[i].math;
        switch (p[i].major)
        {
        case KI:
            cout << " програмування : "; cin >> p[i].program;
            break;
        case INF:
            cout << " чисельні методи : "; cin >> p[i].nummeth;
            break;
        case MATH:
            cout << " педагогіка : "; cin >> p[i].pedagog;
            break;
        case PHYSICS:
            cout << " педагогіка : "; cin >> p[i].pedagog;
            break;
        case ART:
            cout << " педагогіка : "; cin >> p[i].pedagog;
            break;
        }
        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << "========================================================================================================================"
        << endl;
    cout << "|  № |   Прізвище   | Курс | Спеціальність          | Фізика | Математика | Програмування | Чисельні методи | Педагогіка"
        << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout << "| " << setw(13) << left << p[i].prizv
            << "| " << setw(4) << right << p[i].kurs << " "
            << "| " << setw(23) << left << majorStr[p[i].major];
        cout << "| " << setw(7) << right << p[i].physics
            << "| " << setw(11) << right << p[i].math;
        switch (p[i].major)
        {
        case KI:
            cout << "| " << setw(14) << right << p[i].program << "| " << setw(17) << "|" << setw(11) << "|" << endl;
            break;
        case INF:
            cout << "| " << setw(15) << "|" << setw(17) << right << p[i].nummeth << "| " << setw(10) << "|" <<  endl;
            break;
        case MATH:
            cout << "| " << setw(15) << "|" << setw(18) << "|" << setw(10) << right << p[i].pedagog << "| ";
            break;
        case PHYSICS:
            cout << "| " << setw(15) << "|" << setw(18) << "|" << setw(10) << right << p[i].pedagog << "| ";
            break;
        case ART:
            cout << "| " << setw(15) << "|" << setw(18) << "|" << setw(10) << right << p[i].pedagog << "| ";
            break;
        }
        cout << endl;
    }
    cout << "========================================================================================================================"
        << endl;
    cout << endl;
}

void CountGoodGrades(Student* p, const int N)
{
    int countPhysics = 0;
    int countMath = 0;
    int countProgram = 0;
    int countNummeth = 0;
    int countPedagog = 0;

    for (int i = 0; i < N; i++)
    {
        if (p[i].physics == 4) {
            countPhysics++;
        }

        if (p[i].math == 4) {
            countMath++;
        }

        if (p[i].program == 4) {
            countProgram++;
        }
        if (p[i].nummeth == 4) {
            countNummeth++;
        }
        if (p[i].pedagog == 4) {
            countPedagog++;
        }
    }

    cout << "=============================================================================================================" << endl;
    cout << "Кількість оцінок 'Добре' з кожного предмету:" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Фізика: " << countPhysics << " | Математика: " << countMath << " | Програмування: " << countProgram << " | Чисельні методи: " << countNummeth << " | Педагогіка: " << countPedagog << endl;
    cout << "=============================================================================================================" << endl;
}

double CalculatePercentGoodPhysicsMath(Student* p, const int N)
{
    int k = 0;

    for (int i = 0; i < N; i++)
    {
        if (p[i].physics == 5 && p[i].math == 5) {
            k++;
        }
    }

    return 100.0 * k / N;
}
