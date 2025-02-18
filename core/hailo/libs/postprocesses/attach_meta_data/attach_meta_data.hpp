/**
* Copyright (c) 2021-2022 Hailo Technologies Ltd. All rights reserved.
* Distributed under the LGPL license (https://www.gnu.org/licenses/old-licenses/lgpl-2.1.txt)
**/
#pragma once
#include "hailo_objects.hpp"
#include "hailo_common.hpp"
#include <gst/gst.h>


__BEGIN_DECLS
 void filter(HailoROIPtr roi,GstVideoFrame * frame);
__END_DECLS
