#pragma once
#include <string>
class Writer
{
public:
	virtual void write(const std::string& message) const = 0;
};

