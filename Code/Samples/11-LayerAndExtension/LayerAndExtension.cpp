// Application --1:*-- VkInstance -1:*- VkPhysicalDevice -1:*- VkLogicalDevice -1:*- 

#include "Framework/VkApp.h"

class LayerAndExtensionApp : public VkApp
{
public:
	virtual int Run() override;

protected:
	void PrintInstanceLayerProperties();
	void PrintInstanceExtenionProperties();
};

int LayerAndExtensionApp::Run()
{
	PrintInstanceLayerProperties();
	PrintInstanceExtenionProperties();
	return 0;
}

void LayerAndExtensionApp::PrintInstanceLayerProperties()
{
	VKCHK_DECL;
	uint32_t numInstanceLayers = 0;
	std::vector<VkLayerProperties> instanceLayerProperties;

	// Query the instance layers
	VKCHK(vkEnumerateInstanceLayerProperties(&numInstanceLayers, nullptr));

	// If there are any layers, query their properties
	if (numInstanceLayers != 0)
	{
		instanceLayerProperties.resize(numInstanceLayers);
		VKCHK(vkEnumerateInstanceLayerProperties(&numInstanceLayers, instanceLayerProperties.data()));

		for (uint32_t i = 0; i < numInstanceLayers; ++i)
		{
			printf("Instance Layer #%u\n", i);
			printf("  layerName: %s\n", instanceLayerProperties[i].layerName);
			printf("  specVersion: %u\n", instanceLayerProperties[i].specVersion);
			printf("  implementationVersion: %u\n", instanceLayerProperties[i].implementationVersion);
			printf("  description: %s\n", instanceLayerProperties[i].description);
			printf("\n");
		}
	}
}

void LayerAndExtensionApp::PrintInstanceExtenionProperties()
{
	VKCHK_DECL;
	uint32_t numInstanceExtensions = 0;
	std::vector<VkExtensionProperties> instanceExtensionProperties;

	// Query the instance extensions
	VKCHK(vkEnumerateInstanceExtensionProperties(nullptr, &numInstanceExtensions, nullptr));

	// If there are any extensions, query their properties
	if (numInstanceExtensions != 0)
	{
		instanceExtensionProperties.resize(numInstanceExtensions);
		VKCHK(vkEnumerateInstanceExtensionProperties(nullptr,
			&numInstanceExtensions, instanceExtensionProperties.data()));

		printf("Instance Extensions\n");
		for (uint32_t i = 0; i < numInstanceExtensions; ++i)
		{
			printf("  Name: %s, specVersion: %u\n", instanceExtensionProperties[i].extensionName,
				instanceExtensionProperties[i].specVersion);
		}
	}
}

int main()
{
	LayerAndExtensionApp app;
	GApp = &app;
	return GApp->Run();
}
