// 3_함수객체6
// 1. 일반 함수는 자신만의 타입이 없습니다.
//    signature(리턴타입과 파라미터) 가 
//    동일한 모든 함수는 같은 타입입니다.


// 2. 함수 객체는 자신만의 타입이 있습니다.
//    signature(리턴타입과 파라미터) 가
//    동일해도  모든 함수객체는 다른 타입 입니다.


struct Less
{
	inline bool operator()(int a, int b) { return a < b; }
};
struct Greater
{
	inline bool operator()(int a, int b) { return a > b; }
};
//==================================================

void Sort(int* x, int sz, Less cmp )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if (cmp(x[i], x[j]) == true)
				std::swap(x[i], x[j]);
		}
	}
}

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	Less    f1; f1(1, 2); 
	Greater f2; f2(1, 2); 
}



