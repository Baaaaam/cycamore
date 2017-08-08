#ifndef CYCAMORE_SRC_MCORE_REACTOR_H_
#define CYCAMORE_SRC_MCORE_REACTOR_H_

#include "cyclus.h"
#include "cycamore_version.h"

namespace cycamore {

/// @class MultiCoreReactor
/// @section introduction Introduction
/// @section detailedBehavior Detailed Behavior
/// @warning The MultiCoreReactor is experimental
class MultiCoreReactor
    : public cyclus::Institution,
      public cyclus::toolkit::CommodityProducerManager,
      public cyclus::toolkit::Builder {
 public:
  /// Default constructor
  MultiCoreReactor(cyclus::Context* ctx);

  /// Default destructor
  virtual ~MultiCoreReactor();

  virtual std::string version() { return CYCAMORE_VERSION; }

  #pragma cyclus

  #pragma cyclus note {"doc": "An institution that owns and operates a " \
                              "manually entered list of facilities in " \
                              "the input file"}

  /// enter the simulation and register any children present
  virtual void EnterNotify();


 private:

  #pragma cyclus var { \
    "tooltip": "producer facility prototypes",                          \
    "uilabel": "Producer Prototype List",                               \
    "uitype": ["oneormore", "prototype"],                                    \
    "doc": "A set of facility prototypes that this institution can build. " \
    "All prototypes in this list must be based on an archetype that "   \
    "implements the cyclus::toolkit::CommodityProducer interface",      \
    }
  std::vector<std::string> prototypes;
};

}  // namespace cycamore

#endif  // CYCAMORE_SRC_MANAGER_INST_H_
