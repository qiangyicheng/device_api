//This file is hand written to mapping hip_cooperative_groups and cooperative_groups
//The prefix is selected as DAPI and its corresponding lower case.

#pragma once

#ifdef DAPI_GPU_API_CUDA

#include <cooperative_groups.h>

#endif //DAPI_GPU_API_CUDA


#ifdef DAPI_GPU_API_HIP

#include <hip/hip_cooperative_groups.h>

#endif //DAPI_GPU_API_HIP
