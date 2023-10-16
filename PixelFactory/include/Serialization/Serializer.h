#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <cstdint>
#include <cstring>
namespace PixelFactory
{
	namespace Serialization
	{
		#define STRINGIFY(name) #name
		class Serializer
		{
		public:
			template<typename T>
			static void Write(const T& value, std::vector<uint8_t>& data)
			{
				std::vector<std::uint8_t> converted;
				converted.resize(sizeof(T));
				std::memcpy(converted.data(), &value, sizeof(T));
				data.insert(data.end(), converted.begin(), converted.end());
			}
			
			template<typename T>
			static T Read(std::vector<uint8_t>& data)
			{
				uint8_t dataArray[sizeof(T)];
				std::memcpy(dataArray, data.data(), sizeof(T));
				data.erase(data.begin(), data.begin() + sizeof(T));
				return *reinterpret_cast<T*>(dataArray);
			}

			static void WriteInt(const int32_t& value, std::vector<uint8_t>& data)
			{
				Write<int32_t>(value, data);
			}
			static int32_t ReadInt(std::vector<uint8_t>& data)
			{
				return Read<int32_t>(data);
			}

			static void WriteFloat(const float& value, std::vector<uint8_t>& data)
			{
				Write<float>(value, data);
			}
			static int32_t ReadFloat (std::vector<uint8_t>& data)
			{
				return Read<float>(data);
			}

			static void WriteString(const std::string& value, std::vector<uint8_t>& data)
			{
				int32_t length = value.length();
				WriteInt(length, data);
				data.insert(data.end(), value.begin(), value.end());
			}
			static std::string ReadString(std::vector<uint8_t>& data)
			{
				int32_t length = ReadInt(data);
				char* dataArray = new char[length];
				std::memcpy(dataArray, data.data(), length);
				data.erase(data.begin(), data.begin() + length);
				dataArray[length] = '\0';
				std::string result(dataArray);
				return result;
			}

		};
	}
}