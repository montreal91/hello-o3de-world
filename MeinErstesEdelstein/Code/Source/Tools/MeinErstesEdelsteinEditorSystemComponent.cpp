
#include <AzCore/Serialization/SerializeContext.h>
#include "MeinErstesEdelsteinEditorSystemComponent.h"

#include <MeinErstesEdelstein/MeinErstesEdelsteinTypeIds.h>

namespace MeinErstesEdelstein
{
    AZ_COMPONENT_IMPL(MeinErstesEdelsteinEditorSystemComponent, "MeinErstesEdelsteinEditorSystemComponent",
        MeinErstesEdelsteinEditorSystemComponentTypeId, BaseSystemComponent);

    void MeinErstesEdelsteinEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<MeinErstesEdelsteinEditorSystemComponent, MeinErstesEdelsteinSystemComponent>()
                ->Version(0);
        }
    }

    MeinErstesEdelsteinEditorSystemComponent::MeinErstesEdelsteinEditorSystemComponent() = default;

    MeinErstesEdelsteinEditorSystemComponent::~MeinErstesEdelsteinEditorSystemComponent() = default;

    void MeinErstesEdelsteinEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("MeinErstesEdelsteinEditorService"));
    }

    void MeinErstesEdelsteinEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("MeinErstesEdelsteinEditorService"));
    }

    void MeinErstesEdelsteinEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void MeinErstesEdelsteinEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    void MeinErstesEdelsteinEditorSystemComponent::Activate()
    {
        MeinErstesEdelsteinSystemComponent::Activate();
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void MeinErstesEdelsteinEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
        MeinErstesEdelsteinSystemComponent::Deactivate();
    }

} // namespace MeinErstesEdelstein
