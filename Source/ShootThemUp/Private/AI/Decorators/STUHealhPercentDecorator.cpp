// Shoot Them Up Game. TestUnit. All RIghts Recieved

#include "AI/Decorators/STUHealhPercentDecorator.h"
#include "AIController.h"
#include "STUUtils.h"
#include "Components/STUHealthComponent.h"

USTUHealhPercentDecorator::USTUHealhPercentDecorator()
{
	NodeName = "Health Percent";
}

bool USTUHealhPercentDecorator::CalculateRawConditionValue(UBehaviorTreeComponent &OwnerComp,
														 uint8 *NodeMemory) const
{
	const auto Controller = OwnerComp.GetAIOwner();
	if (!Controller)
		return false;

	const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(Controller->GetPawn());
	if (!HealthComponent || HealthComponent->IsDead())
		return false;

	return HealthComponent->GetHealthPercent() <= HealthPercent;
}
