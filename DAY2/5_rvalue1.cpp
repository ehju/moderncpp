// 4_rvalue - 87 page
int x = 0;
int  foo() { return x;}		// x의 값 0 반환
int& goo() { return x; }	// x의 별명(메모리 정보)반환

// lvalue : 등호의 왼쪽에 올수 있는 표현식 (오른쪽도 가능)
//			이름(id) 가 있고, 단일 식을 넘어서도 사용가능하다. 
//			주소연산자로 주소를 구할수 있다.( 사용자가 할당한 메모리 사용)
//			반환타입이 참조인 함수

// rvalue : 등호의 왼쪽에 올수 없는 표현식 (오른쪽만 가능)
//			이름(id) 가 없고, 단일 식에서만 사용 가능.
//			주소연산자로 주소를 구할수 없다.( 임시로 사용하는 값)
//			반환타입이 값인 함수
//			literal, 임시객체 


int main()
{
	int v1 = 10, v2 = 10;

	v1 = 20;	// ok.    v1 는 등호의 왼쪽에 올수 있다. lvalue
	10 = v1;	// error. 10 은 등호의 왼쪽에 올수 없다. rvalue
	v2 = v1;

	int* p1 = &v1;	// ok
	int* p2 = &10;	// error

	foo() = 10; // error
	goo() = 10; // ok
}









