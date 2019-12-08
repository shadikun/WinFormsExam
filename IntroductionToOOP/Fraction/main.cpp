#include<iostream>
using namespace std;

//#define CONSTRUCTORS_CHECK
#define OPERATORS_CHECK

class Fraction
{
	//Описывает простую дробь.
	int integer;	//Целая часть
	int numerator;	//Числитель
	int denominator;//Знаменатель
public:
	int get_integer() const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator != 0)
		{
			this->denominator = denominator;
		}
		else
		{
			this->denominator = 1;
		}
	}

	//		Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstruct:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgumentConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->denominator = denominator ? denominator : 1;
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator ? denominator : 1;
		/*
			condition ? expression1 : expression2;
		*/
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		//*this = other;
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//		Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:" << this << endl;
		return *this;
	}

	Fraction operator*(Fraction right) const
	{
		Fraction left = *this;
		left.to_improper();
		right.to_improper();
		Fraction result;
		result.numerator = left.numerator*right.numerator;
		result.denominator = left.denominator*right.denominator;
		result.to_proper();
		return result;
	}

	//		Methods:
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}

	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer -= integer;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result(left.get_numerator()*right.get_numerator(), left.get_denominator()*right.get_denominator());
	/*result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	//result.to_proper();
	return result.to_proper();
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	double a = 5;
	cout << a << endl;

	Fraction A;		//Default constructor
	A.print();

	Fraction B = 5;	//Single argument constructor
	B.print();

	Fraction C(1, 2);//Constructor
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;	//CopyConstructor
	E.print();

	Fraction F;
	F = E;
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATORS_CHECK
	Fraction A(2, 1, 2);
	Fraction B(3, 4, 5);
	A.print();
	B.print();
	Fraction C = A * B;
	C.print();
	A.print();
	B.print();

	double a = 2.5;
	double b = 3.14;
	double c = a * b;
#endif
}