#include <vulkan/vulkan.h>
#include <stdio.h>
#include <vector>

int main()
{
	VkInstance instance = nullptr;
	std::vector<VkPhysicalDevice> physicalDevices;

	VkResult result = VK_SUCCESS;
	VkApplicationInfo appInfo = {};
	VkInstanceCreateInfo instanceCreateInfo = {};

	// A generic application info structure
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Application";
	appInfo.applicationVersion = 1;
	appInfo.apiVersion = VK_MAKE_VERSION(1, 0, 0);

	// Create the instance
	instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instanceCreateInfo.pApplicationInfo = &appInfo;

	result = vkCreateInstance(&instanceCreateInfo, nullptr, &instance);
	if (result == VK_SUCCESS)
	{
		// First figure out how many devices are in the system
		uint32_t physicalDeviceCount = 0;
		vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, nullptr);
		if (result == VK_SUCCESS)
		{
			printf("physicalDeviceCount = %u\n", physicalDeviceCount);
			physicalDevices.resize(physicalDeviceCount);
			vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, &physicalDevices[0]);
		}
	}

	return 0;
}
