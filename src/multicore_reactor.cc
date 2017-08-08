// Implements the MultiCoreReactor class
#include "multicore_reactor.h"

namespace cycamore {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
MultiCoreReactor::MultiCoreReactor(cyclus::Context* ctx) : cyclus::Institution(ctx) { }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
MultiCoreReactor::~MultiCoreReactor() {}


#define DECLARE_HAS_MEMBER(__trait_name__, __member_name__)                          \
                                                                                     \
    template <typename __boost_has_member_T__>                                       \
    class __trait_name__                                                             \
    {                                                                                \
        using check_type = ::std::remove_const_t<__boost_has_member_T__>;            \
        struct no_type {char x[2];};                                                 \
        using  yes_type = char;                                                      \
                                                                                     \
        struct  base { void __member_name__() {}};                                   \
        struct mixin : public base, public check_type {};                            \
                                                                                     \
        template <void (base::*)()> struct aux {};                                   \
                                                                                     \
        template <typename U> static no_type  test(aux<&U::__member_name__>*);       \
        template <typename U> static yes_type test(...);                             \
                                                                                     \
        public:                                                                      \
                                                                                     \
        static constexpr bool value = (sizeof(yes_type) == sizeof(test<mixin>(0)));  \
    }

// INSTANTIATE
DECLARE_HAS_MEMBER(CanRun);


void MultiCoreReactor::EnterNotify() {
  cyclus::Institution::EnterNotify();

  for (int i = 0; i < prototypes.size(); i++) {
    std::string s_proto = prototypes[i];
    context()->SchedBuild(this, s_proto);  //builds on next timestep
    BuildNotify(this);
  }

  std::set<Agent*>::iterator it;
  for ( it = this->children().begin(); it != this->children().end(); it++){
    std::cout << Has_CanRun<it>::value << std::endl;
  }
}



// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
extern "C" cyclus::Agent* ConstructMultiCoreReactor(cyclus::Context* ctx) {
  return new MultiCoreReactor(ctx);
}

}  // namespace cycamore
