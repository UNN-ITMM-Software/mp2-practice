#include <iostream>
#include "HashTable.h"
#include "ScanTable.h"
#include "SortTable.h"
#include "polinom.h"

using namespace std;

int main()
{
	/*HashTable<string, Polinom> H(10);
	H.Insert("first", Polinom("3x"));
	H.Insert("second", Polinom("2y^5"));
	H.Insert("third", Polinom("12.3z^3"));
	H.Insert("fourth", Polinom("1.2"));
	H.Insert("fifth", Polinom("3x + 4y + 5"));
	H.Insert("sixth", Polinom("1.2 + 45 - 3.4y^1x^5"));
	H.Insert("seventh", Polinom("2.3x^2y^3z^7 + 3.2"));
	cout << H << endl;

    ScanTable<string, Polinom> T(10);
	T.Insert("first", Polinom("3x"));
	T.Insert("second", Polinom("2y^5"));
	T.Insert("third", Polinom("12.3z^3"));
	T.Insert("fourth", Polinom("1.2"));
	T.Insert("fifth", Polinom("3x + 4y + 5"));
	T.Insert("sixth", Polinom("1.2 + 45 - 3.4y^1x^5"));
	T.Insert("seventh", Polinom("2.3x^2y^3z^7 + 3.2"));
	cout << T << endl;

    SortTable<string, Polinom> S(T);
    S.Insert("eighth", Polinom("z^2 - z"));
    cout << S << endl;*/

	Polinom a("-x-x");
	cout << a << endl;




	return 0;
}
