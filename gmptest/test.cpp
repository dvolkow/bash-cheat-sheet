#include <gmp.h>
#include <stdio.h>
#include <iostream>
#include <string>

class bigInt
{
	mpz_t i;
public:
	bigInt()
	{
		mpz_init(i);
	}

	bigInt(std::string s)
	{
		mpz_init(i);
		mpz_set_str(i, s.c_str(), 10);
	};
	
	~bigInt()
	{
		mpz_clear(i);
	};

	mpz_t & operator()()
	{
		return this->i;
	} 

	void print()
	{
		mpz_out_str(stdout, 10, i);
	}
	
};

int main ()
{

	bigInt a("1233234952378293498747589239384747382987843233423443287182398723789123987578321987347895987111298749873437282123123133123098426781230987123567432872311");
	a.print();

	std::cout << " * ";
	bigInt b("1233321232342398757389429328734874382938747389229387473899234987234789212321209856789123876432671809123876476891283767831231331");
	b.print();

	bigInt mldest;
	mpz_mul(mldest(), a(), b());

	std::cout << " = ";
	mldest.print();
	std::cout << " \n ";


    	return 0;
}