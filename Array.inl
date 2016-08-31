// -*- C++ -*-
// $Id: Array.inl 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// size
//
inline
	size_t Array::size (void) const
{
	return cur_size_;
}

//
// max_size
//
inline
	size_t Array::max_size (void) const
{
	return max_size_;
}

//
// is_valid_index (size_t)
//
inline
	bool Array::is_valid_index (size_t i) const
{
	if(i>=0 && i<cur_size_){
		return true;
	}
	else{
		return false;
	}
}