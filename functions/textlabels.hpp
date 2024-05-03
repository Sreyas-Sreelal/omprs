#pragma once

#include "../api.hpp"

OMPRS_API(void*, Create3DTextLabel(StringView text, Colour colour, Vector3 position, float drawDistance, int virtualWorld, bool los))
{
	ITextLabelsComponent* component = OMPRSComponent::Get()->GetTextLabels();
	if (component)
	{
		ITextLabel* textlabel = component->create(text, colour, position, drawDistance, virtualWorld, los);
		if (textlabel)
		{
			return textlabel;
		}
	}
	return nullptr;
}

OMPRS_API(void,Delete3DTextLabel(void* textlabel))
{
	OMPRSComponent::Get()->GetTextLabels()->release(static_cast<ITextLabel*>(textlabel)->getID());
}

OMPRS_API(void,Attach3DTextLabelToPlayer(void* textlabel, void* player, Vector3 offset))
{
	static_cast<ITextLabel*>(textlabel)->attachToPlayer(*static_cast<IPlayer*>(player), offset);
}

OMPRS_API(void,Attach3DTextLabelToVehicle(void* textlabel, void* vehicle, Vector3 offset))
{
	static_cast<ITextLabel*>(textlabel)->attachToVehicle(*static_cast<IVehicle*>(vehicle), offset);
}

OMPRS_API(void,Update3DTextLabelText(void* textlabel, Colour colour, StringView text))
{
	static_cast<ITextLabel*>(textlabel)->setColourAndText(colour, text);
}


OMPRS_API(bool, Is3DTextLabelStreamedIn(void* textlabel, void* player))
{
	return static_cast<ITextLabel*>(textlabel)->isStreamedInForPlayer(*static_cast<IPlayer*>(player));
}

OMPRS_API(void,Get3DTextLabelText(void* textlabel, StringView* output))
{
	*output = static_cast<ITextLabel*>(textlabel)->getText();
}

OMPRS_API(void,Get3DTextLabelColor(void* textlabel,Colour* colour))
{
	*colour = static_cast<ITextLabel*>(textlabel)->getColour();
}

OMPRS_API(void,Get3DTextLabelPos(void* textlabel, Vector3* out))
{
	*out = static_cast<ITextLabel*>(textlabel)->getPosition();
}

OMPRS_API(void,Set3DTextLabelDrawDistance(void* textlabel, float distance))
{
	static_cast<ITextLabel*>(textlabel)->setDrawDistance(distance);
}

OMPRS_API(float,Get3DTextLabelDrawDistance(void* textlabel))
{
	return static_cast<ITextLabel*>(textlabel)->getDrawDistance();
}

OMPRS_API(bool,Get3DTextLabelLOS(void* textlabel))
{
	return static_cast<ITextLabel*>(textlabel)->getTestLOS();
}

OMPRS_API(void,Set3DTextLabelLOS(void* textlabel, bool status))
{
	static_cast<ITextLabel*>(textlabel)->setTestLOS(status);
}

OMPRS_API(int,Get3DTextLabelVirtualWorld(void* textlabel))
{
	return static_cast<ITextLabel*>(textlabel)->getVirtualWorld();
}

OMPRS_API(void,Set3DTextLabelVirtualWorld(void* textlabel, int world))
{
	static_cast<ITextLabel*>(textlabel)->setVirtualWorld(world);
}

OMPRS_API(void, Get3DTextLabelAttachedData(void* textlabel, TextLabelAttachmentData* data))
{
	*data = static_cast<ITextLabel*>(textlabel)->getAttachmentData();
}

OMPRS_API(int, Get3DTextLabelID(void* textlabel))
{
	if (textlabel)
	{
		return static_cast<ITextLabel*>(textlabel)->getID();
	}
	return INVALID_TEXT_LABEL_ID;
}

OMPRS_API(void*, Get3DTextLabelFromID(int id))
{
	ITextLabelsComponent* component = OMPRSComponent::Get()->GetTextLabels();
	if (component)
	{
		return component->get(id);
	}	
	return nullptr;
}

// Player TextLabels

OMPRS_API(void*, CreatePlayer3DTextLabelOnPlayer(void* player, void* attachedPlayer, StringView text, Colour colour, Vector3 position, float drawDistance, bool los))
{
	IPlayerTextLabelData* labelData = queryExtension<IPlayerTextLabelData>(*static_cast<IPlayer*>(player));
	if (labelData)
	{
		if (attachedPlayer)
		{
			IPlayerTextLabel* textlabel = nullptr;
			textlabel = labelData->create(text, colour, position, drawDistance, los, *static_cast<IPlayer*>(attachedPlayer));		
			return textlabel;
		}
	}
	return nullptr;
}

OMPRS_API(void*, CreatePlayer3DTextLabelOnVehicle(void* player, void* attachedVehicle, StringView text, Colour colour, Vector3 position, float drawDistance, bool los))
{
	IPlayerTextLabelData* labelData = queryExtension<IPlayerTextLabelData>(*static_cast<IPlayer*>(player));
	if (labelData)
	{		
		if (attachedVehicle)
		{
			IPlayerTextLabel* textlabel = nullptr;
			textlabel = labelData->create(text, colour, position, drawDistance, los, *static_cast<IVehicle*>(attachedVehicle));
			return textlabel;
		}
	}
	return nullptr;
}

OMPRS_API(void*, CreatePlayer3DTextLabel(void* player, StringView text, Colour colour, Vector3 position, float drawDistance, bool los))
{
	IPlayerTextLabelData* labelData = queryExtension<IPlayerTextLabelData>(*static_cast<IPlayer*>(player));
	if (labelData)
	{
		IPlayerTextLabel* textlabel = nullptr;
		textlabel = labelData->create(text, colour, position, drawDistance, los);
		return textlabel;
	}
	return nullptr;
}

OMPRS_API(void,DeletePlayer3DTextLabel(void* player, void* textlabel))
{
	auto data = queryExtension<IPlayerTextLabelData>(*static_cast<IPlayer*>(player));
	if (data)
	{
		data->release(static_cast<IPlayerTextLabel*>(textlabel)->getID());
	}
	
}

OMPRS_API(void,UpdatePlayer3DTextLabelText(void* textlabel, Colour colour, StringView text))
{
	static_cast<IPlayerTextLabel*>(textlabel)->setColourAndText(colour, text);
}

OMPRS_API(void,GetPlayer3DTextLabelText(void* textlabel, StringView* output))
{
	*output = static_cast<IPlayerTextLabel*>(textlabel)->getText();
}

OMPRS_API(void,GetPlayer3DTextLabelColor(void* textlabel,Colour* colour))
{
	*colour = static_cast<IPlayerTextLabel*>(textlabel)->getColour();
}

OMPRS_API(void,GetPlayer3DTextLabelPos(void* textlabel, Vector3* out))
{
	*out = static_cast<IPlayerTextLabel*>(textlabel)->getPosition();
}

OMPRS_API(void,SetPlayer3DTextLabelDrawDistance(void* textlabel, float distance))
{
	static_cast<IPlayerTextLabel*>(textlabel)->setDrawDistance(distance);
}

OMPRS_API(float,GetPlayer3DTextLabelDrawDistance(void* textlabel))
{
	return static_cast<IPlayerTextLabel*>(textlabel)->getDrawDistance();
}


OMPRS_API(bool,GetPlayer3DTextLabelLOS(void* textlabel))
{
	return static_cast<IPlayerTextLabel*>(textlabel)->getTestLOS();
}

OMPRS_API(void,SetPlayer3DTextLabelLOS(void* textlabel, bool status))
{
	static_cast<IPlayerTextLabel*>(textlabel)->setTestLOS(status);
}

OMPRS_API(void, GetPlayer3DTextLabelAttachedData(void* textlabel, TextLabelAttachmentData* data))
{
	*data = static_cast<IPlayerTextLabel*>(textlabel)->getAttachmentData();
}

OMPRS_API(int, GetPlayer3DTextLabelID(void* textlabel))
{
	if (textlabel)
	{
		return static_cast<IPlayerTextLabel*>(textlabel)->getID();
	}
	return INVALID_TEXT_LABEL_ID;
}

OMPRS_API(void*, GetPlayer3DTextLabelFromID(void* player,int id))
{
	if (player)
	{
		IPlayerTextLabelData* labelData = queryExtension<IPlayerTextLabelData>(*static_cast<IPlayer*>(player));
		return labelData->get(id);
	}
	return nullptr;
}