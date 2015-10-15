#include <dawn/log/logger.hpp>

int main()
{
	dawn::logger& logger = dawn::logger::get("MAIN");
	logger.info() << "Hello" << std::endl;
	return 0;
}
