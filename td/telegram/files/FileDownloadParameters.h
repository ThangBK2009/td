#pragma once

#include "td/utils/common.h"

namespace td {

class FileDownloadParameters {
 public:
  static FileDownloadParameters &get_instance() {
    static FileDownloadParameters instance;
    return instance;
  }

  void set_part_size(int64 size) {
    part_size_ = size;
  }

  int64 get_part_size() const {
    return part_size_;
  }

  void set_download_limit_bytes(int64 limit) {
    download_limit_bytes_ = limit;
  }

  int64 download_limit_bytes() const {
    return download_limit_bytes_;
  }

 private:
  FileDownloadParameters() = default;
  int64 download_limit_bytes_ = 20 << 20;  // Default: 20 MB
  int64 part_size_ = 4 << 20;              // Default: 4 MB
};
}  // namespace td