
#include <MeinErstesEdelstein/MeinErstesEdelsteinTypeIds.h>
#include <MeinErstesEdelsteinModuleInterface.h>
#include "MeinErstesEdelsteinSystemComponent.h"

namespace MeinErstesEdelstein
{
    class MeinErstesEdelsteinModule
        : public MeinErstesEdelsteinModuleInterface
    {
    public:

        MeinErstesEdelsteinModule()
        {
            AZ_Printf("MeinErstesEdelstein", "=== MODULE CONSTRUCTOR CALLED ===\n");
        }

        AZ_RTTI(MeinErstesEdelsteinModule, MeinErstesEdelsteinModuleTypeId, MeinErstesEdelsteinModuleInterface);
        AZ_CLASS_ALLOCATOR(MeinErstesEdelsteinModule, AZ::SystemAllocator);

        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<MeinErstesEdelsteinSystemComponent>(),
            };
        }
    };
}// namespace MeinErstesEdelstein

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), MeinErstesEdelstein::MeinErstesEdelsteinModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_MeinErstesEdelstein, MeinErstesEdelstein::MeinErstesEdelsteinModule)
#endif
