#include "..\script_component.hpp"
/*
	 * Authors: Bragg
	 * Description: Display the selected loadout
	 *
	 * Arguments:
	 * 0: _loadout <ARRAY> - The loadout to display
	 * 1: _listInventory <CONTROL> - The inventory list control
	 *
	 * Return Value:
	 * <NONE>
	 *
	 * Example:
	 * [[],myInventoryList] call PREFIX_dialogs_loadout_fnc_displayLoadout
	 *
	 * Public: No
 */

params [
	["_loadout",[],[[]]],
	["_listInventory",controlNull,[controlNull]]
];

TRACE_1("fnc_displayLoadout",_this);

if (isNull _listInventory) exitWith {
	ERROR("fnc_displayLoadout: Invalid inventory list control");
};

if (count _loadout != 10) exitWith {
	ERROR("fnc_displayLoadout: Invalid loadout");
};

// Clear the inventory list
lbClear _listInventory;

// Fonction locale pour ajouter des items multiples (magasins ou équipements)
private _addItems = {
	params ["_items"];
	{
		_x params ["_item","_count"];
		if (_item != "") then {
			private _cfgSource = configFile >> "CfgWeapons" >> _item;
			private _itemDisplayName = [_cfgSource] call BIS_fnc_displayName;
			if (_itemDisplayName isEqualTo "") then {
				_cfgSource = configFile >> "CfgMagazines" >> _item;
				_itemDisplayName = [_cfgSource] call BIS_fnc_displayName;
			};
			private _itemName = FORMAT_2("%1 (x%2)",_itemDisplayName,_count);
			private _index = _listInventory lbAdd _itemName;
			_listInventory lbSetPicture [_index,getText (_cfgSource >> "picture")];
		};
	} forEach _items;
};

// Fonction locale pour ajouter des items simples (armes,vêtements,etc.)
private _addItem = {
	params ["_item",["_cfgSource","CfgWeapons"]];
	if (_item != "") then {
		private _itemName = [configFile >> "CfgWeapons" >> _item] call BIS_fnc_displayName;
		private _index = _listInventory lbAdd _itemName;
		_listInventory lbSetPicture [_index,getText (configFile >> "CfgWeapons" >> _item >> "picture")];
	};
};

private _primaryWeapon = ARG_2(_loadout,0,0);
[_primaryWeapon] call _addItem;

private _secondaryWeapon = ARG_2(_loadout,1,0);
[_secondaryWeapon] call _addItem;

private _handgun = ARG_2(_loadout,2,0);
[_handgun] call _addItem;

_listEquipement lbAdd " ";// Add a space before
_listEquipement lbAdd " ";// Add a space before

private _headgear = ARG_1(_loadout,6);
[_headgear] call _addItem;

private _goggles = ARG_1(_loadout,7);
[_goggles] call _addItem;

private _binoculars = ARG_2(_loadout,8,0);
[_binoculars] call _addItem;

private _assignedItems = ARG_1(_loadout,9);
[_assignedItems] call _addItems;

_listEquipement lbAdd " ";// Add a space before
_listEquipement lbAdd " ";// Add a space before

private _uniform = ARG_2(_loadout,3,0);
[_uniform] call _addItem;

_listEquipement lbAdd " ";// Add a space before

private _uniformItems = ARG_2(_loadout,3,1);
[_uniformItems] call _addItems;

_listEquipement lbAdd " ";// Add a space before
_listEquipement lbAdd " ";// Add a space before

private _vest = ARG_2(_loadout,4,0);
[_vest] call _addItem;

_listEquipement lbAdd " ";// Add a space before

private _vestItems = ARG_2(_loadout,4,1);
[_vestItems] call _addItems;

_listEquipement lbAdd " ";// Add a space before
_listEquipement lbAdd " ";// Add a space before

private _backpack = ARG_2(_loadout,5,0);
[_backpack,"CfgVehicles"] call _addItem;

_listEquipement lbAdd " ";// Add a space before

private _backpackItems = ARG_2(_loadout,5,1);
[_backpackItems] call _addItems;
