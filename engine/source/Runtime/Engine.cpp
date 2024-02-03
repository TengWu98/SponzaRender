#include "pch.h"
#include "Engine.h"

#include "Function/Global/RuntimeGlobalContext.h"


SPONZA_RENDER_NAMESPACE_BEGIN
	Engine::Engine()
	{
	}

	Engine::~Engine()
	{
	}

	void Engine::Init()
	{
		g_runtimeGlobalContext.Init();

		LOG_DEV_INFO("Initialize Engine");
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

	void Engine::LogicalTick(float deltaTime)
	{
	}

	bool Engine::RendererTick(float deltaTime)
	{
		return true;
	}


	void Engine::Shutdown()
	{
		LOG_DEV_INFO("Shutdown Engine");
	}

SPONZA_RENDER_NAMESPACE_END
