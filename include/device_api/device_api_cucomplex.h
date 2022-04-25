//This file is generated from hipify-src/doc/markdown/cuComplex_API_supported_by_HIP.md with the restriction of <CUDA Ver.> <= 11.5 and <HIP Ver.> <= 4.3.0.
//The prefix is selected as DAPI and its corresponding lower case.

#pragma once

#ifdef DAPI_GPU_API_CUDA

#define dapi_cuComplex cuComplex
#define dapi_cuDoubleComplex cuDoubleComplex
#define dapi_cuFloatComplex cuFloatComplex
#define dapi_cuCabs cuCabs
#define dapi_cuCabsf cuCabsf
#define dapi_cuCadd cuCadd
#define dapi_cuCaddf cuCaddf
#define dapi_cuCdiv cuCdiv
#define dapi_cuCdivf cuCdivf
#define dapi_cuCfma cuCfma
#define dapi_cuCfmaf cuCfmaf
#define dapi_cuCimag cuCimag
#define dapi_cuCimagf cuCimagf
#define dapi_cuCmul cuCmul
#define dapi_cuCmulf cuCmulf
#define dapi_cuComplexDoubleToFloat cuComplexDoubleToFloat
#define dapi_cuComplexFloatToDouble cuComplexFloatToDouble
#define dapi_cuConj cuConj
#define dapi_cuConjf cuConjf
#define dapi_cuCreal cuCreal
#define dapi_cuCrealf cuCrealf
#define dapi_cuCsub cuCsub
#define dapi_cuCsubf cuCsubf
#define dapi_make_cuComplex make_cuComplex
#define dapi_make_cuDoubleComplex make_cuDoubleComplex
#define dapi_make_cuFloatComplex make_cuFloatComplex

#endif //DAPI_GPU_API_CUDA


#ifdef DAPI_GPU_API_HIP

#define dapi_cuComplex hipComplex
#define dapi_cuDoubleComplex hipDoubleComplex
#define dapi_cuFloatComplex hipFloatComplex
#define dapi_cuCabs hipCabs
#define dapi_cuCabsf hipCabsf
#define dapi_cuCadd hipCadd
#define dapi_cuCaddf hipCaddf
#define dapi_cuCdiv hipCdiv
#define dapi_cuCdivf hipCdivf
#define dapi_cuCfma hipCfma
#define dapi_cuCfmaf hipCfmaf
#define dapi_cuCimag hipCimag
#define dapi_cuCimagf hipCimagf
#define dapi_cuCmul hipCmul
#define dapi_cuCmulf hipCmulf
#define dapi_cuComplexDoubleToFloat hipComplexDoubleToFloat
#define dapi_cuComplexFloatToDouble hipComplexFloatToDouble
#define dapi_cuConj hipConj
#define dapi_cuConjf hipConjf
#define dapi_cuCreal hipCreal
#define dapi_cuCrealf hipCrealf
#define dapi_cuCsub hipCsub
#define dapi_cuCsubf hipCsubf
#define dapi_make_cuComplex make_hipComplex
#define dapi_make_cuDoubleComplex make_hipDoubleComplex
#define dapi_make_cuFloatComplex make_hipFloatComplex

#endif //DAPI_GPU_API_HIP
