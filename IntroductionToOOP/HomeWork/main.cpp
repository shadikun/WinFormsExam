#include<iostream>

using namespace std;

class S_Fraction
{
private:
	int Numerator;
	int Denominator;
	int WholePart;
public:
	S_Fraction(int n = 0, int d = 1, int w = 0)
	{
		this->Numerator = n;
		this->Denominator = d;
		this->WholePart = w;
		cout << "Constructor:\t" << this << endl;
	}
	~S_Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	int getNumerator() const
	{
		return Numerator;
	}
	int getDenominator() const
	{
		return Denominator;
	}
	int getWholePart() const
	{
		return WholePart;
	}

	double get_decimal()	// получение дроби в типе double для сравнений на <, <=, >, >=
	{
		double result = (double)(WholePart * Denominator + Numerator) / Denominator;
		return result;
	}
	void set_Numerator(int n)
	{
		this->Numerator = n;
	}
	void set_Denominator(int d)
	{
		if (d == 0)
		{
			cout << "Знаменатель не может быть нулем. На ноль делить нельзя!" << endl;
			while (d <= 0)
			{
				cout << "Введите новое положительное значение знаменателя: ";
				cin >> d;
				cout << endl;
			}
			this->Denominator = d;
		}
		else
		{
			this->Denominator = d;
		}
	}
	void set_Whole_part(int w)
	{
		if (Numerator >= Denominator)
		{
			this->WholePart = w;
			WholePart += (Numerator / Denominator);
			Numerator %= Denominator;
		}
		else this->WholePart = 0;
	}

	void getIntPart()	//выделение целой части дроби
	{
		if (Numerator >= Denominator)
		{
			WholePart += (Numerator / Denominator);
			Numerator %= Denominator;
		}
	}
	void Cancellation()	//сокращение дроби
	{
		if (Numerator != 0)
		{
			int m = Denominator,
				n = Numerator,
				rest = m % n;
			while (rest != 0)
			{
				m = n; n = rest;
				rest = m % n;
			}
			int nod = n;
			if (nod != 1)
			{
				Numerator /= nod; Denominator /= nod;
			}
		}
	}
	void GetMixedView()				//выделение целой части + сокращение дроби
	{
		getIntPart();
		Cancellation();
	}

	S_Fraction& operator=(const S_Fraction& other)
	{
		this->Numerator = other.Numerator;
		this->Denominator = other.Denominator;
		this->WholePart = other.WholePart;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	S_Fraction& operator+(const S_Fraction& other)
	{
		S_Fraction result;
		result.Numerator = (this->WholePart*this->Denominator + this->Numerator)*other.Denominator +
			(other.WholePart*other.Denominator + other.Numerator)*this->Denominator;
		result.Denominator = this->Denominator*other.Denominator;
		result.GetMixedView();
		return result;
	}
	S_Fraction& operator-(const S_Fraction& other)
	{
		S_Fraction result;
		result.Numerator = (this->WholePart*this->Denominator + this->Numerator)*other.Denominator -
			(other.WholePart*other.Denominator + other.Numerator)*this->Denominator;
		result.Denominator = this->Denominator*other.Denominator;
		result.GetMixedView();
		return result;
	}
	S_Fraction operator*(const S_Fraction& other)
	{
		S_Fraction result;
		result.Numerator = (this->WholePart*this->Denominator + this->Numerator)*
			(other.WholePart*other.Denominator + other.Numerator);
		result.Denominator = this->Denominator*other.Denominator;
		result.GetMixedView();
		return result;
	}
	S_Fraction operator/(const S_Fraction& other)
	{
		S_Fraction result;
		result.Numerator = (this->WholePart*this->Denominator + this->Numerator)*other.Denominator;
		result.Denominator = this->Denominator*(other.WholePart*other.Denominator + other.Numerator);
		result.GetMixedView();
		return result;
	}

	bool operator ==(const S_Fraction& other)
	{
		if (this->WholePart != other.WholePart || this->Numerator * other.Denominator !=
			this->Denominator * other.Numerator)
			return false;
		return true;
	}
	bool operator !=(const S_Fraction& other)
	{
		if (this->WholePart == other.WholePart && this->Numerator * other.Denominator ==
			this->Denominator * other.Numerator)
			return false;
		return true;
	}
	bool operator > (const S_Fraction& other)
	{
		double result1 = (double)(this->WholePart * this->Denominator + this->Numerator) / this->Denominator;
		double result2 = (double)(other.WholePart * other.Denominator + other.Numerator) / other.Denominator;
		if (result1 <= result2) return false;
		else return true;
	}
	bool operator < (const S_Fraction& other)
	{
		double result1 = (double)(this->WholePart * this->Denominator + this->Numerator) / this->Denominator;
		double result2 = (double)(other.WholePart * other.Denominator + other.Numerator) / other.Denominator;
		if (result1 >= result2) return false;
		else return true;
	}
	bool operator >= (const S_Fraction& other)
	{
		double result1 = (double)(this->WholePart * this->Denominator + this->Numerator) / this->Denominator;
		double result2 = (double)(other.WholePart * other.Denominator + other.Numerator) / other.Denominator;
		if (result1 < result2) return false;
		else return true;
	}
	bool operator <= (const S_Fraction& other)
	{
		double result1 = (double)(this->WholePart * this->Denominator + this->Numerator) / this->Denominator;
		double result2 = (double)(other.WholePart * other.Denominator + other.Numerator) / other.Denominator;
		if (result1 > result2) return false;
		else return true;
	}

	friend ostream& operator << (ostream& out, S_Fraction a);
};
	ostream& operator << (ostream& out, S_Fraction a)
	{
		if (a.getWholePart() != 0)
			out << a.getWholePart() << " ";
		if (a.getNumerator() != 0)
			out << a.getNumerator() << "/" << a.getDenominator();
		if (a.getWholePart() == 0 && a.getNumerator() == 0)
			out << "0";
		else out << " ";
		return out;
	}



void main()
{
	setlocale(LC_ALL, "");
	S_Fraction A;
	A.set_Numerator(5);
	A.set_Denominator(10);
	A.set_Whole_part(0);
	//cout << "Вывод объекта А в виде простой дроби: "<<A<<endl;


	S_Fraction B;
	B.set_Numerator(1);
	B.set_Denominator(2);
	B.set_Whole_part(0);
	/*cout << "Вывод объекта B в виде простой дроби: " << B << endl;

	cout << "Результат сложения двух дробей: "<<A+B<<endl;
	cout << "Результат вычитания двух дробей: " << A - B << endl;
	cout<< "Результат умножения двух дробей: " << A * B << endl;
	cout << "Результат деления двух дробей: " << A / B << endl;
	cout << "Дробь " << A << "равна " << B <<": "<<(A == B) << endl;
	cout << "Дробь " << A << "неравна " << B << ": " << (A != B) << endl;
	cout << "Дробь " << A << "неравна " << B << ": " << (A != B) << endl;*/
	if (A >= B) cout << "Дробь " << A << "больше или равна дроби " << B << endl;
	else cout << "Дробь " << A << "меньше дроби " << B << endl;

}