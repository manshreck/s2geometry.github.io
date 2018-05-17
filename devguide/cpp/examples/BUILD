# Copyright 2017 Google Inc. All Rights Reserved.
# Author: ericv@google.com (Eric Veach)
#
# Description:
#   This package contains example code used in the S2 library documentation.

package(default_visibility = ["//visibility:private"])

exports_files(
    [
        "CMakeLists.txt",
        "point_index.cc",
        "term_index.cc",
    ],
    visibility = ["//util/geometry/opensource:__pkg__"],
)

cc_test(
    name = "point_index",
    srcs = ["point_index.cc"],
    deps = [
        "//base",
        "//geostore/geomodel/public",
        "//util/geometry:s2",
        "//util/geometry:s2testing",
    ],
)

cc_test(
    name = "term_index",
    srcs = ["term_index.cc"],
    deps = [
        "//base",
        "//geostore/geomodel/public",
        "//util/geometry:s2",
        "//util/geometry:s2testing",
        "//util/gtl:node_hash_map",
    ],
)
