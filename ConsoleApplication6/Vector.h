#pragma once

#include <vector>

template <class T>
class Vector
{
	public:
		void push_back(const T & newelement);
		const T& at(unsigned index);
		unsigned size();

	private:
		std::vector<T> stlvec;
};

template <class T>
void Vector<T>::push_back(const T & newelement){
	stlvec.push_back(newelement);
}

template <class T>
const T& Vector<T>::at(unsigned index){
	return stlvec.at(index);
}

template <class T>
unsigned Vector<T>::size(){
	return stlvec.size();
}