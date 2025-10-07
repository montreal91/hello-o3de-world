
#pragma once

namespace MeinErstesEdelstein
{
    // System Component TypeIds
    inline constexpr const char* MeinErstesEdelsteinSystemComponentTypeId = "{4450B91A-99F7-4069-8ABF-6C493F2A75E2}";
    inline constexpr const char* MeinErstesEdelsteinEditorSystemComponentTypeId = "{631F0B06-F98B-40EB-93C9-0159337F0D09}";

    // Module derived classes TypeIds
    inline constexpr const char* MeinErstesEdelsteinModuleInterfaceTypeId = "{D36DAB9A-C340-4DBC-8618-95299A28A682}";
    inline constexpr const char* MeinErstesEdelsteinModuleTypeId = "{84DE92DC-E1D7-401D-AF8E-B68CE77C0AF6}";
    // The Editor Module by default is mutually exclusive with the Client Module
    // so they use the Same TypeId
    inline constexpr const char* MeinErstesEdelsteinEditorModuleTypeId = MeinErstesEdelsteinModuleTypeId;

    // Interface TypeIds
    inline constexpr const char* MeinErstesEdelsteinRequestsTypeId = "{FE0CEAF8-C620-42CD-B8AD-CC1EEEAE0566}";
} // namespace MeinErstesEdelstein
