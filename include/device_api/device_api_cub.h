//This file is hand written to mapping hipcub and cub
//The prefix is selected as DAPI and its corresponding lower case.

#pragma once

#ifdef DAPI_GPU_API_CUDA

#include <cub/cub.cuh>
#define dapi_cub cub

#endif //DAPI_GPU_API_CUDA


#ifdef DAPI_GPU_API_HIP

#include <hipcub/hipcub.hpp>
#define dapi_cub hipcub

#endif //DAPI_GPU_API_HIP
