
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "hello_o3de_worldSystemComponent.h"

#include <hello_o3de_world/hello_o3de_worldTypeIds.h>

namespace hello_o3de_world
{
    class hello_o3de_worldModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(hello_o3de_worldModule, hello_o3de_worldModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(hello_o3de_worldModule, AZ::SystemAllocator);

        hello_o3de_worldModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                hello_o3de_worldSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<hello_o3de_worldSystemComponent>(),
            };
        }
    };
}// namespace hello_o3de_world

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), hello_o3de_world::hello_o3de_worldModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_hello_o3de_world, hello_o3de_world::hello_o3de_worldModule)
#endif
