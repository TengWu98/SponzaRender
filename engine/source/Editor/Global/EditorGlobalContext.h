#pragma once

SPONZA_RENDER_NAMESPACE_BEGIN
	class EditorGlobalContext {
	public:
		EditorGlobalContext();
		~EditorGlobalContext();

		void Init();
		void Clear();
	};

	extern EditorGlobalContext g_editorGlobalContext;

SPONZA_RENDER_NAMESPACE_END
