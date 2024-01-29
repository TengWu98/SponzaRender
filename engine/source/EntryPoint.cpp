#pragma once

#include "pch.h"

#include "Editor/Editor.h"
#include "Runtime/Engine.h"

#ifdef SPONZA_RENDER_PLATFORM_WINDOWS

// Entry point
int main(int argc, char** argv)
{
	auto& engine = SponzaRender::Engine::Get();
	auto& editor = SponzaRender::Editor::Get();
	engine.Init();
	editor.Init();
	editor.Run();
	editor.Clear();
	engine.ShutdownEngine();

	EXIT_SUCCESS;
}

#endif
