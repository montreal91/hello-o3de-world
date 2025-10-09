
#include <MeinErstesEdelstein/MeinErstesEdelsteinTypeIds.h>
#include <MeinErstesEdelsteinModuleInterface.h>
#include "MeinErstesEdelsteinEditorSystemComponent.h"

namespace MeinErstesEdelstein
{
    class MeinErstesEdelsteinEditorModule
        : public MeinErstesEdelsteinModuleInterface
    {
    public:
        AZ_RTTI(MeinErstesEdelsteinEditorModule, MeinErstesEdelsteinEditorModuleTypeId, MeinErstesEdelsteinModuleInterface);
        AZ_CLASS_ALLOCATOR(MeinErstesEdelsteinEditorModule, AZ::SystemAllocator);

        MeinErstesEdelsteinEditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                MeinErstesEdelsteinEditorSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<MeinErstesEdelsteinEditorSystemComponent>(),
            };
        }
    };
}// namespace MeinErstesEdelstein

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME, _Editor), MeinErstesEdelstein::MeinErstesEdelsteinEditorModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_MeinErstesEdelstein_Editor, MeinErstesEdelstein::MeinErstesEdelsteinEditorModule)
#endif
