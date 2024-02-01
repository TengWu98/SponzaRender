#pragma once
#include "Function/Window/Window.h"

SPONZA_RENDER_NAMESPACE_BEGIN
	class Engine {
	public:
		Engine();
		~Engine();

		void Init();
		void Run();
		void Clear();
		void ShutdownEngine();

		float Tick();
		bool TickOneFrame(float deltaTime);

	protected:
		void LogicalTick(float deltaTime);
		bool RendererTick(float deltaTime);

	private:
		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;

	private:
		Timer m_timer;
		std::shared_ptr<Window> m_spWindow;
	};

SPONZA_RENDER_NAMESPACE_END
