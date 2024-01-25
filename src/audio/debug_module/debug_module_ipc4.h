// SPDX-License-Identifier: BSD-3-Clause
//
// Copyright(c) 2022 Intel Corporation. All rights reserved.
//
// Author: Bartosz Kokoszko <bartoszx.kokoszko@intel.com>

#ifndef __SOF_IPC4_DEBUG_MODULE_H__
#define __SOF_IPC4_DEBUG_MODULE_H__

#include <ipc4/base-config.h>

/**
 *  \brief bits field map which helps to describe each channel location a the data stream buffer
 */
typedef uint32_t channel_map;

enum debug_module_module_config_params {
	IPC4_DEBUG_MODULE_INVALID                     = 0,
	IPC4_DEBUG_MODULE_HANG_FW_TO_TEST_WATCHDOG    = 1,
	IPC4_DEBUG_MODULE_I2C_XFER                    = 2,
	IPC4_DEBUG_MODULE_WDT_ENABLE_SET              = 3,
	IPC4_DEBUG_MODULE_REGISTER_CAMERA_DEV         = 4,
	IPC4_DEBUG_MODULE_SHA384_TEST                 = 5,
	IPC4_DEBUG_MODULE_CREATE_APP_TASK             = 6,
	IPC4_DEBUG_MODULE_REMOVE_APP_TASK             = 7,
	IPC4_DEBUG_MODULE_DMIC_PERIODIC_START_TEST    = 8,
	IPC4_DEBUG_MODULE_DTF_INITIALIZE              = 9,
	IPC4_DEBUG_MODULE_DTF_SEND_MESSAGE            = 10,
	IPC4_DEBUG_MODULE_DTF_READ_REGISTER           = 11,
	IPC4_DEBUG_MODULE_DTF_WRITE_REGISTER          = 12,
	IPC4_DEBUG_MODULE_DTF_WRITE_64_REGISTER       = 13,
	IPC4_DEBUG_MODULE_DTF_WRITE_PKT_32BIT_PAYLOAD = 14,
	IPC4_DEBUG_MODULE_POWER_MATRIX_TEST           = 15,
	IPC4_DEBUG_MODULE_FW_EXCEPTION_TEST           = 16,
	IPC4_DEBUG_MODULE_MEMORY_ALLOCATE_TEST        = 17,
	IPC4_DEBUG_MODULE_GNA_TESTS                   = 18,
	IPC4_DEBUG_MODULE_GNA_TESTS_STATUS            = 19,
};

#define DEBUG_MODULE_COEFFS_LENGTH       8
#define IPC4_DEBUG_MODULE_MODULE_OUTPUT_PINS_COUNT	1
#ifndef __packed
#define __packed __attribute__((packed))
#endif
struct ipc4_debug_module_cfg {
	struct ipc4_base_module_cfg base_cfg;
} __packed __aligned(8);

#endif /* __SOF_IPC4_DEBUG_MODULE_H__ */
