#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Shield.generated.h"

class UCapsuleComponent;

UCLASS()
class LYRAGAME_API AShield : public AActor
{
	GENERATED_BODY()

	// States //
	// ====== //
private:
	UPROPERTY()
	APawn* ShieldInstigator;

	UPROPERTY()
	USkeletalMeshComponent* MeshComponent;

	UPROPERTY()
	ACharacter* ShieldInstigatorCharacter;

	UPROPERTY()
	UCapsuleComponent* CharacterCapsule;

	FTimerHandle OnShieldEndedDurationTimerHandle;

protected:
	// States //
	// ====== //
	UPROPERTY(EditAnywhere, Category=Shield, BlueprintReadWrite)
	float ShieldDuration;

	// Subroutines //
	// =========== //
	UFUNCTION(BlueprintNativeEvent)
	void OnShieldEndedDuration();
	
public:
	// Lifecycle //
	// ========= //
	AShield();

protected:
	// Lifecycle //
	// ========= //
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	// Subroutines //
	// =========== //
	void SetTimerForEvent();
};
