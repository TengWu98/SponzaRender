#pragma once

SPONZA_RENDER_NAMESPACE_BEGIN
	class Editor : public Singleton<Editor> {
	public:
		Editor();
		virtual ~Editor();

		void Init();
		void Run();
		void Clear();
	private:
	};

SPONZA_RENDER_NAMESPACE_END
