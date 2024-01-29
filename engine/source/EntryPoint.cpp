#pragma once

#include "pch.h"

#include "Editor/Editor.h"
#include "Runtime/Engine.h"

#ifdef SPONZA_RENDER_PLATFORM_WINDOWS

// Entry point
int main(int argc, char** argv)
{
	LOG_DEV_WARN("Initialize Log!");

	auto& engine = SponzaRender::Engine::Get();
	auto& editor = SponzaRender::Editor::Get();
	engine.Init();
	editor.Init();
	editor.Run();
	editor.Clear();
	engine.ShutdownEngine();

	while(true) {
		std::cout << "Hello World" << std::endl;
	}

	EXIT_SUCCESS;
}

#endif
