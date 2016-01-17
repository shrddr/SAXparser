#include <cstdio>
#include "SAXparser.h"

class MyParser: public SAXparser
{
public:
	void tagEvent(char* name) { printf("%s\n", name); }
};

int main()
{
	MyParser p;

	try
	{
		p.start("<?xml?><model>mymodel<nodes><node>1</node></nodes></model>");
	}
	catch (int bufsize)
	{
		printf("buffer size: %d bytes - not enough\n", bufsize);
	}

	return 0;
}