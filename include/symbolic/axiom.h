/**
 * axiom.h
 *
 * Copyright 2020. All Rights Reserved.
 *
 * Created: April 23, 2020
 * Authors: Toki Migimatsu
 */

#ifndef SYMBOLIC_AXIOM_H_
#define SYMBOLIC_AXIOM_H_

#include "symbolic/action.h"

namespace symbolic {

class Axiom : public Action {
 public:
  Axiom(const Pddl& pddl, const VAL::operator_* symbol);

  bool IsConsistent(const State& state) const;

 private:
  std::vector<std::vector<Object>> arguments_;
};

}  // namespace symbolic

#endif  // SYMBOLIC_AXIOM_H_