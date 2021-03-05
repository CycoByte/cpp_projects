#include "SingletonDesign.h"



std::unique_ptr<Singleton> Singleton::s_Instance = nullptr;

Singleton::Singleton()
{ 
	std::cout << "Singleton created!" << std::endl; 
}

Singleton::~Singleton()
{
	std::cout << "Singleton destroyed!" << std::endl;
}

std::unique_ptr<Singleton>& Singleton::Get()
{	
	if(!s_Instance)
		s_Instance = std::make_unique<Singleton>();
	return s_Instance;
}

void Singleton::destroy()
{
	s_Instance.reset();
}


