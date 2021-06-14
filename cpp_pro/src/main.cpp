#include <iostream>
#include <cmath>

int main() {
	using namespace std;
	setlocale(LC_ALL, "Russian");

	//1
    // average

//	double first {}, second{}, third{};
//	cout << "first: ";
//	cin >> first;
//	cout << "second: ";
//	cin >> second;
//	cout << "third: ";
//	cin >> third;
//    cout << "average is: " << (first + second + third) / 3.0 << endl;

    //2
    //roots of equation

//    double a{}, b{}, x{};
//    cout << "a: ";
//    cin >> a;
//    cout << "b: ";
//    cin >> b;
//    x = -b/a;
//    cout << "x = " << x << endl;

    //3
    // power of num

//    double num = 0.0, power = 0.0;
//    cout << "num: ";
//    cin >> num;
//    cout << "power: ";
//    cin >> power;
//    cout << num << " in " << power << " = " << pow(num, power) << endl;

    //4
    // Circle forms

//    double const PI = 3.14159265359;
//    double r {0.0};
//    double L {0.0};
//    double S {0.0};
//    cout << "r: " ;
//    cin >> r;
//    L = 2.0 * PI * r;
//    S = PI * r * r;
//    cout << "L = " << L << endl;
//    cout << "S = " << S << endl;

    //5
    //currency converter

//    double const DOLLAR_HRYVNA = 27.0924;
//    double const EURO_HRYVNA = 33.0100;
//    double const BYTCOIN_HRYVNA = 895321.67;
//    cout << "Hryvnas: ";
//    double hryvnas = 0.0;
//    cin >> hryvnas;
//    cout << "dollars: " << hryvnas / DOLLAR_HRYVNA << "\t";
//    cout << "euro: " << hryvnas / EURO_HRYVNA << "\t";
//    cout << "bitcoin: " << hryvnas / BYTCOIN_HRYVNA << "\n";

    //6
    //converner km, miles

//    cout << "km: ";
//    double km = 0.0;
//    cin >> km;
//    double const MILLES_KM = 1.0 / 1.60934;
//    double const SEA_MILLES_KM = 1.0 / 1.852;
//    cout << "miles: " << MILLES_KM * km << "\t";
//    cout << "sea_miles: " << SEA_MILLES_KM * km << "\n";

    //7
    //percents

//    cout << "N: ";
//    double N = 0;
//    cin >> N;
//    double PERCENT = 0.01;
//    cout << "P: ";
//    double P = 0;
//    cin >> P;
//    cout << N * P * PERCENT << endl;

    //8
    //degrees converter

//    double KC = 273.15;
//    double REAMUR_CELCIUM = 1.25;
//    cout << "C: ";
//    double C = 0;
//    cin >> C;
//    cout << "F: " << (C * 9.0/5.0) + 32.0 << "\t";
//    cout << "K: " << C + KC << "\t";
//    cout << "R: " << 1.0 / REAMUR_CELCIUM * C << "\t";
//    cout << "D: " << (100.0 - C) * 3.0 / 2.0 << "\n";
//    cout << "F: ";
//    double F = 0;
//    cin >> F;
//    cout << "C: " << (F - 32.0) * 5.0/9.0 << " C" << endl;

    //9
    //swap a and b;
    int a = 0, b = 0;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "a = " << a << "\tb = " << b << endl;
    int tmp = a;
    a = b;
    b = tmp;
    cout << "a = " << a << "\tb = " << b << endl;
    a += b;
    b = a - b;
    a -= b;
    cout << "a = " << a << "\tb = " << b << endl;
	return 0;
}
