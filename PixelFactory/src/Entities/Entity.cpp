#include<Entities/Entity.h>
#include<Serialization/Serializer.h>
#include<any>
#include<iostream>
#include<typeindex>
namespace PixelFactory
{
	namespace Entities
	{
		Entity::Entity()
		{

		}
		Entity::Entity(const Entity& other)
		{
			m_id = other.m_id;
		}

		std::vector<uint8_t> Entity::GetData(bool addName)
		{
			std::vector<uint8_t> data;
			if (addName)
			{
				Serialization::Serializer::WriteString(STRINGIFY(PixelFactory::Entities::Entity), data);
			}
			Serialization::Serializer::WriteString(m_id, data);
			return data;
		}

		std::vector<uint8_t> Entity::Serialize()
		{
			auto data = GetData(true);
			std::vector<uint8_t> result;
			result.insert(result.end(), data.begin(), data.end());
			return result;
		}
		void Entity::Deserialize(std::vector<uint8_t>& data, const const InstantiatorPtr& instantiator)
		{
			m_id = Serialization::Serializer::ReadString(data);
		}

		EntityPtr Entity::Create(std::vector<uint8_t>& data, const const InstantiatorPtr& instantiator)
		{
			EntityPtr result = std::make_shared<Entity>();
			result->Deserialize(data);
			return result;
		}


	}
}