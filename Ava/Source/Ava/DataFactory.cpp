#include "Ava.h"
#include "DataFactory.h"


// Sets default values
ADataFactory::ADataFactory()
{
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
	blank.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/Blank.Blank");
	blank.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/Blank_Hovered.Blank_Hovered");
	blank.Add(ItemDataVariables::itemName, "");
	tItems.Add(Item::BLANK, blank);

	ItemData a; 
	a.Add(ItemDataVariables::itemDescription," A symbol of the infinite connections in life that bind us all together.");
	a.Add(ItemDataVariables::itemEnumIdentifier, "Scroll01");
	a.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Scroll1.Scroll1");
	a.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/Knot.Knot");
	a.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/wheel_Hovered.wheel_Hovered");
	a.Add(ItemDataVariables::itemName, "The Endless Knot");
	tItems.Add(Item::Scroll01, a);

	ItemData b; 
	b.Add(ItemDataVariables::itemDescription, "This pond-dwelling flower represents the teachings that Buddha imparted on mankind.");
	b.Add(ItemDataVariables::itemEnumIdentifier, "Scroll02");
	b.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Scroll2.Scroll2");
	b.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/lotus.lotus");
	b.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/lotus_Hovered.lotus_Hovered");
	b.Add(ItemDataVariables::itemName, "The Lotus");
	tItems.Add(Item::Scroll02, b);

	ItemData c;
	c.Add(ItemDataVariables::itemDescription, "When the Buddha bested the demon Mara, this banner came to symbolise his triumph over the demon’s vices.");
	c.Add(ItemDataVariables::itemEnumIdentifier, "Scroll03");
	c.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Scroll3.Scroll3");
	c.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/victory_banner.victory_banner"); 
	c.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/victory_banner_Hovered.victory_banner_Hovered");
	c.Add(ItemDataVariables::itemName, "The Dhvaja");
	tItems.Add(Item::Scroll03, c);

	ItemData d;
	d.Add(ItemDataVariables::itemDescription, "Symbolic of the Buddha himself, the eight spokes represent the Buddha’s eightfold path.");
	d.Add(ItemDataVariables::itemEnumIdentifier, "Scroll04");
	d.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Scroll4.Scroll4");
	d.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/wheel.wheel");
	d.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/wheel_Hovered.wheel_Hovered");
	d.Add(ItemDataVariables::itemName, "The Dharmachakra");
	tItems.Add(Item::Scroll04, d);

	ItemData e;
	e.Add(ItemDataVariables::itemDescription, "A vase filled with the blessings of prosperity and enlightenment.");
	e.Add(ItemDataVariables::itemEnumIdentifier, "Scroll05");
	e.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Scroll5.Scroll5");
	e.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/vase.vase");
	e.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/vase_Hovered.vase_Hovered");
	e.Add(ItemDataVariables::itemName, "The Bumpa");
	tItems.Add(Item::Scroll05, e);

	ItemData f;
	f.Add(ItemDataVariables::itemDescription, "These twin fish represent luck, fortune, and courage in the face of adversity.");
	f.Add(ItemDataVariables::itemEnumIdentifier, "Scroll06");
	f.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Scroll6.Scroll6");
	f.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/fish.fish");
	f.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/fish_Hovered.fish_Hovered");
	f.Add(ItemDataVariables::itemName, "The Two Golden Fish");
	tItems.Add(Item::Scroll06, f);

	ItemData g;
	g.Add(ItemDataVariables::itemDescription, "As a parasol protects from the sun and rain, so too will it shield you from suffering.");
	g.Add(ItemDataVariables::itemEnumIdentifier, "Scroll07");
	g.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Scroll7.Scroll7");
	g.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/parasol.parasol");
	g.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/parasol_Hovered.parasol_Hovered");
	g.Add(ItemDataVariables::itemName, "The Parasol");
	tItems.Add(Item::Scroll07, g);

	ItemData h;
	h.Add(ItemDataVariables::itemDescription, "Used as a call to battle, the sound of it resonates within the teachings of the Dharma.");
	h.Add(ItemDataVariables::itemEnumIdentifier, "Scroll08");
	h.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Scroll8.Scroll8");
	h.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/croch.croch");
	h.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/croch_Hovered.croch_Hovered");
	h.Add(ItemDataVariables::itemName, "The Conch Shell");
	tItems.Add(Item::Scroll08, h);

	ItemData i;
	i.Add(ItemDataVariables::itemDescription, "A simple but luxurious golden bracelet, your one remnant from your past life as a prince.");
	i.Add(ItemDataVariables::itemEnumIdentifier, "Bracelet");
	i.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus");
	i.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/bracelet.bracelet");
	i.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/bracelet_Hovered.bracelet_Hovered");
	i.Add(ItemDataVariables::itemName, "Bracelet");
	tItems.Add(Item::Bracelet, i);
	
	ItemData j; 
	j.Add(ItemDataVariables::itemDescription, "A rice dish, exquisitely presented upon a mandala- a feast fit for a god.");
	j.Add(ItemDataVariables::itemEnumIdentifier, "Item01");
	j.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Food_mandala1.Food_mandala1");
	j.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/food_mandala_red.food_mandala_red");
	j.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/food_mandala_red_Hovered.food_mandala_red_Hovered");
	j.Add(ItemDataVariables::itemName, "White Offering Mandala");
	tItems.Add(Item::Item01, j);

	ItemData k;
	k.Add(ItemDataVariables::itemDescription, "A rice dish, exquisitely presented upon a mandala- a feast fit for a god.");
	k.Add(ItemDataVariables::itemEnumIdentifier, "Item02");
	k.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Food_mandala2.Food_mandala2");
	k.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/food_mandala_white.food_mandala_white");
	k.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/food_mandala_white_Hovered.food_mandala_white_Hovered");
	k.Add(ItemDataVariables::itemName, "Red Offering Mandala");
	tItems.Add(Item::Item02, k);

	ItemData l;
	l.Add(ItemDataVariables::itemDescription, "A rice dish, exquisitely presented upon a mandala- a feast fit for a god.");
	l.Add(ItemDataVariables::itemEnumIdentifier, "Item03");
	l.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Food_mandala3.Food_mandala3");
	l.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/food_mandala_yellow.food_mandala_yellow");
	l.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/food_mandala_yellow_Hovered.food_mandala_yellow_Hovered");
	l.Add(ItemDataVariables::itemName, "Yellow Offering Mandala");
	tItems.Add(Item::Item03, l);

	ItemData m;
	m.Add(ItemDataVariables::itemDescription, "This weapon is used to symbolise a thunderbolt- an indestructible force of nature.");
	m.Add(ItemDataVariables::itemEnumIdentifier, "Trash01");
	m.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Vajra.Vajra");
	m.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/Modelling/Interactives/vajra.vajra");
	m.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/Modelling/Interactives/vajra_Hovered.vajra_Hovered");
	m.Add(ItemDataVariables::itemName, "The Vajra");
	tItems.Add(Item::Trash01, m);

	ItemData n;
	n.Add(ItemDataVariables::itemDescription, "An item for the white room");
	n.Add(ItemDataVariables::itemEnumIdentifier, "Trash02");
	n.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus");
	n.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Trash2.Trash2");
	n.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Scroll1Hovered.Scroll1Hovered");
	n.Add(ItemDataVariables::itemName, "Trash 2");
	tItems.Add(Item::Trash02, n);

	ItemData o;
	o.Add(ItemDataVariables::itemDescription, "An item for the white room");
	o.Add(ItemDataVariables::itemEnumIdentifier, "Trash03");
	o.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus");
	o.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Trash3.Trash3");
	o.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Scroll1Hovered.Scroll1Hovered");
	o.Add(ItemDataVariables::itemName, "Trash 3");
	tItems.Add(Item::Trash03, o);

	ItemData p;
	p.Add(ItemDataVariables::itemDescription, "An item of no use, but is very pretty");
	p.Add(ItemDataVariables::itemEnumIdentifier, "Trash04");
	p.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus");
	p.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Trash4.Trash4");
	p.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Scroll1Hovered.Scroll1Hovered");
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
	if (Item_type != Item::BLANK)
	{

		UStaticMesh* mesh = Cast <UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, e[ItemDataVariables::itemMeshFilepath].GetCharArray().GetData()));
		return mesh;
	}
	else
	{
		return nullptr;
	}
}
UTexture2D * ADataFactory::GetIconForItem(Item Item_type)
{
	ItemData e = Items[Item_type];
	if (Item_type != Item::BLANK)
	{
		UTexture2D* Texture = Cast <UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, e[ItemDataVariables::itemSpriteFilepath].GetCharArray().GetData()));
		return Texture;
	}
	else
	{
		return nullptr;
	}
}

UTexture2D * ADataFactory::GetIconSelectedForItem(Item Item_type)
{
	ItemData e = Items[Item_type];
	if (Item_type != Item::BLANK)
	{
		UTexture2D* Texture = Cast <UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, e[ItemDataVariables::itemSelectedSpriteFilepath].GetCharArray().GetData()));
		return Texture;
	}
	else
	{
		return nullptr;
	}
}
Item ADataFactory::GetItemType(const FString & enumType, const FString & enumName)
{
	UEnum *Ingr = FindObject<UEnum>(ANY_PACKAGE, *enumType, true);

	return (Item)Ingr->FindEnumIndex(FName(*enumName));
}

FString ADataFactory::getItemDescription(Item ItemToSpawn)
{
	ItemData e = Items[ItemToSpawn];
	return e[ItemDataVariables::itemDescription];
}

FString ADataFactory::getItemName(Item ItemToSpawn)
{
	ItemData e = Items[ItemToSpawn];
	return e[ItemDataVariables::itemName];
}