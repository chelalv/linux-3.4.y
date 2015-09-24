/*
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from NEXELL Limited
 * (C) COPYRIGHT 2010-2013 NEXELL Limited
 * ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from NEXELL Limited.
 */

#ifndef _VR_UTGARD_PROFILING_EVENTS_H_
#define _VR_UTGARD_PROFILING_EVENTS_H_

/*
 * The event ID is a 32 bit value consisting of different fields
 * reserved, 4 bits, for future use
 * event type, 4 bits, cinstr_profiling_event_type_t
 * event channel, 8 bits, the source of the event.
 * event data, 16 bit field, data depending on event type
 */

/**
 * Specifies what kind of event this is
 */
typedef enum {
	VR_PROFILING_EVENT_TYPE_SINGLE  = 0 << 24,
	VR_PROFILING_EVENT_TYPE_START   = 1 << 24,
	VR_PROFILING_EVENT_TYPE_STOP    = 2 << 24,
	VR_PROFILING_EVENT_TYPE_SUSPEND = 3 << 24,
	VR_PROFILING_EVENT_TYPE_RESUME  = 4 << 24,
} cinstr_profiling_event_type_t;


/**
 * Secifies the channel/source of the event
 */
typedef enum {
	VR_PROFILING_EVENT_CHANNEL_SOFTWARE =  0 << 16,
	VR_PROFILING_EVENT_CHANNEL_GP0      =  1 << 16,
	VR_PROFILING_EVENT_CHANNEL_PP0      =  5 << 16,
	VR_PROFILING_EVENT_CHANNEL_PP1      =  6 << 16,
	VR_PROFILING_EVENT_CHANNEL_PP2      =  7 << 16,
	VR_PROFILING_EVENT_CHANNEL_PP3      =  8 << 16,
	VR_PROFILING_EVENT_CHANNEL_PP4      =  9 << 16,
	VR_PROFILING_EVENT_CHANNEL_PP5      = 10 << 16,
	VR_PROFILING_EVENT_CHANNEL_PP6      = 11 << 16,
	VR_PROFILING_EVENT_CHANNEL_PP7      = 12 << 16,
	VR_PROFILING_EVENT_CHANNEL_GPU      = 21 << 16,
} cinstr_profiling_event_channel_t;


#define VR_PROFILING_MAKE_EVENT_CHANNEL_GP(num) (((VR_PROFILING_EVENT_CHANNEL_GP0 >> 16) + (num)) << 16)
#define VR_PROFILING_MAKE_EVENT_CHANNEL_PP(num) (((VR_PROFILING_EVENT_CHANNEL_PP0 >> 16) + (num)) << 16)

/**
 * These events are applicable when the type VR_PROFILING_EVENT_TYPE_SINGLE is used from software channel
 */
typedef enum {
	VR_PROFILING_EVENT_REASON_SINGLE_SW_NONE                  = 0,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_EGL_NEW_FRAME         = 1,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_FLUSH                 = 2,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_EGL_SWAP_BUFFERS      = 3,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_FB_EVENT              = 4,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_GP_ENQUEUE            = 5,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_PP_ENQUEUE            = 6,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_READBACK              = 7,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_WRITEBACK             = 8,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_ENTER_API_FUNC        = 10,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_LEAVE_API_FUNC        = 11,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_DISCARD_ATTACHMENTS   = 13,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_UMP_TRY_LOCK          = 53,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_UMP_LOCK              = 54,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_UMP_UNLOCK            = 55,
	VR_PROFILING_EVENT_REASON_SINGLE_LOCK_CONTENDED           = 56,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_EGL_VR_FENCE_DUP    = 57,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_EGL_SET_PP_JOB_FENCE  = 58,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_EGL_WAIT_SYNC         = 59,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_EGL_CREATE_FENCE_SYNC = 60,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_EGL_CREATE_NATIVE_FENCE_SYNC = 61,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_EGL_FENCE_FLUSH       = 62,
	VR_PROFILING_EVENT_REASON_SINGLE_SW_EGL_FLUSH_SERVER_WAITS= 63,
} cinstr_profiling_event_reason_single_sw_t;

/**
 * These events are applicable when the type VR_PROFILING_EVENT_TYPE_START/STOP is used from software channel
 * to inform whether the core is physical or virtual
 */
typedef enum {
	VR_PROFILING_EVENT_REASON_START_STOP_HW_PHYSICAL  = 0,
	VR_PROFILING_EVENT_REASON_START_STOP_HW_VIRTUAL   = 1,
} cinstr_profiling_event_reason_start_stop_hw_t;

/**
 * These events are applicable when the type VR_PROFILING_EVENT_TYPE_START/STOP is used from software channel
 */
typedef enum {
	/*VR_PROFILING_EVENT_REASON_START_STOP_SW_NONE            = 0,*/
	VR_PROFILING_EVENT_REASON_START_STOP_SW_VR            = 1,
	VR_PROFILING_EVENT_REASON_START_STOP_SW_CALLBACK_THREAD = 2,
	VR_PROFILING_EVENT_REASON_START_STOP_SW_WORKER_THREAD   = 3,
	VR_PROFILING_EVENT_REASON_START_STOP_SW_BOTTOM_HALF     = 4,
	VR_PROFILING_EVENT_REASON_START_STOP_SW_UPPER_HALF      = 5,
} cinstr_profiling_event_reason_start_stop_sw_t;

/**
 * These events are applicable when the type VR_PROFILING_EVENT_TYPE_SUSPEND/RESUME is used from software channel
 */
typedef enum {
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_NONE                     =  0, /* used */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_PIPELINE_FULL            =  1, /* NOT used */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_VSYNC                    = 26, /* used in some build configurations */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_FB_IFRAME_WAIT           = 27, /* USED */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_FB_IFRAME_SYNC           = 28, /* USED */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_VG_WAIT_FILTER_CLEANUP   = 29, /* used */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_VG_WAIT_TEXTURE          = 30, /* used */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_GLES_WAIT_MIPLEVEL       = 31, /* used */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_GLES_WAIT_READPIXELS     = 32, /* used */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_EGL_WAIT_SWAP_IMMEDIATE  = 33, /* NOT used */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_ICS_QUEUE_BUFFER         = 34, /* USED */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_ICS_DEQUEUE_BUFFER       = 35, /* USED */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_UMP_LOCK                 = 36, /* Not currently used */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_X11_GLOBAL_LOCK          = 37, /* Not currently used */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_X11_SWAP                 = 38, /* Not currently used */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_VR_EGL_IMAGE_SYNC_WAIT = 39, /* USED */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_GP_JOB_HANDLING          = 40, /* USED */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_PP_JOB_HANDLING          = 41, /* USED */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_EGL_VR_FENCE_MERGE     = 42, /* USED */
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_EGL_VR_FENCE_DUP       = 43,
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_EGL_FLUSH_SERVER_WAITS   = 44,
	VR_PROFILING_EVENT_REASON_SUSPEND_RESUME_SW_EGL_WAIT_SYNC            = 45, /* USED */
} cinstr_profiling_event_reason_suspend_resume_sw_t;

/**
 * These events are applicable when the type VR_PROFILING_EVENT_TYPE_SINGLE is used from a HW channel (GPx+PPx)
 */
typedef enum {
	VR_PROFILING_EVENT_REASON_SINGLE_HW_NONE          = 0,
	VR_PROFILING_EVENT_REASON_SINGLE_HW_INTERRUPT     = 1,
	VR_PROFILING_EVENT_REASON_SINGLE_HW_FLUSH         = 2,
} cinstr_profiling_event_reason_single_hw_t;

/**
 * These events are applicable when the type VR_PROFILING_EVENT_TYPE_SINGLE is used from the GPU channel
 */
typedef enum {
	VR_PROFILING_EVENT_REASON_SINGLE_GPU_NONE              = 0,
	VR_PROFILING_EVENT_REASON_SINGLE_GPU_FREQ_VOLT_CHANGE  = 1,
	VR_PROFILING_EVENT_REASON_SINGLE_GPU_L20_COUNTERS      = 2,
	VR_PROFILING_EVENT_REASON_SINGLE_GPU_L21_COUNTERS      = 3,
	VR_PROFILING_EVENT_REASON_SINGLE_GPU_L22_COUNTERS      = 4,
} cinstr_profiling_event_reason_single_gpu_t;

/**
 * These values are applicable for the 3rd data parameter when
 * the type VR_PROFILING_EVENT_TYPE_START is used from the software channel
 * with the VR_PROFILING_EVENT_REASON_START_STOP_BOTTOM_HALF reason.
 */
typedef enum {
	VR_PROFILING_EVENT_DATA_CORE_GP0             =  1,
	VR_PROFILING_EVENT_DATA_CORE_PP0             =  5,
	VR_PROFILING_EVENT_DATA_CORE_PP1             =  6,
	VR_PROFILING_EVENT_DATA_CORE_PP2             =  7,
	VR_PROFILING_EVENT_DATA_CORE_PP3             =  8,
	VR_PROFILING_EVENT_DATA_CORE_PP4             =  9,
	VR_PROFILING_EVENT_DATA_CORE_PP5             = 10,
	VR_PROFILING_EVENT_DATA_CORE_PP6             = 11,
	VR_PROFILING_EVENT_DATA_CORE_PP7             = 12,
} cinstr_profiling_event_data_core_t;

#define VR_PROFILING_MAKE_EVENT_DATA_CORE_GP(num) (VR_PROFILING_EVENT_DATA_CORE_GP0 + (num))
#define VR_PROFILING_MAKE_EVENT_DATA_CORE_PP(num) (VR_PROFILING_EVENT_DATA_CORE_PP0 + (num))


#endif /*_VR_UTGARD_PROFILING_EVENTS_H_*/