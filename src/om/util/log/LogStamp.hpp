#pragma once

#include <iostream>
#include <string>


namespace om
{
	class LogStamp
	{
	public:
		LogStamp(std::string const& str)
			: m_str(str)
		{

		}

	private:
		std::string m_str;

		template<class charT, class Traits>
			friend std::basic_ostream<charT, Traits>& operator<<(
					std::basic_ostream<charT, Traits>& stream,
					LogStamp const& stamp);
	};

	template<class charT, class Traits>
		std::basic_ostream<charT, Traits>& operator<<(
				std::basic_ostream<charT, Traits>& stream,
				LogStamp const& stamp)
		{
			return (stream << stamp.m_str);
		}
}

