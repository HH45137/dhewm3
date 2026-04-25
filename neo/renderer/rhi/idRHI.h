#pragma once

#include <string>
#include <vector>


enum RHIDataFormat {
    RHI_DATA_FORMAT_R_8,
    RHI_DATA_FORMAT_RG_8,
    RHI_DATA_FORMAT_RGB_8,
    RHI_DATA_FORMAT_RGBA_8,
    RHI_DATA_FORMAT_UNKNOWN,

    RHI_DATA_FORMAT_COUNT
};

enum RHIFeature {
    RHI_FEATURE_RAY_TRACING,
    RHI_FEATURE_MESH_SHADER,
    RHI_FEATURE_VRS,

    RHI_FEATURE_COUNT
};

struct RHIAdapterInfo {
    std::string name;
    size_t ram_size;
    size_t max_texture_size;
    size_t max_uniform_buffer_range;
    std::vector<RHIDataFormat> formats;
    std::vector<RHIFeature> features;
};

struct RHIResource {
    size_t ref_count;
    bool is_destroy;
};

struct RHIBuffer : RHIResource{

};
