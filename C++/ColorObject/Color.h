#ifndef COLOR_H
#define COLOR_H

// ���� ����
class Color
{
public:
	// RGB ��� Ÿ��
	typedef unsigned char element_t;

	// 32��Ʈ ���� Ÿ��
	typedef unsigned long color32_t;

	// �⺻ RGB��
	enum { defR = 255, defG = 255, defB = 255 };

protected:
	// ������ RGB�� ����
	element_t R;
	element_t G;
	element_t B;

public:
	// ������
	Color();
	Color(element_t R, element_t G, element_t B);

	// ������
	void SetR(element_t var);
	void SetG(element_t var);
	void SetB(element_t var);
	element_t GetR(void) const;
	element_t GetG(void) const;
	element_t GetB(void) const;

	// RGB 32��Ʈ ��������
	// 32��Ʈ �� 24��Ʈ�� ���
	// ��Ҵ� 8��Ʈ
	void SetColor32(color32_t var);
	color32_t GetColor32() const;

	// ���� ��� ��ȭ
	void AdjustBright(int delta);

	// RGB�� �ѹ��� �ٲٱ�
	void SetRGB(element_t R, element_t G, element_t B);

	// ���� ���
	// (endLine == true �Ͻ� ����)
	void Print(bool endLine = true) const;

protected:
	// ������ ��� ���� ����
	int PutInRange(int val);
	
public:
	//���� ���̴� ���� ���� ���
	static const Color Black;
	static const Color White;
};

#endif