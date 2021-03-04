#include <chrono>
#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
#include <string>

int main()
{
	std::vector <int> vec;

	std::default_random_engine dre(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution <> uid(1, 10);

	for (auto i = 0U; i < 10; ++i)
	{
		vec.push_back(uid(dre));
	}

	// Sequence generated

	int input;

	for (auto i = 0U; i < 1; i++)
	{
		std::cin >> input;
		vec.push_back(input);
	}

	// Походу это неправильный ввод из cin

	std::shuffle(std::begin(vec), std::end(vec), dre);

	std::cout << "Shuffled\n";
	for (auto i : vec)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	// Sequence shuffled

	std::sort(std::begin(vec), std::end(vec));
	vec.erase(std::unique(std::begin(vec), std::end(vec)), std::end(vec));

	std::cout << "Unique\n";
	for (auto i : vec)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	// Duplicates erased

	int odd = 0;

	std::for_each(std::begin(vec), std::end(vec), [&odd](auto i) {if (i % 2 != 0) { odd++; }});

	std::cout << "Number of odd numbers in the sequence - " << odd << std::endl;

	// Number of odds counted

	auto res = std::minmax_element(std::begin(vec), std::end(vec));

	std::cout << "Minimal - " << *res.first << " Maximal - " << *res.second << std::endl;

	// Minimal and Maximal elements detected
	
	auto it = std::find_if(std::begin(vec), std::end(vec), [](auto x)
		{for (auto i = x - 1; i > 1; i--)
	{
		if (x % i == 0)
		{
			return false;
		}
	}

	return true;
	});

	std::cout << vec[*it - 1] << std::endl; 
	
	// Prime number found

	std::transform(std::begin(vec), std::end(vec), std::begin(vec), [](auto x) {return x * x; });

	std::cout << "Squared\n";
	for (auto i : vec)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	// Replaced with squared

	std::vector < int > vec_2;

	std::generate_n(std::back_inserter(vec_2), vec.size(), [&dre, &uid]() {return uid(dre); });

	std::cout << "Vec_2\n";
	for (auto i : vec_2)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	// Second sequence created

	auto result = std::accumulate(std::begin(vec_2), std::end(vec_2), 0);

	std::cout << result << std::endl;

	// Summ of the second sequence counted

	std::transform(std::begin(vec_2), std::next(std::begin(vec_2), 3), std::begin(vec_2), [](auto x) {return 1; });

	std::cout << "Replaced with 1\n";
	for (auto i : vec_2)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	// Replaced with 1

	std::vector < int > vec_3;

	std::transform(std::begin(vec), std::end(vec), std::begin(vec_2), std::back_inserter(vec_3), [](auto x1, auto x2) {return x1 - x2; });

	std::cout << "Vec_3\n";
	for (auto i : vec_3)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	// Third sequence created

	std::for_each(std::begin(vec_3), std::end(vec_3), [](auto &x) {x -= 20; }); // This is done for some negative numbers in the sequence

	std::replace_if(std::begin(vec_3), std::end(vec_3), [](auto x) {return (x < 0); }, 0);

	std::cout << "Replaced with zeros\n";
	for (auto i : vec_3)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	// Replaced with zeros

	vec_3.erase(std::remove_if(std::begin(vec_3), std::end(vec_3), [](auto x) {return (x == 0); }), std::end(vec_3));

	std::cout << "Zeros erased\n";
	for (auto i : vec_3)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	// Zeros erased

	std::reverse(std::begin(vec_3), std::end(vec_3));

	std::cout << "Reversed\n";
	for (auto i : vec_3)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	// Reversed

	std::nth_element(std::begin(vec_3), std::end(vec_3) - 3, std::end(vec_3));

	std::cout << "3 biggest elements\n";
	std::for_each(std::end(vec_3) - 3, std::end(vec_3), [](auto x) {std::cout << x << ' '; });

	// 3 biggest elements

	std::sort(std::begin(vec), std::end(vec));
	std::sort(std::begin(vec_2), std::end(vec_2));

	std::for_each(std::begin(vec), std::end(vec), [](auto x) {std::cout << x << ' '; });
	std::cout << std::endl;
	std::for_each(std::begin(vec_2), std::end(vec_2), [](auto x) {std::cout << x << ' '; });
	std::cout << std::endl;

	// Sorted

	std::vector < int > vec_4;

	std::copy(std::begin(vec), std::end(vec), std::back_inserter(vec_4));
	std::copy(std::begin(vec_2), std::end(vec_2), std::back_inserter(vec_4));

	// Sequence 4 done



	return EXIT_SUCCESS;
}