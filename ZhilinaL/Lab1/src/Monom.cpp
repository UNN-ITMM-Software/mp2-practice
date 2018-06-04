#include "monom.h"

monom::monom(double c, unsigned int a)
{
	coeff = c;
	abc = a;
}

monom& monom:: operator=(const monom& m)
{
	coeff = m.coeff;
	abc = m.abc;
	return *this;
}

bool monom:: operator< (const monom& m) const
{
	bool res = true;
	if (abc >= m.abc)
		res = false;
	return res;
}

bool monom:: operator> (const monom& m) const
{
	bool res = true;
	if (abc <= m.abc)
		res = false;
	return res;
}

bool monom:: operator==(const monom& m) const
{
	bool res = true;
	if (abc != m.abc || coeff != m.coeff)
		res = false;
	return res;
}

bool monom:: operator!=(const monom& m) const
{
	return !(*this == m);
}
