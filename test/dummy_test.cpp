// c++ headers

// gtest headers
#include <gtest/gtest.h>

// current project header
#include "device_api/device_api_cooperative_groups.h"
#include "device_api/device_api_cub.h"
#include "device_api/device_api_cublas.h"
#include "device_api/device_api_cucomplex.h"
#include "device_api/device_api_cuda_device.h"
#include "device_api/device_api_cuda_driver.h"
#include "device_api/device_api_cuda_rtc.h"
#include "device_api/device_api_cuda_runtime.h"
// #include "device_api/device_api_cudnn.h"
#include "device_api/device_api_cufft.h"
#include "device_api/device_api_curand.h"
#include "device_api/device_api_cusparse.h"
// #include "device_api/device_api_helper.h"

TEST(DeviceAPI, CompilationTest)
{
    EXPECT_EQ(0, 0);
}
