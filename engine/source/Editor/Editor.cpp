#include "pch.h"
#include "Editor.h"

SPONZA_RENDER_NAMESPACE_BEGIN
	Editor::Editor()
	{
		LOG_DEV_INFO("Editor Start");
	}

	Editor::~Editor()
	{
		LOG_DEV_INFO("Editor End");
	}

	void Editor::Init(Engine* engineRuntime)
	{
		SPONZA_RENDER_ASSERT(engineRuntime, "Engine runtime is null");

		m_pEngineRuntime = engineRuntime;
	}

	void Editor::Run()
	{
		SPONZA_RENDER_ASSERT(m_pEngineRuntime, "Engine runtime is null");

		float deltaTime;
		while (true) {
			LOG_DEV_INFO("Editor is running...");
			deltaTime = m_pEngineRuntime->Tick();
			if (!m_pEngineRuntime->TickOneFrame(deltaTime)) {
				break;
			}
		}
	}

	void Editor::Clear()
	{
	}

SPONZA_RENDER_NAMESPACE_END
