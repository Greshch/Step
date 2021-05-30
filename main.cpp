#include <iostream>

int main() {
	using namespace std;
	setlocale(LC_ALL, "Russian");
	//1
	/*
	char const* strs[] = {
		"\"To be",
		"or not",
		"to be...\"",
		"/ Shakespeare /"
	};

	cout << "\t" << strs[0] << endl;
	cout << "\t\t" << strs[1] << endl;
	cout << "\t\t\t" << strs[2] << endl;
	cout << "\t\t\t\t" << strs[3] << endl;
	*/
	
	//2

	/*char const* str = "I love C++!";
	size_t const STRINGS = 5;
	for (size_t i = 0; i < STRINGS; ++i) {
		for (size_t j = 0; j <= i; ++j) {
			cout << "\t";
		}
		cout << str << endl;
	}*/

	//3

	//cout << "\'\\t\', " << "\'\\n\', " << "\'\\\\', " << "\'\\'\', " << "\'\\\"\'." << endl;

	//4
	/*char const* strs[] = {
		"#include <iostream>",
		"int main() {",
		"\tusing namespace std;",
		"\tsetlocale(LC_ALL, \"Russian\");",
		"\tcout << \"\'\\t\', \" << \"\'\\n\', \" << \"\'\\\\', \" << \"\'\\'\', \" << \"\'\\\"\'.\" << endl;",
		"\treturn 0;",
		"}"
	};
	size_t STRINGS = sizeof strs / sizeof strs[0];
	for (size_t i = 0; i < STRINGS; ++i) {
		cout << strs[i] << endl;
	}*/

	//5
	/*char const* strs[] = {
		"Май 2021",
		"Пн\tВт\tСр\tЧт\tПт\tСб\tВс",
		"26\t27\t28\t29\t30\t1\t2",
		"3\t4\t5\t6\t7\t8\t9",
		"10\t11\t12\t13\t14\t15\t16",
		"17\t18\t19\t20\t21\t22\t23",
		"24\t25\t26\t27\t28\t29\t30",
		"31\t1\t2\t3\t4\t5\t6"
	};
	size_t STRINGS = sizeof strs / sizeof strs[0];
	for (size_t i = 0; i < STRINGS; ++i) {
		cout << strs[i] << endl;
	}*/
	return 0;
}
