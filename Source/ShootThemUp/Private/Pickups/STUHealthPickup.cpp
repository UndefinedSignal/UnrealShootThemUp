// Shoot Them Up Game. TestUnit. All RIghts Recieved

#include "Components/STUHealthComponent.h"
#include "Pickups/STUHealthPickup.h"
#include "STUUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthPickup, All, All);

bool ASTUHealthPickup::GivePickupTo(APawn *PlayerPawn)
{
	const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(PlayerPawn);
	if (!HealthComponent || HealthComponent->IsDead())
	{
		return false;
	}

	return HealthComponent->TryToHeal(HealthAmount);
}