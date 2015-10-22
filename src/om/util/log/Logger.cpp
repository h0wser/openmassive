#include "Logger.hpp"


using namespace om;

LogConfig Logger::defaultConfig;
std::unordered_map<std::string, std::unique_ptr<Logger>> Logger::loggers;
std::mutex Logger::loggersLock;


Logger& Logger::get(std::string const& name, LogConfig const& config)
{
	std::lock_guard<std::mutex> guard(Logger::loggersLock);

	if(!Logger::loggerExists(name))
	{
		Logger::createNewLogger(name, config);
	}

	return *Logger::loggers[name];
}
Logger& Logger::get(std::string const& name)
{
	return Logger::get(name, Logger::defaultConfig);
}

void Logger::create(std::string const& name)
{
	Logger::get(name, Logger::defaultConfig);
}

void Logger::create(std::string const& name, LogConfig const& config)
{
	Logger::get(name, config);
}

void Logger::setDefaultFormat(LogConfig const& config)
{
	Logger::defaultConfig = config;
}

bool Logger::loggerExists(std::string const& name)
{
	return Logger::loggers.find(name) != Logger::loggers.end();
}

void Logger::createNewLogger(std::string const& name, LogConfig const& config)
{
	Logger* new_Logger = new Logger(name, config);
	Logger::loggers[name].reset(new_Logger);
}

Logger::Logger(std::string const& name, LogConfig const& config)
	: m_name(name), m_config(config)
{
	// assign streams
	m_streams[Severity::TRACE].reset(new om::LogStream(std::cout));
	m_streams[Severity::DEBUG].reset(new om::LogStream(std::cout));
	m_streams[Severity::INFO].reset(new om::LogStream(std::cout));
	m_streams[Severity::WARNING].reset(new om::LogStream(std::cerr));
	m_streams[Severity::ERROR].reset(new om::LogStream(std::cerr));
	m_streams[Severity::FATAL].reset(new om::LogStream(std::cerr));
}

Logger::~Logger()
{
}

LogStream& Logger::trace()
{
	return *m_streams[Severity::TRACE];
}

LogStream& Logger::debug()
{
	return *m_streams[Severity::DEBUG];
}

LogStream& Logger::info()
{
	return *m_streams[Severity::INFO];
}

LogStream& Logger::warning()
{
	return *m_streams[Severity::WARNING];
}

LogStream& Logger::error()
{
	return *m_streams[Severity::ERROR];
}

LogStream& Logger::fatal()
{
	return *m_streams[Severity::FATAL];
}

