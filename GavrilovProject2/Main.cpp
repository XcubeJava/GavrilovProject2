#include "Autorization.hpp"
#include <io.h>	
#include <fcntl.h>
#include "Storage.hpp"

int main()
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	Start();
	delete[]userId;
	delete[]loginArr;
	delete[]passArr;
	delete[]StatusArr;

	if (IsStoregeCreated)
	{
		delete[]idArr;
		delete[]nameArr;
		delete[]countArr;
		delete[]priceArr;
	}


	return 0;
}