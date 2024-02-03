#pragma once
#include "Runtime/Engine.h"

SPONZA_RENDER_NAMESPACE_BEGIN
	class Editor {
		friend class Engine;

	public:
		Editor();
		~Editor();

		void Init(Engine* engineRuntime);
		void Run();
		void Close();

	private:
		Engine* m_pEngineRuntime;
	};

SPONZA_RENDER_NAMESPACE_END
