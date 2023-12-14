// 4_type_traits3 - 210 page
#include <iostream>
#include <type_traits>

// traits 의 종류
// 1. 타입질의 : is_xxx<T>::value
// 2. 변형타입얻기 : xxx<T>::type

// 변형 타입을 얻은 traits 만들기

template<typename T> struct remove_pointer
{
	using type = T;
};



int main()
{
	remove_pointer<int*>::type n2;  // int n2
}

template<typename T> void foo(T a)
{
}