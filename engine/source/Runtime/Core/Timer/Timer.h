#pragma once

#include <chrono>

SPONZA_RENDER_NAMESPACE_BEGIN
	class Timer {
	public:
		Timer() noexcept;
		float Mark() noexcept;
		float Peek() const noexcept;

	private:
		std::chrono::steady_clock::time_point last;
	};

SPONZA_RENDER_NAMESPACE_END
