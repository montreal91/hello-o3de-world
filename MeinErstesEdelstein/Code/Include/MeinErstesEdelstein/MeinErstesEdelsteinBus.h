
#pragma once

#include <MeinErstesEdelstein/MeinErstesEdelsteinTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace MeinErstesEdelstein
{
    class MeinErstesEdelsteinRequests
    {
    public:
        AZ_RTTI(MeinErstesEdelsteinRequests, MeinErstesEdelsteinRequestsTypeId);
        virtual ~MeinErstesEdelsteinRequests() = default;
        // Put your public methods here
    };

    class MeinErstesEdelsteinBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using MeinErstesEdelsteinRequestBus = AZ::EBus<MeinErstesEdelsteinRequests, MeinErstesEdelsteinBusTraits>;
    using MeinErstesEdelsteinInterface = AZ::Interface<MeinErstesEdelsteinRequests>;

} // namespace MeinErstesEdelstein
