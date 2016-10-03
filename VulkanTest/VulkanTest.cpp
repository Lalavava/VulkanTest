// VulkanTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <vulkan\vulkan.h>

int main()
{
    VkApplicationInfo app_info{
        VK_STRUCTURE_TYPE_APPLICATION_INFO,
        nullptr,
        "VulkanTest",
        1,
        "KiKiGameEngine",
        1,
        VK_API_VERSION_1_0
    };

    VkInstanceCreateInfo inst_info{
        VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        nullptr,
        0,
        &app_info,
        0,
        nullptr,
        0,
        nullptr
    };

    VkInstance inst;
    switch (vkCreateInstance(&inst_info,nullptr,&inst)) {
    case VK_SUCCESS:
        std::cout << "Vulkanʵ�������ɹ�" << std::endl;
        break;

    case VK_ERROR_INCOMPATIBLE_DRIVER:
        std::cout << "Vulkanʵ������ʧ��:�������򲻼���" << std::endl;
        break;

    default:
        std::cout << "Vulkanʵ������ʧ��:δ֪����" << std::endl;
    }

    std::vector<VkPhysicalDevice> gpus;
    uint32_t gpu_count;
    vkEnumeratePhysicalDevices(inst,&gpu_count,nullptr);
    gpus.resize(gpu_count);
    vkEnumeratePhysicalDevices(inst,&gpu_count,gpus.data());
    std::cout << gpu_count << std::endl;

    for (auto &&gpu : gpus) {
        uint32_t count;
        vkEnumerateDeviceLayerProperties(gpu,&count,nullptr);
        std::vector<VkLayerProperties> layer_properties(count);
        vkEnumerateDeviceLayerProperties(gpu,&count,layer_properties.data());
        for (auto &&layer_property : layer_properties) {
            std::cout << layer_property.layerName << std::endl;
            std::cout << layer_property.description << std::endl;
        }
    }


    for (auto &&gpu : gpus) {
        uint32_t queue_family_count;
        vkGetPhysicalDeviceQueueFamilyProperties(gpu,&queue_family_count,nullptr);

    }

    float queue_priorities[1]{
        0.0f
    };

    VkDeviceQueueCreateInfo queue_info{
        VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
        nullptr,
        0,
        1,
        1,
        queue_priorities
    };

    vkDestroyInstance(inst,nullptr);

    //�޸�ע��
    return 0;
}

