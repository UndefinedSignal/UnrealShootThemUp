// Shoot Them Up Game. TestUnit. All RIghts Recieved

#include "Weapon/Components/STUWeaponFXComponent.h"
#include "Components/DecalComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"

USTUWeaponFXComponent::USTUWeaponFXComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USTUWeaponFXComponent::PlayImpactFX(const FHitResult &Hit)
{
	auto ImpactData = DefaultImpactData;

	if (Hit.PhysMaterial.IsValid())
	{
		const auto PhysMat = Hit.PhysMaterial.Get();
		if (ImpactDataMap.Contains(PhysMat))
		{
			ImpactData = ImpactDataMap[PhysMat];
		}
	}

	// Niagara
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(),				 //
												   ImpactData.NiagaraEffect, //
												   Hit.ImpactPoint,			 //
												   Hit.ImpactNormal.Rotation());
	// Decal
	auto DecalComponent = UGameplayStatics::SpawnDecalAtLocation(GetWorld(),					//
																 ImpactData.DecalData.Material, //
																 ImpactData.DecalData.Size,		//
																 Hit.ImpactPoint,				//
																 Hit.ImpactNormal.Rotation());
	if (DecalComponent)
	{
		DecalComponent->SetFadeOut(ImpactData.DecalData.LifeTime, ImpactData.DecalData.FadeOutTime);
	}
}