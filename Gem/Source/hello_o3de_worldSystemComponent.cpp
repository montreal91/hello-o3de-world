
#include <AzCore/Serialization/SerializeContext.h>

#include "hello_o3de_worldSystemComponent.h"

#include <hello_o3de_world/hello_o3de_worldTypeIds.h>

namespace hello_o3de_world
{
    AZ_COMPONENT_IMPL(hello_o3de_worldSystemComponent, "hello_o3de_worldSystemComponent",
        hello_o3de_worldSystemComponentTypeId);

    void hello_o3de_worldSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<hello_o3de_worldSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void hello_o3de_worldSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("hello_o3de_worldService"));
    }

    void hello_o3de_worldSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("hello_o3de_worldService"));
    }

    void hello_o3de_worldSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void hello_o3de_worldSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    hello_o3de_worldSystemComponent::hello_o3de_worldSystemComponent()
    {
        if (hello_o3de_worldInterface::Get() == nullptr)
        {
            hello_o3de_worldInterface::Register(this);
        }
    }

    hello_o3de_worldSystemComponent::~hello_o3de_worldSystemComponent()
    {
        if (hello_o3de_worldInterface::Get() == this)
        {
            hello_o3de_worldInterface::Unregister(this);
        }
    }

    void hello_o3de_worldSystemComponent::Init()
    {
    }

    void hello_o3de_worldSystemComponent::Activate()
    {
        hello_o3de_worldRequestBus::Handler::BusConnect();
    }

    void hello_o3de_worldSystemComponent::Deactivate()
    {
        hello_o3de_worldRequestBus::Handler::BusDisconnect();
    }
}
