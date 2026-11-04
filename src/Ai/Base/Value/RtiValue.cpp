/*
 * This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
 * information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
 * or (at your option) any later version.
 */

#include "RtiValue.h"
#include "Playerbots.h"

RtiValue::RtiValue(PlayerbotAI* botAI) : ManualSetValue<std::string>(botAI, "skull", "rti") {}

std::string const RtiValue::Save() { return value; }

bool RtiValue::Load(std::string const text)
{
    value = text;
    return true;
}

// CUSTOM (James): default CC icon by class.
// square = hunter (freezing trap), moon = mage (polymorph), diamond = warlock (fear; banish also uses circle),
// circle = priest (shackle undead), star = rogue (sap). Everyone else keeps moon.
static std::string DefaultRtiCc(PlayerbotAI* botAI)
{
    Player* bot = botAI ? botAI->GetBot() : nullptr;
    if (!bot)
        return "moon";

    switch (bot->getClass())
    {
        case CLASS_HUNTER:  return "square";
        case CLASS_WARLOCK: return "diamond";
        case CLASS_PRIEST:  return "circle";
        case CLASS_ROGUE:   return "star";
        default:            return "moon";
    }
}

RtiCcValue::RtiCcValue(PlayerbotAI* botAI) : ManualSetValue<std::string>(botAI, DefaultRtiCc(botAI), "rti cc") {}

std::string const RtiCcValue::Save() { return value; }

bool RtiCcValue::Load(std::string const text)
{
    value = text;
    return true;
}
