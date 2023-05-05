//#include <iostream>
//using namespace std;
//struct list
//{
//    int number;
//    list* next;
//};
//
//void insert(list*&, int); //функция добавления элемента, передается адрес списка и символ, который добавляется 
//float del(list*&, int);   //функция удаления, передается адрес списка и символ, который удаляется 
//int IsEmpty(list*);         //функция, которая проверяет, пуст ли список
//void printList(list*);      //функция вывода
//void menu(void);     //функция, показывающая меню
//void sum7(list*);  //функция подсчета положительных суммы чисел  
//
//int main()
//{
//    setlocale(LC_CTYPE, "Russian");
//    list* first = NULL;
//    int choice;
//    float value;
//    menu();    // вывести меню 
//    cout << " ? ";
//    cin >> choice;
//    while (choice != 4)
//    {
//        switch (choice)
//        {
//        case 1:  	cout << "Введите число "; // добавить число в список
//            cin >> value;
//            insert(first, value);
//            printList(first);
//            break;
//        case 2:   if (!IsEmpty(first)) // удалить число из списка
//        {
//            cout << "Введите удаляемое число ";
//            cin >> value;
//            if (del(first, value))
//            {
//                cout << "Удалено число " << value << endl;
//                printList(first);
//            }
//            else
//                cout << "Число не найдено" << endl;
//        }
//              else
//            cout << "Список пуст" << endl;
//            break;
//        case 3:   sum7(first);	// вычисление суммы	
//            break;
//        default:  cout << "Неправильный выбор" << endl;
//            menu();
//            break;
//        }
//        cout << "?  ";
//        cin >> choice;
//    }
//    cout << "Конец" << endl;
//    return 0;
//}
//
//void menu(void)  //Вывод меню 
//{
//    cout << "Сделайте выбор:" << endl;
//    cout << " 1 - Ввод числа" << endl;
//    cout << " 2 - Удаление числа" << endl;
//    cout << " 3 - Вычисление суммы положительных чисел" << endl;
//    cout << " 4 - Выход" << endl;
//}
//
//void insert(list*& p, int value) //Добавление числа value в список 
//{
//    list* newP = new list;
//    if (newP != NULL)     //есть ли место?  
//    {
//        newP->number = value;
//        newP->next = p;
//        p = newP;
//    }
//    else
//        cout << "Операция добавления не выполнена" << endl;
//}
//
//float del(list*& p, int value)  // Удаление числа 
//{
//    list* previous, * current, * temp;
//    if (value == p->number)
//    {
//        temp = p;
//        p = p->next;    // отсоединить узел 
//        delete temp;      //освободить отсоединенный узел 
//        return value;
//    }
//    else
//    {
//        previous = p;
//        current = p->next;
//        while (current != NULL && current->number != value)
//        {
//            previous = current;
//            current = current->next; // перейти к следующему 
//        }
//        if (current != NULL)
//        {
//            temp = current;
//            previous->next = current->next;
//            free(temp);
//            return value;
//        }
//    }
//    return 0;
//}
//
//int IsEmpty(list* p) //Список  пустой? (1-да, 0-нет) 
//{
//    return p == NULL;
//}
//
//
//
//void printList(list* p)  //Вывод списка 
//{
//    if (p == NULL)
//        cout << "Список пуст" << endl;
//    else
//    {
//        cout << "Список:" << endl;
//        while (p != NULL)
//        {
//            cout << "-->" << p->number;
//            p = p->next;
//        }
//        cout << "-->NULL" << endl;
//    }
//}
//
//void sum7(list* p)  // Подсчет суммы положительных чисел  
//{
//    int sm = 0;
//    if (p == NULL)
//        cout << "Список пуст" << endl;
//    else
//    {
//        while (p != NULL)
//        {
//            if (p->number > 0)
//                sm = sm + (p->number);
//            p = p->next;
//        }
//        cout << "Сумма = " << sm << endl;
//    }
//}




///Вариант5
#include <iostream>
using namespace std;
struct list
{
    int number;
    list* next;
};

void insert(list*&, int); //функция добавления элемента, передается адрес списка и символ, который добавляется 
float del(list*&, int);   //функция удаления, передается адрес списка и символ, который удаляется 
int IsEmpty(list*);         //функция, которая проверяет, пуст ли список
void printList(list*);      //функция вывода
void menu(void);     //функция, показывающая меню
void sum7(list*);  //функция подсчета суммы чисел 

int main()
{
    setlocale(LC_CTYPE, "Russian");
    list* first = NULL;
    int choice;
    float value;
    menu();    // вывести меню 
    cout << " ? ";
    cin >> choice;
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:  	cout << "Введите число "; // добавить число в список
            cin >> value;
            insert(first, value);
            printList(first);
            break;
        case 2:   if (!IsEmpty(first)) // удалить число из списка
        {
            cout << "Введите удаляемое число ";
            cin >> value;
            if (del(first, value))
            {
                cout << "Удалено число " << value << endl;
                printList(first);
            }
            else
                cout << "Число не найдено" << endl;
        }
              else
            cout << "Список пуст" << endl;
            break;
        case 3:   sum7(first);	// вычисление суммы	
            break;
        default:  cout << "Неправильный выбор" << endl;
            menu();
            break;
        }
        cout << "?  ";
        cin >> choice;
    }
    cout << "Конец" << endl;
    return 0;
}

void menu(void)  //Вывод меню 
{
    cout << "Сделайте выбор:" << endl;
    cout << " 1 - Ввод числа" << endl;
    cout << " 2 - Удаление числа" << endl;
    cout << " 3 - Вычисление суммы положительных чисел меньше 100" << endl;
    cout << " 4 - Выход" << endl;
}

void insert(list*& p, int value) //Добавление числа value в список 
{
    list* newP = new list;
    if (newP != NULL)     //есть ли место?  
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}

float del(list*& p, int value)  // Удаление числа 
{
    list* previous, * current, * temp;
    if (value == p->number)
    {
        temp = p;
        p = p->next;    // отсоединить узел 
        delete temp;      //освободить отсоединенный узел 
        return value;
    }
    else
    {
        previous = p;
        current = p->next;
        while (current != NULL && current->number != value)
        {
            previous = current;
            current = current->next; // перейти к следующему 
        }
        if (current != NULL)
        {
            temp = current;
            previous->next = current->next;
            free(temp);
            return value;
        }
    }
    return 0;
}

int IsEmpty(list* p) //Список  пустой? (1-да, 0-нет) 
{
    return p == NULL;
}



void printList(list* p)  //Вывод списка 
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void sum7(list* p)  // Подсчет суммы положительных чисел  
{
    int sm = 0;
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number > 9 && p->number < 100)
                sm = sm + (p->number);
            p = p->next;
        }
        cout << "Сумма = " << sm << endl;
    }
}



//////Вариант10
//#include <iostream>
//using namespace std;
//struct list
//{
//    int number;
//    list* next;
//};
//
//void insert(list*&, int); //функция добавления элемента, передается адрес списка и символ, который добавляется 
//float del(list*&, int);   //функция удаления, передается адрес списка и символ, который удаляется 
//int IsEmpty(list*);         //функция, которая проверяет, пуст ли список
//void printList(list*);      //функция вывода
//void menu(void);     //функция, показывающая меню
//void sum7(list*);  //функция подсчета суммы чисел 
//
//int main()
//{
//    setlocale(LC_CTYPE, "Russian");
//    list* first = NULL;
//    int choice;
//    float value;
//    menu();    // вывести меню 
//    cout << " ? ";
//    cin >> choice;
//    while (choice != 4)
//    {
//        switch (choice)
//        {
//        case 1:  	cout << "Введите число "; // добавить число в список
//            cin >> value;
//            insert(first, value);
//            printList(first);
//            break;
//        case 2:   if (!IsEmpty(first)) // удалить число из списка
//        {
//            cout << "Введите удаляемое число ";
//            cin >> value;
//            if (del(first, value))
//            {
//                cout << "Удалено число " << value << endl;
//                printList(first);
//            }
//            else
//                cout << "Число не найдено" << endl;
//        }
//              else
//            cout << "Список пуст" << endl;
//            break;
//        case 3:   sum7(first);	// вычисление суммы	
//            break;
//        default:  cout << "Неправильный выбор" << endl;
//            menu();
//            break;
//        }
//        cout << "?  ";
//        cin >> choice;
//    }
//    cout << "Конец" << endl;
//    return 0;
//}
//
//void menu(void)  //Вывод меню 
//{
//    cout << "Сделайте выбор:" << endl;
//    cout << " 1 - Ввод числа" << endl;
//    cout << " 2 - Удаление числа" << endl;
//    cout << " 3 - Вычисление произведения чисел меньше 10" << endl;
//    cout << " 4 - Выход" << endl;
//}
//
//void insert(list*& p, int value) //Добавление числа value в список 
//{
//    list* newP = new list;
//    if (newP != NULL)     //есть ли место?  
//    {
//        newP->number = value;
//        newP->next = p;
//        p = newP;
//    }
//    else
//        cout << "Операция добавления не выполнена" << endl;
//}
//
//float del(list*& p, int value)  // Удаление числа 
//{
//    list* previous, * current, * temp;
//    if (value == p->number)
//    {
//        temp = p;
//        p = p->next;    // отсоединить узел 
//        delete temp;      //освободить отсоединенный узел 
//        return value;
//    }
//    else
//    {
//        previous = p;
//        current = p->next;
//        while (current != NULL && current->number != value)
//        {
//            previous = current;
//            current = current->next; // перейти к следующему 
//        }
//        if (current != NULL)
//        {
//            temp = current;
//            previous->next = current->next;
//            free(temp);
//            return value;
//        }
//    }
//    return 0;
//}
//
//int IsEmpty(list* p) //Список  пустой? (1-да, 0-нет) 
//{
//    return p == NULL;
//}
//
//
//
//void printList(list* p)  //Вывод списка 
//{
//    if (p == NULL)
//        cout << "Список пуст" << endl;
//    else
//    {
//        cout << "Список:" << endl;
//        while (p != NULL)
//        {
//            cout << "-->" << p->number;
//            p = p->next;
//        }
//        cout << "-->NULL" << endl;
//    }
//}
//
//void sum7(list* p)  // Подсчет суммы положительных чисел  
//{
//    int sm = 0;
//    if (p == NULL)
//        cout << "Список пуст" << endl;
//    else
//    {
//        while (p != NULL)
//        {
//            if (p->number > 10)
//                sm = sm * (p->number);
//            p = p->next;
//        }
//        cout << "Сумма = " << sm << endl;
//    }
//}



//////Вариант2
//#include <iostream>
//using namespace std;
//struct list
//{
//    int number;
//    list* next;
//};
//
//void insert(list*&, int); //функция добавления элемента, передается адрес списка и символ, который добавляется 
//float del(list*&, int);   //функция удаления, передается адрес списка и символ, который удаляется 
//int IsEmpty(list*);         //функция, которая проверяет, пуст ли список
//void printList(list*);      //функция вывода
//void menu(void);     //функция, показывающая меню
//void sum7(list*);  //функция подсчета суммы чисел 
//
//int main()
//{
//    setlocale(LC_CTYPE, "Russian");
//    list* first = NULL;
//    int choice;
//    float value;
//    menu();    // вывести меню 
//    cout << " ? ";
//    cin >> choice;
//    while (choice != 4)
//    {
//        switch (choice)
//        {
//        case 1:  	cout << "Введите число "; // добавить число в список
//            cin >> value;
//            insert(first, value);
//            printList(first);
//            break;
//        case 2:   if (!IsEmpty(first)) // удалить число из списка
//        {
//            cout << "Введите удаляемое число ";
//            cin >> value;
//            if (del(first, value))
//            {
//                cout << "Удалено число " << value << endl;
//                printList(first);
//            }
//            else
//                cout << "Число не найдено" << endl;
//        }
//              else
//            cout << "Список пуст" << endl;
//            break;
//        case 3:   sum7(first);	// вычисление суммы	
//            break;
//        default:  cout << "Неправильный выбор" << endl;
//            menu();
//            break;
//        }
//        cout << "?  ";
//        cin >> choice;
//    }
//    cout << "Конец" << endl;
//    return 0;
//}
//
//void menu(void)  //Вывод меню 
//{
//    cout << "Сделайте выбор:" << endl;
//    cout << " 1 - Ввод числа" << endl;
//    cout << " 2 - Удаление числа" << endl;
//    cout << " 3 - Вычисление среднее значение положительных чисел" << endl;
//    cout << " 4 - Выход" << endl;
//}
//
//void insert(list*& p, int value) //Добавление числа value в список 
//{
//    list* newP = new list;
//    if (newP != NULL)     //есть ли место?  
//    {
//        newP->number = value;
//        newP->next = p;
//        p = newP;
//    }
//    else
//        cout << "Операция добавления не выполнена" << endl;
//}
//
//float del(list*& p, int value)  // Удаление числа 
//{
//    list* previous, * current, * temp;
//    if (value == p->number)
//    {
//        temp = p;
//        p = p->next;    // отсоединить узел 
//        delete temp;      //освободить отсоединенный узел 
//        return value;
//    }
//    else
//    {
//        previous = p;
//        current = p->next;
//        while (current != NULL && current->number != value)
//        {
//            previous = current;
//            current = current->next; // перейти к следующему 
//        }
//        if (current != NULL)
//        {
//            temp = current;
//            previous->next = current->next;
//            free(temp);
//            return value;
//        }
//    }
//    return 0;
//}
//
//int IsEmpty(list* p) //Список  пустой? (1-да, 0-нет) 
//{
//    return p == NULL;
//}
//
//
//
//void printList(list* p)  //Вывод списка 
//{
//    if (p == NULL)
//        cout << "Список пуст" << endl;
//    else
//    {
//        cout << "Список:" << endl;
//        while (p != NULL)
//        {
//            cout << "-->" << p->number;
//            p = p->next;
//        }
//        cout << "-->NULL" << endl;
//    }
//}
//
//void sum7(list* p)  // Подсчет суммы положительных чисел  
//{
//    int sm = 0; int i = 0;
//    if (p == NULL)
//        cout << "Список пуст" << endl;
//    else
//    {
//        while (p != NULL)
//        {
//            if (p->number > 0)
//            {
//                sm = sm + (p->number);
//                i++;
//            }
//            p = p->next;
//        }
//        cout << "Сумма = " << sm << endl;
//        cout << "Среднее арифметическое :" << (sm / i) << endl;
//    }
//}












//#include <iostream>
//using namespace std;
//struct Item {
//	int a;
//	Item* next;
//};
//void list(Item*&, int);
//void vivod(Item*);
//
//void main(){
//	setlocale(LC_ALL, "Russian");
//	int choice;
//	int lox;
//	Item* first = NULL;
//	cout << "Enter variant:" << endl;
//	cin >> lox;
//	while(lox != 'x')
//	{
//		cout << "Enter number: ";
//			cin >> lox;
//			list(first, lox);
//			vivod(first);
//	}
//}
//void list(Item*& p, int num) {
//	Item* newP = new Item;
//	if (newP != NULL) {
//		newP->a = num;
//		newP->next = p;
//		p = newP;
//	}
//	else
//		cout << "error!";
//}
//void vivod(Item* p) {
//	if (p == NULL)
//		cout << "This is the end of list!";
//	else {
//		cout << "List: \t";
//		while (p != NULL) {
//			cout << "-->" << p->a;
//			p = p->next;
//		}
//		cout << "-->NULL" << endl;
//	}
//}