#include <iostream>
#include <string>
#include <math.h>
#define OUTPUT_ITEMS_SIZE 6

void string_serch_in_ascii();
//овтеты к заданию номер (1):
/*
	1): 
		c -- strlen: [определения длинны строки от начала до последнего 'нуль терминатора'];
		c++ -- strlen : [функция аналогична языку c];
	2): 
		c -- strcpy: 
		[
			.копирует строку в буфер
			.имеет два параметра:
				
				.указатель на строку в которую мы хотим скопировать изначальную
				.изначальная строка для копирования
			
		];

		с++ -- strcpy: [функция аналогична языку с];
	
	3): 
		c -- strcmp:
		[
			.сравнивает две строки
			.имеет два параметра:
				
				.первая строка для сравнивания
				.вторая строка для сравнивания

			.возвращает:
				
				.значение < 0: если первая строка меньше чем вторая по значению символов в таблице ASCII
				.значение 0: если первая строка равна второй 
				.значение > 0: если первая строка больше чем вторая

		];
		с++ -- strcmp: [функция аналогична что в с, что в с ++];

	4):
		c -- strcat: 
		[
			.функция объединяет две строки добавляя вторую к первой;
			.имеет два парметра указатель на первую строку и на вторую: char* string_one и const char* string_two;

		];
		c++ -- strcat: [функция не иммет отличий за исключеним принимаемых парметров: const chat* string_one и const char* string_two];

	5):
		получение элемента по индексу строки, работает одинакого что в C, что в C++. В обоих языках исользуется один формат си-строк;

	6):
		c++ -- std::string str_object.push_bach(template T: {T| char or char*}): [добавляет char или char* в конец строк str_object];
		c -- в си за место данной функции используется strcat;

	7):
		c++ -- std::string str_object.pop_back(none): [функция удаляет последний элемент строки типа char]
		c -- [нет аналогов, вместо данной функции используе тся индексный способ например: string[strlen(string) - 1] = "\0"]
		
*/		

/*
	1):
		c -- int *ptr = (int*)malloc(sizeof(int)): [выделение динамической памяти для одного int объекта];
		с -- int *ptr{ new int [sizeof(int)] }: тоже самое на ++;
	2):
		c -- int *ptrArr = (int*)malloc(sizeof(int) * N): [выделение динамической памяти под n int объктов];
		c++ -- int *ptrAtt{ new int [sizeof(int) * N]}: тоже самое на ++;
	3):
		c -- free(ptr): [освобождение памяти от одного int объекта];
		c++ -- delete ptr: [тоже самое на ++];
	4): 
		c -- free(ptrArr): [освобождение памяти от n int объектов];
		c++ -- delete [] prt: [тоже самое на ++];

	вопрос номер (1):
		-нжуно, потому что если этого не делать то стек памяти переполниться, это приведет к ошибки во время исоплнения.
	вопрос номер (2):
		-можно но это может привести к ошибкам ведь по сути память адресс в памяти уже пуст.
	вопрос номер (3):
		-можно но может привети к ошибкам
*/

//задание номер (1):
void string_serch_in_ascii()
{	
	char tmp_char;
	std::string vocube{ "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz" };
	std::string deletable_items{ "?.,_-" };
	std::string serchin_string{};

	std::string pretty_output_item{};
	pretty_output_item.resize(OUTPUT_ITEMS_SIZE);

	std::cout << "\n" << pretty_output_item << "[input the string for serhcing]" << pretty_output_item << "\n";
	std::cin >> serchin_string;

	for (int item_index{ 0 }; item_index < serchin_string.size(); item_index++)
	{
		int min_index = 1000000;
		if (deletable_items.find(serchin_string.at(item_index)) != std::string::npos)
		{
			serchin_string.erase(item_index, 1);
		}
		else
		{
			for (int min_sercher{ item_index }; min_sercher < serchin_string.size(); min_sercher++)
			{
				if (min_index > serchin_string.find(min_sercher))
				{
					min_index = serchin_string.find(min_sercher);
				}
			}
			tmp_char = serchin_string.at(item_index);
			serchin_string.at(item_index) = serchin_string.at(min_index);
			serchin_string.at(min_index) = tmp_char;
			
		}
	}

	std::cout << "\n" << "[!STRING WAS RESERCH!]" << "\n";
	std::cout << serchin_string;
}

int main()
{
	string_serch_in_ascii();
	return 0;
}