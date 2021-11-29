// Shoot Them Up Game. TestUnit. All RIghts Recieved


#include "Components/STUHealthComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TimerManager.h"
	//#include "Dev/STUFireDamageType.h"
//#include "Dev/STUIceDamageType.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthComponent, All, All)

// Sets default values for this component's properties
USTUHealthComponent::USTUHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void USTUHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	check(MaxHealth > 0);

	SetHealth(MaxHealth);
	// ...
	AActor *ComponentOwner = GetOwner();
	if (ComponentOwner)
	{
		ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &USTUHealthComponent::OnTakeAnyDamage);
	}
}

void USTUHealthComponent::OnTakeAnyDamage(AActor *DamagedActor, float Damage, const class UDamageType *DamageType,
											  class AController *InstigatedBy, AActor *DamageCauser)
{
	
	if (Damage <= 0.0f || IsDead() || !GetWorld())
	{
		return;
	}
	
	SetHealth(Health - Damage);

	GetWorld()->GetTimerManager().ClearTimer(HealTimerHandle);

	if (IsDead())
	{
		OnDeath.Broadcast();
	}
	else if (AutoHeal )
	{
		GetWorld()->GetTimerManager().SetTimer(HealTimerHandle, this, &USTUHealthComponent::HealUpdate, HealUpdateTime,
											   true, HealDelay);
	}

	//UE_LOG(LogHealthComponent, Display, TEXT("%f"), Damage);
	//if (damagetype)
	//{
	//	if (damagetype->isa<ustufiredamagetype>())
	//	{
	//		ue_log(loghealthcomponent, display, text("so hot!"));
	//	}
	//	else if (damagetype->isa<ustuicedamagetype>())
	//	{
	//		ue_log(loghealthcomponent, display, text("so cold..."));
	//	}
	//}
	//UE_LOG(BaseCharacterLog, Display, TEXT("Damage: %f"), Damage);
}

void USTUHealthComponent::HealUpdate()
{
	SetHealth(Health + HealModifer);

	if (FMath::IsNearlyEqual(Health,MaxHealth) && GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(HealTimerHandle);
	}
}

void USTUHealthComponent::SetHealth(float NewHealth)
{
	Health = FMath::Clamp(NewHealth, 0.0f, MaxHealth);
	OnHealthChanged.Broadcast(Health);
}
