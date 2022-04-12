#pragma once
#include <iostream>
#include "Writer.h"
class ConsolenWriter :
    public Writer
{
public:
	void write(const std::string& message) const override
	{
		std::cout << message << std::endl;
	}
};

