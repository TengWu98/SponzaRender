#pragma once

// namespace
#ifndef SPONZA_RENDER_NAMESPACE_BEGIN
#define SPONZA_RENDER_NAMESPACE_BEGIN \
	namespace  SponzaRender{
#endif 

#ifndef SPONZA_RENDER_NAMESPACE_END
#define SPONZA_RENDER_NAMESPACE_END \
	}
#endif

// bit operation
#define BIT(x) (1<<x)

// assert
#ifdef SPONZA_RENDER_ENABLE_ASSERTS
#define SPONZA_RENDER_ASSERT(x,...) { if(!(x)) { LOG_DEV_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}

#endif 