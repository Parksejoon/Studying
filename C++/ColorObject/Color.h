#ifndef COLOR_H
#define COLOR_H

// 색상 정보
class Color
{
public:
	// RGB 요소 타입
	typedef unsigned char element_t;

	// 32비트 색상 타입
	typedef unsigned long color32_t;

	// 기본 RGB값
	enum { defR = 255, defG = 255, defB = 255 };

protected:
	// 색상을 RGB로 보관
	element_t R;
	element_t G;
	element_t B;

public:
	// 생성자
	Color();
	Color(element_t R, element_t G, element_t B);

	// 접근자
	void SetR(element_t var);
	void SetG(element_t var);
	void SetB(element_t var);
	element_t GetR(void) const;
	element_t GetG(void) const;
	element_t GetB(void) const;

	// RGB 32비트 정수형식
	// 32비트 중 24비트만 사용
	// 요소당 8비트
	void SetColor32(color32_t var);
	color32_t GetColor32() const;

	// 색상 밝기 변화
	void AdjustBright(int delta);

	// RGB값 한번에 바꾸기
	void SetRGB(element_t R, element_t G, element_t B);

	// 값을 출력
	// (endLine == true 일시 개행)
	void Print(bool endLine = true) const;

protected:
	// 범위를 벗어난 값을 조정
	int PutInRange(int val);
	
public:
	//자주 쓰이는 색상 정적 멤버
	static const Color Black;
	static const Color White;
};

#endif