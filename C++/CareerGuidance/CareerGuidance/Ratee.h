#pragma once
#include <string>
#include <map>
#include <utility>      // std::pair

#include "Trait.h"




typedef size_t trait_numb;
typedef size_t prof_num; // profession number

template <class A, class B>
std::multimap<B, A> flip_map(const std::map<A, B> & src)
{
	std::multimap<B, A> dst;

	for (auto pair : src)
		dst.insert(std::make_pair(pair.second, pair.first));

	return dst;
}



class Ratee
{
public:
	const std::string name;
	std::map<trait_numb, int> result;
    std::map<prof_num, int> final_result;

	Ratee(std::string &name_) : name(name_)
	{
		for (trait_numb i = 0; i < Trait::traits.size(); i++)
			result[i] = 0;
	}

	std::multimap<int, trait_numb> reverseResult(){
		return flip_map(result);
	}

	std::multimap<int, prof_num> reverseFinalResult(){
		return flip_map(final_result);
	}

};
