#pragma once

#include "pch.h"

#include "Editor/Editor.h"
#include "Runtime/Engine.h"

#ifdef SPONZA_RENDER_PLATFORM_WINDOWS

// Entry point
int main(int argc, char** argv)
{
	LOG_DEV_INFO("Initialize Log");

	auto engine = new SponzaRender::Engine();
	engine->Init();

	auto editor = new SponzaRender::Editor();
	editor->Init(engine);

	editor->Run();

	editor->Close();
	engine->Shutdown();

	EXIT_SUCCESS;
}

#endif
