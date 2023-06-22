//This file is hand written to mapping helper_hip( which is not implemented ) and helper_cuda
//The prefix is selected as DAPI and its corresponding lower case.

#pragma once

#ifdef DAPI_GPU_API_CUDA

#ifdef __cuda_cuda_h__
#ifndef CUDA_DRIVER_API
#define CUDA_DRIVER_API
#endif
#endif
#include <helper_cuda.h>
#define dapi_checkCudaErrors checkCudaErrors

#endif //DAPI_GPU_API_CUDA


#ifdef DAPI_GPU_API_HIP

#include <cstdio>
#define dapi_checkCudaErrors checkHipErrors

namespace device_api {
    namespace workaround {
        template <typename T>
        inline void hipCheck(T result, char const* const func, const char* const file,
            int const line) {
            if (result) {
                fprintf(stderr, "HIP error at %s:%d code=%d \"%s\" \n", file, line,
                    static_cast<unsigned int>(result), func);
                exit(EXIT_FAILURE);
            }
        }
    }
}

#define checkHipErrors(val) device_api::workaround::hipCheck((val), #val, __FILE__, __LINE__)

#endif //DAPI_GPU_API_HIP
