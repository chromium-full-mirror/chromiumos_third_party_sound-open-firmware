// SPDX-License-Identifier: BSD-3-Clause
//
// Copyright(c) 2022 Intel Corporation. All rights reserved.
//
// Author: Bartosz Kokoszko <bartoszx.kokoszko@intel.com>
// Author: Adrian Bonislawski <adrian.bonislawski@intel.com>

#ifndef __SOF_AUDIO_DEBUG_MODULE_H__
#define __SOF_AUDIO_DEBUG_MODULE_H__
#ifndef MODULE_PRIVAT
#include <sof/audio/component_ext.h>
#include <sof/common.h>
#endif
#include <sof/audio/ipc-config.h>

#include <ipc/stream.h>
#ifndef MODULE_PRIVAT
#include <ipc4/module.h>
#endif
#include <ipc4/base-config.h>
#include <stddef.h>
#include <stdint.h>

#include "debug_module_ipc4.h"

/** forward declaration */
struct debug_module_data;

static inline uint8_t get_channel_location(const channel_map map,
					   const enum ipc4_channel_index channel)
{
	uint8_t offset = 0xF;
	uint8_t i;

	/* Search through all 4 bits of each byte in the integer for the channel. */
	for (i = 0; i < 8; i++) {
		if (((map >> (i * 4)) & 0xF) == (uint8_t)channel) {
			offset = i;
			break;
		}
	}

	return offset;
}

static inline enum ipc4_channel_index get_channel_index(const channel_map map,
							const uint8_t location)
{
	return (enum ipc4_channel_index)((map >> (location * 4)) & 0xF);
}

/**
 * \brief debug_module component private data.
 */
struct debug_module_data {
	struct ipc4_debug_module_cfg config;
};


#endif /* __SOF_AUDIO_DEBUG_MODULE_H__ */
