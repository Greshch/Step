#include <iostream>
#include <time.h>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

size_t GetSize(size_t i);
size_t GetSumArmstrong(size_t i, size_t sz);

bool IsSimple( size_t n);
size_t GetSumPerfect(size_t n);

int month_days[13] = {
        0,
        31, 28,
        31,30,31,
        30,31,31,
        30,31,30,
        31
};
std::string month_names[13] {
    "",
    "January", "February",
    "March", "April", "May",
    "June", "July", "August",
    "September", "October", "November",
    "December"

};

int GetDaysFromMonth(int month, int year);

bool IsLeapYear(int year);

struct struct_date
{
    char day;
    char month;
    short year;
};

int what_day(struct struct_date const& date);

void PrintMonth(int month, int year);

bool IsFourIncludes(int n);

bool IsThirteenIncludes(int n);


void PrintDigit(int n);


int main() {
    //1
    /*srand(time(0));
    int const LEFT_BOUND = -100;
    int const RIGHT_BOUND = 100;
    int const CNT = 100;
    int plus = 0;
    int minus = 0;
    int zero = 0;
    int odd = 0;
    int event = 0;
    for (int i = 0; i < CNT; ++i) {
        int curent = LEFT_BOUND + rand() % (RIGHT_BOUND - LEFT_BOUND + 1);\
        if (curent > 0) plus++;
        else if (curent < 0) minus++;
        else zero++;

        if (0 == curent % 2)    event++;
        else    odd++;
    }
    cout << " > 0 -> " <<  1.0 * plus / CNT * 100  << "%" << endl;
    cout << " < 0 -> " <<  1.0 * minus / CNT * 100  << "%" << endl;
    cout << "   0 -> " <<  1.0 * zero / CNT * 100  << "%" << endl;
    cout << " event -> " <<  1.0 * event / CNT * 100  << "%" << endl;
    cout << " odd -> " <<  1.0 * odd / CNT * 100  << "%" << endl;*/

    //2
    /*int const LEFT = 1;
    int const RIGHT = 10;
    for (int i = LEFT; i <= RIGHT; ++i) {
        for (int j = LEFT; j <= RIGHT; ++j) {
            cout << i * j;
            cout << "\t";
        }
        cout << endl;
    }*/

    //3
    /*double N, M;
    double const inf = 0.03;
    int MONTHES = 10;
    double need_sum = 0;
    cout << "Stipendia: ";
    cin >> N;
    cout << "Need for first month: ";
    cin >> M;
    for (int i = 0; i < MONTHES; ++i) {
        need_sum += M - N;
        M += M * inf;
    }
    cout << "Give me: " << need_sum << " hrn" << endl;*/

    //4
    /*cout << "Rows: ";
    int N;
    cin >> N;
    cout << "Cols: ";
    int M;
    cin >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
            cout << " ";
        }
        cout << endl;
    }*/

    //5
//    int h;
//    cout << "h: ";
//    cin >> h;
//    int space = (2 * h - 1) / 2 + 1;
//    for (int i = 1; i <= h; ++i, --space) {
//        for (int j = 0; j < space; ++j) {
//            cout << " ";
//        }
//        int len = 2 * i - 1;
//        for (int k = 0; k < len; ++k) {
//            cout << ((k == 0 || k == len - 1 || i == h) ? "*" : " ");
//        }
//
//        cout << endl;
//    }

    //6
//    int h;
//    cout << "h: ";
//    cin >> h;
//    int len;
//    int space = (2 * h - 1) / 2 + 1;
//    for (int i = 1; i <= h; ++i, --space) {
//        for (int j = 0; j < space; ++j) {
//            cout << " ";
//        }
//        len = 2 * i - 1;
//        for (int k = 0; k < len; ++k) {
//            cout << ((k == 0 || k == len - 1) ? "*" : " ");
//        }
//        cout << endl;
//    }
//    space = 2;
//    for (int i = 1; i < h; ++i, ++space) {
//        for (int j = 0; j < space; ++j) {
//            cout << " ";
//        }
//
//        for (int k = (len - 2 * i); k > 0; --k) {
//            cout << ((k == len - 2*i || k == 1) ? "*" : " ");
//        }
//        cout << endl;
//    }

    //7
//    int N;
//    cout << "N: ";
//    cin >> N;
//    int copyN = N;
//    bool  palindrome = true;
//    int exp = 1;
//    while  (copyN > 10) {
//        exp *= 10;
//        copyN /= 10;
//    }
//
//    copyN = N;
//    int rest = N;
//    while (copyN) {
//        int left = rest / exp;
//        int right = copyN % 10;
//        if (left != right) {
//            //cout << left << "\t" << right << endl;
//            palindrome = false;
//        }
//        rest %= exp;
//        exp /= 10;
//        copyN /= 10;
//    }
//    cout << N << (palindrome ? " is palindrome" : "");
//    cout << endl;

//9
    /*int A, B, C;
    cout << "Input sizes of paralelepiped(axbxc): ";
    cin >> A >> B >> C;
    if (C < B) {
        int tmp = C;
        C = B;
        B = tmp;
    }
    int const left_front = 1;
    int const left_back = left_front + B - 1;
    int const right_front = left_front + A - 1;
    int const right_back= left_back + A - 1;
    int const right_back_botom = C - B - 1;
    char const brush = '*';
    char const space = '.';


    // draw top frame with top of right back altitude
    for (int i = 0; i < B; ++i) {
        for (int j = 0; j <= right_back; ++j) {
            if (j == right_back) {
                cout << brush;
            }

            else if (j >= left_back - i && j <= right_back - i) {
                cout << brush;
            }
            else {
                cout << space;
            }
        }
        cout << endl;
    }
    // draw front projection and bottom of right back altitude
    for (int i = 0; i < C - 1; ++i) {
        for (int j = 0; j <= right_back; ++j) {
            if (j == right_back) {
                if (i <= right_back_botom)
                    cout << brush;
            }

            else if (j >= left_front && j <= right_front) {
                cout << brush;
            }

            else {
                cout << space;
            }
        }
        cout << endl;
    }*/

    //10
    /*size_t LEFT = 2;
    size_t RIGHT = 10000000;
    for (size_t i = LEFT; i < RIGHT; ++i) {
        size_t midle = i / 2;
        bool simple = true;
        for (size_t j = LEFT; j <=  midle; ++j) {
            if (0 == i % j) {
                simple = false;
                break;
            }
        }
        if (simple) {
            cout << i << " ";
        }
    }
    cout << endl;*/

    //11
    /*size_t const LEFT = 1;
    size_t const RIGHT = 10000000;
    for (size_t i = LEFT; i <= RIGHT; ++i) {
        size_t sz = GetSize(i);
        if (GetSumArmstrong(i, sz) == i) {
            cout << i << endl;
        }
    }*/

    //12
    /*size_t const LEFT = 1;
    size_t const RIGHT = 10000000;
    size_t sum = 0;
    for (size_t i = LEFT; sum < RIGHT; i++) {
        sum += pow (2 * i - 1, 3.);
        if (i == 1 ) {
            cout << 6 << endl;
        }
        else if (GetSumPerfect(sum) == sum) {
            cout << sum << endl;
        }
    }*/

    //13
    /*size_t const RIGHT = 10000000;
    size_t a = 1;
    size_t b = 1;
    size_t c = 1;
    while (a < RIGHT) {
        c = a + b;
        cout << a << endl;
        a = b;
        b = c;

    }*/

    //14
    /*cout << "Year: ";
    int year;
    cin >> year;
    for (int i = 1; i <= 12; ++i) {
        PrintMonth(i, year);
        cout << endl << endl;
    }*/

    //15
    /*int stairsLength;
    int stairs;
    cout << "Input length of stairs: ";
    cin >> stairsLength;
    cout << "how many stairs: ";
    cin >> stairs;
    cout << endl;
    for (int i = 0; i < stairs; ++i) {
        for (int k = 0; k < 2*i; ++k) {
            cout << " ";
        }
        for (int j = 0; j < stairsLength; ++j) {
            cout << "*";
        }
        cout << endl;
    }*/

    //16
    /*int const LENHGTH = 3;
    int stairs;
    cout << "stairs: ";
    cin >> stairs;
    for (int i = 0; i < stairs; ++i) {
        for (int k = 0; k < i*LENHGTH - 1; ++k) {
            cout << " ";
        }
        for (int j = 0; j < LENHGTH; ++j) {
            cout << "*";
        }
        cout << endl;
        for (int k = 0;
        k < i*LENHGTH - 1 + LENHGTH - (i > 0) ? 1 : 0;
        ++k) {
            cout << " ";
        }
        cout << "*";
        cout << endl;

    }*/

    //17
    // int const SIZE = 11;
    // //17.1
    // for (int i = 0; i < SIZE; ++i) {
    //     for (int j = 0; j < SIZE; ++j) {
    //         if (i == 0 || j == 0 || j == SIZE - 1 || i == SIZE - 1
    //         || i == j
    //         ) {
    //             cout << "*";
    //         } else {
    //             cout << " ";
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // // 17.2
    // for (int i = 0; i < SIZE; ++i) {
    //     for (int j = 0; j < SIZE; ++j) {
    //         if (i == 0 || j == 0 || j == SIZE - 1 || i == SIZE - 1
    //             || i + j == SIZE - 1
    //                 ) {
    //             cout << "*";
    //         } else {
    //             cout << " ";
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // //17.3
    // for (int i = 0; i < SIZE; ++i) {
    //     for (int j = 0; j < SIZE; ++j) {
    //         if (i == 0 || j == 0 || j == SIZE - 1 || i == SIZE - 1
    //             || j == SIZE / 2
    //                 ) {
    //             cout << "*";
    //         } else {
    //             cout << " ";
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // // 17.4
    // for (int i = 0; i < SIZE; ++i) {
    //     for (int j = 0; j < SIZE; ++j) {
    //         if (i == 0 || j == 0 || j == SIZE - 1 || i == SIZE - 1
    //             || i == SIZE / 2
    //                 ) {
    //             cout << "*";
    //         } else {
    //             cout << " ";
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // //17.5
    // for (int i = 0; i < SIZE; ++i) {
    //     for (int j = 0; j < SIZE; ++j) {
    //         if (i == j ||
    //                 (i <= SIZE / 2 && j == 0) ||
    //                 (i == 0 && j <= SIZE / 2) ||
    //                 (i >= SIZE / 2 && j == SIZE - 1) ||
    //                 (i == SIZE - 1 && j >= SIZE / 2)
    //                 ) {
    //             cout << "*";
    //         } else {
    //             cout << " ";
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // //17.6
    // for (int i = 0; i < SIZE; ++i) {
    //     for (int j = 0; j < SIZE; ++j) {
    //         if (i+ j == SIZE - 1 ||
    //             (i <= SIZE / 2 && j == SIZE - 1) ||
    //             (i == 0 && j >= SIZE / 2) ||
    //             (i >= SIZE / 2 && j == 0) ||
    //             (i == SIZE - 1 && j <= SIZE / 2)
    //                 ) {
    //             cout << "*";
    //         } else {
    //             cout << " ";
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // //17.7
    // for (int i = 0; i < SIZE; ++i) {
    //     for (int j = 0; j < SIZE; ++j) {
    //         if (i == 0 || j == 0 || j == SIZE - 1 || i == SIZE - 1
    //             || i == j
    //             || i + j == SIZE - 1
    //                 ) {
    //             cout << "*";
    //         } else {
    //             cout << " ";
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // //17.8
    // for (int i = 0; i < SIZE; ++i) {
    //     for (int j = 0; j < SIZE; ++j) {
    //         if (j == 0 || j == SIZE - 1
    //             || i == j
    //             || i + j == SIZE - 1
    //                 ) {
    //             cout << "*";
    //         } else {
    //             cout << " ";
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // //17.9
    // for (int i = 0; i < SIZE; ++i) {
    //     for (int j = 0; j < SIZE; ++j) {
    //         if (i == 0  || i == SIZE - 1
    //             || i == j
    //             || i + j == SIZE - 1
    //                 ) {
    //             cout << "*";
    //         } else {
    //             cout << " ";
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // //17.10
    // for (int i = 0; i < SIZE; ++i) {
    //     for (int j = 0; j < SIZE; ++j) {
    //         if (i == 0 || j == 0 || j == SIZE - 1 || i == SIZE - 1
    //             || i == SIZE / 2
    //             || j == SIZE / 2
    //                 ) {
    //             cout << "*";
    //         } else {
    //             cout << " ";
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // //17.11
    // for (int i = 0; i < SIZE; ++i) {
    //     for (int j = 0; j < SIZE; ++j) {
    //         if ( ((i == 0 || i == SIZE / 2) && (j > 0 && j < SIZE /2))
    //             || ((i > 0 && i < SIZE / 2) && (j == 0 || j == SIZE /2))
    //             || ((i == SIZE / 2  || i == SIZE - 1) && (j > SIZE / 2 && j < SIZE - 1))
    //             || ((i > SIZE / 2  && i < SIZE - 1 ) && (j == SIZE / 2 || j == SIZE - 1 ))
    //                 ) {
    //             cout << "*";
    //         } else {
    //             cout << " ";
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // //17.12
    // for (int i = 0; i < SIZE; ++i) {
    //     for (int j = 0; j < SIZE; ++j) {
    //         if ( ((i == 0 || i == SIZE / 2) && (j > SIZE / 2 && j < SIZE - 1))
    //              || ((i > 0 && i < SIZE / 2) && (j == SIZE / 2 || j == SIZE - 1))
    //              || ((i == SIZE / 2  || i == SIZE - 1) && (j > 0 && j < SIZE / 2))
    //              || ((i > SIZE / 2  && i < SIZE - 1 ) && (j == 0 || j == SIZE / 2))
    //                 ) {
    //             cout << "*";
    //         } else {
    //             cout << " ";
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    //18

    // double h;
    // cout << "H(>= 20): ";
    // cin >> h;

    // int length = 2 * round(h / 3) - 1;
    // int h_roof = round(h / 3);
    // int top_roof = round(h / 3);
    // int thick_roof = round (h / 8);
    // for (int i = 0; i <  h_roof; ++i) {
    //     for (int j = 0; j < length; ++j) {
    //         if (
    //         (i + j == top_roof - 1) ||
    //         (i + top_roof - 1 == j) ||
    //         i == h_roof - 1 ||
    //         ((i == 0 && (j > length / 2 && j < length / 2 + thick_roof))) ||
    //         ((i > 0 && i < thick_roof) && (j == length / 2 + thick_roof - 1))
    //         ) {
    //             cout << "*";
    //         }
    //         else {
    //             cout << " ";
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    // 
    // int h_botom = round(h * 1.25 / 3);
    // int h_win = h_botom / 2;
    // int thick_win = length / 4;
    // int thick_dor = thick_win;
    // for (int i = 0; i < h_botom; ++i) {
    //     for (int j = 0; j < length; ++j) {
    //         if (
    //         j == 0 ||
    //         j == length - 1 ||
    //         i == h_botom - 1 ||
    //         ((i == h_botom / 6) && (j >= h_botom / 6 && j <= h_botom / 6 + thick_win)) ||
    //         ((i == h_botom / 6 + h_win) && (j >= h_botom / 6 && j <= h_botom / 6 + thick_win)) ||
    //         ((i > h_botom / 6 && i < h_botom / 6 + h_win) && (j == h_botom / 6)) ||
    //         ((i > h_botom / 6 && i < h_botom / 6 + h_win) && (j == h_botom / 6 + thick_win)) ||
    //         ((i == h_botom / 6) && (j < length - h_botom / 6 && j >= length - h_botom / 6 - thick_dor)) ||
    //         ((i == h_botom - 2) && (j < length - h_botom / 6 && j >= length - h_botom / 6 - thick_dor)) ||
    //         ((i > h_botom / 6 && i < h_botom - 2) && (j == length - h_botom / 6 - thick_dor)) ||
    //         ((i > h_botom / 6 && i < h_botom - 2) && (j == length - h_botom / 6 - 1))
    //         ) {
    //             cout << "*";
    //         }
    //         else {
    //             cout << " ";
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }

    //19
    // int rows, h;
    // cout << "Rows, H: ";
    // cin >> rows >> h;
    // cout << endl;
    // int const spaces = 40;
    // int const thick = 2;
    // for (int i = 0; i < rows; ++i) {
    //     for (int j = 0; j < h; ++j) {
    //         for (int k = 0; k < spaces; ++k) {
    //             if (k < spaces / 2 - j - i) {
    //                 cout << "  ";
    //             } 
    //             else if (k <= spaces / 2 + j + i) {
    //                 cout << "<>";
    //             }
    //         }
    //         cout << endl;
    //     }
    // }
    // for (int i = 0; i < 4; ++i) {
    //     for (int j = 0; j < spaces; ++j) {
    //         if (
    //             j >= spaces / 2 - thick / 2 &&
    //             j <= spaces / 2 + thick / 2
    //             ) {
    //                 cout << "<>";
    //             }
    //             else {
    //                 cout << "  ";
    //             }
    //     }
    //     cout << endl;
    // }

    //20

    // cout << "Day : Month : Year : ";
    // int day, month, year;
    // cin >> day >> month >> year;
    // int week_day = what_day({(char)day,(char) month, (short)year});
    // switch (week_day) {
    //     case 0:
    //         cout << "Sunday";
    //         break;

    //     case 1:
    //         cout << "Monday";
    //         break;

    //     case 2:
    //         cout << "Tuesday";
    //         break;  

    //     case 3:
    //         cout << "Wensday";
    //         break;

    //     case 4:
    //         cout << "Thursnday";
    //         break;

    //     case 5:
    //         cout << "Friday";
    //         break;

    //     case 6:
    //         cout << "Saturday";
    //         break;

    //     default:
    //         cout << "???";
    //         break;
    // }
    // cout << endl;

    //21

    // int const LEFT = 1;
    // int const RIGHT = 100000;
    // int cnt = 0;
    // for (int i = LEFT; i < RIGHT; ++i) {
    //     if (IsThirteenIncludes(i) || IsFourIncludes(i)) {
    //         cout << i << " ";
    //         cnt++;
    //         if (cnt % 10 == 0) {
    //             cnt = 0;
    //             cout << endl;
    //         }
    //     }
    // }

    stack<int> decimals;
    int n;
    cout << "n: ";
    cin >> n;
    while (n) {
        decimals.push(n % 10);
        n /= 10;
    }

    while (!decimals.empty()) {
        int tmp = decimals.top();
        PrintDigit(tmp);
        decimals.pop();
    }

    cout << endl;
    
    return 0;
}

size_t GetSumArmstrong(size_t n, size_t sz) {
    size_t sum = 0;
    while (n) {
        sum += pow( n % 10, sz);
        n /= 10;
    }
    return sum;
}

size_t GetSize(size_t i) {
    size_t sz = 0;
    while (i) {
        i /= 10;
        sz++;
    }
    return sz;
}

bool IsSimple(size_t n) {
    for (size_t i = 2; i  <=  n / 2; ++i ) {
        if (0 == n % i) return false;
    }
    return true;
}

size_t GetSumPerfect(size_t n) {
    size_t sum = 1;
    for (size_t i = 2; i < n; ++i) {
        if (0 == n % i) {
            sum += i;
        }
    }
    return sum;
}

int what_day(struct struct_date const& date)
{
    int a = (14 - date.month) / 12;
    int y = date.year - a;
    int m = date.month + 12 * a - 2;
    return (7000 + (date.day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7;
}

bool IsLeapYear(int year) {
    if (year % 4) {
        return false;
    } else {
        if (year % 100) {
            return true;
        }
        else {
            if (year % 400) {
                return false;
            }
            else {
                return true;
            }
        }
    }
}

int GetDaysFromMonth(int month, int year) {
    if (month != 1 ) {
        return month_days[month];
    }
    else  if (!IsLeapYear(year)){
        return month_days[month];
    }
    else {
        return month_days[month] + 1;
    }
}

void PrintMonth(int month, int year) {
    cout << "\t\t" << month_names[month] << endl << endl;
    struct_date tmp;
    tmp.day = 1;
    tmp.month = month;
    tmp.year = year;
    int pos = what_day(tmp);
    int days = GetDaysFromMonth(month, year);
     cout << "Sun\t" << "Mon\t" << "Tue\t" << "Wen\t";
     cout << "Thu\t" << "Fri\t" << "Sat\n";
    for (int j = 0; j < pos; ++j) {
        cout << "\t";
    }
    for (int i = 1; i <= days; ++i) {
        cout  << i;
        cout << "\t";
        if (pos == 6) {
            cout << endl;
        }
        pos++;
        pos %= 7;
    }
}

bool IsFourIncludes(int n) {
    while (n) {
        if (n % 10 == 4) {
            return true;
        }
        n /= 10;
    }
    return false;
}

bool IsThirteenIncludes(int n) {
    bool flag = false;
    while (n) {
        int tmp = n % 10;
        if (3 == tmp) {
            flag = true;
        }
        else if (flag) {
            if (1 == tmp) {
                return true;
            }
            else {
                flag = false;
            }
        }
        n /= 10;
    }
    return false;
}

void PrintDigit(int n) {
    switch (n) {
        case 0:
        cout << "   ***  " << endl;
        cout << "  *   * " << endl;
        cout << "  *   * " << endl;
        cout << "  *   * " << endl;
        cout << "   ***  " << endl;
        break;
        
        case 1:
        cout << "    *   " << endl;
        cout << "  * *   " << endl;
        cout << "    *   " << endl;
        cout << "    *   " << endl;
        cout << "   ***  " << endl;
        break;
        
        case 2:
        cout << "   ***  " << endl;
        cout << "  *   * " << endl;
        cout << "     *  " << endl;
        cout << "    *   " << endl;
        cout << "   **** " << endl;
        break;
        
        case 3:
        cout << "   ***  " << endl;
        cout << "  *   * " << endl;
        cout << "    **  " << endl;
        cout << "  *   * " << endl;
        cout << "   ***  " << endl;
        break;

        case 4:
        cout << "  *  *  " << endl;
        cout << "  *  *  " << endl;
        cout << "  ****  " << endl;
        cout << "     *  " << endl;
        cout << "     *  " << endl;
        break;

        case 5:
        cout << "  ****  " << endl;
        cout << "  *     " << endl;
        cout << "  ****  " << endl;
        cout << "     *  " << endl;
        cout << "  ****  " << endl;
        break;

        case 6:
        cout << "  ****  " << endl;
        cout << "  *     " << endl;
        cout << "  ****  " << endl;
        cout << "  *  *  " << endl;
        cout << "  ****  " << endl;
        break;

        case 7:
        cout << "  ****  " << endl;
        cout << "    *   " << endl;
        cout << "  *     " << endl;
        cout << "  *     " << endl;
        cout << "  *     " << endl;
        break;

        case 8:
        cout << "  ****  " << endl;
        cout << "  *  *  " << endl;
        cout << "  ****  " << endl;
        cout << "  *  *  " << endl;
        cout << "  ****  " << endl;
        break;

        case 9:
        cout << "  ****  " << endl;
        cout << "  *  *  " << endl;
        cout << "  ****  " << endl;
        cout << "     *  " << endl;
        cout << "  ****  " << endl;
        break;

        default:

        break;
    }
}