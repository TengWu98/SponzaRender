#pragma once

#include "Runtime/Function/Window/Window.h"

SPONZA_RENDER_NAMESPACE_BEGIN
	class RuntimeGlobalContext {
	public:
		RuntimeGlobalContext();
		~RuntimeGlobalContext();

		void Init();
		void Clear();

	public:
		std::shared_ptr<Window> m_spWindowSystem;
	};

	extern RuntimeGlobalContext g_runtimeGlobalContext;

SPONZA_RENDER_NAMESPACE_END
