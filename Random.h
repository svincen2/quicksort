#ifndef RANDOM_H
#define RANDOM_H

#include <chrono>
#include <random>


template<typename Int_type>
class Random
{
public:
	using value_type = Int_type;


	/*
	* Construct a random number generator to generate numbers
	* within the given range.
	* params:
	*	min - Minimum value that can be generated.
	*	max - Maximum value that can be generated.
	*/
	Random(value_type min, value_type max)
		: dist{min, max},
		  gen{}
	{
		gen.seed(std::chrono::system_clock::now().time_since_epoch().count());
	}


	/*
	* Seed the random number generator.
	* params:
	*	val - Seed value.
	*/
	void seed(unsigned long val)
	{
		gen.seed(val);
	}


	/*
	* Set the distribution range for integers generated by this random
	* number generator.
	* params:
	*	min - Minimum value that can be generated.
	*	max - Maximum value that can be generated.
	*/
	void range(value_type min, value_type max)
	{
		dist = std::uniform_int_distribution<value_type>(min, max);
	}


	/*
	* Return the minimum value of the distribution range.
	* return:
	*	value_type - Minimum possible value that can be generated.
	*/
	value_type min() const
	{
		return dist.min();
	}


	/*
	* Return the maximum value of the distribution range.
	* return:
	*	value_type - Maximum possible value that can be generated.
	*/
	value_type max() const
	{
		return dist.max();
	}


	/*
	* Generate a random integer within the range specified during contruction.
	* return:
	*	value_type - Random integer.
	*/
	value_type value()
	{
		return dist(gen);
	}


	/*
	* Generate a vector of random integers with n elements.
	* params:
	*	n - The number of random integers to generate.
	* return:
	*	std::vector - Vector of random integers.
	*/
	std::vector<value_type> vector(int n)
	{
		std::vector<value_type> vec{};
		while (vec.size() != n) {
			vec.push_back(value());
		}
		return vec;
	}

private:
	std::uniform_int_distribution<value_type> dist;
	std::default_random_engine gen;
};
#endif

