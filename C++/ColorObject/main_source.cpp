#include <iostream>
#include "Color.h"

using namespace std;

int main(void)
{
	// -------------------------
	// Color 클래스 기본 기능 사용

	// 티폴트 생성자
	Color c1;
	c1.Print();

	// 인자가 있는 생성자
	Color c2(100, 100, 100);
	c2.Print();

	// c2의 R요소 변경
	c2.SetR(255);
	c2.Print();

	// c2의 R요소 확인
	cout << "c2.R = " << (int)c2.GetR() << "\n";

	// c2의 전체 밝기를 50 증가
	c2.AdjustBright(50);
	c2.Print();

	//// c2의 색상을 32비트 값으로 출력
	//Color::color32_t color = c2.GetColor32();
	//cout << "c2 = " << color << "\n";

	//// c1의 색상을 32비트 값을 사용하여 변경
	//c1.SetColor32( color);
	//c1.Print();

	// ---------------
	// 정적 멤버의 사용

	//// 검정색 객체의 값 확인
	////Color::Black.Print();

	//// 객체를 검정색으로 초기화
	//Color c3 = Color::Black;

	return 0;
}