#pragma once



/* USE EXAMPLE
	std::cout << "Scope main" << std::endl;
	{
		Ref<Entity> refSmartPtr;
	//scope 1
		std::cout << "Scope 1" << std::endl;
		{
		//scope 2
			std::cout << "Scope 2" << std::endl;
			Scope<Entity> scopedPtr = MAKE_SCOPED(Entity) ();
			std::cout << "Scope 2 ended" << std::endl;
		}
		Ref<Entity> refSmartPtr2 = MAKE_REF(Entity) ();
		refSmartPtr = refSmartPtr2;
		std::cout << "Scope 1 ended" << std::endl;
	}
	//scope main
	std::cout << "Scope main ending..." << std::endl;

*/



class Singleton
{
	
public:

	static std::unique_ptr<Singleton>& Get();
	static void destroy();

	void functionz()
	{
		std::cout << testString + " function!" << std::endl;
	}

	//must be public for smart pointer to create an instance
	Singleton();
	~Singleton();

private:

	Singleton(const Singleton& other) = delete;
	std::string testString = " Demo Singleton String ";
	static std::unique_ptr<Singleton> s_Instance;
	
};
