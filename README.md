# api-intro-vulkan

![](Asset/vulkan-logo.png)

* An sandbox of [Vulkan API][1]


## Build

* open Code/Solutions/VS2017/ApiIntroVulkan.sln
* build & play~


## Platforms

* Win7, Win10
* Linux
* Android


## Solution Layout

```
[Bin32]           x86 build
[Bin64]           x64 build
[BinTemp]         intermediate build files
[Asset]           asset data
[Code]
  [External]      3rdparty libraries
  [Framework]     mini framework makes vulkan runs~
  [Samples]       a lot of samples
  [Solutions]
    [Android]     gradle files
    [VS2017]      vs2017 solution files
```


## Tutorial

* [RenderDoc - Vulkan in 30 Minutes][10]
* [RenderDoc - Brief Guide to Vulkan Layers][11]
* [Intel - API without Secrets: Introduction to Vulkan][12]
* [Vulkan Tutorial][7]
* [Vulkan Guide][30]
  * [GPU Driven Rendering][31]


## Hardware Supports

* https://vulkan.gpuinfo.org/


## Resources

* [KHRONOS - Vulkan Homepage][8]
* [KHRONOS - Vulkan 1.0 Spec][9]
* [LunarG - Vulkan SDK][6]
* [NVIDIA - Vulkan Developer][2]
* [NVIDIA - DesignWorks Samples][5]
* [AMD - Vulkan Developer][3]
* [AMD - Vulkan Memory Allocator(VMA)][4]
* [AMD - GPUOpen Libraries & SDKs][13]
* [GDC2019 - NVIDIA Nsight Graphics: Getting The Most From Your Vulkan Applications][19]


## Khronos Group

* [Moving to Vulkan : How to make your 3D graphics more explicit][32]
  * Vulkan 101
  * Command buffers
  * SPIR-V and GLSL, SPIR-V Cross Tool
  * Vertex Fetch and resource descriptors
  * Render passes
  * Synchronisation
  * Swapchains
  * Simultaneous Graphics & Compute
  * Porting apps to Vulkan


## Blog

* [Render Graphs and Vulkan - A Deep Dive][33]
* [Writing an efficient Vulkan renderer][34]


## Github

CIS 565

* [CIS 565 GPU Programming and Architecture][12]
* [CIS 565 Homework1 - Forward+ renderer in Vulkan using Compute Shader][14]
* [CIS 565 Homework2 - Forward+ rendering using Vulkan][15]

Niagara

* [Niagara - a Vulkan renderer that is written on stream from scratch][29]


## vkDOOM3

* [vkDOOM3][18]
* [GDC2018 - Getting Explicit: How Hard is Vulkan Really? (Porting DOOM3 to Vulkan)][17]
* I Am Graphics And So Can You
  * [Part 1 - Intro][20]
  * [Part 2 - Intuition][21]
  * [Part 3 - The First 1,000][22]
  * [Part 4 - Resources Rush The Stage][23]
  * [An Aside - Motivation & Effort][24]
  * [Part 4.5 - idTech][25]
  * [Part 5 - Your Pixels Are Served][26]
  * [Part 6 - Pipelines][27]
  * [Part 7 - The Renderer Of Worlds][28]



[1]:https://www.khronos.org/vulkan/
[2]:https://developer.nvidia.com/Vulkan
[3]:https://gpuopen.com/vulkan/
[4]:https://gpuopen.com/vulkan-memory-allocator/
[5]:https://github.com/nvpro-samples
[6]:https://www.lunarg.com/vulkan-sdk/
[7]:https://vulkan-tutorial.com/
[8]:https://www.khronos.org/vulkan/
[9]:https://www.khronos.org/registry/vulkan/specs/1.0/html/
[10]:https://renderdoc.org/vulkan-in-30-minutes.html
[11]:https://renderdoc.org/vulkan-layer-guide.html
[12]:https://cis565-fall-2020.github.io/
[13]:https://github.com/GPUOpen-LibrariesAndSDKs
[14]:https://github.com/WindyDarian/Vulkan-Forward-Plus-Renderer
[15]:https://github.com/zimengyang/ForwardPlus_Vulkan
[16]:https://github.com/GameTechDev/IntroductionToVulkan
[17]:https://www.gdcvault.com/play/1024848/Getting-Explicit-How-Hard-is
[18]:https://github.com/DustinHLand/vkDOOM3
[19]:https://www.nvidia.com/en-us/on-demand/session/gtcsiliconvalley2019-s9661/
[20]:https://www.fasterthan.life/blog/2017/7/11/i-am-graphics-and-so-can-you-part-1
[21]:https://www.fasterthan.life/blog/2017/7/11/i-am-graphics-and-so-can-you-part-2-intuition
[22]:https://www.fasterthan.life/blog/2017/7/12/i-am-graphics-and-so-can-you-part-3-breaking-ground
[23]:https://www.fasterthan.life/blog/2017/7/13/i-am-graphics-and-so-can-you-part-4-
[24]:https://www.fasterthan.life/blog/2017/7/15/i-am-graphics-and-so-can-you-effort
[25]:https://www.fasterthan.life/blog/2017/7/16/i-am-graphics-and-so-can-you-idtech
[26]:https://www.fasterthan.life/blog/2017/7/22/i-am-graphics-and-so-can-you-part-5-your-pixels-are-served
[27]:https://www.fasterthan.life/blog/2017/7/24/i-am-graphics-and-so-can-you-part-6-pipelines
[28]:https://www.fasterthan.life/blog/2017/7/28/i-am-graphics-and-so-can-you-part-7-the-renderer-of-worlds
[29]:https://github.com/zeux/niagara
[30]:https://vkguide.dev/
[31]:https://vkguide.dev/docs/gpudriven
[32]:https://www.khronos.org/events/moving-to-vulkan-how-to-make-your-3d-graphics-more-explicit
[33]:http://themaister.net/blog/2017/08/15/render-graphs-and-vulkan-a-deep-dive/
[34]:https://zeux.io/2020/02/27/writing-an-efficient-vulkan-renderer/
