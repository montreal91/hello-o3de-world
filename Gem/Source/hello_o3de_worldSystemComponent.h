
#pragma once

#include <AzCore/Component/Component.h>

#include <hello_o3de_world/hello_o3de_worldBus.h>

namespace hello_o3de_world
{
    class hello_o3de_worldSystemComponent
        : public AZ::Component
        , protected hello_o3de_worldRequestBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(hello_o3de_worldSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        hello_o3de_worldSystemComponent();
        ~hello_o3de_worldSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // hello_o3de_worldRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
