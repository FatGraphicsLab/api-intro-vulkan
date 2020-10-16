#pragma once

#include "Framework/VkHeaders.h"

class VkApp
{
public:
	VkApp();
	virtual ~VkApp();

	virtual void InitVulkan();
	virtual void ShutdownVulkan();
	
	virtual int Run();

private:
	VkInstance vkInstance_;
	std::vector<VkPhysicalDevice> vkPhysicalDevices_;
};

extern VkApp* GApp;
