#include <cmath>			// математические функции
#include <locale.h>	// функции, устанавливающие национальные кодировки символов
#include <iostream>	// Эта - часть библиотеки STL (Standard Template Library)
#include <limits>			// Полезные константы
#include<bitset>
#include<conio.h>

using namespace std;		// Обеспечивает видимость имен STL
#define stop __asm nop// Эта макроподстановка упрощает установку точек останова

int n;	 // Глобальная переменная. По умолчанию она обнуляется.

namespace space	 // В пространстве имен - space
{
	int n = 1;	 // Объявлена переменная n
}				 // space определяет область видимости этой переменной

int  main()
{
	// Выполняя программу по шагам, следите за значениями переменных  и интерпретируйте результат, объясняя себе
	// наблюдаемые значения. Обратите внимание на разную интерпретацию отладчиком  signed и unsigned типов данных.
	char c = 'A'; // 65 'A' 0x41 
	char test = 'A' - 'a';
	// !Первое число означает дестияная кодировка данного символа в соответствии в таблицами ASCII(American Standard Code for Information Interchange)
	// !0x41 шестнадцатиричная кодировка данного сивола, так как sizeof(char) = 1 byte, то поэтому 2 ячейки 
	// В комментарии справа полезно проставить десятичное символьное и шестнадцатиричное 
	// значения переменной после выполнения указанной строки. Вы должны видеть их в окне Autos.
	c = 0x42;		// 66 'B' 0x42
	c = -1;		// -1 'я' 0xff
	c = CHAR_BIT;	 // Размер переменной типа char !1 byte = 8 bit

	//cout<<int(255)<<endl;

	// В комментариях напишите результат, возвращаемый оператором sizeof для
	// переменной типа wchar_t (ее размер)
	wchar_t cw = L'Ф'; // !wchar_t - это расширенный тип символов
	// !Символьный литерал, начинающийся с L префикса, является расширенным символьным литералом.
	size_t ns = sizeof(cw); // !2 byte

	unsigned char uc = 0x41; // !65 'A' весь 1 байт используется под неотрицательные значения 
	uc = 'B'; // !66 'B' 0x42
	uc = -1; // !255 'я' 0xff

	stop;

	int i = 1;
	i = -1;
	stop;

	unsigned int ui = 1;
	ui = -1; // 4294967295 0xffff

	unsigned short s = 0xffff;// !нужно добавить unsigned // Здесь compiler генерирует warning. Измените код, чтобы убрать warning
	s = short(0xffff);
	s = 1;

	//==== Измените код, чтобы убрать warning
	unsigned short us = 0xffff;
	us = 5;

	long l = 0xffffffff;
	l = -128;

	// Все эти константы вы должны найти в файле limits (float.h) и объяснить их смысл по комментариям
	l = FLT_MAX_EXP; //!max binary exponent Если вы пытаетесь сохранить число в переменной float, которая больше FLT_MAX (2^128), происходит переполнение
	l = DBL_MAX_EXP; //!max binary exponent Если вы пытаетесь сохранить число в переменной double, которая больше DBL_MAX (2^1024), происходит переполнение

	l = FLT_MANT_DIG; // !# of bits in mantissa  = 24 (-1)^s × M × B^E  228 = 2.28*10^2 только в двоичном формате
	l = DBL_DIG; // !# of decimal digits of precision = 15 показывает точность числа double

	l = FLT_MANT_DIG; // !# of bits in mantissa
	l = DBL_MANT_DIG; // !# of bits in mantissa  = 52
	l = FLT_DIG; // !# of decimal digits of precision = 6 показывает точность числа float

	float f = -12.56f; // !truncation from 'double' to 'float' добавить f	 // Здесь warning. Уберите его.
	f = -1.e-27f;

	f = FLT_MAX; // !3.402823466e+38F max value
	f = FLT_MIN; // !1.175494351e-38F min normalized positive value

	double d = 0.1234567890123456789123456789;
	d = -0.123456789012345e+306;
	d = DBL_MAX; // !1.7976931348623158e+308  max value
	d = DBL_MIN; //!2.2250738585072014e-308  min positive value
	d = DBL_EPSILON; // Самая маленькая разность между двумя пер-ми типа double 2.2204460492503131e-016

	double test1 = 0.1;
	double test2 = 0.2;
	cout << test1 + test2;

	uc = ~0;	// 255 'я' // Побитовое отрицание
	i = ~0; // -1
	stop;
	// Раннее (при компиляции) или неявное приведение типов данных
	// Объясните те значения, которые вы наблюдаете в окне Autos. Определите порядок выполения присваиваний.

	d = (f = (i = (s = (c = 1 / 3))));  // 0
	c = (s = (i = (f = (d = 100 / 3)))); // !33 '!' ... для разных типов будет 33
	c = (s = (i = (f = (d = 10 / 3)))); // 3
	c = (s = (i = (f = (d = 1 / 3.)))); // d = 0.33333333333333331 f = 0.333333343 отсальные 0

	// Пример "небрежного" использования неявного приведения типов.	 Объясните результаты.
	i = 256;
	c = i; // с = 0 '\0' 0x00 потому что размер char = 1 byte, то есть можно закодировать 255 символов( -127 128), если написали 256, то все пойдет сначала (с 0)

	uc = 255;
	unsigned char u = 2, sum = uc + u; // sum = 1 unsigned char от 0 до 255, потому что 1 байт => если будет 257, то начнется все сначала 
	stop;

	// Явное приведение типов	Объясните разницу результатов в строках (3) и (4)
	i = 100;
	f = d = i / 3;							// (3)
	f = d = (double)i / 3;		// (4)
	f = d = double(i) / 3;			// (4)
	f = d = static_cast<double>(i) / 3;		// (4)
	stop;

	// Область действия, область видимости и время существования. В этом фрагменте фигурируют четыре
	//  переменных с одним и тем же именем n.  Одна - глобальная, вторая определена в своем пространстве имен,
	// третья - локальная внутри функции main(), четвертая - локальная внутри блока. 
	//  Обратите внимание, что глобальная переменная и та, что в пространстве имен space - объявлены вне функции main()
	// Определите, к какой из четырех переменных идет обращение, cформулируйте область действия и область видимости
	// каждой переменной. Для выполнения задания рекомендуется пользоваться  закладкой "Watches" или "Locals" окна
	// "Autos". Подсказка: В окно "Watches" можно поместить сразу все переменные (n, ::n, и space::n)
	n = 100;
	space::n = 200;
	//n++;
	int test3 = n++ + ++n;

	int arrtest[10];

	cout << endl;

	for (int i = 0; i < 10; i++) {
		i++;
		cout << space::n + i << endl;
		++i;
		::n++;
	}
	//2 6 12 
	int n;		//Где живет эта переменная ? !локальная переменная, находится в стеке
	n = 10;
	::n++;

	{				//  Начало блока
		int n;		// Эта переменная живет внутри блока
		n = -1;
		n++;
		::n++;
		space::n++;
	}		// Конец блока
	n--;
	::n--;
	space::n--;

	// Спецификатор класса памяти - static Выполняя задание по шагам, обратите внимание на  разное поведение
	// переменных nLoc и nStat
	{
	Again:
		int outer;
		cout << endl;
		for (int i = 0; i < 5; i++)
		{
			static int nStat;
			{
				int nLoc = 0;
				nLoc++;		nStat++;
				cout <<"x" << i << " " << nLoc << " " << nStat << endl;
			}
			outer = nStat;
		}
		if (outer < 10)
			goto Again;
	}

	/*
	x 0 1 1
	x 1 1 2
	x 2 1 3
	x 3 1 4
	*/

	// Перечисления - enum. Обратите внимание на явную и неявную инициализацию констант
	enum RANK
	{
		eSoldier,
		eSergeant,
		eCorporal,
		eLieutenant,
		eCaptain = 6,
		eMajor,
		eColonel = eMajor + 3,
		eGeneral = 20
	};
	typedef RANK RANG;

	RANG r = eSoldier;
	RANG rrrrr = eMajor;
	if (r == eSoldier)
		r = eSergeant;

	if (r == eSergeant)
	{
		// Любой целочисленной переменной можно присвоить enum-переменную 
		int i = r;
		r = RANK(i++);		// Обратное преобразование надо указывать явно
		i = r;
		r = RANK(++i);
		i = r;
	}
	RANK rr = eColonel;
	stop;
	//	Логический тип bool.	Выполняя задание по шагам, следите за значениями переменной b
	{
		int n = 4;
		bool b = n != 0;
		b = n == 0;
		b = n > 0;
		b = n <= 0;
		b = n > 1;
		auto task1 = n >> 1;
		auto task2 = n << 1;

		int num = static_cast<int>(b);
		if (b)
			cout << "\n\t My flag is: true" << "   or: " << b
			<< "\n\t Conversion to int: " << num << endl;
		b = n == num;
		cout << "\n\t Now the flag is: false" << "   or: " << b;
	}

	//	Модификатор const
	const double pi = acos(-1.);
	double space_permiability = 4.e-7 * pi;		//	Магнитная проницаемость пустоты
	const int dozen = 12;
	int var = dozen;

	//	Раскомментируйте следующую строчку и объясните ошибку компиляции (l-value означает left value)
	//	dozen = 1;   //! нельзя изменять значение константы
	//	Директивы условной трансляции. Объясните значение, которое принимает переменная version.
	//	Что нужно сделать для того, чтобы результат был другим?
#define _MSVER400
	const char* version;// !version принимает константную строку 
#if defined _MSVER400
	version = "version 4.00";
#elif defined _MSVER311
	version = "version 3.11";
#else
	version = "version Unknown";
#endif

	cout << endl << version;
	stop;

	//В окне ClassView или Solution Explorer поставьте фокус на имя проекта дайте команду Project/Properties.
	//	В диалоге Property Pages щелкните на папке Configuration Properties, убедитесь, что в разделе Code Generation
	//	установлена константа компиляции _DEBUG. Создайте директивы препроцессора и код С++, которые
	//	в зависимости от действующей конфигурации проекта (_DEBUG или NDEBUG) выводят соответствующее
	//	сообщение. Измените конфигурацию проекта (в диалоге Property Pages) и проверьте ваш код.
	//	Чтобы изменить конфигурацию пользуйтесь кнопкой Configuration Manager
#if defined _DEBUG
	cout << "DEDUG";
#elif defined NDEBUG
	cout << "RELEASE";
#endif
	//	Простейшие циклы. Объясните суть происходящего. 
	{
		// Цикл while надо использовать, когда неизвестно количество итераций (повторений) цикла.
		// Операция & — это побитовое AND.  Операция &= — это побитовое AND с присвоением.
		// Если непонятно, то прочтите документ Операции языка С.doc
		cout << "\n\nGradually eat out all the units:\n\n";
		unsigned short us = 0xff; // значение 1111 1111
		while (us)
		{
			cout << hex << us << endl; // выводится в 16: ff,fe,fc,f8,f0,e0,c0,80,0
			us &= us - 1; // С каждой итерацией будет убираться 1 с конца
			// 1111 1111 & 1111 1110 = 1111 1110
			// 1111 1110 & 1111 1101 = 1111 1100
			// 1111 1100 & 1111 1011 = 1111 1000
			// 1111 1000 & 1111 0111 = 1111 0000
			// 1111 0000 & 1110 1111 = 1110 0000
			// 1110 0000 & 1101 1111 = 1100 0000
			// 1100 0000 & 1011 1111 = 1000 0000
			// 1000 0000 & 0111 1111 = 0000 0000
		}

		cout << hex << us <<dec<< "\nDone\n"; // 0x00
		// Цикл for надо использовать, когда известно количество итераций и/или есть код подготовки.
		// Подсказка: odd - нечетое, even - четное.
		cout << "\n\nShow even-odd:\n\n";
		for (int i = 0; i < 10; i++)
		{
			if (i & 1)
				cout << i << " - odd\n";
			else
				cout << i << " - even\n";
		}
		// Цикл do-while программисты не любят, так как они требуют 
		// большего напряжения при разгадке своей логики.
		char c = ' ';
		do
		{
			if (c == 'a')
				cout << "\nAction is a delegate type in C#";
			else if (c == 'b')
				cout << "\nbreak is one of the 'leave' statements in all C-like languages";
			else if (c == 'c')
				cout << "\ncontinue is a 'go on' statement in all C-like languages";
			else if (c == 'd')
				cout << "\ndo-while is a rarely used loop statement in all C-like languages";
			else
				cout << "\nPlease read the rules of this loop";
			cout << "\n\nEnter chars: a, b, c, d (q - to quit):\n\n";
			cin >> c;
			if (c == 'q')
				cout << "\nI am going to leave the loop\n";
		} while (c != 'q');
		stop;
	}
	//	Логические условные операторы и циклы. Функция y = f(x) задана графиком
	//	Напишите фрагмент кода, который с шагом 0.1 вычисляет y = f(x)  и выводит в консольное окно значения x и y. 
	//	  y
	//	  | 
	//	 2|__________
	//	  |         /\
	//	  |        /  \
	//	  |       /    \
	//	  |______/      \__________  x
	//	  0      1   2   3
	//	 Реалируйте 2 варианта этого алгоритма: 1. Используйте операторы if	 2. Используйте тернарные операции    ? :
	int x, y;
	for (int x = 0; i < 5; x++){
		if (x <= 1 || x >= 3) {
			y = 0;
		}
		else if (x > 1 && x <=2) {
			y = 2 * x - 2;
		}
		else if (x > 2 && x<3) {
			y = (-2 * x) + 6;
		}
	}
	(x <= 1 || x >= 3) ? y = 0 : ((x > 1 && x <= 2) ? y = 2 * x - 2 : y = (-2 * x) + 6);


	//	Напишите фрагмент, который с помощью for и switch реализует следующую логику. Если пользователь ввел:
	//	символ 'a',   ваш алгоритм выводит  "Ok" (в кавычках)
	//	символ 'b',   ваш алгоритм выводит  Bell (alert - звуковой сигнал)
	//	символ 'с',   ваш алгоритм выводит  число, которое равно количеству введенных символов
	//	символ 'Esc', ваш алгоритм выводит  "to quit use 'q'"
	//	символ 'q',   ваш алгоритм выводит  "Bye" и выходит из цикла ввода
	int counter = 0;
	char ch;
	ch = _getch();
	while (ch != 'q') {
		switch (ch) {
		case 'a': cout << "Ok" << endl;; counter++; break;
		case 'b': cout << "\a"<<endl; counter++; break;
		case 'c': counter++; cout << counter << endl; break;
		case 27: counter += 3; cout << "to quit use 'q'"<<endl; break;
		case 'q': cout << "Bye" << endl; break;
		}
		ch = _getch();

	}

	//	Побитовые операции:  |, &, ~, ^ и сдвиги >>, <<
	//	Поменяйте местами байты переменной flags и выведите результат в консолное окно unsigned short flags = 0xaabb;
	//	Ваш код
	unsigned short flags = 0xaabb; // 1010 1010 1011 1011
	int j = (0xff00 & (flags << 8));
	// 1111 1111 0000 0000 ^ 1011 1011 0000 0000 = 1011 1011 0000 0000 (0xbb00)
	int k = ((flags >> 8) & 0x00ff);
	// 0000 0000 1010 1010 ^ 0000 0000 1111 1111 = 0000 0000 1010 1010 (0x00aa)
	int g = j ^ k;
	// 1011 1011 0000 0000 ^ 0000 0000 1010 1010 = 1011 1011 1010 1010 (0xbbaa)
	cout <<"\nbits = " << bitset<16>(g) << endl << hex << g << endl;
	
	//	Для вывода в шестнадцатеричном виде используйте  cout <<"\n bits = " << hex << flags;
	//	В переменной unsigned char byte = 0x26; установите в единицу 3-й бит (счет от нуля). Выведите результат.
	//	Затем инвертируйте два младших бита. Выведите результат. Обнулите 4 младших бита. Выведите результат
	//	cout <<endl << hex << flags << endl<<dec<<flags;    
	unsigned char byte = 0x26; // 0010 0110
	byte = byte | 0x08;  // 0010 0110 | 0000 1000 = 0010 1110
	byte = byte ^ 0x03;  // 0010 1110 ^ 0000 0011 = 0010 1101
	byte = byte & 0xf0;  // 0010 1101 & 1111 0000 = 0010 0000
	cout <<hex << int(byte) << endl<<dec<<int(byte)<<endl;
	cout << "\n\n";
}	// Конец функции main()

