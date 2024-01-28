#include "pch.h"
#include "Engine.h"

SPONZA_RENDER_NAMESPACE_BEGIN

Engine::Engine()
{
	std::cout << "Engine::Engine()" << std::endl;
}

Engine::~Engine()
{
	std::cout << "Engine::~Engine()" << std::endl;

}

void Engine::Init()
{
	std::cout << "Engine::Init()" << std::endl;
}

void Engine::ShutdownEngine()
{
	std::cout << "Engine::ShutdownEngine()" << std::endl;
}

SPONZA_RENDER_NAMESPACE_END