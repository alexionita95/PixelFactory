#pragma once
#include<string>
#include<vector>
#include<memory>
#include<functional>
#include<Instantiator.h>
namespace PixelFactory
{
	namespace Entities
	{
		class Entity
		{
		public:
			Entity();
			Entity(const Entity& other);
			virtual ~Entity() = default;
			const std::string& GetId()
			{
				return m_id;
			}
			void SetId(const std::string& value)
			{
				m_id = value;
			}

			virtual std::vector<uint8_t> GetData(bool addName = false);
			virtual std::vector<uint8_t> Serialize();
			virtual void Deserialize(std::vector<uint8_t>& data, const InstantiatorPtr& instantiator = nullptr);
			static std::shared_ptr<Entity> Create(std::vector<uint8_t>& data, const InstantiatorPtr& instantiator = nullptr);

		private:
			std::string m_id;
		};
		using EntityPtr = std::shared_ptr<Entity>;

	}
}
