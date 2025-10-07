
#pragma once

#include <hello_o3de_world/hello_o3de_worldTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace hello_o3de_world
{
    class hello_o3de_worldRequests
    {
    public:
        AZ_RTTI(hello_o3de_worldRequests, hello_o3de_worldRequestsTypeId);
        virtual ~hello_o3de_worldRequests() = default;
        // Put your public methods here
    };

    class hello_o3de_worldBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using hello_o3de_worldRequestBus = AZ::EBus<hello_o3de_worldRequests, hello_o3de_worldBusTraits>;
    using hello_o3de_worldInterface = AZ::Interface<hello_o3de_worldRequests>;

} // namespace hello_o3de_world
