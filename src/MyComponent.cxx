
#include "WireCellIface/IConfigurable.h"
#include "WireCellUtil/NamedFactory.h"
#include "WireCellUtil/Logging.h"


class MyComponent : public WireCell::IConfigurable {
public:
    WireCell::Configuration default_configuration() const {
        WireCell::Configuration cfg;
        cfg["param"] = "value";
        return cfg;
    }
    void configure(const WireCell::Configuration& cfg) {
        auto log = WireCell::Log::logger("my");
        log->info(cfg);
    }
        
};

// dump example.  normally, more ifaces than just configurable
WIRECELL_FACTORY(MyComponent, MyComponent, WireCell::IConfigurable)

