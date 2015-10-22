#include <gtest/gtest.h>
#include <iostream>

#include <om/util/log/Logger.hpp>

TEST(util_Logger, streams)
{
	// Tests that the default streams correspond to the correct
	// standard streams.
	om::Logger& logger = om::Logger::get("test");

	ASSERT_EQ(&logger.trace().getBuffer().getRealStream(), &std::cout);
	ASSERT_EQ(&logger.debug().getBuffer().getRealStream(), &std::cout);
	ASSERT_EQ(&logger.info().getBuffer().getRealStream(), &std::cout);

	ASSERT_EQ(&logger.warning().getBuffer().getRealStream(), &std::cerr);
	ASSERT_EQ(&logger.error().getBuffer().getRealStream(), &std::cerr);
	ASSERT_EQ(&logger.fatal().getBuffer().getRealStream(), &std::cerr);
}
