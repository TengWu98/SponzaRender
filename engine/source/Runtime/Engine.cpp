#include "pch.h"
#include "Engine.h"

SPONZA_RENDER_NAMESPACE_BEGIN
	Engine::Engine()
	{
		LOG_DEV_INFO("Engine Start");
	}

	Engine::~Engine()
	{
	}

	void Engine::Init()
	{
	}

	float Engine::Tick()
	{
		return m_timer.Mark();
	}

	bool Engine::TickOneFrame(float deltaTime)
	{
		LogicalTick(deltaTime);
		if (!RendererTick(deltaTime)) {
			return false;
		}
		return true;
	}

	void Engine::Run()
	{
		// create window
		m_spWindow = Window::Create(WindowProps(L"SponzaRender", 1280, 720));
		SPONZA_RENDER_ASSERT(m_spWindow, "Window is null");

		// loop
		// TODO(WT) modifiy true to a condition(window->ShouldClose)
		while (true) {
			float deltaTime = Tick();
			if (!TickOneFrame(deltaTime)) {
				break;
			}
		}
	}

	void Engine::Clear()
	{
	}

	void Engine::LogicalTick(float deltaTime)
	{
	}

	bool Engine::RendererTick(float deltaTime)
	{
		return true;
	}


	void Engine::ShutdownEngine()
	{
		LOG_DEV_INFO("Engine Shutdown");
	}

SPONZA_RENDER_NAMESPACE_END
