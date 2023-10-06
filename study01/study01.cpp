// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread

void foo()
{
	// do stuff...
	std::cout << "foo" << std::endl;
}

void bar(int x)
{
	// do stuff...
	std::cout << "bar " << x << std::endl;
}

void bar2(int x, int y)
{
	// do stuff...
	std::cout << "bar2 " << x << " " << y << std::endl;
}

int main()
{
	std::thread first(foo);     // spawn new thread that calls foo()
	std::thread second(bar, 0);  // spawn new thread that calls bar(0)
	std::thread third(bar2, 1, 2);  // spawn new thread that calls bar(0)

	std::cout << "main, foo and bar now execute concurrently...\n";

	// synchronize threads:
	for (int i = 0; i < 1000000; i++) {
		;
	}

	std::cout << "1111 " << "11111" << "\n";
	std::cout << "222 " << "222222" << "\n";
	std::cout << "before join" << std::endl;
	first.join();                // pauses until first finishes
	second.join();               // pauses until second finishes
	third.join();

	std::cout << "foo and bar completed.\n";

	return 0;
}