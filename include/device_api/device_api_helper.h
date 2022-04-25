//This file is hand written to mapping hipcub and cub
//The prefix is selected as DAPI and its corresponding lower case.

#pragma once

#ifdef DAPI_GPU_API_CUDA

#define dapi_checkCudaErrors checkCudaErrors

#endif //DAPI_GPU_API_CUDA


#ifdef DAPI_GPU_API_HIP

#define dapi_checkCudaErrors checkHipErrors

#endif //DAPI_GPU_API_HIP
