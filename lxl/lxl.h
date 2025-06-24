#pragma once

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

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4820)
#endif
#define VK_NO_PROTOTYPES
#include <vulkan/vulkan.h>
#ifdef _MSC_VER
#pragma warning(pop)
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
extern PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;

extern PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
extern PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;

// instance level functions
VkResult VKAPI_CALL vkCreateInstance(const VkInstanceCreateInfo* pCreateInfo,
                                     const VkAllocationCallbacks* pAllocator,
                                     VkInstance* pInstance);
void VKAPI_CALL vkDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator);
extern PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties;
extern PFN_vkEnumerateDeviceLayerProperties vkEnumerateDeviceLayerProperties;
extern PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices;
extern PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures;
extern PFN_vkGetPhysicalDeviceFormatProperties vkGetPhysicalDeviceFormatProperties;
extern PFN_vkGetPhysicalDeviceImageFormatProperties vkGetPhysicalDeviceImageFormatProperties;
extern PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties;
extern PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties;
extern PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties;
extern PFN_vkGetPhysicalDeviceSparseImageFormatProperties vkGetPhysicalDeviceSparseImageFormatProperties;
#if defined(VK_KHR_surface)
extern PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
extern PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vkGetPhysicalDeviceSurfaceFormatsKHR;
extern PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vkGetPhysicalDeviceSurfacePresentModesKHR;
extern PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR;
extern PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR;
#endif
#if defined(VK_KHR_win32_surface)
extern PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR;
extern PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR vkGetPhysicalDeviceWin32PresentationSupportKHR;
#endif
#if defined(VK_EXT_debug_utils)
extern PFN_vkCreateDebugUtilsMessengerEXT vkCreateDebugUtilsMessengerEXT;
extern PFN_vkDestroyDebugUtilsMessengerEXT vkDestroyDebugUtilsMessengerEXT;
#endif

// device level functions begin
#if defined(VK_VERSION_1_0)
VkResult VKAPI_CALL vkCreateDevice(VkInstance instance,
                                   VkPhysicalDevice physicalDevice,
                                   const VkDeviceCreateInfo* pCreateInfo,
                                   const VkAllocationCallbacks* pAllocator,
                                   VkDevice* pDevice);
void VKAPI_CALL vkDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator);
VkResult VKAPI_CALL vkAllocateCommandBuffers(VkDevice device,
                                             const VkCommandBufferAllocateInfo* pAllocateInfo,
                                             VkCommandBuffer* pCommandBuffers);
VkResult VKAPI_CALL vkAllocateDescriptorSets(VkDevice device,
                                             const VkDescriptorSetAllocateInfo* pAllocateInfo,
                                             VkDescriptorSet* pDescriptorSets);
VkResult VKAPI_CALL vkAllocateMemory(VkDevice device,
                                     const VkMemoryAllocateInfo* pAllocateInfo,
                                     const VkAllocationCallbacks* pAllocator,
                                     VkDeviceMemory* pMemory);
VkResult VKAPI_CALL vkBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);
VkResult VKAPI_CALL vkBindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);
VkResult VKAPI_CALL vkBindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);
void VKAPI_CALL vkCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags);
void VKAPI_CALL vkCmdBeginRenderPass(VkCommandBuffer commandBuffer,
                                     const VkRenderPassBeginInfo* pRenderPassBegin,
                                     VkSubpassContents contents);
void VKAPI_CALL vkCmdBindDescriptorSets(VkCommandBuffer commandBuffer,
                                        VkPipelineBindPoint pipelineBindPoint,
                                        VkPipelineLayout layout,
                                        uint32_t firstSet,
                                        uint32_t descriptorSetCount,
                                        const VkDescriptorSet* pDescriptorSets,
                                        uint32_t dynamicOffsetCount,
                                        const uint32_t* pDynamicOffsets);
void VKAPI_CALL vkCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType);
void VKAPI_CALL vkCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);
void VKAPI_CALL vkCmdBindVertexBuffers(VkCommandBuffer commandBuffer,
                                       uint32_t firstBinding,
                                       uint32_t bindingCount,
                                       const VkBuffer* pBuffers,
                                       const VkDeviceSize* pOffsets);
void VKAPI_CALL vkCmdBlitImage(VkCommandBuffer commandBuffer,
                               VkImage srcImage,
                               VkImageLayout srcImageLayout,
                               VkImage dstImage,
                               VkImageLayout dstImageLayout,
                               uint32_t regionCount,
                               const VkImageBlit* pRegions,
                               VkFilter filter);
void VKAPI_CALL vkCmdClearAttachments(VkCommandBuffer commandBuffer,
                                      uint32_t attachmentCount,
                                      const VkClearAttachment* pAttachments,
                                      uint32_t rectCount,
                                      const VkClearRect* pRects);
void VKAPI_CALL vkCmdClearColorImage(VkCommandBuffer commandBuffer,
                                     VkImage image,
                                     VkImageLayout imageLayout,
                                     const VkClearColorValue* pColor,
                                     uint32_t rangeCount,
                                     const VkImageSubresourceRange* pRanges);
void VKAPI_CALL vkCmdClearDepthStencilImage(VkCommandBuffer commandBuffer,
                                            VkImage image,
                                            VkImageLayout imageLayout,
                                            const VkClearDepthStencilValue* pDepthStencil,
                                            uint32_t rangeCount,
                                            const VkImageSubresourceRange* pRanges);
void VKAPI_CALL
vkCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions);
void VKAPI_CALL vkCmdCopyBufferToImage(VkCommandBuffer commandBuffer,
                                       VkBuffer srcBuffer,
                                       VkImage dstImage,
                                       VkImageLayout dstImageLayout,
                                       uint32_t regionCount,
                                       const VkBufferImageCopy* pRegions);
void VKAPI_CALL vkCmdCopyImage(VkCommandBuffer commandBuffer,
                               VkImage srcImage,
                               VkImageLayout srcImageLayout,
                               VkImage dstImage,
                               VkImageLayout dstImageLayout,
                               uint32_t regionCount,
                               const VkImageCopy* pRegions);
void VKAPI_CALL vkCmdCopyImageToBuffer(VkCommandBuffer commandBuffer,
                                       VkImage srcImage,
                                       VkImageLayout srcImageLayout,
                                       VkBuffer dstBuffer,
                                       uint32_t regionCount,
                                       const VkBufferImageCopy* pRegions);
void VKAPI_CALL vkCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer,
                                          VkQueryPool queryPool,
                                          uint32_t firstQuery,
                                          uint32_t queryCount,
                                          VkBuffer dstBuffer,
                                          VkDeviceSize dstOffset,
                                          VkDeviceSize stride,
                                          VkQueryResultFlags flags);
void VKAPI_CALL vkCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
void VKAPI_CALL vkCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);
void VKAPI_CALL
vkCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
void VKAPI_CALL vkCmdDrawIndexed(VkCommandBuffer commandBuffer,
                                 uint32_t indexCount,
                                 uint32_t instanceCount,
                                 uint32_t firstIndex,
                                 int32_t vertexOffset,
                                 uint32_t firstInstance);
void VKAPI_CALL
vkCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
void VKAPI_CALL vkCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
void VKAPI_CALL vkCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query);
void VKAPI_CALL vkCmdEndRenderPass(VkCommandBuffer commandBuffer);
void VKAPI_CALL vkCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
void VKAPI_CALL
vkCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data);
void VKAPI_CALL vkCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents);
void VKAPI_CALL vkCmdPipelineBarrier(VkCommandBuffer commandBuffer,
                                     VkPipelineStageFlags srcStageMask,
                                     VkPipelineStageFlags dstStageMask,
                                     VkDependencyFlags dependencyFlags,
                                     uint32_t memoryBarrierCount,
                                     const VkMemoryBarrier* pMemoryBarriers,
                                     uint32_t bufferMemoryBarrierCount,
                                     const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                     uint32_t imageMemoryBarrierCount,
                                     const VkImageMemoryBarrier* pImageMemoryBarriers);
void VKAPI_CALL vkCmdPushConstants(VkCommandBuffer commandBuffer,
                                   VkPipelineLayout layout,
                                   VkShaderStageFlags stageFlags,
                                   uint32_t offset,
                                   uint32_t size,
                                   const void* pValues);
void VKAPI_CALL vkCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
void VKAPI_CALL vkCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
void VKAPI_CALL vkCmdResolveImage(VkCommandBuffer commandBuffer,
                                  VkImage srcImage,
                                  VkImageLayout srcImageLayout,
                                  VkImage dstImage,
                                  VkImageLayout dstImageLayout,
                                  uint32_t regionCount,
                                  const VkImageResolve* pRegions);
void VKAPI_CALL vkCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]);
void VKAPI_CALL vkCmdSetDepthBias(VkCommandBuffer commandBuffer,
                                  float depthBiasConstantFactor,
                                  float depthBiasClamp,
                                  float depthBiasSlopeFactor);
void VKAPI_CALL vkCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds);
void VKAPI_CALL vkCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
void VKAPI_CALL vkCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth);
void VKAPI_CALL vkCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors);
void VKAPI_CALL vkCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask);
void VKAPI_CALL vkCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference);
void VKAPI_CALL vkCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask);
void VKAPI_CALL vkCmdSetViewport(VkCommandBuffer commandBuffer,
                                 uint32_t firstViewport,
                                 uint32_t viewportCount,
                                 const VkViewport* pViewports);
void VKAPI_CALL
vkCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData);
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
                                const VkImageMemoryBarrier* pImageMemoryBarriers);
void VKAPI_CALL vkCmdWriteTimestamp(VkCommandBuffer commandBuffer,
                                    VkPipelineStageFlagBits pipelineStage,
                                    VkQueryPool queryPool,
                                    uint32_t query);
VkResult VKAPI_CALL vkCreateBuffer(VkDevice device,
                                   const VkBufferCreateInfo* pCreateInfo,
                                   const VkAllocationCallbacks* pAllocator,
                                   VkBuffer* pBuffer);
VkResult VKAPI_CALL vkCreateBufferView(VkDevice device,
                                       const VkBufferViewCreateInfo* pCreateInfo,
                                       const VkAllocationCallbacks* pAllocator,
                                       VkBufferView* pView);
VkResult VKAPI_CALL vkCreateCommandPool(VkDevice device,
                                        const VkCommandPoolCreateInfo* pCreateInfo,
                                        const VkAllocationCallbacks* pAllocator,
                                        VkCommandPool* pCommandPool);
VkResult VKAPI_CALL vkCreateComputePipelines(VkDevice device,
                                             VkPipelineCache pipelineCache,
                                             uint32_t createInfoCount,
                                             const VkComputePipelineCreateInfo* pCreateInfos,
                                             const VkAllocationCallbacks* pAllocator,
                                             VkPipeline* pPipelines);
VkResult VKAPI_CALL vkCreateDescriptorPool(VkDevice device,
                                           const VkDescriptorPoolCreateInfo* pCreateInfo,
                                           const VkAllocationCallbacks* pAllocator,
                                           VkDescriptorPool* pDescriptorPool);
VkResult VKAPI_CALL vkCreateDescriptorSetLayout(VkDevice device,
                                                const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                const VkAllocationCallbacks* pAllocator,
                                                VkDescriptorSetLayout* pSetLayout);
VkResult VKAPI_CALL vkCreateEvent(VkDevice device,
                                  const VkEventCreateInfo* pCreateInfo,
                                  const VkAllocationCallbacks* pAllocator,
                                  VkEvent* pEvent);
VkResult VKAPI_CALL vkCreateFence(VkDevice device,
                                  const VkFenceCreateInfo* pCreateInfo,
                                  const VkAllocationCallbacks* pAllocator,
                                  VkFence* pFence);
VkResult VKAPI_CALL vkCreateFramebuffer(VkDevice device,
                                        const VkFramebufferCreateInfo* pCreateInfo,
                                        const VkAllocationCallbacks* pAllocator,
                                        VkFramebuffer* pFramebuffer);
VkResult VKAPI_CALL vkCreateGraphicsPipelines(VkDevice device,
                                              VkPipelineCache pipelineCache,
                                              uint32_t createInfoCount,
                                              const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                              const VkAllocationCallbacks* pAllocator,
                                              VkPipeline* pPipelines);
VkResult VKAPI_CALL vkCreateImage(VkDevice device,
                                  const VkImageCreateInfo* pCreateInfo,
                                  const VkAllocationCallbacks* pAllocator,
                                  VkImage* pImage);
VkResult VKAPI_CALL vkCreateImageView(VkDevice device,
                                      const VkImageViewCreateInfo* pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator,
                                      VkImageView* pView);
VkResult VKAPI_CALL vkCreatePipelineCache(VkDevice device,
                                          const VkPipelineCacheCreateInfo* pCreateInfo,
                                          const VkAllocationCallbacks* pAllocator,
                                          VkPipelineCache* pPipelineCache);
VkResult VKAPI_CALL vkCreatePipelineLayout(VkDevice device,
                                           const VkPipelineLayoutCreateInfo* pCreateInfo,
                                           const VkAllocationCallbacks* pAllocator,
                                           VkPipelineLayout* pPipelineLayout);
VkResult VKAPI_CALL vkCreateQueryPool(VkDevice device,
                                      const VkQueryPoolCreateInfo* pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator,
                                      VkQueryPool* pQueryPool);
VkResult VKAPI_CALL vkCreateRenderPass(VkDevice device,
                                       const VkRenderPassCreateInfo* pCreateInfo,
                                       const VkAllocationCallbacks* pAllocator,
                                       VkRenderPass* pRenderPass);
VkResult VKAPI_CALL vkCreateSampler(VkDevice device,
                                    const VkSamplerCreateInfo* pCreateInfo,
                                    const VkAllocationCallbacks* pAllocator,
                                    VkSampler* pSampler);
VkResult VKAPI_CALL vkCreateSemaphore(VkDevice device,
                                      const VkSemaphoreCreateInfo* pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator,
                                      VkSemaphore* pSemaphore);
VkResult VKAPI_CALL vkCreateShaderModule(VkDevice device,
                                         const VkShaderModuleCreateInfo* pCreateInfo,
                                         const VkAllocationCallbacks* pAllocator,
                                         VkShaderModule* pShaderModule);
void VKAPI_CALL vkDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator);
void VKAPI_CALL vkDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator);
void VKAPI_CALL vkDestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator);
void VKAPI_CALL vkDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator);
void VKAPI_CALL vkDestroyDescriptorSetLayout(VkDevice device,
                                             VkDescriptorSetLayout descriptorSetLayout,
                                             const VkAllocationCallbacks* pAllocator);
void VKAPI_CALL vkDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator);
void VKAPI_CALL vkDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator);
void VKAPI_CALL vkDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator);
void VKAPI_CALL vkDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator);
void VKAPI_CALL vkDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator);
void VKAPI_CALL vkDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator);
void VKAPI_CALL vkDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator);
void VKAPI_CALL vkDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator);
void VKAPI_CALL vkDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator);
void VKAPI_CALL vkDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator);
void VKAPI_CALL vkDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator);
void VKAPI_CALL vkDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator);
void VKAPI_CALL vkDestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator);
VkResult VKAPI_CALL vkDeviceWaitIdle(VkDevice device);
VkResult VKAPI_CALL vkEndCommandBuffer(VkCommandBuffer commandBuffer);
VkResult VKAPI_CALL vkFlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
void VKAPI_CALL vkFreeCommandBuffers(VkDevice device,
                                     VkCommandPool commandPool,
                                     uint32_t commandBufferCount,
                                     const VkCommandBuffer* pCommandBuffers);
VkResult VKAPI_CALL vkFreeDescriptorSets(VkDevice device,
                                         VkDescriptorPool descriptorPool,
                                         uint32_t descriptorSetCount,
                                         const VkDescriptorSet* pDescriptorSets);
void VKAPI_CALL vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);
void VKAPI_CALL vkGetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements);
void VKAPI_CALL vkGetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes);
void VKAPI_CALL vkGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue);
VkResult VKAPI_CALL vkGetEventStatus(VkDevice device, VkEvent event);
VkResult VKAPI_CALL vkGetFenceStatus(VkDevice device, VkFence fence);
void VKAPI_CALL vkGetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements);
void VKAPI_CALL vkGetImageSparseMemoryRequirements(VkDevice device,
                                                   VkImage image,
                                                   uint32_t* pSparseMemoryRequirementCount,
                                                   VkSparseImageMemoryRequirements* pSparseMemoryRequirements);
void VKAPI_CALL vkGetImageSubresourceLayout(VkDevice device,
                                            VkImage image,
                                            const VkImageSubresource* pSubresource,
                                            VkSubresourceLayout* pLayout);
VkResult VKAPI_CALL vkGetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData);
VkResult VKAPI_CALL vkGetQueryPoolResults(VkDevice device,
                                          VkQueryPool queryPool,
                                          uint32_t firstQuery,
                                          uint32_t queryCount,
                                          size_t dataSize,
                                          void* pData,
                                          VkDeviceSize stride,
                                          VkQueryResultFlags flags);
void VKAPI_CALL vkGetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity);
VkResult VKAPI_CALL vkInvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
VkResult VKAPI_CALL
vkMapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData);
VkResult VKAPI_CALL vkMergePipelineCaches(VkDevice device,
                                          VkPipelineCache dstCache,
                                          uint32_t srcCacheCount,
                                          const VkPipelineCache* pSrcCaches);
VkResult VKAPI_CALL vkQueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence);
VkResult VKAPI_CALL vkQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);
VkResult VKAPI_CALL vkQueueWaitIdle(VkQueue queue);
VkResult VKAPI_CALL vkResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags);
VkResult VKAPI_CALL vkResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags);
VkResult VKAPI_CALL vkResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags);
VkResult VKAPI_CALL vkResetEvent(VkDevice device, VkEvent event);
VkResult VKAPI_CALL vkResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences);
VkResult VKAPI_CALL vkSetEvent(VkDevice device, VkEvent event);
void VKAPI_CALL vkUnmapMemory(VkDevice device, VkDeviceMemory memory);
void VKAPI_CALL vkUpdateDescriptorSets(VkDevice device,
                                       uint32_t descriptorWriteCount,
                                       const VkWriteDescriptorSet* pDescriptorWrites,
                                       uint32_t descriptorCopyCount,
                                       const VkCopyDescriptorSet* pDescriptorCopies);
VkResult VKAPI_CALL vkWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout);
#if defined(VK_KHR_swapchain)
VkResult VKAPI_CALL vkCreateSwapchainKHR(VkDevice device,
                                         const VkSwapchainCreateInfoKHR* pCreateInfo,
                                         const VkAllocationCallbacks* pAllocator,
                                         VkSwapchainKHR* pSwapchain);
VkResult VKAPI_CALL vkGetSwapchainImagesKHR(VkDevice device,
                                            VkSwapchainKHR swapchain,
                                            uint32_t* pSwapchainImageCount,
                                            VkImage* pSwapchainImages);
void VKAPI_CALL vkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator);
#endif
#endif
// device level functions end

uint32_t lxlCreate();
void lxlDestroy();

#ifdef __cplusplus
}
#endif

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4127)
#pragma warning(disable : 4100)
#pragma warning(disable : 4189)
#pragma warning(disable : 4324)
#pragma warning(disable : 4820)
#pragma warning(disable : 4505)
#endif
#define VMA_STATIC_VULKAN_FUNCTIONS 0
#define VMA_DYNAMIC_VULKAN_FUNCTIONS 1
#include <vma/vk_mem_alloc.h>
#ifdef _MSC_VER
#pragma warning(pop)
#endif