#pragma once

#include "../api.hpp"

OMPRS_API(void*,CreateMenu(StringView title, uint32_t columns, Vector2 position, float column1Width, float column2Width))
{
	IMenusComponent* component = OMPRSComponent::Get()->GetMenus();
	if (component)
	{
		return component->create(title, position, columns, column1Width, column2Width);		
	}
	return nullptr;
}

OMPRS_API(void,DestroyMenu(void* menu))
{
	OMPRSComponent::Get()->GetMenus()->release(static_cast<IMenu*>(menu)->getID());
}

OMPRS_API(int,AddMenuItem(void* menu, uint8_t column, StringView text))
{
	return static_cast<IMenu*>(menu)->addCell(text, column);
}

OMPRS_API(void, SetMenuColumnHeader(void* menu, uint8_t column, StringView headerTitle))
{
	static_cast<IMenu*>(menu)->setColumnHeader(headerTitle, column);
}

OMPRS_API(void,ShowMenuForPlayer(void* menu, void* player))
{
	static_cast<IMenu*>(menu)->showForPlayer(*static_cast<IPlayer*>(player));
}

OMPRS_API(void, HideMenuForPlayer(void* menu, void* player))
{
	static_cast<IMenu*>(menu)->hideForPlayer(*static_cast<IPlayer*>(player));
}

OMPRS_API(void,DisableMenu(void* menu))
{
	static_cast<IMenu*>(menu)->disable();
}

OMPRS_API(void,DisableMenuRow(void* menu, uint8_t row))
{
	static_cast<IMenu*>(menu)->disableRow(row);
}

OMPRS_API(void*,GetPlayerMenu(void* player))
{
	IMenusComponent* component = OMPRSComponent::Get()->GetMenus();
	if (component)
	{

		IPlayerMenuData* menuData = queryExtension<IPlayerMenuData>(static_cast<IPlayer*>(player));
		if (menuData)
		{
			return component->get(menuData->getMenuID());
		}
	}
	return nullptr;
}

OMPRS_API(bool,IsValidMenu(void* menu))
{
	return menu != nullptr;
}

OMPRS_API(bool,IsMenuDisabled(void* menu))
{
	return !static_cast<IMenu*>(menu)->isEnabled();
}

OMPRS_API(bool,IsMenuRowDisabled(void* menu, int row))
{
	return !static_cast<IMenu*>(menu)->isRowEnabled(row);
}

OMPRS_API(int,GetMenuColumns(void* menu))
{
	return static_cast<IMenu*>(menu)->getColumnCount();
}

OMPRS_API(int,GetMenuItems(void* menu, int column))
{
	return static_cast<IMenu*>(menu)->getRowCount(column);
}

OMPRS_API(void,GetMenuPos(void* menu, Vector2* pos))
{
	*pos = static_cast<IMenu*>(menu)->getPosition();
}

OMPRS_API(void,GetMenuColumnWidth(void* menu, float* column1Width, float* column2Width))
{
	const Vector2 widths = static_cast<IMenu*>(menu)->getColumnWidths();
	*column1Width = widths.x;
	*column2Width = widths.y;
}

OMPRS_API(void,GetMenuColumnHeader(void* menu, int column, StringView* header))
{
	*header = static_cast<IMenu*>(menu)->getColumnHeader(column);
}

OMPRS_API(void,GetMenuItem(void* menu, int column, int row, StringView* item))
{
	*item = static_cast<IMenu*>(menu)->getCell(column, row);
}

OMPRS_API(int, GetMenuID(void* menu))
{
	return static_cast<IMenu*>(menu)->getID();
}