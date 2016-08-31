// Include the Array class
#include "Array.h"
#include <iostream>
#include <stdexcept>

int main (int argc, char* argv [])
{
	// TODO Add code that uses the Array class here to test if your
	// implemenation is working correctly.
	//
	// Ex. Array a (4);
	// a.size ();
	{
		Array a (10,'a');
		Array b (10,'a');
		Array c(b);
		Array d;
		Array f(6,'v');
		Array g(5,'v');
		Array h(10,'a');
		h.set(9,'z');
		std::cout<<h.find('a')<<std::endl;
		std::cout<<h.find('a',8)<<std::endl;
		if(h==b){
			std::cout<<"Fail"<<std::endl;
		}
		else{
			std::cout<<"Success!!"<<std::endl;
		}
		f=g;
		d.resize(0);
		std::cout<<d.max_size()<<std::endl;
		d=f;
		for(size_t i=0;i<f.size();i++){
			std::cout<<f[i];
		}

		const Array e(10,'z');
		std::cout<<std::endl;

		std::cout<<d.max_size()<<std::endl;
		d.resize(20);
		d.resize(20);
		d.resize(3);
		for(size_t i=0;i<d.size();i++){
			std::cout<<d[i];
		}
		std::cout<<std::endl;
		std::cout<<d.max_size()<<std::endl;
		std::cout<<d[2]<<std::endl;
		try{
			std::cout<<d[2]<<std::endl;

			std::cout<<b.size ()<<std::endl;
			std::cout<<b.max_size ()<<std::endl;
			if(c==b){
				std::cout<<b.max_size ()<<std::endl; 
			}
			std::cout<<b.get(8)<<std::endl;
			c.resize(12);
			if(c!=b){
				std::cout<<b.max_size ()<<std::endl; 
			}
			std::cout<<b.find('a')<<std::endl;
			d=b;
			std::cout<<d.get(8)<<std::endl;
			std::cout<<d.max_size()<<std::endl;
			d.resize(15);
			std::cout<<d.max_size()<<std::endl;
			std::cout<<d.get(8)<<std::endl;
			std::cout<<"ahh"<<std::endl;
			//std::cout<<d.get(13)<<std::endl;
			d.resize(5);
			std::cout<<d.max_size()<<std::endl;
			std::cout<<d.size()<<std::endl;
			d.resize(14);
			std::cout<<d.max_size()<<std::endl;
			std::cout<<d.size()<<std::endl;
			std::cout<<b.find('a')<<std::endl;
			d.fill('a');
			for(size_t i=0;i<d.size();i++){
				std::cout<<d[i];
			}
			std::cout<<std::endl;
			std::cout<<d.find('a',13)<<std::endl;
			Array t;
			t.fill('l');
			for(size_t i=0;i<t.size();i++){
				std::cout<<t[i];
			}
			std::cout<<std::endl;
			Array m;
			Array n(m);
			std::cout<<n.find('a')<<std::endl;
			//t.set(0,'a');
			std::cout<<t[0]<<std::endl;
		}
		catch(const std::out_of_range& e){
			std::cerr<<e.what()<<std::endl;

		}
		//system("pause");
	}
	return 0;
}
