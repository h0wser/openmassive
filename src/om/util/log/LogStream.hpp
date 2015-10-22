#pragma once

#include <iostream>
#include <sstream>
#include <string>


namespace om
{
	template<class charT, class Traits = std::char_traits<charT>>
	class BasicLogStream final : public std::basic_ostream<charT, Traits>
	{
	private:
		class LogBuffer final : public std::basic_stringbuf<charT, Traits>
		{
		public:
			LogBuffer(std::basic_ostream<charT, Traits>& real_stream)
				: m_realStream(real_stream), m_newLine(true)
			{ }

			int sync()
			{
				// obtain buffer string
				std::basic_string<charT> bufferString(this->str());

				// print a stamp for each character following a newline
				for(size_t i=0; i<bufferString.size(); ++i)
				{
					if(m_newLine)
						printStamp();

					if(bufferString[i] == '\n')
						m_newLine = true;
					else
						m_newLine = false;

					m_realStream << bufferString[i];
				}

				// flush the underlying stream
				m_realStream.flush();

				// reset buffer
				this->str("");

				return 0;
			}

			std::basic_ostream<charT, Traits> const& getRealStream() const
			{
				return m_realStream;
			}

		private:
			std::basic_ostream<charT, Traits>& m_realStream;
			bool m_newLine;

			void printStamp()
			{
				m_realStream << "[00:00:00] ";
			}
		};

		LogBuffer m_buffer;

	public:
		BasicLogStream(std::basic_ostream<charT, Traits>& stream)
		:
			std::basic_ostream<charT, Traits>(&m_buffer),
			m_buffer(stream)
		{
		}

		LogBuffer const& getBuffer() const
		{
			return m_buffer;
		}
	};

	typedef BasicLogStream<char> LogStream;
}

