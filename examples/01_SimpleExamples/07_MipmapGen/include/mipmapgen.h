#ifndef MIPMAPGEN_H
#define MIPMAPGEN_H
#include "vulkan_basicengine.h"
class CubeTunnel;

class MipmapGen:public VulkanBasicEngine{
public:
    MipmapGen(bool debug=false);
    ~MipmapGen();

    virtual void prepare();
    virtual void render();
    virtual void draw();

    virtual void OnUpdateUIOverlay(vks::UIOverlay *overlay);
private:
    void createObjects();
    void setupVertexDescriptions();
    void setupDescriptorPool();
    void setupDescriptorSetLayout();
    void setupDescriptorSet();
    void preparePipelines();
    void buildCommandBuffers();
private:
    VkPipelineLayout m_pipelineLayout=VK_NULL_HANDLE;
    VkDescriptorSetLayout m_descriptorSetLayout=VK_NULL_HANDLE;
    struct {
        VkPipelineVertexInputStateCreateInfo inputState;
        std::vector<VkVertexInputBindingDescription> bindingDescriptions;
        std::vector<VkVertexInputAttributeDescription> attributeDescriptions;
    } m_vertices;
    struct Vertex {
        float pos[3];
        float uv[2];
        float normal[3];
    };
private:
    CubeTunnel* m_cubeTunnel=nullptr;
};
#endif
