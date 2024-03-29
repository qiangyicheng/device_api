//This file is generated from hipify-src/doc/markdown/CUDA_RTC_API_supported_by_HIP.md with the restriction of <CUDA Ver.> <= 12.0 and <HIP Ver.> <= 5.4.0.
//The prefix is selected as DAPI and its corresponding lower case.

#pragma once

#ifdef DAPI_GPU_API_CUDA

#include <nvrtc.h>
#define DAPI_NVRTC_ERROR_BUILTIN_OPERATION_FAILURE NVRTC_ERROR_BUILTIN_OPERATION_FAILURE
#define DAPI_NVRTC_ERROR_COMPILATION NVRTC_ERROR_COMPILATION
#define DAPI_NVRTC_ERROR_INTERNAL_ERROR NVRTC_ERROR_INTERNAL_ERROR
#define DAPI_NVRTC_ERROR_INVALID_INPUT NVRTC_ERROR_INVALID_INPUT
#define DAPI_NVRTC_ERROR_INVALID_OPTION NVRTC_ERROR_INVALID_OPTION
#define DAPI_NVRTC_ERROR_INVALID_PROGRAM NVRTC_ERROR_INVALID_PROGRAM
#define DAPI_NVRTC_ERROR_NAME_EXPRESSION_NOT_VALID NVRTC_ERROR_NAME_EXPRESSION_NOT_VALID
#define DAPI_NVRTC_ERROR_NO_LOWERED_NAMES_BEFORE_COMPILATION NVRTC_ERROR_NO_LOWERED_NAMES_BEFORE_COMPILATION
#define DAPI_NVRTC_ERROR_NO_NAME_EXPRESSIONS_AFTER_COMPILATION NVRTC_ERROR_NO_NAME_EXPRESSIONS_AFTER_COMPILATION
#define DAPI_NVRTC_ERROR_OUT_OF_MEMORY NVRTC_ERROR_OUT_OF_MEMORY
#define DAPI_NVRTC_ERROR_PROGRAM_CREATION_FAILURE NVRTC_ERROR_PROGRAM_CREATION_FAILURE
#define DAPI_NVRTC_SUCCESS NVRTC_SUCCESS
#define dapi_nvrtcProgram nvrtcProgram
#define dapi_nvrtcResult nvrtcResult
#define dapi_nvrtcAddNameExpression nvrtcAddNameExpression
#define dapi_nvrtcCompileProgram nvrtcCompileProgram
#define dapi_nvrtcCreateProgram nvrtcCreateProgram
#define dapi_nvrtcDestroyProgram nvrtcDestroyProgram
#define dapi_nvrtcGetErrorString nvrtcGetErrorString
#define dapi_nvrtcGetLoweredName nvrtcGetLoweredName
#define dapi_nvrtcGetPTX nvrtcGetPTX
#define dapi_nvrtcGetPTXSize nvrtcGetPTXSize
#define dapi_nvrtcGetProgramLog nvrtcGetProgramLog
#define dapi_nvrtcGetProgramLogSize nvrtcGetProgramLogSize
#define dapi_nvrtcVersion nvrtcVersion

#endif //DAPI_GPU_API_CUDA


#ifdef DAPI_GPU_API_HIP

#include <hip/hip_runtime.h>
#include <hiprtc.h>
#define DAPI_NVRTC_ERROR_BUILTIN_OPERATION_FAILURE HIPRTC_ERROR_BUILTIN_OPERATION_FAILURE
#define DAPI_NVRTC_ERROR_COMPILATION HIPRTC_ERROR_COMPILATION
#define DAPI_NVRTC_ERROR_INTERNAL_ERROR HIPRTC_ERROR_INTERNAL_ERROR
#define DAPI_NVRTC_ERROR_INVALID_INPUT HIPRTC_ERROR_INVALID_INPUT
#define DAPI_NVRTC_ERROR_INVALID_OPTION HIPRTC_ERROR_INVALID_OPTION
#define DAPI_NVRTC_ERROR_INVALID_PROGRAM HIPRTC_ERROR_INVALID_PROGRAM
#define DAPI_NVRTC_ERROR_NAME_EXPRESSION_NOT_VALID HIPRTC_ERROR_NAME_EXPRESSION_NOT_VALID
#define DAPI_NVRTC_ERROR_NO_LOWERED_NAMES_BEFORE_COMPILATION HIPRTC_ERROR_NO_LOWERED_NAMES_BEFORE_COMPILATION
#define DAPI_NVRTC_ERROR_NO_NAME_EXPRESSIONS_AFTER_COMPILATION HIPRTC_ERROR_NO_NAME_EXPRESSIONS_AFTER_COMPILATION
#define DAPI_NVRTC_ERROR_OUT_OF_MEMORY HIPRTC_ERROR_OUT_OF_MEMORY
#define DAPI_NVRTC_ERROR_PROGRAM_CREATION_FAILURE HIPRTC_ERROR_PROGRAM_CREATION_FAILURE
#define DAPI_NVRTC_SUCCESS HIPRTC_SUCCESS
#define dapi_nvrtcProgram hiprtcProgram
#define dapi_nvrtcResult hiprtcResult
#define dapi_nvrtcAddNameExpression hiprtcAddNameExpression
#define dapi_nvrtcCompileProgram hiprtcCompileProgram
#define dapi_nvrtcCreateProgram hiprtcCreateProgram
#define dapi_nvrtcDestroyProgram hiprtcDestroyProgram
#define dapi_nvrtcGetErrorString hiprtcGetErrorString
#define dapi_nvrtcGetLoweredName hiprtcGetLoweredName
#define dapi_nvrtcGetPTX hiprtcGetCode
#define dapi_nvrtcGetPTXSize hiprtcGetCodeSize
#define dapi_nvrtcGetProgramLog hiprtcGetProgramLog
#define dapi_nvrtcGetProgramLogSize hiprtcGetProgramLogSize
#define dapi_nvrtcVersion hiprtcVersion

#endif //DAPI_GPU_API_HIP
