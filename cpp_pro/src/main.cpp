#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <time.h>

using namespace std;

struct Point {
    int x;
    int y;
};

enum DAYS {
    SUNDAY,
    MONDAY,
    THUESDAY,
    WENSDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

struct Data {
    int year;
    int month;
    int day;
};

enum MONTHES {
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

int const MON = 12;

int days[MON] {
    31,28, // winter
    31,30,31, // spring
    30,31,31, // summer
    30,31,30, // autumn
    31 // winter
};

bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100) {
            return true;
        } else if (year % 400 == 0) {
            return true;
        } else {
            return false;
        }
    } 
    else {
        return false;
    }
}

enum ANIMALS {
    CAT = 1,
    DOG,
    COW,
    SHEEP,
    DONKEY,
    HORSE,
    PIG,
    RUSTER,
    TURKEY,
    CROW
};

struct AnswerStruct {
    string answer;
    int right; 
};

AnswerStruct answers[] = {
    {
        R"(Определить государство по его краткому описанию. 
        Эта страна относится к числу экономически высокоразвитых.
        Ее территория полностью расположена в Западном полушарии 
        и омывается водами трех океанов.
        Страна является первой по размерам территории и третьей по
        численности населения на материке, на котором она расположена.
        
        1 Бразилия
        2 Арентина
        3 Канада
        4 США
        )",
        3,
    },

    {
        R"(Территория этой африканской страны расположена в пределах 
        экваториальногои субэкваториального климатических поясов. 
        Главными природными богатствами являются запасы нефти, 
        природного газа, оловянных руд. 
        По численности населения страна входит в десятку крупнейших стран мира. 
        Страна активно участвует в международном 
        географическом разделении труда, является членом ОПЕК.

        1 Судан
        2 Египет
        3 Нигерия
        4 Ангола
        )" , 
        3
    },

    {
        R"(Эта страна относится к числу экономически высокоразвитых.
        Ее территория расположена в Восточном полушарии и омывается 
        водами Тихого и Индийского океанов. 
        Значительную часть территории занимают пустыни и полупустыни. 
        Особенность животного мира – сумчатые млекопитающие, 
        а также млекопитающие, откладывающие яйца.

        1 Япония
        2 Австралия
        3 Китай
        4 Саудовская Аравия
        )" , 
        2
    },

    {
        R"(Эта страна — одна из самых крупных, быстроразвивающихся стран
        материка, длительное время была колонией Франции.
        Более 90% ее населения проживает в прибрежной полосе 
        и горных долинах. Главное богатство страны — месторождения 
        нефти и природного газа. Основная отрасль промышленности — 
        горнодобывающая, 99% экспорта страны составляют нефть 
        и нефтепродукты.

        1 Алжир
        2 Египет
        3 Ливия
        4 Судан
        )" , 
        1
    },
    
    {
        R"(Эта высокоразвитая страна по форме правления является конституционной 
        монархией. По числу жителей входит в первую десятку стран мира. 
        Однонациональное по составу население характеризуется высокой 
        средней плотностью, самой высокой продолжительностью жизни в мире. 
        В промышленности приоритетное развитие получили новейшие наукоемкие
        отрасли.

        1 Япония
        2 США
        3 Китай
        4 Бразилия
        )" , 
        1
    },

    {
        R"( Эта страна — вторая по площади территории на материке,
        расположена в трех климатических поясах. Длительное время
        (в течение трех веков) она оставалась испанской колонией. 
        В этой стране находится самая высокая 
        точка на материке (6959 м). На юге сформировались сухие 
        степи – Патагония. Крупнейшим городом является столица.

        1 Венесуэла
        2 Бразилия
        3 Аргентина
        4 Мексика
        )" , 
        3
    }
    
};

int const T_TOO_HOT = 35;
int const T_HOT = 27;
int const T_WARMY = 21;
int const T_COOL = 15;
int const T_COLDLY = 8;
int const T_COLD = 0;
int const T_FROZENLY = -5;
int const T_FROZEN = -12;
int const T_VERY_FROZEN = -20;
int const T_DEEP_FROZEN = -27;

enum ZODIACS {
    KOZEROG,
    STRELEC,
    VODOLEY,
    RYBY,
    OVEN,
    TELEC,
    BLYZNICY,
    RAK,
    LEV,
    DEVA,
    VESY,
    SCORPION
};

int main() {
	setlocale(LC_ALL, "Russian");
    srand(time(0));

	//1
    //Paralelna li pryamaya OX or OY

    // Point A, B;
    // cout << "A(x,y): ";
    // cin >> A.x >> A.y;

    // cout << "B(x,y): ";
    // cin >> B.x >> B.y;

    // int dx = B.x - A.x;
    // int dy = B.y - A.y;

    // if (0 == dx) {
    //     cout << "AB || OY" << endl;
    // }

    // if (0 == dy) {
    //     cout << "AB || OX" << endl;
    // }

    //////////////////////////////////////////////////////

    //2
    //Does the num have a iracional part

    // double d_num = 0.0;
    // cout << "num: ";
    // cin >> d_num;
    
    // bool realExist = (d_num - (int)d_num > 0) ? true : false;
    // if (realExist) {
    //     cout << "Num has a fractional part\n";
    // } 

    //////////////////////////////////////////////////////

    //3
    //Day of week
    //3.1 version "if"
    // int day;
    // cout << "Input num of day: ";
    // cin >> day;

    // if (day == DAYS::SUNDAY) {
    //     cout << "It's a " << "sunday" << endl;
    // }
    // else if (day == DAYS::MONDAY) {
    //     cout << "It's a " << "monday" << endl;
    // }
    // else if (day == DAYS::THUESDAY) {
    //     cout << "It's a " << "thuesday" << endl;
    // }
    // else if (day == DAYS::WENSDAY) {
    //     cout << "It's a " << "wensday" << endl;
    // }
    // else if (day == DAYS::THURSDAY) {
    //     cout << "It's a " << "thursday" << endl;
    // }
    // else if (day == DAYS::FRIDAY) {
    //     cout << "It's a " << "friday" << endl;
    // } 
    // else if (day == DAYS::SATURDAY) {
    //     cout << "It's a " << "saturday" << endl;
    // } 
    // else {
    //     cout << "Unknown day..." << endl;
    // }

    //3.1 switch version
    // int day;
    // cout << "Input num of day: ";
    // cin >> day;

    // switch (day) {
    //     case DAYS::SUNDAY:
    //     cout << "It's a " << "sunday" << endl;
    //     break;

    //     case DAYS::MONDAY:
    //     cout << "It's a " << "monday" << endl;
    //     break;

    //     case DAYS::THUESDAY:
    //     cout << "It's a " << "thuesday" << endl;
    //     break;

    //     case DAYS::WENSDAY:
    //     cout << "It's a " << "wensday" << endl;
    //     break;

    //     case DAYS::THURSDAY:
    //     cout << "It's a " << "thursday" << endl;
    //     break;

    //     case DAYS::FRIDAY:
    //     cout << "It's a " << "friday" << endl;
    //     break;

    //     case DAYS::SATURDAY:
    //     cout << "It's a " << "saturday" << endl;
    //     break;
    // }

    /////////////////////////////////////////////////////////////////////

    //4
    //Correct hour:minutes:seconds

    // int hours, minutes, seconds;
    // cout << "Input hours(0-23): ";
    // cin >> hours;

    // cout << "Input minutes(0-59): ";
    // cin >> minutes;

    // cout << "Input seconds(0-59): ";
    // cin >> seconds;

    // if (hours < 0 || hours > 23) {
    //     cout << "Incorrect hours...\n";
    // }
    // if (minutes < 0 || hours > 59) {
    //     cout << "Incorrect minutes...\n";
    // }
    // if (seconds < 0 || seconds > 59) {
    //     cout << "Incorrect seconds...\n";
    // }

    ////////////////////////////////////////////////////////////////////

    //5
    //Lucky trams ticket with 6 digits

    // cout << "Input number of ticket(******): ";
    // int ticket_num = 0;
    // cin >> ticket_num;

    // int n6 = (ticket_num / 1) % 10;
    // int n5 = (ticket_num / 10) % 10;
    // int n4 = (ticket_num / 100) % 10;
    // int n3 = (ticket_num / 1000) % 10;
    // int n2 = (ticket_num / 10000) % 10;
    // int n1 = (ticket_num / 100000) % 10;

    // int sum_left = n1 + n2 + n3;
    // int sum_right = n4 + n5 + n6;

    // if (sum_left == sum_right) {
    //     cout << "Lucky ticket!!))\n";
    // }
    // else {
    //     cout << "...Hmm...\n";
    // }

    /////////////////////////////////////////////////////////////

    //6
    //Greetings (hour)

    // int hours = 0;
    // cout << "Input hours(0-23): ";
    // cin >> hours;
    // if (hours >= 16) {
    //     cout << "Good Evening!";
    // } 
    // else if (hours >= 12) {
    //     cout << "Good Day!";
    // }
    // else if (hours >= 4) {
    //     cout << "Good Mornig!";
    // }
    // else  {
    //     cout << "Good Night!";
    // }
    // cout << endl;

    /////////////////////////////////////////////////////////////

    //7
    //Perfect weight and height

    // int const HEIGHT_LOW = 45;
    // int const HEIGHT_UP = 245;

    // int const WEIGHT_LOW = 10;
    // int const WEIGHT_UP = 500;

    // int const PERFECT_DIF_MAN = 100;
    // int const PERFECT_DIF_WOMAN = 110;

    // cout << "Your sex(m,f): ";
    // char sex;
    // cin >> sex;
    // if (sex != 'm' && sex != 'f') {
    //     cout << "...Unknown gender error...\n";
    //     return 101;
    // }

    // cout << "Your height(sm): ";
    // int height = 0;
    // cin >> height;
    // if (height < HEIGHT_LOW || height > HEIGHT_UP) {
    //     cout << "...Out of bound of height error...\n";
    //     return 404;
    // }

    // cout << "Your weight(kg): ";
    // int weight = 0;
    // cin >> weight;
    // if (weight < WEIGHT_LOW || weight > WEIGHT_UP) {
    //     cout << "...Out of bound of weight error...\n";
    //     return 103;
    // }

    // int perfect_weight = (sex == 'm') ? (height - PERFECT_DIF_MAN)
    //                            : (height - PERFECT_DIF_WOMAN);
    // if (weight < perfect_weight) {
    //     cout << "You ought to put on weight " << perfect_weight - weight
    //          << endl;
    // } 
    // else if (weight > perfect_weight) {
    //      cout << "You ought to lose weight " << weight - perfect_weight
    //          << endl;
    // }
    //  else {
    //      cout << "You have a perfect weight!!!" << endl;
    // }

    /////////////////////////////////////////////////////////////

    //8 Next Day

    // Data prev;
    // cout << "Input data(d:m:y): ";
    // cin >> prev.day >> prev.month >> prev.year;
    // if (prev.year < 0 ||
    //     prev.month <= 0 || prev.month > MON || 
    //     prev.day <= 0 || prev.day > days[prev.month-1]) {
    //     cout << "Incorrect data...\n";
    //     return 101;
    // }

    // Data next;
    // next.month = prev.month;
    // next.year = prev.year;
    // //leaps year ammend
    // int leap_february_add = 
    // (isLeapYear(prev.year) && prev.month == MONTHES::FEB) ? 1 : 0;
    // next.day = (prev.day + 1) % (days[prev.month - 1] + 1 + leap_february_add);
    // if (next.day == 0) {
    //     next.day = 1;
    //     next.month = (prev.month + 1) % (MON + 1); 
    // }

    // if (next.month == 0) {
    //     next.month = 1;
    //     next.year++;
    // }

    // cout << next.day << "." << next.month << "." << next.year << endl; 

    /////////////////////////////////////////////////////////////

    //9 Animals behaviour

    // int animal;
    // cout << "\tCAT(1)\n";
    // cout << "\tDOG(2)\n";
    // cout << "\tCOW(3)\n";
    // cout << "\tSHEEP(4)\n";
    // cout << "\tDONKEY(5)\n";
    // cout << "\tHORSE(6)\n";
    // cout << "\tPIG(7)\n";
    // cout << "\tRUSTER(8)\n";
    // cout << "\tTURKEY(9)\n";
    // cout << "\tCROW(10)\n";
    // cout << "Choose Animal: ";

    
    // cin >> animal;
    // switch (animal) {
    //     case ANIMALS::CAT:
    //     cout << "..Miau..Murr...\n";
    //     break;

    //     case ANIMALS::DOG:
    //     cout << "..Wwaaw...Tiav..tiav...\n";
    //     break;

    //     case ANIMALS::COW:
    //     cout << "..Muu..Muuu...\n";
    //     break;

    //     case ANIMALS::SHEEP:
    //     cout << "..Beee..Beee...\n";
    //     break;

    //     case ANIMALS::DONKEY:
    //     cout << "..Ia..Ia...\n";
    //     break;

    //     case ANIMALS::HORSE:
    //     cout << "..Iiggogo..Iigogo...\n";
    //     break;

    //     case ANIMALS::PIG:
    //     cout << "..Qee..Quee...\n";
    //     break;

    //     case ANIMALS::RUSTER:
    //     cout << "..Kuka-reku..Kuka-reku...\n";
    //     break;

    //     case ANIMALS::TURKEY:
    //     cout << "..Guul..Guul-guul...\n";
    //     break;

    //     case ANIMALS::CROW:
    //     cout << "..Kharr..Kharr...\n";
    //     break;
        
    //     default:
    //     cout << "...Undefined behaviour\n";
    //     break;
    // }

    /////////////////////////////////////////////////////////////

    //10 O schaslivchik
    // random_shuffle(begin(answers), end(answers));

    // size_t size = sizeof answers / sizeof answers[0];
    // for (size_t i = 0; i < size; ++i) {
    //     cout << answers[i].answer;
    //     int answer = 0;
    //     cout << ": ";
    //     cin >> answer;

    //     if (answer != answers[i].right) {
    //         cout << "\n\tGame Over....\n";
    //         return 101;
    //     }
    // }
    // cout << "CONGRATULATIONS!!!\n";

    /////////////////////////////////////////////////////////////

    //11 forecast

    // int T = 0;
    // cout << "T(*C): ";
    // cin >> T;
    // if (T >= T_TOO_HOT) {
    //     cout << "It's too hot\n";
    // } 
    // else if (T >= T_HOT) {
    //      cout << "It's hot\n";
    // }
    // else if (T >= T_WARMY) {
    //     cout << "It's warmy\n";
    // }
    // else if (T >= T_COOL) {
    //     cout << "It's cool\n";
    // }
    // else if (T >= T_COLDLY) {
    //     cout << "It's coldly\n";
    // }
    // else if (T >= T_COLD) {
    //     cout << "It's cold\n";
    // }
    // else if (T >= T_FROZENLY) {
    //     cout << "It's frozenly\n";
    // }
    // else if (T >= T_VERY_FROZEN) {
    //     cout << "It's very frozen\n";
    // }
    // else if (T >= T_DEEP_FROZEN) {
    //     cout << "It's too frozen\n";
    // }
    // else {
    //     cout << "It's extremaly frozen\n";
    // }

    //12
    //mystic

    // const int LENGTH = 20;

    // cout << "Your answer: ";
    // char ch;
    // cin >> ch;

    // int ask = rand() % LENGTH;

    // switch (ask) {
    //     case 0:
    //     cout << "Бесспорно" << endl;
    //     break;

    //     case 1:
    //     cout << "Предрешено" << endl;
    //     break;

    //     case 2:
    //     cout << "Никаких сомнений" << endl;
    //     break;

    //     case 3:
    //     cout << "Определённо да" << endl;
    //     break;

    //     case 4:
    //     cout << "Можешь быть уверен в этом" << endl;
    //     break;

    //     case 5:
    //     cout << "Мне кажется — «да»" << endl;
    //     break;

    //     case 6:
    //     cout << "Вероятнее всего" << endl;
    //     break;

    //     case 7:
    //     cout << "Хорошие перспективы" << endl;
    //     break;

    //     case 8:
    //     cout << "Знаки говорят — «да»" << endl;
    //     break;

    //     case 9:
    //     cout << "Да" << endl;
    //     break;

    //     case 10:
    //     cout << "Пока не ясно, попробуй снова" << endl;
    //     break;

    //     case 11:
    //     cout << "Спроси позже" << endl;
    //     break;

    //     case 12:
    //     cout << "Лучше не рассказывать" << endl;
    //     break;

    //     case 13:
    //     cout << "Сейчас нельзя предсказать" << endl;
    //     break;

    //     case 14:
    //     cout << "Сконцентрируйся и спроси опять" << endl;
    //     break;

    //     case 15:
    //     cout << "Даже не думай" << endl;
    //     break;

    //     case 16:
    //     cout << "Мой ответ — «нет»" << endl;
    //     break;

    //     case 17:
    //     cout << "По моим данным — «нет»" << endl;
    //     break;

    //     case 18:
    //     cout << "Перспективы не очень хорошие" << endl;
    //     break;

    //     case 19:
    //     cout << "Весьма сомнительно" << endl;
    //     break;
    // }

    //13 zodiac
    // Data user_data;
    // cout << "User birthday(day : month) : ";
    // cin >> user_data.day >> user_data.month;
    // int user_zodiac;
    
    // if ((user_data.month == 12 && user_data.day >= 23) ||
    //      (user_data.month == 1 && user_data.day <= 20)) {
    //     user_zodiac = ZODIACS::KOZEROG;
    // }
    // else if ((user_data.month == 1 && user_data.day >= 21) ||
    //      (user_data.month == 2 && user_data.day <= 19)) {
    //     user_zodiac = ZODIACS::VODOLEY;
    // }
    // else if ((user_data.month == 2 && user_data.day >= 20) ||
    //      (user_data.month == 3 && user_data.day <= 20)) {
    //     user_zodiac = ZODIACS::RYBY;
    // }
    // else if ((user_data.month == 3 && user_data.day >= 21) ||
    //      (user_data.month == 4 && user_data.day <= 20)) {
    //     user_zodiac = ZODIACS::OVEN;
    // }
    // else if ((user_data.month == 4 && user_data.day >= 21) ||
    //      (user_data.month == 5 && user_data.day <= 21)) {
    //     user_zodiac = ZODIACS::TELEC;
    // }
    // else if ((user_data.month == 5 && user_data.day >= 22) ||
    //      (user_data.month == 6 && user_data.day <= 21)) {
    //     user_zodiac = ZODIACS::BLYZNICY;
    // }
    // else if ((user_data.month == 6 && user_data.day >= 22) ||
    //      (user_data.month == 7 && user_data.day <= 22)) {
    //     user_zodiac = ZODIACS::RAK;
    // }
    // else if ((user_data.month == 7 && user_data.day >= 23) ||
    //      (user_data.month == 8 && user_data.day <= 21)) {
    //     user_zodiac = ZODIACS::LEV;
    // }
    // else if ((user_data.month == 8 && user_data.day >= 22) ||
    //      (user_data.month == 9 && user_data.day <= 23)) {
    //     user_zodiac = ZODIACS::DEVA;
    // }
    // else if ((user_data.month == 9 && user_data.day >= 23) ||
    //      (user_data.month == 10 && user_data.day <= 23)) {
    //     user_zodiac = ZODIACS::VESY;
    // }
    // else if ((user_data.month == 10 && user_data.day >= 24) ||
    //      (user_data.month == 11 && user_data.day <= 22)) {
    //     user_zodiac = ZODIACS::SCORPION;
    // }
    // else if ((user_data.month == 11 && user_data.day >= 23) ||
    //      (user_data.month == 12 && user_data.day <= 20)) {
    //     user_zodiac = ZODIACS::STRELEC;
    // }

    // switch (user_zodiac) {
    //     case ZODIACS::OVEN:
    //     cout << R"(
    //     Обстоятельства этой недели вызовут у Овнов небольшую растерянность. 
    //     Представители знака Зодиака Овен будут подсознательно чувствовать 
    //     тревогу от общения с кем-то из новых соседей или друзей. 
    //     Возможно, лучше не форсировать события на пути сближения с этим 
    //     человеком. Спешить не нужно и в домашних делах. 
    //     Астрологическая картина этой недели не исключает бытовых травм
    //     и ушибов.

    //     Необходимо следить и за тем, каков уровень ваших жизненных сил. 
    //     Дорогие Овны, порой следует отказаться от «неотложных» дел ради 
    //     восстановления организма. Энергия станет расти, если окружите 
    //     себя всем тем, что особенно любите. Звёзды не советуют 
    //     злоупотреблять алкоголем и превышать калорийность своего рациона.

    //     )";
    //     break;

    //     case ZODIACS::TELEC:
    //     cout << R"(
    //     Tельцам на этой неделе, скорее всего, не избежать недомолвок и сплетен.
    //     Постарайтесь не привлекать к себе слишком много внимания, не пытайтесь
    //     перетягивать одеяло в ходе диалога. Скромность и простота
    //     приветствуются буквально во всём. Астрологическая обстановка этой
    //     недели в целом благоприятна для старта новых идей
    //     (тех, которыми можете заниматься и без союзников).

    //     К середине недели у многих из вас появятся на руках главные козыри.
    //     Возможно, станет более понятной ситуация в личных делах или
    //     состоится знакомство, способное стать судьбоносным.
    //     Семейным Тельцам не желательно тратить словарный запас на
    //     попытки примирить конфликтующих родственников. Наблюдайте
    //     за ними со стороны, и скоро они сами решат сесть за стол переговоров.

    //     )";
    //     break;

    //     case ZODIACS::BLYZNICY:
    //     cout << R"(
    //     Начало недели для Близнецов ознаменуется необычным предложением.
    //     Не торопитесь его отвергать. Не исключено, что прозвучавшее если
    //     не целиком, то частично, можно использовать с расчётом на будущее.
    //     В середине недели у вас, дорогие Близнецы, возрастёт творческая
    //     составляющая жизни. Смело беритесь за «пробу пера» в любом
    //     интересном для вас направлении.

    //     Астрологическая картина этой недели почти полностью исключает
    //     вероятность неожиданностей в личных делах. Семейные Близнецы
    //     увидят от своих вторых половинок и романтизм, и обожание, 
    //     и открытость для продуктивного общения. Тем, кто пока не нашёл
    //     спутника жизни, следует менее требовательно смотреть на сферу
    //     чувств и отказаться от поиска идеала.

    //     )";
    //     break;

    //     case ZODIACS::RAK:
    //     cout << R"(
    //     У Раков на этой неделе почти не останется времени на отдых.
    //     Каждое дело, которое будут начинать представители вашего знака
    //     Зодиака, приблизит успех. Особенно продуктивно будут удаваться
    //     переговоры и обсуждения. Настойчивее боритесь за свои права,
    //     допустив в своём голосе нотки металла.

    //     Во второй половине недели гороскоп советует не вмешиваться в
    //     происходящие события. Пока мир нестабилен, куда правильнее будет
    //     заниматься своим самочувствием, красотой, повышением
    //     энергетического потенциала. Дорогие Раки, скептически относитесь
    //     ко всем новостным вбросам в этот период. Далеко не вся входящая
    //     информация исходит из достоверных источников и уж точно не
    //     вся заслуживает вашего внимания.

    //     )";
    //     break;

    //     case ZODIACS::LEV:
    //     cout << R"(
    //     Неделя благоприятна для того, чтобы Львы могли приблизить свой
    //     успех. Гороскоп советует прислушаться к пожеланиям своего
    //     ближайшего круга общения. Эти люди для вас гораздо больше,
    //     нежели просто союзники. Успех во многом будет зависеть от
    //     установленных между вами договорённостей.

    //     Не следует забывать и о повседневных делах. Во второй половине
    //     недели возможно неожиданное развитие событий в том процессе,
    //     который, как вы считали, не требует внимания. Откорректируйте
    //     поведение, проведите работу над ошибками, и ни в коем случае
    //     не останавливайтесь на достигнутом. Выходные этой недели
    //     будет хорошо посвятить близким членам семьи или любимому человеку.

    //     )";
    //     break;

    //     case ZODIACS::DEVA:
    //     cout << R"(
    //     На этой неделе представители знака Зодиака Дева проявят стремление
    //     к независимости. Следите, чтобы борьба за свободу не мешала делам.
    //     В них на первом месте по-прежнему суммарный итог командных трудов,
    //     а не возможность потешить своё самолюбие. Астрологическая
    //     обстановка недели не предполагает неожиданностей. Этот спокойный
    //     и гармоничный период желательно посвятить активному продвижению
    //     своих природных талантов.

    //     В личных делах Девам не придётся кого-то убеждать в своей правоте.
    //     Близкие люди будут открыты для диалога и обсуждения свежих идей.
    //     Если на повестке дня вопросы, связанные с имуществом, наследством
    //     или недвижимостью, следует воспользоваться советом эксперта.
    //     Импульсивные решения могут быть опасны.

    //     )";
    //     break;

    //     case ZODIACS::VESY:
    //     cout << R"(
    //     Весам на этой неделе удастся разобраться c одной из запутанных
    //     ситуаций. Однако гороскоп не гарантирует, что, пролив свет на этот
    //     вопрос, вы будете удовлетворены полученным итогом. Многое потребует
    //     доработки или корректировки. В начале недели может проявиться 
    //     лёгкая грусть. Дорогие Весы, вы быстро избавитесь от депрессивного
    //     настроя, если вспомните о прошлых победах и мотивируете себя с
    //     надеждой посмотреть в будущее.

    //     Личные отношения на протяжении недели будут развиваться своим
    //     чередом. Одинокие представители знака Зодиака Весы при желании
    //     смогут привлечь к себе внимание интересующего вас человека.
    //     Семейные Весы, решив потешить тщеславие, рискуют вызвать приступ
    //     ревности со стороны своего партнёра по отношениям.

    //     )";
    //     break;

    //     case ZODIACS::SCORPION:
    //     cout << R"(
    //     Скорпионы на этой неделе почувствуют прирост жизненных сил.
    //     Это отличное время, чтобы перейти от планирования к активным
    //     действиям. Если ваша главная цель — нечто конкретное в домашних
    //     делах, итоги каждого из таких начинаний окажутся впечатляющими.

    //     Гороскоп не рекомендует терять драгоценное время и в делах
    //     личных. Во второй половине недели станет понятно, кто настоящий
    //     друг, а кто всего лишь пользуется вашим доверием. Не стоит
    //     переживать. Прервав малоприятный контакт, вы готовите свободное
    //     место, чтобы впустить в свою жизнь более подходящего вам
    //     человека — честного и порядочного.

    //     )";
    //     break;

    //     case ZODIACS::STRELEC:
    //     cout << R"(
    //     Уравновешенность Стрельцов на этой неделе будет достойна похвал,
    //     и нет таких дел, в которых вы бы не смогли разобраться в этот
    //     период. Астрологическая обстановка не исключает необходимости
    //     тушить разногласия между родственниками, коллегами или соседями.

    //     К концу недели вам, дорогие Стрельцы, рекомендуется слегка снизить
    //     финансовый аппетит. Попробуйте рассмотреть бюджетные аналоги тех
    //     вещей, которые хотели бы приобрести, не отказывайтесь от
    //     консультации со специалистами интернет-магазинов. На выходных
    //     может напомнить о себе человек из вашего детства. Воскресенье
    //     оставит приятные воспоминания.

    //     )";
    //     break;

    //     case ZODIACS::KOZEROG:
    //     cout << R"(
    //     Неделя благоприятная, не грузит проблемами, но и интересных событий
    //     также пока не предвидится. Гороскоп рекомендует Козерогам поработать
    //     над собой. Это отличное время учиться и развиваться как внешне, так
    //     и внутренне. Все важные решения перенесите на следующую неделю.

    //     В конце недели Козерогам следует избегать недосказанности в личных
    //     беседах, и старайтесь мысленно проговаривать каждую фразу прежде,
    //     чем её произнести. Гороскоп рекомендует в этот период избегать
    //     легковерности. Есть риск, что кто-то намерен лишить вас объективной
    //     картины происходящих событий, представив всё в выгодном для себя виде.

    //     )";
    //     break;
    // }

    ////////////////////////////////////////////////////////////////////////

    //14
    // Chickens and egs

    // double const NDS = 0.8;

    // int N; //cn-t chickens
    // double M; // Price of a chicken

    // int X; //cn-t eggs in week
    // double Z; // Price of 10 eggs

    // cout << "Chickens: ";
    // cin >> N;

    // cout << "Price of a chicken: ";
    // cin >> M;

    // cout << "How many eggs it gets in a week from one chicken: ";
    // cin >> X;

    // cout << "Price of 10 eggs: ";
    // cin >> Z;

    // double spending = N * M;
    // double profite_per_week = (N * X) / 10.0 * Z * NDS;
    // double weeks = spending / profite_per_week;

    // cout << "You have to spend " << weeks << endl;

	return 0;
}
