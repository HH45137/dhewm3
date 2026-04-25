#pragma once

#include "idRHI.h"


class RHIDevice {
public:
    virtual ~RHIDevice() = default;

    virtual const RHIDevice *Create(void *window_handle);

    virtual const RHIAdapterInfo *GetAdapterInfo() = 0;

    virtual const RHIBuffer *CreateBuffer(
        RHIBufferUsage usage,
        RHIMemoryType memory_type,
        uint32_t size,
        uint32_t stride
    ) = 0;

    virtual const RHITexture *CreateTexture(
        RHITextureFormat usage,
        RHITextureSamplerType sampler_type,
        RHITextureAddressType address_type,
        uint32_t width,
        uint32_t height,
        uint32_t depth,
        uint32_t mip_levels,
        uint32_t sample_count
    ) = 0;
};
