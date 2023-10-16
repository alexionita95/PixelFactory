#pragma once
#include <map>
#include <string>
#include <functional>
#include <memory>
#include<any>
namespace PixelFactory
{
	class Instantiator
	{
	using CreateFct = std::function<std::any(std::vector<uint8_t>&, const std::shared_ptr<Instantiator>&)>;
	public:
		Instantiator();
		~Instantiator()=default;

		template<typename T>
		T Create(const std::string& className, std::vector<uint8_t>& data, std::shared_ptr<Instantiator>& instantiator)
		{
			if (m_functions.find(className) != m_functions.end())
			{
				return std::any_cast<T>(m_functions[className](data, instantiator));
			}
			return nullptr;
		}

		bool Register(const std::string& className, CreateFct createFunction);
		

	private:

		std::map<const std::string, CreateFct> m_functions;
	};

	using InstantiatorPtr = std::shared_ptr<Instantiator>;

}