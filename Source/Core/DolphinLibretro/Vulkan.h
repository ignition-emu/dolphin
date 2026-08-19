#pragma once

class AbstractTexture;

namespace Libretro
{
namespace Video
{
namespace Vk
{
void Init(VkInstance instance, VkPhysicalDevice gpu, VkSurfaceKHR surface,
          PFN_vkGetInstanceProcAddr get_instance_proc_addr, const char** required_device_extensions,
          unsigned num_required_device_extensions, const char** required_device_layers,
          unsigned num_required_device_layers, const VkPhysicalDeviceFeatures* required_features);
void SetSurfaceSize(uint32_t width, uint32_t height);
void SetHWRenderInterface(retro_hw_render_interface* hw_render_interface);
void Shutdown();
void WaitForPresentation();
VkSurfaceKHR GetSurface();
// Hands a finished XFB straight to the frontend. Used when there is no swap
// chain to present through -- see HandOffFrame in Video.cpp.
bool HandOffXFB(const AbstractTexture* texture);
}  // namespace Vk
}  // namespace Video
}  // namespace Libretro
