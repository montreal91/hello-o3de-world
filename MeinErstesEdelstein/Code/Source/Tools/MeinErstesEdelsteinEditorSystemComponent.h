
#pragma once

#include <AzToolsFramework/API/ToolsApplicationAPI.h>

#include <Clients/MeinErstesEdelsteinSystemComponent.h>

namespace MeinErstesEdelstein
{
    /// System component for MeinErstesEdelstein editor
    class MeinErstesEdelsteinEditorSystemComponent
        : public MeinErstesEdelsteinSystemComponent
        , protected AzToolsFramework::EditorEvents::Bus::Handler
    {
        using BaseSystemComponent = MeinErstesEdelsteinSystemComponent;
    public:
        AZ_COMPONENT_DECL(MeinErstesEdelsteinEditorSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        MeinErstesEdelsteinEditorSystemComponent();
        ~MeinErstesEdelsteinEditorSystemComponent();

    private:
        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        // AZ::Component
        void Activate() override;
        void Deactivate() override;
    };
} // namespace MeinErstesEdelstein
