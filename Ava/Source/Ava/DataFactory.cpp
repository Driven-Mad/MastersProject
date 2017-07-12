// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "DataFactory.h"


// Sets default values
ADataFactory::ADataFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Items = SetupItems();

}

// Called when the game starts or when spawned
void ADataFactory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADataFactory::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

//Forward Declaration
TMap<Item, ItemData> ADataFactory::Items;

TMap<Item, ItemData> ADataFactory::SetupItems()
{
	// setup out item data container
	TMap<Item, ItemData> tItems;
	
	ItemData blank;
	blank.Add(ItemDataVariables::itemDescription, "");
	blank.Add(ItemDataVariables::itemEnumIdentifier, "BLANK");
	blank.Add(ItemDataVariables::itemMeshFilepath, "");
	blank.Add(ItemDataVariables::itemSpriteFilepath, "");
	blank.Add(ItemDataVariables::itemSelectedSpriteFilepath, "");
	blank.Add(ItemDataVariables::itemName, "");
	tItems.Add(Item::BLANK, blank);

	ItemData a;
	a.Add(ItemDataVariables::itemDescription,"Endless Knot - The intertwining of lines in the eternal knot is said to symbolize how everything is connected. It can also represent how religion and secular affairs, as well as compassion and wisdom are united and connected to each other.");
	a.Add(ItemDataVariables::itemEnumIdentifier, "Scroll01");
	a.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe");
	a.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Scroll1.Scroll1");
	a.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Scroll1Hovered.Scroll1Hovered");
	a.Add(ItemDataVariables::itemName, "Endless Knot Scroll");
	tItems.Add(Item::Scroll01, a);

	ItemData b; 
	b.Add(ItemDataVariables::itemDescription, "Lotus - The lotus has been used in many teachings of Buddhism to impart the true nature of all mankind. The roots of the lotus plant are stuck deep in the mud, but it still grows above murky water and blossoms into a beautiful, sweet-smelling flower. ");
	b.Add(ItemDataVariables::itemEnumIdentifier, "Scroll02");
	b.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe");
	b.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Scroll2.Scroll2");
	b.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Scroll2Hovered.Scroll2Hovered");
	b.Add(ItemDataVariables::itemName, "Lotus Scroll");
	tItems.Add(Item::Scroll02, b);

	ItemData c;
	c.Add(ItemDataVariables::itemDescription, "Banner of Victory - This symbol represents how Buddha won over the demon Mara. This demon, in Buddhism, is synonymous to passion, lust and pride. The Banner of Victory is used to remind people that one must win over their own pride, lust and passions to be able to reach enlightenment.");
	c.Add(ItemDataVariables::itemEnumIdentifier, "Scroll03");
	c.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe");
	c.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Scroll3.Scroll3"); 
	c.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Scroll3Hovered.Scroll3Hovered");
	c.Add(ItemDataVariables::itemName, "Banner of Victory Scroll");
	tItems.Add(Item::Scroll03, c);

	ItemData d;
	d.Add(ItemDataVariables::itemDescription, "Dharma Wheel - This wheel is also called the dharmachakra or the dhamma chakka and is often used to represent Buddha himself. It has also universally become the symbol for Buddhism. The dharma wheel has eight spokes, which represent Buddha’s Eightfold Path.");
	d.Add(ItemDataVariables::itemEnumIdentifier, "Scroll04");
	d.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe");
	d.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Scroll4.Scroll4");
	d.Add(ItemDataVariables::itemName, "Dharma Wheel Scroll");
	tItems.Add(Item::Scroll04, d);

	ItemData e;
	e.Add(ItemDataVariables::itemDescription, "Bumpa - A vase can be filled with many different things. The vase, in Buddhism, can mean the showering of health, wealth, prosperity and all the good things that come with enlightenment.");
	e.Add(ItemDataVariables::itemEnumIdentifier, "Scroll05");
	e.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe");
	e.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Scroll5.Scroll5");
	e.Add(ItemDataVariables::itemName, "Bumpa Scroll");
	tItems.Add(Item::Scroll05, e);

	ItemData f;
	f.Add(ItemDataVariables::itemDescription, "The Two Golden Fish - In older times, the two fish were drawn to symbolize the Ganges and the Yamuna rivers. It has, through interpretation, come to mean luck and fortune. It also means the courage and fearlessness to face the ocean of sufferings and to be able to swim freely like fish through water.");
	f.Add(ItemDataVariables::itemEnumIdentifier, "Scroll06");
	f.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe");
	f.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Scroll6.Scroll6");
	f.Add(ItemDataVariables::itemName, "Two Golden Fish Scroll");
	tItems.Add(Item::Scroll06, f);

	ItemData g;
	g.Add(ItemDataVariables::itemDescription, "Parasol - An umbrella can protect people from the different elements, like the sun or the rain. In this context, a parasol or umbrella can mean protection from suffering and harmful forces. It can also mean the enjoyment of the cool shade it provides.");
	g.Add(ItemDataVariables::itemEnumIdentifier, "Scroll07");
	g.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe");
	g.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Scroll7.Scroll7");
	g.Add(ItemDataVariables::itemName, "Parasol Scroll");
	tItems.Add(Item::Scroll07, g);

	ItemData h;
	h.Add(ItemDataVariables::itemDescription, "Conch Shell - This large shell has been used in many countries as a traditional battle horn. In Buddhism, the white Conch shell that spirals to the right can mean the deep and joyful sound of the Dharma teachings. It is representative of the awakening disciples receive when they hear these teachings. The Conch shell can also mean the rousing of people from ignorance.");
	h.Add(ItemDataVariables::itemEnumIdentifier, "Scroll08");
	h.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe");
	h.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Scroll8.Scroll8");
	h.Add(ItemDataVariables::itemName, "Conch Shell Scroll");
	tItems.Add(Item::Scroll08, h);

	ItemData i;
	i.Add(ItemDataVariables::itemDescription, "A Precious gift from Avas previous life, it is extremely valued");
	i.Add(ItemDataVariables::itemEnumIdentifier, "Bracelet");
	i.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus");
	i.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/bracelet.bracelet");
	i.Add(ItemDataVariables::itemName, "Ava's Bracelet");
	tItems.Add(Item::Bracelet, i);

	ItemData j;
	j.Add(ItemDataVariables::itemDescription, "An item for the white room");
	j.Add(ItemDataVariables::itemEnumIdentifier, "Item01");
	j.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus");
	j.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Item1.Item1");
	j.Add(ItemDataVariables::itemName, "Item 1");
	tItems.Add(Item::Item01, j);

	ItemData k;
	k.Add(ItemDataVariables::itemDescription, "An item for the white room");
	k.Add(ItemDataVariables::itemEnumIdentifier, "Item02");
	k.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus");
	k.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Item2.Item2");
	k.Add(ItemDataVariables::itemName, "Item 2");
	tItems.Add(Item::Item02, k);

	ItemData l;
	l.Add(ItemDataVariables::itemDescription, "An item for the white room");
	l.Add(ItemDataVariables::itemEnumIdentifier, "Item03");
	l.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus");
	l.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Item3.Item3");
	l.Add(ItemDataVariables::itemName, "Item 3");
	tItems.Add(Item::Item03, l);

	ItemData m;
	m.Add(ItemDataVariables::itemDescription, "An item for the white room");
	m.Add(ItemDataVariables::itemEnumIdentifier, "Trash01");
	m.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus");
	m.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Trash1.Trash1");
	m.Add(ItemDataVariables::itemName, "Trash 1");
	tItems.Add(Item::Trash01, m);

	ItemData n;
	n.Add(ItemDataVariables::itemDescription, "An item for the white room");
	n.Add(ItemDataVariables::itemEnumIdentifier, "Trash02");
	n.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus");
	n.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Trash2.Trash2");
	n.Add(ItemDataVariables::itemName, "Trash 2");
	tItems.Add(Item::Trash02, n);

	ItemData o;
	o.Add(ItemDataVariables::itemDescription, "An item for the white room");
	o.Add(ItemDataVariables::itemEnumIdentifier, "Trash03");
	o.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus");
	o.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Trash3.Trash3");
	o.Add(ItemDataVariables::itemName, "Trash 3");
	tItems.Add(Item::Trash03, o);

	ItemData p;
	p.Add(ItemDataVariables::itemDescription, "An item of no use, but is very pretty");
	p.Add(ItemDataVariables::itemEnumIdentifier, "Trash04");
	p.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus");
	p.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Trash4.Trash4");
	p.Add(ItemDataVariables::itemName, "Trash 4");
	tItems.Add(Item::Trash04, p);

	return tItems;
}
FString ADataFactory::AccessTMapItems(Item Item_type, ItemDataVariables Item_variable)
{
	ItemData e = Items[Item_type];
	return e[Item_variable];
}
UStaticMesh * ADataFactory::Get3DRepresentationForItem(Item Item_type)
{
	ItemData e = Items[Item_type];
	UStaticMesh* mesh = Cast <UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, e[ItemDataVariables::itemMeshFilepath].GetCharArray().GetData()));;
	return mesh;
}
UTexture2D * ADataFactory::GetIconForItem(Item Item_type)
{
	ItemData e = Items[Item_type];
	UTexture2D* Texture = Cast <UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, e[ItemDataVariables::itemSpriteFilepath].GetCharArray().GetData()));
	return Texture;
}

UTexture2D * ADataFactory::GetIconSelectedForItem(Item Item_type)
{
	ItemData e = Items[Item_type];
	UTexture2D* Texture = Cast <UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, e[ItemDataVariables::itemSelectedSpriteFilepath].GetCharArray().GetData()));
	return Texture;
}
Item ADataFactory::GetItemType(const FString & enumType, const FString & enumName)
{
	UEnum *Ingr = FindObject<UEnum>(ANY_PACKAGE, *enumType, true);

	return (Item)Ingr->FindEnumIndex(FName(*enumName));
}
AActor * ADataFactory::SpawnItem(Item ItemToSpawn, FTransform Position, TSubclassOf<AActor> AnotherClass)
{
	UWorld * const world = GetWorld();
	if (world && AnotherClass)
	{
		//FActorSpawnParameters t;
		//t.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		//APickUpItem* reference = world->SpawnActor<APickUpItem>(AnotherClass, Position, t);
		////reference->InventoryObject3DRepresentation->SetStaticMesh(Get3DRepresentationForItem(ItemToSpawn));
		//reference->ItemName = AccessTMapItems(ItemToSpawn, IngredientDataVariables::i_item_name);
		//reference->InventoryObjectSprite2DRepresentation = GetIconForItem(ItemToSpawn);
		//return reference;
	
	}
	return nullptr;
}

FString ADataFactory::getItemDescription(Item ItemToSpawn)
{
	ItemData e = Items[ItemToSpawn];
	return e[ItemDataVariables::itemDescription];
}
