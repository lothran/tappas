/**
 * Copyright (c) 2021-2022 Hailo Technologies Ltd. All rights reserved.
 * Distributed under the LGPL license
 *(https://www.gnu.org/licenses/old-licenses/lgpl-2.1.txt)
 **/
#include "attach_meta_data.hpp"
#include "../../../plugins/export/encode_json.hpp"

void filter(HailoROIPtr roi, GstVideoFrame *frame) {
  rapidjson::Document d;
  encode_json::encode_hailo_objects_to_json(d, d.allocator(), frame);
  rapidjson::StringBuffer buffer;
  buffer.Clear();
  rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
  jsonDoc.Accept(writer);
  static const gchar *tags[] = {NULL};
  auto meta_info = gst_meta_register_custom("mymeta", tags, NULL, NULL, NULL);
  auto meta = gst_buffer_add_custom_meta(*frame.buffer, "mymeta");
  auto metadata = gst_custom_meta_get_structure(meta);
  auto str = g_string_new(buffer.GetString());
  gst_structure_set(metadata, "property_name", G_TYPE_STRING, str, nullptr);
}
