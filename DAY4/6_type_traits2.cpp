#include <iostream>
#include <type_traits>

// type traits : 타입(T) 에 대한 다양한 특성(특질)을 조사하는 기술

template<typename T>
struct is_pointer
{
	enum { value = false };
};



template<typename T> void foo(const T& a)
{
	if ( is_pointer<T>::value )
		std::cout << "포인터" << std::endl;
	else
		std::cout << "포인터 아님" << std::endl;
}
int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}