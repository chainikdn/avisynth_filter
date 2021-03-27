// License: https://github.com/CrendKing/avisynth_filter/blob/master/LICENSE

#pragma once

#include "pch.h"
#include "version.h"


namespace AvsFilter {

// {E5E2C1A6-C90F-4247-8BF5-604FB180A932}
DEFINE_GUID(inline CLSID_AviSynthFilter,
            0xe5e2c1a6, 0xc90f, 0x4247, 0x8b, 0xf5, 0x60, 0x4f, 0xb1, 0x80, 0xa9, 0x32);

// {90C56868-7D47-4AA2-A42D-06406A6DB35F}
DEFINE_GUID(inline CLSID_AvsPropSettings,
            0x90c56868, 0x7d47, 0x4aa2, 0xa4, 0x2d, 0x06, 0x40, 0x6a, 0x6d, 0xb3, 0x5f);

// {E58206EF-C9F2-4F8C-BF0B-975C28552700}
DEFINE_GUID(inline CLSID_AvsPropStatus,
            0xe58206ef, 0xc9f2, 0x4f8c, 0xbf, 0x0b, 0x97, 0x5c, 0x28, 0x55, 0x27, 0x00);

// {85C582FE-5B6F-4BE5-A0B0-57A4FDAB4412}
DEFINE_GUID(inline IID_IAvsFilter,
            0x85c582fe, 0x5b6f, 0x4be5, 0xa0, 0xb0, 0x57, 0xa4, 0xfd, 0xab, 0x44, 0x12);

static const GUID MEDIASUBTYPE_I420                                  = FOURCCMap('024I');
static const GUID MEDIASUBTYPE_YV24                                  = FOURCCMap('42VY');

#ifdef _DEBUG
#define FILTER_NAME_SUFFIX                                             " [Debug]"
#else
#define FILTER_NAME_SUFFIX
#endif // DEBUG
#define SETTINGS_NAME_SUFFIX                                           " Settings"
#define STATUS_NAME_SUFFIX                                             " Status"

#define FILTER_NAME_FULL                                               FILTER_NAME_WIDE FILTER_NAME_SUFFIX
#define SETTINGS_NAME_FULL                                             FILTER_NAME_WIDE SETTINGS_NAME_SUFFIX FILTER_NAME_SUFFIX
#define STATUS_NAME_FULL                                               FILTER_NAME_WIDE STATUS_NAME_SUFFIX FILTER_NAME_SUFFIX

// interface version 7 = AviSynth+ 3.5
static constexpr const int MINIMUM_AVISYNTH_PLUS_INTERFACE_VERSION   = 7;

/*
 * Extra number of frames received before blocking upstream from flooding the input queue.
 * Once reached, it must wait until the output thread delivers and GC source frames.
 */
static constexpr const int EXTRA_SOURCE_FRAMES_AHEAD_OF_DELIVERY     = 0;

/*
 * If an output frame's stop time is this value close to the the next source frame's
 * start time, make up its stop time with the padding.
 * This trick helps eliminating frame time drift due to precision loss.
 * Unit is 100ns. 10 = 1ms.
 */
static constexpr const int MAX_OUTPUT_FRAME_DURATION_PADDING         = 10;

/*
 * Some source filter may not set the VIDEOINFOHEADER::AvgTimePerFrame field.
 * Default to 25 FPS in such cases.
 */
static constexpr const REFERENCE_TIME DEFAULT_AVG_TIME_PER_FRAME     = 400000;
static constexpr const int STATUS_PAGE_TIMER_INTERVAL_MS             = 1000;
static constexpr const WCHAR *UNAVAILABLE_SOURCE_PATH                = L"N/A";

/*
 * Stream could last forever. Use a large power as the fake number of frames.
 * Avoid using too large number because some AviSynth filters allocate memory based on the number of frames.
 * Also, some filters may perform calculation on it, resulting overflow.
 * Same as ffdshow, uses a highly composite number 10810800, which could last 50 hours for a 60fps stream.
 */
static constexpr const int NUM_FRAMES_FOR_INFINITE_STREAM            = 10810800;

static constexpr const WCHAR *REGISTRY_KEY_NAME                      = L"Software\\AviSynthFilter";
static constexpr const WCHAR *SETTING_NAME_AVS_FILE                  = L"AvsFile";
static constexpr const WCHAR *SETTING_NAME_LOG_FILE                  = L"LogFile";
static constexpr const WCHAR *SETTING_NAME_INPUT_FORMAT_PREFIX       = L"InputFormat_";
static constexpr const WCHAR *SETTING_NAME_REMOTE_CONTROL            = L"RemoteControl";
static constexpr const WCHAR *SETTING_NAME_EXTRA_SOURCE_BUFFER       = L"ExtraSourceBuffer";

static constexpr const int REMOTE_CONTROL_SMTO_TIMEOUT_MS            = 1000;

}
