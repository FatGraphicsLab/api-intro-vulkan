// Application --1:*-- VkInstance -1:*- VkPhysicalDevice -1:*- VkLogicalDevice -1:*- 

#include "Framework/VkApp.h"

class InstanceAndDeviceApp : public VkApp
{
public:
	virtual int Run() override;

protected:
	void PrintPhysicalDeviceProperties();
	const char* GetPhysicalDeviceTypeName(VkPhysicalDeviceType type);
	const char* GetMemoryPropertyDesc(VkMemoryPropertyFlags flags);
	const char* GetMemoryHeapDesc(VkMemoryHeapFlags flags);
};

int InstanceAndDeviceApp::Run()
{
	PrintPhysicalDeviceProperties();
	return 0;
}

const char* InstanceAndDeviceApp::GetPhysicalDeviceTypeName(VkPhysicalDeviceType type)
{
	switch (type)
	{
	case VK_PHYSICAL_DEVICE_TYPE_OTHER:          return "Other";
	case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU: return "IntegratedGPU";
	case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:   return "DiscreteGPU";
	case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:    return "VirtualGPU";
	case VK_PHYSICAL_DEVICE_TYPE_CPU:            return "CPU";
	default:                                     return "Unknown";
	}
}

const char* InstanceAndDeviceApp::GetMemoryPropertyDesc(VkMemoryPropertyFlags flags)
{
	static char desc[512];

	bool prefix = false;
	desc[0] = '\0';

#define DESC_CONCAT(bit, s) \
	if (flags & bit) { \
		if (prefix) { \
			strcat(desc, ","); \
		} \
		strcat(desc, s); \
		prefix = true; \
	}

	DESC_CONCAT(VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, "DeviceLocal");
	DESC_CONCAT(VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT, "HostVisible");
	DESC_CONCAT(VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, "HostCoherent");
	DESC_CONCAT(VK_MEMORY_PROPERTY_HOST_CACHED_BIT, "HostCached");
	DESC_CONCAT(VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT, "LazilyAllocated");

#undef DESC_CONCAT

	return desc;
}

const char* InstanceAndDeviceApp::GetMemoryHeapDesc(VkMemoryHeapFlags flags)
{
	static char desc[512];

	desc[0] = '\0';
	if (flags & VK_MEMORY_HEAP_DEVICE_LOCAL_BIT)
		strcat(desc, "DeviceLocal");

	return desc;
}

void InstanceAndDeviceApp::PrintPhysicalDeviceProperties()
{
	for (size_t i = 0; i < vkPhysicalDevices_.size(); ++i)
	{
		printf("Phsical Device #%zu\n", i);

		VkPhysicalDeviceProperties deviceProperty;
		vkGetPhysicalDeviceProperties(vkPhysicalDevices_[i], &deviceProperty);
		printf("  Device Properties\n");
		printf("    apiVersion: %u\n", deviceProperty.apiVersion);
		printf("    driverVersion: %u\n", deviceProperty.driverVersion);
		printf("    vendorID: %u\n", deviceProperty.vendorID);
		printf("    deviceID: %u\n", deviceProperty.deviceID);
		printf("    deviceType: %s\n", GetPhysicalDeviceTypeName(deviceProperty.deviceType));
		printf("    deviceName: %s\n", deviceProperty.deviceName);


		VkPhysicalDeviceMemoryProperties memoryProperty;
		vkGetPhysicalDeviceMemoryProperties(vkPhysicalDevices_[i], &memoryProperty);
		printf("  Memory Properties\n");
		printf("    memoryTypeCount: %u\n", memoryProperty.memoryTypeCount);
		for (uint32_t j = 0; j < memoryProperty.memoryTypeCount; ++j)
		{
			VkMemoryType& memType = memoryProperty.memoryTypes[j];
			printf("      #%u: heapIndex:%u, flags:%s\n", j, memType.heapIndex, GetMemoryPropertyDesc(memType.propertyFlags));
		}
		printf("    memoryHeapCount: %u\n", memoryProperty.memoryHeapCount);
		for (uint32_t j = 0; j < memoryProperty.memoryHeapCount; ++j)
		{
			VkMemoryHeap& memHeap = memoryProperty.memoryHeaps[j];
			printf("      #%u: size:%lluMb, flags:%s\n", j, memHeap.size/1024/1024, GetMemoryHeapDesc(memHeap.flags));
		}

		printf("\n");
	}
}

int main()
{
	InstanceAndDeviceApp app;
	GApp = &app;
	return GApp->Run();
}

#if 0
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
#endif
