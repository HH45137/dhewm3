#pragma once

#include <cstdint>
#include <string>
#include <vector>


enum RHIFeature {
    RHI_FEATURE_RAY_TRACING,
    RHI_FEATURE_MESH_SHADER,
    RHI_FEATURE_VRS,

    RHI_FEATURE_COUNT
};

enum RHIResourceState {
    RHI_RESOURCE_STATE_UNINITIALIZED,
    RHI_RESOURCE_STATE_INITIALIZED,

    RHI_RESOURCE_STATE_COUNT
};

enum RHIBufferUsage {
    RHI_BUFFER_USAGE_VERTEX,
    RHI_BUFFER_USAGE_FRAGMENT,
    RHI_BUFFER_USAGE_UNIFORM,
    RHI_BUFFER_USAGE_STORAGE,
    RHI_BUFFER_USAGE_STAGING,

    RHI_BUFFER_USAGE_COUNT
};

enum RHIMemoryType {
    RHI_MEMORY_TYPE_HOST,
    RHI_MEMORY_TYPE_DEVICE,
    RHI_MEMORY_TYPE_SHARED,

    RHI_MEMORY_TYPE_COUNT
};

enum RHITextureSamplerType {
    RHI_SAMPLER_TYPE_NEAREST,
    RHI_SAMPLER_TYPE_LINEAR,

    RHI_SAMPLER_TYPE_COUNT
};

enum RHITextureAddressType {
    RHI_TEXTURE_ADDRESS_TYPE_REPEAT,
    RHI_TEXTURE_ADDRESS_TYPE_MIRROR_REPEAT,
    RHI_TEXTURE_ADDRESS_TYPE_CLAMP_TO_EDGE,
    RHI_TEXTURE_ADDRESS_TYPE_CLAMP_TO_BORDER,

    RHI_TEXTURE_ADDRESS_TYPE_COUNT
};

enum RHITextureFormat {
    RHI_DATA_TEXTURE_R_8,
    RHI_DATA_TEXTURE_RG_8,
    RHI_DATA_TEXTURE_RGB_8,
    RHI_DATA_TEXTURE_RGBA_8,
    RHI_DATA_TEXTURE_UNKNOWN,

    RHI_DATA_TEXTURE_COUNT
};

struct RHIAdapterInfo {
    std::string name;
    size_t ram_size;
    size_t max_texture_size;
    size_t max_uniform_buffer_range;
    std::vector<RHITextureFormat> formats;
    std::vector<RHIFeature> features;
};

struct RHIResource {
    RHIResourceState state;
    size_t ref_count;
    bool is_destroy;
    std::string debug_name;
};

struct RHIBuffer : RHIResource {
    RHIBufferUsage usage;
    RHIMemoryType memory_type;
    uint32_t size;
    uint32_t stride;
};

struct RHITexture : RHIResource {
    RHITextureFormat usage;
    RHITextureSamplerType sampler_type;
    RHITextureAddressType address_type;
    uint32_t width, height, depth;
    uint32_t mip_levels;
    uint32_t sample_count;
};
