#pragma once

#include <chrono>
#include <thread>


namespace om
{
	class LoopDriven
	{
	public:
		virtual ~LoopDriven() {};

		virtual void tick() = 0;

		void run()
		{
			m_running = true;
			while(m_running)
			{
				tick();
				std::this_thread::sleep_for(
						std::chrono::milliseconds(1));
			}
		}

		void stop()
		{
			m_running = false;
		}

	private:
		volatile bool m_running;
	};
}
