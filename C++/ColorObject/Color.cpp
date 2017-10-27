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

// RGB�� 32��Ʈ ������ ��ȯ
void Color::SetColor32(color32_t var)
{

}

Color::color32_t Color::GetColor32() const
{
	return 0;
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
	std::cout << val << "\n";
	if (val <= 0)
	{
		return 0;
	}
	else if (val >= 255)
	{
		return 255;
	}
	else
	{
		return val;
	}
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
static const Color Black(0, 0, 0);
static const Color White(255, 255, 255);