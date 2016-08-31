// $Id: Array.cpp 1473 2014-01-20 15:48:07Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>          // for throwing std::out_of_range exception.
#include <cstdlib>            // for printing exception message.
#include <algorithm>          // for std::swap function before C++11.
#include <utility>            // for std::swap function after C++11.

//
// Array
//
Array::Array (void)
	// Arvind, initial each member variable on its own line in the base member
	// initialization section. This way, it statement has its own distinct line
	// for error reporting and debugging purposes.

	// Dr.Hill, I have done initialization of each member variable on its own 
	// line in the base member initialization section.
	:data_(0),
	cur_size_(0),
	max_size_(0)
{ }

//
// Array (size_t)
//
Array::Array (size_t length)
	// Arvind, initial each member variable on its own line in the base member
	// initialization section. This way, it statement has its own distinct line
	// for error reporting and debugging purposes.

	// Dr.Hill, I have done initialization of each member variable on its own 
	// line in the base member initialization section.
	:data_(new char[length]),
	cur_size_(length),
	max_size_(length)
{ }

//
// Array (size_t, char)
//
Array::Array (size_t length, char fill)
	// Arvind, initial each member variable on its own line in the base member
	// initialization section. This way, it statement has its own distinct line
	// for error reporting and debugging purposes.

	// Dr.Hill, I have done initialization of each member variable on its own 
	// line in the base member initialization section.
	:data_(new char[length]),
	cur_size_(length),
	max_size_(length)
{
	for(size_t i=0;i<cur_size_;i++){
		data_[i]=fill;
	}
}

//
// Array (const Array &)
//
Array::Array (const Array & array)
	// Arvind, initial each member variable on its own line in the base member
	// initialization section. This way, it statement has its own distinct line
	// for error reporting and debugging purposes.

	// Dr.Hill, I have done initialization of each member variable on its own 
	// line in the base member initialization section.
	:data_(new char[array.max_size_]),
	cur_size_(array.cur_size_),
	max_size_(array.max_size_)
{
	for(size_t i=0;i<cur_size_;i++){
		data_[i]=array.data_[i];
	}
}

//
// ~Array
//
Array::~Array (void)
{
	// Arvind, you should check if data_ is 0 before calling delete
	// to prevent unnecessary system-level calls. For example, when
	// the default constructor is used and the array is never resized.

	// Dr.Hill, I have included a check to ensure data_ is 0 before 
	// calling delete to prevent unnecessary system-level calls.
	if(0!=data_)
		delete [] data_;

	// Arvind, there is no need to reset the member variables in this
	// method. This is becasue after this method returns, none of its
	// data is accessible.

	// Dr.Hill, I have removed the resetting of the member variables 
	// in this method i.e., data_=0.
}

//
// operator =
//
const Array & Array::operator = (const Array & rhs)
{
	// if lhs array is not equal to rhs array perform assignment
	if(*this!=rhs){

		// Arvind, instead of explicitly calling the destructor, you only
		// need to delete the original array if this array is too small to
		// hold the contents of rhs. Right now, you are making a system call
		// each time, which may not be necessary.

		// Dr.Hill, I am now swapping the addresses if the array is smaller than
		// the buffer(i.e., max_size_) which also maintains data consistency. Also,
		// if the array is larger than rhs then I do not perform reallocation and
		// destruction. Thus, I have eliminated unnecessary system calls.

		// if max_size_ is greater than or equal to the rhs cur_size_ no need 
		// for reallocation.
		if(max_size_>=rhs.cur_size_){
			cur_size_=rhs.cur_size_;
			for (size_t i = 0; i < rhs.cur_size_; i++)
			{
				data_[i]=rhs.data_[i];
			}
		}

		// when max_size is lesser than rhs cur_size_ there is 
		// need for reallocation. 
		else{
			cur_size_=rhs.cur_size_;
			max_size_=rhs.cur_size_;

			// create a temporary array for reallocation.
			char * temp=new char[rhs.cur_size_];
			for (size_t i = 0; i < rhs.cur_size_; i++)
			{
				temp[i]=rhs.data_[i];
			}

			// perform a swap of the addresses of temp and data_.
			std::swap(temp,data_);
			delete [] temp;
		}
	}
	return *this;
}

//
// operator []
//
char & Array::operator [] (size_t index)
{

	if(is_valid_index(index)){
		return data_[index];
	}
	else{
		throw std::out_of_range("Invalid \a index value");
	}


}

//
// operator [] 
//
const char & Array::operator [] (size_t index) const
{

	if(is_valid_index(index)){
		return data_[index];
	}
	else{
		throw std::out_of_range("Invalid \a index value");
	}

}

//
// get
//
char Array::get (size_t index) const
{
	if(is_valid_index(index)){
		return data_[index];
	}
	else{
		throw std::out_of_range("Invalid \a index value");
	}

}

//
// set
//
void Array::set (size_t index, char value)
{
	if(is_valid_index(index)){
		data_[index]=value;
	}
	else{
		throw std::out_of_range("Invalid \a index value");
	}
}

//
// resize
//
void Array::resize (size_t new_size)
{
	// if new size is not equal to current size, perform resize.
	if(new_size!=cur_size_){
		// Arvind, instead of explicitly calling the destructor, you only
		// need to delete the original array the new size if larger than
		// the number of elements this array can hold. Right now, you are making
		// a system call each time, which may not be necessary. Also, your
		// implemenation is more complex than it needs to be.

		// Dr.Hill, I am now swapping the addresses if the new_size specified is
		// greater than the buffer(i.e.,max_size_). If the new_size specified is
		// smaller than the buffer then the reallocation and destruction is not
		// performed. Hence, I have prevented unnecessary system calls and made 
		// implementation more simple.

		if(max_size_<new_size){

			// create a temporary array for reallocation.
			char * temp=new char[new_size];
			for (size_t i = 0; i < cur_size_; i++)
			{
				temp[i]=data_[i];
			}
			cur_size_=new_size;
			max_size_=new_size;

			// perform a swap of the addresses of temp and data_.
			std::swap(temp,data_);
			delete [] temp;
		}
		else{
			cur_size_=new_size;
		}
	}
}

//
// find (char)
//
int Array::find (char ch) const
{
	for(size_t i=0;i<cur_size_;i++){

		// if character is found return the index.
		if(data_[i]==ch){
			return i;
		}
	}
	return -1;
}

//
// find (char, size_t) 
//
int Array::find (char ch, size_t start) const
{
	if (is_valid_index(start))
	{
		for(size_t i=start;i<cur_size_;i++){

			// if character is found return the index.
			if(data_[i]==ch){
				return i;
			}
		}
		return -1;
	}
	else{
		throw std::out_of_range("Invalid \a index value");
	}

}

//
// operator ==
//
bool Array::operator == (const Array & rhs) const
{
	// if current and max size are equal, check individual
	// data elements.
	if(cur_size_==rhs.cur_size_){
		for(size_t i=0;i<cur_size_;i++){

			// if any one of the elements are not equal, arrays 
			// are not same.
			if(data_[i]!=rhs.data_[i]){
				return false;
			}
		}
		return true;
	}

	// current and max size are not equal, so arrays compared 
	// are not same.
	else{
		return false;
	}


}

//
// operator !=
//
bool Array::operator != (const Array & rhs) const
{
	// Arvind, it is easier to write this in terms of ==. For example,
	// return !(*this == rhs).

	// Dr.Hill, I have changed the implementation to return !(*this == rhs).
	return !(*this == rhs);
}

//
// fill
//
void Array::fill (char ch)
{
	for(size_t i=0;i<cur_size_;i++){
		data_[i]=ch;
	}
}
