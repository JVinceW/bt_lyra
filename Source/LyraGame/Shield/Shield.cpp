#include "Shield.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"

DEFINE_LOG_CATEGORY_STATIC(LogShield, Log, All);

void AShield::OnShieldEndedDuration_Implementation()
{
	// Destroy Actor
	this->Destroy();
}

// Sets default values
AShield::AShield()
	: ShieldInstigator{nullptr}
	  , MeshComponent{nullptr}
	  , ShieldInstigatorCharacter{nullptr}
	  , CharacterCapsule{nullptr}
	  , ShieldDuration(30.f)
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AShield::BeginPlay()
{
	Super::BeginPlay();
	ShieldInstigator = GetInstigator();
	ShieldInstigatorCharacter = Cast<ACharacter>(ShieldInstigator);
	MeshComponent = ShieldInstigatorCharacter->GetMesh();
	CharacterCapsule = ShieldInstigatorCharacter->GetCapsuleComponent();

	// Ignore actor when move myself
	CharacterCapsule->IgnoreActorWhenMoving(this, true);
	MeshComponent->IgnoreActorWhenMoving(ShieldInstigator, true);

	// Set the event timer;
	SetTimerForEvent();
}


// Called every frame
void AShield::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AShield::SetTimerForEvent()
{
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.SetTimer(OnShieldEndedDurationTimerHandle, [this]
	{
		UE_LOG(LogShield, Log, TEXT("Shield ended"))
		// OnShieldEndedDuration();
		OnShieldEndedDurationTimerHandle.Invalidate();
	}, ShieldDuration, false);
}
