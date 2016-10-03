#include "stdafx.h"
#include "Instance.h"


Instance::Instance()
{
	VkInstanceCreateInfo info{
		VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
		nullptr,
		0,
		nullptr,
		0,
		nullptr,
		0,
		nullptr
	};

	vkCreateInstance(&info, nullptr, &mInstance);
}

Instance::Instance(std::vector<std::string> layerNames,std::vector<std::string> extensionNames)
{
	char const * * const cLayerNames = new char const *[layerNames.size()];
	for (int i = 0;i < layerNames.size();++i)
		cLayerNames[i] = layerNames[i].c_str();

	char const * * const cExtensionNames = new char const *[extensionNames.size()];
	for (int i = 0; i < extensionNames.size(); ++i)
		cExtensionNames[i] = extensionNames[i].c_str();

	VkInstanceCreateInfo const info{
		VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
		nullptr,
		0,
		nullptr,
		static_cast<uint32_t>(layerNames.size()),
		cLayerNames,
		static_cast<uint32_t>(extensionNames.size()),
		cExtensionNames
	};

	switch (vkCreateInstance(&info,nullptr,&mInstance)) {
	case VK_SUCCESS:
		break;

	case VK_ERROR_INCOMPATIBLE_DRIVER:
		break;

	default:
		break;
	}

	delete[] cLayerNames;
	delete[] cExtensionNames;
}


Instance::~Instance()
{
	vkDestroyInstance(mInstance,nullptr);
}
