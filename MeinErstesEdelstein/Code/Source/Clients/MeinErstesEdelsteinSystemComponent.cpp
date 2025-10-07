
#include "MeinErstesEdelsteinSystemComponent.h"

#include <iostream>
#include <stdexcept>

#include <MeinErstesEdelstein/MeinErstesEdelsteinTypeIds.h>

#include <AzCore/Debug/Trace.h>
#include <AzCore/Serialization/SerializeContext.h>

namespace MeinErstesEdelstein
{
    AZ_COMPONENT_IMPL(MeinErstesEdelsteinSystemComponent, "MeinErstesEdelsteinSystemComponent",
        MeinErstesEdelsteinSystemComponentTypeId);

    void MeinErstesEdelsteinSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<MeinErstesEdelsteinSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void MeinErstesEdelsteinSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("MeinErstesEdelsteinService"));
    }

    void MeinErstesEdelsteinSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("MeinErstesEdelsteinService"));
    }

    void MeinErstesEdelsteinSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void MeinErstesEdelsteinSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    MeinErstesEdelsteinSystemComponent::MeinErstesEdelsteinSystemComponent()
    {
        if (MeinErstesEdelsteinInterface::Get() == nullptr)
        {
            MeinErstesEdelsteinInterface::Register(this);
        }
    }

    MeinErstesEdelsteinSystemComponent::~MeinErstesEdelsteinSystemComponent()
    {
        if (MeinErstesEdelsteinInterface::Get() == this)
        {
            MeinErstesEdelsteinInterface::Unregister(this);
        }
    }

    void MeinErstesEdelsteinSystemComponent::Init()
    {
    }

    void MeinErstesEdelsteinSystemComponent::Activate()
    {
        MeinErstesEdelsteinRequestBus::Handler::BusConnect();
        AZ::TickBus::Handler::BusConnect();

        AZ_Error("MeinErstesEdelstein", false, "=== WILKOMMEN FROM ACTIVATE ===");
    }

    void MeinErstesEdelsteinSystemComponent::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
        MeinErstesEdelsteinRequestBus::Handler::BusDisconnect();
    }

    void MeinErstesEdelsteinSystemComponent::OnTick([[maybe_unused]] float deltaTime, [[maybe_unused]] AZ::ScriptTimePoint time)
    {
        static int tickCount = 0;
        tickCount++;

        // AZ_Printf("MeinErstesEdelstein", "Tick #%d\n", tickCount);
        std::cout << "[MeingErsersEdelstein]" << " " << "Tick #" << tickCount << "\n";

        AZ_Error("MeinErstesEdelstein", false, "=== HUGS: WILKOMMEN FROM ACTIVATE ===");

        if (tickCount > 60)  // Wait ~1 second at 60fps
        {
            throw std::runtime_error("Intentional crash!");
        }
    }

} // namespace MeinErstesEdelstein
