#include <cstdio>
#include "SAXparser.h"

SAXparser::SAXparser()
{
	
}

SAXparser::~SAXparser()
{

}

void SAXparser::start(const char* s)
{
	const int bufsize = 6;
	char* buf = new char[bufsize];
	char* temp = buf;
	bool ok = false;

	for (; *s != 0; s++)
	{
		if (*s == '<')
		{
			ok = true;
			temp = buf;
			continue;
		}

		if (!ok) continue;

		if (*s == '?') ok = false;
		if (*s == '/') ok = false;

		if (*s == '>')
		{
			*temp = 0;
			if (ok) tagEvent(buf);
			ok = false;
			continue;
		}

		if (temp == (buf + bufsize - 1)) throw bufsize;
		*(temp++) = *s;
	}

	delete[] buf;
}