#include <iostream>

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types...>
{
	using base = tuple<Types...>;

	T value;

	tuple() = default;
	tuple(const T& v, const Types& ... args)
		: value(v), base(args...) {}

	static constexpr int N = base::N + 1;
};


int main()
{
	//	tuple<> t0;
	//	tuple<             short> t1; // 2번째 부모  - 2 
	//	tuple<     double, short> t2; // 1번째 부모	- 3.4
	//	tuple<int, double, short> t3; // 0번째 부모  - 1 보관

	tuple<int, double, short> t(1, 3.4, 2);


	std::cout << t.value << std::endl; // 1

	// 주석처럼 결과가 나오도록 해보세요
	std::cout << static_cast<tuple<double, short>&>(t).value  << std::endl; // 3.4
	std::cout << static_cast<tuple<short>&>(t).value << std::endl; // 2 


	// get 의 모양을 생각해 봅시다.
	double d = get<1>(t);
	get<1>(t) = 2.1;		// 좌변에 올수 있어야 하므로 참조 반환
}

template<int N, typename TP>  // TP 는 임의의 튜플
TP의 N번째 요소의 타입&
get(TP& tp)
{
	return static_cast<TP의 N번째 부모&>(tp).value;
}

// 결국 get 을 만들려면 "임의의 튜플 타입 TP" 에서
// 1. TP의 N 번째 요소의 타입과
// 2. TP의 N 번째 기반 클래스의 타입을 구해야 합니다.

// 앞의예제에서 "함수 T" 에서
// => N 번째 인자의 타입 구하기 와 거의 유사합니다
// int(int, double, short)   의 1번째 인자 타입
// tuple<int, double, short> 의 1번째 요소 타입