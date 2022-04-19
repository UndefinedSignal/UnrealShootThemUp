// Shoot Them Up Game. TestUnit. All RIghts Recieved

#include "UI/STURoundStatisticsWidget.h"
#include "STUPlayerState.h"
#include "STUGameModeBase.h"

int32 USTURoundStatisticsWidget::GetPlayerKills() const
{
	const auto PlayerState = GetSTUPlayerState();
	return PlayerState ? PlayerState->GetKillsNum() : 0;
}
int32 USTURoundStatisticsWidget::GetPlayerDeaths() const
{
	const auto PlayerState = GetSTUPlayerState();
	return PlayerState ? PlayerState->GetDeathsNum() : 0;
}
int32 USTURoundStatisticsWidget::GetCurrentRounNum() const
{
	const auto GameMode = GetSTUGameMode();
	return GameMode ? GameMode->GetCurrentRound() : 0;
}
int32 USTURoundStatisticsWidget::GetRoundsCounter() const
{
	const auto GameMode = GetSTUGameMode();
	return GameMode ? GameMode->GetGameData().RoundsNum : 0;
}
int32 USTURoundStatisticsWidget::GetRoundRemainingTime() const
{
	const auto GameMode = GetSTUGameMode();
	return GameMode ? GameMode->GetRoundCountDown() : 0;
}

ASTUGameModeBase *USTURoundStatisticsWidget::GetSTUGameMode() const
{
	return GetWorld() ? Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode()) : nullptr;
}
ASTUPlayerState *USTURoundStatisticsWidget::GetSTUPlayerState() const
{
	return GetOwningPlayer() ? Cast<ASTUPlayerState>(GetOwningPlayer()->PlayerState) : nullptr;
}