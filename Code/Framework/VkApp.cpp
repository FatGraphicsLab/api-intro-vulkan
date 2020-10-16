#include "Framework/VkApp.h"

VkApp* GApp = nullptr;
VkInstance GVkInstance = nullptr;

VkApp::VkApp()
{
#if FAT_OS_WINDOWS && FAT_DEBUG_BUILD
	// Enable run-time memory check for debug builds
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	vkInstance_ = nullptr;
	vkLogicalDevice_ = nullptr;

	InitVulkan();
}

VkApp::~VkApp()
{
	ShutdownVulkan();
}

void VkApp::InitVulkan()
{
	VKCHK_DECL;
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
	GVkInstance = vkInstance_;

	// First figure out how many devices are in the system
	uint32_t physicalDeviceCount = 0;
	VKCHK(vkEnumeratePhysicalDevices(vkInstance_, &physicalDeviceCount, nullptr));

	vkPhysicalDevices_.resize(physicalDeviceCount);
	vkEnumeratePhysicalDevices(vkInstance_, &physicalDeviceCount, &vkPhysicalDevices_[0]);

	// Create logical device on physicalDevice[0]
	VkPhysicalDeviceFeatures supportedFeatures;
	VkPhysicalDeviceFeatures requiredFeatures = {};

	vkGetPhysicalDeviceFeatures(vkPhysicalDevices_[0], &supportedFeatures);

	requiredFeatures.multiDrawIndirect  = supportedFeatures.multiDrawIndirect;
	requiredFeatures.tessellationShader = VK_TRUE;
	requiredFeatures.geometryShader     = VK_TRUE;

	const VkDeviceQueueCreateInfo deviceQueueCreateInfo = {
		VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,  // sType
		nullptr,                                     // pNext
		0,                                           // flags
		0,                                           // queueFamilyIndex
		1,                                           // queueFamilyCount,
		nullptr                                      // pQueuePriorities
	};

	const VkDeviceCreateInfo deviceCreateInfo = {
		VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,        // sType
		nullptr,                                     // pNext
		0,                                           // flags
		1,                                           // queueCreateInfoCount
		&deviceQueueCreateInfo,                      // pQueueCreateInfos
		0,                                           // enabledLayerCount
		nullptr,                                     // ppEnabledLayerNames
		0,                                           // enabledExtensionCount
		nullptr,                                     // ppEnabledExtensionNames
		&requiredFeatures                            // pEnabledFeatures
	};

	VKCHK(vkCreateDevice(vkPhysicalDevices_[0], &deviceCreateInfo, nullptr, &vkLogicalDevice_));
}

void VkApp::ShutdownVulkan()
{
	VKCHK_DECL;
	VKCHK(vkDeviceWaitIdle(vkLogicalDevice_));
	vkDestroyDevice(vkLogicalDevice_, nullptr);
	vkDestroyInstance(vkInstance_, nullptr);
}

int VkApp::Run()
{
	return 0;
}
