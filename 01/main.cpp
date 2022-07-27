#include <iostream>
#include <string>

class Figure {
public:
	Figure() {
		name = "Фигура";
		side = 0;
	}
	std::string GetName() {
		return this->name;
	}
	int GetNumberSides() {
		return this->side;
	}
protected:
	int side;
	std::string name;
};

class Triangle : public Figure {
public:
	Triangle() {
		name = "Треугольник";
		side = 3;
	}
};

class Quadrilateral : public Figure {
public:
	Quadrilateral() {
		name = "Четырехугольник";
		side = 4;
	}
};

void ShowInfoFigure(Figure* figure) {
	std::cout << figure->GetName() << ": " << figure->GetNumberSides() << std::endl;
}

int main(int argc, char** argv) {

	setlocale(LC_ALL, "ru");

	Figure circle;
	Triangle tABC;
	Quadrilateral qABCD;

	std::cout << "Количество сторон: " << std::endl;

	ShowInfoFigure(&circle);
	ShowInfoFigure(&tABC);
	ShowInfoFigure(&qABCD);


	return 0;
}