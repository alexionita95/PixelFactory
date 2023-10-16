#include<Instantiator.h>

namespace PixelFactory
{
	Instantiator::Instantiator()
	{

	}

	bool Instantiator::Register(const std::string& className, CreateFct createFunction)
	{
		if (m_functions.find(className) != m_functions.end())
		{
			return false;
		}
		m_functions.emplace(className, createFunction);
		return true;
	}

}