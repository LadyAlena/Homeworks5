#include <iostream>
#include <string>

class Figure {
public:

	Figure() {
		name = "Фигура";
		side = 0;
	}

	virtual bool checkFigure() {

		bool сondition = this->side == 0 ? true : false;

		return сondition;
	}

	int GetCountSides() {
		return this->side;
	}

	std::string GetName() {
		return this->name;
	}

	virtual void GetSides() {};

	virtual void GetAngles() {};

	void showInfoFigure() {
		std::cout << GetName() << ": " << std::endl;
		std::cout << (checkFigure() ? "Правильная" : "Неправильная") << std::endl;
		std::cout << "Количество сторон: " << GetCountSides() << std::endl;
		GetSides();
		GetAngles();
		std::cout << std::endl;
	}

protected:
	std::string name;
	int side;
};


//Треугольники

class Triangle : public Figure {
public:
	Triangle(int a, int b, int c, int A, int B, int C) {
		name = "Треугольник";
		side = 3;
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
	}

	bool checkFigure() override {

		bool condition = A + B + C == 180 ? true : false;

		return condition;
	}

	void GetSides() override {
		std::cout << "Стороны: " << "a = " << a << " b = " << b << " c = " << c << std::endl;
	}

	void GetAngles() override {
		std::cout << "Углы: " << "A = " << A << " B = " << B << " C = " << C << std::endl;
	}

protected:
	int a;
	int b;
	int c;
	int A;
	int B;
	int C;
};

class RightTriangle : public Triangle {
public:
	RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
		name = "Прямоугольный треугольник";
	}

	bool checkFigure() override {

		bool condition = Triangle::checkFigure() && (C == 90 ? true : false)

		return condition;
	}

};

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(int LengthAandC,  int b, int valueAnglesAandC, int B) : Triangle(LengthAandC, b, LengthAandC, valueAnglesAandC, B, valueAnglesAandC) {
		name = "Равнобедренный треугольник";
	}

	bool checkFigure() override {

		bool condition = Triangle::checkFigure() && (a == c && A == C ? true : false)

		return condition;
	}

};

class EquilateraltTriangle : public Triangle {
public:
	EquilateraltTriangle(int LengthSide) : Triangle(LengthSide, LengthSide, LengthSide, 60, 60, 60) {
		name = "Равносторонний треугольник";
	}

	bool checkFigure() override {

		bool condition = Triangle::checkFigure() && ((a == c && a == b && b == c) && (A == C && A == B && B == C) ? true : false);

		return condition;
	}
};

// Четырехугольник

class Quadrilateral : public Figure {
public:
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) {
		name = "Четырехугольник";
		side = 4;
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}

	bool checkFigure() override {

		bool condition = (A + B + C + D == 360 ? true : false);

		return condition;
	}

	void GetSides() override {
		std::cout << "Стороны: " << "a = " << a << " b = " << b << " c = " << c << " d = " << d << std::endl;
	}

	void GetAngles() override {
		std::cout << "Углы: " << "A = " << A << " B = " << B << " C = " << C << " D = " << D << std::endl;
	}

protected:
	int a;
	int b;
	int c;
	int d;
	int A;
	int B;
	int C;
	int D;
};

class Parallelogram : public Quadrilateral {
public:
	Parallelogram(int LengthAandC, int LengthBandD, int AnglesAandC, int AnglesBandD) : Quadrilateral(LengthAandC, LengthBandD, LengthAandC, LengthBandD, AnglesAandC, AnglesBandD, AnglesAandC, AnglesBandD) {
		name = "Параллелограмм";
	}

	bool checkFigure() override {

		bool condition = Quadrilateral::checkFigure() && ((a == c && b == d) && (A == C && B == D) ? true : false);

		return condition;
	}

};

class Rectangle : public Parallelogram {
public:
	Rectangle(int LengthAandC, int LengthBandD) : Parallelogram(LengthAandC, LengthBandD, 90, 90) {
		name = "Прямоугольник";
	}
};

class Rhomb : public Parallelogram {
public:
	Rhomb(int LengthSides, int AnglesAandC, int AnglesBandD) : Parallelogram(LengthSides, LengthSides, AnglesAandC, AnglesBandD) {
		name = "Ромб";
	}
};

class Square : public Rectangle {
public:
	Square(int LengthSides) : Rectangle(LengthSides, LengthSides) {
		name = "Квадрат";
	}
};

void GetInfoAboutFigure(Figure* figure) {
	figure->showInfoFigure();
}

int main(int argc, char** argv) {

	setlocale(LC_ALL, "ru");

	Figure figure;
	GetInfoAboutFigure(&figure);

	Triangle tABC(10, 20, 30, 50, 60, 70);
	GetInfoAboutFigure(&tABC);

	RightTriangle rtABC(10, 20, 30, 50, 50);
	GetInfoAboutFigure(&rtABC);

	IsoscelesTriangle itABC(10, 50, 80, 20);
	GetInfoAboutFigure(&itABC);

	EquilateraltTriangle etABC(70);
	GetInfoAboutFigure(&etABC);

	Quadrilateral ABCD(10, 20, 30, 40, 50, 60, 70, 80);
	GetInfoAboutFigure(&ABCD);

	Parallelogram pABCD(20, 45, 50, 130);
	GetInfoAboutFigure(&pABCD);

	Rectangle rABCD(56, 78);
	GetInfoAboutFigure(&rABCD);

	Rhomb rhombABCD(50, 120, 60);
	GetInfoAboutFigure(&rhombABCD);

	Square sABCD(67);
	GetInfoAboutFigure(&sABCD);


	return 0;
}