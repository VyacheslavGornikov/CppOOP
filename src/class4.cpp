#include <iostream>

class PointND {
	unsigned total {0};
	int *coords {nullptr};
public:
PointND() : total(0), coords(nullptr)
	{ }
PointND(unsigned sz) : total(sz)
{
	coords = new int[total] {0};
}

/* PointND(int* cr, unsigned len) : total(len) возникает дублироание с
   PointND(unsigned sz) : total(sz), поэтому вместо total(len) лучше подставить
   конструктор PointND(unsigned sz) : total(sz) -> PointND (len)
   Здесь PointND(int* cr, unsigned len) - делегирующий конструктор*/
PointND(int* cr, unsigned len) : PointND (len)
{
	// coords = new int[total]; // после PointND (len) это не нужно
	set_coords(cr, len);
}

/* Конструктор копирования для PointND pt2 {pt}; */
PointND (const PointND& other) : PointND (other.coords, other.total)
{
	/* Аналогично предыдущему делегирующему конструктору,
	   PointND (const PointND& other) использует 2 предыдущих => код ниже
	   уже не нужен */
	// coords = new int[total];
	// set_coords (other.coords, total);
}

/* Вызывается при уничтожении объекта и освобождает память */
~PointND()
{
	delete[] coords;
}

unsigned get_total() { return total; }
const int* get_coords() { return coords; }
void set_coords(int* cr, unsigned len)
{
	for(unsigned i = 0; i < total; ++i)
		coords[i] = (i < len) ? cr[i] : 0;
}

/* Переопределяем оператор присвоения */
const PointND& operator= (const PointND& other)
{
	if (this == &other)
		return *this;

	delete[] coords; /* Если nullptr, то delete не выполняется */
	total = other.total;
	coords = new int[total];
	set_coords (other.coords, total);

	return *this;
}

};

int main()
{
	PointND pt(5);
	PointND pt2 {pt};

	PointND pt3 (3);
	PointND pt4;

	/* Это операция присваивания, конструктор копирования не вызывается */
	pt4 = pt3;

	std :: cout << pt3.get_total() << std :: endl;

	return 0;
}