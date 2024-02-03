#include "pch.h"
#include "Editor.h"

SPONZA_RENDER_NAMESPACE_BEGIN
	Editor::Editor()
	{
	}

	Editor::~Editor()
	{
	}

	void Editor::Init(Engine* engineRuntime)
	{
		SPONZA_RENDER_ASSERT(engineRuntime, "Engine runtime must not be null.");

		m_pEngineRuntime = engineRuntime;

		LOG_DEV_INFO("Initialize Editor");
	}

	void Editor::Run()
	{
		SPONZA_RENDER_ASSERT(m_pEngineRuntime, "Engine runtime must not be null.");

		float deltaTime;
		while (true) {
			deltaTime = m_pEngineRuntime->Tick();
			if (!m_pEngineRuntime->TickOneFrame(deltaTime)) {
				break;
			}
		}
	}

	void Editor::Close()
	{
		m_pEngineRuntime = nullptr;

		LOG_DEV_INFO("Close Editor");
	}

SPONZA_RENDER_NAMESPACE_END
