#pragma once

#include <chrono>


namespace om
{
	namespace time
	{
		typedef std::chrono::system_clock Clock;
		typedef Clock::duration Duration;
		typedef Clock::time_point TimePoint;
	}
}
