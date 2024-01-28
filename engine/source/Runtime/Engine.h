#pragma once

SPONZA_RENDER_NAMESPACE_BEGIN
	class Engine : public Singleton<Engine> {
	public:
		Engine();
		~Engine();

		void Init();
		void ShutdownEngine();

	private:
	};

SPONZA_RENDER_NAMESPACE_END
