#pragma once

#include "idRHI.h"


class RHIDevice {
public:
    static RHIDevice* Create(void* window_handle);
    virtual ~RHIDevice() = default;

    virtual const RHIAdapterInfo* GetAdapterInfo() = 0;
};
