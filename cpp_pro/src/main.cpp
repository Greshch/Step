#include <iostream>
#include <time.h>
using namespace std;
///////////////////////////////////////////
struct Threebits {
    size_t f;
    size_t s;
    size_t t;
};

int const SIMPLE_PAY = 250;

bool isWin(Threebits const& threebits);

bool isDefeat(int credits);

void displayBandit(Threebits const& threebits);

void evaluate(Threebits threebits, int &pInt);

void currentPay(int &credits);

void displayCredit(int const &credits);

////////////////////////////////////////////////

void printDigits(size_t n, size_t exp);

////////////////////////////////////////////////

struct Monster {
    int hp;
    int damage;
};

struct Pickman : public Monster {

};

struct Dragon : public Monster {

};

bool isAlive(Monster const &dragon);

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    //1
    // star's line output
    /*cout << "stars in line: " ;
    size_t stars = 0;
    cin >> stars;
    for (size_t i = 0; i < stars; ++i) {
        cout << "*";
    }   cout << endl;*/

    //2
    // event nums output from 1 to 100
    /*int const FROM = 2;
    int const TO = 100;
    for (int i = FROM; i <= TO; i += 2) {
        cout << i << " " ;
        if (0 == i % 50) { cout << endl; }
    } cout << endl;*/

    //3
    // sum from M to N;
    /*int M, N, sum = 0;
    cout << "N,M: ";
    cin >> N >> M;
    for (int i = N; i <= M; ++i) {
        sum += i;
    }
    cout << "sum: " << sum << endl;*/

    //4
    // From Celcium to Farengeit
    /*int from, to;
    cout << "FROM ... TO: ";
    cin >> from >> to;
    cout << "================================\n";
    cout << "|    Celcium    |   Farengeit   |\n";
    for (int i = from; i < to; ++i) {
        cout << "|\t" << i << "\t|\t" << (9.0 / 5.0) * i + 32 << "\t|\n";
    }
    cout << "================================\n";*/

    //5
    //Factorial n
    /*int N = 0;
    cout << "N: " ;
    cin >> N;
    long int F = 1;
    for (int i = 2; i <= N; ++i) {
        F *= i;
    }
    cout << N << "! = " << F << endl;*/

    //6
    // length and sum of num(N)
    /*long long N = 0l;
    cout << "N: " ;
    cin >> N;
    long long tmp = N;
    int size = 0;
    int sum = 0;
    while (tmp) {
        int current = tmp % 10;
        sum += current;
        size++;
        tmp /= 10;
    }
    cout << "size: " << size << endl;
    cout << "sum: " << sum << endl;*/

    //7
    //Reverse nums (123 -> 321)
    /*long long N = 0L;
    cout << "N: " ;
    cin >> N;
    long long tmp = N;
    long long R = 0;
    int n = 1;

    while (tmp) {
        n *= 10;
        tmp /= 10;
    }
    tmp = N;
    while (n) {
        int current = tmp % 10;
        n /= 10;
        R += current * n;
        tmp /= 10;
    }
    cout << N << " -> " << R << endl;*/

    //8
    //mod from 1 to N
    /*int N = 0;
    cout << "N: ";
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        if (N % i == 0) {
            cout << i << " ";
        }
    } cout << endl;*/

    //9
    //Simple N
    /*int N = 0;
    cout << "N: ";
    cin >> N;
    bool isNSimple = true;
    for (int i = 2; i <= N/2 && isNSimple; ++i) {
        if (0 == N % i) {
            isNSimple = false;
        }
    }
    cout << "N -> simple: " << isNSimple << endl;*/

    //10 Does the num have two digits
    /*int N = 0;
    cout << "N: ";
    cin >> N;
    int tmp = N;
    int prev = -1;
    int cur;
    bool flag = false;
    while (tmp && !flag) {
        if (tmp != N) {
            prev = cur;
        }
        cur = tmp % 10;
        if (prev == cur && tmp != N) {
            flag = true;
        }
        tmp /= 10;
    }
    if (flag) {
        cout << "В этом числе две цифпы подряд одинаковы!" << endl;
    }*/

    //11
    // ordered digits in num
    /*int N;
    cout << "N: " ;
    cin >> N;
    int tmp = N;
    int cur;
    int prev = -1;
    bool flag = true;
    while (tmp && flag) {
        if (tmp != N) {
            prev = cur;
        }
        cur = tmp % 10;
        if (prev < cur && tmp != N) {
            cout << "unordered digits\n" ;
            flag = false;
        }
        tmp /= 10;
    }*/

    //12
    //CPU try to guess a number from 1 to 1000
    /*size_t const LEFT = 1;
    size_t const RIGHT = 1000;
    size_t secret = rand() % (RIGHT - LEFT) + LEFT;
    bool flag = false;
    const int TRIES = 10;
    size_t left = LEFT;
    size_t right = RIGHT;
    for (size_t i = 0; !flag && i < TRIES; ++i) {
        size_t midle = (left + right) / 2;
        cout << i + 1 << ": " << midle << "\t";
        if (midle == secret) {
            cout << "\nYou have just guess number. Congratulations!!!\n" ;
            flag = true;
        }
        else if (midle < secret) {
            cout << "My number is graiter then this one\n";
            left = midle + 1;
        } else {
            cout << "My number is less then this one\n";
            right = midle - 1;
        }
    }*/

    //13
    //Lucky's tickets output
    /*size_t const LEFT =  100000;
    size_t const RIGHT = 999999;

    for (size_t i = LEFT, cnt = 0; i <= RIGHT; ++i) {
        size_t l_sum = 0;
        size_t r_sum = 0;
        size_t tmp = i;
        for (int j = 0; j < 6; ++j, tmp /= 10) {
            size_t cur = tmp % 10;
            if (j < 3) {
                l_sum += cur;
            }
            else {
                r_sum += cur;
            }
        }
        if (l_sum == r_sum) {
            cnt++;
            if (cnt && cnt % 10 == 0) cout << endl;
            cout << i << " " ;
        }
    }
    cout << endl;*/

    //14
    //12345
    /*long long const LEFT =  10000000;
    long long const RIGHT = 99999999;
    long long delim = 12345;
    long long cnt = 0;
    for (long long i = LEFT; i <= RIGHT; ++i) {
        if (0 == i % delim) {
            cout << i << endl;
            ++cnt;
        }
    }
    cout << "\tcnt: " << cnt << endl;*/

    //15
    // bynary oct hex
    /*size_t const BYNARY = 2;
    size_t const OCT = 8;
    size_t const HEX = 16;
    size_t num;
    cout << "num: ";
    cin >> num;
    cout << num << "\t";
    printDigits(num, BYNARY);
    cout << "\t";
    printDigits(num, OCT);
    cout << "\t0x";
    printDigits(num, HEX);
    cout << endl;*/

    //16
    /*Реализовать игровую программу «Однорукий бандит»*/

    /*int const SZ = 8;
    int credits = 5000;
    Threebits bandyt;
    bool flagWin = false;
     do {
        bandyt.f = rand() % SZ;
        bandyt.s = rand() % SZ;
        bandyt.t = rand() % SZ;
        evaluate(bandyt, credits);
        displayBandit(bandyt);
        currentPay(credits);
        displayCredit(credits);
        flagWin = isWin(bandyt);
    } while (!flagWin && !isDefeat(credits));
    if (flagWin) {
        cout << "Congratulation!! You won jackpot!!)))\n";
    }
    else {
        cout << "GAME OVER!\n";
    }*/

    Dragon Smaug;
    Pickman pickman;
    int pickmans = 0;
    cout << "Input dragons(hitpoint, demage): " ;
    cin >> Smaug.hp >> Smaug.damage;

    cout << "Input pickman(hitpoint, demage): " ;
    cin >> pickman.hp >> pickman.damage;

    cout << "how many pickmans you can by: ";
    cin >> pickmans;

    while (true) {
        int pickmans_total_dmg = pickmans * pickman.damage;
        int pickmans_total_hp = pickmans * pickman.hp;
        Smaug.hp -= pickmans_total_dmg;
        cout << "Копейщики атакуют(" << "урон "  << pickmans_total_dmg << ")"
             << " - у дракона осталось " << Smaug.hp << " очков здоровья.\n";
        if (!isAlive(Smaug)) {
            cout << "Копейщики побеждают!!\n ";
            break;
        }

        pickmans_total_hp -= Smaug.damage;
        if (pickmans_total_hp <= 0) {
            cout << "Дракон побеждает.\n" ;
            break;
        }
        pickmans = pickmans_total_hp / pickman.hp;
        int injured = pickmans_total_hp % pickman.hp;
        if (injured) {
            ++pickmans;
        }

        if (pickmans == 0) {
            cout << "Дракон побеждает.\n" ;
            break;
        }
        cout << "Дракон атакует (урон " << Smaug.damage << ") – осталось "
             << pickmans;
        if (injured) {
            cout << " копейщиков один из которых ранен (осталось " << injured << " очков здоровья).";
        }
        else {
            cout << " копейщиков.";
        }
        cout << endl;
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////

bool isAlive(Monster const &obj) {
    return obj.hp > 0;
}

////////////////////////////////////////////////////////////////////////

void printDigits(size_t n, size_t exp) {
    if (n == 0) {
        return;
    }
    //cout << n % exp;
    printDigits(n / exp, exp);
    //cout << n % exp;
    size_t cur = n % exp;
    if (cur < 10) {
        cout << cur;
    }
    else {
        cout << (char) ('A' + cur - 10);
    }
}

///////////////////////////////////////////////////////////////////

void displayCredit(int const &credits) {
    cout << "Total credits: " << credits << endl;
}

void currentPay(int &credits) {
    credits -= SIMPLE_PAY;
}

void evaluate(Threebits threebits, int & pInt) {
    //pInt -= 100;
    if (threebits.f == 0 && threebits.s == 0 && threebits.t == 0) {
        pInt += 100;
    }
    else if (threebits.f == 1 && threebits.s == 1 && threebits.t == 1) {
        pInt += 150;
    }
    else if (threebits.f == 2 && threebits.s == 2 && threebits.t == 2) {
        pInt += 200;
    }
    else if (threebits.f == 3 && threebits.s == 3 && threebits.t == 3) {
        pInt += 250;
    }
    else if (threebits.f == 4 && threebits.s == 4 && threebits.t == 4) {
        pInt += 300;
    }
    else if (threebits.f == 5 && threebits.s == 5 && threebits.t == 5) {
        pInt += 250;
    }
    else if (threebits.f == 7 && threebits.s == 7 && threebits.t == 7) {
        pInt += 0;
    }
    else if (threebits.f == 7 && threebits.s == 7) {
        pInt += 50;
    }
    else if (threebits.f == 7) {
        pInt += 25;
    }
    else if (threebits.f == 5 && threebits.s == 5) {
        pInt += 50;
    }
    else if (threebits.f == 5) {
        pInt += 25;
    }
    else if (threebits.f == 6 && threebits.s == 6 && threebits.t == 6) {
        pInt -= 1000;
    }
}

void displayBandit(Threebits const& threebits) {
    cout << "\t" << threebits.f << " : " << threebits.s
        << " : " << threebits.t << endl;
}

bool isDefeat(int credits) {
    //cout << "#credits : " << credits << endl;
    return credits <= 0;
}

bool isWin(Threebits const& threebits) {
    return threebits.f == 7 && threebits.s == 7 && threebits.t == 7;
}

/////////////////////////////////////////////////////////////////