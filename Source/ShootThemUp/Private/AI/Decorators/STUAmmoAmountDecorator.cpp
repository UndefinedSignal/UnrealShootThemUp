// Shoot Them Up Game. TestUnit. All RIghts Recieved

#include "AI/Decorators/STUAmmoAmountDecorator.h"
#include "AIController.h"
#include "Components/STUWeaponComponent.h"
#include "STUUtils.h"

USTUAmmoAmountDecorator::USTUAmmoAmountDecorator()
{
	NodeName = "Ammo Amount";
}

bool USTUAmmoAmountDecorator::CalculateRawConditionValue(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) const
{
	const auto Controller = OwnerComp.GetAIOwner();
	if (!Controller)
	{
		return false;
	}

	const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(Controller->GetPawn());

	if (!WeaponComponent)
	{
		return false;
	}

	return WeaponComponent->NeedAmmo(WeaponType);
}
