#pragma once

class SAXparser
{
private:
	virtual void tagEvent(char* name) = 0;
public:
	SAXparser();
	~SAXparser();
	void start(const char* s);
};

