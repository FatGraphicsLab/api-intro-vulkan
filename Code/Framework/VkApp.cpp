#include "Framework/VkApp.h"

VkApp* GApp = nullptr;

VkApp::VkApp()
{
	vkInstance_ = nullptr;

	InitVulkan();
}

VkApp::~VkApp()
{
	ShutdownVulkan();
}

void VkApp::InitVulkan()
{
	VkResult result;
	VkApplicationInfo appInfo = {};
	VkInstanceCreateInfo instanceCreateInfo = {};

	// A generic application info structure
	appInfo.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName   = "ApiIntroVulkan";
	appInfo.applicationVersion = 1;
	appInfo.apiVersion         = VK_MAKE_VERSION(1, 0, 0);

	// Create the instance
	instanceCreateInfo.sType            = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instanceCreateInfo.pApplicationInfo = &appInfo;

	VKCHK(vkCreateInstance(&instanceCreateInfo, nullptr, &vkInstance_));

	// First figure out how many devices are in the system
	uint32_t physicalDeviceCount = 0;
	VKCHK(vkEnumeratePhysicalDevices(vkInstance_, &physicalDeviceCount, nullptr));

	printf("physicalDeviceCount = %u\n", physicalDeviceCount);
	vkPhysicalDevices_.resize(physicalDeviceCount);
	vkEnumeratePhysicalDevices(vkInstance_, &physicalDeviceCount, &vkPhysicalDevices_[0]);
}

void VkApp::ShutdownVulkan()
{
	vkDestroyInstance(vkInstance_, nullptr);
}

int VkApp::Run()
{
	return 0;
}
