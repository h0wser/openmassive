#pragma once

#include "om/Uncopiable.hpp"

#include "LogConfig.hpp"
#include "LogStream.hpp"

#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <map>


namespace om
{
	enum Severity
	{
		TRACE   = 1000,
		DEBUG   = 2000,
		INFO    = 3000,
		WARNING = 4000,
		ERROR   = 5000,
		FATAL   = 6000
	};

	class Logger final : Uncopiable
	{
	public:
		static Logger& get(std::string const& name);
		static Logger& get(std::string const& name, LogConfig const& config);
		static void create(std::string const& name);
		static void create(std::string const& name, LogConfig const& config);
		static void setDefaultFormat(LogConfig const& config);

		~Logger();

		LogStream& trace();
		LogStream& debug();
		LogStream& info();
		LogStream& warning();
		LogStream& error();
		LogStream& fatal();

		template <typename T>
		LogStream& operator<<(T const& value)
		{
			return static_cast<LogStream&>(info() << value);
		}

	private:
		Logger(std::string const& name, LogConfig const& config);

		std::string m_name;
		LogConfig m_config;

		std::map<Severity, std::unique_ptr<LogStream>> m_streams;

		static LogConfig defaultConfig;
		static std::unordered_map<std::string, std::unique_ptr<Logger>> loggers;
		static std::mutex loggersLock;

		static bool loggerExists(std::string const& name);
		static void createNewLogger(std::string const& name, LogConfig const& config);
	};
}

