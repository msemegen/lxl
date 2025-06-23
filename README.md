# Introduction

**LXL** is part of the **LX** project, which aims to provide a lightweight and user friendly platform supporting modern graphics APIs such as Vulkan and DirectX12.\
**LXL** (LX Loader) is a library for loading Vulkan API functions, with built-in support for concurrent multi-device usage handled automatically, requiring no explicit configuration. 

# Supported platforms

* ✅  Windows
* ❌  Linux
* ❌  MacOS
* ❌  Android

# Vulkan supprt

* ✅  1.0
* ❌  1.1
* ❌  1.2
* ❌  1.3
* ❌  1.4

Instance extensions:
* VK_KHR_surface
* VK_KHR_win32_surface
* VK_EXT_debug_utils

Device extensions:
* VK_KHR_swapchain

# CMake support

Not ready

# Sample
	#include <lx/lx.hpp>

	//...

	std::uint32_t loaded_vulkan_version = lxlCreate();

	// Vulkan stuff
	// ...

	lxlDestroy();