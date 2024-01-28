#include "pch.h"
#include "Editor.h"

SPONZA_RENDER_NAMESPACE_BEGIN
	Editor::Editor()
	{
		std::cout << "Editor::Editor()" << std::endl;
	}

	Editor::~Editor()
	{
		std::cout << "Editor::~Editor()" << std::endl;
	}

	void Editor::Init()
	{
		std::cout << "Editor::Init()" << std::endl;
	}

	void Editor::Run()
	{
		std::cout << "Editor::Run()" << std::endl;
	}

	void Editor::Clear()
	{
		std::cout << "Editor::Clear()" << std::endl;
	}

SPONZA_RENDER_NAMESPACE_END
