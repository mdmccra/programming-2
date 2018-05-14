// Include iostream to get access to istream, ostream
#include <iostream>
using namespace std;

struct Fraction {
   int num;
   int den;
};

// A function to calculate the greatest common divisor will be useful
int gcd(int a, int b)
{
	if( b == 0 )
		return a;
	return gcd(b,a%b);
}

//reduce the fraction to simplest form
void reduce(Fraction &f)
{
	//declare variable
	int GCD = gcd(f.num,f.den);
	
	//divide each part of the fraction by its gcd
	f.num /= GCD;
	f.den /= GCD;
	
	//put the negative sign on the numerator if applicable
	
	if (f.num >= 0 && f.den < 0)
	{
		f.num *= -1;
		f.den *= -1;
	}
	
	//if num and den are both negative make it positive
	else if (f.num < 0 && f.den < 0)
	{
		f.num *= -1;
		f.den *= -1;
	}
}

istream& operator>>(istream& in, Fraction &f)
{
    //input numerator, /, and denominator
    char c;
    in >> f.num >> c >> f.den;
    return in;
}

ostream& operator<<(ostream& out, Fraction f)
{
    //output numerator, /, and denominator
    out << f.num << '/' << f.den;
    return out;
}

Fraction operator+(Fraction a, Fraction b)
{
	//declare variables
    Fraction result;
    
    //multiply each fraction by the other denominator
    a.num *= b.den;
    b.num *= a.den;
    a.den *= b.den;

    //add the numerators together
    result.num = a.num + b.num;
    result.den = a.den;
    
    //reduce the fraction
    reduce(result);
    
    //return the fraction
    return result;
}

Fraction operator-(Fraction a, Fraction b)
{
    //declare variables
    Fraction result;
    
    //multiply each fraction by the other denominator
    a.num *= b.den;
    b.num *= a.den;
    a.den *= b.den;

    //subtract the numerators
    result.num = a.num - b.num;
    result.den = a.den;
    
    //reduce the fraction
    reduce(result);
    
    //return the fraction
    return result;
}

Fraction operator*(Fraction a, Fraction b)
{
	//declare variable
    Fraction result;
    
    //multiply the numerators together and multiply the denominators together
    result.num = a.num * b.num;
    result.den = a.den * b.den;
    
    //reduce the result fraction
    reduce(result);
    
    //return the reduced fraction
    return result;
}

Fraction operator/(Fraction a, Fraction b)
{
	//declare variable
	Fraction result;
	
	//multiply the first fraction by the reciprocal of the other fraction
	result.num = a.num * b.den;
	result.den = a.den * b.num;
	
	//reduce the result fraction
	reduce(result);
	
	//return the reduced fraction
	return result;
}
