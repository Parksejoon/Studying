#include <iostream>
#include "Color.h"

// ������
Color::Color(void)
{
	SetRGB(defR, defG, defB);
}

Color::Color(element_t R, element_t G, element_t B)
{
	SetRGB(R, G, B);
}

// ������
void Color::SetR(element_t var)
{
	R = Color::PutInRange(var);
}

void Color::SetG(element_t var)
{
	G = Color::PutInRange(var);
}

void Color::SetB(element_t var)
{
	B = Color::PutInRange(var);
}

Color::element_t Color::GetR(void) const
{
	return R;
}

Color::element_t Color::GetG(void) const
{
	return G;
}

Color::element_t Color::GetB(void) const
{
	return B;
}

// ��ü ��� ��ȭ
void Color::AdjustBright(int delta)
{
	SetRGB(R + delta, G + delta, B + delta);
}

// RGB �ѹ��� �ٲٱ�
void Color::SetRGB(element_t R, element_t G, element_t B)
{
	SetR(R);
	SetG(G);
	SetB(B);
}

// ������ ����� ��
int Color::PutInRange(int val)
{
	if (val <= 0)
	{
		val = 0;
	}
	else if (val >= 255)
	{
		val = 255;
	}

	return val;
}

// ���
void Color::Print(bool endLine) const
{
	std::cout << "< R = " << (int)R << ", G = " << (int)G << ", B = " << (int)B << " >";
	if (endLine)
	{
		std::cout << "\n";
	}
}

// ���� ����ϴ� ��
const Color Color::Black(0, 0, 0);
const Color Color::White(255, 255, 255);