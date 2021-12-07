// Shoot Them Up Game. TestUnit. All RIghts Recieved

#include "Pickups/STUHealthPickup.h"
#include "Components/STUHealthComponent.h"
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