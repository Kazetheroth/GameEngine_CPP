#pragma once

#include "InfraStructure.h"

#include <chrono>
#include <vector>
#include <functional>
#include <thread>

using namespace std;

namespace ESGI
{
	struct TimeSource
	{
		using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
		static TimePoint now() { return std::chrono::high_resolution_clock::now(); }
	};

	struct Timer
	{
		double Delay;
		double CurrentTime;
		bool Repeat;
	};

	struct Clock : public InfraStructure
	{
		std::vector<std::pair<Timer, std::function<void()>>> m_Timers;

		TimeSource::TimePoint TimePointAtStartup;
		TimeSource::TimePoint PreviousTimePoint;
		TimeSource::TimePoint CurrentTimePoint;

		double TimeSinceStartup = 0.0;
		double ElapsedTime = 0.0;

		bool Initialize() final;
		void DeInitialize() final;

		void RunUpdate();
		// ce n'est pas une fonction virtuelle !
		thread Update();

		void AddTimer(Timer& timer, std::function<void(void)> event)
		{
			m_Timers.push_back({ timer, event });
		}
	};
}