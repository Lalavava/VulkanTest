#pragma once

#include <vector>
#include <vulkan\vulkan.h>

class Instance
{
public:
	Instance();
	Instance(std::vector<std::string> layerNames,std::vector<std::string> extensionNames);
	~Instance();

	std::vector<VkPhysicalDevice> const & getPhysicalDevices() const &;

private:
	VkInstance mInstance;
};