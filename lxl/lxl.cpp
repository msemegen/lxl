// This file is part of the LX project.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#define VMA_IMPLEMENTATION
#include <lxl/lxl.hpp>

// std
#include <cassert>
#include <limits>
#include <unordered_map>

namespace {
HMODULE vk_driver_handle = nullptr;

struct DeviceFunctions
{
#if defined(VK_VERSION_1_0)
    PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers = nullptr;
    PFN_vkAllocateDescriptorSets vkAllocateDescriptorSets = nullptr;
    PFN_vkAllocateMemory vkAllocateMemory = nullptr;
    PFN_vkBeginCommandBuffer vkBeginCommandBuffer = nullptr;
    PFN_vkBindBufferMemory vkBindBufferMemory = nullptr;
    PFN_vkBindImageMemory vkBindImageMemory = nullptr;
    PFN_vkCmdBeginQuery vkCmdBeginQuery = nullptr;
    PFN_vkCmdBeginRenderPass vkCmdBeginRenderPass = nullptr;
    PFN_vkCmdBindDescriptorSets vkCmdBindDescriptorSets = nullptr;
    PFN_vkCmdBindIndexBuffer vkCmdBindIndexBuffer = nullptr;
    PFN_vkCmdBindPipeline vkCmdBindPipeline = nullptr;
    PFN_vkCmdBindVertexBuffers vkCmdBindVertexBuffers = nullptr;
    PFN_vkCmdBlitImage vkCmdBlitImage = nullptr;
    PFN_vkCmdClearAttachments vkCmdClearAttachments = nullptr;
    PFN_vkCmdClearColorImage vkCmdClearColorImage = nullptr;
    PFN_vkCmdClearDepthStencilImage vkCmdClearDepthStencilImage = nullptr;
    PFN_vkCmdCopyBuffer vkCmdCopyBuffer = nullptr;
    PFN_vkCmdCopyBufferToImage vkCmdCopyBufferToImage = nullptr;
    PFN_vkCmdCopyImage vkCmdCopyImage = nullptr;
    PFN_vkCmdCopyImageToBuffer vkCmdCopyImageToBuffer = nullptr;
    PFN_vkCmdCopyQueryPoolResults vkCmdCopyQueryPoolResults = nullptr;
    PFN_vkCmdDispatch vkCmdDispatch = nullptr;
    PFN_vkCmdDispatchIndirect vkCmdDispatchIndirect = nullptr;
    PFN_vkCmdDraw vkCmdDraw = nullptr;
    PFN_vkCmdDrawIndexed vkCmdDrawIndexed = nullptr;
    PFN_vkCmdDrawIndexedIndirect vkCmdDrawIndexedIndirect = nullptr;
    PFN_vkCmdDrawIndirect vkCmdDrawIndirect = nullptr;
    PFN_vkCmdEndQuery vkCmdEndQuery = nullptr;
    PFN_vkCmdEndRenderPass vkCmdEndRenderPass = nullptr;
    PFN_vkCmdExecuteCommands vkCmdExecuteCommands = nullptr;
    PFN_vkCmdFillBuffer vkCmdFillBuffer = nullptr;
    PFN_vkCmdNextSubpass vkCmdNextSubpass = nullptr;
    PFN_vkCmdPipelineBarrier vkCmdPipelineBarrier = nullptr;
    PFN_vkCmdPushConstants vkCmdPushConstants = nullptr;
    PFN_vkCmdResetEvent vkCmdResetEvent = nullptr;
    PFN_vkCmdResetQueryPool vkCmdResetQueryPool = nullptr;
    PFN_vkCmdResolveImage vkCmdResolveImage = nullptr;
    PFN_vkCmdSetBlendConstants vkCmdSetBlendConstants = nullptr;
    PFN_vkCmdSetDepthBias vkCmdSetDepthBias = nullptr;
    PFN_vkCmdSetDepthBounds vkCmdSetDepthBounds = nullptr;
    PFN_vkCmdSetEvent vkCmdSetEvent = nullptr;
    PFN_vkCmdSetLineWidth vkCmdSetLineWidth = nullptr;
    PFN_vkCmdSetScissor vkCmdSetScissor = nullptr;
    PFN_vkCmdSetStencilCompareMask vkCmdSetStencilCompareMask = nullptr;
    PFN_vkCmdSetStencilReference vkCmdSetStencilReference = nullptr;
    PFN_vkCmdSetStencilWriteMask vkCmdSetStencilWriteMask = nullptr;
    PFN_vkCmdSetViewport vkCmdSetViewport = nullptr;
    PFN_vkCmdUpdateBuffer vkCmdUpdateBuffer = nullptr;
    PFN_vkCmdWaitEvents vkCmdWaitEvents = nullptr;
    PFN_vkCmdWriteTimestamp vkCmdWriteTimestamp = nullptr;
    PFN_vkCreateBuffer vkCreateBuffer = nullptr;
    PFN_vkCreateBufferView vkCreateBufferView = nullptr;
    PFN_vkCreateCommandPool vkCreateCommandPool = nullptr;
    PFN_vkCreateComputePipelines vkCreateComputePipelines = nullptr;
    PFN_vkCreateDescriptorPool vkCreateDescriptorPool = nullptr;
    PFN_vkCreateDescriptorSetLayout vkCreateDescriptorSetLayout = nullptr;
    PFN_vkCreateEvent vkCreateEvent = nullptr;
    PFN_vkCreateFence vkCreateFence = nullptr;
    PFN_vkCreateFramebuffer vkCreateFramebuffer = nullptr;
    PFN_vkCreateGraphicsPipelines vkCreateGraphicsPipelines = nullptr;
    PFN_vkCreateImage vkCreateImage = nullptr;
    PFN_vkCreateImageView vkCreateImageView = nullptr;
    PFN_vkCreatePipelineCache vkCreatePipelineCache = nullptr;
    PFN_vkCreatePipelineLayout vkCreatePipelineLayout = nullptr;
    PFN_vkCreateQueryPool vkCreateQueryPool = nullptr;
    PFN_vkCreateRenderPass vkCreateRenderPass = nullptr;
    PFN_vkCreateSampler vkCreateSampler = nullptr;
    PFN_vkCreateSemaphore vkCreateSemaphore = nullptr;
    PFN_vkCreateShaderModule vkCreateShaderModule = nullptr;
    PFN_vkDestroyBuffer vkDestroyBuffer = nullptr;
    PFN_vkDestroyBufferView vkDestroyBufferView = nullptr;
    PFN_vkDestroyCommandPool vkDestroyCommandPool = nullptr;
    PFN_vkDestroyDescriptorPool vkDestroyDescriptorPool = nullptr;
    PFN_vkDestroyDescriptorSetLayout vkDestroyDescriptorSetLayout = nullptr;
    PFN_vkDestroyEvent vkDestroyEvent = nullptr;
    PFN_vkDestroyFence vkDestroyFence = nullptr;
    PFN_vkDestroyFramebuffer vkDestroyFramebuffer = nullptr;
    PFN_vkDestroyImage vkDestroyImage = nullptr;
    PFN_vkDestroyImageView vkDestroyImageView = nullptr;
    PFN_vkDestroyPipeline vkDestroyPipeline = nullptr;
    PFN_vkDestroyPipelineCache vkDestroyPipelineCache = nullptr;
    PFN_vkDestroyPipelineLayout vkDestroyPipelineLayout = nullptr;
    PFN_vkDestroyQueryPool vkDestroyQueryPool = nullptr;
    PFN_vkDestroyRenderPass vkDestroyRenderPass = nullptr;
    PFN_vkDestroySampler vkDestroySampler = nullptr;
    PFN_vkDestroySemaphore vkDestroySemaphore = nullptr;
    PFN_vkDestroyShaderModule vkDestroyShaderModule = nullptr;
    PFN_vkDeviceWaitIdle vkDeviceWaitIdle = nullptr;
    PFN_vkEndCommandBuffer vkEndCommandBuffer = nullptr;
    PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges = nullptr;
    PFN_vkFreeCommandBuffers vkFreeCommandBuffers = nullptr;
    PFN_vkFreeDescriptorSets vkFreeDescriptorSets = nullptr;
    PFN_vkFreeMemory vkFreeMemory = nullptr;
    PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements = nullptr;
    PFN_vkGetDeviceMemoryCommitment vkGetDeviceMemoryCommitment = nullptr;
    PFN_vkGetDeviceQueue vkGetDeviceQueue = nullptr;
    PFN_vkGetEventStatus vkGetEventStatus = nullptr;
    PFN_vkGetFenceStatus vkGetFenceStatus = nullptr;
    PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements = nullptr;
    PFN_vkGetImageSparseMemoryRequirements vkGetImageSparseMemoryRequirements = nullptr;
    PFN_vkGetImageSubresourceLayout vkGetImageSubresourceLayout = nullptr;
    PFN_vkGetPipelineCacheData vkGetPipelineCacheData = nullptr;
    PFN_vkGetQueryPoolResults vkGetQueryPoolResults = nullptr;
    PFN_vkGetRenderAreaGranularity vkGetRenderAreaGranularity = nullptr;
    PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges = nullptr;
    PFN_vkMapMemory vkMapMemory = nullptr;
    PFN_vkMergePipelineCaches vkMergePipelineCaches = nullptr;
    PFN_vkQueueBindSparse vkQueueBindSparse = nullptr;
    PFN_vkQueueSubmit vkQueueSubmit = nullptr;
    PFN_vkQueueWaitIdle vkQueueWaitIdle = nullptr;
    PFN_vkResetCommandBuffer vkResetCommandBuffer = nullptr;
    PFN_vkResetCommandPool vkResetCommandPool = nullptr;
    PFN_vkResetDescriptorPool vkResetDescriptorPool = nullptr;
    PFN_vkResetEvent vkResetEvent = nullptr;
    PFN_vkResetFences vkResetFences = nullptr;
    PFN_vkSetEvent vkSetEvent = nullptr;
    PFN_vkUnmapMemory vkUnmapMemory = nullptr;
    PFN_vkUpdateDescriptorSets vkUpdateDescriptorSets = nullptr;
    PFN_vkWaitForFences vkWaitForFences = nullptr;
#if defined(VK_KHR_swapchain)
    PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR = nullptr;
    PFN_vkGetSwapchainImagesKHR vkGetSwapchainImagesKHR = nullptr;
    PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR = nullptr;
#endif
#endif
};

template<typename Function> Function load_instance_level_function(VkInstance vk_instance_a, const char* name_a)
{
    return reinterpret_cast<Function>(vkGetInstanceProcAddr(vk_instance_a, name_a));
}

template<typename Function> Function load_device_level_function(VkDevice vk_device_a, const char* name_a)
{
    return reinterpret_cast<Function>(vkGetDeviceProcAddr(vk_device_a, name_a));
}

std::unordered_map<VkDevice, DeviceFunctions> device_functions;
std::unordered_map<VkCommandBuffer, VkDevice> command_buffers;
std::unordered_map<VkQueue, VkDevice> queues;
} // namespace

#define LOAD_INSTANCE_LEVEL_FUNCTION(function) function = load_instance_level_function<decltype(function)>(*pInstance, #function)
#define LOAD_DEVICE_LEVEL_FUNCTION(table, function) \
    table.function = load_device_level_function<decltype(table.function)>(*pDevice, #function)

#ifdef __cplusplus
extern "C" {
#endif

PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr = nullptr;
PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr = nullptr;

PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;

PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties = nullptr;
PFN_vkEnumerateDeviceLayerProperties vkEnumerateDeviceLayerProperties = nullptr;
PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices = nullptr;
PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures = nullptr;
PFN_vkGetPhysicalDeviceFormatProperties vkGetPhysicalDeviceFormatProperties = nullptr;
PFN_vkGetPhysicalDeviceImageFormatProperties vkGetPhysicalDeviceImageFormatProperties = nullptr;
PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties = nullptr;
PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties = nullptr;
PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties = nullptr;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties vkGetPhysicalDeviceSparseImageFormatProperties = nullptr;
#if defined(VK_KHR_surface)
PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR = nullptr;
PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vkGetPhysicalDeviceSurfaceFormatsKHR = nullptr;
PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vkGetPhysicalDeviceSurfacePresentModesKHR = nullptr;
PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR = nullptr;
PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR = nullptr;
#endif
#if defined(VK_KHR_win32_surface)
PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR = nullptr;
PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR vkGetPhysicalDeviceWin32PresentationSupportKHR = nullptr;
#endif
#if defined(VK_EXT_debug_utils)
PFN_vkCreateDebugUtilsMessengerEXT vkCreateDebugUtilsMessengerEXT = nullptr;
PFN_vkDestroyDebugUtilsMessengerEXT vkDestroyDebugUtilsMessengerEXT = nullptr;
#endif

uint32_t lxlCreate()
{
    assert(nullptr == vk_driver_handle);

    vk_driver_handle = LoadLibrary("vulkan-1.dll");
    if (nullptr != vk_driver_handle)
    {
        uint32_t version = VK_API_VERSION_1_0;

        vkGetInstanceProcAddr =
            reinterpret_cast<decltype(vkGetInstanceProcAddr)>(GetProcAddress(vk_driver_handle, "vkGetInstanceProcAddr"));
        vkGetDeviceProcAddr = reinterpret_cast<decltype(vkGetDeviceProcAddr)>(GetProcAddress(vk_driver_handle, "vkGetDeviceProcAddr"));

        vkEnumerateInstanceExtensionProperties = reinterpret_cast<decltype(vkEnumerateInstanceExtensionProperties)>(
            GetProcAddress(vk_driver_handle, "vkEnumerateInstanceExtensionProperties"));
        vkEnumerateInstanceLayerProperties = reinterpret_cast<decltype(vkEnumerateInstanceLayerProperties)>(
            GetProcAddress(vk_driver_handle, "vkEnumerateInstanceLayerProperties"));
        return version;
    }

    return 0u;
}
void lxlDestroy()
{
    FreeLibrary(vk_driver_handle);

    vk_driver_handle = nullptr;
}

#if defined(VK_VERSION_1_0)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateInstance(const VkInstanceCreateInfo* pCreateInfo,
                                                const VkAllocationCallbacks* pAllocator,
                                                VkInstance* pInstance)
{
    assert(nullptr != vk_driver_handle);

    PFN_vkCreateInstance vk_create_instance =
        reinterpret_cast<decltype(vk_create_instance)>(GetProcAddress(vk_driver_handle, "vkCreateInstance"));
    VkResult ret = vk_create_instance(pCreateInfo, pAllocator, pInstance);

    if (VK_SUCCESS == ret)
    {
        LOAD_INSTANCE_LEVEL_FUNCTION(vkEnumerateDeviceExtensionProperties);
        LOAD_INSTANCE_LEVEL_FUNCTION(vkEnumerateDeviceLayerProperties);
        LOAD_INSTANCE_LEVEL_FUNCTION(vkEnumeratePhysicalDevices);
        LOAD_INSTANCE_LEVEL_FUNCTION(vkGetPhysicalDeviceFeatures);
        LOAD_INSTANCE_LEVEL_FUNCTION(vkGetPhysicalDeviceFormatProperties);
        LOAD_INSTANCE_LEVEL_FUNCTION(vkGetPhysicalDeviceImageFormatProperties);
        LOAD_INSTANCE_LEVEL_FUNCTION(vkGetPhysicalDeviceMemoryProperties);
        LOAD_INSTANCE_LEVEL_FUNCTION(vkGetPhysicalDeviceProperties);
        LOAD_INSTANCE_LEVEL_FUNCTION(vkGetPhysicalDeviceQueueFamilyProperties);
        LOAD_INSTANCE_LEVEL_FUNCTION(vkGetPhysicalDeviceSparseImageFormatProperties);
#if defined(VK_KHR_surface)
        LOAD_INSTANCE_LEVEL_FUNCTION(vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
        LOAD_INSTANCE_LEVEL_FUNCTION(vkGetPhysicalDeviceSurfaceFormatsKHR);
        LOAD_INSTANCE_LEVEL_FUNCTION(vkGetPhysicalDeviceSurfacePresentModesKHR);
        LOAD_INSTANCE_LEVEL_FUNCTION(vkGetPhysicalDeviceSurfaceSupportKHR);
        LOAD_INSTANCE_LEVEL_FUNCTION(vkDestroySurfaceKHR);
#endif
#if defined(VK_KHR_win32_surface)
        LOAD_INSTANCE_LEVEL_FUNCTION(vkCreateWin32SurfaceKHR);
        LOAD_INSTANCE_LEVEL_FUNCTION(vkGetPhysicalDeviceWin32PresentationSupportKHR);
#endif
#if defined(VK_EXT_debug_utils)
        LOAD_INSTANCE_LEVEL_FUNCTION(vkCreateDebugUtilsMessengerEXT);
        LOAD_INSTANCE_LEVEL_FUNCTION(vkDestroyDebugUtilsMessengerEXT);
#endif
    }

    return ret;
}
void VKAPI_CALL vkDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator)
{
    PFN_vkDestroyInstance vk_destroy_instance =
        reinterpret_cast<decltype(vk_destroy_instance)>(GetProcAddress(vk_driver_handle, "vkDestroyInstance"));
    vk_destroy_instance(instance, pAllocator);
}

VkResult VKAPI_CALL vkCreateDevice(VkInstance instance,
                                   VkPhysicalDevice physicalDevice,
                                   const VkDeviceCreateInfo* pCreateInfo,
                                   const VkAllocationCallbacks* pAllocator,
                                   VkDevice* pDevice)
{
    PFN_vkCreateDevice vk_create_device = reinterpret_cast<decltype(vk_create_device)>(vkGetInstanceProcAddr(instance, "vkCreateDevice"));
    VkResult ret = vk_create_device(physicalDevice, pCreateInfo, pAllocator, pDevice);

    if (VK_SUCCESS == ret)
    {
        DeviceFunctions functions;
#if defined(VK_VERSION_1_0)
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkAllocateCommandBuffers);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkAllocateDescriptorSets);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkAllocateMemory);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkBeginCommandBuffer);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkBindBufferMemory);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkBindImageMemory);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdBeginQuery);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdBeginRenderPass);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdBindDescriptorSets);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdBindIndexBuffer);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdBindPipeline);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdBindVertexBuffers);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdBlitImage);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdClearAttachments);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdClearColorImage);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdClearDepthStencilImage);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdCopyBuffer);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdCopyBufferToImage);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdCopyImage);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdCopyImageToBuffer);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdCopyQueryPoolResults);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdDispatch);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdDispatchIndirect);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdDraw);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdDrawIndexed);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdDrawIndexedIndirect);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdDrawIndirect);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdEndQuery);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdEndRenderPass);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdExecuteCommands);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdFillBuffer);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdNextSubpass);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdPipelineBarrier);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdPushConstants);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdResetEvent);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdResetQueryPool);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdResolveImage);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdSetBlendConstants);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdSetDepthBias);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdSetDepthBounds);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdSetEvent);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdSetLineWidth);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdSetScissor);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdSetStencilCompareMask);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdSetStencilReference);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdSetStencilWriteMask);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdSetViewport);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdUpdateBuffer);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdWaitEvents);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCmdWriteTimestamp);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreateBuffer);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreateBufferView);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreateCommandPool);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreateComputePipelines);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreateDescriptorPool);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreateDescriptorSetLayout);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreateEvent);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreateFence);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreateFramebuffer);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreateGraphicsPipelines);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreateImage);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreateImageView);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreatePipelineCache);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreatePipelineLayout);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreateQueryPool);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreateRenderPass);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreateSampler);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreateSemaphore);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreateShaderModule);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroyBuffer);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroyBufferView);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroyCommandPool);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroyDescriptorPool);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroyDescriptorSetLayout);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroyEvent);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroyFence);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroyFramebuffer);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroyImage);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroyImageView);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroyPipeline);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroyPipelineCache);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroyPipelineLayout);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroyQueryPool);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroyRenderPass);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroySampler);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroySemaphore);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroyShaderModule);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDeviceWaitIdle);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkEndCommandBuffer);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkFlushMappedMemoryRanges);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkFreeCommandBuffers);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkFreeDescriptorSets);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkFreeMemory);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkGetBufferMemoryRequirements);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkGetDeviceMemoryCommitment);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkGetDeviceQueue);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkGetEventStatus);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkGetFenceStatus);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkGetImageMemoryRequirements);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkGetImageSparseMemoryRequirements);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkGetImageSubresourceLayout);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkGetPipelineCacheData);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkGetQueryPoolResults);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkGetRenderAreaGranularity);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkInvalidateMappedMemoryRanges);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkMapMemory);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkMergePipelineCaches);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkQueueBindSparse);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkQueueSubmit);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkQueueWaitIdle);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkResetCommandBuffer);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkResetCommandPool);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkResetDescriptorPool);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkResetEvent);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkResetFences);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkSetEvent);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkUnmapMemory);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkUpdateDescriptorSets);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkWaitForFences);
#endif
#if defined(VK_KHR_swapchain)
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkCreateSwapchainKHR);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkGetSwapchainImagesKHR);
        LOAD_DEVICE_LEVEL_FUNCTION(functions, vkDestroySwapchainKHR);
#endif
        device_functions[*pDevice] = functions;
    }
    return ret;
}
void VKAPI_CALL vkDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());

    PFN_vkDestroyDevice vk_destroy_device = reinterpret_cast<decltype(vk_destroy_device)>(vkGetDeviceProcAddr(device, "vkDestroyDevice"));

    if (nullptr != vk_destroy_device)
    {
        vk_destroy_device(device, pAllocator);
        device_functions.erase(device);
    }
}

VkResult VKAPI_CALL vkAllocateCommandBuffers(VkDevice device,
                                             const VkCommandBufferAllocateInfo* pAllocateInfo,
                                             VkCommandBuffer* pCommandBuffers)
{
    assert(device_functions.find(device) != device_functions.end());
    auto res = device_functions[device].vkAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);

    if (VK_SUCCESS == res)
    {
        for (uint32_t i = 0; i < pAllocateInfo->commandBufferCount; i++)
        {
            command_buffers[pCommandBuffers[i]] = device;
        }
    }

    return res;
}
VkResult VKAPI_CALL vkAllocateDescriptorSets(VkDevice device,
                                             const VkDescriptorSetAllocateInfo* pAllocateInfo,
                                             VkDescriptorSet* pDescriptorSets)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
}
VkResult VKAPI_CALL vkAllocateMemory(VkDevice device,
                                     const VkMemoryAllocateInfo* pAllocateInfo,
                                     const VkAllocationCallbacks* pAllocator,
                                     VkDeviceMemory* pMemory)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
}
VkResult VKAPI_CALL vkBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkBeginCommandBuffer(commandBuffer, pBeginInfo);
}
VkResult VKAPI_CALL vkBindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkBindBufferMemory(device, buffer, memory, memoryOffset);
}
VkResult VKAPI_CALL vkBindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkBindImageMemory(device, image, memory, memoryOffset);
}
void VKAPI_CALL vkCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdBeginQuery(commandBuffer, queryPool, query, flags);
}
void VKAPI_CALL vkCmdBeginRenderPass(VkCommandBuffer commandBuffer,
                                     const VkRenderPassBeginInfo* pRenderPassBegin,
                                     VkSubpassContents contents)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
}
void VKAPI_CALL vkCmdBindDescriptorSets(VkCommandBuffer commandBuffer,
                                        VkPipelineBindPoint pipelineBindPoint,
                                        VkPipelineLayout layout,
                                        uint32_t firstSet,
                                        uint32_t descriptorSetCount,
                                        const VkDescriptorSet* pDescriptorSets,
                                        uint32_t dynamicOffsetCount,
                                        const uint32_t* pDynamicOffsets)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdBindDescriptorSets(
        commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}
void VKAPI_CALL vkCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
}
void VKAPI_CALL vkCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
}
void VKAPI_CALL vkCmdBindVertexBuffers(VkCommandBuffer commandBuffer,
                                       uint32_t firstBinding,
                                       uint32_t bindingCount,
                                       const VkBuffer* pBuffers,
                                       const VkDeviceSize* pOffsets)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdBindVertexBuffers(
        commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}
void VKAPI_CALL vkCmdBlitImage(VkCommandBuffer commandBuffer,
                               VkImage srcImage,
                               VkImageLayout srcImageLayout,
                               VkImage dstImage,
                               VkImageLayout dstImageLayout,
                               uint32_t regionCount,
                               const VkImageBlit* pRegions,
                               VkFilter filter)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdBlitImage(
        commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
}
void VKAPI_CALL vkCmdClearAttachments(VkCommandBuffer commandBuffer,
                                      uint32_t attachmentCount,
                                      const VkClearAttachment* pAttachments,
                                      uint32_t rectCount,
                                      const VkClearRect* pRects)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdClearAttachments(
        commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}
void VKAPI_CALL vkCmdClearColorImage(VkCommandBuffer commandBuffer,
                                     VkImage image,
                                     VkImageLayout imageLayout,
                                     const VkClearColorValue* pColor,
                                     uint32_t rangeCount,
                                     const VkImageSubresourceRange* pRanges)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdClearColorImage(
        commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}
void VKAPI_CALL vkCmdClearDepthStencilImage(VkCommandBuffer commandBuffer,
                                            VkImage image,
                                            VkImageLayout imageLayout,
                                            const VkClearDepthStencilValue* pDepthStencil,
                                            uint32_t rangeCount,
                                            const VkImageSubresourceRange* pRanges)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdClearDepthStencilImage(
        commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}
void VKAPI_CALL
vkCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}
void VKAPI_CALL vkCmdCopyBufferToImage(VkCommandBuffer commandBuffer,
                                       VkBuffer srcBuffer,
                                       VkImage dstImage,
                                       VkImageLayout dstImageLayout,
                                       uint32_t regionCount,
                                       const VkBufferImageCopy* pRegions)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdCopyBufferToImage(
        commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}
void VKAPI_CALL vkCmdCopyImage(VkCommandBuffer commandBuffer,
                               VkImage srcImage,
                               VkImageLayout srcImageLayout,
                               VkImage dstImage,
                               VkImageLayout dstImageLayout,
                               uint32_t regionCount,
                               const VkImageCopy* pRegions)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdCopyImage(
        commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}
void VKAPI_CALL vkCmdCopyImageToBuffer(VkCommandBuffer commandBuffer,
                                       VkImage srcImage,
                                       VkImageLayout srcImageLayout,
                                       VkBuffer dstBuffer,
                                       uint32_t regionCount,
                                       const VkBufferImageCopy* pRegions)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdCopyImageToBuffer(
        commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}
void VKAPI_CALL vkCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer,
                                          VkQueryPool queryPool,
                                          uint32_t firstQuery,
                                          uint32_t queryCount,
                                          VkBuffer dstBuffer,
                                          VkDeviceSize dstOffset,
                                          VkDeviceSize stride,
                                          VkQueryResultFlags flags)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdCopyQueryPoolResults(
        commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}
void VKAPI_CALL vkCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
void VKAPI_CALL vkCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdDispatchIndirect(commandBuffer, buffer, offset);
}
void VKAPI_CALL
vkCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdDraw(
        commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}
void VKAPI_CALL vkCmdDrawIndexed(VkCommandBuffer commandBuffer,
                                 uint32_t indexCount,
                                 uint32_t instanceCount,
                                 uint32_t firstIndex,
                                 int32_t vertexOffset,
                                 uint32_t firstInstance)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdDrawIndexed(
        commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}
void VKAPI_CALL
vkCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
}
void VKAPI_CALL vkCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
}
void VKAPI_CALL vkCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdEndQuery(commandBuffer, queryPool, query);
}
void VKAPI_CALL vkCmdEndRenderPass(VkCommandBuffer commandBuffer)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdEndRenderPass(commandBuffer);
}
void VKAPI_CALL vkCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
}
void VKAPI_CALL vkCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
}
void VKAPI_CALL vkCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdNextSubpass(commandBuffer, contents);
}
void VKAPI_CALL vkCmdPipelineBarrier(VkCommandBuffer commandBuffer,
                                     VkPipelineStageFlags srcStageMask,
                                     VkPipelineStageFlags dstStageMask,
                                     VkDependencyFlags dependencyFlags,
                                     uint32_t memoryBarrierCount,
                                     const VkMemoryBarrier* pMemoryBarriers,
                                     uint32_t bufferMemoryBarrierCount,
                                     const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                     uint32_t imageMemoryBarrierCount,
                                     const VkImageMemoryBarrier* pImageMemoryBarriers)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdPipelineBarrier(commandBuffer,
                                                                                 srcStageMask,
                                                                                 dstStageMask,
                                                                                 dependencyFlags,
                                                                                 memoryBarrierCount,
                                                                                 pMemoryBarriers,
                                                                                 bufferMemoryBarrierCount,
                                                                                 pBufferMemoryBarriers,
                                                                                 imageMemoryBarrierCount,
                                                                                 pImageMemoryBarriers);
}
void VKAPI_CALL vkCmdPushConstants(VkCommandBuffer commandBuffer,
                                   VkPipelineLayout layout,
                                   VkShaderStageFlags stageFlags,
                                   uint32_t offset,
                                   uint32_t size,
                                   const void* pValues)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
}
void VKAPI_CALL vkCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdResetEvent(commandBuffer, event, stageMask);
}
void VKAPI_CALL vkCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
}
void VKAPI_CALL vkCmdResolveImage(VkCommandBuffer commandBuffer,
                                  VkImage srcImage,
                                  VkImageLayout srcImageLayout,
                                  VkImage dstImage,
                                  VkImageLayout dstImageLayout,
                                  uint32_t regionCount,
                                  const VkImageResolve* pRegions)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdResolveImage(
        commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}
void VKAPI_CALL vkCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4])
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdSetBlendConstants(commandBuffer, blendConstants);
}
void VKAPI_CALL vkCmdSetDepthBias(VkCommandBuffer commandBuffer,
                                  float depthBiasConstantFactor,
                                  float depthBiasClamp,
                                  float depthBiasSlopeFactor)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdSetDepthBias(
        commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}
void VKAPI_CALL vkCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
}
void VKAPI_CALL vkCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdSetEvent(commandBuffer, event, stageMask);
}
void VKAPI_CALL vkCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdSetLineWidth(commandBuffer, lineWidth);
}
void VKAPI_CALL vkCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
}
void VKAPI_CALL vkCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
}
void VKAPI_CALL vkCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdSetStencilReference(commandBuffer, faceMask, reference);
}
void VKAPI_CALL vkCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
}
void VKAPI_CALL vkCmdSetViewport(VkCommandBuffer commandBuffer,
                                 uint32_t firstViewport,
                                 uint32_t viewportCount,
                                 const VkViewport* pViewports)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
}
void VKAPI_CALL
vkCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}
void VKAPI_CALL vkCmdWaitEvents(VkCommandBuffer commandBuffer,
                                uint32_t eventCount,
                                const VkEvent* pEvents,
                                VkPipelineStageFlags srcStageMask,
                                VkPipelineStageFlags dstStageMask,
                                uint32_t memoryBarrierCount,
                                const VkMemoryBarrier* pMemoryBarriers,
                                uint32_t bufferMemoryBarrierCount,
                                const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                uint32_t imageMemoryBarrierCount,
                                const VkImageMemoryBarrier* pImageMemoryBarriers)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdWaitEvents(commandBuffer,
                                                                            eventCount,
                                                                            pEvents,
                                                                            srcStageMask,
                                                                            dstStageMask,
                                                                            memoryBarrierCount,
                                                                            pMemoryBarriers,
                                                                            bufferMemoryBarrierCount,
                                                                            pBufferMemoryBarriers,
                                                                            imageMemoryBarrierCount,
                                                                            pImageMemoryBarriers);
}
void VKAPI_CALL vkCmdWriteTimestamp(VkCommandBuffer commandBuffer,
                                    VkPipelineStageFlagBits pipelineStage,
                                    VkQueryPool queryPool,
                                    uint32_t query)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
}
VkResult VKAPI_CALL vkCreateBuffer(VkDevice device,
                                   const VkBufferCreateInfo* pCreateInfo,
                                   const VkAllocationCallbacks* pAllocator,
                                   VkBuffer* pBuffer)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
}
VkResult VKAPI_CALL vkCreateBufferView(VkDevice device,
                                       const VkBufferViewCreateInfo* pCreateInfo,
                                       const VkAllocationCallbacks* pAllocator,
                                       VkBufferView* pView)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreateBufferView(device, pCreateInfo, pAllocator, pView);
}
VkResult VKAPI_CALL vkCreateCommandPool(VkDevice device,
                                        const VkCommandPoolCreateInfo* pCreateInfo,
                                        const VkAllocationCallbacks* pAllocator,
                                        VkCommandPool* pCommandPool)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
}
VkResult VKAPI_CALL vkCreateComputePipelines(VkDevice device,
                                             VkPipelineCache pipelineCache,
                                             uint32_t createInfoCount,
                                             const VkComputePipelineCreateInfo* pCreateInfos,
                                             const VkAllocationCallbacks* pAllocator,
                                             VkPipeline* pPipelines)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}
VkResult VKAPI_CALL vkCreateDescriptorPool(VkDevice device,
                                           const VkDescriptorPoolCreateInfo* pCreateInfo,
                                           const VkAllocationCallbacks* pAllocator,
                                           VkDescriptorPool* pDescriptorPool)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
}
VkResult VKAPI_CALL vkCreateDescriptorSetLayout(VkDevice device,
                                                const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                const VkAllocationCallbacks* pAllocator,
                                                VkDescriptorSetLayout* pSetLayout)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
}
VkResult VKAPI_CALL vkCreateEvent(VkDevice device,
                                  const VkEventCreateInfo* pCreateInfo,
                                  const VkAllocationCallbacks* pAllocator,
                                  VkEvent* pEvent)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreateEvent(device, pCreateInfo, pAllocator, pEvent);
}
VkResult VKAPI_CALL vkCreateFence(VkDevice device,
                                  const VkFenceCreateInfo* pCreateInfo,
                                  const VkAllocationCallbacks* pAllocator,
                                  VkFence* pFence)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreateFence(device, pCreateInfo, pAllocator, pFence);
}
VkResult VKAPI_CALL vkCreateFramebuffer(VkDevice device,
                                        const VkFramebufferCreateInfo* pCreateInfo,
                                        const VkAllocationCallbacks* pAllocator,
                                        VkFramebuffer* pFramebuffer)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
}
VkResult VKAPI_CALL vkCreateGraphicsPipelines(VkDevice device,
                                              VkPipelineCache pipelineCache,
                                              uint32_t createInfoCount,
                                              const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                              const VkAllocationCallbacks* pAllocator,
                                              VkPipeline* pPipelines)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}
VkResult VKAPI_CALL vkCreateImage(VkDevice device,
                                  const VkImageCreateInfo* pCreateInfo,
                                  const VkAllocationCallbacks* pAllocator,
                                  VkImage* pImage)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreateImage(device, pCreateInfo, pAllocator, pImage);
}
VkResult VKAPI_CALL vkCreateImageView(VkDevice device,
                                      const VkImageViewCreateInfo* pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator,
                                      VkImageView* pView)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreateImageView(device, pCreateInfo, pAllocator, pView);
}
VkResult VKAPI_CALL vkCreatePipelineCache(VkDevice device,
                                          const VkPipelineCacheCreateInfo* pCreateInfo,
                                          const VkAllocationCallbacks* pAllocator,
                                          VkPipelineCache* pPipelineCache)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
}
VkResult VKAPI_CALL vkCreatePipelineLayout(VkDevice device,
                                           const VkPipelineLayoutCreateInfo* pCreateInfo,
                                           const VkAllocationCallbacks* pAllocator,
                                           VkPipelineLayout* pPipelineLayout)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
}
VkResult VKAPI_CALL vkCreateQueryPool(VkDevice device,
                                      const VkQueryPoolCreateInfo* pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator,
                                      VkQueryPool* pQueryPool)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
}
VkResult VKAPI_CALL vkCreateRenderPass(VkDevice device,
                                       const VkRenderPassCreateInfo* pCreateInfo,
                                       const VkAllocationCallbacks* pAllocator,
                                       VkRenderPass* pRenderPass)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
}
VkResult VKAPI_CALL vkCreateSampler(VkDevice device,
                                    const VkSamplerCreateInfo* pCreateInfo,
                                    const VkAllocationCallbacks* pAllocator,
                                    VkSampler* pSampler)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreateSampler(device, pCreateInfo, pAllocator, pSampler);
}
VkResult VKAPI_CALL vkCreateSemaphore(VkDevice device,
                                      const VkSemaphoreCreateInfo* pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator,
                                      VkSemaphore* pSemaphore)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
}
VkResult VKAPI_CALL vkCreateShaderModule(VkDevice device,
                                         const VkShaderModuleCreateInfo* pCreateInfo,
                                         const VkAllocationCallbacks* pAllocator,
                                         VkShaderModule* pShaderModule)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
}
void VKAPI_CALL vkDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroyBuffer(device, buffer, pAllocator);
}
void VKAPI_CALL vkDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroyBufferView(device, bufferView, pAllocator);
}
void VKAPI_CALL vkDestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroyCommandPool(device, commandPool, pAllocator);
}
void VKAPI_CALL vkDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroyDescriptorPool(device, descriptorPool, pAllocator);
}
void VKAPI_CALL vkDestroyDescriptorSetLayout(VkDevice device,
                                             VkDescriptorSetLayout descriptorSetLayout,
                                             const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
}
void VKAPI_CALL vkDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroyEvent(device, event, pAllocator);
}
void VKAPI_CALL vkDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroyFence(device, fence, pAllocator);
}
void VKAPI_CALL vkDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroyFramebuffer(device, framebuffer, pAllocator);
}
void VKAPI_CALL vkDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroyImage(device, image, pAllocator);
}
void VKAPI_CALL vkDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroyImageView(device, imageView, pAllocator);
}
void VKAPI_CALL vkDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroyPipeline(device, pipeline, pAllocator);
}
void VKAPI_CALL vkDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroyPipelineCache(device, pipelineCache, pAllocator);
}
void VKAPI_CALL vkDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroyPipelineLayout(device, pipelineLayout, pAllocator);
}
void VKAPI_CALL vkDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroyQueryPool(device, queryPool, pAllocator);
}
void VKAPI_CALL vkDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroyRenderPass(device, renderPass, pAllocator);
}
void VKAPI_CALL vkDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroySampler(device, sampler, pAllocator);
}
void VKAPI_CALL vkDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroySemaphore(device, semaphore, pAllocator);
}
void VKAPI_CALL vkDestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroyShaderModule(device, shaderModule, pAllocator);
}
VkResult VKAPI_CALL vkDeviceWaitIdle(VkDevice device)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDeviceWaitIdle(device);
}
VkResult VKAPI_CALL vkEndCommandBuffer(VkCommandBuffer commandBuffer)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkEndCommandBuffer(commandBuffer);
}
VkResult VKAPI_CALL vkFlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
}
void VKAPI_CALL vkFreeCommandBuffers(VkDevice device,
                                     VkCommandPool commandPool,
                                     uint32_t commandBufferCount,
                                     const VkCommandBuffer* pCommandBuffers)
{
    assert(device_functions.find(device) != device_functions.end());
    device_functions[device].vkFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);

    for (uint32_t i = 0; i < commandBufferCount; i++)
    {
        command_buffers.erase(pCommandBuffers[i]);
    }
}
VkResult VKAPI_CALL vkFreeDescriptorSets(VkDevice device,
                                         VkDescriptorPool descriptorPool,
                                         uint32_t descriptorSetCount,
                                         const VkDescriptorSet* pDescriptorSets)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
}
void VKAPI_CALL vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkFreeMemory(device, memory, pAllocator);
}
void VKAPI_CALL vkGetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
}
void VKAPI_CALL vkGetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
}
void VKAPI_CALL vkGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue)
{
    assert(device_functions.find(device) != device_functions.end());
    device_functions[device].vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);

    queues[*pQueue] = device;
}
VkResult VKAPI_CALL vkGetEventStatus(VkDevice device, VkEvent event)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkGetEventStatus(device, event);
}
VkResult VKAPI_CALL vkGetFenceStatus(VkDevice device, VkFence fence)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkGetFenceStatus(device, fence);
}
void VKAPI_CALL vkGetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkGetImageMemoryRequirements(device, image, pMemoryRequirements);
}
void VKAPI_CALL vkGetImageSparseMemoryRequirements(VkDevice device,
                                                   VkImage image,
                                                   uint32_t* pSparseMemoryRequirementCount,
                                                   VkSparseImageMemoryRequirements* pSparseMemoryRequirements)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkGetImageSparseMemoryRequirements(
        device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}
void VKAPI_CALL vkGetImageSubresourceLayout(VkDevice device,
                                            VkImage image,
                                            const VkImageSubresource* pSubresource,
                                            VkSubresourceLayout* pLayout)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkGetImageSubresourceLayout(device, image, pSubresource, pLayout);
}
VkResult VKAPI_CALL vkGetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkGetPipelineCacheData(device, pipelineCache, pDataSize, pData);
}
VkResult VKAPI_CALL vkGetQueryPoolResults(VkDevice device,
                                          VkQueryPool queryPool,
                                          uint32_t firstQuery,
                                          uint32_t queryCount,
                                          size_t dataSize,
                                          void* pData,
                                          VkDeviceSize stride,
                                          VkQueryResultFlags flags)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
}
void VKAPI_CALL vkGetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkGetRenderAreaGranularity(device, renderPass, pGranularity);
}
VkResult VKAPI_CALL vkInvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
}
VkResult VKAPI_CALL
vkMapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkMapMemory(device, memory, offset, size, flags, ppData);
}
VkResult VKAPI_CALL vkMergePipelineCaches(VkDevice device,
                                          VkPipelineCache dstCache,
                                          uint32_t srcCacheCount,
                                          const VkPipelineCache* pSrcCaches)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkMergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);
}
VkResult VKAPI_CALL vkQueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence)
{
    assert(queues.find(queue) != queues.end());
    assert(device_functions.find(queues[queue]) != device_functions.end());

    return device_functions[queues[queue]].vkQueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
}
VkResult VKAPI_CALL vkQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence)
{
    assert(queues.find(queue) != queues.end());
    assert(device_functions.find(queues[queue]) != device_functions.end());

    return device_functions[queues[queue]].vkQueueSubmit(queue, submitCount, pSubmits, fence);
}
VkResult VKAPI_CALL vkQueueWaitIdle(VkQueue queue)
{
    assert(queues.find(queue) != queues.end());
    assert(device_functions.find(queues[queue]) != device_functions.end());

    return device_functions[queues[queue]].vkQueueWaitIdle(queue);
}
VkResult VKAPI_CALL vkResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags)
{
    assert(command_buffers.find(commandBuffer) != command_buffers.end());
    assert(device_functions.find(command_buffers[commandBuffer]) != device_functions.end());

    return device_functions[command_buffers[commandBuffer]].vkResetCommandBuffer(commandBuffer, flags);
}
VkResult VKAPI_CALL vkResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkResetCommandPool(device, commandPool, flags);
}
VkResult VKAPI_CALL vkResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkResetDescriptorPool(device, descriptorPool, flags);
}
VkResult VKAPI_CALL vkResetEvent(VkDevice device, VkEvent event)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkResetEvent(device, event);
}
VkResult VKAPI_CALL vkResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkResetFences(device, fenceCount, pFences);
}
VkResult VKAPI_CALL vkSetEvent(VkDevice device, VkEvent event)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkSetEvent(device, event);
}
void VKAPI_CALL vkUnmapMemory(VkDevice device, VkDeviceMemory memory)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkUnmapMemory(device, memory);
}
void VKAPI_CALL vkUpdateDescriptorSets(VkDevice device,
                                       uint32_t descriptorWriteCount,
                                       const VkWriteDescriptorSet* pDescriptorWrites,
                                       uint32_t descriptorCopyCount,
                                       const VkCopyDescriptorSet* pDescriptorCopies)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkUpdateDescriptorSets(
        device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}
VkResult VKAPI_CALL vkWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkWaitForFences(device, fenceCount, pFences, waitAll, timeout);
}
#if defined(VK_KHR_swapchain)
VkResult VKAPI_CALL vkCreateSwapchainKHR(VkDevice device,
                                         const VkSwapchainCreateInfoKHR* pCreateInfo,
                                         const VkAllocationCallbacks* pAllocator,
                                         VkSwapchainKHR* pSwapchain)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
}
VkResult VKAPI_CALL vkGetSwapchainImagesKHR(VkDevice device,
                                            VkSwapchainKHR swapchain,
                                            uint32_t* pSwapchainImageCount,
                                            VkImage* pSwapchainImages)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
}
void VKAPI_CALL vkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator)
{
    assert(device_functions.find(device) != device_functions.end());
    return device_functions[device].vkDestroySwapchainKHR(device, swapchain, pAllocator);
}
#endif
#endif

#ifdef __cplusplus
}
#endif
