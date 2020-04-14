/**
 * parameter_generator.cc
 *
 * Copyright 2018. All Rights Reserved.
 *
 * Created: November 28, 2018
 * Authors: Toki Migimatsu
 */

#include "symbolic/utils/parameter_generator.h"

namespace {

using ::symbolic::ParameterGenerator;
using ::symbolic::Object;

std::vector<const std::vector<Object>*>
ParamTypes(const ParameterGenerator::ObjectTypeMap& object_map,
           const std::vector<Object>& params) {
  std::vector<const std::vector<Object>*> types;
  types.reserve(params.size());
  for (const Object& param : params) {
    types.push_back(&object_map.at(param.type().name()));
  }
  return types;
}

}  // namespace

namespace symbolic {

ParameterGenerator::ParameterGenerator(const ObjectTypeMap& object_map,
                                       const std::vector<Object>& params)
    : CombinationGenerator(ParamTypes(object_map, params)) {}

}  // namespace symbolic
