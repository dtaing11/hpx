//  Copyright (c) 2007-2008 Hartmut Kaiser
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <hpx/hpx.hpp>
#include <hpx/runtime/components/component_factory.hpp>
#include <hpx/runtime/actions/continuation_impl.hpp>

#include <hpx/util/portable_binary_iarchive.hpp>
#include <hpx/util/portable_binary_oarchive.hpp>

#include <boost/serialization/version.hpp>
#include <boost/serialization/export.hpp>

#include "server/accumulator.hpp"

///////////////////////////////////////////////////////////////////////////////
// Add factory registration functionality
HPX_REGISTER_COMPONENT_MODULE();

///////////////////////////////////////////////////////////////////////////////
typedef hpx::components::managed_component<
    hpx::components::server::accumulator
> accumulator_type;

HPX_REGISTER_MINIMAL_COMPONENT_FACTORY(accumulator_type, accumulator);

///////////////////////////////////////////////////////////////////////////////
// Serialization support for the accumulator actions
HPX_REGISTER_ACTION(accumulator_type::wrapped_type::init_action);
HPX_REGISTER_ACTION(accumulator_type::wrapped_type::add_action);
HPX_REGISTER_ACTION(accumulator_type::wrapped_type::query_action);
HPX_REGISTER_ACTION(accumulator_type::wrapped_type::print_action);
HPX_DEFINE_GET_COMPONENT_TYPE(accumulator_type::wrapped_type);

