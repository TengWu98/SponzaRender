#include "pch.h"
#include "RuntimeGlobalContext.h"

SPONZA_RENDER_NAMESPACE_BEGIN
	RuntimeGlobalContext g_runtimeGlobalContext;

	SponzaRender::RuntimeGlobalContext::RuntimeGlobalContext()
	{
	}

	SponzaRender::RuntimeGlobalContext::~RuntimeGlobalContext()
	{
	}

	void SponzaRender::RuntimeGlobalContext::Init()
	{
		// create window
		m_spWindowSystem = Window::Create(WindowCreateInfo(L"SponzaRender", 1280, 720));
		SPONZA_RENDER_ASSERT(m_spWindowSystem, "Window must not be null.");


	}

	void SponzaRender::RuntimeGlobalContext::Clear()
	{
		// clear window
		m_spWindowSystem.reset();
	}

SPONZA_RENDER_NAMESPACE_END
