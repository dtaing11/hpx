# Copyright (c) 2019 The STE||AR-Group
#
# SPDX-License-Identifier: BSL-1.0
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(affinity_headers
    hpx/affinity/affinity_data.hpp hpx/affinity/detail/partlit.hpp
    hpx/affinity/detail/parse_mappings.hpp
    hpx/affinity/parse_affinity_options.hpp
)

# cmake-format: off
set(affinity_compat_headers
    hpx/affinity.hpp => hpx/modules/affinity.hpp
    hpx/runtime/threads/policies/affinity_data.hpp => hpx/modules/affinity.hpp
    hpx/runtime/threads/policies/parse_affinity_options.hpp => hpx/modules/affinity.hpp
)
# cmake-format: on

set(affinity_sources affinity_data.cpp parse_affinity_options.cpp)

include(HPX_AddModule)
add_hpx_module(
  core affinity
  GLOBAL_HEADER_GEN ON
  SOURCES ${affinity_sources}
  HEADERS ${affinity_headers}
  COMPAT_HEADERS ${affinity_compat_headers}
  MODULE_DEPENDENCIES
    hpx_assertion
    hpx_config
    hpx_datastructures
    hpx_errors
    hpx_format
    hpx_topology
    hpx_util
  DEPENDENCIES Hwloc::hwloc
  CMAKE_SUBDIRS tests
)

# see #6579
if(MSVC AND Boost_VERSION_STRING VERSION_LESS "1.79.0")
  target_compile_definitions(hpx_affinity PRIVATE NOMINMAX)
endif()
