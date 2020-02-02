#include<iostream>

class ForwardList
{
	class Element
	{
		int Data;
		Element* pNext;
		static int count;
	public:
		Element(int Data, Element* pNext = nullptr)
		{
			this->Data = Data;
			this->pNext = pNext;
			count++;
			std::cout << "EConstructor:\t" << this << std::endl;
		}
		~Element()
		{
			count--;
			std::cout << "EDestructor:\t" << this << std::endl;
		}
		friend class ForwardList;
	};

	Element* Head;
	int size;
public:
	ForwardList()
	{
		this->Head = nullptr;
		this->size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	explicit ForwardList(int size):ForwardList()
	{
		while (size--)push_front(0);
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	ForwardList(std::initializer_list<int> il) :ForwardList()
	{
		std::cout << typeid(il.begin()).name() << std::endl;
		for (int const *it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
		std::cout << "ILconstructor:\t" << this << std::endl;
	}
	~ForwardList()
	{
		while (Head)pop_front();
		std::cout << "LDestructor:\t" << this << std::endl;
	}

	//				Operators:
	int& operator[](int index)
	{
		Element* Temp = Head;
		for (int i = 0; i < index; i++)Temp = Temp->pNext;
		return Temp->Data;
	}

	//				Methods:
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Element* New = new Element(Data);
		Temp->pNext = New;
		size++;
	}
	void insert(int Index, int Data)
	{
		if (Index == 0)
		{
			push_front(Data);
			return;
		}
		if (Index > size)
		{
			std::cout << "Error: Out of range" << std::endl;
			return;
		}
		//1) Создаем элемент:
		Element* New = new Element(Data);
		//2) Доходим до нужной позиции в списке:
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		//3) Вставляем новый элемент в список:
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}

	void pop_front()
	{
		Element* Temp = Head;
		Head = Head->pNext;
		delete Temp;
		size--;
	}

	void pop_back()
	{
		//Удаление элемента с конца списка.
		Element* Temp = Head;
		while (Temp->pNext->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}

	void erase(int index)
	{
		if (index == 0)
		{
			pop_front();
			return;
		}
		if (index >= size)
		{
			std::cout << "Error: Out of range" << std::endl;;
			return;
		}
		/*if (index == size - 1)
		{
			pop_back();
			return;
		}*/
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		Element* buffer = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete buffer;
		size--;
	}

	//			methods:
	void print()
	{
		Element* Temp = Head;	//Temp - это итератор.
								//Итератор - это указатель, при помощи которого 
								//можно получить доступ к элементам структуры данных.
		while (Temp != nullptr)
		{
			std::cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << std::endl;
			Temp = Temp->pNext;	//Переход на следующий элемент.
		}
		std::cout << "List size:\t" << size << std::endl;
	}
};

int ForwardList::Element::count = 0;

//#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "");

	int n;
	//std::cout << "Input list size: "; std::cin >> n;
#ifdef BASE_CHECK
	ForwardList fl;
	for (int i = 0; i < n; i++)
	{
		fl.push_back(rand() % 100);
	}
	//fl.push_back(123);
	fl.print();

	int index;
	int data;

	/*std::cout << "Input index: "; std::cin >> index;
	std::cout << "Input value: "; std::cin >> data;
	fl.insert(index, data);
	fl.print();*/

	/*fl.pop_front();
	fl.pop_back();
	fl.print();*/

	/*std::cout << "Input index: "; std::cin >> index;
	fl.erase(index);
	fl.print();*/
#endif // BASE_CHECK
	
	/*int a = 2;
	double b = 3;
	ForwardList list1(5);
	for (int i = 0; i < n; i++)
	{
		list1[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << list1[i] << "\t";
	}
	std::cout << std::endl;*/

	ForwardList list1 = { 3, 5, 8, 13, 21 };
	list1.print();
}